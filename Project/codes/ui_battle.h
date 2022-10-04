/********************************************************************************
** Form generated from reading UI file 'battle.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLE_H
#define UI_BATTLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Battle
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Battle)
    {
        if (Battle->objectName().isEmpty())
            Battle->setObjectName(QStringLiteral("Battle"));
        Battle->resize(400, 300);
        graphicsView = new QGraphicsView(Battle);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(0, 0, 1480, 680));
        graphicsView->setMouseTracking(false);

        retranslateUi(Battle);

        QMetaObject::connectSlotsByName(Battle);
    } // setupUi

    void retranslateUi(QWidget *Battle)
    {
        Battle->setWindowTitle(QApplication::translate("Battle", "Battle", 0));
#ifndef QT_NO_WHATSTHIS
        graphicsView->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class Battle: public Ui_Battle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLE_H