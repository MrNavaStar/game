#include <stdio.h>
#include <curses.h>
#include <stdlib.h>


void display_level(int i){
	
	FILE *fptr;
	char ch;
	
	clear();

	if (i==1){
		fptr = fopen("level1.txt","r");
		
		if (fptr == NULL){
			endwin();
			printf("file cannot be read\n");
			exit(EXIT_FAILURE);
		}
		for(int i = 0; i<30; i++){
			for(int j = 0; j<80; j++){

				ch = fgetc(fptr);
				mvaddch(i,j,ch);
				
			}
		}
	
	}
	
	if (i==2){
                fptr = fopen("level2.txt","r");

                if (fptr == NULL){
                        endwin();
                        printf("file cannot be read\n");
                        exit(EXIT_FAILURE);
                }
                for(int i = 0; i<30; i++){
                        for(int j = 0; j<80; j++){

                                ch = fgetc(fptr);
                                mvaddch(i,j,ch);

                        }
                }

        }

	if (i==3){
                fptr = fopen("level3.txt","r");

                if (fptr == NULL){
                        endwin();
                        printf("file cannot be read\n");
                        exit(EXIT_FAILURE);
                }
                for(int i = 0; i<30; i++){
                        for(int j = 0; j<80; j++){

                                ch = fgetc(fptr);
                                mvaddch(i,j,ch);

                        }
                }

        }
	fclose(fptr);
		
}
