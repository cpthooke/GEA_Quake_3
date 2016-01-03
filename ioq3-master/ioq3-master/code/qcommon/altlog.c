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

int a = 0; // Variables for testing.
int b = 0;
int c = 0;
int d = 0;

void testSum() // Test method.
{
	a = 1;
	b = 2;

	c = 3;
	d = a + b + c;
}

void testLog(level logLevel, char* log, ...)
{
	FILE *output = fopen("altlog.txt", "a");
	testSum(); // For testing.
	va_list args; // Makes it variadic.
	va_start(args, log); // Starts variadic arguments.

	time_t ltime; // Calendar time - http://cc.byexamples.com/2007/01/26/create-your-own-time-stamp/
	ltime = time(NULL); // Get current time
	char* timeStamp = ("%s", asctime(localtime(&ltime)));

	if (logLevel < 0 || logLevel > 2)
	{
		fprintf(output, "LOGGING SYSTEM OUT OF SCOPE\n");
	}

	vfprintf(output, timeStamp, args);
	
	if (logLevel == DEBUG)
	{
		vfprintf(output, log, args);
		fprintf(output, "\nTest level: DEBUG \n");
	}

	if (logLevel == ERRORS)
	{
		vfprintf(output, log, args);
		fprintf(output, "\nTest level: ERRORS \n %d %d %d\n", a, b, c);
	}

	if (logLevel == PERFORM)
	{
		vfprintf(output, log, args);
		fprintf(output, "\nTest level: PERFORM \n%d + %d + %d = %d\n", a, b, c, d);
	}

	va_end(args);
	fclose(output);
}