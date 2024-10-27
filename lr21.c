#include <stdio.h>

double calculateSum(double E);

int main() {
    double E;
    printf("\nВведите точность E: ");
    scanf("%lf", &E);  // вводим точность

    double result = calculateSum(E);  // вычисляем сумму
    printf("Сумма ряда: %lf\n", result);  // выводим результат

    return 0;
}

double calculateSum(double E) {
    double firstNum = 1.0; //первый член последовательности
    double sum = 0; // сумма ряда
    int n = 1; // индекс для следующего члена последовательности

    while (firstNum > E) {
        firstNum /= n; //находим следующий член последовательности
        sum += firstNum; //добавляем к сумме следующий член
        n++;
    }

    return sum;
}
