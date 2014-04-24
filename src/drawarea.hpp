#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <memory>

namespace Ui {
    class DrawArea;
}

class DrawArea : public QWidget
{
    Q_OBJECT

    public:
        bool modified;

        DrawArea(QWidget *parent = nullptr);
        ~DrawArea();

        bool openImage(const QString &fileName);
        bool saveImage(const QString & fileName, const char* fileFormat);

    protected:
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);

    private:
        Ui::DrawArea *ui;

        QPoint _lastPoint;
        QPen _pen;
        bool _scribbling;

        QImage *_image;

        void _drawLineTo(const QPoint& endPoint);
};

#endif // DRAWAREA_H
