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
void retrieveAndDisplayMovieReviews(char movieTitle[]);

/******************************************************************************
 * The program will only stop if the user chooses to exit the program. If     *
 * the user chooses to proceed to movie genre picking, the program will call  *
 * the functions from tasks 4 to 8.															*
 ******************************************************************************/
int main(void) 
{
	char * stringMovieTitle;
	int genre;
	
	genre = genreUserInput();
	retrieveAndDisplayMovieTitles(genre);
	stringMovieTitle = movieTitleUserInput();
	retrieveAndDisplayMovieReviews(stringMovieTitle);
	
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
	int genre = 0;

     do{
        printf("\nMovie Genres");
        printf("\n(1) Horror");
        printf("\n(2) Romance");
        printf("\n(3) Comedy");
        printf("\n(4) Fantasy");
        printf("\n(5) Action");
        printf("\n\nPlease choose a movie genre: ");
        scanf("%d",&genre);
     
        if(genre != 1 && genre != 2 && genre != 3 && genre != 4 && genre != 5){
           printf("\n\nERROR: INPUT INVALID!\n");
        }
     }while (genre != 1 && genre != 2 && genre != 3 && genre != 4 && genre != 5);
     
     return genre;
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
	FILE* fp; 
	char stringGenre[] = "";		// Genre for file
	char c;							// Contents of the file
	
	switch(genre){		// Searches for genre, otherwise, throw an error
		// Horror
		case 1: strcat(stringGenre, "Horror.txt"); break;
		
		// Romance
		case 2: strcat(stringGenre, "Romance.txt"); break;
		
		// Comedy
		case 3: strcat(stringGenre, "Comedy.txt"); break;
		
		// Fantasy
		case 4: strcat(stringGenre, "Fantasy.txt"); break;
		
		// Action
		case 5: strcat(stringGenre, "Action.txt"); break;
		
		default: printf("ERROR: Genre doesn't exist!"); break;
	}
	
	if(strlen(stringGenre) != 0){
		fp = fopen(stringGenre, "r");
	
		if(fp != NULL){	
    		while ((c = getc(fp)) != EOF){		// Iterates until the End of File (EOF)
    			putchar(c);						// Directly print the movie titles
			}
			
			fclose(fp);							// Closes the file
		}
	}
}

/******************************************************************************
 * With the displayed movie titles, this function will ask the user to input  *
 * the full movie title. The function will return the full movie title to the *
 * main function.															  *
 ******************************************************************************/
char * movieTitleUserInput(void)
{
	char * stringMovieTitle = (char*)malloc(sizeof(char)*100);
	
	printf("\nPlease enter the movie title: ");
	fflush(stdin);	
//	scanf("%s", stringMovieTitle);
	fgets (stringMovieTitle, 100, stdin);
	stringMovieTitle[strlen(stringMovieTitle)-1] = '\0';
	
	return stringMovieTitle;
}

/******************************************************************************
 * This function will accept a string variable containing the full movie   	  *
 * title....																  *
 * (1) Concatenate the word "".txt"" to the movie title variable			  *
 * (2) Using the string, retrieve and display the movie contents	   		  *
 * (3)The function should notify the user if he/she inputted the wrong movie  *
 *    title (case-sensitive)												  *
 ******************************************************************************/
void retrieveAndDisplayMovieReviews(char * movieTitle)
{
	FILE *fp;
	
	if(strlen(movieTitle) > 0){
		printf("\n\t%s\n", movieTitle);
		char *movie = strcat(movieTitle, ".txt");
		char c;
		
		fp = fopen(movie, "r");
		
		if(fp != NULL){
			printf( "\n");
			while((c = getc(fp)) != EOF){
				putchar(c);
			}
			printf("\n");
		} else {
			printf("\nError: Movie review for %s was not found.", movieTitle);
			exit(1);
		}
		
		fclose(fp);
		exit(0);
	} else {
		printf("\nError: You did not input a movie.");
		exit(1);
	}
}
