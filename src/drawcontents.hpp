#ifndef DRAWCONTENTS_HPP
#define DRAWCONTENTS_HPP

#include <memory>
#include <QWidget>

#include "drawarea.hpp"

namespace Ui {
    class DrawContents;
}

class DrawContents : public QWidget
{
    Q_OBJECT

    public:
         //ctor and dtor
        explicit DrawContents(QWidget* parent = nullptr);
        virtual ~DrawContents();
        const Ui::DrawContents* getUi() const;
        void setImage(QImage* image, QColor color = Qt::white);

    public slots:
        void setPenColor(const QColor& color);
        void setCurrentTool(DrawArea::DrawTool value);
        void changeColor(const QColor& color);

    signals:
        void colorChanged(const QColor& color);

    private:
        //member
        std::unique_ptr<Ui::DrawContents> _ui;

        void _createConnects();

    private slots:
        void _onZoomOutButtonClicked();
        void _onZoomInButtonClicked();
};
#endif //DRAWCONTENTS_HPP
