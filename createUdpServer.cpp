#include "createUdpServer.h"


bool createUdpServer ::listenServer(int port)
{
    setPort(port);
    setMasterSocket(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP));
    int option = 1;

    int &localMasterSocket = getMasterSocket();
    if (localMasterSocket < 0)
    {
        std::cout << "Unable to create UDP socket" << std::endl;
    }
}