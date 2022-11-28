# Decimal to binary converter using stack data structure

This code converts a decimal which is between 0 and 255 to its 8 bit binary equivalent using stack data structure.
And returns 0 if the entered number is not between 0 - 255

EXAMPLE OUTPUT
------------------------------------------------------------------------
```diff
Please enter the decimal number to convert to binary (Only 0 to 255 and positive decimals):189
1 added to the stack
0 added to the stack
1 added to the stack
1 added to the stack
1 added to the stack
1 added to the stack
0 added to the stack
1 added to the stack

-----------BINARY EQUIVALENT-------------
1 0 1 1 1 1 0 1

Process returned 0 (0x0)   execution time : 2.554 s
Press any key to continue.
```
as seen above  (1 + 4 + 8 + 16 + 32 + 128) = 189
