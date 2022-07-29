Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

The idea behind is this: A number is prime, if none of the smaller prime numbers divides it. Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible. Hence if we reach a cell and it is not marked, then it isn't divisible by any smaller prime number and therefore has to be prime.


EXAMPLE OUTPUT
------------------------------------------------------------------------
```diff


Please enter the number to find primes smaller than it: 56

2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 | 23 | 29 | 31 | 37 | 41 | 43 | 47 | 53 |
