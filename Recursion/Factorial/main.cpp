#include <iostream>
using namespace std;
int myfact(int n);
int main()
{
    int n = 5;
    // cout << "Enter a positive value: ";
    // cin >> n;
    cout << "Factorial is " << myfact(n);
    return 0;
}

int myfact(int n)
{
    if (n > 1)
    {
        return n * myfact(n - 1);
    }
    else
    {
        return 1;
    }
}