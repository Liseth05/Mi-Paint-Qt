#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>//
#include <QImage>//
#include <QPainter>//
#include <QPaintEvent>
#include <QMouseEvent>//
#include <QPaintEvent>//
#include <QDialog>//
#include <QInputDialog>//ancho del pincel
#include <QColorDialog>//paleta de colores
#include <QMessageBox>//
#include <QFileDialog>//
#include <QDebug>//
#include <QAbstractButton>//
#include <QIcon>//
#include <QPixmap>//

#define DEFAULT_ANCHO 2

#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_actionGuardar_triggered();
    void on_actionNuevo_triggered();

    void on_actionColor_triggered();

    void on_actionLibre_triggered();

    void on_actionLineas_triggered();

    void on_actionAncho_triggered();

    void on_actionCircunferencias_triggered();

    void on_actionRectangulos_triggered();

private:
    Ui::Principal *ui;
    QColor m_Color;
    QImage *m_imagen; //imagen sobre la cual se va a dibujar
    QPainter *m_painter; //el objeto del painter
    QPoint m_ptInicial; //punto inicial para dibujar
    QPoint m_ptFinal; //punto final para dibujar
    int m_opcion;
    int m_ancho;
int nNumLineas;
    bool m_toogle=false;

};
#endif // PRINCIPAL_H
