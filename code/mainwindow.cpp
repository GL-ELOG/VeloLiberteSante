#include "mainwindow.h"
#include "ajouterstation.h"
#include "ajouterborne.h"
#include "ajoutervelo.h"
#include "ajouterabonne.h"
#include "modifierstation.h"
#include "modifierborne.h"
#include "modifiervelo.h"
#include "modifierabonne.h"
#include "consulterabonne.h"
#include "consultervelo.h"
#include "ui_mainwindow.h"
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*Ajuste la largeur des colonnes du QTableWidget pour les stations*/
    ui->tableWidgetStations->horizontalHeader()->resizeSection(0, 60); /*Identifiant*/
    ui->tableWidgetStations->horizontalHeader()->resizeSection(1, 140);/*Localisation*/
    ui->tableWidgetStations->horizontalHeader()->resizeSection(2, 90);/*Nombre de bornes*/
    ui->tableWidgetStations->horizontalHeader()->resizeSection(3, 120);/*Nombres de bornes libres*/
    ui->tableWidgetStations->horizontalHeader()->resizeSection(4, 125);/*Nombre de bornes occupées*/
    ui->tableWidgetStations->horizontalHeader()->resizeSection(5, 100);/*Nombre de bornes HS*/

    /*Ajuste la largeur des colonnes du QTableWidget pour les bornes*/
    ui->tableWidgetBornes->horizontalHeader()->resizeSection(0, 60);/*Identifiant*/

    /*Ajuste la largeur des colonnes du QTableWidget pour les velos*/
    ui->tableWidgetVelos->horizontalHeader()->resizeSection(0, 60);/*Identifiant*/
    ui->tableWidgetVelos->horizontalHeader()->resizeSection(1, 150);/*Etat*/

    /*Ajuste la largeur des colonnes du QTableWidget pour les abonnes*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(0, 80);/*Nom*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(1, 100);/*Prenom*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(2, 30);/*Sexe*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(3, 90);/*Date de naissance*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(4, 100);/*Date d'abonnement*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(5, 150);/*Adresse*/
    ui->tableWidgetAbonnes->horizontalHeader()->resizeSection(6, 60);/*Telephone*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*Stations*/
void MainWindow::on_stationBtnAj_clicked()
{
    AjouterStation *formulaire= new AjouterStation();
    formulaire->show();
}
void MainWindow::on_stationBtnMod_clicked()
{
    ModifierStation *formulaire= new ModifierStation();
    formulaire->show();
}
void MainWindow::on_stationBtnSup_clicked()
{

}

/*Bornes*/
void MainWindow::on_borneBtnAj_clicked()
{
    AjouterBorne *formulaire= new AjouterBorne();
    formulaire->show();
}
void MainWindow::on_borneBtnMod_clicked()
{
    ModifierBorne *formulaire= new ModifierBorne();
    formulaire->show();
}
void MainWindow::on_borneBtnSup_clicked()
{

}

/*Velos*/
void MainWindow::on_veloBtnAj_clicked()
{
    AjouterVelo *formulaire= new AjouterVelo();
    formulaire->show();
}
void MainWindow::on_veloBtnMod_clicked()
{
    ModifierVelo *formulaire= new ModifierVelo();
    formulaire->show();
}
void MainWindow::on_veloBtnSup_clicked()
{

}
void MainWindow::on_veloBtnCon_clicked()
{
    ConsulterVelo *formulaire= new ConsulterVelo();
    formulaire->show();
}

/*Abonnes*/
void MainWindow::on_abonneBtnAj_clicked()
{
    AjouterAbonne *formulaire= new AjouterAbonne();
    formulaire->show();
}
void MainWindow::on_abonneBtnMod_clicked()
{
    ModifierAbonne *formulaire= new ModifierAbonne();
    formulaire->show();
}
void MainWindow::on_abonneBtnSup_clicked()
{

}
void MainWindow::on_abonneBtnCon_clicked()
{
    ConsulterAbonne *formulaire= new ConsulterAbonne();
    formulaire->show();
}


void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
