#include "drawarea.hpp"
#include "ui_drawarea.h"

DrawArea::DrawArea(QWidget *parent) : QWidget(parent), ui(new Ui::DrawArea) {
    ui->setupUi(this);

    setAttribute(Qt::WA_StaticContents);

    _scribbling = false;
    _pen = QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin);
    _image = QImage(64, 64, QImage::Format_RGB32);
    _image.fill(Qt::blue);

}

DrawArea::~DrawArea() {
    delete ui;
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
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, _image, rect);
}

void DrawArea::resizeEvent(QResizeEvent *event) {
    if (width() > _image.width()
            || height() > _image.height()
            ) {
        int newWidth = qMax(width() + 128, _image.width());
        int newHeight = qMax(height() + 128, _image.height());
        _resizeImage(&_image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void DrawArea::_drawLineTo(const QPoint &endPoint) {
    QPainter painter(&_image);
    painter.setPen(_pen);
    painter.drawLine(_lastPoint, endPoint);

    int rad = _pen.width() / 2 + 2;
    //avoid repaint of complete widget
    update(QRect(_lastPoint, endPoint).normalized().
           adjusted(-rad, -rad, +rad, +rad));

    _lastPoint = endPoint;
}

void DrawArea::_resizeImage(QImage *image, const QSize &size) {
    if (image->size() == size)
        return;
    QImage newImage(size, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), _image);
    *image = newImage;
}
