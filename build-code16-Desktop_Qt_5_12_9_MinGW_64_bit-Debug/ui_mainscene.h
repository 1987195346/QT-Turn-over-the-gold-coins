/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName(QString::fromUtf8("MainScene"));
        MainScene->resize(800, 600);
        actionquit = new QAction(MainScene);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(MainScene);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScene);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainScene->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QApplication::translate("MainScene", "MainScene", nullptr));
        actionquit->setText(QApplication::translate("MainScene", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("MainScene", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
