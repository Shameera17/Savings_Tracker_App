/*!
  * \author Shameera Carrim
  */

#ifndef SCHEMECONTROLLER_H
#define SCHEMECONTROLLER_H
#include "dbgateway.h"
#include "scheme.h"
#include <QTableView>

/*!
 * \brief The SchemeController class controls the operations of the Scheme class
 */
class SchemeController
{
public:
    /*!
     * \brief SchemeController Constructor
     */
    SchemeController();
public:
    /*!
     * \brief updateSchemes update the schema names
     * \param scheme takes the Scheme model
     */
    void updateSchemes(Scheme scheme);

    /*!
     * \brief displaySchemes displays all schemes in a table
     * \param tbl is the QTableView model to display schemes
     */
    void displaySchemes(QTableView *tbl);

//    void insertAmount();
};

#endif // SCHEMECONTROLLER_H
