#ifndef MODIFIERABONNE_H
#define MODIFIERABONNE_H

#include <QDialog>

namespace Ui {
class ModifierAbonne;
}

class ModifierAbonne : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierAbonne(QWidget *parent = 0);
    ~ModifierAbonne();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnModAbo_clicked();
    void on_validerBtnModAbo_clicked();

private:
    Ui::ModifierAbonne *ui;
};

#endif // MODIFIERABONNE_H
