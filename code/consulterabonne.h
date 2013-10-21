#ifndef CONSULTERABONNE_H
#define CONSULTERABONNE_H

#include <QDialog>

namespace Ui {
class ConsulterAbonne;
}

class ConsulterAbonne : public QDialog
{
    Q_OBJECT

public:
    explicit ConsulterAbonne(QWidget *parent = 0);
    ~ConsulterAbonne();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_imprimerBtnConAbo_clicked();
    void on_quitterBtnConAbo_clicked();

private:
    Ui::ConsulterAbonne *ui;
};

#endif // CONSULTERABONNE_H
