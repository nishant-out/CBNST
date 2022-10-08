#include<stdio.h>
#include<math.h>
#define MAX_ITR 100
# define EPSILON 0.0001 //  Tolerance - Means upto 3 decimal places

//	Secant method Or Chord method in C lang.	( for finding Roots )

float f( float x ){
	return x*x*x - 5*x +1;
}

float formula( float x1, float x2 ){
    return ( x1 * f( x2 ) - x2 * f( x1 ) )/ (f( x2 ) - f( x1 )) ;
}

float secant( float x0, float x1 ){
    int itr = 1;
    float x;

    //  Using Previous Roots to find next approx.
	while( itr < MAX_ITR ){
		printf( "\nIteration %d: \n\t", itr++ );
 		printf( "x: %f", x );
		
		x = formula( x0, x1 );
		
		if( fabs( x - x1 ) < EPSILON )
		    return x;

        x0 = x1;
        x1 = x;
	}

    return x;
}

int main( ){

	int itr = 1;
	float x0 = 1, x1 = 2;	//  for eqn in f

    do{
        printf( "\nEnter x0 & x1: " );
        scanf( "%f %f", &x0, &x1 );
        
        if( f( x0 ) * f( x1 ) > 0 )
    		printf( "\nNot valid Interval !!!!! Try Again !!!!!\n" );
	    else
	        break;
        
	}while( 1 ); //  For finding x0 & x1
	

    float root = secant( x0, x1 );

	printf("\n\nRoot: %f\n\n", root );
	return 0;
}

