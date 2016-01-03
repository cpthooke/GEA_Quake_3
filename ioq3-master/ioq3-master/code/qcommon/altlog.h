#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef __altlog_h__
#define __altlog_h__

typedef enum
{
	DEBUG = 0,
	ERRORS = 1,
	PERFORM = 2
} level;

level logLevel;
void testSum();
void testLog(level logLevel, char* log);

#endif