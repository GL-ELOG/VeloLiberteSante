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
    return os << QString("VELO")
              << (qint16)this->id
              << this->libelle;
}

QDataStream & Bike::deserialize (QDataStream & is) {
    QString str;
    is >> str;
    if (0 != str.compare(QString("VELO"))) {
        is.setStatus(QDataStream::ReadCorruptData);
        return is;
    }
    return is >> this->id >> this->libelle;
}
