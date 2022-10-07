#include<stdio.h>
#include<math.h>
# define EPSILON 0.0001 //  Tolerance - Means upto 3 decimal places

//	Regula Falsi method in C lang.	( for finding Roots )

float f( float x ){

	return x*x*x -x -1;
}

float formula( float x1, float x2 ){
    
    return ( x1 * f( x2 ) - x2 * f( x1 ) )/ (f( x2 ) - f( x1 )) ;
}

float falsi( float x0, float x1 ){
    int itr = 1;
    float x = formula( x0, x1 );
    
	do{
		printf( "\nIteration %d: \n\t", itr++ );
		printf( "x0: %f, f( x0 ): %f", x0, f( x0 ) );
		printf( ", x1: %f, f( x1 ): %f", x1, f( x1 ) );
// 		printf( ", %f - %f = %f", x0, x1, fabs( x0 - x1 ) );
		
		if( f( x0 ) * f( x ) < 0 )
			x1 = x;
		
		else
			x0 = x;
		
		float x3 = formula( x0, x1 );
		
		if( fabs( x3 - x ) < EPSILON )
		    return x;

        x = x3;
	}while( itr < 12 ) ;
		
    return 0.0;
}

int main( ){

	int itr = 1;
	float x0 = 1, x1 = 2;	//  for eqn in f

    do{
        printf( "\nEnter x0 & x1: " );
        scanf( "%f %f", &x0, &x1 );
        
        if( f( x0 ) * f( x1 ) > 0 ){
    		printf( "\nNot valid Interval !!!!! Try Again !!!!!\n" );
	    }
	    else
	        break;
        
	}while( 1 ); //  For finding x0 & x1
	

    float root = falsi( x0, x1 );

	printf("\n\nRoot: %f\n\n", root );
	return 0;
}


