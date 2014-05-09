#ifndef LAYOUTTABRADIO_H
#define LAYOUTTABRADIO_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QScrollArea>
#include "LayoutRadio.h"

class LayoutTabRadio : public QWidget
{
    Q_OBJECT
public:
    LayoutTabRadio();
    void changeFolder(QString newPath);
    void loadFile(int positionRadio, QString keyBinded, int bigCategory, int littleCategory, QString messageToWrite); // Fonction pour écrire dans un widget Radio
public slots:
    void ecrireDansConfigs();
private:
    QVBoxLayout *m_vbox1;
    QVBoxLayout *m_vBox2;
    LayoutRadio *m_widgetRadio1;
    LayoutRadio *m_widgetRadio2;
    LayoutRadio *m_widgetRadio3;
    LayoutRadio *m_widgetRadio4;
    LayoutRadio *m_widgetRadio5;
    LayoutRadio *m_widgetRadio6;
    LayoutRadio *m_widgetRadio7;
    LayoutRadio *m_widgetRadio8;
    QPushButton *m_build1;
    QString *m_folder;

    QScrollArea *m_scrollingArea;
    QWidget *m_scrolling;
};

#endif // LAYOUTTABRADIO_H
