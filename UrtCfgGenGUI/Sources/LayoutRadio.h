#ifndef LAYOUTRADIO_H
#define LAYOUTRADIO_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>
#include <QString>

class LayoutRadio : public QWidget
{
    Q_OBJECT
public:
    LayoutRadio(bool activeDefaut = false);
    void desactiver();
    bool etat() const;
    QString lireKey() const;
    int lireBigCont() const;
    int lireLitCont() const;
    QString lireText() const;
    void loadConfig(QString keyAssociated, int bigCat, int littleCat, QString messageWritten);
public slots:
    void activerDesactiver(int etatCheckBox);
    void changerMessage();
    void limiterSpin(int valeurBig = 0);
private:
    QHBoxLayout *m_hLayout; //Le layout supérieur
    QVBoxLayout *m_vLayout; // Le layout complet

    QCheckBox *m_boxEnable;

    QLabel *m_bind; //Le label Bind
    QLabel *m_with; //Le label with
    QLabel *m_messageRadio;


    QComboBox *m_keyToBind; // La touche à binder
    QComboBox *m_bigCategory; //Les grandes catégories

    QSpinBox *m_littleCategory;

    QLineEdit *m_userText; //le texte à afficher
};

#endif // LAYOUTRADIO_H
