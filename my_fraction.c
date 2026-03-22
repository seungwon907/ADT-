#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "my_fraction.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

Fraction reduce(Fraction frac) {
    if (frac.denominator == 0) {
        fprintf(stderr, "Error: Division by zero in reduce function.\n");
        exit(EXIT_FAILURE);
    }
    int divisor = gcd(frac.numerator, frac.denominator);
    frac.numerator /= divisor;
    frac.denominator /= divisor;
    if (frac.denominator < 0) {
        frac.numerator = -frac.numerator;
        frac.denominator = -frac.denominator;
    }
    return frac;
}

Fraction from_string(const char* str) {
    Fraction frac;
    if (strchr(str, '/')) {
        sscanf(str, "%d/%d", &frac.numerator, &frac.denominator);
    }
    else if (strchr(str, '.')) {
        double decimal = atof(str);
        frac = from_decimal(decimal);
    }
    else {
        int integer = atoi(str);
        frac = from_integer(integer);
    }
    return reduce(frac);
}

Fraction from_integer(int integer) {
    Fraction frac;
    frac.numerator = integer;
    frac.denominator = 1;
    return frac;
}

Fraction from_decimal(double decimal) {
    Fraction frac;
    int denominator = 1;
    while (decimal != (int)decimal) {
        decimal *= 10;
        denominator *= 10;
    }
    frac.numerator = (int)decimal;
    frac.denominator = denominator;
    return reduce(frac);
}

char* to_string(Fraction frac) {
    char* result = (char*)malloc(20 * sizeof(char));
    if (frac.denominator == 1) {
        sprintf(result, "%d", frac.numerator);
    }
    else {
        sprintf(result, "%d/%d", frac.numerator, frac.denominator);
    }
    return result;
}

Fraction add(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return reduce(result);
}

Fraction subtract(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return reduce(result);
}

Fraction multiply(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return reduce(result);
}

Fraction divide(Fraction frac1, Fraction frac2) {
    if (frac2.numerator == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;
    return reduce(result);
}
