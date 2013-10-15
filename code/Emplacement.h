/*
 * @File Emplacement.h
 *
 * @Author Eloi PERDEREAU
 *
 * @Date 15-10-2013
 *
 */
#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

#include "Bike.h"
#include "Serializable.h"

/* enum EmpState { FREE, OCCUPIED, HS }; */

class Emplacement : public Serializable {

  protected:

    /* EmpState state; */
    qint16 state;
    Bike * bike;

    /*!
     * \brief serialize a Emplacement (inherited from Serializable)
     * \param the output stream where to serialize
     * \return the stream after serialization
     */
    virtual QDataStream & serialize   (QDataStream & os) const;

    /*!
     * \brief deserialize a Emplacement (inherited from Serializable)
     * \param the input stream where to deserialize
     * \return the stream after deserialization
     */
    virtual QDataStream & deserialize (QDataStream & is) ;

  public:

    /*!
     * \brief Construct a Emplacement
     */
    Emplacement();

    /*!
     * \brief Construct a Emplacement
     * \param the state
     * \param the initial bike in the emplacement
     */
    Emplacement(qint32 &, Bike *);

    /*!
     * \brief getter of the field state
     * \return the state of the emplacement
     */
    qint32 getState();

    /*!
     * \brief the setter of the field state
     * \param the new state
     */
    void setState(qint32 &);

    /*!
     * \brief getter of the field bike
     * \return the bike of the emplacement
     */
    Bike * getBike();

    /*!
     * \brief the setter of the field bike
     * \param the new bike
     */
    void setBike(Bike *);

};

#endif /* EMPLACEMENT_H */
