#include "registrar.h"
#include "ui_registrar.h"

Registrar::Registrar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registrar)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg")));
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Registrar::~Registrar()
{
    delete ui;
}

void Registrar::on_commandLinkButton_clicked()
{
    //Declaracion de variables
    ofstream escritura;
    ifstream consulta;
    bool repetido=false;
    string Nombre, Contrasena;
    int Puntaje=0;

    QString user=ui->Usuario->text();
    QString password=ui->Contrasena->text();
    QString C_Password=ui->ConfirmarCon->text();

    if(password!=C_Password){//Si las contrasenas son diferentes
        //Para que aparezca mensaje en pantalla
        QMessageBox msgBox;
        msgBox.setText("Las contraseñas ingresadas no coinciden");
        msgBox.exec();
        exit(0);
    }

    string jugador,Contra;

    //Se convierten los Qstring a String
    jugador=user.toStdString();
    Contra=password.toStdString();

    //Se abren los ficheros
    escritura.open("JUGADORES.txt",ios::out|ios::app);
    consulta.open("JUGADORES.txt",ios::in);

     if(escritura.is_open() && consulta.is_open()){ //Mientras los ficheros esten abiertos

         consulta>>Nombre; //Se consulta el Nombre de usuario

         while(!consulta.eof()){//Mientras la consulta no haya llegado a su fin
             consulta>>Contrasena;
             if(Nombre==jugador){

                 //Para que aparezca mensaje en pantalla
                 QMessageBox msgBox;
                 msgBox.setText("Ya Existe un Registro con este nombre");
                 msgBox.exec();
                 repetido=true;

                 this->close();

             }
         consulta>>Nombre;
         }

         if(repetido==false){
             //Se pasa a imprimir los datos en el fichero de una manera organizada

             escritura<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<<Puntaje<<endl;

             QMessageBox msgBox;
             msgBox.setText("Registro Exitoso");
             msgBox.exec();

             this->close();

         }
     }

     else{
         qDebug()<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
     }

    //Cerrando los archivos
     escritura.close();
     consulta.close();

}
