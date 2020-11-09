#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define FOREVER 1
// Piezas para condiciones

/* @brief: Compare A[ pivot ] is greather than now position   
*
*	@params <int> now, <int> pivot, <int *> Array values
*	@return <int> condition value
*  
*/
int conditionGreatherThan( int now, int pivot, int * A ) {
	return ( A[ pivot ] > A[ now ] ) ? 1 : 0; 
} 

// Funciones para pruebas
void printArray( int * A, int size ) {
	printf("= ");
	for( register int i = 0; i < N; i++ )
		printf( "%d ", A[i] );

	printf(" =\n");
} 

/* @brief: Change values in the arra A[ini] = A[replace] 
*	using pass by reference
*	@params <int> now, <int> pivot, <int *> Array values
*	@return <void>
*  
*/
// Funciones indispensables para el funcionamiento
void swap( int ini, int replace, int * A ) {
	int aux = -1;
	aux = A[ ini ];
	A[ ini ] = A[ replace ];
	A[ replace ] = aux;
}

/* @brief: Compare and swap if the condition is true      
*
*	It'll return -1 if the condition never meets. 
*   
*	@params <int> position pivot, position start
*	@return <int> pivot | <int> -1
*  
*/
int orderRight( int ini, int end, int * A  ) {	
	for( register int i = end; i > ini; i-- )
		if( conditionGreatherThan( i, ini, A ) ) {
			swap( ini, i, A );
			return i;
		}
	return -1;
}

/* @brief: Compare and swap if the condition is true  
*   It'll return -1 if the condition never meets. 
*   
*	@params <int> position pivot, position start
*	@return <int> pivot | <int> -1
*  
*/
int orderLeft( int ini, int end, int * A ) {

	for( register int i = ini; i < end; i++ ) 
		if( conditionGreatherThan( end, i, A ) ) {
			swap( end, i, A );
			return i;
		}

	return -1;
}


/* @brief: Determine the final position of one item
*	using pass by reference
*	@params <int> now, <int> pivot, <int *> Array values
*	@return <void>
*  
*/
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
		
	} while( FOREVER );

	return pivot;
}


void quicksort( int ini, int end, int * A ) {

	if( ini != end ) {	

		// Step 1
		int pivot = determinePosition( ini, end, A );

		// Step 2
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

	int size = N;
	sortArrayByParity( array, N, &size );

	return 0;
}