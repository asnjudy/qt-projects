#include <QDebug>
#include "std2qt.h"
#include "account.h"

using namespace std2qt;

// 构造函数，给账号赋予初值
Account::Account(unsigned acctno, double ba1, QString owner) :
	m_AcctNo(acctno), m_Balance(ba1), m_Owner(owner)
{
}

Account::~Account()
{
	qDebug() << this << " Closing Acct - sending email to primary acctholder: " << m_Owner;
}

// 向账号里存钱
void Account::deposit(double amt)
{
	cout << QString("Before deposit(%1): ").arg(amt) << this << endl;
	m_Balance += amt;
	cout << QString("After deposit(%1): ").arg(amt) << this << endl;
}
// 返回账号信息
QString Account::toString() const
{
	// 默认使用","分隔
	return QString("Account=%1, Owner=%2, Balance=%3\n")
		.arg(m_AcctNo)
		.arg(m_Owner)
		.arg(m_Balance);
}
// 使用指定的分隔符返回账号信息
QString Account::toString(char delimiter)
{
	return QString("Account=%1").arg(m_AcctNo) + QString(delimiter)
		+ QString("Owner=%1").arg(m_Owner) + QString(delimiter)
		+ QString("Balance=%1").arg(m_Balance) + QString('\n');
}

// 调用父类Account的构造函数
InsecureAccount::InsecureAccount(unsigned acctno, double ba1, QString owner)
	: Account(acctno, ba1, owner)
{
}

QString InsecureAccount::toString() const
{
	return Account::toString();
}

void InsecureAccount::deposit(double amt, QDate postDate)
{
	cout << QString("Before deposit(%1): %2, %3\n").arg(amt).arg(toString()).arg(postDate.toString());
	m_Balance += amt;
	cout << QString("After deposit(%1): %2, %3\n").arg(amt).arg(toString()).arg(postDate.toString());
}


JointAccount::JointAccount(unsigned acctNum, double balance, QString owner, QString jowner)
	: Account(acctNum, balance, owner), m_JointOwner(jowner) {}

/**
* 复制构造函数，调用基类Account默认的复制构造函数Account::Account(const Account&)
*/
JointAccount::JointAccount(const Account & acct, QString jowner)
	: Account(acct), m_JointOwner(jowner) {}

JointAccount::~JointAccount()
{
	qDebug() << this << " Closing Joint Acct - sending email to joint acctbolder: " << m_JointOwner;
}
