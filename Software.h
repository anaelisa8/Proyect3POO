/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
//Software.h
#include <iostream>
#include <string>
#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "Material.h"
using namespace std;

class Software:public Material{
  public:
  Software();
  Software(int idM, string t,int v,string s);
  void setVersion(int v);
  void setSO(string s);
  int getVersion();
  string getSO();
  void muestraDatos();
  int cantidadDiasPrestamo();

  private:
  int version;
  string SO;
};
Software::Software():Material(){
  version = 0;
  SO = "S/SO";
}
Software::Software(int idM, string t,int v,string s):Material(idM, t){
  version = v;
  SO = s;
}
void Software::setVersion(int v){
  version = v;
}
void Software::setSO(string s){
  SO = s;
}
int Software::getVersion(){
  return version;
}
string Software::getSO(){
  return SO;
}
void Software::muestraDatos(){
  cout<<"Material: Software"<<endl;
  cout<<"Id Material: "<<idMaterial<<endl;
  cout<<"Título: "<<titulo<<endl;
  cout<<"Versión: "<<version<<endl;
  cout<<"SO: "<<SO<<endl;
}
int Software::cantidadDiasPrestamo(){
  return 1;
}
#endif
