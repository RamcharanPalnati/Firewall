#pragma once

#include<signal.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <execinfo.h>

void signalHandlerConfig(struct sigaction * sigAction);

void signalHandler(int signal);