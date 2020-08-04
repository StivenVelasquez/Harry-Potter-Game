#include <QMediaPlayer>
#include <QDebug>

#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include "nivel2.h"
#include "cargar_partidas.h"
#include "ventana_multijugador.h"
#include "modojuego.h"
#include "player1_ganador.h"
#include "player2_ganador.h"

extern Login *login; //Se usa clase externa
extern Spell *spell;//Se usa clase externa
extern Cargar_Partidas *Partidas; //Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern ModoJuego *modoJuego; //Se instancia la clase ModoJuego

//Se instancian objetos
Nivel2 *nivel;
Ventana_Multijugador *multijugador2;
QMediaPlayer *Nivel1Sound; //Se instancia un objeto tipo QMediaPlayer
Player1_Ganador *Ganador1;
Player2_Ganador *Ganador2;

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

    ui->pushButton->hide();

    //------------------------------------------------------------------------------------------

    //Snitch Dorada
    snich=new Snitch_Dorada(); //Se crea snitch
    scene->addItem(snich);//añade la snitch a la escena

    //-------------------------------------------------------------------------------------------

    Nombre_Jugador=login->jugador;//Nombre del jugador que esta jugando
    //modoJuego->Contador_Multijugador=1;

    //-------------------------------------------------------------------------------------------

    //Se crea el jugador
    personaje= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personaje);

    personaje->setPos(100,100); //Posicion en la escena

    //Para poder manejar el personaje con el teclado en la escena
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();

    //------------------------------------------------------------------------------------------
    //Fantasma

    fantasma=new ghost();
    scene->addItem(fantasma);
    fantasma->setPos(700,700);

    //-----------------------------------------------------------------------------------------
    Amiga=new Hermione();
    scene->addItem(Amiga);//añade los circulos a la escena

    Amigo=new malfoi();
    scene->addItem(Amigo);//añade los circulos a la escena

    time = new QTimer();
    time->start(95);
    connect(time,SIGNAL(timeout()),scene,SLOT(advance()));

    //-------------------------------------------------------------------------------------------

    if(modoJuego->Jugador==1){ // Para trabajar con partidas

        ui->lcdNumber->hide(); //Se esconde la pantalla lcd

            if(Partidas->Para_Jugar_Nivel_1==1){ //Para trabajar con Inicio de partidas desde cero

                //Para musica de Juego
                 Nivel1Sound=new QMediaPlayer();
                 Nivel1Sound->setMedia(QUrl("qrc:/Musica/The Dementors Converge.mp3"));
                 Nivel1Sound->setVolume(50);

                 if(Nivel1Sound->state()==QMediaPlayer::PlayingState){
                     Nivel1Sound->setPosition(0);
                 }else if(Nivel1Sound->state()==QMediaPlayer::StoppedState){
                     Nivel1Sound->play();
                 }

                //Para la puntuación de los jugadores
                score = new Puntuacion(0);//Se crea la puntuacion
                scene->addItem(score);//Se añade a la escena
                score->setPos(score->x()+750,score->y());//posicion en la escena

                //------------------------------------------------------------------------------------

                //Para las vidas de los jugadores
                health=new Vidas_Jugador(6);//Se crean las vidas
                scene->addItem(health);//Se añade a la escena
                health->setPos(health->x()+650, health->y());//Posicion en la escena

                //Generar enemigos
                timer = new QTimer();
                QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
                timer->start(1000);

            }

            if(Partidas->Para_Jugar_Nivel_1==2){ //Cuando se trabaja con partidas cargadas

                //Para musica de Juego
                 Nivel1Sound=new QMediaPlayer();
                 Nivel1Sound->setMedia(QUrl("qrc:/Musica/The Dementors Converge.mp3"));
                 Nivel1Sound->setVolume(50);

                 if(Nivel1Sound->state()==QMediaPlayer::PlayingState){
                     Nivel1Sound->setPosition(0);
                 }else if(Nivel1Sound->state()==QMediaPlayer::StoppedState){
                     Nivel1Sound->play();
                 }


                //Para la puntuación de los jugadores
                score = new Puntuacion(Partidas->Puntaje_Jugador);//Se crea la puntuacion
                scene->addItem(score);//Se añade a la escena
                score->setPos(score->x()+750,score->y());//posicion en la escena

                //---------------------------------------------------------------------

                //Para las vidas de los jugadores
                health=new Vidas_Jugador(Partidas->Vidas_Jugador);//Se crean las vidas
                scene->addItem(health);//Se añade a la escena
                health->setPos(health->x()+650, health->y());//Posicion en la escena


                //Generar enemigos
                timer = new QTimer();
                QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
                timer->start(1000);
            }
    }

    if(modoJuego->Jugador==2){ //Para trabajar con multijugador

        ui->pushButton_2->hide(); //Se esconde boton de guardar partidas
        ui->pushButton->hide();//Se esconde boton de segundo nivel

        //Para musica de Juego
         Nivel1Sound=new QMediaPlayer();
         Nivel1Sound->setMedia(QUrl("qrc:/Musica/2 Snape to Malfoy Manor - Harry Potter and the Deathly Hallows soundtrack.mp3"));

         if(Nivel1Sound->state()==QMediaPlayer::PlayingState){
             Nivel1Sound->setPosition(0);
         }else if(Nivel1Sound->state()==QMediaPlayer::StoppedState){
             Nivel1Sound->play();
         }

         if(multijugador->Multijugador==1){ //Para player 1

            //Para la puntuación de los jugadores
            score = new Puntuacion(0);//Se crea la puntuacion
            scene->addItem(score);//Se añade a la escena
            score->setPos(score->x()+750,score->y());//posicion en la escena

            //---------------------------------------------------------------------

            //Para las vidas de los jugadores
            health=new Vidas_Jugador(6);//Se crean las vidas
            scene->addItem(health);//Se añade a la escena
            health->setPos(health->x()+650, health->y());//Posicion en la escena

            //---------------------------------------------------------------------

            //Generar enemigos
            timer = new QTimer();
            QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
            //Se generan los enemigos mas rapido que en el caso de las partidas
            timer->start(1000);
        }

        //Para funcionamiento de cronometro cuando de juega en modo Multijugador
        QTimer *cronometro=new QTimer(this);
        connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
        cronometro->start(500);

    }

    //----------------------------------------------------------------------------------

}

VentanaJuego::~VentanaJuego()
{
    delete ui;
    delete time;
}

void VentanaJuego::on_pushButton_2_clicked()
{
    // Variables para trabajar con ficheros
    ofstream aux;
    ifstream lectura;
    string jugador,Contra;
    int Puntaje, Nivel, Vidas;

    aux.open("auxiliar.txt",ios::out|ios::app); //Se abre fichero
    lectura.open("JUGADORES.txt",ios::in);//Se abre fichero

    if(lectura.is_open() && aux.is_open()){//Si estan abiertos
      lectura>>jugador;
       while(!lectura.eof()){//Mientras no haya llegado a su fin
           lectura>>Contra>>Puntaje>>Vidas>>Nivel;
           if(jugador==Nombre_Jugador){ //Si se encuentra el jugador

               //Se escribe en el archivo
              aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<< score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< health->getVidas_Jugador()<<setw(7)<<setprecision(2)<<right<<1<<endl;

           }

           else

           {

               aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<<Puntaje<<endl<<setw(7)<<setprecision(2)<<right<<Vidas<<setw(7)<<setprecision(2)<<right<<Nivel<<endl;

           }
           lectura>>jugador;//Para buscar jugador
     }

    }

    else qDebug()<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;

    //Se cierran los archivos
 lectura.close();
 aux.close();

 remove("JUGADORES.txt");//Se elimina
 rename("auxiliar.txt","JUGADORES.txt");//Se renombra

}

void VentanaJuego::on_pushButton_clicked()
{

    nivel= new Nivel2();
    nivel->show();
}

void VentanaJuego::funcionActivacionTimer(){
    ui->lcdNumber->display(contador);
    contador++;
    if(contador==30){

        /*SE TRABAJA CON ARCHIVOS*/
        ofstream escritura;
        escritura.open("MULTIJUGADOR.txt",ios::out|ios::app); //Se abre el archivo

        if(escritura.is_open()){//Mientras este abierto

            //Se escribe el puntaje y las vidas con que quedo el jugador
           escritura<<left<<setw(10)<<multijugador->Jugar<<setw(13)<< score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< health->getVidas_Jugador()<<endl;

        }
        escritura.close();//Se cierra fichero

        modoJuego->Contador_Multijugador+=1; //Se suma al contador de multijugador

                //Se abre una nueva ventana de multijugador
                multijugador=new Ventana_Multijugador();
                multijugador->show();//Se muestra

                this->close();//Se cierra actual mentana
                Nivel1Sound->stop();



        if(modoJuego->Contador_Multijugador>2){//Para definir ganador en multijugador

            //Declaracion de variables para manejo de archivos
            ifstream lectura;

            bool encontrado_=false;
            string auxNombre;
            int aux_Puntaje,aux_Vidas;
            int Puntaje1,Vidas1;

          /*PLAYER 1*/

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


            /*PLAYER 2*/

             int Puntaje2=0;
             int Vidas2=0;

             lectura.open("MULTIJUGADOR.txt",ios::in);//Se abre el fichero

               if(lectura.is_open() ){//Si el fichero esta abierto
                  lectura>>auxNombre;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingreso
                      while(!lectura.eof()){//Mientras el fichero no llegue a su fin
                          lectura>>aux_Puntaje>>aux_Vidas;//Se lee primera palabra de la fila para encontrar el nombre del jugador que se ingreso
                          if(auxNombre=="2"){ //En caso de que se encuente
                              encontrado_=true;

                              //Asignación a variables
                              Puntaje2=aux_Puntaje;
                              Vidas2=aux_Vidas;

                              this->close();//Se cierra la ventana actual
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

                if(Vidas1 > Vidas2){//Ganador es player 1
                    Ganador1= new Player1_Ganador();
                    Ganador1->show();
                }

                if(Vidas2 > Vidas1){//Ganador es player 2
                    Ganador2= new Player2_Ganador();
                    Ganador2->show();
                }

                if(Vidas1 == Vidas2){

                    if(Puntaje1>Puntaje2){ //Ganador es player 1
                        Ganador1= new Player1_Ganador();
                        Ganador1->show();
                    }

                    if(Puntaje1<Puntaje2){//Ganador es player 2
                        Ganador2= new Player2_Ganador();
                        Ganador2->show();
                    }
                }

            remove("MULTIJUGADOR.txt");
        }
    }
}
