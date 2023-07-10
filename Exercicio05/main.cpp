#include <iostream>
#include "URL.h"
using namespace std;


int main() {
    
    URL url1 = "https://cefetplusplus.github.io/curso"_url;
    URL url2 = "https://www.cefetmg.br/"_url;
    URL url3 = "https://www.cefetmg.br:443/"_url;
    URL url4 = "https://pt.wikipedia.org/wiki/URL"_url;
    URL url5 = "https://pt.wikipedia.org/wiki/URL#cite_note-4"_url;
    URL url6 = "esquema://domínio:123/caminho/recurso?query_string#fragmento"_url;

    cout<<"\nUrl 1:\n";
    url1.print();
    
    cout<<"\nUrl 2:\n";
    url2.print();

    cout<<"\nUrl 3:\n";
    url3.print();

    cout<<"\nUrl 4:\n";
    url4.print();

    cout<<"\nUrl 5:\n";
    url5.print();

    cout<<"\nUrl 6:\n";
    url6.print();
    

 }  



