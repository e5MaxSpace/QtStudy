#include "currencymodel.h"

CurrencyModel::CurrencyModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void CurrencyModel::setCurrencyMap(const QMap<QString, double> &currencyMap)
{
    m_currencyMap = currencyMap;
    //reset();
}

int CurrencyModel::rowCount(const QModelIndex &parent) const
{
    return m_currencyMap.count();
}

int CurrencyModel::columnCount(const QModelIndex &parent) const
{
    return m_currencyMap.count();
}

QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        QString rowCurrency = currencyAt(index.row());
        QString columnCurrency = currencyAt(index.column());

        if (m_currencyMap.value(rowCurrency) == 0.0)
            return QString("####");

        double amount = m_currencyMap.value(columnCurrency)/m_currencyMap.value(rowCurrency);

        return QString::number(amount, 'f', 4);
    }

    return QVariant();
}

//QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    Q_UNUSED(orientation);
//    if (role == Qt::DisplayRole)
//        return currencyAt(section);
//    return QVariant();
//}

QString CurrencyModel::currencyAt(int offset) const
{
    return (m_currencyMap.begin() + offset).key();
}
