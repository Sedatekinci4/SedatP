#include <iostream>

using namespace std;

int isSumOfTwoPrime(int num);

int main(){
    int N = 23;
    int answer;
    answer = isSumOfTwoPrime(N);
    if(answer == 1){
        cout << "This number can be used" << endl;
    }
    else{
        cout << "This number:" << N << "can not be used" << endl;
    }

    return 0;
}

int isSumOfTwoPrime(int num){
    cout << "Checking for the sum of two prime..." << endl;
    int isPrime = 1;
    int prime_num = num -2;
    for (int i = 2; i < prime_num ; i++)
    {
        if(prime_num  % i == 0){
            isPrime = 0;
            cout << prime_num << " is divisible to " << i <<  endl;
        }
    }
    return isPrime;
}