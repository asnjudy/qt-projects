#include "mainwindow.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int answer = 0;

    do
    {
        int factArg = 0;
        int fact(1);
        factArg = QInputDialog::getInt(0, "Factorial Calculator",
                                       "Factorial of:", 1);
        cout << "User entered: " << factArg << endl;
        int i = 2;
        while (i <= factArg)
        {
            fact = fact * i;
            ++i;
        }
        QString resp = QString("The factorial of %1 is %2.\n%3")
                .arg(factArg)
                .arg(fact)
                .arg("Do you want to compute another factorial?");
        answer = QMessageBox::question(0, "Play again?", resp, QMessageBox::Yes | QMessageBox::No);
    } while (answer == QMessageBox::Yes);

    MainWindow w;
    w.show();

    return a.exec();
}
