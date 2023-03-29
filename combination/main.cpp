#include<iostream>
using namespace std;

int factorial(int);
int combination(int, int);

int main(){
    int n, r;
    cin>>n;
    cin>>r;
    cout<<n<<"C"<<r<<" = "<<combination(n, r)<<endl;

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

int combination(int n, int r){
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}