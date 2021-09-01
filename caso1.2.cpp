//Ejercicio 2 del caso 1

#include <string>
#include <iostream>

using namespace std;

#define MAXIMO_CASILLAS 75

struct excelBox{
    //Casilla de excel con datos y coordenadas
    int dato;
    string ejeX;
    int ejeY;

    excelBox(){
        //Constructor vacío
        dato = 0;
        ejeX = "";
        ejeY = 0;
    }

    excelBox(int _dato, string _ejeX, int _ejeY){
        //constructor con datos
        dato = _dato;
        ejeX = _ejeX;
        ejeY = _ejeY;
    }

    void printData(){
        //Imprime los datos de una casilla
        cout << "Coordenada x: " << ejeX << " Coordenada y: " << ejeY << " Dato: " << dato << endl;
    }
};

struct Node{
    //Nodeo de una lista de casillas
    excelBox datos = excelBox();
    Node * next;

    Node(int _dato, string _ejeX, int _ejeY){
        //Constructor con los datos en la entrada
        datos.dato = _dato;
        datos.ejeX = _ejeX;
        datos.ejeY = _ejeY;
        next = NULL;
    }

};

struct excelList{
    //Lista de casillas de excel
    Node * firstNode;

    excelList(){
        //Constructor vacío
        firstNode = NULL;
    }

    void insertNode(Node * _node){
        //Insertar al inicio un nodo prehecho
        if (firstNode == NULL){
            firstNode = _node;
        }
        else{
            Node * tmp = _node;
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    void insertNodeAtEnd(Node * _node){
        //Insertar al final un nodo prehecho
        if (firstNode == NULL){
            firstNode = _node;
        }
        else{
            Node * tmp = firstNode;
            while (tmp != NULL){
                if (tmp->next == NULL){
                    tmp->next = _node;
                }
                else{
                    tmp = tmp->next;
                }
            }
        }
    }

};

int main(){
    /*excelBox lista[MAXIMO_CASILLAS];
    int lista3[5];
    lista3[0] = 5;
    cout << "Lista 3: " << lista3[0] << endl;*/
    //Terminar de crear la lista de casillas
    //Hacer un algoritmo que reciba una lista de casillas y una lista de coordenadas que sumar y realice la suma
    return 0;
}