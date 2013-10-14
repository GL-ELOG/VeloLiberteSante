/*
 * @File main.cxx
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */

#include <QDebug>
#include <sstream>
#include <iostream>

#include "Bike.h"
#include "Controller.h"

using namespace std;

int main() {

    Bike b0 (1, "un_velo");
    Bike b1 (2, "un_autre_velo");

    /* serialization * /
    stringstream sstr;
    sstr << b0;
    cout << "dans sstr se trouve : " << sstr.str() << endl;
    sstr >> b1;
    cout << "on a reussi a extraire b1 : " << b1 << endl;
    /* serialization */

    /* controller */
    Bike * b2 = new Bike(3, "un velo mortel");
    {
        Controller<Bike> bikeController ("bikes.txt");
        bikeController.addElem(b2);

        QVector<Bike*> bikes = bikeController.getElems();
        /* qDebug() << "controller has " << bikes.size() << " bikes" << endl; */
        for (int i(0); i < bikes.size(); ++i) {
            // :'(
            /* qDebug() << *bikes[i] << endl; */
        }
    }
    /* qDebug() << "et mainteant b2 est mort : " << b2 << endl; */
    /* controller */

    return 0;
}
