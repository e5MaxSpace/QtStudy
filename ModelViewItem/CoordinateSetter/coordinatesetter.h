#ifndef COORDINATESETTER_H
#define COORDINATESETTER_H

#include <QDialog>

namespace Ui {
class CoordinateSetter;
}

class CoordinateSetter : public QDialog
{
    Q_OBJECT
    
public:
    explicit CoordinateSetter(QVector<QPointF> &coords, QWidget *parent = 0);
    ~CoordinateSetter();
    
private slots:
    void on_addRowBtn_clicked();

private:
    Ui::CoordinateSetter *ui;

    void addRow();
};

#endif // COORDINATESETTER_H
