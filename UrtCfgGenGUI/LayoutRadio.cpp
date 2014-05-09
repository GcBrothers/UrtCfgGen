#include "LayoutRadio.h"

LayoutRadio::LayoutRadio(bool activeDefaut)
{
    m_hLayout = new QHBoxLayout;
    m_vLayout = new QVBoxLayout;
    m_boxEnable = new QCheckBox;
    m_bind = new QLabel(tr("Bind :"));
    m_with = new QLabel(tr("with :"));
    m_messageRadio = new QLabel("1. Affirmative!");
    m_keyToBind = new QComboBox;
    m_bigCategory = new QComboBox;
    m_littleCategory = new QSpinBox;
    m_userText = new QLineEdit;


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

    m_bigCategory->addItem("1. Answers");
    m_bigCategory->addItem("2. Orders");
    m_bigCategory->addItem("3. Status");
    m_bigCategory->addItem("4. Requests");
    m_bigCategory->addItem("5. Enemy Activity");
    m_bigCategory->addItem("6. Directions");
    m_bigCategory->addItem("7. CTF");
    m_bigCategory->addItem("8. Bomb");
    m_bigCategory->addItem("9. Miscellaneous");

    m_userText->setMaxLength(120);

    m_littleCategory->setMaximum(8);
    m_littleCategory->setMinimum(1);

    m_hLayout->addWidget(m_boxEnable);
    m_hLayout->addWidget(m_bind);
    m_hLayout->addWidget(m_keyToBind);
    m_hLayout->addWidget(m_with);
    m_hLayout->addWidget(m_bigCategory);
    m_hLayout->addWidget(m_littleCategory);
    m_hLayout->addWidget(m_messageRadio);

    m_vLayout->addLayout(m_hLayout);
    m_vLayout->addWidget(m_userText);

    this->setLayout(m_vLayout);

    QObject::connect(m_boxEnable, SIGNAL(stateChanged(int)), this, SLOT(activerDesactiver(int)));
    QObject::connect(m_bigCategory, SIGNAL(currentIndexChanged(int)), this, SLOT(changerMessage()));
    QObject::connect(m_littleCategory, SIGNAL(valueChanged(int)), this, SLOT(changerMessage()));
    QObject::connect(m_bigCategory, SIGNAL(currentIndexChanged(int)), this, SLOT(limiterSpin(int)));
}

void LayoutRadio::desactiver()
{
    m_boxEnable->setChecked(false);
    m_bind->setEnabled(false);
    m_with->setEnabled(false);
    m_messageRadio->setEnabled(false);
    m_keyToBind->setEnabled(false);
    m_bigCategory->setEnabled(false);
    m_littleCategory->setEnabled(false);
    m_userText->setEnabled(false);
}

bool LayoutRadio::etat() const
{
    return m_boxEnable->isChecked();
}

QString LayoutRadio::lireKey() const
{
    return m_keyToBind->currentText();
}

int LayoutRadio::lireBigCont() const
{
    int numero(0);
    numero = m_bigCategory->currentIndex() + 1;
    return numero;
}

int LayoutRadio::lireLitCont() const
{
    int numero(0);
    numero = m_littleCategory->value();
    return numero;
}

QString LayoutRadio::lireText() const
{
    return m_userText->text();
}

void LayoutRadio::loadConfig(QString keyAssociated, int bigCat, int littleCat, QString messageWritten)
{
    m_boxEnable->setChecked(true);
    m_keyToBind->setCurrentText(keyAssociated);
    m_bigCategory->setCurrentIndex(bigCat - 1);
    m_littleCategory->setValue(littleCat);
    m_userText->setText(messageWritten);
}


void LayoutRadio::activerDesactiver(int etatCheckBox)
{
    if (etatCheckBox)
    {
        m_bind->setEnabled(true);
        m_with->setEnabled(true);
        m_messageRadio->setEnabled(true);
        m_keyToBind->setEnabled(true);
        m_bigCategory->setEnabled(true);
        m_littleCategory->setEnabled(true);
        m_userText->setEnabled(true);
    }
    if (etatCheckBox == 0)
    {
        m_bind->setEnabled(false);
        m_with->setEnabled(false);
        m_messageRadio->setEnabled(false);
        m_keyToBind->setEnabled(false);
        m_bigCategory->setEnabled(false);
        m_littleCategory->setEnabled(false);
        m_userText->setEnabled(false);
    }

}

void LayoutRadio::changerMessage()
{
    int currentIndexBig(m_bigCategory->currentIndex());
    currentIndexBig += 1;
    switch (currentIndexBig)
    {
    case 1:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. Affirmative!");
            break;
        case 2:
            m_messageRadio->setText("2. Negative!");
            break;
        case 3:
            m_messageRadio->setText("3. I'm on it!");
            break;
        case 4:
            m_messageRadio->setText("4. Area secured.");
            break;
        case 5:
            m_messageRadio->setText("5. Base is secure.");
            break;
        case 6:
            m_messageRadio->setText("6. Medic on the way, hang in there.");
            break;
        case 7:
            m_messageRadio->setText("7. I've got your back.");
            break;
        case 8:
            m_messageRadio->setText("8. Enemy terminated.");
            break;
        default:
            break;
        }
        break;
    case 2:
        switch(m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. Move in.");
            break;
        case 2:
            m_messageRadio->setText("2. Fallback and regroup.");
            break;
        case 3:
            m_messageRadio->setText("3. Hold your position.");
            break;
        case 4:
            m_messageRadio->setText("4. Stick with me.");
            break;
        case 5:
            m_messageRadio->setText("5. Cover me.");
            break;
        case 6:
            m_messageRadio->setText("6. Requesting backup.");
            break;
        case 7:
            m_messageRadio->setText("7. Go for the objective.");
            break;
        case 8:
            m_messageRadio->setText("8. Flank them!");
            break;
        case 9:
            m_messageRadio->setText("9. Double time, let's move!");
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. I'm moving in.");
            break;
        case 2:
            m_messageRadio->setText("2. Awaiting orders.");
            break;
        case 3:
            m_messageRadio->setText("3. I need a medic!");
            break;
        case 4:
            m_messageRadio->setText("4. Objective in sight.");
            break;
        case 5:
            m_messageRadio->setText("5. Objective is clear.");
            break;
        case 6:
            m_messageRadio->setText("6. I'm attacking.");
            break;
        case 7:
            m_messageRadio->setText("7. I'm defending.");
            break;
        case 8:
            m_messageRadio->setText("8. I'm flanking.");
            break;
        case 9:
            m_messageRadio->setText("9. Holding here.");
            break;
        default:
            break;
        }
        break;
    case 4:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. Status?");
            break;
        case 2:
            m_messageRadio->setText("2. Objective status?");
            break;
        case 3:
            m_messageRadio->setText("3. Base status?");
            break;
        case 4:
            m_messageRadio->setText("4. Where's the enemy?");
            break;
        case 5:
            m_messageRadio->setText("5. Where are the medics?");
            break;
        case 6:
            m_messageRadio->setText("6. Anyone need support?");
            break;
        case 7:
            m_messageRadio->setText("7. Anyone need a medic?");
            break;
        case 8:
            m_messageRadio->setText("8. Who's ya daddy?");
            break;
        case 9:
            m_messageRadio->setText("9. How the hell are ya?");
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. Enemy spotted!");
            break;
        case 2:
            m_messageRadio->setText("2. Enemy heard!");
            break;
        case 3:
            m_messageRadio->setText("3. Enemy is flanking!");
            break;
        case 4:
            m_messageRadio->setText("4. Enemy headed your way!");
            break;
        case 5:
            m_messageRadio->setText("5. Incoming!");
            break;
        case 6:
            m_messageRadio->setText("6. Objective in danger!");
            break;
        default:
            break;
        }
        break;
    case 6:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. North");
            break;
        case 2:
            m_messageRadio->setText("2. South.");
            break;
        case 3:
            m_messageRadio->setText("3. East.");
            break;
        case 4:
            m_messageRadio->setText("4. West.");
            break;
        case 5:
            m_messageRadio->setText("5. Base.");
            break;
        case 6:
            m_messageRadio->setText("6. High.");
            break;
        case 7:
            m_messageRadio->setText("7. Low.");
            break;
        case 8:
            m_messageRadio->setText("8. Water.");
            break;
        case 9:
            m_messageRadio->setText("9. Here.");
            break;
        }
        break;
    case 7:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. I've got the flag.");
            break;
        case 2:
            m_messageRadio->setText("2. I'm going for the flag.");
            break;
        case 3:
            m_messageRadio->setText("3. They have our flag.");
            break;
        case 4:
            m_messageRadio->setText("4. Base is being overrun!");
            break;
        case 5:
            m_messageRadio->setText("5. Recover the flag!");
            break;
        case 6:
            m_messageRadio->setText("6. Flag exiting left.");
            break;
        case 7:
            m_messageRadio->setText("7. Flag exiting right.");
            break;
        case 8:
            m_messageRadio->setText("8. Flag exiting front.");
            break;
        case 9:
            m_messageRadio->setText("9.Flag exiting back.");
            break;
        default:
            break;
        }
        break;
    case 8:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. Heading to Bombsite A.");
            break;
        case 2:
            m_messageRadio->setText("2. Heading to Bombsite B.");
            break;
        case 3:
            m_messageRadio->setText("3. Enemy at Bombsite A.");
            break;
        case 4:
            m_messageRadio->setText("4. Enemy at Bombsite B.");
            break;
        case 5:
            m_messageRadio->setText("5. I have the bomb.");
            break;
        case 6:
            m_messageRadio->setText("6. The bomb is loose!");
            break;
        default:
            break;
        }
        break;
    case 9:
        switch (m_littleCategory->value())
        {
        case 1:
            m_messageRadio->setText("1. Good job, team.");
            break;
        case 2:
            m_messageRadio->setText("2. Nice one.");
            break;
        case 3:
            m_messageRadio->setText("3. Check your fire!");
            break;
        case 4:
            m_messageRadio->setText("4. Sorry about that.");
            break;
        case 5:
            m_messageRadio->setText("5. Whatever.");
            break;
        case 6:
            m_messageRadio->setText("6. No problem.");
            break;
        case 7:
            m_messageRadio->setText("7. Oh, you idiot.");
            break;
        case 8:
            m_messageRadio->setText("8. What the f***, over?");
            break;
        case 9:
            m_messageRadio->setText("9. Thanks!");
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void LayoutRadio::limiterSpin(int valeurBig)
{
    valeurBig += 1;
    if (valeurBig == 1)
    {
        m_littleCategory->setMaximum(8);
    }
    if (valeurBig == 2)
    {
        m_littleCategory->setMaximum(9);
    }
    if (valeurBig == 3)
    {
        m_littleCategory->setMaximum(9);
    }
    if (valeurBig == 4)
    {
        m_littleCategory->setMaximum(9);
    }
    if (valeurBig == 5)
    {
        m_littleCategory->setMaximum(6);
    }
    if (valeurBig == 6)
    {
        m_littleCategory->setMaximum(9);
    }
    if (valeurBig == 7)
    {
        m_littleCategory->setMaximum(9);
    }
    if (valeurBig == 8)
    {
        m_littleCategory->setMaximum(6);
    }
    if (valeurBig == 9)
    {
        m_littleCategory->setMaximum(9);
    }
}
