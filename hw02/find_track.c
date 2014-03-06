/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Modified Feb 2014 by Ken Berry
Olin College Software Systems--Spring 2014

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};




// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}



// Finds all tracks that match the given pattern.
//
// Based on example code from IBM i information center documentation
// Modified by KFB, 17FEB2014
//
// Prints track number and title.
void find_track_regex(char pattern[])
{

    int i;

    for (i=0; i<NUM_TRACKS; i++) {
	regex_t    preg;
	char       *string = tracks[i];
	int        rc;		// stores final status of regcomp and regexec
	size_t     nmatch = 1;	// only looks for first match in each track
	regmatch_t pmatch[2];

	if (0 != (rc = regcomp(&preg, pattern, 0))) {
		printf("regcomp() failed, returning nonzero (%d)\n", rc);
		exit(EXIT_FAILURE);
	}

	if (0 != (rc = regexec(&preg, string, nmatch, pmatch, 0))) {
		printf("Failed to match '%s' with '%s',returning %d.\n",
		string, pattern, rc);
	}
	else {
		printf("Track %i: '%s'\n", i, tracks[i]);
	}

	regfree(&preg);

    }
}



// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}



// MAIN
//
//

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
