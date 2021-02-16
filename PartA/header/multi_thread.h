#include <pthread.h>
// Create other necessary functions here
#define Nthread 10
     int N;
     int *matA;
     int *matB;
     int *output;
     
struct arg_struct {
     int m;
     int *arr;
};

void *multFunction( void *arguments)
{
       struct arg_struct *args = (struct arg_struct *)arguments;
       // Iterate over first half of output elements
   for(int i = 0 ; i < N;i += 16){
     for(int j = 0; j <= i;j +=16){
       if( (i + j) % Nthread == args -> m){
         for(int k = i;k<i+16;k++){
           for(int l = j;l<j+16;l++){
             int rowA = N-1-l;
             int colA = k;
             int rowB = k;
             int colB = l;
             output[rowA+colA]+= matA[rowA * N + colA] * matB[rowB * N + colB];
         }
       }
      }
     }
   }
     // Iterate over second half of output elements
   for (int i = 0; i < N; i+=16) {
     for(int j = i+16; j< N; j+=16){
        if( (i + j) % Nthread == args -> m){
           for(int k =i;k<i+16;k++){
             for(int l = j;l<j+16;l++){
               int rowA = N-1-l;
               int colA = k;
               int rowB = k;
               int colB = l;
               output[rowA+colA]+= matA[rowA * N + colA] * matB[rowB * N + colB];
             }
        }
       }
     }
   }
    pthread_exit(NULL);
}
// Fill in this function
void multiThread(int N, int *matA, int *matB, int *output)
{
    ::N = N;
    ::matA = matA;
    ::matB = matB;
    ::output = output;
    
    pthread_t threads[Nthread];
    struct arg_struct args[Nthread];
    
    for(int i = 0; i < Nthread; i++){
       pthread_create( &threads[i], NULL, &multFunction, &args[i]);
    }
    
    for(int j = 0; j < Nthread; j++){
       pthread_join( threads[j], NULL);
    }
}
