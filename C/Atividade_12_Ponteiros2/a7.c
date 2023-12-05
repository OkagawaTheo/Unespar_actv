#include <stdio.h>

void medidas_retangulo(double *var1, double *var2) {
    double area = (*var1) * (*var2);
    double perimetro = 2 * ((*var1) + (*var2));
    *var1 = area;
    *var2 = perimetro;
}
