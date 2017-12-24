#include <QCoreApplication>
#include <QDebug>
#include "argumentlist.h"

ArgumentList::ArgumentList()
{
	if (qApp != NULL) {
		*this = qApp->arguments();
	}
}

bool ArgumentList::getSwitch(QString option)
{
	QMutableStringListIterator itr(*this);
	while (itr.hasNext()) {
		if (option == itr.next()) {
			itr.remove();
			return true;
		}
	}
	return false;
}

QString ArgumentList::getSwitchArg(QString option, QString defaultValue)
{
	if (isEmpty()) {
		return defaultValue;
	}
	QMutableStringListIterator itr(*this);
	while (itr.hasNext()) {
		if (option == itr.next()) {
			itr.remove();
			if (itr.hasNext()) {
				QString retVal = itr.next();
				itr.remove();
				return retVal;
			}
			else {
				qDebug() << "Missing Argument for " << option;
				return QString();
			}
		}
	}
	return defaultValue;
}

void ArgumentList::argsToStringlist(int argc, char * argv[])
{
	for (int i = 0; i < argc; ++i) {
		*this += argv[i];
	}
}
