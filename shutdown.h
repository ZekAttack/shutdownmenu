#ifndef SHUTDOWN_H
#define SHUTDOWN_H

#include <QDialog>
#include <cstdlib>

enum Action {
    DEFAULT, SHUTDOWN, RESTART
};

namespace Ui {
    class Shutdown;
}

class Shutdown : public QDialog {
    Q_OBJECT

public:
    explicit Shutdown(QWidget *parent = nullptr, enum Action = DEFAULT);
    ~Shutdown();

private slots:
    int time();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Shutdown_rejected();

private:
    Ui::Shutdown *ui;
    Action action;
};

#endif // SHUTDOWN_H
