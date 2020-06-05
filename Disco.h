/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
//Disco.h
#include <iostream>
#include <string>
#ifndef DISCO_H
#define DISCO_H
#include "Material.h"
using namespace std;

class Disco:public Material{
  public:
  Disco();
  Disco(int idM, string t, int du,string g);
  void setDuracion(int du);
  void setGenero(string g);
  int getDuracion();
  string getGenero();
  void muestraDatos();
  int cantidadDiasPrestamo();

  private:
  int duracion;
  string genero;
};
Disco::Disco():Material(){
  duracion = 0;
  genero = "S/N";
}
Disco::Disco(int idM, string t, int du,string g):Material(idM, t){
  duracion = du;
  genero = g;
}
void Disco::setDuracion(int du){
  duracion = du;
}
void Disco::setGenero(string g){
  genero = g;
}
int Disco::getDuracion(){
  return duracion;
}
string Disco::getGenero(){
  return genero;
}
void Disco::muestraDatos(){
  cout<<"Material: Disco"<<endl;
  cout<<"Id Material: "<<idMaterial<<endl;
  cout<<"Título: "<<titulo<<endl;
  cout<<"Duración: "<<duracion<<endl;
  cout<<"Genero: "<<genero<<endl;
}
int Disco::cantidadDiasPrestamo(){
  return 2;
}
#endif