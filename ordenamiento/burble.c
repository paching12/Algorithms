#include <stdio.h>
#include <stdlib.h>
#define N 100000


// Funciones para pruebas
void printArray( int * A, int size ) {
	printf("= ");
	for( register int i = 0; i < N; i++ )
		printf( "%d ", A[i] );

	printf(" =\n");
} 

int main() {

	int array[ N ];

	for( register int i = 0;  i < N; i ++ )
		array[ i ] = (rand() % N) + 1;

	for( register int i = 0; i < N; i++ ) 
		for( register int j = 1; j < N; j++ ) 
			if( array[ i ] < array[ j ] ) {
				int aux = array[ i ];
				array[ i ] = array[ j ];
				array[ j ] = aux;
			}

	return 0;
}