#ifndef AJOUTERABONNE_H
#define AJOUTERABONNE_H

#include <QDialog>

namespace Ui {
class AjouterAbonne;
}

class AjouterAbonne : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterAbonne(QWidget *parent = 0);
    ~AjouterAbonne();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnAjAbo_clicked();
    void on_validerBtnAjAbo_clicked();

private:
    Ui::AjouterAbonne *ui;
};

#endif // AJOUTERABONNE_H
