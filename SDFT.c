// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
    // the input discrete signal x[n]
    int x[10] = {1, -5, 2, 7, 1, 7, 2, 4, 0, 9};
    printf("the x[n] = ");
    for (int i = 0;i< 10; i++){
        printf("%d\t",x[i]);
    }
    printf("\n");

    int N = 5;
    int Wind_arrays[6][N]; // array of arrays window
    // Create the sliding window
    for(int i =0; i< 6 ; i++){
        printf("the %d window = ",i);
        for (int j=0; j<N ; j++){
            Wind_arrays[i][j] = x[i+j];
            printf("%d\t",Wind_arrays[i][j]);
        }
        printf("\n");
    }

    //Compute A[k] using DFT
    printf("\n");
    complex A_k[5];
    printf("A[k]\n");
    for (int k = 0 ; k < 5; k ++){
        complex sum = 0 ;
        for(int n = 0; n < 5 ; n ++){
            complex e = Wind_arrays[0][n] * (cos((2*M_PI*n*k)/N) -I* sin((2*M_PI*k*n)/N));
            sum = sum + e;
        }
        A_k[k] = sum;
        printf("A[%d] = %f +%fj\n",k,creal(sum), cimag(sum));
    }

    //Compute B[k] using sliding DFT
    printf("\n");
    printf("B[k]\n");
    complex B_k[5];
    for (int k = 0 ; k < 5; k ++){
        B_k[k] = A_k[k] + Wind_arrays[1][4] - Wind_arrays[0][0];
        B_k[k] = B_k[k] * (cos((2*M_PI*k)/N) + I*sin((2*M_PI*k)/N));
        printf("B[%d] = %f +%fj\n",k,creal(B_k[k]), cimag(B_k[k]));
    }

    //Compute C[k] using sliding DFT
    printf("\n");
    printf("C[k]\n");
    complex C_k[5];
    for (int k = 0 ; k < 5; k ++){
        C_k[k] = B_k[k] + Wind_arrays[2][4] - Wind_arrays[1][0];
        C_k[k] = C_k[k] * (cos((2*M_PI*k)/N) + I*sin((2*M_PI*k)/N));
        printf("C[%d] = %f +%fj\n",k,creal(C_k[k]), cimag(C_k[k]));
    }

    //Compute D[k] using sliding DFT
    printf("\n");
    printf("D[k]\n");
    complex D_k[5];
    for (int k = 0 ; k < 5; k ++){
        D_k[k] = C_k[k] + Wind_arrays[3][4] - Wind_arrays[2][0];
        D_k[k] = D_k[k] * (cos((2*M_PI*k)/N) + I*sin((2*M_PI*k)/N));
        printf("D[%d] = %f +%fj\n",k,creal(D_k[k]), cimag(D_k[k]));
    }

    //Compute E[k] using sliding DFT
    printf("\n");
    printf("E[k]\n");
    complex E_k[5];
    for (int k = 0 ; k < 5; k ++){
        E_k[k] = D_k[k] + Wind_arrays[4][4] - Wind_arrays[3][0];
        E_k[k] = E_k[k] * (cos((2*M_PI*k)/N) + I*sin((2*M_PI*k)/N));
        printf("E[%d] = %f +%fj\n",k,creal(E_k[k]), cimag(E_k[k]));
    }

    //Compute F[k] using sliding DFT
    printf("\n");
    printf("F[k]\n");
    complex F_k[5];
    for (int k = 0 ; k < 5; k ++){
        F_k[k] = E_k[k] + Wind_arrays[5][4] - Wind_arrays[4][0];
        F_k[k] = F_k[k] * (cos((2*M_PI*k)/N) + I*sin((2*M_PI*k)/N));
        printf("F[%d] = %f +%fj\n",k,creal(F_k[k]), cimag(F_k[k]));
    }

    return 0;
}
