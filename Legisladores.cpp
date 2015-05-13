#include "Legisladores.h"
#include "ui_Legisladores.h"

Legisladores::Legisladores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Legisladores)
{
    ui->setupUi(this);
}

Legisladores::~Legisladores()
{
    delete ui;
}
