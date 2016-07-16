/*
 * 260674863.c
 *
 *  Created on: Feb 20, 2016
 *      Author: kille_000
 */

//the text editor is Eclipse and the compiler is MinGW

#include <stdio.h>
#include <string.h>
#define INPUTFILE "moves.txt"
#define OUTPUTFILE "result.txt"
#define ROWS 3
#define COLS 3


void print_board (char tic_tac_toe[ROWS][COLS]){
	int i, j;
	FILE *file2;
	file2= fopen(OUTPUTFILE, "a");

	if (file2 == NULL){
	printf("Error opening input file. \n");
	}

	for(i = 0; i < 3; i++){				//nested loop which spans the rows and columns
			for(j = 0; j < 3; j++){		//if there is an input of X or O and column is less than 2 it prints the character
			if(((tic_tac_toe[i][j] == 'X')||(tic_tac_toe[i][j] == 'O')) && j<2){
				fprintf(file2, "%c|", tic_tac_toe[i][j]);
			}
			else if(j<2){		//if there is no input then it prints a dot
				fprintf(file2, ".|");
			}
			if(((tic_tac_toe[i][j] == 'X')||(tic_tac_toe[i][j] == 'O')) && j==2){
				fprintf(file2, "%c", tic_tac_toe[i][j]);	//if the columns are equal to 2 it does not print a |
			            }
			else if(j==2){
				fprintf(file2, ".");
			}
		}
		fprintf(file2, "\n");
	}
	fclose(file2);
	return;
}


int has_won (char tic_tac_toe[ROWS][COLS]){   //there are 8 winning configurations for tic-tac-toe

	int i, j;

	for(j=0; j<3; ++j){
		if(tic_tac_toe[0][j] == 'X'||tic_tac_toe[0][j] == 'O'){
			if((tic_tac_toe[0][j]==tic_tac_toe[1][j])&&		//if the input is X or O it checks column for three same chars
			   (tic_tac_toe[1][j]==tic_tac_toe[2][j])){
				return 1;
			}
		}
	}
	for(i=0; i<3; ++i){
		if(tic_tac_toe[i][0] == 'X'||tic_tac_toe[i][0] == 'O'){
			if((tic_tac_toe[i][0]==tic_tac_toe[i][1])&&		//if the input is X or O it checks row for three same chars
				(tic_tac_toe[i][1]==tic_tac_toe[i][2])){
				return 1;
			}
		}
	}
	if(tic_tac_toe[1][1] == 'X'||tic_tac_toe[1][1] == 'O'){
		if((tic_tac_toe[0][0]==tic_tac_toe[1][1])&&		//if the input is X or O it checks first diagonal for three same chars
			(tic_tac_toe[1][1]==tic_tac_toe[2][2])){
				return 1;
		}
		else if((tic_tac_toe[0][2]==tic_tac_toe[1][1])&&
				(tic_tac_toe[1][1]==tic_tac_toe[2][0])){	//if the input is X or O it checks second diagonal for three same chars
				return 1;
		}
	}
	return 0;
}

int is_valid_move (char tic_tac_toe[3][3], int x, int y){
	if ((x < 0) || (x >= 3)){		//Illegal row position
	return 1;
	}

	else if ((y < 0) || (y >= 3)){		//Illegal column position
	return 1;
	}

	else if ((tic_tac_toe[x][y] == 'X')||(tic_tac_toe[x][y] == 'O')){		//Character already in position
	return 1;
	}

	return 0;
}

int main () {
	int x, y, n = 0;
	char tic_tac_toe[ROWS][COLS];

	FILE *file1;
	FILE *file2;
	file1= fopen(INPUTFILE,"r");

	if (file1 == NULL){
		printf("Error opening input file. \n");
	}

	while(fscanf(file1,"%d %d", &x, &y)==2){    //it scans for two inputs from the moves file
		if (is_valid_move(tic_tac_toe, x, y)==1){  //it checks whether move is valid
			file2= fopen(OUTPUTFILE, "a");
			if (file2 == NULL){
			printf("Error opening input file. \n");
			}
			fprintf(file2, "Wrong Move");
			fclose(file2);
			return 0;
		}
		if(n%2 == 0){			//it assigns even rows as char X
			tic_tac_toe[x][y]='X';
		}
		else if(n%2 != 0){		//it assigns odd rows as char O
			tic_tac_toe[x][y]='O';
		}
		n++;

		if((has_won(tic_tac_toe))==1){			//it checks whether move is valid
			file2= fopen(OUTPUTFILE, "a");
			if (file2 == NULL){
			printf("Error opening input file. \n");
			}
			fprintf(file2, "%c Wins\n\n", tic_tac_toe[x][y]);
			fclose(file2);
			print_board (tic_tac_toe);
			fclose(file1);
			return 0;
		}

		if((n==9)&&((has_won(tic_tac_toe))==0)){	//if moves are 9 and the game has not been won, its a draw
			file2= fopen(OUTPUTFILE, "a");
			if (file2 == NULL){
			printf("Error opening input file. \n");
			}
			fprintf(file2, "Draw\n\n");
			fclose(file2);
			print_board (tic_tac_toe);
			fclose(file1);
			return 0;
		}
	}

	file2= fopen(OUTPUTFILE, "a");		//if both conditions are not met, then it is incomplete game
	if (file2 == NULL){
	printf("Error opening input file. \n");
	}
	fprintf(file2, "Incomplete Game\n\n");
	fclose(file2);
	print_board (tic_tac_toe);
	fclose(file1);
	return 0;
}
