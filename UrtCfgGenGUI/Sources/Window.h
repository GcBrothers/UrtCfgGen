#ifndef WINDOW_H
#define WINDOW_H

#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QTabWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include "LayoutTabArme.h"
#include "LayoutTabRadio.h"

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    MyWindow();
    void changerFolder(QString path);

public slots:
    void selectionFolder();
    void readFile();
    //void tabResize(int currentTab);

private:
    QVBoxLayout *m_vBox;
    LayoutTabArme *m_widget1;
    LayoutTabRadio *m_widget2;
    QPushButton *m_selectFolder;
    QLabel *m_currentFolder;
    QTabWidget *m_tabs;
    QWidget *m_zoneCentrale;

};

#endif // WINDOW_H
