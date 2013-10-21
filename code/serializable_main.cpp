/*
 * @File main.cxx
 *
 * @Author Eloi PERDEREAU
 *
 * @Date 13-10-2013
 *
 */

#include <QFile>
#include <QDataStream>

#include "Bike.h"
#include "Emplacement.h"
#include "Station.h"
#include "Controller.h"

#include <iostream>
using std::cout;
using std::endl;
using std::flush;

namespace {

    void generateBikes() {
        QFile file (QString("bikes.txt"));
        file.open(QIODevice::WriteOnly);
        QDataStream out (&file);
        for (unsigned i(1); i < 5; ++i) {
            out << QString("VELO")
                << (quint16)i
                << QDate::currentDate()
                << (quint16)(i*100);
        }
        file.flush();
        file.close();
    }

    void generateEmplacements() {
        QFile file (QString("emplacements.txt"));
        file.open(QIODevice::WriteOnly);
        QDataStream out (&file);
        for (unsigned i(1); i < 5; ++i) {
            out << QString("EMPLACEMENT")
                << (quint16)0   // FREE
                << Bike(i, QDate::currentDate(), i*100);
        }
        file.flush();
        file.close();
    }

    void generateStations() {
        QFile file (QString("stations.txt"));
        file.open(QIODevice::WriteOnly);
        QDataStream out (&file);
        for (unsigned i(1); i < 5; ++i) {
            out << QString("STATION")
                << QString::number(i*2).append(QString(" rue consolat"))
                << (quint16)0;
        }
        file.flush();
        file.close();
    }

}

/* int main() { */
/*     generateBikes(); */
/*     generateEmplacements(); */
/*     generateStations(); */

/*     Controller<Bike> bikeController ("bikes.txt"); */
/*     Controller<Emplacement> emplacementController ("emplacements.txt"); */
/*     Controller<Station> stationController ("stations.txt"); */

/*     QVector<Bike*> bikes = bikeController.getElems(); */
/*     for (int i(0); i < bikes.size(); ++i) { */
/*         cout << "Bike :" << '\n' */
/*              << "\tid=" << bikes[i]->getId() << '\n' */
/*              << "\tcommDate=" */
/*              << bikes[i]->getCommissioningDate().toString().toStdString() << '\n' */
/*              << "\tkmTravelled=" << bikes[i]->getKmTravelled() << '\n'; */
/*     } */
/*     cout << endl; */

/*     QVector<Emplacement*> emplacements = emplacementController.getElems(); */
/*     for (int i(0); i < emplacements.size(); ++i) { */
/*         cout << "Emplacement :" << '\n' */
/*              << "\tstate=" << emplacements[i]->getState() << '\n' */
/*              << "\tbike=" << '\n' */
/*              << "\t\tid=" << emplacements[i]->getBike()->getId() << '\n' */
/*              << "\t\tcommDate=" */
/*              << emplacements[i]->getBike()->getCommissioningDate().toString().toStdString() << '\n' */
/*              << "\t\tkmTravelled=" << emplacements[i]->getBike()->getKmTravelled() << '\n'; */
/*     } */
/*     cout << endl; */

/*     QVector<Station*> stations = stationController.getElems(); */
/*     for (int i(0); i < stations.size(); ++i) { */
/*         cout << "Station :" << '\n' */
/*              << "\tlocalization=" << stations[i]->getLocalization().toStdString() << '\n' */
/*              << "\tnb emplacements=" << stations[i]->getEmplacements().size() << '\n'; */
/*     } */
/*     cout << flush; */

/*     return 0; */
/* } */
