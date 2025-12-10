cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug)
project(StatComp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(MY_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

# --- BLOQUE HÍBRIDO 1: Ubicación del JAR del Generador ---
if(WIN32 AND EXISTS "C:/Users/jde/DevTools/antlr-4.13.2-complete.jar")
    # Para ti: Usa tu archivo local para no descargarlo
    set(ANTLR_EXECUTABLE "C:/Users/jde/DevTools/antlr-4.13.2-complete.jar")
else()
    # Para tu compañero: La ruta relativa original
    set(ANTLR_EXECUTABLE "${MY_BASE_DIR}/antlr-4.13.2-complete.jar")
endif()

# --- BLOQUE HÍBRIDO 2: Búsqueda de Headers (Añadí tus rutas a la lista) ---
find_path(ANTLR_INCLUDE_DIR
  NAMES antlr4-runtime.h
  PATHS 
    /usr/include 
    /usr/local/include 
    /usr/include/antlr4-runtime 
    /usr/local/include/antlr4-runtime
    # Rutas añadidas para Windows/MSYS2:
    "C:/antlr4-runtime"                       
    "C:/msys64/ucrt64/include/antlr4-runtime"
    "C:/Users/jde/DevTools/antlr4-runtime/include/antlr4-runtime"
)

if(NOT ANTLR_INCLUDE_DIR)
  message(FATAL_ERROR "Could not find antlr4-runtime.h. Install the ANTLR C++ runtime.")
endif()

list(APPEND CMAKE_MODULE_PATH ${MY_BASE_DIR})

# Descarga del JAR (Lógica original intacta por si acaso)
if(NOT EXISTS "${ANTLR_EXECUTABLE}")
    message(STATUS "Couldn't find: ${ANTLR_EXECUTABLE}")
    message(STATUS "Trying to download it...")
    file(DOWNLOAD
    "https://www.antlr.org/download/antlr-4.13.2-complete.jar"
    "${ANTLR_EXECUTABLE}"
    STATUS DOWNLOAD_STATUS TIMEOUT 60)
endif()

if(NOT EXISTS "${MY_BASE_DIR}/FindANTLR.cmake")
    message(STATUS "Couldn't find: FindANTLR.cmake")
    message(STATUS "Trying to download it.")
    set(URL1 "https://raw.githubusercontent.com/antlr/antlr4/")
    set(URL2 "refs/heads/dev/runtime/Cpp/cmake/FindANTLR.cmake")
    file(DOWNLOAD
    "${URL1}${URL2}"
    "${MY_BASE_DIR}/FindANTLR.cmake"
    STATUS DOWNLOAD_STATUS TIMEOUT 60)
endif()

find_package(ANTLR)
message(STATUS "Found ANTLR: ${ANTLR_VERSION}")

file(GLOB GFOURS "*.g4")

# =========================================================
# 3. GENERACIÓN DE CÓDIGO ANTLR
# =========================================================
# Fallback para Windows si la macro de FindANTLR falla (común en MSYS2)
if(WIN32 AND NOT ANTLR_FOUND)
    message(STATUS "Windows Mode: Using manual ANTLR generation")
    set(ANTLR_${PROJECT_NAME}_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
    file(MAKE_DIRECTORY ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR})
    set(ANTLR_${PROJECT_NAME}_CXX_OUTPUTS 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompLexer.cpp" 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompParser.cpp" 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompBaseVisitor.cpp" 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompVisitor.cpp"
    )
    add_custom_command(OUTPUT ${ANTLR_${PROJECT_NAME}_CXX_OUTPUTS}
        COMMAND java -jar ${ANTLR_EXECUTABLE} -Dlanguage=Cpp -no-listener -visitor -o ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR} -package antlr4 ${GFOURS}
        DEPENDS ${GFOURS}
    )
else()
    # Lógica original de tu compañero
    antlr_target(${PROJECT_NAME} ${GFOURS} LEXER PARSER VISITOR)
endif()

message(STATUS "ANTLR generated: ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}")
include_directories(${ANTLR_${PROJECT_NAME}_OUTPUT_DIR})

# =========================================================
# CONFIGURACIÓN DE LLVM
# =========================================================
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# --- BLOQUE HÍBRIDO 3: Selección de Librerías LLVM ---
if(WIN32)
    # En Windows/MSYS2 es más seguro mapear componentes explícitamente
    llvm_map_components_to_libnames(llvm_libs core support executionengine mcjit interpreter native)
else()
    # Lógica original de tu compañero para Linux
    find_library(LLVM_MAIN_LIB NAMES LLVM PATHS ${LLVM_LIBRARY_DIRS} NO_DEFAULT_PATH)
    if(LLVM_MAIN_LIB)
        set(llvm_libs ${LLVM_MAIN_LIB})
        message(STATUS "Using main LLVM library: ${LLVM_MAIN_LIB}")
    else()
        llvm_map_components_to_libnames(llvm_libs all)
        message(STATUS "Using LLVM component libraries")
    endif()
endif()

# =========================================================
# 4. COMPILACIÓN DEL EJECUTABLE
# =========================================================
file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${ANTLR_${PROJECT_NAME}_CXX_OUTPUTS})

# --- BLOQUE HÍBRIDO 4: Enlace final ---
if(WIN32)
    # En Windows buscamos la librería explícitamente en tus rutas
    find_library(ANTLR4_LIB NAMES antlr4-runtime 
        PATHS 
        "C:/antlr4-runtime/lib" 
        "C:/msys64/ucrt64/lib"
    )
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_LIB} ${llvm_libs})
else()
    # En Linux enlazamos por nombre estándar (Original)
    target_link_libraries(${PROJECT_NAME} PRIVATE antlr4-runtime ${llvm_libs})
endif()

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ${ANTLR_INCLUDE_DIR}
  ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}
  ${LLVM_INCLUDE_DIRS}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# --- BLOQUE HÍBRIDO 5: Copiar DLL (Solo Windows) ---
if(WIN32)
    # Intentamos encontrar la DLL en tus rutas conocidas
    find_file(ANTLR_DLL NAMES "libantlr4-runtime.dll" 
        PATHS 
        "C:/antlr4-runtime/bin"
        "C:/msys64/ucrt64/bin"
    )
    if(ANTLR_DLL)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${ANTLR_DLL}"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        )
    endif()
endif()

# vim: set ts=4 sw=4 et sts=0 :