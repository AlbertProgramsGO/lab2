#include <stdio.h>
#include <math.h>



double countIntegral(double a, double b, int n);


int main() {
    double a, b, E;
    int n = 1;

    printf("Введите a: ");
    scanf("%lf", &a);

    printf("Введите b: ");
    scanf("%lf", &b);

    printf("Введите погрешность E: ");
    scanf("%lf", &E);

    double previousResult = 0.0;
    double result = countIntegral(a, b, n);
    
    // Увеличиваем количество разбиений до достижения заданной погрешности
    while (fabs(result - previousResult) > E) {
        previousResult = result;
        n *= 2;
        result = countIntegral(a, b, n);
    }
    
    printf("Значение интеграла: %f\n", result);
    
    return 0;
}

double countIntegral(double a, double b, int n) {
    double sum = 0.0; //создание переменной для общей суммы
    double dx = (b - a) / n; // создание переменной для значения h
    
    for (int i = 1; i <= n; i++) {
        double x = a + i * dx; // нахождение правого конца прямоугольника
        sum += log(x) * dx; // площадь прямоугольника добавляется к сумме
    }
    
    return sum;
}
