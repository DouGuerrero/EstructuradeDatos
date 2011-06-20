#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMainWindow>
#include <QList>
#include <time.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //finder busca las palabras horizontalmente y verticalmente
    void finder();
    //finderDiagonal busca las palabras diagonalmente
    void finderDiagonal();
    //esta funcion le da vuelta a las palabras
    QString alrevez(QString);

private:
    Ui::MainWindow *ui;
    //aca meto las palabras encontradas
    QList<QString> verificar;
    //valor minimo de letras a buscar
    int valorMin;

private slots:
    void on_botonResultado_clicked();
    void on_botonDic_clicked();
    void on_cargarMatriz_clicked();
};

#endif // MAINWINDOW_H
