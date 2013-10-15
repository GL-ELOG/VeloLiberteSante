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
#include <QDebug>

#include "Bike.h"
#include "Controller.h"

using namespace std;

namespace {

    void generate() {
        QFile file (QString("bikes.txt"));
        file.open(QIODevice::WriteOnly);
        QDataStream out (&file);

        for (unsigned i(0); i < 5; ++i) {
            out << QString("VELO")
                << (qint16)i
                << QString("le velo no ").append(QString::number(i));
        }
        file.flush();
        file.close();
    }

}

int main() {
    /* generate(); */

    Bike b0 (1, "un_velo");
    Bike b1 (2, "un_autre_velo");

    /* serialization * /
    stringstream sstr;
    sstr << b0;
    cout << "dans sstr se trouve : " << sstr.str() << endl;
    sstr >> b1;
    cout << "on a reussi a extraire b1 : " << b1 << endl;
    /* serialization */

    Controller<Bike> bikeControll ("bikes.txt");

    return 0;
}
