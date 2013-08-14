#include "coordinatesetter.h"
#include "ui_coordinatesetter.h"

CoordinateSetter::CoordinateSetter(QVector<QPointF> &coords, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoordinateSetter)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<tr("X")<<tr("Y"));
    for(QVector<QPointF>::size_type iRow=0; iRow<coords.size(); ++iRow)
    {
        addRow();
        ui->tableWidget->item(iRow, 0)->setText(QString::number(coords.at(iRow).x()));
        ui->tableWidget->item(iRow, 1)->setText(QString::number(coords.at(iRow).y()));
    }
}

CoordinateSetter::~CoordinateSetter()
{
    delete ui;
}

void CoordinateSetter::on_addRowBtn_clicked()
{
    addRow();
}

void CoordinateSetter::addRow()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *item0 = new QTableWidgetItem();
    item0->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(row, 0, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem();
    item1->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(row, 1, item1);

    ui->tableWidget->setCurrentItem(item0);
}
