#include "ajouterstation.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "ui_ajouterstation.h"

AjouterStation::AjouterStation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterStation)
{
    ui->setupUi(this);
}

AjouterStation::~AjouterStation()
{
    delete ui;
}

void AjouterStation::on_annulerBtnAjSta_clicked()
{
    int r = QMessageBox::warning(this, "Confirmation", "Voulez-vous quitter sans ajouter de station ?", QMessageBox::Yes, QMessageBox::No);
    if (r == QMessageBox::Yes)
        this->close();
}

void AjouterStation::on_validerBtnAjSta_clicked()
{
    //Récupération des données dans une classe d'abonné


    // Création d'un objet QFile
    QFile file("Stations.txt");
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);
    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    flux.setCodec("UTF-8");

    // Écriture des différentes lignes dans le fichier


    //fermeture de la fenetre
    this->close();
}

void AjouterStation::changeEvent(QEvent *e)
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
