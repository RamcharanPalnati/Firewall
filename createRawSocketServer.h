#pragma once 

#include "createServer.h"



class createRawSocketServer : public createServer
{
public:
    createRawSocketServer() = default;
    bool listenServer(int port);
};

