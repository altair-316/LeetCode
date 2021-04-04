#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{

public:
    int getInt(char c)
    {

        int t = 0;

        switch (c)
        {
        case '1':
            t = 1;
            break;

        case '2':
            t = 2;
            break;

        case '3':
            t = 3;
            break;

        case '4':
            t = 4;
            break;

        case '5':
            t = 5;
            break;

        case '6':
            t = 6;
            break;

        case '7':
            t = 7;
            break;

        case '8':
            t = 8;
            break;

        case '9':
            t = 9;
            break;

        case '0':
            t = 0;
            break;

        case '-':
            t = -1;
            break;

        case '+':
            t = 0;
            break;
                
        default:
            t=-2;
                
        }
        return(t);
    }

    int myAtoi(string s)
    {
        unsigned int j=1;
        long int  myInt = 0, t = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i]==' '){
                j=1;
                continue;
            }
            
            t = getInt(s[i]);
            if (t >= 0){
                myInt = myInt + (t % 10) * j;
                j = j * 10;
            }
            if (t==-1)
                myInt = myInt * (-1);
            else if(t==-2){
                myInt=0;
                j=1;
            }
        }

        return (myInt);
    }
};

int main()
{

    Solution mySToI;
    int myInt = 0;
    string str;
    cin >> str ;

    myInt = mySToI.myAtoi(str);

    cout << myInt << endl;

    return (0);
}