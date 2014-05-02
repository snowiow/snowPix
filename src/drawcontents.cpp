#include "drawcontents.hpp"
#include "ui_drawcontents.h"

//ctor and dtor
DrawContents::DrawContents(QWidget *parent) : QWidget(parent), _ui(new Ui::DrawContents) {
    _ui->setupUi(this);
    _createConnects();
}

DrawContents::~DrawContents() {

}

void DrawContents::setImage(QImage* image) {
    _ui->drawArea->setImage(image);
}

void DrawContents::_createConnects() {
    connect(_ui->zoomOutButton, SIGNAL(clicked()), this,
            SLOT(_onZoomOutButtonClicked()));
    connect(_ui->zoomInButton, SIGNAL(clicked()), this,
            SLOT(_onZoomInButtonClicked()));
    connect(_ui->spinBox, SIGNAL(valueChanged(int)), _ui->drawArea,
            SLOT(setZoom(int)));
}


void DrawContents::_onZoomOutButtonClicked() {
    _ui->spinBox->setValue(_ui->spinBox->value() - 1);
}

void DrawContents::_onZoomInButtonClicked() {
    _ui->spinBox->setValue(_ui->spinBox->value() + 1);
}