#include "createRawSocketServer.h"


bool createRawSocketServer ::listenServer(int port)

{
    setPort(port);
    setMasterSocket(socket(AF_INET, SOCK_RAW, IPPROTO_ICMP));
    std::cout << "raw socket" << getMasterSocket() << std::endl;
    if (getMasterSocket() < 0)
    {
        std::cout << "Unable to create RAW socket" << std::endl;
    }
}