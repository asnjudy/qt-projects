#pragma once

#include <QList>
#include <QString>

class Account;

class Bank {
public:
	Bank& operator<< (Account* acct);
	~Bank();
	QString getAcctListing() const;
private:
	QList<Account*> m_Accounts;
};