#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP 
#include <omp.h> 
#endif 

#define SIZE 2048


void init_ary(double m[SIZE][SIZE]){
    long i, j;

    for( i = 0; i < SIZE; i++ ){
	for( j = 0; j < SIZE; j++ ){
	    m[i][j] = i*SIZE+j+1;
	}
    }
    m[0][0] = -1;
}


void mul_ary( m, x, y )
double m[SIZE][SIZE], x[SIZE][SIZE], y[SIZE][SIZE];
{
    int i, j, k, NumT;
    double t;

    #pragma omp parallel
    NumT = omp_get_num_threads();
    printf("The number of thread is %d\n", NumT);
    
    t=omp_get_wtime();
    #pragma omp parallel for private(j,k) 
    for( i = 0; i < SIZE; i++ ){
	for( j = 0; j < SIZE; j++ ){
	    m[i][j] = 0.0;
	    for( k = 0; k < SIZE; k++ ){
		m[i][j] += x[i][k] * y[k][j];
	    }
	}
    }
    t=omp_get_wtime()-t;
    printf( "t=%f sec\n", t );
}


void main(){
    double (*a)[SIZE], (*x)[SIZE], (*y)[SIZE];
    double km[4][4]={{2,-2,4,2},{2,-1,6,3},{3,-2,12,12},{-1,3,-4,4}};
    double proctime;

    a = malloc( (long)sizeof(double) * SIZE * SIZE );
    x = malloc( (long)sizeof(double) * SIZE * SIZE );
    y = malloc( (long)sizeof(double) * SIZE * SIZE );

    if( (long)a+(long)x+(long)y == 0 )
	printf( "malloc error\n" );

    init_ary( x ); 	/* prnt_ary( x, "x" );	*/
    init_ary( y );	/* prnt_ary( y, "y" );	*/

    proctime = omp_get_wtime();
    mul_ary( a, x, y );
    proctime = omp_get_wtime() - proctime;
    printf( "det(km) = %e\t%f Second\n", a[0][0], proctime );
}

