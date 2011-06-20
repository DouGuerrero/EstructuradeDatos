#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qt>
#include "QBitArray"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //aca se establece el menor tamano de palabra a busca
    this->valorMin=2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cargarMatriz_clicked()
{
    //se pide cargar un archivo que contenga la sopa de letras
    //se va insertando las filas y columnas dependiendo del tamaño de la sopa de letras
    //se recorre toda la matriz y en la posicion asignada se va insertando la letra

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
    QString line;

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    line=stream.readLine().trimmed().toLower();

    for(int a=0;a<line.count();a++)
    {
        ui->tableWidget->insertRow(a);
        ui->tableWidget->insertColumn(a);
    }

    for(int i=0;i<line.count();i++)
    {

       for(int j=0;j<line.count();j++)
       {
            QTableWidgetItem *item= new QTableWidgetItem(line.at(j));
            ui->tableWidget->setItem(i,j,item);
            ui->tableWidget->item(i,j)->setTextAlignment(1);

       }
           line=stream.readLine().trimmed().toLower();
   }

}

void MainWindow::on_botonDic_clicked()
{
    //se pide un archivo que contenga palabras de un diccionario
    //todas estas palabras se meten a una lista
    QString fileName=  QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.*)"));
    QString line;
    QStringList limpiarduplicados;
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int cont=0;

    while(!stream.atEnd())
    {
       line=stream.readLine().trimmed().toLower();
       limpiarduplicados.append(line);
       cont++;
    }
    limpiarduplicados.removeDuplicates();

    for(int i=0;i<limpiarduplicados.count();i++)
    {
    line=limpiarduplicados.at(i);
    ui->listDiccionario->insertItem(cont,line);
    }
}

void MainWindow::on_botonResultado_clicked()
{
    //se crea la variable para contar tiempo, llamo a la funcion finder y finderDiagonal
    //al final se inserta en una lista los resultados finales de palabras encontradas
    QString tiempo;
    clock_t init, final;
    ui->listResultado->clear();
    this->verificar.clear();

    init=clock();

    finder();
    //finderDiagonal();

    final=clock()-init;
    tiempo.setNum((double)final);

    ui->lineEdit->setText(tiempo);

    for(int i=0;i<verificar.count();i++)
    {
        ui->listResultado->insertItem(i,verificar.at(i));        
    }

    tiempo.setNum(ui->listResultado->count());
    ui->lineEdit_2->setText(tiempo);
}

void MainWindow::finder()
{
    //basicamente se recorre linea por linea y cada linea se compara con todas las palabras del diccionario
    //las comparamos al usar la funcion de qstring contains que busca si esa palabra esta en dicha linea
    //por cada palabra del diccionario se comparan 4 lineas, horizontal, vertical y sus reversas.

    QString lineaHorizontal;
    QString lineaVertical;
    QString HorizontalAlrevez;
    QString verticalAlrevez;
    QString palabra;
    QString lineaDiagonal1;
    QString lineaDiagonal2;
    QString lineaDiagonal3;
    QString lineaDiagonal4;
    QString lineaAlrevez1;
    QString lineaAlrevez2;
    QString lineaAlrevez3;
    QString lineaAlrevez4;
    int cont=0;

    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        for(int e=0;e<ui->tableWidget->columnCount();e++)
        {
            lineaHorizontal.push_back(ui->tableWidget->item(i,e)->text());
            lineaVertical.push_back(ui->tableWidget->item(e,i)->text());
        }
        lineaHorizontal.push_back(" ");
        lineaVertical.push_back(" ");
    }

    for(int i=0;i<ui->tableWidget->rowCount()-this->valorMin+1;i++)
    {
        for(int e=0;e<ui->tableWidget->columnCount()-i;e++)
        {
            lineaDiagonal1.push_back(ui->tableWidget->item(e+i,e)->text());
            lineaDiagonal2.push_back(ui->tableWidget->item(e,e+i)->text());
        }
        lineaDiagonal1.push_back(" ");
        lineaDiagonal2.push_back(" ");
    }


    for(int a=0;a<ui->tableWidget->rowCount()-this->valorMin+1;a++)
    {
        for(int u=ui->tableWidget->columnCount()-a-1;u>=0;u--)
        {
            lineaDiagonal3.push_back(ui->tableWidget->item(u+a,ui->tableWidget->rowCount()-1-u)->text());
            lineaDiagonal4.push_back(ui->tableWidget->item(u,cont)->text());
            cont++;
        }
        cont=0;
        lineaDiagonal3.push_back(" ");
        lineaDiagonal4.push_back(" ");
    }

        HorizontalAlrevez=alrevez(lineaHorizontal);
        verticalAlrevez=alrevez(lineaVertical);
        lineaAlrevez1=alrevez(lineaDiagonal1);
        lineaAlrevez2=alrevez(lineaDiagonal2);
        lineaAlrevez3=alrevez(lineaDiagonal3);
        lineaAlrevez4=alrevez(lineaDiagonal4);

        for(int t=0;t<ui->listDiccionario->count();t++)
        {
            palabra=ui->listDiccionario->item(t)->text();

            if(palabra.length()>this->valorMin)
            {

                if(lineaHorizontal.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(HorizontalAlrevez.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaVertical.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(verticalAlrevez.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaDiagonal1.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaAlrevez1.contains(palabra))
                {

                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaDiagonal2.contains(palabra))
                {
                    if(t<0)
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaAlrevez2.contains(palabra))
                {
                    if(t<0)
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaDiagonal3.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaAlrevez3.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaDiagonal4.contains(palabra))
                {
                    //if(t<0)
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                if(lineaAlrevez4.contains(palabra))
                {
                    //if(t<0)
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }

                /*if(lineaHorizontal.contains(palabra)||HorizontalAlrevez.contains(palabra)||
                   lineaVertical.contains(palabra)||verticalAlrevez.contains(palabra)||lineaDiagonal1.contains(palabra)||
                   lineaAlrevez1.contains(palabra)||lineaDiagonal2.contains(palabra)||lineaAlrevez2.contains(palabra)||
                   lineaDiagonal3.contains(palabra)||lineaAlrevez3.contains(palabra)||lineaDiagonal4.contains(palabra)||
                   lineaAlrevez4.contains(palabra))
                {
                    verificar.push_back(ui->listDiccionario->item(t)->text());
                }*/

            }
        }
}

void MainWindow::finderDiagonal()
{
    //aca hace lo mismo que la funcion anterior pero solo los for cambian, para poder buscar diagonal
    /*
    QString lineaDiagonal1;
    QString lineaDiagonal2;
    QString lineaDiagonal3;
    QString lineaDiagonal4;
    QString lineaAlrevez1;
    QString lineaAlrevez2;
    QString lineaAlrevez3;
    QString lineaAlrevez4;
    QString palabra;
    int cont=0;

    for(int i=0;i<ui->tableWidget->rowCount()-this->valorMin+1;i++)
    {
        for(int e=0;e<ui->tableWidget->columnCount()-i;e++)
        {
            lineaDiagonal1.push_back(ui->tableWidget->item(e+i,e)->text());
            lineaDiagonal2.push_back(ui->tableWidget->item(e,e+i)->text());
        }
        lineaDiagonal1.push_back(" ");
        lineaDiagonal2.push_back(" ");
    }


    for(int a=0;a<ui->tableWidget->rowCount()-this->valorMin+1;a++)
    {
        for(int u=ui->tableWidget->columnCount()-a-1;u>=0;u--)
        {
            lineaDiagonal3.push_back(ui->tableWidget->item(u+a,ui->tableWidget->rowCount()-1-u)->text());
            lineaDiagonal4.push_back(ui->tableWidget->item(u,cont)->text());
            cont++;
        }
        cont=0;
        lineaDiagonal3.push_back(" ");
        lineaDiagonal4.push_back(" ");
    }


    lineaAlrevez1=alrevez(lineaDiagonal1);
    lineaAlrevez2=alrevez(lineaDiagonal2);
    lineaAlrevez3=alrevez(lineaDiagonal3);
    lineaAlrevez4=alrevez(lineaDiagonal4);

    for(int t=0;t<ui->listDiccionario->count();t++)
    {
        palabra=ui->listDiccionario->item(t)->text();

        if(palabra.length()>this->valorMin)
        {
            if(lineaDiagonal1.contains(palabra)||lineaAlrevez1.contains(palabra)||lineaDiagonal2.contains(palabra)||lineaAlrevez2.contains(palabra)||
                lineaDiagonal3.contains(palabra)||lineaAlrevez3.contains(palabra)||lineaDiagonal4.contains(palabra)||lineaAlrevez4.contains(palabra))
            {
                verificar.push_back(ui->listDiccionario->item(t)->text());
            }
        }
    }

    lineaDiagonal1="";
    lineaDiagonal2="";
    lineaDiagonal3="";
    lineaDiagonal4="";*/
}

QString MainWindow::alrevez(QString verificar)
{
   QString alrevez;
   for(int i=verificar.count();i>0;i--)
   {
      alrevez.append(verificar.at(i-1));
   }
   return alrevez;
}
