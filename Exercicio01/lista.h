#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data);
};

template <typename T>
Node<T>::Node(T data){
        this->data = data;
        this->next = nullptr;
};

template <typename T>
class Lista
{
public:
    Node<T> *head;
    int index;

    Lista();
    Lista(T data);
    void Print();
    void Insert(T data, int index);
    void Remove(int index);
    T Search(int index);
};

template <typename T>
Lista<T>::Lista(){
    this->head = nullptr;
    this->index = 0;
}

template <typename T>
Lista<T>::Lista(T data){
    this-> head = new Node<T>(data);
    this-> index = 1;
}

template <typename T>
void Lista<T>::Print(){
    Node<T> *aux = head;

    for (size_t i = 0; i < index; i++)
    {
        cout<<aux->data<<endl;
        aux=aux->next;
    }
    
}


//(i) inserir um valor em uma posição específica; 

template <typename T>
void Lista<T>::Insert(T data, int index){

    if (index < this->index<0 || index > this->index+1)
    {
         throw out_of_range("ERRO DE TAMANHO");
    }
    

    Node<T> *newNode = new Node<T>(data);

    if (this->index==0){

    this-> head = new Node<T>(data);
    this-> index++;

    }else 
    if (index==0){
    
    Node<T> *aux = head;
    this-> head = new Node<T>(data);
    head->next=aux;
    this-> index++;

    }
    else{

    Node<T> *aux = head;

    for (size_t i = 0; i < index-1; i++)
    {
        aux = aux->next;
    }

    newNode->next=aux->next;
    aux->next=newNode;

    this->index++;

    }


}


//(ii) remover uma posição específica;
template <typename T>
void Lista<T>::Remove(int index){

    if (index < this->index<0 || index > this->index+1)
    {
         throw out_of_range("ERRO DE TAMANHO");
    }
    


    if (this->index==0){

    cout<<"Lista vazia";

    }else 
    if (index==0){
    
    head=head->next;
    this-> index--;

    }else 
    if (index==1){
    
    head->next=head->next->next;
    this-> index--;

    }
    else{

    Node<T> *aux = head;

    for (size_t i = 0; i < index-2; i++)
    {
        aux = aux->next;
    }

    aux->next=aux->next->next;

    this->index--;

    }


}


//(iii) retornar o valor de uma posição específica.

template <typename T>
T Lista<T>::Search(int index){

    if (index < this->index<0 || index > this->index+1)
    {
         throw out_of_range("ERRO DE TAMANHO");
    }
    
    T valor;

    if (this->index==0){

    cout<<"Lista vazia";

    }else 
    if (index==0){
    
    valor= head->data;

    }
    else{

    Node<T> *aux = head;

    for (size_t i = 0; i < index; i++)
    {
        aux = aux->next;
    }
    
    valor=aux->data;
    }

return valor;
}