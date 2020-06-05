/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include "Reserva.h"
#include "Disco.h"
#include "Libro.h"
#include "Software.h"

using namespace std;

int main() {
  //Declaración de arreglos
  Reserva arrRes[60];
  Material *arrMa[30];
  Disco arrD[30];
  Libro arrL[30];
  Software arrS[30];
  Fecha fecha,fecha2,fecha3;

  //Abrir archivos
  ifstream infoMa;
  infoMa.open("Material.txt");
  ifstream infoRe;
  infoRe.open("Reserva.txt");

  //Declaración variables
  string titulo,palabra,lineaMa, lineaRe;
  char letra;
  int k=0,dia,mes,anio,idMat,idCli,r=0,num,j=0,nL=0,nD=0,nS=0;

  //Leer datos de archivo material
  while(infoMa>>idMat>>titulo>>letra>>num>>palabra){
    switch(letra){
      case 'L':
      arrMa[nL] = &arrL[nL];
      arrMa[nL]->setIdMaterial(idMat);
      //cout<<arrMa[r]->getIdMaterial()<<"\t";
      arrMa[nL]->setTitulo(titulo);
      //cout<<arrMa[r]->getTitulo()<<"\t";
      arrL[nL].setNumPag(num);
      //cout<<arrL[r].getNumPag()<<"\t";
      arrL[nL].setAutor(palabra);
      //cout<<arrL[r].getAutor()<<endl;
      nL++;
      break;

      case 'D':
      arrMa[nD] = &arrD[nD];
      arrMa[nD]->setIdMaterial(idMat);
      //cout<<arrMa[r]->getIdMaterial()<<"\t";
      arrMa[nD]->setTitulo(titulo);
      //cout<<arrMa[r]->getTitulo()<<"\t";
      arrD[nD].setDuracion(num);
      //cout<<arrD[r].getDuracion()<<"\t";
      arrD[nD].setGenero(palabra);
      //cout<<arrD[r].getGenero()<<endl;
      nD++;
      break;

      case 'S':
      arrMa[nS] = &arrS[nS];
      arrMa[nS]->setIdMaterial(idMat);
      //cout<<arrMa[r]->getIdMaterial()<<"\t";
      arrMa[nS]->setTitulo(titulo);
      //cout<<arrMa[r]->getTitulo()<<"\t";
      arrS[nS].setVersion(num);
      //cout<<arrS[r].getVersion()<<"\t";
      arrS[nS].setSO(palabra);
      //cout<<arrS[r].getSO()<<endl;
      nS++;
      break;

      default:
      cout<<"Material no encontrado"<<endl;
      return 0;
    }
    r++;
  }
  
  //Verificar que se guarden
  /*for(int i=0;i<nL;i++){
    cout<<arrL[i].getIdMaterial()<<endl;
    arrL[i].muestraDatos();
    cout<<endl;
  }
  for(int i=0;i<nD;i++){
    arrD[i].muestraDatos();
    cout<<endl;
  }
  for(int i=0;i<nS;i++){
    arrS[i].muestraDatos();
    cout<<endl;
  }*/

  //Leer datos de archivo reserva
  while(infoRe>>dia>>mes>>anio>>idMat>>idCli){
    //Verificación fecha
    //cout<<dia<<"\t";
    //cout<<mes<<"\t";
    //cout<<anio<<"\t";
    //Carga datos en clase fecha
    fecha.setFecha(dia,mes,anio);
    //Carga datos en el archivo
    arrRes[k].setFechaReservacion(fecha);
    //Verificación idMaterial
    arrRes[k].setIdMaterial(idMat);
    //cout<<arrRes[k].getIdMaterial()<<"\t";
    //Verfificación idCliente
    arrRes[k].setIdCliente(idCli);
    //cout<<arrRes[k].getIdCliente()<<endl;
    k++;//Salta a la sig localidad del arrRe
  }

  char opcion;
  int id,idM,idC,idMaterial,valiMa;
  do{
    cout<<endl;
    cout<<"MENÚ"<<endl;
    cout<<"a. Consultar lista de Materiales"<<endl;
    cout<<"b. Consultar la lista de reservaciones"<<endl;
    cout<<"c. Consultar las reservaciones de un material dado"<<endl;
    cout<<"d. Consultar las reservaciones de una fecha dada"<<endl;
    cout<<"e. Hacer una reservación"<<endl;
    cout<<"f. Terminar"<<endl;
    
    cout<<endl; 
    cout<<"Teclea la letra de la opción deseada"<<"\t";
    cin>>opcion;
    opcion=tolower(opcion);
    int z=0,n=0,day,year,month;  

    switch(opcion){
      case 'a':
      cout<<endl;
      for(int i=0;i<nL;i++){
        arrL[i].muestraDatos();
        cout<<endl;
        }
      for(int i=0;i<nD;i++){
        arrD[i].muestraDatos();
        cout<<endl;
        }
      for(int i=0;i<nS;i++){
        arrS[i].muestraDatos();
        cout<<endl;
        }
      break;
      
      case 'b':
      cout<<endl;
      cout<<"F inicio"<<"\t"<<"F terminación"<<"\t"<<"Nombre"<<"\t"<<"\t"<<"\t"<<"IdCliente"<<endl;
      for(int i=0;i<k;i++){
        cout<<arrRes[i].getFechaReservacion()<<"\t";
        id = arrRes[i].getIdMaterial();
        for(int j=0;j<nL;j++){
          idM = arrL[j].getIdMaterial();
          if(id == idM){
            cout<<arrRes[i].calculaFechaFinReserva(7)<<"\t";
            cout<<arrL[j].getTitulo()<<"\t";
          }
        }
        for(int j=0;j<nD;j++){
          idM = arrD[j].getIdMaterial();
          if(id == idM){
            cout<<arrRes[i].calculaFechaFinReserva(2)<<"\t";
            cout<<arrD[j].getTitulo()<<"\t";
          }
        }
        for(int j=0;j<nS;j++){
          idM = arrS[j].getIdMaterial();
          if(id == idM){
            cout<<arrRes[i].calculaFechaFinReserva(1)<<"\t";
            cout<<arrS[j].getTitulo()<<"\t";
          }
        }
        cout<<arrRes[i].getIdCliente()<<endl;
      }
      break;

      case 'c':
      cout<<endl;
      do{
      cout<<"Teclea id del material"<<"\t";
      cin>>idMaterial;
      for(int j=0;j<nL;j++){
          idM = arrL[j].getIdMaterial();
          if(idMaterial == idM)
            n=1;
        }
      for(int j=0;j<nD;j++){
          idM = arrD[j].getIdMaterial();
          if(idMaterial == idM)
            n=1;
        }
      for(int j=0;j<nS;j++){
          idM = arrS[j].getIdMaterial();
          if(idMaterial == idM)
            n=1;
        }
      }while(n==0);
      cout<<"F inicio"<<"\t"<<"F terminación"<<"\t"<<"Nombre"<<"\t"<<"\t"<<"\t"<<"IdCliente"<<endl;
      for(int i=0;i<k;i++){
        idM = arrRes[i].getIdMaterial();
        fecha = arrRes[i].getFechaReservacion();
        if(idMaterial == idM){
          cout<<arrRes[i].getFechaReservacion()<<"\t";
          for(int j=0;j<nL;j++){
            idM = arrL[j].getIdMaterial();
            if(idMaterial == idM){
              cout<<arrRes[i].calculaFechaFinReserva(7)<<"\t";
              cout<<arrL[j].getTitulo()<<"\t";cout<<arrRes[i].getIdCliente()<<endl;
              z=1;
              }
          }
          for(int j=0;j<nD;j++){
            idM = arrD[j].getIdMaterial();
            if(idMaterial == idM){
              cout<<arrRes[i].calculaFechaFinReserva(2)<<"\t";
              cout<<arrD[j].getTitulo()<<"\t";
              cout<<arrRes[i].getIdCliente()<<endl;
              z=1;
            }
          }
          for(int j=0;j<nS;j++){
            idM = arrS[j].getIdMaterial();
            if(idMaterial == idM){
              cout<<arrRes[i].calculaFechaFinReserva(1)<<"\t";
              cout<<arrS[j].getTitulo()<<"\t";
              cout<<arrRes[i].getIdCliente()<<endl;
              z=1;
            }
          }
        }
      }
      if(z==0){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"El material no está reservado"<<endl;
        }
      break;

      case 'd':
      cout<<endl;
      cout<<"Ingrese fecha deseada:"<<endl;
      cin>>fecha2;
      for(int i=0;i<k;i++){
        fecha = arrRes[i].getFechaReservacion();
        id = arrRes[i].getIdMaterial();
        for(int j=0;j<nL;j++){
          idM = arrL[j].getIdMaterial();
          if(id == idM){
            fecha3 = arrRes[i].calculaFechaFinReserva(7);
          }
        }
        for(int j=0;j<nD;j++){
          idM = arrD[j].getIdMaterial();
          if(id == idM){
           fecha3 = arrRes[i].calculaFechaFinReserva(2);
          }
        }
        for(int j=0;j<nS;j++){
          idM = arrS[j].getIdMaterial();
          if(id == idM){
            fecha3 = arrRes[i].calculaFechaFinReserva(1);
          }
        }
        if((fecha2>=fecha) && (fecha2<=fecha3)){
          cout<<endl;
          cout<<"RESERVACIONES"<<endl;
          cout<<"Fecha"<<"\t"<<"\t"<<"Nombre"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"IdCliente"<<endl;
          cout<<fecha2<<"\t";
          for(int j=0;j<nL;j++){
            idM = arrL[j].getIdMaterial();
            if(id == idM)
              cout<<arrL[j].getTitulo()<<"\t";
          }
          for(int j=0;j<nD;j++){
            idM = arrD[j].getIdMaterial();
            if(id == idM)
              cout<<arrD[j].getTitulo()<<"\t";
          }
          for(int j=0;j<nS;j++){
            idM = arrS[j].getIdMaterial();
            if(id == idM)
              cout<<arrS[j].getTitulo()<<"\t";
          }
          cout<<arrRes[i].getIdCliente()<<endl;
          z=1;
        }
      }
      if(z==0){
        cout<<endl;
        cout<<"Fecha: "<<"\t"<<fecha2<<endl;
        cout<<"No hay nada reservado en fecha indicada "<<endl;
        }
      break;

      case 'e':
      cout<<endl;
      cout<<"Teclea id del cliente"<<"\t";
      cin>>idC;
      cout<<"Teclea la fecha que desea reservar"<<endl;
      cout<<"Dia: "<<"\t";
      cin>>day;
      cout<<"Mes: "<<"\t";
      cin>>month;
      cout<<"Anio: "<<"\t";
      cin>>year;
      fecha2.setFecha(day,month,year);
      do{
      cout<<"Teclea id del material"<<"\t";
      cin>>idMaterial;
      for(int j=0;j<nL;j++){
          idM = arrL[j].getIdMaterial();
          if(idMaterial == idM)
            n=1;
        }
      for(int j=0;j<nD;j++){
          idM = arrD[j].getIdMaterial();
          if(idMaterial == idM)
            n=1;
        }
      for(int j=0;j<nS;j++){
          idM = arrS[j].getIdMaterial();
          if(idMaterial == idM)
            n=1;
        }
      }while(n==0);
      for(int i=0;i<k;i++){
        id = arrRes[i].getIdMaterial();
        if(idMaterial == id){
          fecha = arrRes[i].getFechaReservacion();
          for(int j=0;j<nL;j++){
          idM = arrL[j].getIdMaterial();
          if(id == idM){
            fecha3 = arrRes[i].calculaFechaFinReserva(7);
          }
        }
        for(int j=0;j<nD;j++){
          idM = arrD[j].getIdMaterial();
          if(id == idM){
           fecha3 = arrRes[i].calculaFechaFinReserva(2);
          }
        }
        for(int j=0;j<nS;j++){
          idM = arrS[j].getIdMaterial();
          if(id == idM){
            fecha3 = arrRes[i].calculaFechaFinReserva(1);
          }
        }
        if((fecha2>=fecha) && (fecha2<=fecha3)){
          cout<<"Material reservado en fecha solicitada: "<<fecha2<<endl;
          cout<<"NO SE PUEDE HACER RESERVACIÓN"<<endl;
          z=1;
          }
      }
    }
      if(z==0){
        cout<<endl;
        cout<<"Fecha: "<<"\t"<<fecha2<<endl;
        cout<<"Material disponible en fecha indicada "<<endl;
        cout<<"RESERVACIÓN REALIZADA"<<endl;
        ofstream infoReSalida;
        infoReSalida.open("Reserva.txt",ios::app);
        infoReSalida<<day<<" "<<month<<" "<<year<<" "<<idMaterial<<" "<<idC<<endl;
        infoReSalida.close();
        }
      break;

      case 'f':
      cout<<endl;
      cout<<"PROGRAMA TERMINADO"<<endl;
      break;

      default:
      cout<<endl;
      cout<<"NO EXISTE LA OPCIÓN SELECCIONADA"<<endl;
    }
  }while(opcion != 'f');

  infoMa.close();
  infoRe.close();

  return 0;
}