
#include "mainHeaderFiles.h"

int main(int argc, char **argv)
{
    struct sigaction signalAction;
    memset(&signalAction, 0, sizeof(signalAction));
    signalAction.sa_handler=signalHandler;
    signalHandlerConfig(&signalAction);    

    std::cout << "Main Firewall Started" << std::endl;
    createTcpServer *createTcp = new createTcpServer();
    createTcp->listenServer(4566);    
    delete createTcp;
    
    return 0;
}