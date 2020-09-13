#include<iostream>
#include <bits/stdc++.h>
#include "primeStack.h"

using namespace std;

int main()
{
    stackType<int> factor;
    int num;

    factor.initializeStack();

    cout << "--Find the prime factors of a number in descending order--" << endl << endl;
    cout << "Enter a positive number greater than 1: ";
    cin >>num;
    cout << endl;
    cout << "Prime factors of "<<"["<<num<<"]" << " in descending order are: " << endl << endl;

    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
            factor.push(i);
    }
    while (!factor.isEmptyStack())
		{
            cout << factor.top() << " ";
            factor.pop();
		}
		cout << endl;

    char quit;
    cout << endl;
    cout << "Enter another positive integer (Y/N)? ";
    cin >> quit;
    cout << endl;

    while (toupper(quit) != 'N')
    {
        if(toupper(quit) == 'Y')
        {
            cout << "Enter in a positive number greater than 1: ";
            cin >>num;
            cout << endl;
            cout << "Prime factors of "<< num << " in descending order are: " << endl;

            for (int i = 2; i <= num; i++)
            {
                if (num % i == 0)
                    factor.push(i);
            }
            while (!factor.isEmptyStack())
            {
                cout << factor.top() << " ";
                factor.pop();
            }
            cout << endl;
        }
        else if(toupper(quit) == 'N')
            break;
    cout << endl;
    cout << "Enter in another positive integer (Y/N)? ";
    cin >> quit;
    cout << endl;
    }
return 0;
}
