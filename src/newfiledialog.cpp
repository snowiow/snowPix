#include "newfiledialog.hpp"
#include "ui_newfiledialog.h"

NewFileDialog::NewFileDialog(NewFileDialogResult& result, QWidget *parent) : QDialog(parent), _ui(new Ui::NewFileDialog), _result(result) {
    _ui->setupUi(this);
    _createConnects();
    _hideElements();
}

NewFileDialog::~NewFileDialog() {

}

void NewFileDialog::_createConnects() {
    connect(_ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(_ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(_ui->sizesList, SIGNAL(itemSelectionChanged()), this, SLOT(_onSizeChanged()));
    connect(_ui->colorPickerButton, SIGNAL(clicked()), this,
            SLOT(_onColorPickerClicked()));
    connect(_ui->widthSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(_onWidthSpinBoxClicked(int)));
    connect(_ui->heightSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(_onHeightSpinBoxClicked(int)));
}

void NewFileDialog::_hideElements() {
    if (!_elementsHidden) {
        _ui->widthLabel->hide();
        _ui->widthSpinBox->hide();
        _ui->heightLabel->hide();
        _ui->heightSpinBox->hide();
        _elementsHidden = true;
    }
}

void NewFileDialog::_showElements() {
    if (_elementsHidden) {
        _ui->widthLabel->show();
        _ui->widthSpinBox->show();
        _ui->heightLabel->show();
        _ui->heightSpinBox->show();
        _elementsHidden = false;
    }
}

void NewFileDialog::_onSizeChanged() {
    const QString text = _ui->sizesList->currentItem()->text();
    if (text == "user defined")
        _showElements();
    else {
        _hideElements();
        if (text == "8x8")
            _result.size = QPoint(8, 8);
        else if (text == "16x16")
            _result.size = QPoint(16, 16);
        else if (text == "24x24")
            _result.size = QPoint(24, 24);
        else if (text == "32x32")
            _result.size = QPoint(32, 32);
        else if (text == "48x48")
            _result.size = QPoint(48, 48);
        else if (text == "64x64")
            _result.size = QPoint(64, 64);
        else if (text == "128x128")
            _result.size = QPoint(128, 128);
        else if (text == "256x256")
            _result.size = QPoint(256, 256);
    }
}


void NewFileDialog::_onColorPickerClicked() {
    QColor chosenColor = QColorDialog::getColor(Qt::white, this);
    _result.chosenColor = chosenColor;
    std::string rgbColor =
    "background-color: rgb("
                           + std::to_string(chosenColor.red()) + ","
                           + std::to_string(chosenColor.green()) + ","
                           + std::to_string(chosenColor.blue()) + ");";

_ui->colorPickerButton->setStyleSheet(rgbColor.c_str());
}

void NewFileDialog::_onWidthSpinBoxClicked(int value) {
    _result.size.setX(value);
}

void NewFileDialog::_onHeightSpinBoxClicked(int value) {
    _result.size.setY(value);
}