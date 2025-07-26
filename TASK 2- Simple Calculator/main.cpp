//TASK 2 SIMPLE CALCULATOR
#include<iostream>
#include<string>
using namespace std;
int main(){
    int choice;
    float x,y,z;
    string input;
    cout<<"\nWelcome to SIMPLE CALCUALTOR"<<endl;
    while(true){
    cout<<"\nType 'STOP' to exit or press 'ENTER' to continue"<<endl;
    getline(cin, input);
        if(input=="STOP" || input== "stop"){
            cout<<"...Exiting Calculator..."<<endl;
            break;
        }
    cout<<"Choose an opertaion to perform: \n1.Addition \n2.Subtraction \n3.Multiplication \n4.Division\n";
    cin>> choice;
    cout<<"Enter x and y: ";
    cin>>x>>y;
    cin.ignore();
    switch(choice){
        case 1: 
        cout<<"Addition of "<<x<<" and "<<y<<" : "<< x+y<<endl;
        break;
        case 2: 
        cout<<"Subtraction of "<<x<<" and "<<y<<" : "<< x-y<<endl;
        break;
        case 3: 
        cout<<"Multiplication of "<<x<<" and "<<y<<":  "<< x*y<<endl;
        break;
        case 4: 
        if(y==0)
        cout<<"Numbers cannot be divided by 0"<<endl;
        else
        cout<<"Divsion of "<<x<<" and "<<y<<" : "<< x/y<<endl;
        break;
        default:
        cout<<"Invalid choice"<<endl;
        break;
      }
    }
    return 0;
}