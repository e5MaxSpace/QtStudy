#include "flowchartsymbolpicker.h"
#include "ui_flowchartsymbolpicker.h"

FlowChartSymbolPicker::FlowChartSymbolPicker(const QMap<int, QString> &symbols, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FlowChartSymbolPicker),
    m_id(-1)
{
    ui->setupUi(this);

    ui->listWidget->setIconSize(QSize(60, 60));

    QMapIterator<int, QString> iter(symbols);
    while (iter.hasNext())
    {
        iter.next();

        int id = iter.key();
        QString symbolName = iter.value();
        QIcon symbolIcon = iconForSymbol(symbolName);

        QListWidgetItem *item = new QListWidgetItem(symbolIcon, symbolName,  ui->listWidget);
        item->setData(Qt::UserRole, QVariant(id));
    }
}

FlowChartSymbolPicker::~FlowChartSymbolPicker()
{
    delete ui;
}

int FlowChartSymbolPicker::selectedId() const
{
    return m_id;
}

void FlowChartSymbolPicker::done(int r)
{
    m_id = -1;
    if (r == QDialog::Accepted)
    {
        QListWidgetItem *item = ui->listWidget->currentItem();
        if (item != NULL)
            item->data(Qt::UserRole).toInt();
    }
    QDialog::done(r);
}

QIcon FlowChartSymbolPicker::iconForSymbol(const QString &symbolName) const
{
    QString fileName = "./images/" + symbolName.toLower();
    fileName.replace(' ', '-'); // 图片的文件名称里是‘-’号
    return QIcon(fileName);
}


