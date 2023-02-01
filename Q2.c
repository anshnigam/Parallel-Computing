#include<stdio.h>
#include<omp.h>
int main(){
    int x=4,y=3;
    omp_set_num_threads(4);
    #pragma omp parallel 
    { 
        double t1 = omp_get_wtime();
        printf("hello world from thread Number: %d\n",omp_get_thread_num());
        if(omp_get_thread_num() == 0){
            printf("Sum: %d\n",x+y);
            double t2 = omp_get_wtime();
            printf("Elapsed time: %lf\n",(t2-t1));
        }
        else if(omp_get_thread_num() == 1){
            printf("Difference: %d\n",x-y);
            double t2 = omp_get_wtime();
            printf("Elapsed time: %lf\n",(t2-t1));
        }
        else if(omp_get_thread_num() == 2){
            printf("Product: %d\n",x*y);
            double t2 = omp_get_wtime();
            printf("Elapsed time: %lf\n",(t2-t1));
        }
        else {
            printf("Quotient: %d and Remainder: %d\n",x/y,x%y);
            double t2 = omp_get_wtime();
            printf("Elapsed time: %lf\n",(t2-t1));
        }
    }
}
