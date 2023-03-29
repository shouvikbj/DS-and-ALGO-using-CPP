#include<iostream>
using namespace std;

int factorial(int n);

int main(){
    int n;
    cout<<"Enter a positive value: ";
    cin>>n;
    cout<<"Factorial is: "<<factorial(n)<<endl;

    return 0;
}

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}