/*!
  * \author Shameera Carrim
  */

#ifndef SCHEME_H
#define SCHEME_H
#include <QString>

/*!
 * \brief The Scheme class is the saving scheme model
 */
class Scheme
{
public:
    /*!
     * \brief Scheme Constructor
     * \param Scheme1name is the saving plan 1 name
     * \param Scheme2name is the saving plan 2 name
     * \param Scheme3name is the saving plan 3 name
     * \param Scheme4name is the saving plan 4 name
     * \param Scheme1perc is the saving plan 1 propotion
     * \param Scheme2perc is the saving plan 2 propotion
     * \param Scheme3perc is the saving plan 3 propotion
     * \param Scheme4perc is the saving plan 4 propotion
     */
    Scheme(QString Scheme1name, QString Scheme2name, QString Scheme3name, QString Scheme4name, int Scheme1perc,int Scheme2perc, int Scheme3perc,int Scheme4perc );

    /*!
     * \brief getSchemes
     */
    void getSchemes();

    /*!
     * \brief getScheme1name
     * \return name of the saving plan 1
     */
    QString getScheme1name();

    /*!
     * \brief getScheme2name
     * \return name of the saving plan 2
     */
    QString getScheme2name();

    /*!
     * \brief getScheme3name
     * \return name of the saving plan 3
     */
    QString getScheme3name();

    /*!
     * \brief getScheme4name
     * \return name of the saving plan 4
     */
    QString getScheme4name();

    /*!
     * \brief getScheme1perc
     * \return proportion of the saving plan 1
     */
    int getScheme1perc();

    /*!
     * \brief getScheme2perc
     * \return proportion of the saving plan 2
     */
    int getScheme2perc();

    /*!
     * \brief getScheme3perc
     * \return proportion of the saving plan 3
     */
    int getScheme3perc();

    /*!
     * \brief getScheme4perc
     * \return proportion of the saving plan 4
     */
    int getScheme4perc();

private:
    QString Scheme1name;
    QString Scheme2name;
    QString Scheme3name;
    QString Scheme4name;
    int Scheme1perc;
    int Scheme2perc;
    int Scheme3perc;
    int Scheme4perc;

};

#endif // SCHEME_H
