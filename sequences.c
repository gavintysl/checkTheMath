/*******************************
 *
 *  Project Name: Check the Mathematics
 *  Description: Computes the first 50 iterations of the sequences below
 *  Date: January 31, 2020
 *  Authors: Rob McMahon, Gavin Tysl
 *
 *******************************/

#include <stdio.h>

/* Method signatures to avoid warnings... */
void caterers(); void primes(); int isPrime();
void fib(); void nthFib(); void collatz();
void happy(); void collatzCount(); int isHappyNumber();


/* main */
int main() {
    caterers();
    primes();
    fib();
    collatz();
    happy();
    return 0;
}


/* Lazy Caterer's Sequence */
void caterers() {
    printf("Lazy Caterer's Sequence:\n");

    for (int i = 0; i < 50; i++) {
        int cuts = (i * i + i + 2) / 2;
        printf("%d ", cuts);
    }
    printf("\n\n");
}


/* Prime Numbers */
void primes() {
    printf("Prime Numbers:\n");

    int count = 1;
    int start = 2;

    while (count <= 50) {
        int num = isPrime(start);
        if (num != 0) {
            count++;
            printf("%d ", start);
        }
        start++;
    }
    printf("\n\n");
}


/* return 1 if number is prime, else 0 */
int isPrime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


/* Fibonacci Driver */
void fib() {
    printf("Fibonacci Sequence:\n");

    for (int i = 1; i <= 50; i++) {
        nthFib(i);
    }
    printf("\n\n");
}


/* Prints the n-th fibonacci number in the sequence */
void nthFib(int n) {
    long long first = 0;
    long long second = 1;
    long long nth = 1;

    for (int i = 2; i <= n; i++) {
        nth = first + second;
        first = second;
        second = nth;
    }
    printf("%lld ", nth);
}


/* Collatz Stopping Times */
void collatz() {
    printf("Collatz Stopping Times:\n");
    for (int i = 1; i <= 50; i++) {
        collatzCount(i);
    }
    printf("\n\n");
}


/* Return number of operations it takes to reach 1 for some int n */
void collatzCount(int n) {
    int count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
            count++;
        }
        else {
            n = n * 3 + 1;
            count++;
        }
    }
    printf("%d ", count);
}


/* Happy Numbers */
void happy() {
    printf("Happy Numbers:\n");
    
    int count = 0;
    int tryHappy = 1;

    while (count < 50) {
        if (isHappyNumber(tryHappy) == 1)
            count++;
        tryHappy++;
    }
}


/* returns 1 if number is happy else 0 */
int isHappyNumber(int n) {
    int digit, num = n, rem, start;

    for (digit = 0; digit < 9; digit++) {
        start = 0;

        // sum of squares of individual digits
        while (num > 0) {
            rem = num % 10;
            start = start + rem * rem;
            num /= 10;
        }
        num = start;
    }

    if (start == 1) {
        printf("%d ", n);
        return 1;
    }
    else
        return 0;
}
