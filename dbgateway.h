/*!
  * \author Shameera Carrim
  */

#ifndef DBGATEWAY_H
#define DBGATEWAY_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDir>

/*!
 * \brief The DBGateway class provides the database connection with the SQLite3 database
 */
class DBGateway
{
public:
    /*!
     * \brief DBGateway Constructor
     */
    DBGateway();

public:
    /*!
     * \brief DBconnect opens the connection with the database
     * \return true if connection is success and false if it is not
     */
    bool DBconnect();

    /*!
     * \brief DBdisconnect close the database connection
     */
    void DBdisconnect();

    /*!
     * \brief getDB returns the current instance of the database
     * \return database instance
     */
    QSqlDatabase getDB();

private:
    QSqlDatabase db;
    QString path;
};

#endif // DBGATEWAY_H
