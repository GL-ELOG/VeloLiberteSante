#ifndef MODIFIERBORNE_H
#define MODIFIERBORNE_H

#include <QDialog>

namespace Ui {
class ModifierBorne;
}

class ModifierBorne : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierBorne(QWidget *parent = 0);
    ~ModifierBorne();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnModBor_clicked();
    void on_validerBtnModBor_clicked();

private:
    Ui::ModifierBorne *ui;
};

#endif // MODIFIERBORNE_H
