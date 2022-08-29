#include<stdio.h>
#include<math.h>

/*
	fabs() = used to find absolute value of float type values
*/

int main(){

	float t_val, a_val;
	
	printf( "\nEnter True Value: " );
	scanf( "%f", &t_val );
	printf( "\nEnter Absolute Value: " );
	scanf( "%f", &a_val );
	
	float abs_err = fabs( t_val - a_val );
	float rel_err = fabs( abs_err / t_val );
	float per_err = rel_err *100;
	
	printf( "\nAbsolute Error: %f", abs_err );
	printf( "\nRelative Error: %f", rel_err );
	printf( "\nPercentage Error: %f\n", per_err );

	return 0;
}
