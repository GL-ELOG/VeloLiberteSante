/*
 * @File Serializable.h
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */
#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <QDataStream>

class Serializable {

  protected:

    /*!
     * \brief serialize an the Serializable object, virtual pure
     * \param os, the output stream where to serialize
     */
    virtual QDataStream & serialize   (QDataStream & os) const = 0;

    /*!
     * \brief deserialize an the Serializable object, virtual pure
     * \param is, the input stream where to deserialize
     */
    virtual QDataStream & deserialize (QDataStream & is) = 0;

  public:

    /*!
     * \brief Destructs the Serializable
     */
    virtual ~Serializable() {}

    /*!
     * \brief eject a serializable object in an output stream
     * \param os, the output stream where to eject the object
     * \param obj, the object to eject
     */
    friend QDataStream & operator << (QDataStream & os, const Serializable & obj);

    /*!
     * \brief inject a serializable object in an input stream
     * \param is, the input stream where to inject the object
     * \param obj, the object to inject
     */
    friend QDataStream & operator >> (QDataStream & is, Serializable & obj);

};

/*!
 * \brief eject a serializable object in an output stream
 * \param os, the output stream where to eject the object
 * \param obj, the object to eject
 */
inline QDataStream & operator << (QDataStream & os, const Serializable & obj) {
    return obj.serialize(os);
}

/*!
 * \brief inject a serializable object in an input stream
 * \param is, the input stream where to inject the object
 * \param obj, the object to inject
 */
inline QDataStream & operator >> (QDataStream & is, Serializable & obj) {
    return obj.deserialize(is);
}

#endif /* SERIALIZABLE_H */
