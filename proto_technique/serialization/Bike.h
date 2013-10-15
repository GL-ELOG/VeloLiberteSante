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

#include <QString>
#include <QDataStream>

#include "Serializable.h"

class Bike : public Serializable {

  protected:

    qint16 id;
    QString libel;

    /*!
     * \brief serialize a Bike
     * \param the output stream where to serialize
     * \return the stream after serialization
     */
    virtual QDataStream & serialize   (QDataStream & os) const;

    /*!
     * \brief deserialize a Bike
     * \param the input stream where to deserialize
     * \return the stream after deserialization
     */
    virtual QDataStream & deserialize (QDataStream & is) ;

  public:

    /*!
     * \brief Constructs a Bike
     * \param id
     * \param libel
     */
    Bike(int id = 0, QString libel = "");

    /*!
     * \brief Destructs the Bike
     */
    virtual ~Bike();

    /*!
     * \brief getter of the field id
     * \return the id of the bike
     */
    int getId();

    /*!
     * \brief the setter of the field id
     * \param the new id
     */
    void setId(int);

    /*!
     * \brief getter of the field libel
     * \return the libel of the bike
     */
    QString & getLibel();

    /*!
     * \brief the setter of the field libel
     * \param the new libel
     */
    void setLibel(QString &);

};

#endif /* BIKE_H */
