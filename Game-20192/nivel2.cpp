#include "nivel2.h"
#include "ui_nivel2.h"
#include "login.h"
#include "cargar_partidas.h"
#include "modojuego.h"

extern VentanaJuego *game;//Se usa clase externa
extern Login *login; //Se usa clase externa
extern Cargar_Partidas *Partidas; //Se usa clase externa
extern QMediaPlayer *Nivel1Sound; //Se instancia un objeto tipo QMediaPlayer
extern ModoJuego *modoJuego;

QMediaPlayer *Nivel2Sound; //Se instancia un objeto tipo QMediaPlayer

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    //Se crea la escena
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,905,510);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/background.jpg")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//Se quitan las barras
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    if(Partidas->Para_Jugar_Nivel_1==1 || Partidas->Para_Jugar_Nivel_1==2){
         Nivel1Sound->stop(); //Se apaga la musica del nivel 1
    }

    //Para musica del nivel 2
     Nivel2Sound=new QMediaPlayer();
     Nivel2Sound->setMedia(QUrl("qrc:/Musica/Harry Potter and the Prisoner of Azkaban Soundtrack - 06 Buckbeaks Flight.mp3"));
     Nivel2Sound->setVolume(30);

     if(Nivel2Sound->state()==QMediaPlayer::PlayingState){
         Nivel2Sound->setPosition(0);
     }else if(Nivel2Sound->state()==QMediaPlayer::StoppedState){
         Nivel2Sound->play();
     }

    //------------------------------------------------------------------------------------------

    //Crear mortifagos
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(900);//Cada que pase este tiempo se crea

    //------------------------------------------------------------------------------------------

    //Se crea el jugador
    personajeNivel2= new Jugador();

    //Se agrega el personaje a la escena
    scene->addItem(personajeNivel2);

    //Para poder manejar el personaje con el teclado
    personajeNivel2->setFlag(QGraphicsItem::ItemIsFocusable);
    personajeNivel2->setFocus();

    personajeNivel2->setPos(100,100); //Posicion en la escena

     if(Partidas->Para_Jugar_Nivel_1==1){ //Para seguir con una partida desde cero

                 m_score = new Puntuacion(game->score->getPuntaje());//Con la puntuacion que llevaba
                 scene->addItem(m_score);//Se añade
                 m_score->setPos(m_score->x()+750,m_score->y());//Se ubica

                 //------------------------------------------------------------------------------------------
                 //Para las vidas de los jugadores
                 m_health=new Vidas_Jugador(game->health->getVidas_Jugador());//Se crean las vidas
                 scene->addItem(m_health);//Se añade a la escena
                 m_health->setPos(m_health->x()+650, m_health->y());//Posicion en la escena
        }

     if(Partidas->Para_Jugar_Nivel_1==2){ //para partidas cargadas


       //Para el puntaje en la escena
        m_score = new Puntuacion(game->score->getPuntaje());
        scene->addItem(m_score);
        m_score->setPos(m_score->x()+750,m_score->y());

        //------------------------------------------------------------------------------------------
        //Para las vidas de los jugadores
        m_health=new Vidas_Jugador(game->health->getVidas_Jugador());//Se crean las vidas
        scene->addItem(m_health);//Se añade a la escena
        m_health->setPos(m_health->x()+650, m_health->y());//Posicion en la escena
     }


     if(Partidas->Para_Jugar_Nivel_2==2){ //para cargar partida en nivel 2

       //Para el puntaje en la escena
        m_score = new Puntuacion(Partidas->Puntaje_Jugador);
        scene->addItem(m_score);
        m_score->setPos(m_score->x()+750,m_score->y());

        //------------------------------------------------------------------------------------------
        //Para las vidas de los jugadores
        m_health=new Vidas_Jugador(Partidas->Vidas_Jugador);//Se crean las vidas
        scene->addItem(m_health);//Se añade a la escena
        m_health->setPos(m_health->x()+650, m_health->y());//Posicion en la escena
     }


    Nombre_Jugador=login->jugador;//Nombre del jugador actual

    //-----------------------------------------------------------------------------------------

    cronometro=new QTimer(this);    //crea el timer

    //Se crean 4 cuerpos para la simulación
    Lechuzas[0]=new Hedwig(8000,-10000,2,0,70,15);
    Lechuzas[1]=new Hedwig(8000,-5000,0,0,70000,30);
    Lechuzas[2]=new Hedwig(12000,-2000,-1.6,1.2,25,15);
    //Se añaden a la escena
    scene->addItem(Lechuzas[0]);
    scene->addItem(Lechuzas[1]);
    scene->addItem(Lechuzas[2]);

    connect(cronometro,SIGNAL(timeout()),this,SLOT(actualizar()));
    cronometro->start(10);
}

Nivel2::~Nivel2()
{
    delete ui;
}

void Nivel2::spawn()
{
    //Se van creando los mortifagos
    Mortifago * mortifago = new Mortifago();
    scene->addItem(mortifago); //Se añaden a la escena
}

void Nivel2::on_pushButton_clicked()
{
    //Variables para manejar archivos
    ofstream aux;
    ifstream lectura;
    string jugador,auxJugador, NombreJugador, Contra;
    int Puntaje, Nivel, Vidas;

    aux.open("auxiliar.txt",ios::out|ios::app);//Se abre el fichero
    lectura.open("JUGADORES.txt",ios::in);//Se abre el fichero

    if(lectura.is_open() && aux.is_open()){//Si esta abierto
      lectura>>jugador;
       while(!lectura.eof()){//Mientras no llegue al fin
           lectura>>Contra>>Puntaje>>Vidas>>Nivel;
           if(jugador==Nombre_Jugador){//Si se encuentra el jugador

               //Se escribe en el fichero
              aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<< m_score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< m_health->getVidas_Jugador()<<setw(7)<<setprecision(2)<<right<<2<<endl;

           }

           else
           {

               aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<<Puntaje<<endl<<setw(7)<<setprecision(2)<<right<<Vidas<<setw(7)<<setprecision(2)<<right<<Nivel<<endl;

           }
            lectura>>jugador;//Ciclo para encontrar el jugador
     }

    }

    else  qDebug()<<"--No se pudo abrir el Archivo o aun no ha sido Creado--"<<endl;

    //Se cierran los archivos
     lectura.close();
     aux.close();

     //Se remueve y renombra
     remove("JUGADORES.txt");
     rename("auxiliar.txt","JUGADORES.txt");
}

void Nivel2::actualizar()//Actualizar datos de los pajaros
{
    for(int j=0; j<3; j++)
       {
           for(int k=0; k<3; k++)
           {
               if(j != k){
                   Lechuzas[j]->mover(Lechuzas[k]);
               }
           }

           Lechuzas[j]->ModValor();
       }
   }
