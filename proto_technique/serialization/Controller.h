/*
 * @File Controller.h
 *
 * @Author p1002650
 *
 * @Date 14-10-2013
 *
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QVector>

template <class T>
class Controller {
  private:
    QVector<T *> elems;
    QString fileName;

    void readFile();
    void writeFile();

  public:
    Controller(const QString & fileName);
    virtual ~Controller(void);

    QVector<T*> & getElems();

    void addElem    (T * elem);
    bool removeElem (T * elem);

};

#endif /* CONTROLLER_H */
