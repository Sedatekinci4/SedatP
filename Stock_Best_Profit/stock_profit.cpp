#include <iostream>

using namespace std;

int main()
{
    int prices[] = {4, 5, 8, 1, 7, 3, 9};
    int *ptrBuy;
    int *ptrSell;
    int profit = 0;

    ptrBuy = &prices[0];
    ptrSell = &prices[1];
    cout << sizeof(prices) / sizeof(prices[0]) << endl;
    profit = *ptrSell - *ptrBuy;
    cout << "Profit:" << profit << endl;

    for (int i = 2; i < sizeof(prices) / sizeof(prices[0]); i++)
    {
        cout << "----------------------" << endl;
        if (*ptrSell < *ptrBuy)
        {
            ptrBuy = ptrSell;
            ptrSell = &prices[i];
            if (profit < *ptrSell - *ptrBuy)
            {
                profit = *ptrSell - *ptrBuy;
            }
            cout << "Profit:" << profit << endl;
        }
        else
        {
            ptrSell = &prices[i];
            if (profit < *ptrSell - *ptrBuy)
            {
                profit = *ptrSell - *ptrBuy;
            }
            cout << "Profit:" << profit << endl;
        }
    }

    cout << "The profit is:\t" << profit << endl;

    return 0;
}