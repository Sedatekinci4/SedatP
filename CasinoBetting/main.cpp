#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

int main(){
    int balance = 100;
    int bettingAmount, playerGuess;
    string playerName;
    char choice;

    cout<<"--------------- WELCOME TO THE SEDAT CASINO --------------------"<<endl;
    cout<<"Please enter your name:\t";
    getline(cin,playerName);
    do{
        system("cls");
        rules();
        cout<<"You have an amount of "<< balance << "$"<< endl;

        do{
            cout<< "Please enter how much you want to bet:\t";
            cin >> bettingAmount;
            if(bettingAmount > balance){
                cout<< "PLEASE ENTER AN AMOUNT THAT SMALLER THAN YOUR BALANCE WHICH IS: "<< balance<< endl;
                cout << "Please re enter an amount to bet"<<endl;
            }
        }while(bettingAmount > balance);

        do{
            cout<< "Please guess any number between 0-10:\t";
            cin >> playerGuess;
            if(playerGuess <= 0 || playerGuess >= 10){
                cout<< "Please enter a number between 0 to 10!!!!\n"
                << "Re enter the guess...";
            }
        }while(playerGuess <= 0 || playerGuess >= 10);

        // Providing a seed value
        srand((unsigned) time(NULL));

        // Get a random number
        int random = rand() % 10;

        // Print the random number
        cout<<"The lucky number is: "<<random<<endl;

        if(playerGuess == random){
            cout<< "Congratss!!! You've earned " << 10*bettingAmount<< "$"<<endl;
            balance = balance + 10*bettingAmount;
        }else{
            cout << "Unlucky, better luck next time.."<< endl;
            balance = balance - bettingAmount;
        }

        if(balance == 0){
            cout << "Opps, you don't have any more money to play. Take care!!" << endl;
            return 1;
        }
        cout<< "Do you want to play again? (y/n):\t";
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');

    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}

