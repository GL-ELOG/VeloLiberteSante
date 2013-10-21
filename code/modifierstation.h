#ifndef MODIFIERSTATION_H
#define MODIFIERSTATION_H

#include <QDialog>

namespace Ui {
class ModifierStation;
}

class ModifierStation : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierStation(QWidget *parent = 0);
    ~ModifierStation();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnModSta_clicked();
    void on_validerBtnModSta_clicked();

private:
    Ui::ModifierStation *ui;
};

#endif // MODIFIERSTATION_H
