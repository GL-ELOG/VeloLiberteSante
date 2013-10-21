#ifndef MODIFIERVELO_H
#define MODIFIERVELO_H

#include <QDialog>

namespace Ui {
class ModifierVelo;
}

class ModifierVelo : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierVelo(QWidget *parent = 0);
    ~ModifierVelo();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnModVelo_clicked();
    void on_validerBtnModVelo_clicked();

private:
    Ui::ModifierVelo *ui;
};

#endif // MODIFIERVELO_H
