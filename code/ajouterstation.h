#ifndef AJOUTERSTATION_H
#define AJOUTERSTATION_H

#include <QDialog>

namespace Ui {
class AjouterStation;
}

class AjouterStation : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterStation(QWidget *parent = 0);
    ~AjouterStation();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnAjSta_clicked();
    void on_validerBtnAjSta_clicked();

private:
    Ui::AjouterStation *ui;
};

#endif // AJOUTERSTATION_H
