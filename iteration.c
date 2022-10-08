#include<stdio.h>
#include<math.h>
# define EPSILON 0.0001 //  Tolerance - Means upto 3 decimal places

//	iteration method in C lang.	( for finding Roots )

float f( float x ){

	return x*x*x + x*x -1;
}

float fi( float x ){
    //  Value of fi function
    //  x^2( x +1 ) = 1
    //  x = _| 1/ (x +1) 
    return 1 / sqrt( x +1 ) ;
}

float diff( float x ){
    return -1 / (2 * pow( ( 1 + x ), 1.5 )) ;
}

float iteration( float x0, float x1 ){
    int itr = 1;
    float x = (x0 + x1) /2;
    
    //  check if iteration method can be applied or not
    if( fabs( diff( fi( x ) ) ) > 1 ){
        printf( "\nIteration method cann't be applied" );
        return 0.0;
    }
    
    float prev_x = x, new_x;
    // printf( "%f\n", prev_x );
    
	do{
		printf( "\nIteration %d: \n\t", itr++ );
 		printf( "x: %f", prev_x );
		
		new_x = fi( prev_x );
		
		if( fabs( new_x - prev_x ) < EPSILON )
		    return new_x;

        prev_x = new_x;
        
	}while( 1 ) ;
		
    return 0.0;
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
	

    float root = iteration( x0, x1 );

	printf("\n\nRoot: %f\n\n", root );
	return 0;
}

