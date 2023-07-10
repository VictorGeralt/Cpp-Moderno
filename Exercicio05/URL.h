#include <iostream>
#include <string>

using namespace std;

class URL {
    private:
        string esquema;
        string dominio;
        int porta;
        string caminho;
        string queryString;
        string fragmento;
        string recurso;

    public:


        URL() {
            this->esquema= "";
            this->dominio= "";
            this->porta= 0;
            this->caminho= ""; 
            this->recurso= "";
            this->queryString= "";
            this->fragmento= "";
        }
        

        URL(string esquema, string dominio, int porta, string caminho,string recurso,string queryString,string fragmento){
            this->esquema= esquema;
            this->dominio= dominio;
            this->porta= porta;
            this->caminho= caminho; 
            this->recurso= recurso;
            this->queryString= queryString;
            this->fragmento= fragmento;
        }


        URL(const URL& URL2) {
            this->esquema= URL2.esquema;
            this->dominio= URL2.dominio;
            this->porta= URL2.porta;
            this->caminho= URL2.caminho; 
            this->recurso= URL2.recurso;
            this->queryString= URL2.queryString;
            this->fragmento= URL2.fragmento;
        }

        string getEsquema() const {
            return this->esquema;
        }

        void setEsquema(string esquema) {
            this->esquema = esquema;
        }

        string getDominio() const {
            return this->dominio;
        }

        void setDominio(string dominio) {
            this->dominio = dominio;
        }

        int getPorta() const {
            return this->porta;
        }

        void setPorta(int porta) {
            this->porta = porta;
        }

        string getCaminho() const {
            return this->caminho;
        }

        void setCaminho(string caminho) {
            this->caminho = caminho;
        }

        string getRecurso() const {
            return this->recurso;
        }

        void setRecurso(string recurso) {
            this->recurso = recurso;
        }

        string getQueryString() const {
            return this->queryString;
        }

        void setQueryString(string queryString) {
            this->queryString = queryString;
        }

        string getFragmento() const {
            return this->fragmento;
        }

        void setFragmento(string fragmento) {
            this->fragmento = fragmento;
        }


        void print(){
            cout<<"Esquema: "<<getEsquema()<<endl;
            cout<<"Dominio: "<<getDominio()<<endl;
            cout<<"Porta: "<<getPorta()<<endl;
            cout<<"Caminho: "<<getCaminho()<<endl; 
            cout<<"Recurso: "<<getRecurso()<<endl;
            cout<<"Query String: "<<getQueryString()<<endl;
            cout<<"Fragmento: "<<getFragmento()<<endl;
        }
};


// Sobrecarga do operador de sufixo (literal)
        URL operator ""_url(const char* str, size_t size) {
            string url(str, size);
            string esquema, dominio, caminho, recurso, queryString, fragmento;
            int porta = 0;

            size_t position = url.find("://");
            

            if (position != string::npos) {
                esquema = url.substr(0, position);
                url.erase(0, position + 3);
            }

            

            position = url.find("/");
            if (position != string::npos) {
                dominio = url.substr(0, position);
                url.erase(0, position+1); 
            }

            
            position = dominio.find(":");
            if (position != string::npos) {
                porta = stoi(dominio.substr(position+1));
                dominio.erase(position); 

            }


            position = url.find("/");
            if (position != string::npos) {
                caminho = url.substr(0, position);
                url.erase(0, position+1); 
            } 

            position = url.find("?");
            if (position != string::npos) {
                recurso = url.substr(0, position);
                url.erase(0, position+1); 
            } 

            position = url.find("#");
            if (position != string::npos) {
                queryString = url.substr(0, position);
                url.erase(0, position+1); 
            } 

            fragmento = url;
            
            return URL(esquema, dominio, porta, caminho, recurso, queryString, fragmento);
        }