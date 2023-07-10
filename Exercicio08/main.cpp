#include <iostream>
#include "racional.hpp"
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    Racional soma;
    Racional somatorio;
    bool comparacao;
    Racional n1(19,2);
    Racional n2(17,5);
    Racional n3(11,7);
    Racional n4(13,3);
    vector<Racional> v {n1,n2,n3,n4};

    
    cout<<"\nNumeros Racionais:"<<endl;
    cout<<n1.numerador()<<"/"<<n1.denominador()<<endl;
    cout<<n2.numerador()<<"/"<<n2.denominador()<<endl;
    cout<<n3.numerador()<<"/"<<n3.denominador()<<endl;
    cout<<n4.numerador()<<"/"<<n4.denominador()<<endl;


    soma = n1+n2;
    
    cout<<"\nSoma:"<<endl;
    cout<<n1.numerador()<<"/"<<n1.denominador()<<" + "<<n2.numerador()<<"/"<<n2.denominador()<<" = ";
    cout<<soma.numerador()<<"/"<<soma.denominador()<<endl;

    
    n1+=n2;
    
    cout<<"\nAtribuição:"<<endl;
    cout<<"n1 += n2 = ";
    cout<<n1.numerador()<<"/"<<n1.denominador()<<endl;
    
    

    cout<<"\nComparação:"<<endl;
    cout<<"n1 > n2  : ";
    n1>n2? (cout << "True"<<endl) :
                (cout << "false"<<endl) ;

    cout<<"n1 < n2  : ";
    n1<n2? (cout << "True"<<endl) :
                (cout << "false"<<endl) ;

    cout<<"n1 <= n2 : ";
    n1<=n2? (cout << "True"<<endl) :
                (cout << "false"<<endl) ;

    cout<<"n1 >= n2 : ";
    n1>=n2? (cout << "True"<<endl) :
                (cout << "false"<<endl) ;


    
    cout<<"\nIncrementação:"<<endl;
    cout<<"n1++ = ";
    n1++;
    cout<<n1.numerador()<<"/"<<n1.denominador()<<endl;



    cout<<"\nOrdenação com uso de sort:"<<endl;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout<<v[i].numerador()<<"/"<<v[i].denominador()<<endl;
    }



    for(int i = 0; i < v.size(); i++){
        somatorio += v[i];
    }
    cout<<"\nSomatório: ";
    cout<<somatorio.numerador()<<"/"<<somatorio.denominador()<<endl;


    
    return 0;
}