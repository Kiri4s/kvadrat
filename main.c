#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int kvadur(float, float, float);

int main() {
    printf("ax^2 + bx + c = 0\n");
    printf("input a, b, c\n");
    float a = 0.0,
          b = 0.0,
          c = 0.0;
    scanf("%f %f %f", &a, &b, &c);
    int res = kvadur(a, b, c);
//    printf("result is %d\n", res);
    return 0;
}

int kvadur(float a, float b, float c){
    if (a == 0){
        if (b == 0){
            printf("Ошибка ввода.\n");
            return 1;
        }
        else {
            float x0 = 0.0;
            x0 = -c / b;
            printf("Уравнение имеет единственный корень x = %.2f\n", x0);
        }
    }
    float d = b * b - 4 * a * c;
    printf("D = %.2f\n", d);
    if (d >= 0) {
        float x1 = (-b + sqrtf(d)) / (2 * a);
        float x2 = (-b - sqrtf(d)) / (2 * a);
        if (x1 == x2){
            printf("Уравнение имеет единственный корень x = %.2f\n", x1);
        }
        else if (x1 < x2){
            printf("Уравнение имеет 2 корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
        }
        else {
            printf("Уравнение имеет 2 корня: x1 = %.2f, x2 = %.2f\n", x2, x1);
        }
    }
    else {
        printf("Уравнение не имеет корней.\n");
    }
    return 0;
}
