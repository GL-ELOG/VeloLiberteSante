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

#include <QString>
#include <QDataStream>

#include "Serializable.h"

class Bike : public Serializable {
  protected:
    int id;
    QString libelle;
    virtual QDataStream & serialize   (QDataStream & os) const;
    virtual QDataStream & deserialize (QDataStream & is) ;

  public:
    Bike(int id = 0, QString libelle = "");
    virtual ~Bike();

    int getId();
    void setId(int);

};

#endif /* __BIKE_H__ */
