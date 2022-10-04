#include "battle.h"
#include "helper.h"
#include "quitornot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Battle w;
    Helper h;
    QuitOrNot q;
    w.resize(1480, 680);
    w.move(200, 100);
    w.setWindowTitle("Battle!");
    w.setWindowIcon(QIcon(":/image/img/icon.gif"));
    w.setFixedSize(1480, 680);
    w.show();

    h.resize(850, 700);
    h.move(515, 165);
    h.setWindowTitle("Helper");
    h.setWindowIcon(QIcon(":/image/img/icon.gif"));
    h.setFixedSize(850, 700);

    q.resize(200, 160);
    q.move(840, 380);
    q.setWindowTitle("Quit");
    q.setWindowIcon(QIcon(":/image/img/icon.gif"));
    q.setFixedSize(200, 160);

    QObject::connect(&w, SIGNAL(exit()), &a, SLOT(quit()));
    QObject::connect(&w, SIGNAL(helpPress()), &h, SLOT(showHelper()));
    QObject::connect(&h, SIGNAL(quitHelper()), &w, SLOT(conti()));
    QObject::connect(&w, SIGNAL(quitPress()), &q, SLOT(showQuit()));
    QObject::connect(&q, SIGNAL(quitOut()), &w, SLOT(conti()));
    QObject::connect(&q, SIGNAL(gameRe()), &w, SLOT(restart()));

    return a.exec();
}
