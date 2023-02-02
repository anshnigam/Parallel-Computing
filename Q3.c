#include<stdio.h>
#include<omp.h>
int main(){
    int a,b,c;
    printf("Enter three numbers separated by space: ");
    scanf("%d %d %d",&a,&b,&c);
    double t1=0,t2=0;
    //serial approach.
    printf("\nOutput of serial approach.");
    t1 = omp_get_wtime();
    if(a >=b && a>=c)   printf("\nMaximum is %d",a);
    else if(b >=a && b>=c)  printf("\nMaximum is %d",b);
    else    printf("\nMaximum is %d",c);

    if(a <= b && a <= c)    printf("\nMinimum is %d",a);
    else if(b <= a && b <=c)    printf("\nMinimum id %d",b);
    else    printf("\nMinimum id %d",c);
    t2 = omp_get_wtime();
    printf("\nTime taken in serial approach: %lf",(t2-t1));

    //parallel approach.
    printf("\nOutput of parallel approach.");
    omp_set_num_threads(6);
    #pragma omp parallel
    {
        double t3=0,t4=0;
        t3 = omp_get_wtime();
        int tid = omp_get_thread_num();
        if(tid == 0 && a>b && a > c){
            printf("\nMaximum is %d",a);
            t4 = omp_get_wtime();
            printf("\nTime taken: %lf",(t4-t3));
        }
        if(tid == 1 && b>a && b>c){
            printf("\nMaximum is %d",b);
            t4 = omp_get_wtime();
            printf("\nTime taken: %lf",(t4-t3));
        }
        if(tid == 2 && c>b && c>a){
            printf("\nMaximum is %d",c);
            t4 = omp_get_wtime();
            printf("\nTime taken: %lf",(t4-t3));
        }
        if(tid == 3 && a<b && a<c){   
            printf("\nMinimum is %d",a);
            t4 = omp_get_wtime();
            printf("\nTime taken: %lf",(t4-t3)); 
        }
        if(tid == 4 && b<a && b<c){
            printf("\nMinimum is %d",b);
            t4 = omp_get_wtime();
            printf("\nTime taken: %lf",(t4-t3));  
        }
        if(tid == 5 && c<a && c<b){
            printf("\nMinimum is %d",c);
            t4 = omp_get_wtime();
            printf("\nTime taken: %lf",(t4-t3));
        }
    }
    printf("\n");
}