#ifndef BATTLE_H
#define BATTLE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QGraphicsScene>
#include <QTimer>
#include "scene.h"
#include "helper.h"

namespace Ui {
class Battle;
}

class Battle : public QWidget
{
    Q_OBJECT

public:
    explicit Battle(QWidget *parent = 0);
    ~Battle();

    Scene *scene;
    QGraphicsView *view;
    void settingBg(int x, int y);

private:
    Ui::Battle *ui;
//Beginning page
    QPushButton *btnStart;
//Information page
    QPushButton *btnNextPage;
//Deck-managing page
    QPushButton *btnLastPage;
    QPushButton *btnGameStart;
    QPushButton *btnRandomDeck;
    //For checkboxes: deck choosing
    QVBoxLayout *layout1;
    QGroupBox *card1Choosing;
    QRadioButton *C1knightA;
    QRadioButton *C1archerA;
    QRadioButton *C1punchA;
    QRadioButton *C1bombA;

    QVBoxLayout *layout2;
    QGroupBox *card2Choosing;
    QRadioButton *C2knightA;
    QRadioButton *C2archerA;
    QRadioButton *C2punchA;
    QRadioButton *C2bombA;

    QVBoxLayout *layout3;
    QGroupBox *modeSel;
    QCheckBox *mistySel;
    //QCheckBox *heroSel;
    //For introduction image: minions and how to play
    QLabel *LminionInfo;
    //For functions
    void DeckIni();
    void InfoIni();
    void DeckCheck();
    void BattleIni();
    //For variables:deck
    int deck1;
    int deck2;
//battle page
    //For buttons
    QPushButton *btnCard1;
    QPushButton *btnCard2;
    QPushButton *btnQuit;
    QPushButton *btnHelper;
    //For functions
    void BeginIni();
    void ButtonIni();
    //For timer
    QTimer *timer;
    QLabel *timeLabel;
    int timeSecond;
    //For score
    QLabel *scoreLabel;
    int score;
//For result page
    void WinIni();
    void LoseIni();
    QPushButton *btnReplay;
    QPushButton *btnExit;
    QLabel *scoreResult;
    QLabel *usingTime;
signals:
    void timeStop();
    void exit();
    void helpPress();
    void quitPress();

private slots:
    void on_btnStart_clicked();//click btnStart to go to next page: dack management
    void on_btnGameStart_clicked();//click btnGameStart to go to next page: battle
    void on_btnRandomDeck_clicked();//click btnRandomDeck to get a pair of deck randomly and start game
    void on_btnNextPage_clicked();//click btnNextPage to go to deckMa page from Info
    void on_btnLastPage_clicked();//clicl btnLastPage to back to Info page from deckMa
    void minionInfo_change();//change the pixmap of label.LminionInfo(info of minions)
    void on_btnQuit_clicked();//click btnQuit to quit the game and restart from begin page
    void on_btnCard1_clicked();//click btnCard1 to launch minion of card1
    void on_btnCard2_clicked();//click btnCard2 to launch minion of card2
    void updateTime();
    void timeOut();
    void on_btnReplay_clicked();
    void on_btnExit_clicked();
    void on_btnHelper_clicked();
    void conti();
    void restart();
};

#endif // BATTLE_H
