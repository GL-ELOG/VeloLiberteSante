#include "ajouterabonne.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "ui_ajouterabonne.h"
#include "ui_mainwindow.h"

AjouterAbonne::AjouterAbonne(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterAbonne)
{
    ui->setupUi(this);
}

AjouterAbonne::~AjouterAbonne()
{
    delete ui;
}

void AjouterAbonne::on_annulerBtnAjAbo_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans ajouter de nouvel abonné ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void AjouterAbonne::on_validerBtnAjAbo_clicked()
{
    //Récupération des données
    /*QString nom, prenom, adresse, tel, sexe, dateNais, dateAbo;

    ui->lineEditAjNomAbo->setReadOnly(true);
    nom = ui->lineEditAjNomAbo->text();

    ui->lineEditAjPreAbo->setReadOnly(true);
    prenom = ui->lineEditAjPreAbo->text();

    ui->lineEditAjAdrAbo->setReadOnly(true);
    adresse = ui->lineEditAjAdrAbo->text();

    ui->lineEditAjTelAbo->setReadOnly(true);
    tel = ui->lineEditAjTelAbo->text();

    dateNais = ui->dateEditAjDnAbo->date().toString("dd/MM/yyyy");

    dateAbo = ui->dateEditAjDaAbo->date().toString("dd/MM/yyyy");

    foreach(QRadioButton *radioButton, this->findChildren<QRadioButton *>())
    {
        if (radioButton->isChecked())
        {
             sexe = radioButton->text();
        }
    }*/

    // Création d'un objet QFile
    QFile file("Abonnes.txt");
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);
    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    flux.setCodec("UTF-8");

    // Écriture des différentes lignes dans le fichier
    //flux << nom << "," << prenom << "," << sexe << "," << dateNais << "," << dateAbo << "," << adresse << "," << tel << endl;

    //fermeture de la fenetre
    this->close();
}

void AjouterAbonne::changeEvent(QEvent *e)
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
