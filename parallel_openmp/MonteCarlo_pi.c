#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP 
#include <omp.h> 
#endif 
#define ITER (512*1024*1024)

double generate_double(unsigned long *seed){
    *seed = ((16807 * (*seed))) % 2147483647;
    return (double) (*seed) / 2147483647;
}

main()
{
    int numthreads, MyID;
    int sum=0, seed = 10;
    double x, y;
    numthreads = omp_get_num_threads();
    double proctime = omp_get_wtime();
    
    #pragma omp parallel
    {
	long local_seed = seed + omp_get_thread_num();
        #pragma omp for private(x,y) reduction(+:sum)
        for (int i=0; i < ITER; ++i) {
            x = generate_double(&local_seed);
            y = generate_double(&local_seed);

            if ( x*x+y*y<= 1) {
                sum++;
            }
        }
    }
    printf("Process time: %f\n", omp_get_wtime()-proctime);
    printf( "PI=%f\n", 4.0*sum/ITER );
}

