/*
 * @File Bike.h
 *
 * @Author eloi
 *
 * @Date 13-10-2013
 *
 */
#ifndef __BIKE_H__
#define __BIKE_H__

#include <string>
#include <iostream>

#include "Serializable.h"

class Bike : public Serializable {
  protected:
    int id;
    std::string libelle;
    virtual std::ostream & serialize   (std::ostream & os) const;
    virtual std::istream & deserialize (std::istream & is) ;

  public:
    Bike(int id = 0, std::string libelle = "");
    virtual ~Bike();

    int getId();
    void setId(int);

};

#endif /* __BIKE_H__ */
