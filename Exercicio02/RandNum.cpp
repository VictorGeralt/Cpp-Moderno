#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

int main(int argc, char** argv){
    bool isInt = false;
    int Nval = 1;
    int limInf = 0;
    int limSup = 1;
    int Cval = 4;
    int seed = time(NULL);


    for(int i = 1; i < argc; i++){
        if (string(argv[i])=="-i"){
            isInt= true;

        }else if (string(argv[i])=="-n"){
            Nval= atoi(argv[++i]);
            
        }else if (string(argv[i])=="-r"){
            limInf= atoi(argv[++i]);
            limSup= atoi(argv[++i]);

        }else if (string(argv[i])=="-p"){
            Cval= atoi(argv[++i]);

        }else if (string(argv[i])=="-s"){
            seed= atoi(argv[++i]);

        }
    }

    srand(seed);

    for (size_t i = 0; i < Nval; i++)
    {
        double Num = limInf + (float)(rand()) / ((float)(RAND_MAX/(limSup - limInf)));

        isInt ? cout<<(int)Num<<endl : cout<<fixed<<setprecision(Cval)<<Num<<endl;;

    }

}