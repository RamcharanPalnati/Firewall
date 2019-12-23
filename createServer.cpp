#include "createServer.h"

createServer::createServer()
{
    serverAddr = new sockaddr_in();
    serverAddr->sin_family = AF_INET;
    serverAddr->sin_addr.s_addr = htonl(INADDR_ANY);
    std::cout << "server Created" << std::endl;
}
createServer::~createServer()
{
    delete serverAddr;
    std::cout << "server Deleted" << std::endl;
}

void createServer::setMasterSocket(int socket)
{
    this->masterSocket = socket;
}
int &createServer::getMasterSocket()
{
    return masterSocket;
}

sockaddr_in *createServer::getSocketAddress()
{
    return serverAddr;
}

int createServer::getPort(){
    return port;
}
void createServer::setPort(int port)
{
    this->serverAddr->sin_port = htons(port);
    this->port=port;
}
