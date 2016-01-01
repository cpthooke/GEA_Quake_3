#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include "altlog.h"

//typedef struct altLogLevel
//{
//	int category;
//	level logLevel;
//	struct altLogLevel *next;
//} altLogLevel;

void testLog(level logLevel, char* log, ...)
{
	FILE *output = fopen("altlog.txt", "a");

	va_list args; // Makes it variadic.
	va_start(args, log); // Starts variadic arguments.

	time_t ltime; // Calendar time - http://cc.byexamples.com/2007/01/26/create-your-own-time-stamp/
	ltime = time(NULL); // Get current time
	char* timeStamp = ("%s", asctime(localtime(&ltime)));

	if (logLevel < 0 || logLevel > 2)
	{
		fprintf(output, "LOGGING SYSTEM OUT OF SCOPE\n");
	}

	if (logLevel == DEBUG)
	{
		vfprintf(output, timeStamp, args);
		vfprintf(output, log, args);
		fprintf(output, "\n");
	}

	va_end(args);
	fclose(output);
}