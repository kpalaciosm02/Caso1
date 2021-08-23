#include <iostream>
#include <string>
#include <typeinfo>
#include <bits/stdc++.h>

using namespace std;

struct Node{
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
        cout << frase << " -> ";
    }
};

struct LinkedList{
    Node * firstNode;

    LinkedList(){
        firstNode = NULL;
    }

    void insert(string _frase){
        if (firstNode == NULL)
            firstNode = new Node(_frase);
        else{
            Node * tmp = new Node(_frase);
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    void insertAtEnd(string _frase){
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
            cout << endl;
        }
    }

    void printList(){
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
};

/*void stringSplitter1(string frase){
    int inicio = 0;
    for (int i = 0; i<frase.size(); i++){
        if (frase[i] == ' '){
            cout << frase.substr(inicio, i) << endl;
            inicio = i+1;
        }
    }
}*/

void stringSplitter(string frase, LinkedList* wordList){
    istringstream ss(frase);
    string word;
    while (ss>>word){
        wordList->insertAtEnd(word);
        //cout << word << endl;
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
    string frase = "Esto es una prueba";
    string frase2 = "Vamos a probar esto de nuevo";
    stringSplitter(frase, words);
    stringSplitter(frase2, words);
    words->printList();
}