#ifndef AJOUTERVELO_H
#define AJOUTERVELO_H

#include <QDialog>

namespace Ui {
class AjouterVelo;
}

class AjouterVelo : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterVelo(QWidget *parent = 0);
    ~AjouterVelo();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_annulerBtnAjVelo_clicked();
    void on_validerBtnAjVelo_clicked();

private:
    Ui::AjouterVelo *ui;
};

#endif // AJOUTERVELO_H
