/*
 * @File Serializable.h
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */
#ifndef __SERIALIZABLE_H__
#define __SERIALIZABLE_H__

#include <iostream>

class Serializable {
  protected:
    virtual std::ostream & serialize   (std::ostream & os) const = 0;
    virtual std::istream & deserialize (std::istream & is) = 0;

  public:
    virtual ~Serializable() {}
    friend std::ostream & operator << (std::ostream & os, const Serializable & obj);
    friend std::istream & operator >> (std::istream & is, Serializable & obj);

};

inline std::ostream & operator << (std::ostream & os, const Serializable & obj) {
    return obj.serialize(os);
}

inline std::istream & operator >> (std::istream & is, Serializable & obj) {
    return obj.deserialize(is);
}

#endif /* __SERIALIZABLE_H__ */
