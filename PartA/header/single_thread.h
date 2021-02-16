void singleThread(int N, int *matA, int *matB, int *output)
{
    // Iterate over first half of output elements
    for(int i = 0;i < 2*N-1;i++){
       output[i] = 0;
    }
   for(int i = 0 ; i < N;i += 16){
     for(int j = 0; j <= i;j +=16){
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
     // Iterate over second half of output elements
   for (int i = 0; i < N; i+=16) {
     for(int j = i+16; j< N; j+=16){
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
