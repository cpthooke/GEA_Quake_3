#pragma once

#include <stdio.h>
#include <stdlib.h>

//void testLog(level logLevel, char* log);

typedef enum {DEBUG = 1, ERRORS = 2, PERFORM = 3} level;
level logLevel;
int timeStamp(void);