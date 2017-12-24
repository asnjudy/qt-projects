#include <iostream>
#include <QTextStream>
#include <QDebug>
#include "derivation\overload\account.h"
#include "derivation\overload\animal.h"
#include "derivation\assigncopy\bank.h"
#include "derivation\argumentlist\argumentlist.h"
#include "std2qt.h"
using namespace std2qt;

void testAccount()
{
	InsecureAccount acct(12345, 321.98, "Luke Skywalker");
	acct.deposit(6, QDate());
	cout << acct.toString() << endl;

	cout << "currentDate: " << QDate::currentDate().toString() << endl;
}

void testAnimal()
{
	Animal a1(10, 12);
	Fish f1(100, 20);
}

void testJointAccout()
{
	JointAccount ja(101, 0.0, "Lucy", "xxx");
	Account ja2 = ja;
	cout << &ja << endl;
	cout << &ja2 << endl;
}

void testBank()
{
	QString listing;
	{
		Bank bank;
		Account* a1 = new Account(1, 423, "Gene Kelly");
		JointAccount* a2 = new JointAccount(2, 1541, "Fred Astaire", "Ginger Rodgers");
		JointAccount* a3 = new JointAccount(*a1, "Leslie Caron");

		bank << a1;
		bank << a2;
		bank << a3;

		JointAccount* a4 = new JointAccount(*a3);
		bank << a4;

		listing = bank.getAcctListing();
	}

	qDebug() << listing;
	qDebug() << "Now exit program";
}


void runTestOnly(QStringList & arglist, bool verbose)
{
	foreach(const QString &current, arglist) {
		if (verbose) {
			qDebug() << QString("Do something chatty with %1.").arg(current);
		}
		else {
			qDebug() << current;
		}
	}		
}

void testArgumentList(int argc, char *argv[])
{
	ArgumentList arglist(argc, argv);
	QString appname = arglist.takeFirst();

	qDebug() << "Running " << appname;

	bool verbose = arglist.getSwitch("-v");
	bool testing = arglist.getSwitch("-t");

	if (testing) {
		runTestOnly(arglist, verbose);
	}
	else {
		qDebug() << "This is not a test";
	}
}


