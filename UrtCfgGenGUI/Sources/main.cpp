#include <QApplication>
#include "LayoutTabArme.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QTranslator>
#include "LayoutArme.h"
#include "Window.h"

int main(int argc,char *argv[])
{
    QApplication app(argc, argv);
    QTranslator translate;
    translate.load("ucg_fr");
    app.installTranslator(&translate);
  //  QHBoxLayout *hbox = new QHBoxLayout;
    MyWindow fenetre;
  //  LayoutTabArme widget1;
  //  hbox->addWidget(&widget1);
  //  fenetre.setLayout(hbox);
    fenetre.show();
    return app.exec();
}
