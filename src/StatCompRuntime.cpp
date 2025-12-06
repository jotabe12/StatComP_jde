#include "StatCompRuntime.h"
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>

extern "C" {

// Frecuencia absoluta: cuenta ocurrencias y las imprime
void StatComp_Freq(const double* data, int size) {
    std::map<double,int> table;
    for (int i=0; i<size; ++i) {
        table[data[i]]++;
    }
    std::cout << "Frecuencia absoluta:\n";
    for (auto& kv : table) {
        std::cout << kv.first << " -> " << kv.second << "\n";
    }
}

// Frecuencia absoluta explícita (igual que Freq)
void StatComp_AbsFreq(const double* data, int size) {
    StatComp_Freq(data, size);
}

// Frecuencia relativa: proporción de cada valor
void StatComp_RelFreq(const double* data, int size) {
    std::map<double,int> abs;
    for (int i=0; i<size; ++i) {
        abs[data[i]]++;
    }
    std::cout << "Frecuencia relativa:\n";
    for (auto& kv : abs) {
        double rel = static_cast<double>(kv.second) / size;
        std::cout << kv.first << " -> " << rel << "\n";
    }
}

// Frecuencia absoluta acumulada
void StatComp_AbsFreqCum(const double* data, int size) {
    std::map<double,int> abs;
    for (int i=0; i<size; ++i) {
        abs[data[i]]++;
    }
    int running = 0;
    std::cout << "Frecuencia absoluta acumulada:\n";
    for (auto& kv : abs) {
        running += kv.second;
        std::cout << kv.first << " -> " << running << "\n";
    }
}

// Frecuencia relativa acumulada
void StatComp_RelFreqCum(const double* data, int size) {
    std::map<double,int> abs;
    for (int i=0; i<size; ++i) {
        abs[data[i]]++;
    }
    double running = 0.0;
    std::cout << "Frecuencia relativa acumulada:\n";
    for (auto& kv : abs) {
        double rel = static_cast<double>(kv.second) / size;
        running += rel;
        std::cout << kv.first << " -> " << running << "\n";
    }
}

// Tabla cruzada de dos arrays
void StatComp_CrossTab(const double* data1, int size1,
                       const double* data2, int size2) {
    int n = std::min(size1, size2);
    std::map<std::pair<double,double>,int> table;
    for (int i=0; i<n; ++i) {
        table[{data1[i], data2[i]}]++;
    }
    std::cout << "Tabla cruzada:\n";
    for (auto& kv : table) {
        std::cout << "(" << kv.first.first << ", " << kv.first.second
                  << ") -> " << kv.second << "\n";
    }
}

// ========== IMPLEMENTACIONES DE FUNCIONES ESTADÍSTICAS ==========

// Medidas de tendencia central
double StatComp_Mean(const double* data, int size) {
    if (size <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

double StatComp_Median(const double* data, int size) {
    if (size <= 0) return 0.0;
    std::vector<double> sorted(data, data + size);
    std::sort(sorted.begin(), sorted.end());
    if (size % 2 == 0) {
        return (sorted[size/2 - 1] + sorted[size/2]) / 2.0;
    } else {
        return sorted[size/2];
    }
}

double StatComp_Mode(const double* data, int size) {
    if (size <= 0) return 0.0;
    std::map<double, int> frequency;
    for (int i = 0; i < size; ++i) {
        frequency[data[i]]++;
    }
    double mode = data[0];
    int maxFreq = 0;
    for (const auto& pair : frequency) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mode = pair.first;
        }
    }
    return mode;
}

// Medidas de dispersión
double StatComp_Var(const double* data, int size) {
    if (size <= 1) return 0.0;
    double mean = StatComp_Mean(data, size);
    double variance = 0.0;
    for (int i = 0; i < size; ++i) {
        double diff = data[i] - mean;
        variance += diff * diff;
    }
    return variance / (size - 1); // Varianza muestral
}

double StatComp_Stdev(const double* data, int size) {
    return std::sqrt(StatComp_Var(data, size));
}

double StatComp_Range(const double* data, int size) {
    if (size <= 0) return 0.0;
    double min_val = data[0], max_val = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] < min_val) min_val = data[i];
        if (data[i] > max_val) max_val = data[i];
    }
    return max_val - min_val;
}

double StatComp_CoeffVar(const double* data, int size) {
    double mean = StatComp_Mean(data, size);
    if (mean == 0.0) return 0.0;
    double stdev = StatComp_Stdev(data, size);
    return (stdev / mean) * 100.0; // Porcentaje
}

double StatComp_IQR(const double* data, int size) {
    double q1 = StatComp_Quartile(data, size, 1);
    double q3 = StatComp_Quartile(data, size, 3);
    return q3 - q1;
}

// Medidas de posición
double StatComp_Quartile(const double* data, int size, int quartile) {
    if (size <= 0 || quartile < 1 || quartile > 3) return 0.0;
    return StatComp_Percentile(data, size, quartile * 25.0);
}

double StatComp_Percentile(const double* data, int size, double percentile) {
    if (size <= 0 || percentile < 0 || percentile > 100) return 0.0;
    std::vector<double> sorted(data, data + size);
    std::sort(sorted.begin(), sorted.end());
    double index = (percentile / 100.0) * (size - 1);
    int lower = static_cast<int>(std::floor(index));
    int upper = static_cast<int>(std::ceil(index));
    if (lower == upper) {
        return sorted[lower];
    } else {
        double weight = index - lower;
        return sorted[lower] * (1 - weight) + sorted[upper] * weight;
    }
}

double StatComp_Min(const double* data, int size) {
    if (size <= 0) return 0.0;
    double min_val = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] < min_val) min_val = data[i];
    }
    return min_val;
}

double StatComp_Max(const double* data, int size) {
    if (size <= 0) return 0.0;
    double max_val = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] > max_val) max_val = data[i];
    }
    return max_val;
}

// Operaciones básicas
double StatComp_Sum(const double* data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

int StatComp_Count(const double* data, int size) {
    return size;
}

double StatComp_Square_root(double value) {
    return (value >= 0.0) ? std::sqrt(value) : 0.0;
}

// Medidas de forma
double StatComp_Skewness(const double* data, int size) {
    if (size < 3) return 0.0;
    double mean = StatComp_Mean(data, size);
    double stdev = StatComp_Stdev(data, size);
    if (stdev == 0.0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        double z = (data[i] - mean) / stdev;
        sum += z * z * z;
    }
    return sum / size;
}

double StatComp_Kurtosis(const double* data, int size) {
    if (size < 4) return 0.0;
    double mean = StatComp_Mean(data, size);
    double stdev = StatComp_Stdev(data, size);
    if (stdev == 0.0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        double z = (data[i] - mean) / stdev;
        sum += z * z * z * z;
    }
    return (sum / size) - 3.0; // Exceso de curtosis
}

double StatComp_Moment(const double* data, int size, int order) {
    if (size <= 0 || order < 0) return 0.0;
    double mean = StatComp_Mean(data, size);
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += std::pow(data[i] - mean, order);
    }
    return sum / size;
}

// Estandarización
double StatComp_Standardize(double value, double mean, double stdev) {
    if (stdev == 0.0) return 0.0;
    return (value - mean) / stdev;
}

// Distribuciones (implementaciones simplificadas)
double StatComp_ZProb(double z) {
    // Aproximación de la CDF normal estándar usando la función de error
    return 0.5 * (1.0 + std::erf(z / std::sqrt(2.0)));
}

double StatComp_InvZ(double probability) {
    // Implementación simplificada de la función inversa normal
    // Aproximación de Beasley-Springer-Moro
    if (probability <= 0.0 || probability >= 1.0) return 0.0;
    
    double p = probability;
    if (p > 0.5) p = 1.0 - p;
    
    double t = std::sqrt(-2.0 * std::log(p));
    double result = t - ((2.30753 + t * 0.27061) / (1.0 + t * (0.99229 + t * 0.04481)));
    
    return (probability > 0.5) ? result : -result;
}

double StatComp_NormalPDF(double x, double mean, double stdev) {
    if (stdev <= 0.0) return 0.0;
    double z = (x - mean) / stdev;
    return (1.0 / (stdev * std::sqrt(2.0 * M_PI))) * std::exp(-0.5 * z * z);
}

double StatComp_NormalCDF(double x, double mean, double stdev) {
    if (stdev <= 0.0) return 0.0;
    double z = (x - mean) / stdev;
    return StatComp_ZProb(z);
}

double StatComp_UniformPDF(double x, double a, double b) {
    if (b <= a) return 0.0;
    return (x >= a && x <= b) ? (1.0 / (b - a)) : 0.0;
}

double StatComp_UniformCDF(double x, double a, double b) {
    if (b <= a) return 0.0;
    if (x < a) return 0.0;
    if (x > b) return 1.0;
    return (x - a) / (b - a);
}

// Función de impresión especial
void StatComp_Print(const double* data, int size) {
    std::cout << "Array contents: [";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

} // extern "C"
