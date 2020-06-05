/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
//Libro.h
#include <iostream>
#include <string>
#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"
using namespace std;

class Libro:public Material{
  public:
  Libro();
  Libro(int idM, string t, int n, int au);
  void setNumPag(int n);
  void setAutor(string au);
  int getNumPag();
  string getAutor();
  void muestraDatos();
  int cantidadDiasPrestamo();

  private:
  int numPag;
  string autor;
};
Libro::Libro():Material(){
  numPag = 0;
  autor = "S/A";
}
Libro::Libro(int idM, string t, int n, int au):Material(idM, t){
  numPag = n;
  autor = au;
}
void Libro::setNumPag(int n){
  numPag = n;
}
void Libro::setAutor(string au){
  autor = au;
}
int Libro::getNumPag(){
  return numPag;
}
string Libro::getAutor(){
  return autor;
}
void Libro::muestraDatos(){
  cout<<"Material: Libro"<<endl;
  cout<<"Id Material: "<<idMaterial<<endl;
  cout<<"Título: "<<titulo<<endl;
  cout<<"Número de Páginas: "<<numPag<<endl;
  cout<<"Autor: "<<autor<<endl;
}
int Libro::cantidadDiasPrestamo(){
  return 7;
}
#endif
