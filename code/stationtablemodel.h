#ifndef STATIONTABLEMODEL_H
#define STATIONTABLEMODEL_H

#include <QAbstractTableModel>

#include "Station.h"

class StationTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit StationTableModel(QObject *parent = 0);
    explicit StationTableModel(QVector<Station*> stationsList, QObject *parent = 0);

    void fillHeaders();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());
    QVector<Station*> getList();

private:
    QVector<QString> headers;
    QVector<Station*> stationsList;

signals:

public slots:

};

#endif // STATIONTABLEMODEL_H
