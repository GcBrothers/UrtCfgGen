#include "LayoutTabRadio.h"

LayoutTabRadio::LayoutTabRadio()
{
    m_vbox1 = new QVBoxLayout;
    m_vBox2 = new QVBoxLayout;
    m_widgetRadio1 = new LayoutRadio(true);
    m_widgetRadio2 = new LayoutRadio;
    m_widgetRadio3 = new LayoutRadio;
    m_widgetRadio4 = new LayoutRadio;
    m_widgetRadio5 = new LayoutRadio;
    m_widgetRadio6 = new LayoutRadio;
    m_widgetRadio7 = new LayoutRadio;
    m_widgetRadio8 = new LayoutRadio;
    m_build1 = new QPushButton(tr("Build !"));
    m_folder = new QString;
    m_scrollingArea = new QScrollArea;
    m_scrolling = new QWidget;

    m_vBox2->addWidget(m_widgetRadio1);
    m_vBox2->addWidget(m_widgetRadio2);
    m_vBox2->addWidget(m_widgetRadio3);
    m_vBox2->addWidget(m_widgetRadio4);
    m_vBox2->addWidget(m_widgetRadio5);
    m_vBox2->addWidget(m_widgetRadio6);
    m_vBox2->addWidget(m_widgetRadio7);
    m_vBox2->addWidget(m_widgetRadio8);
    m_vBox2->setSizeConstraint(QLayout::SetMinimumSize);

    m_scrolling->setLayout(m_vBox2);
    m_scrollingArea->setWidget(m_scrolling);
    m_scrollingArea->setMinimumHeight(100);
    m_scrollingArea->setWidgetResizable(true);
    m_scrollingArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollingArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    m_vbox1->addWidget(m_scrollingArea);
    m_vbox1->addWidget(m_build1);

    this->setLayout(m_vbox1);

    QObject::connect(m_build1, SIGNAL(clicked()), this, SLOT(ecrireDansConfigs()));
}
void LayoutTabRadio::changeFolder(QString newPath)
{
    *m_folder = newPath;
}

void LayoutTabRadio::loadFile(int positionRadio, QString keyBinded, int bigCategory, int littleCategory, QString messageToWrite)
{
    if (positionRadio == 1)
    {
        m_widgetRadio1->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
        m_widgetRadio2->desactiver();
        m_widgetRadio3->desactiver();
        m_widgetRadio4->desactiver();
        m_widgetRadio5->desactiver();
        m_widgetRadio6->desactiver();
        m_widgetRadio7->desactiver();
        m_widgetRadio8->desactiver();
    }
    if (positionRadio == 2)
    {
        m_widgetRadio2->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
    if (positionRadio == 3)
    {
        m_widgetRadio3->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
    if (positionRadio == 4)
    {
        m_widgetRadio4->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
    if (positionRadio == 5)
    {
        m_widgetRadio5->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
    if (positionRadio == 6)
    {
        m_widgetRadio6->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
    if (positionRadio == 7)
    {
        m_widgetRadio7->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
    if (positionRadio == 8)
    {
        m_widgetRadio8->loadConfig(keyBinded, bigCategory, littleCategory, messageToWrite);
    }
}

void LayoutTabRadio::ecrireDansConfigs()
{
    if(*m_folder != "")
    {
        QString cheminRad1(*m_folder + "/radio1.cfg");
        QString cheminAutoexec(*m_folder + "/autoexec.cfg");
        bool rajouterLigne(false);
        QString ligne;
        QFile fichierRadio1(cheminRad1);
        fichierRadio1.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream ecrireRadio(&fichierRadio1);
        QFile fichierAutoexec(cheminAutoexec);
        if (fichierAutoexec.open(QIODevice::ReadWrite))
        {
            QTextStream lireAutoexec(&fichierAutoexec);
            while (!lireAutoexec.atEnd())
            {
                ligne = lireAutoexec.readLine();
                if(ligne == "exec radio1.cfg")
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
            ecrireAutoexec << endl << "exec radio1.cfg";
            fichierAutoexec.close();
        }
        ecrireRadio << "//rac" << endl;
        if (m_widgetRadio1->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio1->lireKey() << " \"ut_radio " << m_widgetRadio1->lireBigCont() << " " << m_widgetRadio1->lireLitCont() << " " << m_widgetRadio1->lireText() << "\"" << endl;
        }
        if (m_widgetRadio2->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio2->lireKey() << " \"ut_radio " << m_widgetRadio2->lireBigCont() << " " << m_widgetRadio2->lireLitCont() << " " << m_widgetRadio2->lireText() << "\"" << endl;
        }
        if (m_widgetRadio3->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio3->lireKey() << " \"ut_radio " << m_widgetRadio3->lireBigCont() << " " << m_widgetRadio3->lireLitCont() << " " << m_widgetRadio3->lireText() << "\"" << endl;
        }
        if (m_widgetRadio4->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio4->lireKey() << " \"ut_radio " << m_widgetRadio4->lireBigCont() << " " << m_widgetRadio4->lireLitCont() << " " << m_widgetRadio4->lireText() << "\"" << endl;
        }
        if (m_widgetRadio5->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio5->lireKey() << " \"ut_radio " << m_widgetRadio5->lireBigCont() << " " << m_widgetRadio5->lireLitCont() << " " << m_widgetRadio5->lireText() << "\"" << endl;
        }
        if (m_widgetRadio6->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio6->lireKey() << " \"ut_radio " << m_widgetRadio6->lireBigCont() << " " << m_widgetRadio6->lireLitCont() << " " << m_widgetRadio6->lireText() << "\"" << endl;
        }
        if (m_widgetRadio7->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio7->lireKey() << " \"ut_radio " << m_widgetRadio7->lireBigCont() << " " << m_widgetRadio7->lireLitCont() << " " << m_widgetRadio7->lireText() << "\"" << endl;
        }
        if (m_widgetRadio8->etat())
        {
            ecrireRadio << "bind " << m_widgetRadio8->lireKey() << " \"ut_radio " << m_widgetRadio8->lireBigCont() << " " << m_widgetRadio8->lireLitCont() << " " << m_widgetRadio8->lireText() << "\"" << endl;
        }
        fichierRadio1.close();
        QMessageBox::information(this, tr("Successful"), tr("Build has finished correctly"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Please select your q3ut4 folder before to build !"));
    }
}
