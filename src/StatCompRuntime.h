#ifndef STATCOMP_RUNTIME_H
#define STATCOMP_RUNTIME_H

// Declaraciones de las funciones de tabla de StatComp
// Usamos extern "C" para evitar name mangling y permitir enlace desde LLVM IR

extern "C" {

// Frecuencia absoluta: cuenta ocurrencias y las imprime
void StatComp_Freq(const double* data, int size);

// Frecuencia absoluta explícita (igual que Freq)
void StatComp_AbsFreq(const double* data, int size);

// Frecuencia relativa: proporción de cada valor
void StatComp_RelFreq(const double* data, int size);

// Frecuencia absoluta acumulada
void StatComp_AbsFreqCum(const double* data, int size);

// Frecuencia relativa acumulada
void StatComp_RelFreqCum(const double* data, int size);

// Tabla cruzada de dos arrays
void StatComp_CrossTab(const double* data1, int size1,
                       const double* data2, int size2);

// ========== FUNCIONES ESTADÍSTICAS ==========
// Estas funciones retornan valores calculados (principalmente double)

// Medidas de tendencia central
double StatComp_Mean(const double* data, int size);
double StatComp_Median(const double* data, int size);
double StatComp_Mode(const double* data, int size);

// Medidas de dispersión
double StatComp_Stdev(const double* data, int size);
double StatComp_Var(const double* data, int size);
double StatComp_Range(const double* data, int size);
double StatComp_CoeffVar(const double* data, int size);
double StatComp_IQR(const double* data, int size);

// Medidas de posición
double StatComp_Quartile(const double* data, int size, int quartile);
double StatComp_Percentile(const double* data, int size, double percentile);
double StatComp_Min(const double* data, int size);
double StatComp_Max(const double* data, int size);

// Operaciones básicas
double StatComp_Sum(const double* data, int size);
int StatComp_Count(const double* data, int size);
double StatComp_Square_root(double value);

// Medidas de forma
double StatComp_Skewness(const double* data, int size);
double StatComp_Kurtosis(const double* data, int size);
double StatComp_Moment(const double* data, int size, int order);

// Estandarización
double StatComp_Standardize(double value, double mean, double stdev);

// Distribuciones
double StatComp_ZProb(double z);
double StatComp_InvZ(double probability);
double StatComp_NormalPDF(double x, double mean, double stdev);
double StatComp_NormalCDF(double x, double mean, double stdev);
double StatComp_UniformPDF(double x, double a, double b);
double StatComp_UniformCDF(double x, double a, double b);

// Función de impresión especial
void StatComp_Print(const double* data, int size);

}

#endif // STATCOMP_RUNTIME_H
