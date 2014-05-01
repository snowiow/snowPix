#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <memory>
#include <QScrollArea>
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
        //member
        int zoom;

         //ctor and dtor
        DrawArea(QWidget* parent = nullptr);
        virtual ~DrawArea();

        //methods
        void setImage(QImage* image);
        // QSize sizeHint() const;

    protected:
        //methods
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);

    private:
        //member
        std::unique_ptr<Ui::DrawArea> ui;
        std::unique_ptr<QImage> _image;
        std::unique_ptr<QPen> _pen;

        //methods
        void _setImagePixel(const QPoint& pos, bool opaque);
        QRect _pixelRect(int i, int j) const;

};

#endif // DRAWAREA_H
