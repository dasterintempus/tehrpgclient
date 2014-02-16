/********************************************************************************
** Form generated from reading UI file 'tehrpgclient.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TEHRPGCLIENT_FORM_H
#define TEHRPGCLIENT_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionConnect;
    QAction *actionAbout;
    QAction *actionDisconnect;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *outputPlainTextEdit;
    QWidget *inputContainerWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputLineEdit;
    QPushButton *enterButton;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 527));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        outputPlainTextEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        outputPlainTextEdit->setObjectName(QStringLiteral("outputPlainTextEdit"));
        outputPlainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(outputPlainTextEdit);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        inputContainerWidget = new QWidget(centralwidget);
        inputContainerWidget->setObjectName(QStringLiteral("inputContainerWidget"));
        horizontalLayout_2 = new QHBoxLayout(inputContainerWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        inputLineEdit = new QLineEdit(inputContainerWidget);
        inputLineEdit->setObjectName(QStringLiteral("inputLineEdit"));

        horizontalLayout_2->addWidget(inputLineEdit);

        enterButton = new QPushButton(inputContainerWidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        horizontalLayout_2->addWidget(enterButton);


        verticalLayout->addWidget(inputContainerWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionConnect);
        menuGame->addAction(actionDisconnect);
        menuGame->addSeparator();
        menuGame->addAction(actionQuit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "tehRPG", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        enterButton->setText(QApplication::translate("MainWindow", "Enter", 0));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TEHRPGCLIENT_FORM_H
