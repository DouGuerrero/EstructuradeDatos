#include "recorrido.h"

Recorrido::Recorrido()
{
    this->variableMin=5;
    this->hashset=new QList<QString>[30];
}

void Recorrido::DiccionarioHash(int letra,QString line)
{
       this->hashset[letra].append(line);

}

QList<QString> Recorrido::Horizontal(QString linea)
{
    QString verificar;
    int algor;
    int varMin=this->variableMin;

    for(int i=0;i<=linea.length()-this->variableMin;i++)
    {
        algor=varMin-1;

        for(int e=0;e<linea.length()-algor;e++)
        {
            verificar=linea.mid(e,varMin);
            Buscarpalabras(verificar);

            verificar=alrevez(verificar);
            Buscarpalabras(verificar);

        }
        varMin++;
    }

    return this->encontradas;
}

void Recorrido::Buscarpalabras(QString verificar)
{
    int letra;

    letra=verificar.at(0).toAscii()-97;

    for(int i=0;i<this->hashset[letra].count();i++)
    {
        if(verificar==hashset[letra].at(i))
        {
            this->encontradas.append(verificar);
            return;
        }
    }
}

QString Recorrido::alrevez(QString verificar)
{
   QString alrevez;
   for(int i=verificar.count();i>0;i--)
   {
      alrevez.append(verificar.at(i-1));
   }
   return alrevez;
}

void Recorrido::limpiarLista()
{
    this->encontradas.clear();
}
