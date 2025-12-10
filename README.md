# Guía de Compilación de StatComp en Windows (MSYS2)

Esta guía detalla los pasos para configurar un entorno de desarrollo profesional, compilar las dependencias y construir el compilador **StatComp** en Windows utilizando **MSYS2 (UCRT64)**.

## 1. Prerrequisitos

1. **Instalar MSYS2:** Descarga e instala MSYS2 desde https://www.msys2.org/
2. **Java (JRE/JDK):** Necesario para ejecutar el generador de código de ANTLR (el archivo `.jar`).
   - Verifica que lo tienes instalado ejecutando `java -version` en una terminal (PowerShell o CMD).

---

## 2. Configuración del Entorno (MSYS2)

Abre la terminal **"MSYS2 UCRT64"** y ejecuta los siguientes pasos:

### 2.1. Instalar Herramientas Base

Instala Clang, LLVM, CMake, Ninja y herramientas esenciales:

```bash
pacman -S mingw-w64-ucrt-x86_64-toolchain mingw-w64-ucrt-x86_64-llvm mingw-w64-ucrt-x86_64-clang mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja git base-devel
```

### 2.2. Compilar e Instalar ANTLR4 Runtime

Como el paquete oficial de ANTLR no siempre está disponible, lo compilaremos manualmente.

1. **Descargar el código fuente:**

```bash
cd ~
git clone https://github.com/antlr/antlr4.git
cd antlr4/runtime/Cpp
```

2. **Configurar y Compilar:**

```bash
rm -rf build_system && mkdir build_system && cd build_system

cmake .. -G "Ninja" -DCMAKE_INSTALL_PREFIX=/ucrt64 -DCMAKE_BUILD_TYPE=Release

cmake --build .
```

3. **Instalar en el sistema:**

```bash
cmake --install .
```

4. **Organizar los Headers:**

```bash
if [ ! -d "/ucrt64/include/antlr4-runtime" ]; then
    cd /ucrt64/include
    mkdir -p antlr4-runtime
    mv antlr4-*.h antlr4-runtime/ 2>/dev/null || true
    echo "Headers organizados correctamente en /ucrt64/include/antlr4-runtime."
else
    echo "La carpeta ya existe, no es necesario mover nada."
fi
```

---

## 3. Configuración de Windows (PATH)

1. Abre **"Editar las variables de entorno de esta cuenta"**.
2. Edita la variable **Path**.
3. Agrega la ruta:

```
C:\msys64\ucrt64\bin
```

4. Cierra y vuelve a abrir la terminal.

---

## 4. Compilación del Proyecto

Desde **PowerShell** en la carpeta del proyecto:

### 4.1. Limpiar compilaciones previas

```powershell
Remove-Item build -Recurse -Force -ErrorAction SilentlyContinue
```

### 4.2. Configurar el proyecto

```powershell
cmake -S src -B build -G "Ninja"
```

### 4.3. Compilar

```powershell
cmake --build build
```

---

## 5. Ejecución y Pruebas

### Ejecutar un script de prueba

```powershell
.\build\StatComp.exe test_completo.scp
```

### Guardar código intermedio (.ll)

```powershell
.\build\StatComp.exe test.scp > output.ll
```

---

## Solución de Problemas Comunes

- **Error "Could not find antlr4-runtime.h":**  
  Asegúrate de haber ejecutado el paso 2.2(4).

- **Error "cmake not recognized":**  
  Revisa que `C:\msys64\ucrt64\bin` esté en el PATH.

- **Error "JIT has not been linked in":**  
  Falta llamar `InitializeNativeTarget()` en `main` (archivo `src/main.cpp`).

- **Error de Java al compilar:**  
  Asegúrate de tener Java instalado y accesible.

