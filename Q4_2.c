#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    int x = 34;
    printf("Entering firstprivate section with value x = %d.",x);
    #pragma omp parallel for firstprivate(x)
    for(int i=0;i<=10;i++){
        x=i;
        printf("\nThread number: %d     x: %d",omp_get_thread_num(),x);
    }
    printf("\nx after firstprivate: %d", x);

    x= 34;

    printf("\n\nEntering lastprivate section with value x = %d.",x);
    #pragma omp parallel for lastprivate(x)
    for(int i=0;i<=10;i++){
        x=i;
        printf("\nThread number: %d     x: %d",omp_get_thread_num(),x);
    }
    printf("\nx after lastprivate: %d", x);
    printf("\n");
}