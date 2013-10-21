#include "consultervelo.h"
#include <QMessageBox>
#include "ui_consultervelo.h"

ConsulterVelo::ConsulterVelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsulterVelo)
{
    ui->setupUi(this);
}

ConsulterVelo::~ConsulterVelo()
{
    delete ui;
}

void ConsulterVelo::on_quitterBtnConVelo_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans imprimer les données ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void ConsulterVelo::on_imprimerBtnConVelo_clicked()
{

}

void ConsulterVelo::changeEvent(QEvent *e)
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
