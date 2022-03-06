#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 06.03.2022

enum count_roots_t {
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
};

const double EPS = 1e-6;

//-------------------------------------------------
//!  Solves equation ax^2 + bx + c = 0
//!
//!  @param [in]   a      a - coefficient
//!  @param [in]   b      b - coefficient
//!  @param [in]   c      c - coefficient
//!  @param [out]  x1    x1 - pointer to the 1-st root
//!  @param [out]  x2    x2 - pointer to the 2-nd root
//!
//!  @return number of roots
//!
//!  @note function Linear_Equalution_Solve is necessary.
//!  @note if the equalution has only one root, then variable x1 contains that root value.
//!
//--------------------------------------------------

count_roots_t Square_Equalution_Solver(double a, double b, double c, double *x1, double *x2);

//-------------------------------------------------
//!  Solves equation kx + b = 0
//!
//!  @param [in]   k      k - coefficient
//!  @param [in]   b      b - coefficient
//!  @param [out]  x      x - pointer to the root
//!
//!  @return number of roots
//!
//!  @note in case of infinite number of roots, returns INF_ROOTS.
//!  @note if the equalution has only one root, then variable x1 contains that root value.
//!
//--------------------------------------------------

count_roots_t Linear_Equalution_Solve(double k, double b, double* x);

//-------------------------------------------------
//!  Tests Square_Equalution_Solver function
//!
//!  @param [in]   a                        a - coefficient
//!  @param [in]   b                        b - coefficient
//!  @param [in]   c                        c - coefficient
//!  @param [in]  count_roots    count_roots - pointer to the 1-st root
//!  @param [in]  x1right           x1right - right root
//!  @param [in]  x2right           x2right - right root
//!
//!  @return if the test succeed returns true, otherwise - false
//!
//!  @note in case error don't returns wrong roots.
//!
//--------------------------------------------------

bool test(double a, double b, double c, count_roots_t count_roots, double x1right, double             x2right);

//-------------------------------------------------
//!  Adresses test function. Contains check values.
//!
//!  @note commented.
//!
//--------------------------------------------------

void Square_Equalution_Test();

//-------------------------------------------------
//!  Enters coefficients a, b, c. (ax^2 + bx + c = 0).
//!
//!  @param [in]   a                        a - pointer to coefficient
//!  @param [in]   b                        b - pointer to coefficient
//!  @param [in]   c                        c - pointer to coefficient
//!
//!  @note controls input information.
//!
//--------------------------------------------------

void input_coefficients(double* a, double* b, double* c);

//-------------------------------------------------
//!  Shows roots of equalution ax^2 + bx + c = 0.
//!
//!  @param [in]  count_roots    count_roots - pointer to the 1-st root
//!  @param [in]  x1                        x1right - right root
//!  @param [in]  x2                        x2right - right root
//!
//!  @note output contains text comments.
//!
//--------------------------------------------------

void output_roots(double x1, double x2, count_roots_t count_roots);

//-------------------------------------------------
//!  Compares double values.
//!
//!  @param [in]  a       a - 1-st value
//!  @param [in]  b       b - 2-nd value
//!
//!  @return if a equal b returns true, otherwise - false
//!
//!  @note uses ESP
//!
//--------------------------------------------------

bool Is_Equal_double(double a, double b);

//-------------------------------------------------
//!  swaps  *a and *b values
//!
//!  @param [in]   a                        a - pointer to variable
//!  @param [in]   b                        b - pointer to variable
//!
//--------------------------------------------------

void swap(double * a, double * b);

//-------------------------------------------------
//!
//!  @note Cleans input buffer.
//!
//--------------------------------------------------

void Clean_Input_Buffer();


int main() {
    printf("Square equalution solver.\n");
    printf("Kiri4, 23.08.2021\n\n");

    double a  = 0.0,
           b  = 0.0,
           c  = 0.0,
           x1 = 0.0,
           x2 = 0.0;
    
    input_coefficients(&a, &b, &c);
    
//    Square_Equalution_Test();
    
    count_roots_t count_roots = Square_Equalution_Solver(a, b, c, &x1, &x2);
    
    output_roots(x1, x2, count_roots);
    
    return 0;
}


count_roots_t Square_Equalution_Solver(double a, double b, double c, double* x1, double* x2) {
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    if (Is_Equal_double(a, 0)) {
        return Linear_Equalution_Solve(b, c, x1);
    }
    
    if (Is_Equal_double(c, 0)) {  // ax^2 + bx = 0
        *x1 = 0;
        *x2 = -b / a;
        
        if (*x1 > *x2) {
            swap(x1, x2);
        }
        return TWO_ROOTS;
    }
    
    double d = b * b - 4 * a * c;
    
    if (Is_Equal_double(d, 0)) {
        *x1 = -b / (2 * a);
        return ONE_ROOT;
    }
    
    if (d > EPS) {
        double sqrt_d = sqrtf(d);
        *x1 = (-b - sqrt_d) / (2 * a);
        *x2 = (-b + sqrt_d) / (2 * a);
        
        if (*x1 > *x2) {
            swap(x1, x2);
        }
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}


count_roots_t Linear_Equalution_Solve(double k, double b, double* x) { // kx + b = 0 //!
    if (Is_Equal_double(k, 0)) {
        if (Is_Equal_double(b, 0)) {
            return INF_ROOTS;
        } else {
            return NO_ROOTS;
        }
    } else {
        *x = -b / k;
        return ONE_ROOT;
    }
}


void Clean_Input_Buffer() {
    while (getchar() != '\n') ;
}


void input_coefficients(double* a, double* b, double* c) {
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    
    printf("ax^2 + bx + c = 0\n");
    printf("input a, b, c\n");
    
    bool is_incorrect_input = true; // raassttreellyyaaatt'''
    
    while (is_incorrect_input) {
        int res = scanf("%lg %lg %lg", a, b, c);
        if (res < 3) {
            printf("\nОшибка ввода.\n");
            printf("Необходимо ввести 3 разделённых пробелами числа.\n\n");
            Clean_Input_Buffer();
        } else {
            is_incorrect_input = false;
            Clean_Input_Buffer();
        }
    }
}


void output_roots(double x1, double x2, count_roots_t count_roots){
    switch (count_roots) {
            
        case INF_ROOTS:
            printf("Уравнение имеет бесконечное множество решений.\n");
            break;
            
        case NO_ROOTS:
            printf("Уравнение не имеет корней.\n");
            break;
            
        case ONE_ROOT:
            printf("Уравнение имеет единственный корень x = %.2f\n", x1);
            break;
            
        case TWO_ROOTS:
            printf("Уравнение имеет 2 корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
            break;
            
        default:
            printf("\nОшибка, неверный формат полученных данных.\n");
            printf("(double x1, double x2, countroots_t countroot)\n\n");
    }
}


void swap(double * a, double * b) {
    double s = *a;
    *a = *b;
    *b = s;
}


bool Is_Equal_double(double a, double b) {
    return (fabs(a - b) < EPS);
}


bool test(double a, double b, double c, count_roots_t count_roots, double x1right, double             x2right) {
    double x01 = 0.0,
           x02 = 0.0;
    
    if (count_roots != Square_Equalution_Solver(a, b, c, &x01, &x02)) {
        return false;
    }
//    printf("%.2f %.2f", x01, x02);
    switch (count_roots) {
        case TWO_ROOTS:
            if (!(Is_Equal_double(x1right, x01) && Is_Equal_double(x2right, x02))) {
                return false;
            } else {
                return true;
            }
            
        case ONE_ROOT:
            if (!(Is_Equal_double(x1right, x01))) {
                return false;
            } else {
                return true;
            }
            
        case NO_ROOTS:
            return true;
            
        case INF_ROOTS:
            return true;
            
        default:
            return true;
    }
}


void Square_Equalution_Test() {
    const int count_tests = 10;
    
    count_roots_t count_roots[count_tests] = {ONE_ROOT, ONE_ROOT, ONE_ROOT, NO_ROOTS, TWO_ROOTS, TWO_ROOTS, INF_ROOTS, NO_ROOTS, TWO_ROOTS, TWO_ROOTS};
    
    double a[count_tests] = {   1,   0,   0,  1,   1,    2,  0,  0,  -1,   1};
    
    double b[count_tests] = {   2,   1, -40,  5, -20,    5,  0,  0,   7,  43};
    
    double c[count_tests] = {   1,   5,   0,  7,  91,    2,  0,  5, -10, 120};
    
    double x1[count_tests] = { -1,  -5,   0,  0,   7,   -2,  0,  0,   2, -40};
    
    double x2[count_tests] = {  0,   0,   0,  0,  13, -0.5,  0,  0,   5,  -3};

    for (int i = 0; i < count_tests; ++i) {
        
        printf("%d input: (%.2f, %.2f, %.2f, %d, %.2f, %.2f)\n", i, a[i], b[i], c[i], count_roots[i], x1[i], x2[i]);
        
        if (test(a[i], b[i], c[i], count_roots[i], x1[i], x2[i])) {
            
            printf("test succeed\n\n");
        }
        else {
            
            printf("test failed\n\n");
        }
    }
}
