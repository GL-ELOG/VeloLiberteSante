/*
 * @File Station.cpp
 *
 * @Author Eloi PERDEREAU
 *
 * @Date 15-10-2013
 *
 */

#include <QString>
#include <QVector>

#include "Station.h"
#include "Emplacement.h"

/*!
 * \brief Construct a Station
 */
Station::Station() {}

/*!
 * \brief Construct a Station
 * \param the localization
 * \param the emplacements
 */
Station::Station(QString & localization, QVector<Emplacement*> & emplacements)
: localization (localization), emplacements (emplacements)
{}

/*!
 * \brief serialize a Station (inherited from Serializable)
 * \param the output stream where to serialize
 * \return the stream after serialization
 */
QDataStream & Station::serialize   (QDataStream & os) const {
    os << QString("STATION")
       << this->localization
       << (quint16) emplacements.size();
    for (int i (0); i < emplacements.size(); ++i) {
        os << *(emplacements[i]);
    }
    return os;
}

/*!
 * \brief deserialize a Station (inherited from Serializable)
 * \param the input stream where to deserialize
 * \return the stream after deserialization
 */
QDataStream & Station::deserialize (QDataStream & is) {
    QString str;
    is >> str;
    if (0 != str.compare(QString("STATION"))) {
        is.setStatus(QDataStream::ReadCorruptData);
        return is;
    }
    is >> this->localization;
    quint16 sz;
    is >> sz;
    for (int i (0); i < sz; ++i) {
        Emplacement e;
        is >> e;
        emplacements.push_back(new Emplacement(e));
    }
    return is;
}

/*!
 * \brief Destructs the Station
 */
Station::~Station() {}

/*!
 * \brief getter of the field localization
 * \return the localization of the station
 */
QString & Station::getLocalization() {
    return this->localization;
}

/*!
 * \brief the setter of the field localization
 * \param the new localization
 */
void Station::setLocalization(QString & localization) {
    this->localization = localization;
}

/*!
 * \brief getter of the field emplacements
 * \return the emplacements of the station
 */
QVector<Emplacement*> & Station::getEmplacements() {
    return this->emplacements;
}

/*!
 * \brief the setter of the field emplacements
 * \param the new emplacements
 */
void Station::setEmplacements(QVector<Emplacement*> & emplacements) {
    this->emplacements = emplacements;
}

