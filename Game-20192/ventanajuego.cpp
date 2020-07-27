#include "ventanajuego.h"
#include "ui_ventanajuego.h"
#include "nivel2.h"
#include "cargar_partidas.h"
#include "ventana_multijugador.h"
#include "modojuego.h"

extern Login *login; //Se usa clase externa
extern Spell *spell;//Se usa clase externa
extern Cargar_Partidas *Partidas; //Se usa clase externa
extern Ventana_Multijugador *multijugador; //Se usa clase externa
extern ModoJuego *modoJuego; //Se instancia la clase ModoJuego

//Se instancian objetos
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

    //Snitch Dorada
    snich=new Snitch_Dorada(); //Se crea snitch
    scene->addItem(snich);//añade la snitch a la escena

    //-------------------------------------------------------------------------------------------

    Nombre_Jugador=login->jugador;//Nombre del jugador que esta jugando
    Contador_Multijugador=1; //Jugadores que han jugado en modo multijugador

    //-------------------------------------------------------------------------------------------

    //Se crea el jugador
    personaje= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personaje);

    //Para poder manejar el personaje con el teclado en la escena
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->setPos(100,100); //Posicion del personaje en escena

    //------------------------------------------------------------------------------------------
    //Personajes para la decoracion del escenario

    // se inicializan variables para Hermione
    Posx_Hermione=0;
    Posy_Hermione=0;
    Radio=100;
    Phi=0;

    //se inicializan variables para Malfoi
    Posx_Malfoi=Posy_Malfoi=0;

    //Se crean los personajes

    Hermion=new Personaje1_Decoracion;
    Malfoi= new Personaje2_Decoracion;

    time = new QTimer(this);

    scene->addItem(Hermion);//añade los circulos a la escena
    scene->addItem(Malfoi);

    Malfoi->setPos(400,200);//Asigna la posicion

    //Para movimiento de los personajes decoracion
    time->start(21);
    connect(time,SIGNAL(timeout()),this,SLOT(posicionPersonajeEscenario()));

    //-------------------------------------------------------------------------------------------

    if(modoJuego->Jugador==1){ // Para trabajar con partidas

        ui->lcdNumber->hide();

            if(Partidas->Para_Jugar_Nivel_1==1){ //Para trabajar con Inicio de partidas desde cero

                //Para la puntuación de los jugadores
                score = new Puntuacion(0);//Se crea la puntuacion
                scene->addItem(score);//Se añade a la escena
                score->setPos(score->x()+750,score->y());//posicion en la escena

                //------------------------------------------------------------------------------------

                //Para las vidas de los jugadores
                health=new Vidas_Jugador(3);//Se crean las vidas
                scene->addItem(health);//Se añade a la escena
                health->setPos(health->x()+650, health->y());//Posicion en la escena

                //Generar enemigos
                timer = new QTimer();
                QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
                timer->start(7000);

            }

            if(Partidas->Para_Jugar_Nivel_1==2){ //Cuando se trabaja con partidas cargadas

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
                timer->start(7000);
            }
    }

    if(modoJuego->Jugador==2){ //Para trabajar con multijugador

         if(multijugador->Multijugador==1){ //Para player 1

            //Para la puntuación de los jugadores
            score = new Puntuacion(0);//Se crea la puntuacion
            scene->addItem(score);//Se añade a la escena
            score->setPos(score->x()+750,score->y());//posicion en la escena

            //---------------------------------------------------------------------

            //Para las vidas de los jugadores
            health=new Vidas_Jugador(3);//Se crean las vidas
            scene->addItem(health);//Se añade a la escena
            health->setPos(health->x()+650, health->y());//Posicion en la escena

            //---------------------------------------------------------------------

            //Generar enemigos
            timer = new QTimer();
            QObject::connect(timer,SIGNAL(timeout()),personaje,SLOT(spawn()));
            //Se generan los enemigos mas rapido que en el caso de las partidas
            timer->start(3000);
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

void VentanaJuego::posicionPersonajeEscenario(void)
{

    Phi+=0.01745329252;
    //Movimiento circular
    Posx_Hermione=-Radio*cos(Phi*2);
    Posy_Hermione=-Radio*sin(Phi*2);
    Hermion->setPos(Posx_Hermione,Posy_Hermione);//Cambia la posición de Hermione con 'x' y 'y'

    Posx_Malfoi=Radio*pow(cos(Phi),3);
    Posy_Malfoi=Radio*pow(sin(Phi),3);
    Malfoi->setPos(Posx_Malfoi,Posy_Malfoi);//Cambia la posición de Malfoi con 'x' y 'y'
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
        if(multijugador->Jugar==1) multijugador->Jugar=2;//Para jugar con el otro jugador
        else multijugador->Jugar=1;

        ofstream escritura;
        escritura.open("MULTIJUGADOR.txt",ios::out|ios::app); //Se abre el archivo

        if(escritura.is_open()){//Mientras este abierto

            //Se escribe el puntaje y las vidas con que quedo el jugador
           escritura<<left<<setw(10)<<multijugador->Jugar<<setw(13)<< score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< health->getVidas_Jugador()<<endl;

        }
        escritura.close();//Se cierra fichero

        multijugador->Contador_Multijugador=multijugador->Contador_Multijugador+1; //Se suma al contador de multijugador

        //Se abre una nueva ventana de multijugador
        multijugador2=new Ventana_Multijugador();
        multijugador2->show();//Se muestra
        this->close();//Se cierra actual mentana

        if(multijugador->Contador_Multijugador>1){//Para definir ganador en multijugador

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

             int Puntaje2=0;
             int Vidas2=0;


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
    }
}
