#include "drawarea.hpp"
#include "ui_drawarea.h"

DrawArea::DrawArea(QWidget *parent) : QWidget(parent), ui(new Ui::DrawArea), image(new QImage(64, 64, QImage::Format_RGB32)) {
    ui->setupUi(this);

    setAttribute(Qt::WA_StaticContents);

    _scribbling = false;
    _pen = QPen(Qt::black, 20, Qt::SolidLine,
                Qt::SquareCap,Qt::BevelJoin);

    image->fill(Qt::white);
}

DrawArea::~DrawArea() {

}

void DrawArea::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        _lastPoint = event->pos();
        _scribbling = true;
    }
}

void DrawArea::mouseMoveEvent(QMouseEvent *event) {
    if((event->buttons() & Qt::LeftButton) && _scribbling)
        _drawLineTo(event->pos());
}

void DrawArea::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && _scribbling) {
        _drawLineTo(event->pos());
        _scribbling = false;
    }
}

void DrawArea::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    QRect rect = event->rect();
    painter.drawImage(rect, *image, rect);
}

void DrawArea::_drawLineTo(const QPoint &endPoint) {
    QPainter painter(image.get());
    painter.setPen(_pen);
    painter.drawLine(_lastPoint, endPoint);

    int rad = _pen.width() / 2 + 2;
    //avoid repaint of complete widget
    update(QRect(_lastPoint, endPoint).normalized().
           adjusted(-rad, -rad, +rad, +rad));

    _lastPoint = endPoint;
}
