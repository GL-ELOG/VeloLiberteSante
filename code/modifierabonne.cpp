#include "modifierabonne.h"
#include <QMessageBox>
#include "ui_modifierabonne.h"

ModifierAbonne::ModifierAbonne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierAbonne)
{
    ui->setupUi(this);
}

ModifierAbonne::~ModifierAbonne()
{
    delete ui;
}

void ModifierAbonne::on_annulerBtnModAbo_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans ajouter de nouvel abonné ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void ModifierAbonne::on_validerBtnModAbo_clicked()
{

}

void ModifierAbonne::changeEvent(QEvent *e)
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
