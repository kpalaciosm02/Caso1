#include <iostream>
#include <string>
#include <typeinfo>
#include <bits/stdc++.h>
#include <algorithm>

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
        }
    }

    int countWord(string _frase){
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

    void printHalfList(){
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
    istringstream ss(frase);
    string word;
    while (ss>>word){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordList->insertAtEnd(word);
    }
}

void twoStringDetector(string frase1, string frase2){
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

int main(){
    /*Node * nodo = new Node();
    nodo->frase = "Hola";
    nodo->printData();*/

    /*LinkedList * lista = new LinkedList();
    lista->insert("Hola");
    lista->insert("Hola2");
    lista->insertAtEnd("Hola3");   
    lista->printList();*/

    //LinkedList * words = new LinkedList();
    string frase = "Esto es una prueba";
    string frase2 = "Vamos a probar esto de una vez";
    //stringSplitter(frase, words);
    //stringSplitter(frase2, words);
    //words->printList();
    //words->printHalfList();
    //cout << "Cantidad de 'esto': " << words->countWord("esto");
    twoStringDetector(frase,frase2);
    //cout << "Largo: " << words->listLarge() << endl;
}