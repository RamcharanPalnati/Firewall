#pragma once

#include "createServer.h"

class createUdpServer : public createServer
{
public:
    createUdpServer() = default;
    bool listenServer(int port);
};