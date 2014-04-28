#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <memory>
#include <QWidget>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
    class DrawArea;
}

class DrawArea : public QWidget
{
    Q_OBJECT

    public:
        bool modified;
         std::unique_ptr<QImage> image;

        DrawArea(QWidget *parent = nullptr);
        virtual ~DrawArea();

        bool openImage(const QString &fileName);
        bool saveImage(const QString & fileName, const char* fileFormat);

    protected:
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);

    private:
        std::unique_ptr<Ui::DrawArea> ui;

        QPoint _lastPoint;
        QPen _pen;
        bool _scribbling;

        void _drawLineTo(const QPoint& endPoint);
};

#endif // DRAWAREA_H
