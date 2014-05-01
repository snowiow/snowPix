#include "drawarea.hpp"
#include "ui_drawarea.h"
#include <iostream>

//ctor and dtor
DrawArea::DrawArea(QWidget *parent) : QWidget(parent), ui(new Ui::DrawArea), _image(new QImage(64, 64, QImage::Format_RGB32)), _pen(new QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap,Qt::BevelJoin))  {
    ui->setupUi(this);

    setAttribute(Qt::WA_StaticContents);
    zoom = 8;
    _image->fill(Qt::white);
}

DrawArea::~DrawArea() {

}

//public methods
void DrawArea::setImage(QImage* image) {
    _image.reset(image);
    _image->fill(Qt::white);
    resize(_image->size().width() * zoom, image->size().height() * zoom);
}

//protected methods
void DrawArea::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)
        _setImagePixel(event->pos(), true);
    else if (event->button() == Qt::RightButton)
        _setImagePixel(event->pos(), false);
}

void DrawArea::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        _setImagePixel(event->pos(), true);
    else if (event->buttons() & Qt::RightButton)
        _setImagePixel(event->pos(), false);
}

void DrawArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (zoom >= 3) {
        painter.setPen(*_pen);
        for (int i = 0; i < _image->width(); i++)
            painter.drawLine(zoom * i, 0, zoom * i, zoom * _image->height());
        for (int i = 0; i < _image->height(); i++)
            painter.drawLine(0, zoom * i, zoom * _image->width(), zoom * i);
    }
    for (int i = 0; i < _image->width(); i++) {
        for (int j = 0; j < _image->height(); j++) {
            QRect rect = _pixelRect(i, j);
            if (!event->region().intersected(rect).isEmpty())
                painter.fillRect(rect, QColor::fromRgb(_image->pixel(i, j)));
        }
    }
}

//private methods
QRect DrawArea::_pixelRect(int i, int j) const {
    if (zoom >= 3)
        return QRect(zoom * i + 1, zoom * j + 1, zoom - 1, zoom - 1);
    return QRect(zoom * i, zoom * j, zoom, zoom);
}

void DrawArea::_setImagePixel(const QPoint& pos, bool opaque) {
    int i = pos.x() / zoom;
    int j = pos.y() / zoom;
    if (_image->rect().contains(i, j)) {
        if (opaque)
            _image->setPixel(i, j, _pen->color().rgb());
        else
            _image->setPixel(i, j, Qt::white);
        update(_pixelRect(i, j));
    }
}
