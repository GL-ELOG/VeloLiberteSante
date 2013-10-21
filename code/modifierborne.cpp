#include "modifierborne.h"
#include <QMessageBox>
#include "ui_modifierborne.h"

ModifierBorne::ModifierBorne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifierBorne)
{
    ui->setupUi(this);
}

ModifierBorne::~ModifierBorne()
{
    delete ui;
}

void ModifierBorne::on_annulerBtnModBor_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans appliquer les modifications ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void ModifierBorne::on_validerBtnModBor_clicked()
{

}

void ModifierBorne::changeEvent(QEvent *e)
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
