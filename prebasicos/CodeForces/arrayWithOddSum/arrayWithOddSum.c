#include <stdio.h>

int isOdd( int n ) {
	return (n & 1) == 1;
}

int main() {

	short int t = 0;
	short int n = 0;

	scanf("%hd", &t);

	while( t-- ) {
		
		scanf("%hd", &n);


		short int odd = 0, even = 0;
		short int sum = 0;
		short int a = 0;

		for( register int i = 0; i < n; i++ ) {
			scanf( "%hd", &a );
			sum += a;
			if( isOdd(a) )
				odd = 1;
			else
				even = 1;
		}

		if( !isOdd(sum) && even && odd )
			printf( "YES\n" );
		else if( isOdd(sum) && odd )
			printf("YES\n");
		else
			printf("NO\n");
	
	}

	return 0;
}
