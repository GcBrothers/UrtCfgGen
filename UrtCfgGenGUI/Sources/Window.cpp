#include "Window.h"

MyWindow::MyWindow()
{
    m_vBox = new QVBoxLayout;
    m_widget1 = new LayoutTabArme;
    m_widget2 = new LayoutTabRadio;
    m_selectFolder = new QPushButton(tr("Select your q3ut4 folder"));
    m_currentFolder = new QLabel;
    m_tabs = new QTabWidget;
    m_zoneCentrale = new QWidget;
    QMenu *menuFile = menuBar()->addMenu(tr("&File"));
    QAction *actionRead = new QAction(tr("&Read config..."), this);

 //   m_widget1->setMinimumHeight(10);

    this->setWindowTitle("Urban Terror Config Generator v1.2");
    m_tabs->addTab(m_widget1, tr("Weapon Config"));
    m_tabs->addTab(m_widget2, tr("Radio Config"));
    m_tabs->setMinimumHeight(250);
    m_vBox->addWidget(m_selectFolder);
    m_vBox->addWidget(m_currentFolder);
    m_vBox->addWidget(m_tabs);
    menuFile->addAction(actionRead);


   // this->setLayout(m_vBox);
    m_zoneCentrale->setLayout(m_vBox);
    setCentralWidget(m_zoneCentrale);

    QObject::connect(m_selectFolder, SIGNAL(clicked()), this, SLOT(selectionFolder()));
    QObject::connect(actionRead, SIGNAL(triggered()), this, SLOT(readFile()));
  //  QObject::connect(m_tabs, SIGNAL(currentChanged(int)), this, SLOT(tabResize(int)));
}

void MyWindow::changerFolder(QString path)
{
    m_widget1->changeFolder(path);
    m_widget2->changeFolder(path);
}

void MyWindow::selectionFolder()
{
    QString dossier = QFileDialog::getExistingDirectory(this);
    changerFolder(dossier);
    m_currentFolder->setText(dossier);
}

void MyWindow::readFile()
{
    QString pathwayReadFile = QFileDialog::getOpenFileName(this);
    QString file;
    QFile fileToRead(pathwayReadFile);
    bool modeEachEnable(true);
    if (fileToRead.open(QIODevice::ReadOnly))
    {
        QTextStream flux(&fileToRead);
        file = flux.readLine();
        if (file == "//wes")//Dans le cas d'une "weapon class switch" :P
        {
            modeEachEnable = true;
            m_tabs->setCurrentIndex(0);
            int i = 1;
            int n(0);  // On cherche la position des guillemets pour récupérer la touche associée
            qint8 positionQuoteBrackets1(0);
            QChar quoteBrackets1('\"');
            file = flux.readLine();
            while (file != "")
            {
                n = 0;
                positionQuoteBrackets1 = 0;
                while (n < file.size() && positionQuoteBrackets1 == 0) //Pour trouver la position des premiers guillemets
                {
                    if (file[n] == quoteBrackets1)
                    {
                        positionQuoteBrackets1 = n;
                    }
                    n++;
                }
                file.remove(0, positionQuoteBrackets1+1);//On supprime la première partie de la ligne
                n = 0;//On réinitialise les compteurs
                positionQuoteBrackets1 = 0;
                while (n < file.size() && positionQuoteBrackets1 == 0) //Pour trouver la position des seconds guillemets
                {
                    if (file[n] == quoteBrackets1)
                    {
                        positionQuoteBrackets1 = n;
                    }
                    n++;
                }
                file.remove(0, positionQuoteBrackets1+10);//On supprime la seconde partie de la ligne
                file.truncate(7); //On supprime les guillemets de la fin
             //   QMessageBox::information(this, "Test", "String weapon = " + file);
                m_widget1->loadClass(i, "a", file, modeEachEnable);
                i++;
             //   QMessageBox::information(this, "Wes", "File :" + file);
                file = flux.readLine();
            }
            file = flux.readLine();
            file = flux.readLine(); // On arrive à la ligne du switching key
            file.remove(0, 4);
            n = 0;//On réinitialise les compteurs
            positionQuoteBrackets1 = 0;
            while (n < file.size() && positionQuoteBrackets1 == 0) //Pour trouver la position des guillemets
            {
                if (file[n] == quoteBrackets1)
                {
                    positionQuoteBrackets1 = n;
                }
                n++;
            }
            file.truncate(positionQuoteBrackets1-1);
            QString switchKey(file);
            file = flux.readLine(); // On arrive à la ligne du accept key
            file.remove(0, 4);
            n = 0;//On réinitialise les compteurs
            positionQuoteBrackets1 = 0;
            while (n < file.size() && positionQuoteBrackets1 == 0) //Pour trouver la position des guillemets
            {
                if (file[n] == quoteBrackets1)
                {
                    positionQuoteBrackets1 = n;
                }
                n++;
            }
            file.truncate(positionQuoteBrackets1-1);
            QString acceptKey(file);
            m_widget1->loadSwitchKeys(switchKey, acceptKey);
            QMessageBox::information(this, "Done !", "Weapon switching config loaded correctly");
            fileToRead.close();
        }
        else if (file == "//wec")
        {
            modeEachEnable = false;
            m_tabs->setCurrentIndex(0); //On se place sur l'onglet Weapon Config
          //  QMessageBox::information(this, "Cfg Type", "weapon class config");
            int i=1;
            file = flux.readLine();
            while (file != "")
            {
                if (file != 0)
                {
                    file.remove(0, 37);
                }
                file.truncate(7);
                QString stringWeapon(file); // On récupère la chaine qui correspond aux armes & équipement


                file = flux.readLine();
                file.remove(0, 4); //On supprime le "bind" du début
                int n(0); // On cherche la position des guillemets pour récupérer la touche associée
                qint8 positionQuoteBrackets1(0);
                QChar quoteBrackets1('\"');
                while (n < file.size() && positionQuoteBrackets1 == 0) //Pour trouver la position des guillemets
                {
                    if (file[n] == quoteBrackets1)
                    {
                        positionQuoteBrackets1 = n;
                    }
                    n++;
                }
                QString keyBinded(file);
                keyBinded.truncate(positionQuoteBrackets1-1);
                m_widget1->loadClass(i, keyBinded, stringWeapon, modeEachEnable);//On envoie

                i++;
                file = flux.readLine();
            }
            QMessageBox::information(this, "Done !", "Weapon config loaded correctly");
            fileToRead.close();
        }
        else if (file == "//rac")
        {
            m_tabs->setCurrentIndex(1); //On se place sur l'onglet Radio Config
            int i=1;
            while (file != "")
            {
                file = flux.readLine();
                if (file != "")
                {
                    file.remove(0,4);
                    int n(0);
                    qint8 positionQuoteBrackets(0);
                    QChar quoteBrackets('\"');
                    while (n < file.size() && positionQuoteBrackets == 0) //Pour trouver la position des guillemets
                    {
                        if (file[n] == quoteBrackets)
                        {
                            positionQuoteBrackets = n;
                        }
                        n++;
                    }
                    QString associatedKey(file); //On crée la touche à associer pour la tronquer après et récupérer la touche
                    associatedKey.truncate(positionQuoteBrackets-1);//On a la touche à associer
                    QString categoryString(file); //On récupère la première position
                    categoryString.remove(0, associatedKey.size() + 11); //On supprime tous les caractères avant la catégorie 1
                    categoryString.truncate(1); //On supprime ce qu'il y a après
                    int firstCategory(categoryString.toInt(0, 10)); //On récupère la valeur de la première catégorie du message
                    categoryString = file; // On recommence la manip' précédente avec la deuxième catégorie
                    categoryString.remove(0, associatedKey.size() + 13);
                    categoryString.truncate(1);
                    int secondCategory(categoryString.toInt(0, 10));
                    QString writtenMessage(file); //On récupère enfin le message écrit par l'utilisateur
                    writtenMessage.remove(0, associatedKey.size() + 15); //Même méthode que précédemment
                    writtenMessage.remove(writtenMessage.size() - 1, 1);
                    m_widget2->loadFile(i, associatedKey, firstCategory, secondCategory, writtenMessage); //On appelle la fonction de l'onglet Radio qui chargera la valeur
                 //   QMessageBox::information(this, "Message Débug","Message écrit = " + writtenMessage);
                }
                i++;
            }
            fileToRead.close();
            QMessageBox::information(this, "Done !", "Radio config loaded correctly");

        }
        else
        {
            QMessageBox::critical(this, "Error", "This config type isn't supported by UCG");
        }
    }
   // QMessageBox::information(this, "Cool", "Ca a l'air de marcher !");
}

/*void MyWindow::tabResize(int currentTab)
{
    if (currentTab == 0) //Si l'onglet sélectionné est arme
    {
        m_tabs->setMinimumHeight(250);
    }
}*/
