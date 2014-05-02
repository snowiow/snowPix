#include "drawarea.hpp"
#include "ui_drawarea.h"

//ctor and dtor
DrawArea::DrawArea(QWidget *parent) : QWidget(parent), _ui(new Ui::DrawArea),  _pen(new QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap,Qt::BevelJoin))  {
    _ui->setupUi(this);
    _zoom = 8;
    setAttribute(Qt::WA_StaticContents);
    setImage(new QImage(16, 16, QImage::Format_RGB32));
}

DrawArea::~DrawArea() {

}

//public methods
void DrawArea::setImage(QImage* image) {
    _image.reset(image);
    _image->fill(Qt::white);
    _resize();
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
    if (_zoom >= 3) {
        painter.setPen(*_pen);
        for (int i = 0; i < _image->width(); i++)
            painter.drawLine(_zoom * i, 0, _zoom * i, _zoom * _image->height());
        for (int i = 0; i < _image->height(); i++)
            painter.drawLine(0, _zoom * i, _zoom * _image->width(), _zoom * i);
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
    if (_zoom >= 3)
        return QRect(_zoom * i + 1, _zoom * j + 1, _zoom - 1, _zoom - 1);
    return QRect(_zoom * i, _zoom * j, _zoom, _zoom);
}

void DrawArea::_setImagePixel(const QPoint& pos, bool opaque) {
    int i = pos.x() / _zoom;
    int j = pos.y() / _zoom;
    if (_image->rect().contains(i, j)) {
        if (opaque)
            _image->setPixel(i, j, _pen->color().rgb());
        else
            _image->setPixel(i, j, Qt::white);
        update(_pixelRect(i, j));
    }
}

void DrawArea::setZoom(int value) {
    if (value > 0 && value < 16) {
        _zoom = value;
        _resize();
    }

}

void DrawArea::_resize() {
    resize(_image->size().width() * _zoom, _image->size().height() * _zoom);
    update();
}
