#pragma once 

#include "createServer.h"


class createTcpServer : public createServer
{
public:
    createTcpServer() = default;
    bool listenServer(int port);
};