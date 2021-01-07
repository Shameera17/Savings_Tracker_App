/*!
  * \author Shameera Carrim
  */

#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "dashboard.h"
#include "dbgateway.h"
namespace Ui {
class Login;
}

/*!
 * \brief The Login class is the sign-in user interface class
 */
class Login : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Login constructor
     */
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    Dashboard *dashboard;
};

#endif // LOGIN_H
