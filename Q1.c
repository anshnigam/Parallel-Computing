#include<stdio.h>
#include<omp.h>
void main(){
    #pragma omp parallel
    {
        printf("Hello world\n");
        printf("Number of threads: %d\n",omp_get_num_threads());
        printf("Thread Number: %d\n",omp_get_thread_num());
        printf("Number of procesors: %d\n",omp_get_num_procs());
        printf("Maximum number of threads: %d\n",omp_get_max_threads());
    }
}
