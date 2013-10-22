#include "stationtablemodel.h"
#include "Emplacement.h"

#include <QMessageBox>

StationTableModel::StationTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    fillHeaders();
}

StationTableModel::StationTableModel(QVector<Station*> stationsList, QObject *parent):
    QAbstractTableModel(parent), stationsList (stationsList)
{
    fillHeaders();
}

void StationTableModel::fillHeaders() {
    headers.clear();
    headers.push_back("id");
    headers.push_back("loc");
    headers.push_back("nb");
    headers.push_back("libre");
    headers.push_back("occ");
    headers.push_back("hs");
}

int StationTableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return stationsList.size();
}

int StationTableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 6;
}

QVariant StationTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= stationsList.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        Station * station = stationsList.at(index.row());

        if (index.column() == 0) {  // id
            return station->getLocalization();
        }
        else if (index.column() == 1) {  // localization
            return station->getLocalization();
        }
        else if (index.column() == 2) {  // nb_emps
            return station->getEmplacements().size();
        }
        else {
            unsigned n = 0;
            QVector<Emplacement*> emps = station->getEmplacements();
            for (int i(0); i < emps.size(); ++i) {
                // increment if column desired is the state of current emp
                n += index.column()+3 == emps.at(i)->getState();
            }
            return QString::number(n);
        }

    }
    return QVariant();
}

QVariant StationTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        return headers.at(section);
    }
    return QVariant();
}

Qt::ItemFlags StationTableModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool StationTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        Station * s = stationsList.value(row);

        if (index.column() == 0)
            s->getLocalization() = value.toString();
        else
            return false;

        stationsList.replace(row, s);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

bool StationTableModel::insertRows(int position, int rows, const QModelIndex &index) {
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        //Station sta (QString("sta1"), QVector<Emplacement*>());
        Station * sta = new Station();
        stationsList.insert(position, sta);
    }
    endInsertRows();
    return true;
}

bool StationTableModel::removeRows(int position, int rows, const QModelIndex &index) {
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        stationsList.remove(position);
    }
    endRemoveRows();
    return true;
}

QVector<Station*> StationTableModel::getList() {
    return stationsList;
}

