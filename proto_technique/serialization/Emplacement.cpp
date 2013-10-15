/*
 * @File Emplacement.cpp
 *
 * @Author Eloi PERDEREAU
 *
 * @Date 15-10-2013
 *
 */

#include <QString>

#include "Bike.h"
#include "Emplacement.h"

/*!
 * \brief Construct a Emplacement
 */
Emplacement::Emplacement() {}

/*!
 * \brief Construct a Emplacement
 * \param the state
 * \param the initial bike in the emplacement
 */
Emplacement::Emplacement(qint32 & state, Bike * bike)
: state (state), bike (bike)
{}

/*!
 * \brief serialize a Emplacement (inherited from Serializable)
 * \param the output stream where to serialize
 * \return the stream after serialization
 */
QDataStream & Emplacement::serialize   (QDataStream & os) const {
    return os << QString("EMPLACEMENT")
              << this->state
              << *(this->bike);
}

/*!
 * \brief deserialize a Emplacement (inherited from Serializable)
 * \param the input stream where to deserialize
 * \return the stream after deserialization
 */
QDataStream & Emplacement::deserialize (QDataStream & is) {
    QString str;
    is >> str;
    if (0 != str.compare(QString("EMPLACEMENT"))) {
        is.setStatus(QDataStream::ReadCorruptData);
        return is;
    }
    Bike b;
    is >> this->state >> b;
    this->bike = new Bike(b);
    return is;
}

/*!
 * \brief getter of the field state
 * \return the state of the emplacement
 */
qint32 Emplacement::getState() {
    return this->state;
}

/*!
 * \brief the setter of the field state
 * \param the new state
 */
void Emplacement::setState(qint32 & state) {
    this->state = state;
}

/*!
 * \brief getter of the field bike
 * \return the bike of the emplacement
 */
Bike * Emplacement::getBike() {
    return this->bike;
}

/*!
 * \brief the setter of the field bike
 * \param the new bike
 */
void Emplacement::setBike(Bike * bike) {
    this->bike = bike;
}

