#include "colornamesdialog.h"
#include "ui_colornamesdialog.h"

#include <QStringListModel>
#include <QSortFilterProxyModel>

ColorNamesDialog::ColorNamesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorNamesDialog)
{
    ui->setupUi(this);

    m_sourceModel = new QStringListModel(QColor::colorNames(), this);

    m_proxyModel = new QSortFilterProxyModel(this);
    m_proxyModel->setSourceModel(m_sourceModel);
    m_proxyModel->setFilterKeyColumn(0);  // 依据初始模型的哪一列进行排序！

    ui->listView->setModel(m_proxyModel);

    ui->syntaxComboBox->addItem(tr("Regular expression"), QRegExp::RegExp);
    ui->syntaxComboBox->addItem(tr("WildCard"), QRegExp::Wildcard);
    ui->syntaxComboBox->addItem(tr("Fixed string"), QRegExp::FixedString);
}

ColorNamesDialog::~ColorNamesDialog()
{
    delete ui;
}

void ColorNamesDialog::on_filterLineEdit_textChanged(const QString &text)
{
    reapplyFilter();
}

void ColorNamesDialog::on_syntaxComboBox_currentIndexChanged(int index)
{
    reapplyFilter();
}

void ColorNamesDialog::reapplyFilter()
{
    //QVariant QComboBox::itemData ( int index, int role = Qt::UserRole ) const
    //Returns the data for the given role in the given index in the combobox,
    //or QVariant::Invalid if there is no data for this role.
    QRegExp::PatternSyntax syntax =
            QRegExp::PatternSyntax(ui->syntaxComboBox->itemData(ui->syntaxComboBox->currentIndex()).toInt());

    //QRegExp ( const QString & pattern, Qt::CaseSensitivity cs = Qt::CaseSensitive, PatternSyntax syntax = RegExp )
    QRegExp regExp(ui->filterLineEdit->text(), Qt::CaseInsensitive, syntax);
    //filterRegExp : QRegExp
    //This property holds the QRegExp used to filter the contents of the source model.
    //QRegExp filterRegExp () const
    //void setFilterRegExp ( const QRegExp & regExp )
    //void setFilterRegExp ( const QString & pattern )
    m_proxyModel->setFilterRegExp(regExp);
}
