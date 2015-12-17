#pragma once

#include <stdio.h>
#include <stdlib.h>

//void testLog(level logLevel, char* log);

FILE *output;
typedef enum {DEBUG, ERRORS, PERFORM} level;
level logLevel;
int timeStamp(void);