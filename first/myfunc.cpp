#include <iostream>
#include<string>
#include "complex.h"
#include "static/static.h"

using namespace std;

void testFactorial()
{
    int factArg = 0;
    int fact(1);

    do {
        cout << "Factorial of: ";
        cin >> factArg;

        if (factArg < 0)
        {
            cout << "No negative values, please!" << endl;
        }
    } while (factArg < 0);

    int i = 2;
    while (i <= factArg)
    {
        fact = fact * i;
        i++;
    }
    cout << "The Factorial of " << factArg << " is: " << fact << endl;
}

void testYourAge()
{
    const int THIS_YEAR = 2011;
    string yourName;
    int birthYear;

    cout << "What is your name? " << flush;
    cin >> yourName;

    cout << "What year were you born? ";
    cin >> birthYear;

    cout << "Your name is " << yourName
         << " and you are approximately "
         << (THIS_YEAR - birthYear)
         << " years old. " << endl;
}

long factorial(long n)
{
    long ans = 1;
    for (long i = 2; i <= n; ++i)
    {
        ans = ans * i;
        if (ans < 0)
        {
            return -1;
        }
    }
    return ans;
}
void testLongFactorial()
{
    cout << "Please enter n: " << flush;
    long n;
    cin >> n;

    if (n >= 0)
    {
        long nfact = factorial(n);
        if (nfact < 0)
        {
            cerr << "overflow error: "
                 << n << " is too big." << endl;
        }
        else
        {
            cout << "factorial(" << n << ") = " << nfact << endl;
        }
    }
    else
    {
        cerr << "Undefined: "
             << "factorial of a negative number: " << n << endl;
    }
}


void test_stl_string()
{
    string s1("This "), s2("is a "), s3("string.");
    s1 += s2;
    string s4 = s1 + s3;
    cout << s4 << endl;

    string s5("The length of that string is: ");
    cout << s5 << s4.length() << " characters." << endl;
    cout << "Enter a sentence: " << endl;

    getline(cin, s2);
    cout << "Here is your sentence: \n" << s2 << endl;
    cout << "The length of your sentence is: " << s2.length() << endl;
}


void testPointer()
{
	int* tp = 0;
	int* jp = 0;

	jp = new int(13);
	cout << " jp = " << jp << endl;
	cout << " *jp = " << *jp << endl;

	delete jp;
	cout << "after delete jp:" << endl;
	cout << " jp = " << jp << endl;
	cout << " *jp = " << *jp << endl;

	tp = new int(17);

	cout << " tp = " << tp << endl;
	cout << " *tp = " << *tp << endl;

	cout << " jp = " << jp << endl;
	cout << " *jp = " << *jp << endl;
}

void testComplexClass()
{
	Complex c1, c2(3.14), c3(6.2, 10.23);
	cout << c1.toString() << ", " << c2.toString() << ", " << c3.toString() << endl;
}

void testStatic() 
{
	Thing::showCount(); // 0
	Thing t1(3, 4), t2(5, 6);

	t1.showCount(); // 2

	{
		Thing t3(7, 8), t4(9, 10);
		Thing::showCount(); // 4
	}

	Thing::showCount(); // 2
}