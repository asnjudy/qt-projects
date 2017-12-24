#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDate>
#include <QString>

class Account {
public:
	Account(unsigned acctno, double ba1, QString owner);
	virtual ~Account();

	virtual void deposit(double amt);
	virtual QString toString() const;
	virtual QString toString(char delimiter); // ����
	virtual QString getName() const { return m_Owner; }

protected:
	unsigned m_AcctNo;
	double m_Balance;
	QString m_Owner;
};

class InsecureAccount : public Account {
public:
	InsecureAccount(unsigned acctno, double ba1, QString owner);
	QString toString() const; // ����Account��toString���������� toString(char)
	void deposit(double amt, QDate postDate); // û�������κη��������������˻����Account::deposit()����
};

class JointAccount : public Account {
public:
	JointAccount(unsigned acctNum, double balance, QString owner, QString jowner);
	JointAccount(const Account &acct, QString jowner);
	~JointAccount();
	QString getName() const {
		return QString("%1 and %2").arg(Account::getName()).arg(m_JointOwner);
	}
private:
	QString m_JointOwner;
};
#endif