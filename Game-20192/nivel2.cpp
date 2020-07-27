#include "nivel2.h"
#include "ui_nivel2.h"
#include "ventanajuego.h"
#include "login.h"
#include "cargar_partidas.h"

extern VentanaJuego *game;//Se usa clase externa
extern Login *login; //Se usa clase externa
extern Cargar_Partidas *Partidas; //Se usa clase externa

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

   // int Nivel=Partidas->Nivel_Juego;
    int Puntaje=Partidas->Puntaje_Jugador;
    int Vidas=Partidas->Vidas_Jugador;

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

     if(Partidas->Para_Jugar_Nivel_2==2){ //para cargar partida


       //Para el puntaje en la escena
        m_score = new Puntuacion(Puntaje);
        scene->addItem(m_score);
        m_score->setPos(m_score->x()+750,m_score->y());

        //------------------------------------------------------------------------------------------
        //Para las vidas de los jugadores
        m_health=new Vidas_Jugador(Vidas);//Se crean las vidas
        scene->addItem(m_health);//Se añade a la escena
        m_health->setPos(m_health->x()+650, m_health->y());//Posicion en la escena
     }


    Nombre_Jugador=login->jugador;//Nombre del jugador actual

    //-----------------------------------------------------------------------------------------

    cronometro=new QTimer(this);    //crea el timer

    //Se crean 4 cuerpos para la simulación
    Cuerpos[0]=new Hedwig(8000,-10000,2,0,70,15);
    Cuerpos[1]=new Hedwig(8000,-5000,0,0,70000,30);
    Cuerpos[2]=new Hedwig(12000,-2000,-1.6,1.2,25,15);
    //Se añaden a la escena
    scene->addItem(Cuerpos[0]);
    scene->addItem(Cuerpos[1]);
    scene->addItem(Cuerpos[2]);

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
    bool encontrado_=false;
    string jugador,auxJugador, NombreJugador, Contra;
    int Puntaje, Nivel, Vidas;

    aux.open("auxiliar.txt",ios::out|ios::app);//Se abre el fichero
    lectura.open("JUGADORES.txt",ios::in);//Se abre el fichero

    if(lectura.is_open() && aux.is_open()){//Si esta abierto
      lectura>>jugador;
       while(!lectura.eof()){//Mientras no llegue al fin
           lectura>>Contra>>Puntaje>>Vidas>>Nivel;
           if(jugador==Nombre_Jugador){//Si se encuentra el jugador
               encontrado_=true;

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
                   Cuerpos[j]->mover(Cuerpos[k]);
               }
           }

           Cuerpos[j]->ModValor();
       }
   }
