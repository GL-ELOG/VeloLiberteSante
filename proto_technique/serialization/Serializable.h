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
    virtual QDataStream & serialize   (QDataStream & os) const = 0;
    virtual QDataStream & deserialize (QDataStream & is) = 0;

  public:
    virtual ~Serializable() {}
    friend QDataStream & operator << (QDataStream & os, const Serializable & obj);
    friend QDataStream & operator >> (QDataStream & is, Serializable & obj);

};

inline QDataStream & operator << (QDataStream & os, const Serializable & obj) {
    return obj.serialize(os);
}

inline QDataStream & operator >> (QDataStream & is, Serializable & obj) {
    return obj.deserialize(is);
}

#endif /* SERIALIZABLE_H */
