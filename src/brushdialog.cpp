#include "brushdialog.hpp"
#include "ui_brushdialog.h"

BrushDialog::BrushDialog(QWidget* parent) : QWidget(parent),
    _ui(new Ui::BrushDialog), _currentColor(QColor()) {
        _ui->setupUi(this);
        _createConnects();
}

BrushDialog::~BrushDialog() {

}

void BrushDialog::_createConnects() {
    connect(_ui->colorPickerButton, SIGNAL(clicked()), this,
            SLOT(_onColorPickerClicked()));
}

void BrushDialog::_setCurrentColor(QColor& color) {
    _currentColor = color;
    emit colorChanged(_currentColor);
}

void BrushDialog::_onColorPickerClicked() {
    QColor chosenColor = QColorDialog::getColor(_currentColor, this);

    if (chosenColor.isValid()) {
        setColorButtonColor(chosenColor);
        _setCurrentColor(chosenColor);
    }
}

void BrushDialog::setColorButtonColor(const QColor& color) {
    std::string rgbColor = "background-color: rgb("
                           + std::to_string(color.red()) + ","
                           + std::to_string(color.green()) + ","
                           + std::to_string(color.blue()) + ");";

    _ui->colorPickerButton->setStyleSheet(rgbColor.c_str());
}