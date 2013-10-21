#include "modifierstation.h"
#include <QMessageBox>
#include "ui_modifierstation.h"

ModifierStation::ModifierStation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierStation)
{
    ui->setupUi(this);
}

ModifierStation::~ModifierStation()
{
    delete ui;
}

void ModifierStation::on_annulerBtnModSta_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans appliquer les modifications ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void ModifierStation::on_validerBtnModSta_clicked()
{

}

void ModifierStation::changeEvent(QEvent *e)
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
