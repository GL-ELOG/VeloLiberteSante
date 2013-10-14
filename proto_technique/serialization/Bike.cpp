/*
 * @File Bike.cxx
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */

#include <QString>
#include <QDataStream>

#include "Bike.h"

Bike::Bike(int id, QString libelle)
: id (id), libelle (libelle)
{}

Bike::~Bike() {}

int Bike::getId() { return this->id; }

void Bike::setId(int id) { this->id = id; }

QDataStream & Bike::serialize (QDataStream & os) const {
    return os << "VELO " << this->id << ' ' << this->libelle.constData();
}

QDataStream & Bike::deserialize (QDataStream & is) {
    char ch [5];
    is.readRawData(ch, 4);
    ch[4] = '\0';
    if (0 != strcmp(ch, "VELO")) {
        is.setStatus(QDataStream::ReadCorruptData);
        return is;
    }
    return is >> this->id >> this->libelle;
}
