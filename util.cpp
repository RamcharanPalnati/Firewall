
#include "util.h"

void signalHandlerConfig(struct sigaction *signalAction)
{
    signal(SIGCHLD,SIG_IGN);
    //signal(SIGPIPE,SIG_IGN);
    sigaction(SIGTERM,signalAction,nullptr);
    sigaction(SIGINT,signalAction,nullptr);
    sigaction(SIGSEGV,signalAction,nullptr);
    sigaction(SIGABRT,signalAction,nullptr);
    return;
}


void signalHandler(int signalNum)
{
    std::cout<<signalNum<<" signal occurred"<<std::endl;
    std::cout<<"Printing the stack trace"<<std::endl;


    char **stack_content_pointer;
    void *back_trace_buffer[30];
    int totalStackSizeObtained=0;

    totalStackSizeObtained = backtrace(back_trace_buffer, 30);
    stack_content_pointer = backtrace_symbols(back_trace_buffer, totalStackSizeObtained);
    
    for(int i=0;i<totalStackSizeObtained;++i)
    {
        printf("StackPoint :%d StackTrace %s \n",i,stack_content_pointer[i]);
    }
    free(stack_content_pointer);
}