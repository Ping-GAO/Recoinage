//
// Created by gary9 on 3/6/2018.
//

// COMP1521 18s1 Week 02 Lab
// Add two numbers (numbers can be LARGE)

#include <stdio.h>
#include "BigNum.h"

int main(int argc, char **argv)
{
    BigNum num1;  // first input number
    BigNum num2;  // second input number
    BigNum sum;   // num1 + num2
    BigNum minus;
    BigNum multi;
    if (argc < 3) {
        printf("Usage: %s Num1 Num2\n", argv[0]);
        return 1;
    }

    // Initialise BigNum objects
    // assume the user know how long is the big number
    // if not, the program should not work
    initBigNum(&num1, 20);
    initBigNum(&num2, 20);
    initBigNum(&sum,  20);
    initBigNum(&minus, 20);
    initBigNum(&multi, 20);
    // Extract values from cmd line args
    if (!scanBigNum(argv[1], &num1)) {
        printf("First number invalid\n");
        return 1;
    }
    if (!scanBigNum(argv[2], &num2)) {
        printf("Second number invalid\n");
        return 1;
    }

    // Add num1+num2, store result in sum
    addBigNums(num1, num2, &sum);
    subtractBigNums(num1, num2, &minus);
    multiplyBigNums(num1, num2, &multi);

    printf("Sum of "); showBigNum(num1);
    printf("\nand "); showBigNum(num2);
    printf("\nis "); showBigNum(sum);
    printf("\n");

    printf("----------------------------\n");
    printf("Subtraction of "); showBigNum(num1);
    printf("\nand "); showBigNum(num2);
    printf("\nis "); showBigNum(minus);
    printf("\n");

    printf("----------------------------\n");
    printf("Multiplication of "); showBigNum(num1);
    printf("\nand "); showBigNum(num2);
    printf("\nis "); showBigNum(multi);
    printf("\n");
    return 0;

}