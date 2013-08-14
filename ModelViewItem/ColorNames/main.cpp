#include <QtGui/QApplication>
#include "colornamesdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ColorNamesDialog dialog;
    dialog.show();
    
    return a.exec();
}
