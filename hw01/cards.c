/******************************************************************************
   cards.c -- Ken Berry
   Software Systems, Spr 2014
   From pg. 37 of Head First C

   Keeps a running card count based on user-inputted card values.

   Displays count after every update; escapes when user types 'X'.

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>



/******************************************************************************/
/* Variables */

char prompt_text[] = "Enter the card name:"; /*Text prompt for card name input*/
char card_name[3];			    /* Buffer to store user input */
int count = 0;				    /* Stores current card count */
int wcount = 0;			/* Working version of count for update-count */




/******************************************************************************/
/* Functions */

/* get_card_name
   Prompts user to input card name and stores it in the given buffer.
   Truncates input to first two characters; Exits when user inputs 'X'.

   prompt_string: text to display to prompt user for input
   card_name: buffer that stores user input
*/

void get_card_name(char *prompt_string, char *card_name)
{
	while (1)
	{	
		puts(prompt_string);	/* prompts for user input */
		scanf("%2s", card_name); /* captures user input into card_name*/
		break;
	}
}



/* update_count
   Takes current value of card_name and updates count accordingly.
   Truncates input to first two characters; Exits when user inputs 'X'.

   card_name: string of current card name
   count: variable that stores the current count
*/

void update_count(char *card_name, int * wcount)
{
	int val = 0;	/* stores value of current card */
	switch(card_name[0]) {	/* updates card value based on card name */
	case 'J':
	case 'Q':
	case 'K':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	case 'X':		/* break on 'X' to escape function */
		break;
	default:
		val = atoi(card_name);	/* for non-face cards */
		if ((val < 1) || (val > 10)) { /*prompt on bad card name */
			puts("Please type an actual card value.");
		}
	}
	if ((val > 2) && (val < 7)) {   /*if card is between 2 and 7, count++ */
		*wcount = *wcount + 1;
	}
	else if (val == 10) {		/* if card is a face card, count-- */
		*wcount = *wcount - 1;
	}
}



/******************************************************************************/
/* Main */

int main()
{
	while (card_name[0] != 'X')	/* if user inputs 'X', end program */
	{
		get_card_name(prompt_text, card_name); /* get user input */
		update_count(card_name, &count);       /* update count */
		printf("Current count: %i\n", count); /* print new count*/
	}
	return 0;
}
