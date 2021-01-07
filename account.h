/*!
  * \author Shameera Carrim
  */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
/*!
 * \brief The Account class is the user account model
 */
class Account
{
public:
    /*!
     * \brief Account constructor
     * \param Passcode is the value that is entered by the user as the new passcode
     */
    Account(QString Passcode);
public:
    /*!
     * \brief getPasscode is the getter of the passcode
     * \return Passcode string
     */
    QString getPasscode(); 

private:
    QString passcode;
};

#endif // ACCOUNT_H
