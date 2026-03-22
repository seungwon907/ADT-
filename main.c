#define _CRT_SECURE_NO_WARNINGS //테스트ㅡㅡㅡㅡ
#include <stdio.h>
#include <stdlib.h>
#include "my_fraction.h"

int main() {
    char input[100];
    printf("입력 (형식: [분수 또는 정수 또는 소수] [연산자] [분수 또는 정수 또는 소수]): ");
    fgets(input, sizeof(input), stdin);

    Fraction frac1, frac2, result;
    char operator;

    char first_operand[50], second_operand[50];
    sscanf(input, "%s %c %s", first_operand, &operator, second_operand);

    frac1 = from_string(first_operand);
    frac2 = from_string(second_operand);

    switch (operator) {
    case '+':
        result = add(frac1, frac2);
        break;
    case '-':
        result = subtract(frac1, frac2);
        break;
    case '*':
        result = multiply(frac1, frac2);
        break;
    case '/':
        result = divide(frac1, frac2);
        break;
    default:
        fprintf(stderr, "지원하지 않는 연산자입니다.\n");
        return EXIT_FAILURE;
    }

    char* result_str = to_string(result);
    printf("결과: %s\n", result_str);
    free(result_str);

    return EXIT_SUCCESS;
}
