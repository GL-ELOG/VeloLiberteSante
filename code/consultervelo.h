#ifndef CONSULTERVELO_H
#define CONSULTERVELO_H

#include <QDialog>

namespace Ui {
class ConsulterVelo;
}

class ConsulterVelo : public QDialog
{
    Q_OBJECT

public:
    explicit ConsulterVelo(QWidget *parent = 0);
    ~ConsulterVelo();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_imprimerBtnConVelo_clicked();
    void on_quitterBtnConVelo_clicked();


private:
    Ui::ConsulterVelo *ui;
};

#endif // CONSULTERVELO_H
