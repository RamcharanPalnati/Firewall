#include <iostream>
#include <cstdio>
#include <string>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

class createServer
{
    int masterSocket;
    int port;
    struct sockaddr_in *serverAddr;

public:
    createServer();

    void setMasterSocket(int socket);
    void setPort(int port);

    int &getMasterSocket();

    virtual bool listenServer(int port) = 0;
    virtual ~createServer();
};

class createTcpServer : public createServer
{
public:
    createTcpServer() = default;
    bool listenServer(int port);
};

class createUdpServer : public createServer
{
public:
    createUdpServer() = default;
    bool listenServer(int port);
};

class createRawSocketServer : public createServer
{
public:
    createRawSocketServer() = default;
    bool listenServer(int port);
};

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


void createServer::setPort(int port)
{
    this->serverAddr->sin_port=htons(port);
}

bool createTcpServer ::listenServer(int port)
{
    setPort(port);
    setMasterSocket(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));
    std::cout<<"TCP"<<getMasterSocket()<<std::endl;
    if (getMasterSocket() < 0)
    {
        std::cout << "Unable to create TCP socket" << std::endl;
    }
}

bool createUdpServer ::listenServer(int port)
{
    setPort(port);    
    setMasterSocket(socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP));
    std::cout<<"UDP"<<getMasterSocket()<<std::endl;
    if (getMasterSocket()< 0)
    {
        std::cout << "Unable to create UDP socket" << std::endl;
    }
}
bool createRawSocketServer ::listenServer(int port)
{
    setPort(port);
    setMasterSocket(socket(AF_INET, SOCK_RAW, IPPROTO_ICMP));
    std::cout<<"raw socket"<<getMasterSocket()<<std::endl;
    if (getMasterSocket()< 0)
    {
        std::cout << "Unable to create RAW socket" << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::cout << "Main Firewall Started" << std::endl;
    createTcpServer *createTcp = new createTcpServer();
    createTcp->listenServer(4566);
    delete createTcp;    
    createRawSocketServer *createRaw = new createRawSocketServer();
    createRaw->listenServer(45436);
    delete createRaw;

    return 0;
}