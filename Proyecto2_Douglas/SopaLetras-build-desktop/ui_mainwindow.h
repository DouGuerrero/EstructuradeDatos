/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 8. Jun 11:51:52 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QListWidget *listDiccionario;
    QListWidget *listResultado;
    QPushButton *botonResultado;
    QPushButton *botonDic;
    QPushButton *cargarMatriz;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(455, 530);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 421, 441));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 411, 411));
        tableWidget->horizontalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setDefaultSectionSize(17);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 216, 216);"));
        listDiccionario = new QListWidget(tab_2);
        listDiccionario->setObjectName(QString::fromUtf8("listDiccionario"));
        listDiccionario->setGeometry(QRect(10, 40, 171, 361));
        listDiccionario->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        listResultado = new QListWidget(tab_2);
        listResultado->setObjectName(QString::fromUtf8("listResultado"));
        listResultado->setGeometry(QRect(210, 40, 171, 361));
        listResultado->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        botonResultado = new QPushButton(tab_2);
        botonResultado->setObjectName(QString::fromUtf8("botonResultado"));
        botonResultado->setGeometry(QRect(300, 10, 75, 23));
        botonDic = new QPushButton(tab_2);
        botonDic->setObjectName(QString::fromUtf8("botonDic"));
        botonDic->setGeometry(QRect(80, 10, 91, 23));
        tabWidget->addTab(tab_2, QString());
        cargarMatriz = new QPushButton(centralWidget);
        cargarMatriz->setObjectName(QString::fromUtf8("cargarMatriz"));
        cargarMatriz->setGeometry(QRect(180, 20, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(340, 20, 41, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 0, 46, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(390, 20, 21, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(280, 20, 31, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        botonResultado->setText(QApplication::translate("MainWindow", "Ver Resultado", 0, QApplication::UnicodeUTF8));
        botonDic->setText(QApplication::translate("MainWindow", "Carga Diccionario", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        cargarMatriz->setText(QApplication::translate("MainWindow", "Cargar Matriz", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Tiempo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "ms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
