#include <stdio.h>
#include <stdlib.h>
#define N 5
// Piezas para condiciones

int isOdd( int item, int * A ) {
	return ( A[ item ] & 1 ) == 1 ? 1 : 0; 
} 

// Funciones para pruebas
void printArray( int * A, int size ) {
	printf("[");
	for( register int i = 0; i < size; i++ )
        if( i != size-1 )
		    printf( "%d,", A[i] );
        else
            printf( "%d", A[i] );
    printf("]\n");
} 

// Funciones indispensables para el funcionamiento
void swap( int ini, int replace, int * A ) {
	int aux = -1;
	aux = A[ ini ];
	A[ ini ] = A[ replace ];
	A[ replace ] = aux;
}

int orderRight( int ini, int end, int * A  ) {
	
	for( register int i = end; i > ini; i-- ) {
		
		// printf( "R%d - %d\n", A[ ini ], A[ i ] );
		if( !isOdd( i, A ) ) {
			swap( ini, i, A );
			return i;
		}

	}
	return -1;
}

int orderLeft( int ini, int end, int * A ) {

	for( register int i = ini; i < end; i++ ) {

		if( isOdd( i, A ) ) {
			swap( end, i, A );
			return i;
		}
	}

	return -1;
}

// Determinar la posición final de un elemento en el arreglo
int determinePosition( int ini, int end, int * A  ) {

	int pivot  = ini;

	do {
		int aux1   = orderRight( ini, end, A );
		int aux3   = aux1 == -1 ? ini : ini+1;
		int aux4   = aux1 == -1 ? ini : aux1;  
		
		int aux2  = orderLeft ( aux3, aux4, A );

		pivot = aux2 != -1 ? aux2 : aux1 != -1 ? aux1 : ini;

		if( aux2 == -1 && aux1 == -1)
			break;

		if( aux2 != -1 )
			ini = aux2;
		else
			ini = aux1;
		
	} while( 1 );

	return pivot;
}


void quicksort( int ini, int end, int * A ) {

	if( ini != end ) {	

		int pivot = determinePosition( ini, end, A );

		if( (pivot - ini) >= 2 )
			quicksort( ini, pivot-1, A );
		
		if( pivot+1 < end ) 
			quicksort( pivot+1, end, A );

	}
}

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    
    int ini = 0;
    int end = ASize;

    quicksort( ini, end-1, A );

    return A;
}

int main() {


	int array[ N ];

	for( register int i = 0;  i < N; i ++ ) {
		array[ i ] = (rand() % N) + 1;
	}

	printArray(array, N);

	int size = N;
	sortArrayByParity( array, N, &size );

	printArray(array, N);


	return 0;
}