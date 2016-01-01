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

//int timeStamp(void) // http://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file
//{
//	char buffer[20];
//	struct tm *stm;
//
//	time_t current = time(0);
//	stm = gmtime(&current);
//	
//	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", stm);
//	fprintf("%s %s\n", buffer); // , "Event occurred now");
//
//	return current;
//}

void testLog(level logLevel, const char* log)
{
	FILE *output = fopen("altlog.txt", "a");

	va_list args; // Makes it variadic.
	va_start(args, log); // Starts variadic arguments.

	time_t now;
	time(&now);
	//int a = ctime(&now);


	if (logLevel == DEBUG)
	{
		vfprintf(output, log, args);
		vfprintf(output, "%t", ctime(&now));
		fprintf(output, "\n");
	}

	va_end(args);
	fclose(output);
}