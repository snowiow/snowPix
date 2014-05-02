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

         //ctor and dtor
        DrawArea(QWidget* parent = nullptr);
        virtual ~DrawArea();

        //methods
        void setImage(QImage* image);
        void increaseZoom();
        void decreaseZoom();
        int getZoom() const {
            return _zoom;
        }

    public slots:
        void setZoom(int value);

    protected:
        //methods
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);

    private:
        //member
        int _zoom;
        std::unique_ptr<Ui::DrawArea> _ui;
        std::unique_ptr<QImage> _image;
        std::unique_ptr<QPen> _pen;

        //methods
        void _setImagePixel(const QPoint& pos, bool opaque);
        QRect _pixelRect(int i, int j) const;
        void _resize();

};

#endif // DRAWAREA_H
