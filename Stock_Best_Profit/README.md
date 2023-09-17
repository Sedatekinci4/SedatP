# Best Profit You Can Get from a Stock

This is actually a leetCode problem where you find the max profit you can get from a stock which means an array from a programming perspective.

The stock has daily (or whatever you want to say periodically) prices. What you want to do is creating a two pointers for saving the adresses of your max profit. While keeping the BUY Pointer at the lowest stock value, you keep changing the SELL Pointer where the stock is at its most expensive price. This is what you get as much as possible form a stock. An example input and output is shown below.

EXAMPLE INPUT
------------------------------------------------------------------------
```diff
int prices[] = {4, 5, 8, 1, 7, 3, 9};
NOTE = Actually you dont give the program an input, you just declare an array. But you can design the code to take stcok values from a user.
```

EXAMPLE output
------------------------------------------------------------------------
```diff
7 (sizeof the price array)
Profit:1
----------------------
Profit:4
----------------------
Profit:4
----------------------
Profit:6
----------------------
Profit:6
----------------------
Profit:8
The profit is:  8
