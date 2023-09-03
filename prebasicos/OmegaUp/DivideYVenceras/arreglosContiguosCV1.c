#include <stdio.h>
#include <stdlib.h>
// long * A;
long A[] = {-2, -5, 6, -2, -3, 1, 5, -6};
long max( long n1, long n2 ) {return ( n1 >=  n2 ) ? n1 : n2;}
long lsc(long inicio, long fin ) {
	if( fin == inicio ) return A[inicio];
	long mitad = (inicio+fin)/2;
	long sumaIzq = 0, sumaDer = 0;
	long izq = lsc( inicio, mitad ), der = lsc( mitad+1, fin ), i, tmp = A[inicio], suma = 0;
	sumaIzq = A[ mitad ];
	sumaDer = A[ mitad+1 ];
	for( i = mitad; i >= inicio; i-- ){suma += A[i];if( suma > sumaIzq ) sumaIzq = suma;}
	suma = 0;
	for( i = mitad+1; i <= fin; i++ ){suma += A[i];if( suma > sumaDer ) sumaDer = suma;}
	return max( max( izq, der ), ( sumaIzq + sumaDer ) );}
int main() {
	// long i;
	// long n = 0;
	// scanf( "%ld", &n );
	// A = (long*)malloc( n* sizeof(long) );
	// for( i = 0; i < n; i++ ) scanf("%ld", &A[ i ] );
    int n = sizeof(A) / sizeof(A[0]);
	printf( "%ld", lsc( 0, n-1 ) );
	return 0;}