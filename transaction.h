/*!
  * \author Shameera Carrim
  */

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>

/*!
 * \brief The Transaction class is the transaction model
 */
class Transaction
{
public:
    /*!
     * \brief Transaction Constructor
     * \param date takes the occured date
     * \param amount takes the value of the transaction
     * \param type takes the tyep as Credit or Debit
     * \param description takes the transaction desc
     * \param repo takes which Scheme to save
     */
    Transaction(QString date, QString amount, QString type, QString description, QString repo);

public:
    /*!
     * \brief getDate
     * \return Returns the transaction date
     */
    QString getDate();

    /*!
     * \brief getAmount
     * \return Returns the transaction amount
     */
    QString getAmount();

    /*!
     * \brief getDescription
     * \return Returns the transaction desc
     */
    QString getDescription();

    /*!
     * \brief getType
     * \return Returns the transaction type
     */
    QString getType();

    /*!
     * \brief getRepo
     * \return Returns the transaction repository
     */
    QString getRepo();

private:
    QString date;
    QString amount;
    QString description;
    QString type;
    QString repo;
};

#endif // TRANSACTION_H
