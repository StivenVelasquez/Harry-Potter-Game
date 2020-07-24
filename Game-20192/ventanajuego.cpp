#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include <QtDebug>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <nivel2.h>
#include "cargar_partidas.h"
#include "ventana_multijugador.h"
#include "modojuego.h"

extern Login *login; //Se usa clase externa
extern Spell *spell;//Se usa clase externa
extern Cargar_Partidas *Partidas; //Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern ModoJuego *modoJuego; //Se instancia la clase ModoJuego

Nivel2 *nivel;
Ventana_Multijugador *multijugador2;

VentanaJuego::VentanaJuego(QWidget *parent) :QMainWindow(parent),ui(new Ui::VentanaJuego)
{
    ui->setupUi(this);

    //Se crea la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,905,510);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/harry potter-fondo.jpg")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setScene(scene);//Se añade la escena
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    //------------------------------------------------------------------------------------------
    //Se crea el jugador 1
    personaje= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personaje);

    //make rect focusable
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->setPos(100,100);

//-----------------------------------------------------------------------------------
    //Personajes para la decoracion del escenario

    //se inicializan variables para Hermione
    x=y=0;
    i=0;
    rad=0.01745329252; //Radio para Hermione y Malfoi

    //==============================================

    //se inicializan variables para Malfoi
    x_=y_=0;

    //==============================================
    //se inicializan variables para el Carro Volador
    xc=yc=0;
    vo=30;

     XIzquierda=-700.351;
     XDerecha=0;
     YSuperior=-360;
     YInferior=0;

     b=0.05; //parámetro, rozamiento
     v0=60;  //velocidad de disparo
     u=v0/2; //velocidad del viento
     alfa=3.14159; //dirección //PI
     k=0;

    //==============================================

    //Se crean los personajes

    Hermione=new Personaje1_Decoracion;
    Malfoi= new Personaje2_Decoracion;
    CarroVolador=new Personaje3_Decoracion;

    time = new QTimer(this);

    scene->addItem(Hermione);//añade los circulos a la escena
    scene->addItem(Malfoi);
    scene->addItem(CarroVolador);

    Malfoi->setPos(400,200);//Asigna la posicion

    //Para movimiento de los personajes decoracion
    time->start(21);
    connect(time,SIGNAL(timeout()),this,SLOT(posicionPersonajeEscenario()));
    connect(this,SIGNAL(cambiar()),this,SLOT(posicionInvPersonajeEscenario()));

    //-------------------------------------------------------------------------

    //Generar enemigos
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
    timer->start(7000);


    //Multijugador=multijugador->Jugar;
    //---------------------------------------------------------------------

    if(modoJuego->Jugador==1){
   // qDebug()<<"Para Jugar "<<Partidas->Para_Jugar_Nivel_1<<endl;

    if(Partidas->Para_Jugar_Nivel_1==1){
    //Para la puntuación de los jugadores
    score = new Puntuacion(0);//Se crea la puntuacion
    scene->addItem(score);//Se añade a la escena
    score->setPos(score->x()+750,score->y());//posicion en la escena

    //---------------------------------------------------------------------

    //Para las vidas de los jugadores
    health=new Vidas_Jugador(3);//Se crean las vidas
    scene->addItem(health);//Se añade a la escena
    health->setPos(health->x()+650, health->y());//Posicion en la escena
    }

    if(Partidas->Para_Jugar_Nivel_1==2){
        //Para la puntuación de los jugadores
        score = new Puntuacion(Partidas->Puntaje_Jugador);//Se crea la puntuacion
        scene->addItem(score);//Se añade a la escena
        score->setPos(score->x()+750,score->y());//posicion en la escena

        //---------------------------------------------------------------------

        //Para las vidas de los jugadores
        health=new Vidas_Jugador(Partidas->Vidas_Jugador);//Se crean las vidas
        scene->addItem(health);//Se añade a la escena
        health->setPos(health->x()+650, health->y());//Posicion en la escena
    }
 }

    if(modoJuego->Jugador==2){

         if(multijugador->Multijugador==1){
        //Para la puntuación de los jugadores
        score = new Puntuacion(0);//Se crea la puntuacion
        scene->addItem(score);//Se añade a la escena
        score->setPos(score->x()+750,score->y());//posicion en la escena

        //---------------------------------------------------------------------

        //Para las vidas de los jugadores
        health=new Vidas_Jugador(3);//Se crean las vidas
        scene->addItem(health);//Se añade a la escena
        health->setPos(health->x()+650, health->y());//Posicion en la escena
    }

    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(500);

}

    //------------------------------------------------------------------------

    //Snitch Dorada
    snich=new Snitch_Dorada();
    scene->addItem(snich);//añade la snitch a la escena
    snich->setPos(100,200);//Asigna la posicion


    //Para Snitch
    timer = new QTimer();
    timer->start(40);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));


   //-------------------------------------------------------------------


    a=login->jugador;//Nombre del jugador actual

    Contador_Multijugador=1;

}


VentanaJuego::~VentanaJuego()
{
    delete ui;
    delete time;
}

void VentanaJuego::posicionPersonajeEscenario(void)
{
    int r=100;
    i+=rad;
    x=-1*r*cos(i*2);
    y=-1*r*sin(i*2);
    Hermione->setPos(x,y);//Cambia la posición de Hermione con x y y
    x_=r*pow(cos(i),3);
    y_=r*pow(sin(i),3);
    Malfoi->setPos(x_,y_);//Cambia la posición de Malfoi 2
    colliding();

    if(CarroVolador->pos().y() >YSuperior){ //Si llega hasta esta parte de la escena se movera con un movimiento parabolico
        xc=u*cos(alfa)*i+(v0*cos(60)-u*cos(alfa))*(1-exp(-b*i))/b;
        yc=(9.8/b+v0*sin(60)-u*sin(alfa))*(1-exp(-b*i))/b-(9.8/b-u*sin(alfa))*i;
        CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
    }



    /*
b=0.05; %parámetro, rozamiento
v0=60;  %velocidad de disparo
u=v0/2; %velocidad del viento
alfa=pi; %dirección
R=zeros(1,70);
i=0;
for angulo=(10:80)*pi/180;
    i=i+1;
    f=@(t) (9.8/b+v0*sin(angulo)-u*sin(alfa))*(1-exp(-b*t))
/b-(9.8/b-u*sin(alfa))*t;
    T0=2*v0*sin(angulo)/9.8; %tiempo de vuelo sin rozamiento
    t=fzero(f,T0); %tiempo de vuelo
    R(i)=u*cos(alfa)*t+(v0*cos(angulo)-u*cos(alfa))*(1-exp(-b*t))/b;
end
plot(10:80,R)
grid on
ylabel('Alcance (m)')
xlabel('\theta_0')
*/


//  if(CarroVolador->pos().y() >YSuperior){ //Si llega hasta esta parte de la escena se movera con un movimiento parabolico
//   xc=vo*cos(60)*i; //Posicion en 'x' del carro
//   yc=-vo*sin(60)*dt-0.5*(9.8)*i*i;//Posicion en 'y' del carro
//   CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
//  // qDebug()<<xc<<endl;
//  }

  if(CarroVolador->pos().x() > XIzquierda){//Mientras la posicion en x sea mayor a esto
  xc=CarroVolador->pos().x()-1; //Posicion en 'x' del carro
  yc=CarroVolador->pos().y();//Posicion en 'y' del carro
  CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena


     if(int(CarroVolador->pos().x()) ==int(XIzquierda)){
          while(CarroVolador->pos().x()<=0){
          xc=CarroVolador->pos().x()+20; //Posicion en 'x' del carro
          yc=CarroVolador->pos().y();//Posicion en 'y' del carro
          CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
          }
  }

  }


  /*if(CarroVolador->pos().x()<XDerecha){
     xc=CarroVolador->pos().x()+1; //Posicion en 'x' del carro
      yc=CarroVolador->pos().y();//Posicion en 'y' del carro
      CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
  }*/

          }
      //CarroVolador->setPos(xc,yc);//Se añaden las posiciones en la escena
      // qDebug()<<xc<<endl;




void VentanaJuego::colliding(void)
{
    collide=Hermione->collidesWithItem(Malfoi);
    if(collide==true){
       emit cambiarDireccion();
    }
}

void VentanaJuego::posicionInvPersonajeEscenario()
{

    rad=-1*rad;

}


void VentanaJuego::on_pushButton_2_clicked()
{
    ofstream aux;
    ifstream lectura;
    bool encontrado_=false;
    string jugador,auxJugador, NombreJugador, Contra;
    int Puntaje, Nivel, Vidas;

    aux.open("auxiliar.txt",ios::out|ios::app);
    lectura.open("JUGADORES.txt",ios::in);

    if(lectura.is_open() && aux.is_open()){
      lectura>>jugador;
       while(!lectura.eof()){
           lectura>>Contra>>Puntaje>>Vidas>>Nivel;
           if(jugador==a){
               encontrado_=true;

              aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<< score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< health->getVidas_Jugador()<<setw(7)<<setprecision(2)<<right<<1<<endl;

           }

           else{

               aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<<Puntaje<<endl<<setw(7)<<setprecision(2)<<right<<Vidas<<setw(7)<<setprecision(2)<<right<<Nivel<<endl;

           }
            lectura>>jugador;
     }

    }

    else

   qDebug()<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;




     lectura.close();
     aux.close();

     remove("JUGADORES.txt");
     rename("auxiliar.txt","JUGADORES.txt");

}

void VentanaJuego::on_pushButton_clicked()
{

    nivel= new Nivel2();
    nivel->show();
}

void VentanaJuego::funcionActivacionTimer(){
    ui->lcdNumber->display(contador);
    contador++;
    if(contador==40){
        if(multijugador->Jugar==1) multijugador->Jugar=2;
        else multijugador->Jugar=1;

        ofstream escritura;
        escritura.open("MULTIJUGADOR.txt",ios::out|ios::app);

        if(escritura.is_open()){

                  escritura<<left<<setw(10)<<multijugador->Jugar<<setw(13)<< score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< health->getVidas_Jugador()<<endl;

               }

        escritura.close();

        multijugador->Contador_Multijugador=multijugador->Contador_Multijugador+1;

        qDebug()<<"CONTADOR "<<multijugador->Contador_Multijugador<<endl;

        multijugador2=new Ventana_Multijugador();
        multijugador2->show();
        this->close();

        if(multijugador->Contador_Multijugador>1){

            //Declaracion de variables para manejo de archivos
            ifstream lectura;
            bool encontrado_=false;
            string auxNombre;
            int aux_Puntaje,aux_Vidas;
            int Puntaje1,Vidas1;


          lectura.open("MULTIJUGADOR.txt",ios::in);//Se abre el fichero

            if(lectura.is_open() ){//Si el fichero esta abierto
                   lectura>>auxNombre;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingreso
               while(!lectura.eof()){//Mientras el fichero no llegue a su fin
                   lectura>>aux_Puntaje>>aux_Vidas;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingreso
                   if(auxNombre=="1"){ //En caso de que se encuente
                       encontrado_=true;

                       Puntaje1=aux_Puntaje;
                       Vidas1=aux_Vidas;

                       this->close();//Se cierra la ventana de login
                   }
                   lectura>>auxNombre; //Ciclo para que recorra todas las lineas tratando de buscar el nombre del jugador que se ingreso
             }
            }

             if(encontrado_==false){

                 //Para que aparezca mensaje en pantalla
                 QMessageBox msgBox;
                 msgBox.setText("PLAYER 1 NO JUGÓ, ASÍ QUE NO SE PUEDE DEFINIR GANADOR");
                 msgBox.exec();

                     }
             lectura.close(); //Se cierra el fichero


            //Para Player 2

             int Puntaje2;
             int Vidas2;


             lectura.open("MULTIJUGADOR.txt",ios::in);//Se abre el fichero

               if(lectura.is_open() ){//Si el fichero esta abierto
                      lectura>>auxNombre;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingreso
                  while(!lectura.eof()){//Mientras el fichero no llegue a su fin
                      lectura>>aux_Puntaje>>aux_Vidas;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingreso
                      if(auxNombre=="2"){ //En caso de que se encuente
                          encontrado_=true;

                          Puntaje2=aux_Puntaje;
                          Vidas2=aux_Vidas;

                          this->close();//Se cierra la ventana de login
                      }
                      lectura>>auxNombre; //Ciclo para que recorra todas las lineas tratando de buscar el nombre del jugador que se ingreso
                }
               }

                if(encontrado_==false){

                    //Para que aparezca mensaje en pantalla
                    QMessageBox msgBox;
                    msgBox.setText("PLAYER 2 NO JUGÓ, ASÍ QUE NO SE PUEDE DEFINIR GANADOR");
                    msgBox.exec();

                        }
                lectura.close(); //Se cierra el fichero


             //Para definir ganador

                if(Vidas1 > Vidas2){
                    QMessageBox msgBox;
                    msgBox.setText("EL GANADOR ES EL PLAYER 1");
                    msgBox.exec();
                }

                if(Vidas2 > Vidas1){
                    QMessageBox msgBox;
                    msgBox.setText("EL GANADOR ES EL PLAYER 2");
                    msgBox.exec();
                }

                if(Vidas1 == Vidas2){

                    if(Puntaje1>Puntaje2){
                    QMessageBox msgBox;
                    msgBox.setText("EL GANADOR ES EL PLAYER 1");
                    msgBox.exec();
                    }

                    if(Puntaje1<Puntaje2){
                    QMessageBox msgBox;
                    msgBox.setText("EL GANADOR ES EL PLAYER 2");
                    msgBox.exec();
                    }
                }



            remove("MULTIJUGADOR.txt");
        }


//        multijugador2=new Ventana_Multijugador();
//        multijugador2->show();
//        this->close();

    }


    }






