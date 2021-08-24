#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    printf("ax^2+bx+c=0\n");
    printf("input a, b, c\n");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0){
        printf("Ошибка ввода.\n");
        exit(1);
    }
    float d = b * b - 4 * a * c;
    printf("D = %.2f\n", d);
    if (d>=0) {
        float x1 = (-b+sqrtf(d))/(2*a);
        float x2 = (-b-sqrtf(d))/(2*a);
        if (x1 == x2)
            printf("Уравнение имеет единственный корень x = %.2f\n", x1);
        else
            printf("Уравнение имеет 2 корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else
        printf("Уравнение не имеет корней.\n");
    return 0;
}
