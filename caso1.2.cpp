//Ejercicio 2 del caso 1

#include <string>
#include <iostream>

using namespace std;

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
                    break;
                }
                else{
                    tmp = tmp->next;
                }
            }
        }
    }

    void insertData(int _dato, string _ejeX, int _ejeY){
        //Insertar al inicio un nodo nuevo con datos nuevos
        Node * _node = new Node(_dato, _ejeX, _ejeY);
        if (firstNode == NULL){
            firstNode = _node;
        }
        else{
            _node->next = firstNode;
            firstNode = _node;
        }
    }

    void insertDataEnd(int _dato, string _ejeX, int _ejeY){
        //Insertar al final un nodo nuevo con datos nuevos
        Node * _node = new Node(_dato, _ejeX, _ejeY);
        if (firstNode == NULL){
            firstNode = _node;
        }
        else{
            Node * tmp = firstNode;
            while (tmp != NULL){
                if (tmp->next == NULL){
                    tmp->next = _node;
                    break;
                }
                else{
                    tmp = tmp->next;
                }
            }
        }
    }
};

int main(){
    //Terminar de crear la lista de casillas
    //Hacer un algoritmo que reciba una lista de casillas y una lista de coordenadas que sumar y realice la suma
    excelBox * casilla = new excelBox(2,"B",3);
    cout << "Dato: " << casilla->dato << endl;
    cout << "Coordinada x: " << casilla->ejeX << endl;
    cout << "Coordinada y: " << casilla->ejeY << endl;
    return 0;
}