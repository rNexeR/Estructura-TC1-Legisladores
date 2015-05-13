#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QMainWindow>
#include "Conjunto.h"
#include <vector>
#include <QMessageBox>

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = 0);
    ~MenuPrincipal();

private slots:
    void on_CrearLeg_clicked();

    void on_CrearLey_clicked();

    void on_AprobarLey_clicked();

    void on_ComprobarMiembrp_clicked();

    void fillLeyes();
    void fillLegisladores();
    void fillAll();

private:
    Ui::MenuPrincipal *ui;
    Conjunto buenos, malos;
    vector<Ley> leyes;
};

#endif // MENUPRINCIPAL_H
