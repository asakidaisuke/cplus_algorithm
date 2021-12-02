#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _OPENMP 
#include <omp.h> 
#endif 
#define ITER (512*1024*1024)

main(argc, argv )
int	argc;
char	*argv[];
{
    int    numthreads, MyID;
    int    i, j, sum=0;
    double x, y;

    #pragma omp parallel
    numthreads = omp_get_num_threads(); 
    double proctime = omp_get_wtime();
    int num_iter = ITER / numthreads;
    #pragma omp parallel private(i, x, y) reduction(+:sum) num_threads(numthreads)
    {
        unsigned short seed = omp_get_thread_num();
	for (int i=0; i < num_iter; ++i) {
	    float x = erand48(&seed);
            float y = erand48(&seed);
            if ( x*x+y*y<= 1) {
                sum++;
            }
        }
    }
    printf("Process time: %f\n", omp_get_wtime()-proctime);
    printf( "PI=%f\n", 4.0*sum/ITER );
}

