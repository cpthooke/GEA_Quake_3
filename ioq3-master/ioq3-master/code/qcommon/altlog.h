#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef enum
{
	DEBUG = 0,
	ERRORS = 1,
	PERFORM = 2
} level;

level logLevel;
void testLog(level logLevel, char* log);
int timeStamp(void);