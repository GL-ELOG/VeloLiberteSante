/*
 * @File main.cxx
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */

#include <QFile>
#include <QDataStream>

#include "Bike.h"
#include "Controller.h"

#include <iostream>
using std::cout;
using std::endl;

namespace {

    void generate() {
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

}

int main() {
    /* generate(); */

    Controller<Bike> bikeControll ("bikes.txt");
    QVector<Bike*> bikes = bikeControll.getElems();
    for (int i(0); i < bikes.size(); ++i) {
        cout << "Bike :" << '\n'
             << "\tid=" << bikes[i]->getId() << '\n'
             << "\tcommDate="
             << bikes[i]->getCommissioningDate().toString().toStdString() << '\n'
             << "\tkmTravelled=" << bikes[i]->getKmTravelled() << endl;
    }

    return 0;
}
