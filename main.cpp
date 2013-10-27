#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

class ConsoleStack: public Stack
{
    public:
        void output(ostream &out) const;
};

ostream &operator<<(ostream &out, const ConsoleStack &stack);

int calc(int a, int b, char c);
int toint(char c);

int main()
{
     ConsoleStack s ;
    char str[] = "3 6 7 12 2 3 - + ";
    cout << "RPN: " << str << endl;

    int i, n = strlen(str);
    bool isNorm = true;

    for (i = 0; i < n && isNorm; ++i)
    {
        if (isdigit(str[i]))
        {
            int z = toint(str[i]);

            while (isdigit(str[++i]))
            {
                z = toint(str[i]) + z * 10;
            }
            s.push(z);
        }
        else
        {
            if (str[i] == ' ') continue;
            if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && s.getNum() > 1)
            {
                int a = s.pop();
                int b = s.pop();

                s.push(calc(b, a, str[i]));
            }
            else
            {

                cout << "Smth wrong!\n";
                isNorm = false;
            }
        }
    }



    if (isNorm)
    {
        cout << "ANS: " << s.pop();

        if (!s.isEmpty())
        {
            cout << "\n extra digits: ";
            while (!s.isEmpty()) cout << s.pop() << ' ';
        }
    }

    return 0;
}

int toint(char c)
{
     int a;
	if( c-'0' < 10 && c -'0'>=0 )
	a=(int)(c-'0');
	else
           a=-1;
           return a;
}

int calc(int a, int b, char c)
{
    switch(c)
    {
    case '+':
        a += b;
        break;

    case '-':
        a -= b;
        break;

    case '*':
        a *= b;
        break;

    case '/':
        a /= b;
        break;
    default:
        break;
    }
    return a;
}
ostream &operator<<(ostream &out, const ConsoleStack &stack)
{
    stack.output(out);
    return out;
}

void ConsoleStack::output(ostream &out) const
{
    Data datum;

    if(nextDatum(true, datum))
        out << datum << " ";

    while(nextDatum(false, datum))
        out << datum << " ";
}
