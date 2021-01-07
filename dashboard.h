/*!
  * \author Shameera Carrim
  */

#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

/*!
 * \brief The Dashboard class is the MainWindow of the system
 */
class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Dashboard constructor
     */
    Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

    /*!
     * \brief DisplayBalance loads and displays the balance
     * \return balance
     */
    double DisplayBalance();

    /*!
     * \brief LoadAccountTransaction loads all the transaction that were recorded
     */
    void LoadAccountTransaction();

    /*!
     * \brief LoadSavingPlanDetails loads the percentages and names of the saving schemas
     */
    void LoadSavingPlanDetails();

private slots:
    void on_btnSetScheme_clicked();

    void on_btnFetchBal_clicked();

    void on_pushButton_3_clicked();

    void on_btnCreateTransaction_clicked();

    void on_btnSetScheme_2_clicked();

    void on_btnLoadData_clicked();

    void on_pushButton_5_clicked();

    void on_schemeEdit1_clicked();

    void on_schemeEdit2_clicked();

    void on_schemeEdit3_clicked();

    void on_schemeEdit4_clicked();

    void on_comboBoxType_currentIndexChanged(const QString &arg1);

    void on_btnLoadsaving_clicked();

    void on_validatepercentages_clicked();

private:
    Ui::Dashboard *ui;
};
#endif // DASHBOARD_H
