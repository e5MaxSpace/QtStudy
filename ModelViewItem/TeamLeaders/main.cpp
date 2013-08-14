#include <QtGui/QApplication>
#include "teamleaders.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList leaders;
    leaders << "Stooge Viller" << "Littleface" << "B-B Eyes"
            << "Pruneface" << "Mrs. Pruneface" << "The Brow"
            << "Vitamin Flintheart" << "Flattop Sr." << "Shakey"
            << "Breathless Mahoney" << "Mumbles" << "Shoulders"
            << "Sketch Paree";

    TeamLeaders dialog(leaders);
    dialog.show();

    return a.exec();
}
