#ifndef AJOUTERBORNE_H
#define AJOUTERBORNE_H

#include <QDialog>

namespace Ui {
class AjouterBorne;
}

class AjouterBorne : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterBorne(QWidget *parent = 0);
    ~AjouterBorne();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnAjBor_clicked();
    void on_validerBtnAjBor_clicked();

private:
    Ui::AjouterBorne *ui;
};

#endif // AJOUTERBORNE_H
