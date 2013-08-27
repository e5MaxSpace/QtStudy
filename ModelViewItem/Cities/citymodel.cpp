#include "citymodel.h"

CityModel::CityModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void CityModel::setCities(const QStringList &cities)
{
    m_cities = cities;

    int size = rowCount() * (rowCount() - 1)/2;
    m_distances.resize( size );
    m_distances.fill(0);
}

int CityModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_cities.count();
}

int CityModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_cities.count();
}

bool CityModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && (index.row() != index.column()) && role == Qt::EditRole)
    {
        int offset = offsetOf(index.row(), index.column());
        m_distances[offset] = value.toInt();

        QModelIndex transposedIndex = createIndex(index.column(), index.row()); // index 对称一则的index

        emit dataChanged(index, index);
        emit dataChanged(transposedIndex, transposedIndex);
        return true;
    }

    return false;
}

QVariant CityModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        if (index.row() == index.column())
            return 0;
        int offset = offsetOf(index.row(), index.column());
        double distance = m_distances.at(offset);
        return distance;
    }

    return QVariant();
}

QVariant CityModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation);
    if (role == Qt::DisplayRole)
        return m_cities.at(section);

    return QVariant();
}

Qt::ItemFlags CityModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    if (index.row() != index.column())
        flags |= Qt::ItemIsEditable;

    return flags;
}

int CityModel::offsetOf(int row, int column) const
{
    if (row < column)
        qSwap(row, column);

    return (row *(row - 1)/2) + column;
}
