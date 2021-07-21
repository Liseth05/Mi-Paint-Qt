#include "principal.h"
#include "ui_principal.h"


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //instancia del objeto imagen
    m_imagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);

    //rellenar de blanco
    m_imagen->fill(Qt::white);

    //instanciar el objeto paiter
    m_painter=new QPainter(m_imagen);

    m_Color = QColor();
     m_ancho = DEFAULT_ANCHO;
     nNumLineas=0;
}

Principal::~Principal()
{
    delete ui;
    // delete m_imagen;
}

/**
 * @brief Principal::paintEvent Se dibuja cada vez que se redibuja la interzaf
 * @param event
 */

void Principal::paintEvent(QPaintEvent *event)
{
    //crear otro painter (local)
    QPainter painter(this);

    //dibujar la imagen
    painter.drawImage(0,0, *m_imagen);

    //aceptar el evento
    event->accept();

}

void Principal::mousePressEvent(QMouseEvent *event)
{

    //    qDebug()<<event->pos();
       // m_ptInicial =event->pos();


    if(m_opcion == 1){
        m_ptInicial = event->pos(); //obtener la posicion del cursor
    }else if (m_opcion == 2){
        if (m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            QPen pincel;
            pincel.setColor(m_Color);
            pincel.setWidth(m_ancho);
            m_painter->setPen(pincel);
            m_painter->drawLine(m_ptInicial, m_ptFinal);
            //Redibujar la interfaz grafica
            update();
        }
    }else if(m_opcion == 3){
        if (m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            //Dibujar rectangulo
            int ancho = m_ptFinal.x() - m_ptInicial.y();
            int alto = m_ptFinal.y() - m_ptInicial.y();
            QPen pincel;
            pincel.setColor(m_Color);
            pincel.setWidth(m_ancho);
            m_painter->setPen(pincel);
            m_painter->drawRect(m_ptInicial.x(),
                                m_ptInicial.y(),
                                ancho, alto);
            //Redibujar la interfaz grafica
            update();
        }
    }else if(m_opcion == 4){
        if (m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            //Dibujar circunferencia
            QPen pincel;
            pincel.setColor(m_Color);
            pincel.setWidth(m_ancho);
            QRectF circulo(m_ptInicial, m_ptFinal);
            m_painter->setPen(pincel);
            m_painter->drawEllipse(circulo);
            //Redibujar la interfaz grafica
            update();
        }
    }
    m_toogle = !m_toogle;

}


void Principal::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug()<<event->pos();
    m_ptFinal =event->pos();
    //Establecer un pincel
    QPen pincel;
    pincel.setColor(m_Color);
    pincel.setWidth(m_ancho);
    m_painter->setPen(pincel);
    m_painter->drawLine(m_ptInicial, m_ptFinal);
    //redibujar la interfaz grafica
    update();
    m_ptInicial = m_ptFinal;

}
void Principal::on_actionNuevo_triggered()
{
    m_imagen->fill(Qt::white);
    update();
}



void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,"Guardar imagen",
                                                         QString(),"Imágenes (*.png)");
    if ( !nombreArchivo.isEmpty() ){
        if (m_imagen->save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo almacenado en: " +
                                     nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen",
                                 "No se pudo almacenar la imagen.");
    }
}

void Principal::on_actionColor_triggered()
{
    m_Color= QColorDialog::getColor(Qt::white,this,
                                    "Color del pincel");

}

void Principal::on_actionLibre_triggered()
{
    m_opcion =1;

}

void Principal::on_actionLineas_triggered()
{
    m_opcion =2;
}
void Principal::on_actionRectangulos_triggered()
{
    m_opcion =3;

}
void Principal::on_actionCircunferencias_triggered()
{
    m_opcion =4;
}

void Principal::on_actionAncho_triggered()
{
    m_ancho = QInputDialog::getInt(this,"Ancho de Principal",
                                   "Ingrese el ancho ",
                                   m_ancho,
                                   1,100);
}


