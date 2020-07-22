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

    //make rect focusable
    personajeNivel2->setFlag(QGraphicsItem::ItemIsFocusable);
    personajeNivel2->setFocus();
    personajeNivel2->setPos(100,100); //Posicion en la escena



    int Nivel=Partidas->Nivel_Juego;
    int Puntaje=Partidas->Puntaje_Jugador;
    int Vidas=Partidas->Vidas_Jugador;

//    if(Nivel==1){
//    //------------------------------------------------------------------------------------------

//    //Para el puntaje en la escena

//   // m_score = new Puntuacion(game->score->getPuntaje());
//    m_score = new Puntuacion(0);
//    //m_score = new Puntuacion(0);
//    scene->addItem(m_score);
//    m_score->setPos(m_score->x()+750,m_score->y());

//    //------------------------------------------------------------------------------------------
//    //Para las vidas de los jugadores
//   // m_health=new Vidas_Jugador(game->health->getVidas_Jugador());//Se crean las vidas
//    m_health=new Vidas_Jugador(0);//Se crean las vidas
//    //m_health=new Vidas_Jugador(0);//Se crean las vidas
//    scene->addItem(m_health);//Se añade a la escena
//    m_health->setPos(m_health->x()+650, m_health->y());//Posicion en la escena

//    }

   // if(Nivel==2){

        //------------------------------------------------------------------------------------------

//


     if(Partidas->Para_Jugar_Nivel_1==1){

                  m_score = new Puntuacion(game->score->getPuntaje());
                // m_score = new Puntuacion(0);
                 //m_score = new Puntuacion(0);
                 scene->addItem(m_score);
                 m_score->setPos(m_score->x()+750,m_score->y());

                 //------------------------------------------------------------------------------------------
                 //Para las vidas de los jugadores
                 m_health=new Vidas_Jugador(game->health->getVidas_Jugador());//Se crean las vidas
                 m_health=new Vidas_Jugador(0);//Se crean las vidas
                 //m_health=new Vidas_Jugador(0);//Se crean las vidas
                 scene->addItem(m_health);//Se añade a la escena
                 m_health->setPos(m_health->x()+650, m_health->y());//Posicion en la escena

}

     if(Partidas->Para_Jugar_Nivel_2==2){


       //Para el puntaje en la escena

        m_score = new Puntuacion(Puntaje);
       // m_score = new Puntuacion(game->score->getPuntaje());
        scene->addItem(m_score);
        m_score->setPos(m_score->x()+750,m_score->y());

        //------------------------------------------------------------------------------------------
        //Para las vidas de los jugadores
        m_health=new Vidas_Jugador(Vidas);//Se crean las vidas
       // m_health=new Vidas_Jugador(game->health->getVidas_Jugador());//Se crean las vidas m_health=new Vidas_Jugador(0);//Se crean las vidas
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
           if(jugador==Nombre_Jugador){
               encontrado_=true;

              aux<<left<<setw(10)<<jugador<<setw(13)<<Contra<<setw(7)<<setprecision(2)<<right<< m_score->getPuntaje()<<setw(7)<<setprecision(2)<<right<< m_health->getVidas_Jugador()<<setw(7)<<setprecision(2)<<right<<2<<endl;

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

void Nivel2::actualizar()//Actualizar datos de los cuerpos
{
    for(int j=0; j<3; j++)
       {
           for(int k=0; k<3; k++)
           {
               if(j != k){
                   Cuerpos[j]->CalcularAcelx(Cuerpos[k]);
                   Cuerpos[j]->CalcularAcely(Cuerpos[k]);
                   Cuerpos[j]->getPosx();
                   Cuerpos[j]->getPosy();
                   Cuerpos[j]->CalcularVelx();
                   Cuerpos[j]->CalcularVely();
                   Cuerpos[j]->mover();
               }
           }

           Cuerpos[j]->ModValor();
       }
   }
