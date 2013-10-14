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

#include <vector>

template <class T>
class Controller {
  private:
    std::vector<T *> elems;
    std::string fileName;

    void readFile();

  public:
    Controller(const std::string & fileName);
    virtual ~Controller(void);

    std::vector<T *> & getElems();

    void addElem    (T * elem);
    bool removeElem (T * elem);

};

#endif /* __CONTROLLER_H__ */
