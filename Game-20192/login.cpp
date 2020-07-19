#include "login.h"
#include "ui_login.h"

//extern Inicio *inicio;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//Se crea la escena del juego
    scene->setSceneRect(0,0,730,548);//Se delimita la escena
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/FondoInicio.jpg")));
    ui->graphicsView->setScene(scene); //Se muestra en el view
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra Horizontal
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Para quitar barra vertical
}

Login::~Login()
{
    delete ui;
}

void Login::on_commandLinkButton_clicked()
{
    QString user=ui->Usuario->text();
    QString password=ui->Contrasena->text();

   //Se convierten de qstring a string
    jugador=user.toStdString();
    Contra=password.toStdString();


    //Declaracion de variables
    ifstream lectura;
    ofstream escritura;
    bool encontrado_=false;
    string auxNombre;

  lectura.open("JUGADORES.txt",ios::in);

    if(lectura.is_open() ){

       while(!lectura.eof()){
           lectura>>auxNombre;
           if(auxNombre==jugador){
               encontrado_=true;

               lectura.close();

               //Se muestra la ventana del modo de juego
               ModoJuego *modoJuego = new ModoJuego(0);
               modoJuego->show();


               //inicio->close();
               this->close();
           }
           lectura>>auxNombre;
     }
    }

    else
     {
              qDebug()<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;

             }

     if(encontrado_==false){

         //Para que aparezca mensaje en pantalla
         QMessageBox msgBox;
         msgBox.setText("No Existe ningún Registro con este Usuario, por favor Registrese");
         msgBox.exec();

             }
     lectura.close();
}
