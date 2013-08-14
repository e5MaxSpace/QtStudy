#include <QtGui/QApplication>
#include "settingsviewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingsViewer w;
    w.show();
    
    return a.exec();
}
