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

float Bisection( float x0, float x1, float tol ){
    int itr = 1;
    
	do{
		printf( "\nIteration %d: \n\t", itr++ );
		printf( "x0: %f, f( x0 ): %f", x0, fn( x0 ) );
		printf( ", x1: %f, f( x1 ): %f", x1, fn( x1 ) );
// 		printf( ", %f - %f = %f", x0, x1, fabs( x0 - x1 ) );
		
		float x = ( x0 + x1 ) /2.0;
		
		if( fabs( x0 - x1 ) <= tol )
		    return x;
		
		if( fn( x0 ) * fn( x ) < 0 )
			x1 = x;
			
		if( fn( x ) * fn( x1 ) < 0 )
			x0 = x;

	}while( itr < 100 ) ;
		
    return 0.0;
}

int main( ){

	int itr = 1;
	float x0 = 1, x1 = 2;	
	float tol = 0.0001;    //  Tolerance
	
	coef[ 0 ] = 1;
	coef[ 1 ] = -1;
	coef[ 2 ] = -2;
	power[ 0 ] = 3;
	power[ 1 ] = 1;
	power[ 2 ] = 0;
	
// 	for( int i = 0; i < 3; i++ ){
// 		scanf( "%f", &coef[ i ] );
// 		scanf( "%f", &power[ i ] );
// 	}
	
//	 while( ! ( fn( x0 ) * fn( x1 ) < 0 ) ){ //  For finding x0 & x1
//	}
	if( fn( x0 ) * fn( x1 ) > 0 ){
		printf( "\nNot valid Interval !!!!! Try Again !!!!!\n" );
		return 0;
	}

    float root = Bisection( x0, x1, tol );

	printf("\n\nRoot: %f\n\n", root );
	return 0;
}









