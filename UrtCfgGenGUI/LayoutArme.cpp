#include "LayoutArme.h"

LayoutArme::LayoutArme(bool activeDefaut) : QWidget()
{
    //On attribue les adresses mémoires déclarées
    m_boxEnable = new QCheckBox;
    m_hBox = new QHBoxLayout;
    m_hBoxUpper = new QHBoxLayout;
    m_hBoxLower = new QHBoxLayout;
    m_vBoxRight = new QVBoxLayout;

    m_bindLabel = new QLabel(tr("Bind :"));
    m_withLabel = new QLabel(tr("with :"));
    m_weaponsLabel = new QLabel(tr("Weapons :"));
    m_nadesLabel = new QLabel(tr("Nades :"));
    m_gearLabel = new QLabel(tr("Gear :"));
    m_keyToBind = new QComboBox;
    m_firstWeapon = new QComboBox;
    m_secondWeapon = new QComboBox;
    m_pistol = new QComboBox;
    m_nades = new QComboBox;
    m_firstItem = new QComboBox;
    m_secondItem = new QComboBox;
    m_thirdItem = new QComboBox;
    m_enableKeyToBind = false;
    //Valeurs par défaut des pointeurs
    if (activeDefaut == false)//Pointeur par défaut est décoché
    {
        desactiver();
    }
    else
    {
        m_boxEnable->setChecked(true);
    }
    m_keyToBind->setEditable(true);
    m_keyToBind->addItem("a"); //La liste des touches que l'on peut binder
    m_keyToBind->addItem("b");
    m_keyToBind->addItem("c");
    m_keyToBind->addItem("d");
    m_keyToBind->addItem("e");
    m_keyToBind->addItem("f");
    m_keyToBind->addItem("g");
    m_keyToBind->addItem("h");
    m_keyToBind->addItem("i");
    m_keyToBind->addItem("j");
    m_keyToBind->addItem("k");
    m_keyToBind->addItem("l");
    m_keyToBind->addItem("m");
    m_keyToBind->addItem("n");
    m_keyToBind->addItem("o");
    m_keyToBind->addItem("p");
    m_keyToBind->addItem("q");
    m_keyToBind->addItem("r");
    m_keyToBind->addItem("s");
    m_keyToBind->addItem("t");
    m_keyToBind->addItem("u");
    m_keyToBind->addItem("v");
    m_keyToBind->addItem("w");
    m_keyToBind->addItem("x");
    m_keyToBind->addItem("y");
    m_keyToBind->addItem("z");
    m_keyToBind->addItem("SPACE");
    m_keyToBind->addItem("F1");
    m_keyToBind->addItem("F2");
    m_keyToBind->addItem("F3");
    m_keyToBind->addItem("F4");
    m_keyToBind->addItem("F5");
    m_keyToBind->addItem("F6");
    m_keyToBind->addItem("F7");
    m_keyToBind->addItem("F8");
    m_keyToBind->addItem("F9");
    m_keyToBind->addItem("F10");
    m_keyToBind->addItem("F11");
    m_keyToBind->addItem("F12");
    m_keyToBind->addItem("MOUSE1");
    m_keyToBind->addItem("MOUSE2");
    m_keyToBind->addItem("MOUSE3");
    m_keyToBind->addItem("HOME");
    m_keyToBind->addItem("END");
    m_keyToBind->addItem("DELETE");
    m_keyToBind->addItem("PGUP");
    m_keyToBind->addItem("PGDN");
    m_keyToBind->addItem("INS");
    m_keyToBind->addItem("UPARROW");
    m_keyToBind->addItem("LEFTARROW");
    m_keyToBind->addItem("DOWNARROW");
    m_keyToBind->addItem("KP_HOME");
    m_keyToBind->addItem("KP_UPARROW");
    m_keyToBind->addItem("KP_LEFTARROW");
    m_keyToBind->addItem("KP_PGUP");
    m_keyToBind->addItem("KP_5");
    m_keyToBind->addItem("KP_END");
    m_keyToBind->addItem("KP_DOWNARROW");
    m_keyToBind->addItem("KP_PGUP");
    m_keyToBind->addItem("KP_PGDN");
    m_keyToBind->addItem("KP_INS");
    m_keyToBind->addItem("KP_PGUP");
    m_keyToBind->addItem("KP_DEL");
    m_keyToBind->addItem("KP_SLASH");
    m_keyToBind->addItem("KP_STAR");
    m_keyToBind->addItem("KP_MINUS");
    m_keyToBind->addItem("KP_PLUS");
    m_keyToBind->addItem("KP_ENTER");
    m_firstWeapon->addItem("G36"); // La liste pour la première arme
    m_firstWeapon->addItem("AK103");
    m_firstWeapon->addItem("LR300");
    m_firstWeapon->addItem("HK69");
    m_firstWeapon->addItem("PSG-1");
    m_firstWeapon->addItem("SR8");
    m_firstWeapon->addItem("Negev");
    m_firstWeapon->addItem("M4");
    m_firstWeapon->addItem("Spas-12");
    m_firstWeapon->addItem("Mp5K");
    m_firstWeapon->addItem("UMP45");
    m_firstWeapon->addItem("Mac 11");
    m_secondWeapon->addItem("None");//Liste de 2eme arme
    m_secondWeapon->addItem("Spas-12");
    m_secondWeapon->addItem("Mp5K");
    m_secondWeapon->addItem("UMP45");
    m_secondWeapon->addItem("Mac 11");
    m_pistol->addItem("Beretta");//Liste des pistols
    m_pistol->addItem("DE");
    m_pistol->addItem("Glock");
    m_pistol->addItem("Colt 911");
    m_nades->addItem("None");//La liste des grens
    m_nades->addItem("HE Nade");
    m_nades->addItem("Smoke Nade");
    m_firstItem->addItem("Kevlar Vest");//La liste de l'item n=1 : penser à ajouter un pour le SLOT de création de chaine
    m_firstItem->addItem("Tactic Googles");
    m_firstItem->addItem("Medikit");
    m_firstItem->addItem("Silencer");
    m_firstItem->addItem("Laser Sight");
    m_firstItem->addItem("Helmet");
    m_firstItem->addItem("Extra Ammo");
    m_secondItem->addItem("None");//La liste de l'item n=2
    m_secondItem->addItem("Kevlar Vest");
    m_secondItem->addItem("Tactic Googles");
    m_secondItem->addItem("Medikit");
    m_secondItem->addItem("Silencer");
    m_secondItem->addItem("Laser Sight");
    m_secondItem->addItem("Helmet");
    m_secondItem->addItem("Extra Ammo");
    m_thirdItem->addItem("None");//La liste de l'item n=
    m_thirdItem->addItem("Kevlar Vest");
    m_thirdItem->addItem("Tactic Googles");
    m_thirdItem->addItem("Medikit");
    m_thirdItem->addItem("Silencer");
    m_thirdItem->addItem("Laser Sight");
    m_thirdItem->addItem("Helmet");
    m_thirdItem->addItem("Extra Ammo");


    //On ajoute tout dans le layout
    m_hBoxUpper->addWidget(m_weaponsLabel);
    m_hBoxUpper->addWidget(m_firstWeapon);
    m_hBoxUpper->addWidget(m_secondWeapon);
    m_hBoxUpper->addWidget(m_pistol);
    m_hBoxUpper->addWidget(m_nadesLabel);
    m_hBoxUpper->addWidget(m_nades);
    m_hBoxLower->addWidget(m_gearLabel);
    m_hBoxLower->addWidget(m_firstItem);
    m_hBoxLower->addWidget(m_secondItem);
    m_hBoxLower->addWidget(m_thirdItem);
    m_vBoxRight->addLayout(m_hBoxUpper);
    m_vBoxRight->addLayout(m_hBoxLower);
    m_hBox->addWidget(m_boxEnable);
    m_hBox->addWidget(m_bindLabel);
    m_hBox->addWidget(m_keyToBind);
    m_hBox->addWidget(m_withLabel);
    m_hBox->addLayout(m_vBoxRight);

  /*  m_hBox->addWidget(m_weaponsLabel);
    m_hBox->addWidget(m_firstWeapon);
    m_hBox->addWidget(m_secondWeapon);
    m_hBox->addWidget(m_pistol);
    m_hBox->addWidget(m_nadesLabel);
    m_hBox->addWidget(m_nades);
    m_hBox->addWidget(m_gearLabel);
    m_hBox->addWidget(m_firstItem);
    m_hBox->addWidget(m_secondItem);
    m_hBox->addWidget(m_thirdItem);*/
    //On attribue le layout au Widget
    this->setLayout((m_hBox));

    // Connexions nécessaires
    QObject::connect(m_boxEnable, SIGNAL(stateChanged(int)), this, SLOT(activerDesactiver(int)));
    QObject::connect(m_firstWeapon, SIGNAL(currentIndexChanged(int)), this, SLOT(autoriserArmes()));
    QObject::connect(m_secondWeapon, SIGNAL(currentIndexChanged(int)), this, SLOT(autoriserArmes()));
    QObject::connect(m_nades, SIGNAL(currentIndexChanged(int)), this, SLOT(autoriserArmes()));
    QObject::connect(m_firstItem, SIGNAL(currentIndexChanged(int)), this, SLOT(autoriserArmes()));
    QObject::connect(m_secondItem, SIGNAL(currentIndexChanged(int)), this, SLOT(autoriserArmes()));
    QObject::connect(m_thirdItem, SIGNAL(currentIndexChanged(int)), this, SLOT(autoriserArmes()));
}

void LayoutArme::desactiver()
{
    m_boxEnable->setChecked(false);
    m_bindLabel->setEnabled(false);
    m_keyToBind->setEnabled(false);
    m_withLabel->setEnabled(false);
    m_weaponsLabel->setEnabled(false);
    m_firstWeapon->setEnabled(false);
    m_secondWeapon->setEnabled(false);
    m_pistol->setEnabled(false);
    m_nadesLabel->setEnabled(false);
    m_nades->setEnabled(false);
    m_gearLabel->setEnabled(false);
    m_firstItem->setEnabled(false);
    m_secondItem->setEnabled(false);
    m_thirdItem->setEnabled(false);
}

QString LayoutArme::chaineConfig()
{
    QString chaineCaractereConfig;
    QString pistol;
    QString primary;
    QString secondary;
    QString grens;
    QString itm1;
    QString itm2;
    QString itm3;
    switch (m_pistol->currentIndex()) //onchoisit pour le pistol
        {
            case 0:
                pistol = "F"; //beretta
                break;
            case 1:
                pistol = "G";
                break; //DE
            case 2:
                pistol = "f"; //Glock
                break;
            case 3:
                pistol = "g"; //Colt 911
                break;
            default:
                pistol = "A";
                break;
        }

        switch (m_firstWeapon->currentIndex() + 1) //on choisit pour l'arme 1
        {
            case 1:
                primary = "M"; //G36
                break;
            case 2:
                primary = "a"; //AK103
                break;
            case 3:
                primary = "L"; //LR300
                break;
            case 4:
                primary = "K"; //HK69
                break;
            case 5:
                primary = "N"; //PSG 1
                break;
            case 6:
                primary = "Z"; //SR8
                break;
            case 7:
                primary = "c"; //Negev
                break;
            case 8:
                primary = "e";//M4
                break;
            case 9:
                primary = "H"; //Spas12
                break;
            case 10:
                primary = "I"; //Mp5K
                break;
            case 11:
                primary = "J"; //UMP45
                break;
            case 12:
                primary = "h"; //Mac 11
                break;
            default:
                primary = "A"; //Rien, mauvaise valeur entrée par l'utilisateur
                break;
        }

        switch (m_secondWeapon->currentIndex()) //seconde arme
        {
            case 0:
                secondary = "A"; // Rien
                break;
            case 1:
                secondary = "H"; //Spas 12
                break;
            case 2:
                secondary = "I"; //Mp5K
                break;
            case 3:
                secondary = "J"; //UMP45
                break;
            case 4:
                secondary = "h";//Mac 11
                break;
            default:
                secondary = "A"; //bug
                break;
        }

        switch (m_nades->currentIndex())
        {
            case 0:
                grens = "A";// pas de grenades
                break;
            case 1:
                grens = "O"; //High Explosive
                break;
            case 2:
                grens = "Q";//Smoke
                break;
            default:
                grens = "A";
                break;
        }

        switch (m_firstItem->currentIndex() + 1) //item 1 : ajouter 1 !
        {
            case 1:
                itm1 = "R"; //Kevlar Vest
                break;
            case 2:
                itm1 = "S"; //Tactic Googles
                break;
            case 3:
                itm1 = "T"; //Medikit
                break;
            case 4:
                itm1 = "U"; //silencer
                break;
            case 5:
                itm1 = "V"; //Laser Sight
                break;
            case 6:
                itm1 = "W"; //Helmet
                break;
            case 7:
                itm1 = "X"; //extra ammo
                break;
            default:
                itm1 = "A";
                break;
        }

        switch (m_secondItem->currentIndex()) //item 2
        {
            case 1:
                itm2 = "R"; //Kevlar Vest
                break;
            case 2:
                itm2 = "S"; //Tactic Googles
                break;
            case 3:
                itm2 = "T"; //Medikit
                break;
            case 4:
                itm2 = "U"; //silencer
                break;
            case 5:
                itm2 = "V"; //Laser Sight
                break;
            case 6:
                itm2 = "W"; //Helmet
                break;
            case 7:
                itm2 = "X"; //extra ammo
                break;
            default:
                itm2 = "A";
                break;
        }

        switch (m_thirdItem->currentIndex()) //item 3
        {
            case 1:
                itm3 = "R"; //Kevlar Vest
                break;
            case 2:
                itm3 = "S"; //Tactic Googles
                break;
            case 3:
                itm3 = "T"; //Medikit
                break;
            case 4:
                itm3 = "U"; //silencer
                break;
            case 5:
                itm3 = "V"; //Laser Sight
                break;
            case 6:
                itm3 = "W"; //Helmet
                break;
            case 7:
                itm3 = "X"; //extra ammo
                break;
            default:
                itm3 = "A";
                break;
        }
        chaineCaractereConfig = pistol + primary + secondary + grens + itm1 + itm2 + itm3;
        return chaineCaractereConfig;
}

void LayoutArme::changerBool(bool nouveau)
{
    m_enableKeyToBind = nouveau;
}

bool LayoutArme::etat() const
{
    return m_boxEnable->isChecked();
}

QString LayoutArme::lireKey() const
{
    return m_keyToBind->currentText();
}

QString LayoutArme::currentWeapons() const
{
    QString pistol;
    QString primary;
    QString secondary;
    QString grens;
    QString weapons;

    switch (m_pistol->currentIndex()) //onchoisit pour le pistol
        {
            case 0:
                pistol = "Beretta"; //beretta
                break;
            case 1:
                pistol = "DE";
                break; //DE
            case 2:
                pistol = "Glock"; //Glock
                break;
            case 3:
                pistol = "Colt 911"; //Colt 911
                break;
            default:
                pistol = "";
                break;
        }
        switch (m_firstWeapon->currentIndex() + 1) //on choisit pour l'arme 1
        {
            case 1:
                primary = "G36"; //G36
                break;
            case 2:
                primary = "AK103"; //AK103
                break;
            case 3:
                primary = "LR300"; //LR300
                break;
            case 4:
                primary = "HK69"; //HK69
                break;
            case 5:
                primary = "PSG-1"; //PSG 1
                break;
            case 6:
                primary = "SR8"; //SR8
                break;
            case 7:
                primary = "Negev"; //Negev
                break;
            case 8:
                primary = "M4";//M4
                break;
            case 9:
                primary = "Spas 12"; //Spas12
                break;
            case 10:
                primary = "Mp5K"; //Mp5K
                break;
            case 11:
                primary = "UMP45"; //UMP45
                break;
            case 12:
                primary = "Mac 11"; //Mac 11
                break;
            default:
                primary = ""; //Rien, mauvaise valeur entrée par l'utilisateur
                break;
        }
        switch (m_secondWeapon->currentIndex()) //seconde arme
        {
            case 0:
                secondary = ""; // Rien
                break;
            case 1:
                secondary = "Spas 12"; //Spas 12
                break;
            case 2:
                secondary = "Mp5K"; //Mp5K
                break;
            case 3:
                secondary = "UMP45"; //UMP45
                break;
            case 4:
                secondary = "Mac 11";//Mac 11
                break;
            default:
                secondary = ""; //bug
                break;
        }
        switch (m_nades->currentIndex())
        {
            case 0:
                grens = "";// pas de grenades
                break;
            case 1:
                grens = "HE"; //High Explosive
                break;
            case 2:
                grens = "Smoke";//Smoke
                break;
            default:
                grens = "";
                break;
        }
        weapons = primary + " " + secondary + " " + pistol + " " + grens;
        return weapons;

}

/*LayoutArme::~LayoutArme()
{
    delete m_hBox;
    //Bouton pour activer une ligne
    delete m_boxEnable;
    //Les textes "bind" et "With", Weapons, Nades et Gear
    delete m_bindLabel;
    delete m_withLabel;
    delete m_weaponsLabel;
    delete m_nadesLabel;
    delete m_gearLabel;
    //Les listes
    delete m_keyToBind; //Pour les caractères à associer
    delete m_firstWeapon;
    delete m_secondWeapon;
    delete m_pistol;
    delete m_nades;
    delete m_firstItem;
    delete m_secondItem;
    delete m_thirdItem;
}*/

void LayoutArme::loadWec(QString key, QString weapString)
{
    m_boxEnable->setChecked(true);
    m_pistol->setCurrentIndex(0);//on Initialise tout
    m_firstWeapon->setCurrentIndex(0);
    m_secondWeapon->setCurrentIndex(0);
    m_nades->setCurrentIndex(0);
    m_firstItem->setCurrentIndex(0);
    m_secondItem->setCurrentIndex(0);
    m_thirdItem->setCurrentIndex(0);
    m_keyToBind->setCurrentText(key);
    if (weapString[0] == 'F') //Premier caractère
    {
        m_pistol->setCurrentIndex(0);
    }
    if (weapString[0] == 'G')
    {
        m_pistol->setCurrentIndex(1);
    }
    if (weapString[0] == 'f')
    {
        m_pistol->setCurrentIndex(2);
    }
    if (weapString[0] == 'g')
    {
        m_pistol->setCurrentIndex(3);
    }


    if (weapString[1] == 'M')//Second caractère
    {
        m_firstWeapon->setCurrentIndex(0);
    }
    if (weapString[1] == 'a')
    {
        m_firstWeapon->setCurrentIndex(1);
    }
    if (weapString[1] == 'L')
    {
        m_firstWeapon->setCurrentIndex(2);
    }
    if (weapString[1] == 'K')
    {
        m_firstWeapon->setCurrentIndex(3);
    }
    if (weapString[1] == 'N')
    {
        m_firstWeapon->setCurrentIndex(4);
    }
    if (weapString[1] == 'Z')
    {
        m_firstWeapon->setCurrentIndex(5);
    }
    if (weapString[1] == 'c')
    {
        m_firstWeapon->setCurrentIndex(6);
    }
    if (weapString[1] == 'e')
    {
        m_firstWeapon->setCurrentIndex(7);
    }
    if (weapString[1] == 'H')
    {
        m_firstWeapon->setCurrentIndex(8);
    }
    if (weapString[1] == 'I')
    {
        m_firstWeapon->setCurrentIndex(9);
    }
    if (weapString[1] == 'J')
    {
        m_firstWeapon->setCurrentIndex(10);
    }
    if (weapString[1] == 'h')
    {
        m_firstWeapon->setCurrentIndex(11);
    }


    if (weapString[2] == 'H')//On passe à la troisième lettre -sic- le nombre de ifs
    {
        m_secondWeapon->setCurrentIndex(1);
    }
    if (weapString[2] == 'I')
    {
        m_secondWeapon->setCurrentIndex(2);
    }
    if (weapString[2] == 'J')
    {
        m_secondWeapon->setCurrentIndex(3);
    }
    if (weapString[2] == 'h')
    {
        m_secondWeapon->setCurrentIndex(4);
    }
    if (weapString[2] == 'A')
    {
        m_secondWeapon->setCurrentIndex(0);
    }

    if (weapString[3] == 'A')//4°
    {
        m_nades->setCurrentIndex(0);
    }
    if (weapString[3] == 'O')
    {
        m_nades->setCurrentIndex(1);
    }
    if (weapString[3] == 'Q')
    {
        m_nades->setCurrentIndex(2);
    }

    if (weapString[4] == 'R')//5°
    {
        m_firstItem->setCurrentIndex(0);
    }
    if (weapString[4] == 'S')
    {
        m_firstItem->setCurrentIndex(1);
    }
    if (weapString[4] == 'T')
    {
        m_firstItem->setCurrentIndex(2);
    }
    if (weapString[4] == 'U')
    {
        m_firstItem->setCurrentIndex(3);
    }
    if (weapString[4] == 'V')
    {
        m_firstItem->setCurrentIndex(4);
    }
    if (weapString[4] == 'W')
    {
        m_firstItem->setCurrentIndex(5);
    }
    if (weapString[4] == 'X')
    {
        m_firstItem->setCurrentIndex(6);
    }

    if (weapString[5] == 'A')//6°
    {
        m_secondItem->setCurrentIndex(0);
    }
    if (weapString[5] == 'R')
    {
        m_secondItem->setCurrentIndex(1);
    }
    if (weapString[5] == 'S')
    {
        m_secondItem->setCurrentIndex(2);
    }
    if (weapString[5] == 'T')
    {
        m_secondItem->setCurrentIndex(3);
    }
    if (weapString[5] == 'U')
    {
        m_secondItem->setCurrentIndex(4);
    }
    if (weapString[5] == 'V')
    {
        m_secondItem->setCurrentIndex(5);
    }
    if (weapString[5] == 'W')
    {
        m_secondItem->setCurrentIndex(6);
    }
    if (weapString[5] == 'X')
    {
        m_secondItem->setCurrentIndex(7);
    }

    if (weapString[6] == 'A') //7°
    {
        m_thirdItem->setCurrentIndex(0);
    }
    if (weapString[6] == 'R')
    {
        m_thirdItem->setCurrentIndex(1);
    }
    if (weapString[6] == 'S')
    {
        m_thirdItem->setCurrentIndex(2);
    }
    if (weapString[6] == 'T')
    {
        m_thirdItem->setCurrentIndex(3);
    }
    if (weapString[6] == 'U')
    {
        m_thirdItem->setCurrentIndex(4);
    }
    if (weapString[6] == 'V')
    {
        m_thirdItem->setCurrentIndex(5);
    }
    if (weapString[6] == 'W')
    {
        m_thirdItem->setCurrentIndex(6);
    }
    if (weapString[6] == 'X')
    {
        m_thirdItem->setCurrentIndex(7);
    }
}

void LayoutArme::activerDesactiver(int etatCheckBox)
{
    if (etatCheckBox)
    {
        if (m_enableKeyToBind == false)
        {
            m_bindLabel->setEnabled(true);
            m_keyToBind->setEnabled(true);
        }
        m_withLabel->setEnabled(true);
        m_weaponsLabel->setEnabled(true);
        m_firstWeapon->setEnabled(true);
        m_secondWeapon->setEnabled(true);
        m_pistol->setEnabled(true);
        m_nadesLabel->setEnabled(true);
        m_nades->setEnabled(true);
        m_gearLabel->setEnabled(true);
        m_firstItem->setEnabled(true);
        m_secondItem->setEnabled(true);
        m_thirdItem->setEnabled(true);
    }
    if (etatCheckBox == 0)
    {
        m_bindLabel->setEnabled(false);
        m_keyToBind->setEnabled(false);
        m_withLabel->setEnabled(false);
        m_weaponsLabel->setEnabled(false);
        m_firstWeapon->setEnabled(false);
        m_secondWeapon->setEnabled(false);
        m_pistol->setEnabled(false);
        m_nadesLabel->setEnabled(false);
        m_nades->setEnabled(false);
        m_gearLabel->setEnabled(false);
        m_firstItem->setEnabled(false);
        m_secondItem->setEnabled(false);
        m_thirdItem->setEnabled(false);

    }

}

void LayoutArme::autoriserArmes()
{
    if (m_firstWeapon->currentIndex() != 6)
    {
        m_secondWeapon->setEnabled(true);
        m_secondItem->setEnabled(true);
        m_thirdItem->setEnabled(true);
        if (m_secondWeapon->currentIndex() != 0)
        {
            m_thirdItem->setCurrentIndex(0);
            m_thirdItem->setEnabled(false);
            if (m_nades->currentIndex() != 0)
            {
                m_secondItem->setCurrentIndex(0);
                m_secondItem->setEnabled(false);
            }
        }
        if (m_nades->currentIndex() != 0)
        {
            m_thirdItem->setCurrentIndex(0);
            m_thirdItem->setEnabled(false);
        }

    }
    if (m_firstWeapon->currentIndex() == 6)
    {
        m_secondWeapon->setCurrentIndex(0);
        m_secondWeapon->setEnabled(false);
        m_thirdItem->setEnabled(true);
        if (m_nades->currentIndex() != 0)
        {
            m_thirdItem->setCurrentIndex(0);
            m_thirdItem->setEnabled(false);
        }
    }
    if (m_secondItem->currentIndex() - 1 == m_firstItem->currentIndex())
    {
        m_secondItem->setCurrentIndex(0);
    }
    if (m_thirdItem->currentIndex() == m_secondItem->currentIndex() || m_thirdItem->currentIndex() - 1 == m_firstItem->currentIndex())
    {
        m_thirdItem->setCurrentIndex(0);
    }
}
 void LayoutArme::disableKey(bool enable)
 {
     if (m_boxEnable->isChecked())
     {
         m_bindLabel->setDisabled(enable);
         m_keyToBind->setDisabled(enable);
     }
 }
