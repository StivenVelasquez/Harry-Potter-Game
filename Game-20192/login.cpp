#include "login.h"
#include "ui_login.h"

extern Inicio *inicio; //Se usa clase externa
ModoJuego *modoJuego; //Se instancia la clase ModoJuego

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/Harry_Potter-Fondo_Login.jpg")));//Fondo
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString user=ui->Usuario->text(); //Usuario ingresado en la linea de escritura
    QString password=ui->Contrasena->text();//Contraseña ingresada en la linea de escritura

   //Se convierten de qstring a string
    jugador=user.toStdString();
    Contra=password.toStdString();

    //Declaracion de variable para manejo de archivos
    ifstream lectura;

    bool encontrado_=false;
    string auxNombre;

  lectura.open("JUGADORES.txt",ios::in);//Se abre el fichero

    if(lectura.is_open() ){//Si el fichero esta abierto

      lectura>>auxNombre;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingresó
       while(!lectura.eof()){//Mientras el fichero no llegue a su fin         
           if(auxNombre==jugador){ //En caso de que se encuentre
               encontrado_=true;
               lectura.close(); //Se cierra el archivo

               //Se crea y muestra la ventana del modo de juego
               modoJuego = new ModoJuego();
               modoJuego->show();

               inicio->close(); //Se cierra la ventana de inicio
               this->close();//Se cierra la ventana de login
           }

            lectura>>auxNombre;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingresó
       }
    }

    else
     {
        qDebug()<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl; //Si no se puedo abrir el fichero
     }

     if(encontrado_==false){
         //Para que aparezca mensaje en pantalla
         QMessageBox msgBox;
         msgBox.setText("No Existe ningún Registro con este Usuario, por favor Registrese");
         msgBox.exec();
      }

lectura.close(); //Se cierra el fichero
}
