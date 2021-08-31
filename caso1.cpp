#include <iostream>
#include <string>
#include <typeinfo>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct Node{
    /*
    Nodo de una lista enlazada de strings
    */

    string frase;
    Node* next;

    Node(){
        frase = "";
        next = NULL;
    }

    Node(string _frase){
        frase = _frase;
        next = NULL;
    }

    Node(string _frase, Node * _next){
        frase = _frase;
        next = _next;
    }

    void printData (){
        //Imprime la informacion de un nodo en pantalla
        cout << frase << " -> ";
    }

    void printCleanData(){
        cout << frase <<  " ";
    }

};

struct LinkedList{
    //Lista enlazada
    Node * firstNode;

    LinkedList(){
        firstNode = NULL;
    }

    void insert(string _frase){
        //Inserta un string al inicio de una lista enlazada
        if (firstNode == NULL)
            firstNode = new Node(_frase);
        else{
            Node * tmp = new Node(_frase);
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    void insertAtEnd(string _frase){
        //Inserta un string al final de una lista enlazada
        if (firstNode == NULL)
            firstNode = new Node(_frase);
        else{
            Node * tmp = firstNode;
            while(tmp != NULL){
                if (tmp->next != NULL){
                    tmp = tmp->next;
                }
                else{
                    tmp->next = new Node(_frase);
                    break;
                }
            }
        }
    }

    int countWord(string _frase){
        //Cuenta cuantas veces se repite un string dentro de la lista
        int counter = 0;
        if (firstNode == NULL)
            return 0;
        else{
            Node * tmp = firstNode;
            while(tmp != NULL){
                int res = tmp->frase.compare(_frase);
                if (res == 0){
                    counter += 1;
                    tmp = tmp->next;
                }
                else{
                    tmp = tmp->next;
                }
            }
            return counter;
        }
    }

    int listLarge(){
        //Retorna el largo de la lista
        if (firstNode == NULL){
            return 0;
        }
        else{
            int large = 0;
            Node * tmp = firstNode;
            while (tmp != NULL){
                large += 1;
                tmp = tmp->next;
            }
            return large;
        }
    }

    void printList(){
        //Imprime todos los datos de la lista, del primero al ultimo
        if (firstNode == NULL){
            cout << "Lista vacía" << endl;
        }
        else{
            Node * tmp = firstNode;
            while(tmp != NULL){
                tmp->printData();
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void printCleanList(){
        //Imprime los datos de la lista del primero al ultimo sin "->"
        if (firstNode == NULL){
            cout << "Lista vacía" << endl;
        }
        else{
            Node * tmp = firstNode;
            while(tmp != NULL){
                tmp->printCleanData();
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void printHalfList(){
        //Imprime la primera mitad de la lista
        if (firstNode == NULL){
            cout << "Lista vacía" << endl;
        }
        else{
            int large = listLarge()/2;
            Node * tmp = firstNode;
            int actual = 1;
            while (actual <= large){
                cout << tmp->frase << " -> ";
                tmp = tmp->next;
                actual += 1;
            }
            cout  << endl;
        }
    }
};

void stringSplitter(string frase, LinkedList* wordList){
    //recibe un string y una lista
    //separa el string en palabras y las inserta una por una en la lista
    istringstream ss(frase);
    string word;
    while (ss>>word){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordList->insertAtEnd(word);
    }
}

void twoStringDetector(string frase1, string frase2){
    //revisa si una palabra se repite mas de una vez entre 2 strings
    //no sirve en este caso porque si una palabra esta dos veces en un string, daria lo mismo a si esta 1 vez en cada string
    LinkedList * words = new LinkedList();
    stringSplitter(frase1, words);
    stringSplitter(frase2, words);
    Node * actualNode = words->firstNode;
    LinkedList * repited = new LinkedList();
    while (actualNode != NULL){
        string frase = actualNode->frase;
        if (words->countWord(frase) > 1){
            repited->insert(frase);
            actualNode = actualNode->next;
        }
        else{
            actualNode = actualNode->next;
        }
    }
    repited->printHalfList();
}

bool stringCheck(string word, LinkedList * list){
    //revisa si un string esta dentro de una lista
    Node * actual = list->firstNode;
    if (actual == NULL){
        return false;
    }
    else{
        while (actual != NULL){
            if (actual->frase == word){
                return true;
            }
            else{
                actual = actual->next;
            }
        }
        return false;
    }
}

LinkedList * stringInTwoLists(string frase1, string frase2){
    LinkedList * words1 = new LinkedList();
    LinkedList * words2 = new LinkedList();
    LinkedList * repited = new LinkedList();
    stringSplitter(frase1, words1);
    stringSplitter(frase2, words2);
    Node * words1First = words1->firstNode;
    while (words1First != NULL){
        bool check = stringCheck(words1First->frase, words2);
        if (check == true){
            repited->insert(words1First->frase);
            words1First = words1First->next;
        }
        else{
            words1First = words1First->next;
        }
    }
    return repited;
}

void coincidenceSearcher(LinkedList * frases){
    Node * firstNode = frases->firstNode;
    
    if (firstNode == NULL){
        cout << "Lista vacia" << endl;
    }
    else{
        while (firstNode->next != NULL){
            Node * secondNode = firstNode->next;
            string frase1 = firstNode->frase;
            while (secondNode != NULL){
                string frase2 = secondNode->frase;
                //cout << frase1 << endl;
                //cout << frase2 << endl;
                LinkedList * repited = stringInTwoLists(frase1, frase2);
                if (repited->firstNode != NULL){
                    cout << frase1 << " , " << frase2 << " -> ";
                    repited->printCleanList();
                }
                secondNode = secondNode->next;
            }
            firstNode = firstNode->next;
        }
    }
}

int main(){
    /*Node * nodo = new Node();
    nodo->frase = "Hola";
    nodo->printData();*/

    /*LinkedList * lista = new LinkedList();
    lista->insert("Hola");
    lista->insert("Hola2");
    lista->insertAtEnd("Hola3");   
    lista->printList();*/

    LinkedList * words = new LinkedList();
    string frase1 = "estoy escribiendo la tarea";
    string frase2 = "mañana voy en carro";
    string frase3 = "estoy en el carro escribiendo la poesía";
    string frase4 = "voy mañana a ver la tarea";
    LinkedList * frases = new LinkedList();
    frases->insertAtEnd(frase1);
    frases->insertAtEnd(frase2);
    frases->insertAtEnd(frase3);
    frases->insertAtEnd(frase4);
    coincidenceSearcher(frases);
}