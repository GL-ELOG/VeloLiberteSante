/*
 * @File main.cxx
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */

#include <iostream>
#include <sstream>

#include "Bike.h"

using namespace std;

int main() {

    Bike b0 (1, "un_velo");
    Bike b1;

    stringstream sstr;
    sstr << b0;
    cout << "dans sstr se trouve : " << sstr.str() << endl;
    sstr >> b1;
    cout << "on a reussi a extraire b1 : " << b1 << endl;

    return 0;
}
