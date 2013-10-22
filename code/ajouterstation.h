#ifndef AJOUTERSTATION_H
#define AJOUTERSTATION_H

#include <QDialog>
#include <QTableView>

#include "stationtablemodel.h"
#include "Controller.h"
#include "Station.h"

namespace Ui {
class AjouterStation;
}

class AjouterStation : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterStation(QTableView * staTable, QWidget *parent = 0);
    ~AjouterStation();

protected:
    Controller<Station> staController;
    QTableView * staTable;
    StationTableModel model;
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnAjSta_clicked();
    void on_validerBtnAjSta_clicked();

private:
    Ui::AjouterStation *ui;
};

#endif // AJOUTERSTATION_H
