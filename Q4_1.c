#include<stdio.h>
#include<omp.h>

int main(){
    int n = 5, a= 1; // shared vars
    int b=0;
    printf("Before pragma, b's value is 0");
    // shared
    printf("\nParallel section");
    #pragma omp parallel for shared(n,a) private(b)
    for(int i=0;i<n;i++){   //i is also prib=vate
        b=a+i;
        printf("\nb (private var)'s value: %d",b); // b has value here
    }
    printf("\nOutside pragma, b's value is back to 0\n");

}