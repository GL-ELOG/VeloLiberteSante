/*
 * @File Controller.h
 *
 * @Author Eloi PERDEREAU
 *
 * @Date 14-10-2013
 *
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QVector>

template <class T>
class Controller {

  protected:

    QVector<T*> elems;
    QString fileName;

    /*!
     * \brief read the whole file and fill deserialized elements in elems
     */
    void readFile();

    /*!
     * \brief write all elems in the file
     */
    void writeFile();

  public:

    /*!
     * \brief Constructs a Controller
     * \param the file name where elements will be stored
     */
    Controller(const QString & fileName);

    /*!
     * \brief Destructs the Controller
     */
    virtual ~Controller(void);

    /*!
     * \brief getter of the field elems
     * \return the field elems
     */
    QVector<T*> & getElems();

    /*!
     * \brief add an element to elems
     * \param elem, the element to add
     */
    void addElem    (T * elem);

    /*!
     * \brief remove an element to elems
     * \param elem, the element to remove
     */
    bool removeElem (T * elem);

};

#endif /* CONTROLLER_H */
