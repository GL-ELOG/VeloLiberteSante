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

/*!
 * \brief Constructs a Bike
 * \param id
 * \param commissioningDate
 * \param kmTravelled
 */
Bike::Bike(qint16 id /* = 0 */,
     QDate commissioningDate /* = QDate() */,
     quint16 kmTravelled /* = 0 */)
: id (id), commissioningDate (commissioningDate), kmTravelled (kmTravelled)
{}

/*!
 * \brief Destructs the Bike
 */
Bike::~Bike() {}

/*!
 * \brief serialize a Bike
 * \param the output stream where to serialize
 * \return the stream after serialization
 */
QDataStream & Bike::serialize (QDataStream & os) const {
    return os << QString("VELO")
              << this->id
              << this->commissioningDate
              << this->kmTravelled;
}

/*!
 * \brief deserialize a Bike
 * \param the input stream where to deserialize
 * \return the stream after deserialization
 */
QDataStream & Bike::deserialize (QDataStream & is) {
    QString str;
    is >> str;
    if (0 != str.compare(QString("VELO"))) {
        is.setStatus(QDataStream::ReadCorruptData);
        return is;
    }
    return is >> this->id
              >> this->commissioningDate
              >> this->kmTravelled;
}

/*!
 * \brief getter of the field id
 * \return the id of the bike
 */
qint16 Bike::getId() {
    return this->id;
}

/*!
 * \brief the setter of the field id
 * \param the new id
 */
void Bike::setId(qint16 id) {
    this->id = id;
}

/*!
 * \brief getter of the field commissionningDate
 * \return the commissionningDate of the bike
 */
QDate & Bike::getCommissioningDate() {
    return this->commissioningDate;
}

/*!
 * \brief the setter of the field commissionningDate
 * \param the new commissioningDate
 */
void Bike::setCommissioningDate(QDate & date) {
    this->commissioningDate = date;
}

/*!
 * \brief getter of the field kmTravelled
 * \return the kmTravelled of the bike
 */
quint16 Bike::getKmTravelled() {
    return this->kmTravelled;
}

/*!
 * \brief the setter of the field kmTravelled
 * \param the new kmTravelled
 */
void Bike::setKmTravelled(quint16 kms) {
    this->kmTravelled = kms;
}
