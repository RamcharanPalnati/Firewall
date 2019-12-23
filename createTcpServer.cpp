#include "createTcpServer.h"

bool createTcpServer ::listenServer(int port)
{
    setPort(port);
    setMasterSocket(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));

    int &localMasterSocket = getMasterSocket();
    int option = 1;
    if (localMasterSocket < 0)
    {
        std::cout << "Unable to create TCP socket" << std::endl;
    }
    if (setsockopt(localMasterSocket, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), (char *)&option, sizeof(option)) < 0)
    {
        printf("setsockopt failed for REUSEPORT and REUSEADDR \n");
        close(localMasterSocket);
    }
    if (setsockopt(localMasterSocket, SOL_SOCKET, SO_KEEPALIVE, (char *)&option, sizeof(option)) < 0)
    {
        printf("setsockopt failed for SO_KEEPALIVE \n");
        close(localMasterSocket);
    }
    if (setsockopt(localMasterSocket, SOL_SOCKET, SO_BROADCAST, (char *)&option, sizeof(option)) < 0)
    {
        printf("setsockopt failed for SO_BROADCAST \n");
        close(localMasterSocket);
    }
    
    if(bind(localMasterSocket,(sockaddr*)getSocketAddress(),sizeof(struct sockaddr))<0)
    {
        printf("Unable to Bind erro No");
        std::cout<<errno<<std::endl;
    }
    listen(localMasterSocket,5);
    std::cout<<"Listeing on server with port:{}"<<getPort()<<std::endl;
    socklen_t sockLen=sizeof(getSocketAddress());
    int clientSocket=accept(localMasterSocket,(sockaddr*)getSocketAddress(),&sockLen);

    if(clientSocket<0)
    {
        std::cout<<"Unable to accept  socket"<<std::endl;
        close(localMasterSocket);
    }

    char recvData[4096];
    std::stringstream ss;
    ss<<"HELLLO WELCOME TO SERVER";
    std::string welcomeMessage=ss.str();
    int i=0;
    while(i<5)
    {
        std::cout<<"Client Connected"<<std::endl;
        struct sockaddr destinationAddress;
        
        size_t size=sendto(clientSocket,(char *)welcomeMessage.c_str()  ,strlen(welcomeMessage.c_str()) ,0,(struct sockaddr*)&destinationAddress,sizeof(destinationAddress));
        std::cout<<size<<" bytes sent" <<std::endl;
        usleep(60000000);
        i++;
    }
    close(clientSocket);
    close(localMasterSocket);
}