#include <iostream>
#include <stack>
using namespace std;

void printstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main()
{
    stack<int> s;
    s.push(13);
    s.push(34);
    s.push(56);
    printstack(s);
    s.pop();
    printstack(s);
    cout << "size is: " << s.size();

    return 0;
}