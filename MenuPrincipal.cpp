#include "MenuPrincipal.h"
#include "ui_MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

void MenuPrincipal::fillLeyes(){
    ui->cmbLey->clear();
    for(int x = 0; x < leyes.size(); x++){
        ui->cmbLey->addItem(leyes[x].descripcion);
    }
}

void MenuPrincipal::fillLegisladores(){
    ui->cmbLegislador1->clear();
    Legislador* actual = buenos.inicio;
    while(actual){
        ui->cmbLegislador1->addItem(QString::number(actual->nombre));
        ui->cmbLegislador2->addItem(QString::number(actual->nombre));
        actual = actual->sig;
    }

    actual = malos.inicio;
    while(actual){
        ui->cmbLegislador1->addItem(QString::number(actual->nombre));
        ui->cmbLegislador2->addItem(QString::number(actual->nombre));
        actual = actual->sig;
    }
}

void MenuPrincipal::fillAll(){

}

void MenuPrincipal::on_CrearLeg_clicked()
{
    QMessageBox msg;
    msg.setWindowTitle("Creacion de Legislador");
    msg.setText("Accion Fallida");
    QString name = ui->txtNombre->text();
    ui->txtNombre->setText("");
    if(name != ""){
        if(buenos.insertar(name.toInt())){
            msg.setText("Accion Exitosa");
            fillLegisladores();
        }
    }
    msg.exec();
}

void MenuPrincipal::on_CrearLey_clicked()
{
    QMessageBox msg;
    msg.setWindowTitle("Creacion de Ley");
    msg.setText("Accion Fallida");

    QString desc = ui->txtDesc->text();
    bool good = ui->check->isChecked();

    ui->txtDesc->setText("");
    ui->check->setChecked(false);

    if(desc != ""){
        leyes.push_back(Ley(desc, good));
        msg.setText("Accion Exitosa");
        fillLeyes();
    }
    msg.exec();
}

void MenuPrincipal::on_AprobarLey_clicked()
{
    QMessageBox msg;
    msg.setWindowTitle("Aprobar Ley");

    QString ley = ui->cmbLey->currentText();
    int num = ui->cmbLey->currentIndex();

    int leg = ui->cmbLegislador1->currentText().toInt();

    if(leyes[num].buena == true){
        if(!buenos.esMiembro(leg)){
            buenos.insertar(leg);
            malos.suprimir(leg);
        }
    }else{
        if(!malos.esMiembro(leg)){
            malos.insertar(leg);
            buenos.suprimir(leg);
        }
    }

    msg.setText("Ley Aprobada");
    msg.exec();
}

void MenuPrincipal::on_ComprobarMiembrp_clicked()
{
    int leg = ui->cmbLegislador1->currentText().toInt();
    QString conjunto = ui->cmbConjunto->currentText();
    QMessageBox msg;
    msg.setWindowTitle("Es Miembro?");

    if (conjunto == "Buenos"){
        if(buenos.esMiembro(leg))
            msg.setText("VERDADERO");
        else
            msg.setText("FALSO");
    }else{
        if(malos.esMiembro(leg))
            msg.setText("VERDADERO");
        else
            msg.setText("FALSO");
    }
    msg.exec();
}
