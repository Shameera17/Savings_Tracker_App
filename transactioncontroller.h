/*!
  * \author Shameera Carrim
  */

#ifndef TRANSACTIONCONTROLLER_H
#define TRANSACTIONCONTROLLER_H
#include "transaction.h"
#include "dbgateway.h"
#include <QTableView>
#include<QSqlRecord>

/*!
 * \brief The TransactionController class controls the operations of the Transaction Model
 */
class TransactionController
{
public:
    /*!
     * \brief TransactionController Constructor
     */
    TransactionController();

public:
    /*!
     * \brief AddTransaction create a new transaction
     * \param transaction takes the Transaction instance
     */
    void AddTransaction(Transaction transaction);

    /*!
     * \brief DisplayTransaction reads the transactions
     */
    void DisplayTransaction();

    /*!
     * \brief storeInScheme do the propogation between the schemes
     */
    void storeInScheme();

    /*!
     * \brief storeSavings update the savigs according to propotions based on the transaction amount
     * \param amount takes the transaction amount
     */
    void storeSavings(double amount);

    /*!
     * \brief storeSavingsSeparately create transactions seperately based on schemas
     * \param type takes the transaction type as credit or debit
     * \param amount takes the transaction amount
     * \param schemeid takes wchich scheme to save by its id
     */
    void storeSavingsSeparately(QString type,double amount, int schemeid);
};

#endif // TRANSACTIONCONTROLLER_H
