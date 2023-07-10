#include <iostream>
#include <csignal>

using namespace std;

static int sigcaught = 0;

static void sighandler(int signal)
{
    sigcaught = signal;
}

int main()
{

    struct sigaction sinal;
    sinal.sa_handler = sighandler;
    sigemptyset(&sinal.sa_mask);
    sinal.sa_flags = 0;

    std::cout << "Tente encerrar esse processo..." << std::endl;

    sigaction(SIGINT, &sinal, nullptr);
    while (true)
    {
        if (sigcaught)
            {
                sigcaught = 0;
                std::cout << "\nAperte novamente Ctrl+C para finalizar" << std::endl;
                while (true){
                    if (sigcaught){
                        exit(EXIT_SUCCESS);
                    }
                }
            }
    }
    
    return 0;
}