/************************************************************************
 * Project Name:  Movie Review Viewer								    *
 * Programmers  : Group 1				                                *
 * Date Completed: June 2018                                			*
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

/******************************************************************
 * Function Prototypes                                            *
 ******************************************************************/
int genreUserInput(void);
void retrieveAndDisplayMovieTitles(int genre);
char * movieTitleUserInput(void);
void retrieveAndDisplayMovieReviews(char movieTitle[]);
void userChoiceMovie (void);

/******************************************************************************
 * The program will only stop if the user chooses to exit the program. If     *
 * the user chooses to proceed to movie genre picking, the program will call  *
 * the functions from tasks 4 to 8.									  		  *
 ******************************************************************************/
int main(void) 
{
	userChoiceMovie ();	
	printf("\n\tThank you for stopping by!");
	
	getch();
	return 0;
}

/******************************************************************************
  * The program will only stop if the user chooses to exit the program. 	  *
  * If the user chooses to proceed to movie genre picking, the program        * 
  * will call the functions from tasks 4 to 8. 							      *
 ******************************************************************************/

void userChoiceMovie (void)
{
	int choice = 0;
	int genre;
	char * stringMovieTitle;
	
	#pragma omp single
	do{
		printf("\n=====================================================");
        printf("\n\tWelcome to the Movie Review!");
        printf("\n\t(1) Proceed to Choosing a Movie Genre");
        printf("\n\t(2) Exit");
        printf("\n=====================================================");
        printf("\n\nPlease choose: ");
        scanf("%d",&choice);
        
        #pragma omp task if(choice == 1)
        if(choice == 1){
        	genre = genreUserInput();
			retrieveAndDisplayMovieTitles(genre);
			stringMovieTitle = movieTitleUserInput();
			retrieveAndDisplayMovieReviews(stringMovieTitle);
		}else if(choice != 1 && choice != 2){
           printf("\n\nERROR: INPUT INVALID!\n");
        }
		
     }while (choice != 2);
     
}

/******************************************************************************
 * (1) Ask the user for input, display the genre menu, number each genre.	  *	
 * (2) Return the integer value.										      *
 * (3) The function should notify the user if he/she inputted the wrong value *
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
           printf("\n\nError: Invalid Input!\n");
        }
     }while (genre != 1 && genre != 2 && genre != 3 && genre != 4 && genre != 5);
     
     return genre;
}

/******************************************************************************
 * This function will accept an integer variable containing the numerical 	  *
 *  value of the genre inputted by the user....								  *
 *       																	  *
 * (1) Assign the string value using the integer value and store it in a      *
 *     string variable. Add '.txt' extension. Make sure the name that you will* 
 *	    assign matches the title of the existing textfile.					  *
 * (2)Using the string variable, retrieve and display the movie titles		  *
 * (3)The function should notify the user if he/she inputted the wrong movie  *
 *    title (case-sensitive)												  *
 ******************************************************************************/
void retrieveAndDisplayMovieTitles(int genre)
{
	FILE* fp; 
	char stringGenre[] = "";		// Genre for file
	char c;							// Contents of the file
	
	#pragma omp task switch(genre)
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

	
	printf("\nMovies Available...\n");
	
	if(strlen(stringGenre) != 0){
		fp = fopen(stringGenre, "r");
	
		if(fp != NULL){	
    		#pragma omp task shared(fp, c)
			while ((c = getc(fp)) != EOF){		// Iterates until the End of File (EOF)
    			putchar(c);						// Directly print the movie titles
			}
			
			fclose(fp);							// Closes the file
		}
	}
	
	printf("\n\n");
}

/******************************************************************************
 * With the displayed movie titles, this function will ask the user to input  *
 * the full movie title. The function will return the full movie title to the *
 * main function.															  *
 ******************************************************************************/
char * movieTitleUserInput(void)
{
	char * stringMovieTitle = (char*)malloc(sizeof(char)*100);
	
	printf("Please enter the movie title: ");
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
	
	#pragma omp task if(strlen(movieTitle) > 0)
	if(strlen(movieTitle) > 0){
		
		char *movie = strcat(movieTitle, ".txt");
		char c;
		
		fp = fopen(movie, "r");
		
		#pragma omp task if(fp != NULL)
		if(fp != NULL){
			printf("\n\t%s\n", movieTitle);
			printf( "\n");

			#pragma omp task shared(fp, c)
			while((c = getc(fp)) != EOF){
				putchar(c);
			}
			
			printf("\n");
		} else {
			printf("\nError: Movie review for %s was not found.\n\nPlease try again from the top\n\n", movieTitle);
		}
		
		fclose(fp);
	} else {
		printf("\nError: You did not input a movie.");
	}
}
