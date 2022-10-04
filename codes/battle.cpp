#include "battle.h"
#include "ui_battle.h"

Battle::Battle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battle)
{
    ui -> setupUi(this);
    ui -> graphicsView -> hide();

    BeginIni();
}

Battle::~Battle()
{
    delete ui;
    delete btnStart;
    delete btnGameStart;
    delete btnRandomDeck;
    delete card1Choosing;
    delete C1knightA;
    delete C1archerA;
    delete C1punchA;
    delete C1bombA;
    delete layout1;
    delete card2Choosing;
    delete C2knightA;
    delete C2archerA;
    delete C2punchA;
    delete C2bombA;
    delete layout2;
    delete LminionInfo;
    delete btnNextPage;
    delete btnLastPage;
    delete modeSel;
    delete mistySel;
    //delete heroSel;
    delete layout3;
    delete btnCard1;
    delete btnCard2;
    delete btnQuit;
    delete scene;
    delete scoreLabel;
    delete timer;
    delete timeLabel;
    delete btnReplay;
    delete btnExit;
    delete scoreResult;
    delete usingTime;
    delete btnHelper;
}

/*Beginning Page*/
void Battle::BeginIni()
{
    //For background
    this -> setAutoFillBackground(true);
    QPalette beginBg;
    beginBg.setBrush(QPalette::Background, QBrush(QPixmap(":/image/img/back2.gif").scaled(1480, 680)));
    this -> setPalette(beginBg);
    //Randdom deck
    qsrand(time(NULL));
    deck1 = qrand()% 8 + 1;
    deck2 = qrand()% 8 + 1;
    //For button
    btnStart = new QPushButton(tr("START"), this);
    btnStart -> setGeometry(590, 400, 300, 80);
    btnStart -> show();

    //click START button, and change page to manage deck
    connect(btnStart, SIGNAL(clicked()), this, SLOT(on_btnStart_clicked()));
}

void Battle::on_btnStart_clicked()
{
    //std::cout << "YA~";//For debuging
    btnStart -> hide();
    InfoIni();
}

/*Game Info Page*/
void Battle::InfoIni()
{
    //For background changing
    QPalette InfoBg;
    InfoBg.setBrush(QPalette::Background, QBrush(QPixmap(":/image/img/info.gif").scaled(1480, 680)));
    this -> setPalette(InfoBg);
    //For Buttons
    btnNextPage = new QPushButton(tr("next"),this);
    btnNextPage -> setGeometry(20, 10, 150, 60);
    btnNextPage -> show();
    connect(btnNextPage, SIGNAL(clicked()), this, SLOT(on_btnNextPage_clicked()));
}

void Battle::on_btnNextPage_clicked()
{
    btnNextPage -> hide();
    DeckIni();
}

/*Deck Management Page*/
void Battle::DeckIni()
{
    //For background changing
    QPalette deckManageBg;
    deckManageBg.setBrush(QPalette::Background, QBrush(QPixmap(":/image/img/back3.gif").scaled(1480, 680)));
    this -> setPalette(deckManageBg);

    //For Groupboxes setting
    card1Choosing = new QGroupBox(tr("Card1"), this);
    card1Choosing -> setFont(QFont("Helvetica", 20));
    card1Choosing -> setGeometry(70, 80, 500, 160);

    C1knightA = new QRadioButton(tr("Launch A !"),this);
    C1archerA = new QRadioButton(tr("Launch B !"),this);
    C1punchA = new QRadioButton(tr("Launch C !"),this);
    C1bombA = new QRadioButton(tr("Launch D !"),this);

    C1knightA -> setChecked(true);

    C1knightA -> setFont(QFont("Helvetica", 14));
    C1archerA -> setFont(QFont("Helvetica", 14));
    C1punchA -> setFont(QFont("Helvetica", 14));
    C1bombA -> setFont(QFont("Helvetica", 14));

    layout1 = new QVBoxLayout;
    layout1 -> addWidget(C1knightA);
    layout1 -> addWidget(C1archerA);
    layout1 -> addWidget(C1punchA);
    layout1 -> addWidget(C1bombA);

    card1Choosing -> setLayout(layout1);

    card2Choosing = new QGroupBox(tr("Card2"), this);
    card2Choosing -> setFont(QFont("Helvetica", 20));
    card2Choosing -> setGeometry(70, 260, 500, 160);

    C2knightA = new QRadioButton(tr("Launch A !"),this);
    C2archerA = new QRadioButton(tr("Launch B !"),this);
    C2punchA = new QRadioButton(tr("Launch C !"),this);
    C2bombA = new QRadioButton(tr("Launch D !"),this);

    C2knightA -> setChecked(true);

    C2knightA -> setFont(QFont("Helvetica", 14));
    C2archerA -> setFont(QFont("Helvetica", 14));
    C2punchA -> setFont(QFont("Helvetica", 14));
    C2bombA -> setFont(QFont("Helvetica", 14));

    layout2 = new QVBoxLayout;
    layout2 -> addWidget(C2knightA);
    layout2 -> addWidget(C2archerA);
    layout2 -> addWidget(C2punchA);
    layout2 -> addWidget(C2bombA);

    card2Choosing -> setLayout(layout2);

    modeSel = new QGroupBox(tr("Mode"), this);
    modeSel -> setFont(QFont("Helvetica", 20));
    modeSel -> setGeometry(70, 440, 500, 160);

    mistySel = new QCheckBox(tr("Fog Mode"),this);
    //heroSel = new QCheckBox(tr("Hero Mode"),this);

    mistySel -> setFont(QFont("Helvetica", 14));
    //heroSel -> setFont(QFont("Helvetica", 14));

    layout3 = new QVBoxLayout;
    layout3 -> addWidget(mistySel);
    //layout3 -> addWidget(heroSel);

    modeSel -> setLayout(layout3);

    card1Choosing -> show();
    card2Choosing -> show();
    modeSel -> show();

    //For buttons
    btnGameStart = new QPushButton(tr("GO!"),this);
    btnGameStart -> setGeometry(1080 , 520, 150, 80);
    btnGameStart -> show();
    btnRandomDeck = new QPushButton(tr("Random!"), this);
    btnRandomDeck -> setGeometry(1300, 520, 150, 80);
    btnRandomDeck -> show();
    btnLastPage = new QPushButton(tr("last"), this);
    btnLastPage -> setGeometry(20, 10, 150, 60);
    btnLastPage ->show();

    //For label
    LminionInfo = new QLabel(this);
    LminionInfo -> setGeometry(650, 60, 800, 500);
    QPixmap Cha1(":/image/img/cha1.gif");
    LminionInfo -> setPixmap(Cha1.scaled(800, 500, Qt::KeepAspectRatio));
    LminionInfo -> show();

    connect(btnGameStart, SIGNAL(clicked()), this, SLOT(on_btnGameStart_clicked()));
    connect(btnRandomDeck, SIGNAL(clicked()), this, SLOT(on_btnRandomDeck_clicked()));
    connect(btnLastPage, SIGNAL(clicked()), this, SLOT(on_btnLastPage_clicked()));

    connect(C1knightA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C1archerA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C1punchA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C1bombA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C2knightA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C2archerA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C2punchA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
    connect(C2bombA, SIGNAL(clicked(bool)), this, SLOT(minionInfo_change()));
}
// click radiobuttons and change the Characters' Info
void Battle::minionInfo_change()
{
    QPixmap Cha1(":/image/img/cha1.gif");
    QPixmap Cha2(":/image/img/cha2.gif");
    QPixmap Cha3(":/image/img/cha3.gif");
    QPixmap Cha4(":/image/img/cha4.gif");
    if(sender() == C1knightA || sender() == C2knightA)
    {
        LminionInfo -> setPixmap(Cha1.scaled(800, 500, Qt::KeepAspectRatio));
    }
    else if(sender() == C1archerA || sender() == C2archerA)
    {
        LminionInfo -> setPixmap(Cha2.scaled(800, 500, Qt::KeepAspectRatio));
    }
    else if(sender() == C1punchA || sender() == C2punchA)
    {
        LminionInfo -> setPixmap(Cha3.scaled(800, 500, Qt::KeepAspectRatio));
    }
    else if(sender() == C1bombA || sender() == C2bombA)
    {
        LminionInfo -> setPixmap(Cha4.scaled(800, 500, Qt::KeepAspectRatio));
    }
   // LminionInfo -> show();
}

void Battle::on_btnGameStart_clicked()
{
    DeckCheck();
    card1Choosing -> hide();
    card2Choosing -> hide();
    modeSel -> hide();
    btnGameStart -> hide();
    btnRandomDeck -> hide();
    btnLastPage -> hide();
    LminionInfo -> hide();
    BattleIni();
}

void Battle::on_btnRandomDeck_clicked()
{
    card1Choosing -> hide();
    card2Choosing -> hide();
    modeSel -> hide();
    btnGameStart -> hide();
    btnRandomDeck -> hide();
    btnLastPage -> hide();
    LminionInfo -> hide();
    BattleIni();
}

void Battle::on_btnLastPage_clicked()
{
    card1Choosing -> hide();
    card2Choosing -> hide();
    modeSel -> hide();
    btnGameStart -> hide();
    btnRandomDeck -> hide();
    btnLastPage -> hide();
    LminionInfo -> hide();
    InfoIni();
}
// check which cards that are chosen
void Battle::DeckCheck()
{
    if(C1knightA -> isChecked())
        deck1 = 1;
    else if(C1archerA -> isChecked())
        deck1 = 2;
    else if(C1punchA -> isChecked())
        deck1 = 3;
    else if(C1bombA -> isChecked())
        deck1 = 4;

    if(C2knightA -> isChecked())
        deck2 = 1;
    else if(C2archerA -> isChecked())
        deck2 = 2;
    else if(C2punchA -> isChecked())
        deck2 = 3;
    else if(C2bombA -> isChecked())
        deck2 = 4;
}

/*Battle Page*/
void Battle::BattleIni()
{
    //For background changing
    QPalette deckBattleeBg;
    deckBattleeBg.setBrush(QPalette::Background, QBrush(QPixmap(":/image/img/back4.gif").scaled(1480, 680)));
    this -> setPalette(deckBattleeBg);
    //Initial buttons
    ButtonIni();
    //Setting game scene
    scene = new Scene(this);
    ui -> graphicsView -> setScene(scene);
    scene -> setSceneRect(10, 10 , 1460, 660);
    settingBg(10, 680);
    ui -> graphicsView -> show();
    //For countdown
    timeSecond = 180;
    timeLabel = new QLabel(this);
    timeLabel -> setGeometry(655, 25, 150, 60);
    timeLabel -> setAlignment(Qt::AlignCenter);
    timeLabel -> setFont(QFont("Helvetica", 20));
    timer = new QTimer(this);
    timer -> start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(this, SIGNAL(timeStop()), this, SLOT(timeOut()));
    timeLabel -> setText("Time : " + QString::number(timeSecond) + " s");
    timeLabel -> show();

    scene -> connect(timer, SIGNAL(timeout()), scene, SLOT(countdown()));

    //For score-counting
    score = 0;
    scoreLabel = new QLabel(this);
    scoreLabel -> setGeometry(655, 60, 150, 60);
    scoreLabel -> setAlignment(Qt::AlignCenter);
    scoreLabel -> setFont(QFont("Helvetica", 20));
    scoreLabel -> setText("Score : " + QString::number(score));
    scoreLabel -> show();

}

void Battle::ButtonIni()
{
    btnCard1 = new QPushButton(this);
    btnCard1 -> setGeometry(80, 540, 90, 120);
    if(deck1 == 1)
        btnCard1 -> setIcon(QIcon(":/image/img/minion1.gif"));
    else if(deck1 == 2)
        btnCard1 -> setIcon(QIcon(":/image/img/minion2.gif"));
    else if(deck1 == 3)
        btnCard1 -> setIcon(QIcon(":/image/img/minion3.gif"));
    else if(deck1 == 4)
        btnCard1 -> setIcon(QIcon(":/image/img/minion4.gif"));
    else if(deck1 == 5)
        btnCard1 -> setIcon(QIcon(":/image/img/minion5.gif"));
    else if(deck1 == 6)
        btnCard1 -> setIcon(QIcon(":/image/img/minion6.gif"));
    else if(deck1 == 7)
        btnCard1 -> setIcon(QIcon(":/image/img/minion7.gif"));
    else if(deck1 == 8)
        btnCard1 -> setIcon(QIcon(":/image/img/minion8.gif"));
    else
        btnCard1 -> setIcon(QIcon(":/image/img/icon.gif"));
    btnCard1 -> setIconSize(QSize(45,45));
    btnCard1 -> show();

    btnCard2 = new QPushButton(this);
    btnCard2 -> setGeometry(200, 540, 90, 120);
    if(deck2 == 1)
        btnCard2 -> setIcon(QIcon(":/image/img/minion1.gif"));
    else if(deck2 == 2)
        btnCard2 -> setIcon(QIcon(":/image/img/minion2.gif"));
    else if(deck2 == 3)
        btnCard2 -> setIcon(QIcon(":/image/img/minion3.gif"));
    else if(deck2 == 4)
        btnCard2 -> setIcon(QIcon(":/image/img/minion4.gif"));
    else if(deck1 == 5)
        btnCard1 -> setIcon(QIcon(":/image/img/minion5.gif"));
    else if(deck1 == 6)
        btnCard1 -> setIcon(QIcon(":/image/img/minion6.gif"));
    else if(deck1 == 7)
        btnCard1 -> setIcon(QIcon(":/image/img/minion7.gif"));
    else if(deck1 == 8)
        btnCard1 -> setIcon(QIcon(":/image/img/minion8.gif"));
    else
        btnCard2 -> setIcon(QIcon(":/image/img/icon.gif"));
    btnCard2 -> setIconSize(QSize(45,45));
    btnCard2 -> show();

    btnQuit = new QPushButton(tr("Quit"), this);
    btnQuit -> setGeometry(1380, 600, 60, 40);
    btnQuit -> show();

    btnHelper = new QPushButton(tr("Help"), this);
    btnHelper -> setGeometry(1380, 540, 60, 40);
    btnHelper -> show();

    connect(btnQuit, SIGNAL(clicked()), this, SLOT(on_btnQuit_clicked()));

    connect(btnHelper, SIGNAL(clicked()), this, SLOT(on_btnHelper_clicked()));

    connect(btnCard1, SIGNAL(clicked()), this, SLOT(on_btnCard1_clicked()));

    connect(btnCard2, SIGNAL(clicked()), this, SLOT(on_btnCard2_clicked()));
 }
//setting the bg of scene(for graphicsview)
void Battle::settingBg(int x, int y)
{
    QImage bg;
    bg.load(":/image/img/back.gif");
    bg = bg.scaled(1460, y);
    scene -> setBackgroundBrush(bg);
    scene -> gameIni(x);
}

void Battle::on_btnQuit_clicked()
{
    timer -> stop();
    emit quitPress();
}

void Battle::restart()
{
    btnCard1 -> hide();
    btnCard2 -> hide();
    btnQuit -> hide();
    timeLabel -> hide();
    scoreLabel -> hide();
    ui -> graphicsView -> hide();
    btnHelper -> hide();
    BeginIni();
}

void Battle::on_btnHelper_clicked()
{
    timer -> stop();
    emit helpPress();
}

void Battle::conti()
{
    timer -> start(1000);
}

//btns to launch minions
void Battle::on_btnCard1_clicked()
{
    scene -> minionLaunch(deck1);
}

void Battle::on_btnCard2_clicked()
{
    scene -> minionLaunch(deck2);
}
//countdown
void Battle::updateTime()
{
    if(timeSecond % 9 == 0)
            scene -> enemyLaunch();
    --timeSecond;
    timeLabel -> setText("Time : " + QString::number(timeSecond) + " s");

    if (timeSecond == 0)
      emit timeStop();
}
//if time out
void Battle::timeOut()
{
    timer -> stop();
    btnCard1 -> hide();
    btnCard2 -> hide();
    btnQuit -> hide();
    timeLabel -> hide();
    scoreLabel -> hide();
    btnHelper -> hide();
    ui -> graphicsView -> hide();
    if(score >= 700)
        WinIni();
    else
        LoseIni();
}
/*Result Page*/
void Battle::WinIni()
{
    //For background
    this -> setAutoFillBackground(true);
    QPalette winBg;
    winBg.setBrush(QPalette::Background, QBrush(QPixmap(":/image/img/win.gif").scaled(1480, 680)));
    this -> setPalette(winBg);
    //For button
    btnReplay = new QPushButton(tr("Restart !"), this);
    btnReplay -> setGeometry(590, 400, 300, 80);
    btnReplay -> show();
    btnExit = new QPushButton(tr("Exit"), this);
    btnExit -> setGeometry(590, 510, 300, 80);
    btnExit -> show();
    connect(btnReplay, SIGNAL(clicked()), this, SLOT(on_btnReplay_clicked()));
    connect(btnExit, SIGNAL(clicked()), this, SLOT(on_btnExit_clicked()));
    //For Label
    scoreResult = new QLabel(this);
    scoreResult -> setGeometry(655, 240, 150, 60);
    scoreResult -> setAlignment(Qt::AlignCenter);
    scoreResult -> setFont(QFont("Helvetica", 30));
    scoreResult -> setText("Score : " + QString::number(score));
    scoreResult -> show();

    usingTime = new QLabel(this);
    usingTime -> setGeometry(655, 320, 150, 60);
    usingTime -> setAlignment(Qt::AlignCenter);
    usingTime -> setFont(QFont("Helvetica", 30));
    usingTime -> setText("Using Time : " + QString::number(180 - timeSecond));
    usingTime -> show();
}

void Battle::LoseIni()
{
    //For background
    this -> setAutoFillBackground(true);
    QPalette loseBg;
    loseBg.setBrush(QPalette::Background, QBrush(QPixmap(":/image/img/lose.gif").scaled(1480, 680)));
    this -> setPalette(loseBg);
    //For button
    btnReplay = new QPushButton(tr("Restart !"), this);
    btnReplay -> setGeometry(590, 400, 300, 80);
    btnReplay -> show();
    btnExit = new QPushButton(tr("Exit"), this);
    btnExit -> setGeometry(590, 510, 300, 80);
    btnExit -> show();
    connect(btnReplay, SIGNAL(clicked()), this, SLOT(on_btnReplay_clicked()));
    connect(btnExit, SIGNAL(clicked()), this, SLOT(on_btnExit_clicked()));
    //For Label
    scoreResult = new QLabel(this);
    scoreResult -> setGeometry(580, 240, 300, 60);
    scoreResult -> setAlignment(Qt::AlignCenter);
    scoreResult -> setFont(QFont("Helvetica", 30));
    scoreResult -> setText("Score : " + QString::number(score));
    scoreResult -> show();

    usingTime = new QLabel(this);
    usingTime -> setGeometry(580, 320, 300, 60);
    usingTime -> setAlignment(Qt::AlignCenter);
    usingTime -> setFont(QFont("Helvetica", 30));
    usingTime -> setText("Using Time : " + QString::number(180 - timeSecond));
    usingTime -> show();
}

void Battle::on_btnReplay_clicked()
{
    btnReplay -> hide();
    btnExit -> hide();
    scoreResult -> hide();
    usingTime -> hide();

    BeginIni();
}

void Battle::on_btnExit_clicked()
{
    emit exit();
}
