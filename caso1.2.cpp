//Ejercicio 2 del caso 1

#include <string>
#include <iostream>

using namespace std;

struct excelBox{
    int dato;
    string ejeX;
    int ejeY;

    excelBox(){
        dato = 0;
        ejeX = "";
        ejeY = 0;
    }

    excelBox(int _dato, string _ejeX, int _ejeY){
        dato = _dato;
        ejeX = _ejeX;
        ejeY = _ejeY;
    }

    void printData(){
        cout << "Coordenada x: " << ejeX << " Coordenada y: " << ejeY << " Dato: " << dato << endl;
    }
};

struct Node{
    excelBox datos = excelBox();
    Node * next;

    Node(int _dato, string _ejeX, int _ejeY){
        datos.dato = _dato;
        datos.ejeX = _ejeX;
        datos.ejeY = _ejeY;
        next = NULL;
    }

};

int main(){

    return 0;
}