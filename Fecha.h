/*
    Programación Orientada a Objetos
    PROYECTO 3
    Ana Elisa Estrada Lugo
    A01251091
    05/06/2020
*/
//Fecha.h
#include <iostream>
#include <string>
#ifndef FECHA_H
#define FECHA_H
using namespace std;

class Fecha {
  public:
  Fecha();
  Fecha(int d,int m,int a);
  int getDd();
  int getMm();
  int getAa();
  void setFecha(int d, int m, int a);
  Fecha operator+(int c);
  bool operator>=(Fecha f);
  bool operator<=(Fecha f);
  bool operator>(Fecha f);
  bool operator<(Fecha f);
  bool operator==(Fecha f);
  friend istream &operator >> (istream &is, Fecha &f);
  friend ostream &operator << (ostream &os, Fecha f);
  string nombreMes();

  private:
  int dd,mm,aa;
};
Fecha::Fecha(){
  dd = 0;
  mm = 0;
  aa = 0;
}
Fecha::Fecha(int d,int m,int a){
  dd = d;
  mm = m;
  aa = a;
}
int Fecha::getDd(){
  return dd;
}
int Fecha::getMm(){
  return mm;
}
int Fecha::getAa(){
  return aa;
}
void Fecha::setFecha(int d, int m, int a){
  dd = d;
  mm = m;
  aa = a;
}
string Fecha::nombreMes(){
  switch(mm){
    case 1:
    return "Ene";
    break;

    case 2:
    return "Feb";
    break;

    case 3:
    return "Mar";
    break;

    case 4:
    return "Abr";
    break;

    case 5:
    return "May";
    break;

    case 6:
    return "Jun";
    break;

    case 7:
    return "Jul";
    break;

    case 8:
    return "Ago";
    break;

    case 9:
    return "Sep";
    break;

    case 10:
    return "Oct";
    break;

    case 11:
    return "Nov";
    break;

    case 12:
    return "Dic";
    break;

    default:
    return "Mes incorrecto";
  }
}
Fecha Fecha::operator+(int c){
    int diaN = this -> dd;
    int mesN = this -> mm;
    int anioN = this -> aa;
    int suma;
    if ((mesN % 2 != 0)&&(mesN <= 7)){
        if (diaN == 31){
            diaN = 0;
            diaN += c;
            mesN++;
        }
        else{
            suma = diaN + c;
            if (suma>31){
                suma -= 31;
                mesN++;
                diaN = suma;
            }
            else
                diaN = suma;
        }
    }
    else if ((mesN % 2 == 0)&&(mesN == 8 || mesN == 10)){
        if (diaN == 31){
            diaN = 0;
            diaN += c;
            mesN++;
        }
        else{
            suma = diaN + c;
            if (suma>31){
                suma -= 31;
                mesN++;
                diaN = suma;
            }
            else
                diaN = suma;
        }
    }
    else if (mesN == 12){
        if (diaN == 31){
            diaN = 0;
            diaN += c;
            mesN = 1;
            anioN++;
        }
        else{
            suma = diaN + c;
            if (suma>31){
                suma -= 31;
                mesN++;
                diaN = suma;
                anioN++;
            }
            else
                diaN = suma;
        }
    }
    else if ((mesN % 2 == 0) && (mesN <= 6 && mesN > 2)){
        if (diaN == 30){
            diaN = 0;
            diaN += c;
            mesN++;
        }
        else{
            suma = diaN + c;
            if (suma>30){
                suma -= 30;
                mesN++;
                diaN = suma;
            }
            else
                diaN = suma;
        }
    }
    else if ((mesN % 2 != 0) && (mesN == 9 || mesN == 11)){
        if (diaN == 30){
            diaN = 0;
            diaN += c;
            mesN++;
        }
        else{
            suma = diaN + c;
            if (suma>30){
                suma -= 30;
                mesN++;
                diaN = suma;
            }
            else
                diaN = suma;
        }
    }
    else if(mesN == 2){
      if(diaN == 28){
        diaN = 0;
        diaN += c;
        mesN++;
      }
      else{
        suma = diaN + c;
        if (suma>28){
          suma -= 28;
          mesN++;
          diaN = suma;
        }
        else
          diaN = suma;

      }
    }
    Fecha nuevaF (diaN, mesN, anioN);
    return nuevaF;
}

bool Fecha::operator>=(Fecha f){
    if (aa > f.aa)
        return true;
    else if (aa == f.aa){
        if (mm > f.mm)
            return true;
        else if (mm == f.mm){
            if (dd > f.dd)
                return true;
            else if (dd == f.dd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator<=(Fecha f){
    if (aa < f.aa)
        return true;
    else if (aa == f.aa){
        if (mm < f.mm)
            return true;
        else if (mm == f.mm){
            if (dd < f.dd)
                return true;
            else if (dd == f.dd)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator>(Fecha f){
    if (aa > f.aa)
        return true;
    else if (aa == f.aa){
        if (mm > f.mm)
            return true;
        else if (mm == f.mm){
            if (dd > f.dd)
                return true;
            else if (dd == f.dd)
                return false;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator<(Fecha f){
    if (aa < f.aa)
        return true;
    else if (aa == f.aa){
        if (mm < f.mm)
            return true;
        else if (mm == f.mm){
            if (dd < f.dd)
                return true;
            else if (dd == f.dd)
                return false;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Fecha::operator==(Fecha f){
    if ((aa == f.aa) && (mm == f.mm) && (dd == f.dd))
        return true;
    else
        return false;
}

ostream &operator << (ostream &os, Fecha f) {
    os << f.dd << "/" << f.nombreMes() << "/" << f.aa;
    return os;
}

istream &operator >> (istream &is, Fecha &f) {
    cout << "Dia: ";
    is >> f.dd;
    cout << "Mes: ";
    is >> f.mm;
    cout << "Anio: ";
    is >> f.aa;
    return is;
}
#endif