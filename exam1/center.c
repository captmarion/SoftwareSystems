/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Modified by Ken Berry, 20 FEB 2014
SoftSys Spr 2014, Exam 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
	int i, fsp;	//iterator and fill space
	int frt, rr;	//fill space in front and to rear of string
	int len = 0;	//length of given string
	char *ret;	//string to return

	len = strlen(s);
	fsp = n - len;	//calc amount of fill characters needed
	frt = fsp/2;	//front is half of the needed fill characters
	rr = frt + (fsp%2);	//rr is front + the remainder
	
	ret = (char *)malloc( n * sizeof(char) ); //allocate memory

/* The following for loop would concatenate to ret the number of fill characters
determined by frt in front of the string, and then add the number of
fill characters determined by rr after the string.
*/

	for (i = 0; i <= n; i++) {
		if (i < frt) {
		strcat(*ret, *fillchar 
		}
	}

	return ret;
}


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
