/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
//Material.h
#include <iostream>
#include <string>
#ifndef MATERIAL_H
#define MATERIAL_H
using namespace std;

class Material{
  public:
  Material();
  Material(int idM, string t);
  void setIdMaterial(int idM);
  void setTitulo(string t);
  int getIdMaterial();
  string getTitulo();
  virtual void muestraDatos()=0;
  virtual int cantidadDiasPrestamo()=0;

  protected:
  int idMaterial;
  string titulo;
};
Material::Material(){
  idMaterial = 0;
  titulo = "S/T";
}
Material::Material(int idM,string t){
  idMaterial = idM;
  titulo = t;
}
void Material::setIdMaterial(int idM){
  idMaterial = idM;
}
void Material::setTitulo(string t){
  titulo = t;
}
int Material::getIdMaterial(){
  return idMaterial;
}
string Material::getTitulo(){
  return titulo;
}
void Material::muestraDatos(){
  cout<<"Id Material: "<<idMaterial<<endl;
  cout<<"Título: "<<titulo<<endl;
}
#endif
