#include <iostream>
using namespace std;

class Racional{
    private:

        int num;
        int den;

    public:
    Racional(){
        this->num = 0;
        this->den = 1;
    };

    Racional(int num, int den){     
        this->num = num;
        this->den = den;
    };

    Racional(const Racional& rac){
        this->num = rac.num;
        this->den = rac.den;
    }

    Racional(Racional &&rac){
        this->num = rac.num;
        this->den = rac.den;
        rac.num = 0;
        rac.den = 1;
    };

    ~Racional(){};

    int const numerador(){
        return this->num;
    }

    int const denominador(){
        return this->den;
    }

    void numerador(int num){
        this->num = num;
    }

    void denominador(int den){
        this->den = den;
    }

    double valor(){
        return (double)this->num/this->den;
    }

    Racional operator=(Racional rac){
            this->num = rac.num;
            this->den = rac.den;
        return *this;
    }        

    bool const operator<(const Racional& rac){    
        Racional r = rac;

        double n1 = this->valor();
        double n2 = r.valor();

        return n1<n2;
    }

    bool const operator<=(const Racional& rac){
        Racional r = rac;

        double n1 = this->valor();
        double n2 = r.valor();

        return n1<=n2;
    }

    bool const operator>(const Racional& rac){
        Racional r = rac;

        double n1 = this->valor();
        double n2 = r.valor();

        return n1>n2;
    }

    bool const operator>=(const Racional& rac){
        Racional r = rac;

        double n1 = this->valor();
        double n2 = r.valor();

        return n1>=n2;
    }

    bool const operator==(const Racional& rac){
        Racional r = rac;

        double n1 = this->valor();
        double n2 = r.valor();

        return n1==n2;
    }

    Racional const operator+(const Racional& rac) const {
        int novoNum = (this->num * rac.den) + (rac.num * this->den);
        int novoDen = this->den * rac.den;
        return Racional(novoNum, novoDen);
    }

    Racional const operator-(const Racional& rac) const {
        int novoNum = (this->num * rac.den) - (rac.num * this->den);
        int novoDen = this->den * rac.den;
        return Racional(novoNum, novoDen);
    }

    Racional const operator*(const Racional& rac) const {
        int novoNum = this->num * rac.num;
        int novoDen = this->den * rac.den;
        return Racional(novoNum, novoDen);
    }

    Racional operator/(const Racional& rac) const {
        int novoNum = this->num * rac.den;
        int novoDen = this->den * rac.num;
        return Racional(novoNum, novoDen);
    }

   Racional& operator+=(const Racional& rac) {
        *this = *this + rac;
        return *this;
    }

    Racional& operator-=(const Racional& rac) {
        *this = *this - rac;
        return *this;
    }

    Racional& operator*=(const Racional& rac) {
        *this = *this * rac;
        return *this;
    }

    Racional& operator/=(const Racional& rac) {
        *this = *this / rac;
        return *this;
    }

    Racional operator++() {
        this->num += this->den;
        return *this;
    }

    Racional operator++(int) {
        Racional temp = *this;
        ++(*this);
        return temp;
    }

    Racional operator--() {
        this->num -= this->den;
        return *this;
    }

    Racional operator--(int) {
        Racional temp = *this;
        --(*this);
        return temp;
    }

};