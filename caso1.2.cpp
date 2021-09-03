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
    excelBox * datos = new excelBox();
    Node * next;

    Node(int _dato, string _ejeX, int _ejeY){
        //Constructor con los datos en la entrada
        datos = new excelBox(_dato, _ejeX, _ejeY);
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
        insertNode(_node);
    }

    void insertDataEnd(int _dato, string _ejeX, int _ejeY){
        //Insertar al final un nodo nuevo con datos nuevos
        Node * _node = new Node(_dato, _ejeX, _ejeY);
        insertNodeAtEnd(_node);
    }

    void printList(){
        if (firstNode == NULL){
            cout << "Lista vacia" << endl;
        }
        else{
            Node * tmp = firstNode;
            while(tmp != NULL){
                cout << "Coordenada x: " << tmp->datos->ejeX << " Coordenada y: " << tmp->datos->ejeY << " Dato: " << tmp->datos->dato << endl;
                tmp = tmp->next;
            }
        }
    }
};

struct coordenadas{
    string ejeX;
    int ejeY;

    coordenadas(){
        ejeX = "";
        ejeY = 0;
    }

    coordenadas(string _ejeX, int _ejeY){
        ejeX = _ejeX;
        ejeY = _ejeY;
    }

    void printCoords(){
        cout << "Eje x: " << ejeX << " Eje y: " << ejeY << endl;
    }
};

struct coordsNode{
    coordenadas * coords = new coordenadas();
    coordsNode * next;

    coordsNode(string _ejeX, int _ejeY){
        coords = new coordenadas(_ejeX, _ejeY);
        next = NULL;
    }
};

struct coordsList{
    coordsNode * firstNode;

    void insertNode(coordsNode * _node){
        if (firstNode == NULL){
            firstNode = _node;
        }
        else{
            _node->next = firstNode;
            firstNode = _node;
        }
    }

    void insertNodeEnd(coordsNode * _node){
        if (firstNode == NULL){
            firstNode = _node;
        }
        else{
            coordsNode * tmp = _node;
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

    void insertData(string _ejeX, int _ejeY){
        coordsNode * _node = new coordsNode(_ejeX,_ejeY);
        insertNode(_node);
    }

    void insertDataEnd(string _ejeX, int _ejeY){
        coordsNode * _node = new coordsNode(_ejeX, _ejeY);
        insertNodeEnd(_node);
    }

    void printList(){
        if (firstNode == NULL){
            cout << "Lista vacia" << endl;
        }
        else{
            coordsNode * tmp = firstNode;
            while (tmp != NULL){
                tmp->coords->printCoords();
                tmp = tmp->next;
            }
        }
    }
};

void addCoincidences(excelList * tablero, coordsList * coords){
    int res = 0;
    
    Node * actualNode = tablero->firstNode;
    while (actualNode != NULL){
        coordsNode * actualCoord = coords->firstNode;
        string xTablero = actualNode->datos->ejeX;
        int yTablero = actualNode->datos->ejeY;
        while (actualCoord != NULL){
            string xNode = actualCoord->coords->ejeX;
            int yNode = actualCoord->coords->ejeY;
            if (xTablero == xNode && yTablero == yNode){
                res += actualNode->datos->dato;
                actualCoord = actualCoord->next;
            }
            else{
                actualCoord = actualCoord->next;
                continue;
            } 
        }
        actualNode = actualNode->next;
    }
    cout << "Coincidencias: " << res << endl;
}

int main(){
    //Terminar de crear la lista de casillas
    //Hacer un algoritmo que reciba una lista de casillas y una lista de coordenadas que sumar y realice la suma
    excelBox * casilla1 = new excelBox(2,"B",3);
    cout << "Dato: " << casilla1->dato << endl;
    cout << "Coordinada x: " << casilla1->ejeX << endl;
    cout << "Coordinada y: " << casilla1->ejeY << endl;

    Node * nodo1 = new Node(2,"B",3);
    //cout << nodo1->datos->ejeY;

    excelList * list = new excelList();
    list->insertDataEnd(1,"C",5);
    list->insertNodeAtEnd(nodo1);
    list->insertDataEnd(3,"A", 3);
    list->printList();
    
    cout << endl << endl;
    coordsList * coords = new coordsList();
    coords->insertDataEnd("A",3);
    coords->insertData("C", 5);
    coords->printList();

    addCoincidences(list,coords);
    return 0;
}