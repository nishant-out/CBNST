#include<stdio.h>
#include<math.h>
#define MAX_ITR 100
# define EPSILON 0.0001 //  Tolerance - Means upto 3 decimal places

//  Ref:    https://www.youtube.com/watch?v=b70Op6iZh2s&list=PLVKIC9j3jSYsm8GELqAMFJ_1ebbMpK-9U&index=5
//	Newton Raphson method in C lang.	( for finding Roots )

float f( float x ){
	return x*x*x - 3*x -5;
}

float diff( float x ){
    return 3*x*x -3 ;
}

float newtonRaphson( float x0, float x1 ){
    int itr = 1;
    float prev_x, new_x;
    /*  3 ways to pick prev_x
    
            1.  any point b/w x0 & x1
            2.  pick mid pt. of x0 & x1
            3.  below implemented
    */
    if( fabs( x0 ) < fabs( x1 ) )
        prev_x = x0;
    else
        prev_x = x1;
    
    //  Successive Approximation
	while( itr < MAX_ITR ){
		printf( "\nIteration %d: \n\t", itr++ );
 		printf( "x: %f", prev_x );
		
		new_x = prev_x - f( prev_x ) / diff( prev_x );
		
		if( fabs( new_x - prev_x ) < EPSILON )
		    return new_x;

        prev_x = new_x;
	}

    return new_x;
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
	

    float root = newtonRaphson( x0, x1 );

	printf("\n\nRoot: %f\n\n", root );
	return 0;
}

