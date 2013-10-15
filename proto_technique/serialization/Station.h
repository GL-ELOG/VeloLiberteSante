/*
 * @File Station.h
 *
 * @Author Eloi PERDEREAU
 *
 * @Date 15-10-2013
 *
 */
#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QVector>

#include "Emplacement.h"
#include "Serializable.h"

class Station : public Serializable {

  protected:

    QString localization;
    QVector<Emplacement*> emplacements;

    /*!
     * \brief serialize a Station (inherited from Serializable)
     * \param the output stream where to serialize
     * \return the stream after serialization
     */
    virtual QDataStream & serialize   (QDataStream & os) const;

    /*!
     * \brief deserialize a Station (inherited from Serializable)
     * \param the input stream where to deserialize
     * \return the stream after deserialization
     */
    virtual QDataStream & deserialize (QDataStream & is) ;

  public:

    /*!
     * \brief Construct a Station
     */
    Station();

    /*!
     * \brief Construct a Station
     * \param the localization
     * \param the emplacements
     */
    Station(QString &, QVector<Emplacement*> &);

    /*!
     * \brief Destructs the Station
     */
    virtual ~Station();

    /*!
     * \brief getter of the field localization
     * \return the localization of the station
     */
    QString & getLocalization();

    /*!
     * \brief the setter of the field localization
     * \param the new localization
     */
    void setLocalization(QString &);

    /*!
     * \brief getter of the field emplacements
     * \return the emplacements of the station
     */
    QVector<Emplacement*> & getEmplacements();

    /*!
     * \brief the setter of the field emplacements
     * \param the new emplacements
     */
    void setEmplacements(QVector<Emplacement*> &);

};

#endif /* STATION_H */
