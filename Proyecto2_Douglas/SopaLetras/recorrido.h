#ifndef RECORRIDO_H
#define RECORRIDO_H
#include <QString>
#include <QList>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

class Recorrido
{
public:
    Recorrido();
    QList<QString> Horizontal(QString);
    void DiccionarioHash(int,QString);
    void Buscarpalabras(QString);
    QString alrevez(QString);
    void limpiarLista();


private:
    int variableMin;
    QList<QString> *hashset;
    QList<QString> encontradas;
};

#endif // RECORRIDO_H
