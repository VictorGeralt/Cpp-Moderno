#include "lista.h"

int main(){

    Lista<int> lista;



    for (int i = 0; i < 10; i++){
    cout<<"inserção : "<< i+1 << endl;
    lista.Insert(i+1,i);
    }

    cout<<"\n\n";
    cout<<"Printando a lista"<<endl;
    cout<<"\n\n";
    lista.Print();

    cout<<"\n\n";
    cout<<"Adicionando 11 na cabeça"<<endl;
    cout<<"\n\n";
    lista.Insert(11,0);
    lista.Print();

    cout<<"\n\n";
    cout<<"Adicionando 12 na posição 5"<<endl;
    cout<<"\n\n";
    lista.Insert(12,5);
    lista.Print();

    cout<<"\n\n";
    cout<<"Removendo a posição 6"<<endl;
    cout<<"\n\n";
    lista.Remove(6);
    lista.Print();

    cout<<"\n\n";
    cout<<"Removendo a posição 0"<<endl;
    cout<<"\n\n";
    lista.Remove(0);
    lista.Print();

    cout<<"\n\n";
    cout<<"Removendo a posição 1"<<endl;
    cout<<"\n\n";
    lista.Remove(1);
    lista.Print();

    cout<<"\n\n";
    cout<<"Buscando o valor da posição 6"<<endl;
    cout<<"\n\n";
    
    int busca = lista.Search(6);

    
    cout<<busca;
    cout<<"\n\n";
    
    cout<<"Buscando o valor da posição 1"<<endl;
    
    int busca2 = lista.Search(1);

    
    cout<<"\n\n";
    cout<<busca2;
    cout<<"\n\n";
     
    return 0;
}