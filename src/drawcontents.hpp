#ifndef DRAWCONTENTS_H
#define DRAWCONTENTS_H

#include <memory>
#include <QWidget>

namespace Ui {
    class DrawContents;
}

class DrawContents : public QWidget
{
    Q_OBJECT

    public:
         //ctor and dtor
        DrawContents(QWidget* parent = nullptr);
        virtual ~DrawContents();
        void setImage(QImage* image, QColor color = Qt::white);

    private:
        //member
        std::unique_ptr<Ui::DrawContents> _ui;

        void _createConnects();

    private slots:
        void _onZoomOutButtonClicked();
        void _onZoomInButtonClicked();
};

#endif
