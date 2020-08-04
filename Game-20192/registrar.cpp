#include "registrar.h"
#include "ui_registrar.h"

Registrar::Registrar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registrar)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Harry Potter_Fondo_Registro.jpg"))); //Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Registrar::~Registrar()
{
    delete ui;
}

void Registrar::on_pushButton_clicked()
{
    //Declaracion de variables para manejo de archivos
    ofstream escritura;
    ifstream consulta;

    bool repetido=false;
    string Nombre, Contrasena;
    int Puntaje=0, Vidas=0,Nivel=0; //Se inicializa el Puntaje, Vidas y Nivel en '0' en el fichero
    /*-------------------------------------------------------------------------------------------------------------*/
    QString user=ui->Usuario->text(); //Texto que se ingreso en la line edit
    QString password=ui->Contrasena->text();//Texto que se ingreso en la line edit
    QString C_Password=ui->ConfirmarCon->text();//Texto que se ingreso en la line edit

     /*-------------------------------------------------------------------------------------------------------------*/
    if(password!=C_Password){//Si las contrasenas son diferentes

        //Para que aparezca mensaje en pantalla
        QMessageBox msgBox; //Se instancia la clase QMessage
        msgBox.setText("Las contraseñas ingresadas no coinciden"); //Se establece el texto que se quiere mostrar
        msgBox.exec(); //Para mostrar el mensaje
        exit(0);
    }
     /*-------------------------------------------------------------------------------------------------------------*/

    string jugador,Contra;

    //Se convierten los Qstring a String
    jugador=user.toStdString();
    Contra=password.toStdString();

    /*-------------------------------------------------------------------------------------------------------------*/
    /*Para el registro de los usuarios*/

    //Se abren los ficheros
    escritura.open("JUGADORES.txt",ios::out|ios::app);
    consulta.open("JUGADORES.txt",ios::in);

     if(escritura.is_open() && consulta.is_open()){ //Mientras los ficheros esten abiertos
         consulta>>Nombre; //Se consulta el Nombre de usuario

         while(!consulta.eof()){//Mientras la consulta no haya llegado a su fin

             if(Nombre==jugador){
                 /*---------------------------------------------------------*/
                 //Para que aparezca mensaje en pantalla
                 QMessageBox msgBox;  //Se instancia la clase QMessageBox
                 msgBox.setText("Ya Existe un Registro con este nombre"); //Se establece el texto que se quiere mostrar
                 msgBox.exec();//para mostrar
                 /*---------------------------------------------------------*/

                 repetido=true;

                 this->close();//Se cierra la ventana actual
             }

         consulta>>Nombre;

         }

         if(repetido==false){
             //Se pasa a imprimir los datos en el fichero de una manera organizada

             escritura<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<<Puntaje<<setw(7)<<setprecision(2)<<right<<Vidas<<setw(7)<<setprecision(2)<<right<<Nivel<<endl;

             QMessageBox msgBox; //Se instancia la clase QMessageBox
             msgBox.setText("Registro Exitoso");//Se establece el texto que se quiere mostrar
             msgBox.exec();//Se muestra el texto

             this->close();//para cerrar la ventana actual

         }
     }

     else{
         qDebug()<<"-Error, el Archivo No se Pudo Abrir o No ha sido Creado-"<<endl;
     }

    //Cerrando los archivos
     escritura.close();
     consulta.close();
}
