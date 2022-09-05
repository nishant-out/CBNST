#include<stdio.h>
#include<math.h>

//	Bisection method in C lang.	( for finding Roots )

float coef[ 3 ];
float power[ 3 ];

float fn( float x ){
	float ans = 0;
	
	for(int i = 0; i < 3; i++){
		ans += coef[ i ] * pow( x, power[ i ] ) ;
	}
	return ans;
}

int main( ){

	int itr = 1;
	float x0 = 0, x1 = 1, x;	
	float all_err = .01;
	
	for( int i = 0; i < 3; i++ ){
		scanf( "%f", &coef[ i ] );
		scanf( "%f", &power[ i ] );
	}
	
//	while( ! ( fn( x0 ) * fn( x1 ) < 0 ) ){
//	}
	if( fn( x0 ) * fn( x1 ) > 0 ){
		printf( "\nNot valid Interval !!!!! Try Again !!!!!\n" );
		return 0;
	}

	do{
		printf( "\nIteration %d: \n\t", itr++ );
		printf( "x0: %f, f( x0 ): %f", x0, fn( x0 ) );
		printf( ", x1: %f, f( x1 ): %f", x1, fn( x1 ) );
		
		x = ( x0 + x1 ) /2;
		
		if( fn( x0 ) * fn( x ) < 0 )
			x1 = x;
		if( fn( x ) * fn( x1 ) < 0 )
			x0 = x;

	}while( ! (fn( x ) <= all_err) ) ;
		
	printf("\n\n");
	return 0;
}










