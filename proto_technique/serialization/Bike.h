/*
 * @File Bike.h
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */
#ifndef BIKE_H
#define BIKE_H

#include <QDate>
#include <QString>
#include <QDataStream>

#include "Serializable.h"

class Bike : public Serializable {

  protected:

    qint16 id;
    QDate commissioningDate;
    quint16 kmTravelled;

    /*!
     * \brief serialize a Bike (inherited from Serializable)
     * \param the output stream where to serialize
     * \return the stream after serialization
     */
    virtual QDataStream & serialize   (QDataStream & os) const;

    /*!
     * \brief deserialize a Bike (inherited from Serializable)
     * \param the input stream where to deserialize
     * \return the stream after deserialization
     */
    virtual QDataStream & deserialize (QDataStream & is) ;

  public:

    /*!
     * \brief Constructs a Bike
     * \param id
     * \param commissioningDate
     * \param kmTravelled
     */
    Bike(qint16 id = 0,
         QDate commissioningDate = QDate(),
         quint16 kmTravelled = 0);

    /*!
     * \brief Destructs the Bike
     */
    virtual ~Bike();

    /*!
     * \brief getter of the field id
     * \return the id of the bike
     */
    qint16 getId();

    /*!
     * \brief the setter of the field id
     * \param the new id
     */
    void setId(qint16);

    /*!
     * \brief getter of the field commissionningDate
     * \return the commissionningDate of the bike
     */
    QDate & getCommissioningDate();

    /*!
     * \brief the setter of the field commissionningDate
     * \param the new commissioningDate
     */
    void setCommissioningDate(QDate &);

    /*!
     * \brief getter of the field kmTravelled
     * \return the kmTravelled of the bike
     */
    quint16 getKmTravelled();

    /*!
     * \brief the setter of the field kmTravelled
     * \param the new kmTravelled
     */
    void setKmTravelled(quint16);

};

#endif /* BIKE_H */
