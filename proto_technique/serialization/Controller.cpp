/*
 * @File Controller.cpp
 *
 * @Author p1002650
 *
 * @Date 14-10-2013
 *
 */
#include <QVector>
#include <QString>
#include <algorithm>    // find()
#include <QFile>
#include <QDataStream>

#include "Controller.h"
#include "Bike.h"

#define TEMPL template<class T>
#define CONTROLLER Controller<T>

TEMPL
CONTROLLER::Controller(const QString & fileName)
: fileName (fileName)
{
    readFile();
}

TEMPL
CONTROLLER::~Controller() {
    writeFile();
    for (int i(0); i < elems.size(); ++i) {
        delete elems[i];
        elems[i] = 0;
    }
}

TEMPL
void CONTROLLER::readFile() {
    QFile file (fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream in (&file);
    for (T t; QDataStream::Ok == (in >> t).status(); ) {
        elems.push_back(new T(t));
    }
    file.close();
}

TEMPL
void CONTROLLER::writeFile() {
    QFile file (fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream out (&file);
    for (typename QVector<T*>::iterator it (elems.begin());
         it != elems.end(); ++it) {
        out << **it;
    }
    file.close();
}

TEMPL
QVector<T*> & CONTROLLER::getElems() { return elems; }

TEMPL
void CONTROLLER::addElem(T * elem) {
    elems.push_back(elem);
}

TEMPL
bool CONTROLLER::removeElem(T * elem) {
    typename QVector<T*>::iterator it =
                    std::find(elems.begin(), elems.end(), elem);

    if (it == elems.end()) return false;

    elems.erase(it);
    return true;
}

template class Controller<Bike>; // ok for our little project
