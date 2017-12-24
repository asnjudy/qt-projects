#include <QDebug>
#include "bank.h"
#include "..\overload\account.h"

Bank & Bank::operator<<(Account * acct)
{
	m_Accounts << acct;
	return *this;
}

Bank::~Bank()
{
	qDeleteAll(m_Accounts);
	m_Accounts.clear();
}

QString Bank::getAcctListing() const
{
	QString listing("\n");
	foreach(Account* acct, m_Accounts) 
		listing += QString("%1\n").arg(acct->getName());
	
	return listing;
}
