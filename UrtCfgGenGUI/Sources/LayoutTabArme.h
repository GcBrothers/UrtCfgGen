#ifndef DEF_LAYOUTTABARME
#define DEF_LAYOUTTABARME
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRadioButton>
#include <QGroupBox>
#include <vector>
#include <QScrollArea>
#include <QVBoxLayout>
#include "LayoutArme.h"

class LayoutTabArme : public QWidget
{
    Q_OBJECT

    public:
    LayoutTabArme();
    void changeFolder(QString newPath);
    void loadClass(int pos, QString keyAssociated, QString classString, bool modeToEnable);
    void loadSwitchKeys(QString switching, QString accepting);
//    ~LayoutTabArme();

    public slots:
    void ecrireDansConfigs();
    void disableBindingKeys(bool switchEnable);

    private:
        QVBoxLayout *m_vbox1;
        QVBoxLayout *m_vbox2;

        QHBoxLayout *m_radio;
        QHBoxLayout *m_switchingKeys;
        QLabel *m_switch;
        QComboBox *m_keyAccept;
        QComboBox *m_keySwitch;
        QGroupBox *m_radioButtons;
        QRadioButton *m_modeEach;
        QRadioButton *m_modeSwitch;
        LayoutArme *m_widgetArme1;
        LayoutArme *m_widgetArme2;
        LayoutArme *m_widgetArme3;
        LayoutArme *m_widgetArme4;
        LayoutArme *m_widgetArme5;
        LayoutArme *m_widgetArme6;
        LayoutArme *m_widgetArme7;
        LayoutArme *m_widgetArme8;
        LayoutArme **m_widgetsArme;
        QPushButton *m_build;
        QString *m_folder;

        QScrollArea *m_scroll;
        QWidget *m_widscroll;
};

#endif
