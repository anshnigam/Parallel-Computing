#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
int main(){
    int arr[50];
    for(int i=0;i<50;i++){
        arr[i] = rand()%50;
    }
    omp_set_num_threads(7);
    #pragma omp parallel
    {   double t1 = omp_get_wtime();
        int tid = omp_get_thread_num();
        if(tid == 0){
            printf("Array elements are: ");
            for(int i=0;i<50;i++) printf("%d ",arr[i]);
            printf("\nMultiplied all elements by 3: ");
            for(int i=0;i<50;i++) printf("%d ",3*arr[i]);
            printf("\n");
            printf("Time taken: %lf\n",(omp_get_wtime()-t1));
            printf("______________________________________________________\n");
        }
        if(tid == 1){
            int sum=0,osum=0,esum=0;
            for(int i=0;i<50;i++){
            sum += arr[i];
            if(arr[i]%2 == 0){
            esum += arr[i];
            }
            else osum += arr[i];
            }
            #pragma omp critical
            {
                printf("Sum of all: %d",sum );
                printf("\nSum of evens: %d",esum );
                printf("\nSum of odd: %d\n",osum );
                printf("Time taken: %lf\n",(omp_get_wtime()-t1));
                printf("______________________________________________________\n");
            }
        }
        if(tid == 2){
            int oc=0,ec=0;
            for(int i=0;i<50;i++){
            if(arr[i]%2 == 0) ec++;
            else oc++;
            }
            #pragma omp critical
            {
                printf("Number of even: %d",ec );
                printf("\nNumber of odd: %d\n",oc );
                printf("Time taken: %lf\n",(omp_get_wtime()-t1));
                printf("______________________________________________________\n");
            }
        }
        if(tid == 3){
            int ss=0, cs=0;
            for(int i=0;i<50;i++){
            ss += (int)pow(arr[i],2);
            cs += (int)pow(arr[i],3);
            }
            #pragma omp critical
            {
                printf("Sum of cubes: %d, Sum of Squares: %d\n",cs,ss);
                printf("Time taken: %lf\n",(omp_get_wtime()-t1));
                printf("______________________________________________________\n");
            }
        }
        if(tid == 4){
            int max = -1, min = 10000000;
            for(int i=0;i<50;i++){
            if(max < arr[i]) max = arr[i];
            if(min > arr[i]) min = arr[i];
            }
            #pragma omp critical
            {
                printf("Maximum number: %d, Minimum number: %d\n",max,min);
                printf("Time taken: %lf\n",(omp_get_wtime()-t1));
                printf("______________________________________________________\n");
            }
        }
        if(tid == 5){
            int pct=0,psum=0;
            for(int i=0;i<50;i++){
                for(int j=2;j<=sqrt(arr[i]);j++){
                    if(arr[i]%j == 0){
                        pct++;
                        psum += arr[i];
                    }
                }
            }
            #pragma omp critical
            {
                printf("Number of prime numbers: %d and their sum is: %d.\n",pct,psum);
                printf("Time taken: %lf\n",(omp_get_wtime()-t1));
                printf("______________________________________________________\n");
            }
        }
        if(tid == 6){
            float mean = 0,var = 0;
            for(int i=0;i<50;i++){
                mean += arr[i];
            }
            mean /= 50;
            for(int i=0;i<50;i++){
                var += (arr[i] - mean)*(arr[i] - mean) ;
            }
            var /= 50;
            #pragma omp critical
            {
                printf("Mean: %.2f, Variance: %.2f, Standard deviation: %0.2f.\n",mean,var,sqrt(var));
                printf("Time taken: %lf\n",(omp_get_wtime()-t1));
                printf("______________________________________________________\n");
            }
        }
    }
}