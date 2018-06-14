#include<stdio.h>
#include<conio.h>

int getUserInput();

int main(void){
    int genre;
    genre = getUserInput();
    
    printf("\n You have selected genre %d", genre);
    
    getch();
    return 0;  
}

int getUserInput(){
     int genre = 0;

     do{
        printf("\nMovie Genres");
        printf("\n(1) Romance");
        printf("\n(2) Horror");
        printf("\n(3) Action");
        printf("\n(4) Comedy");
        printf("\n(5) Fantasy");
        printf("\n\nPlease choose a movie genre: ");
        scanf("%d",&genre);
     
        if(genre != 1 && genre != 2 && genre != 3 && genre != 4 && genre != 5){
           printf("\n\nERROR: INPUT INVALID!\n");
        }
     }while (genre != 1 && genre != 2 && genre != 3 && genre != 4 && genre != 5);
     
     return genre;
          
}
