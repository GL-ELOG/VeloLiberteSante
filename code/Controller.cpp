/*
 * @File Controller.cpp
 *
 * @Author Eloi PERDEREAU
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

// look at the bottom of this file
#include "Bike.h"
#include "Station.h"
#include "Emplacement.h"

#define TEMPL template<class T>
#define CONTROLLER Controller<T>

/*!
 * \brief Constructs a Controller
 * \param the file name where elements will be stored
 */
TEMPL
CONTROLLER::Controller(const QString & fileName)
: fileName (fileName)
{
    readFile();
}

/*!
 * \brief Destructs the Controller
 */
TEMPL
CONTROLLER::~Controller() {
    writeFile();
    for (int i(0); i < elems.size(); ++i) {
        delete elems[i];
        elems[i] = 0;
    }
}

/*!
 * \brief read the whole file and fill deserialized elements in elems
 */
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

/*!
 * \brief write all elems in the file
 */
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

/*!
 * \brief getter of the field elems
 * \return the field elems
 */
TEMPL
QVector<T*> & CONTROLLER::getElems() {
    return elems;
}

/*!
 * \brief add an element to elems
 * \param elem, the element to add
 */
TEMPL
void CONTROLLER::addElem(T * elem) {
    elems.push_back(elem);
}

/*!
 * \brief remove an element to elems
 * \param elem, the element to remove
 */
TEMPL
bool CONTROLLER::removeElem(T * elem) {
    typename QVector<T*>::iterator it =
                    std::find(elems.begin(), elems.end(), elem);

    if (it == elems.end()) return false;

    elems.erase(it);
    return true;
}

// we instanciate our generic controller with the class we will be using.
// it's not the way to do because now Controller.cpp is polluated w/
// class he shouldn't know about, but it's ok for our little project
template class Controller<Bike>;
template class Controller<Station>;
template class Controller<Emplacement>;
