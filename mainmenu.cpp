#include <QDebug>
#include "mainmenu.h"
#include "./ui_mainmenu.h"
#include "shutdown.h"
#include "global.h"

Shutdown* shutdown;

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::on_pushButton_clicked() {
    if (!shutdown) {
        shutdown = new Shutdown(this, SHUTDOWN);
        shutdown->setWindowTitle("Shutdown Timer");
        shutdown->show();
    }
}

void MainMenu::on_pushButton_2_clicked() {
    if (!shutdown) {
        shutdown = new Shutdown(this, RESTART);
        shutdown->setWindowTitle("Restart Timer");
        shutdown->show();
    }
}

void MainMenu::on_pushButton_3_clicked() {
    std::system("shutdown /a");
}
