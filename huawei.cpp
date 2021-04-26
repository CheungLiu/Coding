#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <stack>
using namespace std;

string reverseStr(string &str)
{
    int length = str.size();

    if (length == 0)
    {
        return "";
    }
    string temp = "";
    stack<string> myStack;
    int i = 0;
    for (auto s : str)
    {
        if (str[i] == '(')
        {
            myStack.push(temp);
            temp = "";
        }
        else if (str[i] == ')')
        {
            reverse(temp.begin(), temp.end());
            myStack.top() += temp;
            temp = myStack.top();
            myStack.pop();
        }
        else
        {
            temp += str[i];
        }
        ++i;
    }
    return temp;
}

int main()
{
    string str = "";
    cin >> str;
    cout << reverseStr(str) << endl;
    return 0;
}