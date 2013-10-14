/*
 * @File Controller.cpp
 *
 * @Author p1002650
 *
 * @Date 14-10-2013
 *
 */
#include <vector>
#include <string>
#include <algorithm>    // find()
#include <fstream>

#include "Controller.h"
#include "Bike.h"

#define TEMPL template<class T>
#define CONTROLLER Controller<T>

#include <iostream> // TODO remove

TEMPL
CONTROLLER::Controller(const std::string & fileName)
: fileName (fileName)
{
    readFile();
}

TEMPL
CONTROLLER::~Controller() {
    for (unsigned i(0); i < elems.size(); ++i) {
        delete elems[i];
        elems[i] = 0;
    }
}

TEMPL
void CONTROLLER::readFile() {
    std::ifstream is (fileName.c_str());
    for (Bike b; (is >> b); ) {
        elems.push_back(new Bike(b));
    }
    is.close();
}

TEMPL
std::vector<T *> & CONTROLLER::getElems() { return elems; }

TEMPL
void CONTROLLER::addElem(T * elem) {
    elems.push_back(elem);
}

TEMPL
bool CONTROLLER::removeElem(T * elem) {
    typename std::vector<T*>::iterator it =
                    std::find(elems.begin(), elems.end(), elem);

    if (it == elems.end()) return false;

    elems.erase(it);
    return true;
}

template class Controller<Bike>; // ok for our little project
