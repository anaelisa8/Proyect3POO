/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
//Reserva.h
#include <iostream>
#include <string>
#ifndef RESERVA_H
#define RESERVA_H
#include "Fecha.h"
#include "Material.h"
using namespace std;

class Reserva{
  public:
  Reserva();
  Reserva(int iM,int iC,Fecha f);
  void setIdMaterial(int iM);
  void setIdCliente(int iC);
  void setFechaReservacion(Fecha f);
  int getIdMaterial();
  int getIdCliente();
  Fecha getFechaReservacion();
  Fecha calculaFechaFinReserva(int cantDias);

  private:
  int idMaterial,idCliente;
  Fecha fechaReservacion;
};
Reserva::Reserva(){
  Fecha fe(0,0,0);
  idMaterial = 0;
  idCliente = 0;
  fechaReservacion = fe;
}
Reserva::Reserva(int iM,int iC,Fecha f){
  idMaterial = iM;
  idCliente = iC;
  fechaReservacion = f;
}
void Reserva::setIdMaterial(int iM){
  idMaterial = iM;
}
void Reserva::setIdCliente(int iC){
  idCliente = iC;
}
void Reserva::setFechaReservacion(Fecha f){
  fechaReservacion = f;
}
int Reserva::getIdMaterial(){
  return idMaterial;
}
int Reserva::getIdCliente(){
  return idCliente;
}
Fecha Reserva::getFechaReservacion(){
  return fechaReservacion;
}
Fecha Reserva::calculaFechaFinReserva(int cantDias){
  return fechaReservacion + cantDias;
}
#endif