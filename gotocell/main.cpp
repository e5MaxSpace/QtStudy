#include <QApplication>
#include <QDialog>

#include "gotocelldialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GoToCellDialog *dialog = new GoToCellDialog;
    dialog->show();

    return a.exec();
}
