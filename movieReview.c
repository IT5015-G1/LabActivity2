/************************************************************************
 * Project Name:  Movie Review Viewer										      *
 * Programmers  : Group 1				                              		*
 * Date Completed: June 2018                                				*
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************
 * Function Prototypes                                            *
 ******************************************************************/
int genreUserInput(void);
void retrieveAndDisplayMovieTitles(int genre);
char * movieTitleUserInput(void);
void retrieveAndDisplayMovieReviews(char[] movieTitle);

/******************************************************************************
 * The program will only stop if the user chooses to exit the program. If     *
 * the user chooses to proceed to movie genre picking, the program will call  *
 * the functions from tasks 4 to 8.															*
 ******************************************************************************/
int main(void) 
{
	
	
	getch();
	return 0;
}

/******************************************************************************
 * (1) Ask the user for input, display the genre menu, number each genre.		*	
 * (2) Return the integer value.																*
 * (3) The function should notify the user if he/she inputted the wrong value	*
 ******************************************************************************/
int genreUserInput(void)
{
	
}

/******************************************************************************
 * This function will accept an integer variable containing the numerical 		*
 *  value of the genre inputted by the user....											*
 *       																							*
 * (1) Assign the string value using the integer value and store it in a      *
 *     string variable. Add '.txt' extension. Make sure the name that you will* 
 *	    assign matches the title of the existing textfile.							*
 * (2)Using the string variable, retrieve and display the movie titles			*
 * (3)The function should notify the user if he/she inputted the wrong movie  *
 *    title (case-sensitive)																	*
 ******************************************************************************/
void retrieveAndDisplayMovieTitles(int genre)
{
	
}

/******************************************************************************
 * With the displayed movie titles, this function will ask the user to input  *
 * the full movie title. The function will return the full movie title to the *
 * main function.																					*
 ******************************************************************************/
char * movieTitleUserInput(void)
{
	
}

/******************************************************************************
 * This function will accept a string variable containing the full movie 		*
 * title....																						*
 * (1) Concatenate the word "".txt"" to the movie title variable					*
 * (2) Using the string, retrieve and display the movie contents					*
 ******************************************************************************/
void retrieveAndDisplayMovieReviews(char[] movieTitle)
{
	
}
