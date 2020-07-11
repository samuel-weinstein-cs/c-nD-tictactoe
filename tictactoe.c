#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char chars[3]={' ', 'X', 'O'};
int size;
int dimensions;


enum Move {
	None,
	X,
	O
};

enum Move * pos(int *pos, enum Move * board, int d){
	for(int i=0; i<d; i++){
		board += pos[i]*(int)pow(size,i+1);
	}
	return board;
}

char * draw(enum Move * board, int d){ //MUST FREE RESULT
	char * result = malloc(3);
	int coord[d];
	for(int i=0; i<d; i++){//initialize coord array
		coord[i]=0;
	}
	for(int i=0; i<size; i++){
		coord[d-1]=i;
		char *unit = draw(pos(coord, board, d), d-1);
		if(d==0){
			sprintf(result, " %c", chars[*board]);
			return result;
		} else {
			switch(d%2){
				case 0: //even dimension, vertical
					break;
				case 1: //odd dimension, horizontal
						result = realloc(result, strlen(result)+strlen(unit)+3);
						if(i!=size-1){
							sprintf(result, "| ");
						} else {
							sprintf(result, " ");
						}
					break;
			}
		}
	}
	return result;
}


int main() {
	printf("enter size: ");
	scanf("%d",&size);
	printf("enter dimensions: ");
	scanf("%d", &dimensions);
	enum Move * board = calloc(sizeof(enum Move), (int)pow(size,dimensions));
	// enum Move test = X;
	char *output = draw(board, dimensions);
	printf("%s", output);
	free(output);//MUST free result from draw
	return 0;
}
