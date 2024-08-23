#include <QDebug>
#include <sstream>
#include "shutdown.h"
#include "./ui_shutdown.h"
#include "global.h"

Shutdown::Shutdown(QWidget *parent, enum Action input): QDialog(parent), ui(new Ui::Shutdown) {
    ui->setupUi(this);
    action = input;
}

Shutdown::~Shutdown() {
    delete ui;
}

int Shutdown::time() {
    QString input = ui->textEdit->toPlainText();
    if (input == "") {
        input = "0";
    }
    std::string inputSTD = input.toStdString();
    try {
        double timeDouble = std::stod(inputSTD);
        if (timeDouble < 0) {
            timeDouble = 0;
        }
        int timeInt;
        if (ui->comboBox->currentText() == "Hours") {
            timeInt = static_cast<int>(timeDouble * 3600);
        } else if (ui->comboBox->currentText() == "Minutes") {
            timeInt = static_cast<int>(timeDouble * 60);
        } else {
            timeInt = static_cast<int>(timeDouble);
        }
        return timeInt;
    } catch (int e) {
        return 0;
    }
}

void Shutdown::on_pushButton_clicked() {
   if (action == SHUTDOWN) {
        std::string result = std::to_string(time());
        std::stringstream shutdownCommand;
        shutdownCommand << "shutdown /s /t " << result;
        std::system(shutdownCommand.str().c_str());
    }
    else if (action == RESTART) {
        std::string result = std::to_string(time());
        std::stringstream shutdownCommand;
        shutdownCommand << "shutdown /r /t " << result;
        std::system(shutdownCommand.str().c_str());
    }
    this->close();
    shutdown = nullptr;
}


void Shutdown::on_pushButton_2_clicked() {
    this->close();
    shutdown = nullptr;
}

void Shutdown::on_Shutdown_rejected() {
    shutdown = nullptr;
}

