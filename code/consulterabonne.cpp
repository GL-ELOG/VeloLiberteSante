#include "consulterabonne.h"
#include <QMessageBox>
#include "ui_consulterabonne.h"

ConsulterAbonne::ConsulterAbonne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsulterAbonne)
{
    ui->setupUi(this);
}

ConsulterAbonne::~ConsulterAbonne()
{
    delete ui;
}

void ConsulterAbonne::on_quitterBtnConAbo_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans imprimer les données ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void ConsulterAbonne::on_imprimerBtnConAbo_clicked()
{

}

void ConsulterAbonne::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
