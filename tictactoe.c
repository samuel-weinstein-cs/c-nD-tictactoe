#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int size;
const int dimensions;
const char chars[3]={' ', 'X', 'O'};
enum Move {
    None,
    X,
    O
};

enum Move * pos(int *pos, enum Move * board){
	for(int i=0; i<dimensions; i++){
		board += pos[i]*(int)pow(size,i+1);
	}
	return board;
}

char * draw(enum Move * board, int d){ //MUST FREE RESULT
	char * result = malloc(3);
	switch(d%2){
		case 0: //even dimension, vertical
			if(d==0){
				sprintf(result, " %c", chars[*board]);
				return result;
			} else {
				for(int i=0; i<size; i++){
					// do stuff
				}
			}
			break;
		case 1: //odd dimension, horizontal
			for(int i=0; i<size; i++){
				char *unit = draw//ah fuckkkkk this is so convoluted
				if(i!=size-1){
					
				} else {
					
				}
			}
			break;
	}
	return result;	
}


int main() {
	printf("enter size: ");
	scanf("%d",&size);
	printf("enter dimensions: ");
	scanf("%d", &dimensions);
	enum Move * board = calloc(sizeof(enum Move), (int)pow(size,dimensions));
	enum Move test = X;
	char *output = draw(&test, 0);
	printf("%s", output);
	free(output);//MUST free result from draw
	return 0;
}
