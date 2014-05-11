#include "drawarea.hpp"
#include "ui_drawarea.h"

//ctor and dtor
DrawArea::DrawArea(QWidget* parent) : QWidget(parent), _ui(new Ui::DrawArea),  _pen(new QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin)),
    _gutterPen(new QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin))  {

    _ui->setupUi(this);
    setAttribute(Qt::WA_StaticContents);
    setImage(new QImage(16, 16, QImage::Format_RGB32));
}

DrawArea::~DrawArea() {

}

//public methods
void DrawArea::setImage(QImage* image, const QColor& color) {
    _image.reset(image);
    _resize();
    _image->fill(color);
    _backgroundColor = color;
}

//public slots
void DrawArea::setZoom(int value) {
    _zoom = value;
    _resize();
}

void DrawArea::setPenColor(const QColor& color) {
    _pen->setColor(color);
}

void DrawArea::setCurrentTool(DrawTool tool) {
    _currentTool = tool;
}

//protected methods
void DrawArea::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)
        _setImagePixel(event->pos());
}

void DrawArea::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        _setImagePixel(event->pos());
}

void DrawArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (_zoom >= 3) {
        painter.setPen(*_gutterPen);
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
    _drawImageBorder(painter);
}

//private methods
void DrawArea::_setImagePixel(const QPoint& pos) {
    int i = pos.x() / _zoom;
    int j = pos.y() / _zoom;
    if (_image->rect().contains(i, j)) {
        if (_currentTool == DrawTool::Brush)
            _image->setPixel(i, j, _pen->color().rgb());
        else if (_currentTool == DrawTool::Eraser)
            _image->setPixel(i, j, _backgroundColor.rgb());
        else if (_currentTool == DrawTool::ColorPicker) {
            setPenColor(QColor(_image->pixel(i, j)));
            emit colorChanged(_pen->color());
        }
        update(_pixelRect(i, j));
    }
}

void DrawArea::_resize() {
    resize(_image->width() * _zoom, _image->height() * _zoom);
    update();
}

void DrawArea::_drawImageBorder(QPainter& qPainter) {
    QPen pen(Qt::red, 1, Qt::DashLine, Qt::SquareCap, Qt::BevelJoin);
    qPainter.setPen(pen);
    //draw top horizontal line
    qPainter.drawLine(0, 0, _image->width() * _zoom, 0);
    //draw bottom horizontal line
    qPainter.drawLine(0, _image->height() * _zoom - 1, _image->width() * _zoom, _image->height() * _zoom - 1);
    //draw left vertical line
    qPainter.drawLine(0, 0, 0, _image->height() * _zoom);
    //draw right vertical line
    qPainter.drawLine(_image->width() * _zoom - 1, 0, _image->width() * _zoom - 1, _image->height() * _zoom);
}

QRect DrawArea::_pixelRect(int i, int j) const {
    if (_zoom >= 3)
        return QRect(_zoom * i + 1, _zoom * j + 1, _zoom - 1, _zoom - 1);
    return QRect(_zoom * i, _zoom * j, _zoom, _zoom);
}
