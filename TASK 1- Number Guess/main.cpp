//TASK 1 NUMBER GUESSING GAME
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int num1= rand() % 100 + 1;
    int limit=20;
    
    cout<<"Welcome to the 'NUMBER GUESSING GAME'\n";
    cout<<"Guess the number between 1-100\n"<<endl;
        cout<<"The Computer selected a random number... It's your turn to guess\n"<<endl;
        
    while(true){
        
    cout<<"Enter your guess: ";
    int num2;
    cin>>num2;
    cin.ignore();
    if(num1==num2){
        cout<<"You guessed the number correctly!\n";
    }
    else if(num1>num2+limit){
        cout<<"The guess is TOO LOW... TRY AGAIN\n"<<endl;
    }
    else if(num1>num2){
        cout<<"The guess is LOW... TRY AGAIN\n"<<endl;
    }
    else if(num1<num2-limit){
        cout<<"The guess is TOO HIGH... TRY AGAIN\n"<<endl;
    }
    else{
        cout<<"The guess is HIGH... TRY AGAIN\n"<<endl;
    }
    
    cout<<"Type 'STOP' to exit or press 'ENTER' to continue: ";
    string input;
    getline(cin,input);
    if (input == "STOP" || input == "stop" || input == "Stop"){
    cout << "Game Over. The number was " << num1 << "\n"<<endl;
    cout << "EXITING. THANKS FOR PLAYING..\n";
    break;
    }
    }
    return 0;
}