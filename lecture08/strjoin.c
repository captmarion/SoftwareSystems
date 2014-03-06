/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Modified by Ken Berry
18 FEB 2014 - Software Systems, Spring 2014

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *tracks[] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Returns a heap-allocated string that contains the strings 
   from the given array, joined up with no spaces between.
*/
char *strjoin(char *array[], int n)
{
	int i;
	int len = 0;	//length of final string
	char *buffer, *dest;

	for (i = 0; i < n; i++) {
		len += strlen(array[i]);
//		printf("Length: %i, Iteration: %i\n", len, i); for testing
	}

	buffer = (char *)malloc( len * sizeof(char) );
	buffer[0] = '\0';
	dest = buffer;	//pointer to working position in buf
	
	for (i = 0; i < n; i++) {
		strcpy(dest, array[i]);
		dest += strlen(array[i]);
	}

	return buffer;
}


int main (int argc, char *argv[])
{

	char *s = strjoin(tracks, 5);
	printf("%s\n", s);
	return 0;

}
