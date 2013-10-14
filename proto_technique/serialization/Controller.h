/*
 * @File Controller.h
 *
 * @Author p1002650
 *
 * @Date 14-10-2013
 *
 */
#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <QVector>

template <class T>
class Controller {
  private:
    QVector<T *> elems;
    QString fileName;

    void readFile();

  public:
    Controller(const QString & fileName);
    virtual ~Controller(void);

    QVector<T *> & getElems();

    void addElem    (T * elem);
    bool removeElem (T * elem);

};

#endif /* __CONTROLLER_H__ */
