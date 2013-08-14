#include "teamleaders.h"
#include "ui_teamleaders.h"

#include <QStringListModel>

TeamLeaders::TeamLeaders(const QStringList &leaders, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamLeaders)
{
    ui->setupUi(this);

    ui->listView->setModel(new QStringListModel(leaders));
}

TeamLeaders::~TeamLeaders()
{
    delete ui;
}

QStringList TeamLeaders::leaders() const
{
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->listView->model());
    if (model)
        return model->stringList();

    return QStringList();
}

void TeamLeaders::on_insertButton_clicked()
{
    int row = ui->listView->currentIndex().row();
    // Inserts a single row before the given row in the child items of the parent specified.
    ui->listView->model()->insertRow(row);

    QModelIndex modelIndex = ui->listView->model()->index(row, 0);
    ui->listView->setCurrentIndex(modelIndex);
    ui->listView->edit(modelIndex);
}

void TeamLeaders::on_deleteButton_clicked()
{
    ui->listView->model()->removeRow(ui->listView->currentIndex().row());
}
