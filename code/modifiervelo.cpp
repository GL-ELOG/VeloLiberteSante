#include "modifiervelo.h"
#include <QMessageBox>
#include "ui_modifiervelo.h"

ModifierVelo::ModifierVelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierVelo)
{
    ui->setupUi(this);
}

ModifierVelo::~ModifierVelo()
{
    delete ui;
}

void ModifierVelo::on_annulerBtnModVelo_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans appliquer les modifications ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void ModifierVelo::on_validerBtnModVelo_clicked()
{

}

void ModifierVelo::changeEvent(QEvent *e)
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
