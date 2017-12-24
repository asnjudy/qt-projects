#include <QString>
#include <QTextStream>
#include <QChar>
#include <QDate>
#include <QCoreApplication>
#include <QStringList>
#include <iostream>
#include "fraction.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

void testQString()
{
    QString s1("This "), s2("is a "), s3("string.");
    s1 += s2;
    QString s4 = s1 + s3;
    cout << s4 << endl;

    QString s5("The length of that string is: ");
    cout << s5 << s4.length() << " characters." << endl;
    cout << "Enter a sentence: " << endl;

    // getline(cin, s2);
    s2 = cin.readLine();
    cout << "Here is your sentence: \n" << s2 << endl;
    cout << "The length of your sentence is: " << s2.length() << endl;
}

void testTypeSize()
{
    char array1[34] = "This is a dreaded C array of char";
    char array2[] = "if not for main, we could avoid it entirely.";
    char* charp = array1;
    QString qstring = "This is a unicode QString. Much preferred.";

    int i = 12;

    Q_ASSERT(sizeof(i) == sizeof(int));

    cout <<" c type sizes: \n";
    cout << "sizeof(char) = " << sizeof(char) << '\n';
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << '\n';
    cout << "sizeof(int) = " << sizeof(int) << '\n';
    cout << "sizeof(long) = " << sizeof(long) << '\n';
    cout << "sizeof(float) = " << sizeof(float) << '\n';
    cout << "sizeof(double) = " << sizeof(double) << '\n';
    cout << "sizeof(double*) = " << sizeof(double*) << '\n';
    cout << "sizeof(array1) = " << sizeof(array1) << '\n';
    cout << "sizeof(array2) = " << sizeof(array2) << '\n';
    cout << "sizeof(char*) = " << sizeof(charp) << '\n';

    cout <<" qt type sizes: \n";
    cout << "sizeof(QString) = " << sizeof(QString) << '\n';
    cout << "sizeof(qint32) = " << sizeof(qint32) << '\n';
    cout << "sizeof(int) = " << sizeof(qint64) << '\n';
    cout << "sizeof(long) = " << sizeof(QChar) << '\n';
    cout << "sizeof(float) = " << sizeof(QDate) << '\n';
    cout << "qstring.length() = " << qstring.length() << '\n';
}

/*
void testFractionClass()
{
    Fraction f1, f2;
    f1.set(3, 4);
    f2.set(11, 12);


    cout << "The first fraction is: " << f1.toString() << endl;
    cout << "The second fraction, expressed as a double is: " << f2.toString() << endl;
} */

int main()
{


    // testFractionClass();
	testTypeSize();

    return 0;
}
