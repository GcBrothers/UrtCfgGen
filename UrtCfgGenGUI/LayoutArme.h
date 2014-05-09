#ifndef DEF_LAYOUTARME
#define DEF_LAYOUTARME

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QObject>
#include <QLabel>
#include <QComboBox>
#include <QString>

class LayoutArme : public QWidget
{
    Q_OBJECT

    public:
    //Constructeur
        LayoutArme(bool activeDefaut = false);
        void desactiver();
        QString chaineConfig();
        void changerBool(bool nouveau);
   //Pour la création du fichier
        bool etat() const;
        QString lireKey() const;
        QString currentWeapons() const;
        //Destructeur
       // ~LayoutArme();
        //Pour lire le fichier :
        void loadWec(QString key, QString weapString);

public slots:
        //Pour griser/activer une ligne
    void activerDesactiver(int etatCheckBox);
    void autoriserArmes();
    void disableKey(bool enable);


    private:
    //Conteneur pour mettre en ligne
        QHBoxLayout *m_hBox;
        QHBoxLayout *m_hBoxUpper;
        QHBoxLayout *m_hBoxLower;
        QVBoxLayout *m_vBoxRight;
    //Bouton pour activer une ligne
        QCheckBox *m_boxEnable;
    //Les textes "bind" et "With", Weapons, Nades et Gear et switchind heys

        QLabel *m_bindLabel;
        QLabel *m_withLabel;
        QLabel *m_weaponsLabel;
        QLabel *m_nadesLabel;
        QLabel *m_gearLabel;
    //Les listes
        QComboBox *m_keyToBind; //Pour les caractères à associer
        QComboBox *m_firstWeapon;
        QComboBox *m_secondWeapon;
        QComboBox *m_pistol;
        QComboBox *m_nades;
        QComboBox *m_firstItem;
        QComboBox *m_secondItem;
        QComboBox *m_thirdItem;
        bool m_enableKeyToBind;
};

#endif
