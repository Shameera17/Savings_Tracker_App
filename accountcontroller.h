/*!
  * \author Shameera Carrim
  */

#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H
#include "account.h"
#include "dbgateway.h"
#include <QTableView>
/*!
 * \brief The AccountController class controls the account operations
 */
class AccountController
{
public:
    /*!
     * \brief AccountController constructor
     */
    AccountController();

    /*!
     * \brief updatePasscode updates the user entered new passcode
     * \param account takes the Account model
     */
    void updatePasscode(Account account);

    /*!
     * \brief loadAccount verify and log-in the user
     */
    void loadAccount();

    /*!
     * \brief displayAccountbalances displays the account balance of the user, when the application is started
     * \param tbl is the QTableView model to display the account balances
     */
    void displayAccountbalances(QTableView *tbl);
};

#endif // ACCOUNTCONTROLLER_H
