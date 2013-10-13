/*
 * @File Bike.cxx
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */

#include <string>
#include <iostream>

#include "Bike.h"

using namespace std;

Bike::Bike(int id, string libelle)
: id (id), libelle (libelle)
{}

Bike::~Bike() {}

int Bike::getId() { return this->id; }

void Bike::setId(int id) { this->id = id; }

ostream & Bike::serialize (ostream & os) const {
    return os << "VELO " << this->id << ' ' << this->libelle;
}

istream & Bike::deserialize (istream & is) {
    string str;
    is >> str;
    if (str != "VELO") {
        is.setstate(ios::failbit);
        return is;
    }
    return is >> this->id >> this->libelle;
}
