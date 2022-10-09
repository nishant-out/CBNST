#include<stdio.h>
#include<math.h>

//	Gauss Elim. method in C lang.	( for finding unknowns in a sys. of linear eqn's )
int n = 3;

void print( float aug[][ n +1] ){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            printf( "%.1f ", aug[ i ][ j ] );
        printf( "\n" );
    }
    printf( "\n" );
}

void swap_row(float mat[][ n +1], int i, int j){
    // printf("Swapped rows %d and %d\n", i, j);
 
    for (int k = 0; k <= n; k++){
        
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

void gaussElim( float aug[][ n +1], float values[] ){

    //  Convert augmented matrix to upper triangular
    for (int i = 0; i < n; i++) {
        for (int j = i +1; j < n; j++) {
            
            float ratio = aug[ j ][ i ] / aug[ i ][ i ];
            for (int k = 0; k <= n; k++)
                aug[ j ][ k ] = aug[ j ][ k ] - ( ratio * aug[ i ][ k ] );
            
            if( (j +1) < n && aug[ j ][ j ] == 0 ){ //  Doesn't work if Swapped row also has 0 at ( j, j ) 
                swap_row( aug, j, j +1 );
                j--;
            }
            
            printf( "Intermediate steps.......\n" );
            print( aug );
        }
    }
    
    // 2   -1   1   : 10
    // 0   1   1.5  : 3
    // 0   0   -2   : -10
    //  Perform backSubstitution to fill values of variables
    for (int i = n -1; i >= 0; i--){
        
        float sum = aug[ i ][ n ];
        
        for (int j = i +1; j < n; j++){
            sum -= ( aug[ i ][ j ] * values[ j ] );
        }
        
        values[ i ] = sum / aug[ i ][ i ];
    }
}

int main( ){
/*
1 1 1 7
3 3 4 24
2 1 3 16

6 -1 1 13
1 1 1 9
10 1 -1 19
*/
	float aug[ n ][ n +1];

    printf( "Enter sys of eqn's......\n" );
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf( "%f", &aug[ i ][ j ] );

    float values[ n ];
    gaussElim( aug, values );

	printf("\nx: %.1f", values[ 0 ] );
	printf("\ny: %.1f", values[ 1 ] );
	printf("\nz: %.1f", values[ 2 ] );
	
	return 0;
}









