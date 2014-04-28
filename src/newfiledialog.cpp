#include "newfiledialog.hpp"
#include "ui_newfiledialog.h"
#include <iostream>

NewFileDialog::NewFileDialog(NewFileDialogResult& result, QWidget *parent) : QDialog(parent), _ui(new Ui::NewFileDialog), _result(result) {
    _ui->setupUi(this);
    _createConnects();
}

NewFileDialog::~NewFileDialog() {

}

void NewFileDialog::_createConnects() {
    connect(_ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(_ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(_ui->sizesList, SIGNAL(itemSelectionChanged()), this, SLOT(_onSizeChanged()));
}

void NewFileDialog::_onSizeChanged() {
    const QString text = _ui->sizesList->currentItem()->text();
    if (text == "16x16") {
        _result.size = QPoint(16, 16);
    }
    else if(text == "24x24") {
        _result.size = QPoint(24, 24);
    }
    else if(text == "32x32") {
        _result.size = QPoint(32, 32);
    }
    else if(text == "48x48") {
        _result.size = QPoint(48, 48);
    }
    else if(text == "64x64") {
        _result.size = QPoint(64, 64);
    }
    else if(text == "128x128") {
        _result.size = QPoint(128, 128);
    }
    else if(text == "256x256") {
        _result.size = QPoint(256, 256);
    }
}
