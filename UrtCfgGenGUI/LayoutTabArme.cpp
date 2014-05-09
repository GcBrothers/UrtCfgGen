#include "LayoutTabArme.h"

using namespace std;


LayoutTabArme::LayoutTabArme() : QWidget()
{
    m_vbox1 = new QVBoxLayout;
    m_vbox2 = new QVBoxLayout;
    m_radio = new QHBoxLayout;
    m_switchingKeys = new QHBoxLayout;
    m_switch = new QLabel(tr("Switching keys : first to switch, second to accept (in game): "));
    m_keyAccept = new QComboBox;
    m_keySwitch = new QComboBox;
    m_radioButtons = new QGroupBox;
    m_modeEach = new QRadioButton(tr("Bind each cfg to a different key"));
    m_modeSwitch = new QRadioButton(tr("Use two keys to switch and select"));
    m_widgetArme1 = new LayoutArme(true);
    m_widgetArme2 = new LayoutArme;
    m_widgetArme3 = new LayoutArme;
    m_widgetArme4 = new LayoutArme;
    m_widgetArme5 = new LayoutArme;
    m_widgetArme6 = new LayoutArme;
    m_widgetArme7 = new LayoutArme;
    m_widgetArme8 = new LayoutArme;
    m_build = new QPushButton(tr("Build !"));
    m_folder = new QString;
    m_scroll = new QScrollArea;
    m_widscroll = new QWidget;

    m_keyAccept->setEditable(true);
    m_keyAccept->addItem("a"); //La liste des touches que l'on peut binder a tourner
    m_keyAccept->addItem("b");
    m_keyAccept->addItem("c");
    m_keyAccept->addItem("d");
    m_keyAccept->addItem("e");
    m_keyAccept->addItem("f");
    m_keyAccept->addItem("g");
    m_keyAccept->addItem("h");
    m_keyAccept->addItem("i");
    m_keyAccept->addItem("j");
    m_keyAccept->addItem("k");
    m_keyAccept->addItem("l");
    m_keyAccept->addItem("m");
    m_keyAccept->addItem("n");
    m_keyAccept->addItem("o");
    m_keyAccept->addItem("p");
    m_keyAccept->addItem("q");
    m_keyAccept->addItem("r");
    m_keyAccept->addItem("s");
    m_keyAccept->addItem("t");
    m_keyAccept->addItem("u");
    m_keyAccept->addItem("v");
    m_keyAccept->addItem("w");
    m_keyAccept->addItem("x");
    m_keyAccept->addItem("y");
    m_keyAccept->addItem("z");
    m_keyAccept->addItem("SPACE");
    m_keyAccept->addItem("F1");
    m_keyAccept->addItem("F2");
    m_keyAccept->addItem("F3");
    m_keyAccept->addItem("F4");
    m_keyAccept->addItem("F5");
    m_keyAccept->addItem("F6");
    m_keyAccept->addItem("F7");
    m_keyAccept->addItem("F8");
    m_keyAccept->addItem("F9");
    m_keyAccept->addItem("F10");
    m_keyAccept->addItem("F11");
    m_keyAccept->addItem("F12");
    m_keyAccept->addItem("MOUSE1");
    m_keyAccept->addItem("MOUSE2");
    m_keyAccept->addItem("MOUSE3");
    m_keyAccept->addItem("HOME");
    m_keyAccept->addItem("END");
    m_keyAccept->addItem("DELETE");
    m_keyAccept->addItem("PGUP");
    m_keyAccept->addItem("PGDN");
    m_keyAccept->addItem("INS");
    m_keyAccept->addItem("UPARROW");
    m_keyAccept->addItem("LEFTARROW");
    m_keyAccept->addItem("DOWNARROW");
    m_keyAccept->addItem("KP_HOME");
    m_keyAccept->addItem("KP_UPARROW");
    m_keyAccept->addItem("KP_LEFTARROW");
    m_keyAccept->addItem("KP_PGUP");
    m_keyAccept->addItem("KP_5");
    m_keyAccept->addItem("KP_END");
    m_keyAccept->addItem("KP_DOWNARROW");
    m_keyAccept->addItem("KP_PGUP");
    m_keyAccept->addItem("KP_PGDN");
    m_keyAccept->addItem("KP_INS");
    m_keyAccept->addItem("KP_PGUP");
    m_keyAccept->addItem("KP_DEL");
    m_keyAccept->addItem("KP_SLASH");
    m_keyAccept->addItem("KP_STAR");
    m_keyAccept->addItem("KP_MINUS");
    m_keyAccept->addItem("KP_PLUS");
    m_keyAccept->addItem("KP_ENTER");
    m_keySwitch->setEditable(true);
    m_keySwitch->addItem("a"); //La liste des touches que l'on peut binder
    m_keySwitch->addItem("b");
    m_keySwitch->addItem("c");
    m_keySwitch->addItem("d");
    m_keySwitch->addItem("e");
    m_keySwitch->addItem("f");
    m_keySwitch->addItem("g");
    m_keySwitch->addItem("h");
    m_keySwitch->addItem("i");
    m_keySwitch->addItem("j");
    m_keySwitch->addItem("k");
    m_keySwitch->addItem("l");
    m_keySwitch->addItem("m");
    m_keySwitch->addItem("n");
    m_keySwitch->addItem("o");
    m_keySwitch->addItem("p");
    m_keySwitch->addItem("q");
    m_keySwitch->addItem("r");
    m_keySwitch->addItem("s");
    m_keySwitch->addItem("t");
    m_keySwitch->addItem("u");
    m_keySwitch->addItem("v");
    m_keySwitch->addItem("w");
    m_keySwitch->addItem("x");
    m_keySwitch->addItem("y");
    m_keySwitch->addItem("z");
    m_keySwitch->addItem("SPACE");
    m_keySwitch->addItem("F1");
    m_keySwitch->addItem("F2");
    m_keySwitch->addItem("F3");
    m_keySwitch->addItem("F4");
    m_keySwitch->addItem("F5");
    m_keySwitch->addItem("F6");
    m_keySwitch->addItem("F7");
    m_keySwitch->addItem("F8");
    m_keySwitch->addItem("F9");
    m_keySwitch->addItem("F10");
    m_keySwitch->addItem("F11");
    m_keySwitch->addItem("F12");
    m_keySwitch->addItem("MOUSE1");
    m_keySwitch->addItem("MOUSE2");
    m_keySwitch->addItem("MOUSE3");
    m_keySwitch->addItem("HOME");
    m_keySwitch->addItem("END");
    m_keySwitch->addItem("DELETE");
    m_keySwitch->addItem("PGUP");
    m_keySwitch->addItem("PGDN");
    m_keySwitch->addItem("INS");
    m_keySwitch->addItem("UPARROW");
    m_keySwitch->addItem("LEFTARROW");
    m_keySwitch->addItem("DOWNARROW");
    m_keySwitch->addItem("KP_HOME");
    m_keySwitch->addItem("KP_UPARROW");
    m_keySwitch->addItem("KP_LEFTARROW");
    m_keySwitch->addItem("KP_PGUP");
    m_keySwitch->addItem("KP_5");
    m_keySwitch->addItem("KP_END");
    m_keySwitch->addItem("KP_DOWNARROW");
    m_keySwitch->addItem("KP_PGUP");
    m_keySwitch->addItem("KP_PGDN");
    m_keySwitch->addItem("KP_INS");
    m_keySwitch->addItem("KP_PGUP");
    m_keySwitch->addItem("KP_DEL");
    m_keySwitch->addItem("KP_SLASH");
    m_keySwitch->addItem("KP_STAR");
    m_keySwitch->addItem("KP_MINUS");
    m_keySwitch->addItem("KP_PLUS");
    m_keySwitch->addItem("KP_ENTER");

    m_switch->setEnabled(false);
    m_keyAccept->setEnabled(false);
    m_keySwitch->setEnabled(false);
    m_modeEach->setChecked(true);
    m_radio->addWidget(m_modeEach);
    m_radio->addWidget(m_modeSwitch);

    m_radioButtons->setLayout(m_radio);


    m_switchingKeys->addWidget(m_switch);
    m_switchingKeys->addWidget(m_keySwitch);
    m_switchingKeys->addWidget(m_keyAccept);
    m_vbox1->addWidget(m_radioButtons);
    m_vbox1->addLayout(m_switchingKeys);
    m_vbox2->addWidget(m_widgetArme1);
    m_vbox2->addWidget(m_widgetArme2);
    m_vbox2->addWidget(m_widgetArme3);
    m_vbox2->addWidget(m_widgetArme4);
    m_vbox2->addWidget(m_widgetArme5);
    m_vbox2->addWidget(m_widgetArme6);
    m_vbox2->addWidget(m_widgetArme7);
    m_vbox2->addWidget(m_widgetArme8);
    m_vbox2->setSizeConstraint(QLayout::SetMinimumSize);

    m_widscroll->setLayout(m_vbox2);
    m_scroll->setWidget(m_widscroll);
    m_scroll->setMinimumHeight(100);
    m_scroll->setMinimumWidth(650);
   // m_scroll->setFixedHeight(100);


   // m_scroll->setLayout(m_vbox2);
    m_scroll->setWidgetResizable(true);
   m_scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   m_scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    m_vbox1->addWidget(m_scroll);
    m_vbox1->addWidget(m_build);
    m_vbox1->setSizeConstraint(QLayout::SetNoConstraint);

    this->setLayout(m_vbox1);
    QObject::connect(m_build, SIGNAL(clicked()), this, SLOT(ecrireDansConfigs()));
    QObject::connect(m_modeSwitch, SIGNAL(toggled(bool)), this, SLOT(disableBindingKeys(bool)));
}

void LayoutTabArme::changeFolder(QString newPath)
{
    *m_folder = newPath;
}

void LayoutTabArme::loadClass(int pos, QString keyAssociated, QString classString, bool modeToEnable)
{
    m_modeSwitch->setChecked(modeToEnable);//On active le mode souhaité selon le fichier
    if (modeToEnable == false)
    {
        m_modeEach->setChecked(true);
    }
    if (pos == 1)
    {
        m_widgetArme1->loadWec(keyAssociated, classString);
        m_widgetArme2->desactiver();
        m_widgetArme3->desactiver();
        m_widgetArme4->desactiver();
        m_widgetArme5->desactiver();
        m_widgetArme6->desactiver();
        m_widgetArme7->desactiver();
        m_widgetArme8->desactiver();
    }
    if (pos == 2)
    {
        m_widgetArme2->loadWec(keyAssociated, classString);
    }
    if (pos == 3)
    {
        m_widgetArme3->loadWec(keyAssociated, classString);
    }
    if (pos == 4)
    {
        m_widgetArme4->loadWec(keyAssociated, classString);
    }
    if (pos == 5)
    {
        m_widgetArme5->loadWec(keyAssociated, classString);
    }
    if (pos == 6)
    {
        m_widgetArme6->loadWec(keyAssociated, classString);
    }
    if (pos == 7)
    {
        m_widgetArme7->loadWec(keyAssociated, classString);
    }
    if (pos == 8)
    {
        m_widgetArme8->loadWec(keyAssociated, classString);
    }
}

void LayoutTabArme::loadSwitchKeys(QString switching, QString accepting)
{
    m_keySwitch->setCurrentText(switching);
    m_keyAccept->setCurrentText(accepting);
}

/*LayoutTabArme::~LayoutTabArme()
{

}*/

void LayoutTabArme::ecrireDansConfigs()
{
    if(*m_folder != "")
    {
        QString cheminWeap1(*m_folder + "/weapon1.cfg");
        QString cheminAutoexec(*m_folder + "/autoexec.cfg");
        bool rajouterLigne(false);
        QString ligne;
        QFile fichierWeapon1(cheminWeap1);
        fichierWeapon1.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream ecrireWeapon(&fichierWeapon1);
        QFile fichierAutoexec(cheminAutoexec);
        if (fichierAutoexec.open(QIODevice::ReadWrite))
        {
            QTextStream lireAutoexec(&fichierAutoexec);
            while (!lireAutoexec.atEnd())
            {
                ligne = lireAutoexec.readLine();
                if(ligne == "exec weapon1.cfg")
                {
                    rajouterLigne = true;
                }
            }

            fichierAutoexec.close();
        }
        if (rajouterLigne == false)
        {
            QFile fichierAutoexec(cheminAutoexec);
            fichierAutoexec.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
            QTextStream ecrireAutoexec(&fichierAutoexec);
            ecrireAutoexec << endl << "exec weapon1.cfg";
            fichierAutoexec.close();
        }
        if (m_modeEach->isChecked())
        {
            ecrireWeapon << "//wec" << endl;
            if (m_widgetArme1->etat())
            {
                ecrireWeapon << "set lo_01" << " \"set load vstr lo_02" << "; gear " << m_widgetArme1->chaineConfig() << "; ut_echo " << m_widgetArme1->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme1->lireKey() << " \"vstr lo_01" << "\"" << endl;
            }
            if (m_widgetArme2->etat())
            {
                ecrireWeapon << "set lo_02" << " \"set load vstr lo_03" << "; gear " << m_widgetArme2->chaineConfig() << "; ut_echo " << m_widgetArme2->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme2->lireKey() << " \"vstr lo_02" << "\"" << endl;
            }
            if (m_widgetArme3->etat())
            {
                ecrireWeapon << "set lo_03" << " \"set load vstr lo_04" << "; gear " << m_widgetArme3->chaineConfig() << "; ut_echo " << m_widgetArme3->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme3->lireKey() << " \"vstr lo_03" << "\"" << endl;
            }
            if (m_widgetArme4->etat())
            {
                ecrireWeapon << "set lo_04" << " \"set load vstr lo_05" << "; gear " << m_widgetArme4->chaineConfig() << "; ut_echo " << m_widgetArme4->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme4->lireKey() << " \"vstr lo_04" << "\"" << endl;
            }
            if (m_widgetArme5->etat())
            {
                ecrireWeapon << "set lo_05" << " \"set load vstr lo_06" << "; gear " << m_widgetArme5->chaineConfig() << "; ut_echo " << m_widgetArme5->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme5->lireKey() << " \"vstr lo_05" << "\"" << endl;
            }
            if (m_widgetArme6->etat())
            {
                ecrireWeapon << "set lo_06" << " \"set load vstr lo_07" << "; gear " << m_widgetArme6->chaineConfig() << "; ut_echo " << m_widgetArme6->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme6->lireKey() << " \"vstr lo_06" << "\"" << endl;
            }
            if (m_widgetArme7->etat())
            {
                ecrireWeapon << "set lo_07" << " \"set load vstr lo_08" << "; gear " << m_widgetArme7->chaineConfig() << "; ut_echo " << m_widgetArme7->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme7->lireKey() << " \"vstr lo_07" << "\"" << endl;
            }
            if (m_widgetArme8->etat())
            {
                ecrireWeapon << "set lo_08" << " \"set load vstr lo_09" << "; gear " << m_widgetArme8->chaineConfig() << "; ut_echo " << m_widgetArme8->currentWeapons() << "\" " << endl; // on écrit dans le fichier la configuration
                ecrireWeapon << "bind " << m_widgetArme8->lireKey() << " \"vstr lo_08" << "\"" << endl;
            }
            fichierWeapon1.close();
        }
        if (m_modeSwitch->isChecked())
        {
            ecrireWeapon << "//wes" << endl;
            vector <QString> widgetsEnabled;
            if (m_widgetArme1->etat())
            {
                widgetsEnabled.push_back("m_widgetArme1");
            }
            if (m_widgetArme2->etat())
            {
                widgetsEnabled.push_back("m_widgetArme2");
            }
            if (m_widgetArme3->etat())
            {
                widgetsEnabled.push_back("m_widgetArme3");
            }
            if (m_widgetArme4->etat())
            {
                widgetsEnabled.push_back("m_widgetArme4");
            }
            if (m_widgetArme5->etat())
            {
                widgetsEnabled.push_back("m_widgetArme5");
            }
            if (m_widgetArme6->etat())
            {
                widgetsEnabled.push_back("m_widgetArme6");
            }
            if (m_widgetArme7->etat())
            {
                widgetsEnabled.push_back("m_widgetArme7");
            }
            if (m_widgetArme8->etat())
            {
                widgetsEnabled.push_back("m_widgetArme8");
            }
            for (int i(0); i<widgetsEnabled.size(); ++i)
            {
                if (i != widgetsEnabled.size() - 1)
                {
                    if (widgetsEnabled[i] == "m_widgetArme1")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme1->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme1->chaineConfig() << "\"\"" << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme2")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme2->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme2->chaineConfig() << "\"\"" << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme3")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme3->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme3->chaineConfig() << "\"\"" << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme4")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme4->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme4->chaineConfig() << "\"\"" << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme5")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme5->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme5->chaineConfig() << "\"\"" << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme6")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme6->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme6->chaineConfig() << "\"\"" << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme7")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_0" << i+2 << "; ut_echo " << m_widgetArme7->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme7->chaineConfig() << "\"\"" << endl;
                    }
                }
                if (i == widgetsEnabled.size() - 1)
                {
                    if (widgetsEnabled[i] == "m_widgetArme1")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme1->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme1->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme2")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme2->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme2->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme3")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme3->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme3->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme4")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme4->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme4->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme5")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme5->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme5->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme6")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme6->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme6->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme7")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme7->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme7->chaineConfig() << "\"\"" << endl << endl;
                    }
                    if (widgetsEnabled[i] == "m_widgetArme8")
                    {
                        ecrireWeapon << "set UCGset_0" << i+1 << " \"set UCG-weaponscript vstr UCGset_01; ut_echo " << m_widgetArme8->currentWeapons() << " ; set UCGweapset \"set gear " << m_widgetArme8->chaineConfig() << "\"\"" << endl << endl;
                    }
                }
            }
            ecrireWeapon << "set UCG-weaponscript \"vstr UCGset_01\"" << endl;
            ecrireWeapon << "bind " << m_keySwitch->currentText() << " \"vstr UCG-weaponscript\"" << endl;
            ecrireWeapon << "bind " << m_keyAccept->currentText() << " \"vstr UCGweapset; ut_echo selected\"";
            fichierWeapon1.close();
        }
        QMessageBox::information(this, tr("Successful"), tr("Build has finished correctly"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Please select your q3ut4 folder before to build !"));
    }
}

void LayoutTabArme::disableBindingKeys(bool switchEnable)
{
    m_widgetArme1->disableKey(switchEnable);
    m_widgetArme1->changerBool(switchEnable);
    m_widgetArme2->disableKey(switchEnable);
    m_widgetArme2->changerBool(switchEnable);
    m_widgetArme3->disableKey(switchEnable);
    m_widgetArme3->changerBool(switchEnable);
    m_widgetArme4->disableKey(switchEnable);
    m_widgetArme4->changerBool(switchEnable);
    m_widgetArme5->disableKey(switchEnable);
    m_widgetArme5->changerBool(switchEnable);
    m_widgetArme6->disableKey(switchEnable);
    m_widgetArme6->changerBool(switchEnable);
    m_widgetArme7->disableKey(switchEnable);
    m_widgetArme7->changerBool(switchEnable);
    m_widgetArme8->disableKey(switchEnable);
    m_widgetArme8->changerBool(switchEnable);
    m_switch->setEnabled(switchEnable);
    m_keyAccept->setEnabled(switchEnable);
    m_keySwitch->setEnabled(switchEnable);
}
