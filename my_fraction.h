#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction reduce(Fraction frac);
Fraction from_string(const char* str);
Fraction from_integer(int integer);
Fraction from_decimal(double decimal);
char* to_string(Fraction frac);
Fraction add(Fraction frac1, Fraction frac2);
Fraction subtract(Fraction frac1, Fraction frac2);
Fraction multiply(Fraction frac1, Fraction frac2);
Fraction divide(Fraction frac1, Fraction frac2);

#endif


