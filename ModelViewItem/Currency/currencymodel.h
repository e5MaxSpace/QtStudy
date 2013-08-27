#ifndef CURRENCYMODEL_H
#define CURRENCYMODEL_H

#include <QAbstractTableModel>

class CurrencyModel : public QAbstractTableModel
{
public:
    explicit CurrencyModel(QObject *parent = 0);

    void setCurrencyMap(const QMap<QString, double> &currencyMap);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

    //virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QString currencyAt(int offset) const;

private:
    QMap<QString/*货币编码*/, double/*对美元的汇率*/> m_currencyMap;

};

#endif // CURRENCYMODEL_H
