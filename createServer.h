#pragma once

#include <iostream>
#include <cstdio>
#include <string>

#include <netdb.h>
#include <netinet/in.h>

#include <unistd.h> //unix close()

#include <sys/socket.h>
#include <sys/types.h>

#include <errno.h>

#include <string>
#include <sstream>
#include <cstring>

class createServer
{
    int masterSocket;
    int port;
    struct sockaddr_in *serverAddr;

public:
    createServer();

    void setMasterSocket(int socket);
    void setPort(int port);
    int getPort();
    int &getMasterSocket();

    sockaddr_in *getSocketAddress();

    virtual bool listenServer(int port) = 0;
    virtual ~createServer();
};