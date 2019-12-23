
#include "mainHeaderFiles.h"

int main(int argc, char **argv)
{
    std::cout << "Main Firewall Started" << std::endl;
    createTcpServer *createTcp = new createTcpServer();
    createTcp->listenServer(4566);    
    delete createTcp;
    
    return 0;
}