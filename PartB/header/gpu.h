// Create other necessary functions here
//  a nd b are matrices having data and calculate diagonal data is stored in c matrix

__global__ void multi(int N, int *a, int *b, int *c){
  int row = blockIdx.x * blockDim.x + threadIdx.x;

  if(row < N)
  {
  int temp = 0;
  for (int k = 0; k < row + 1; k++) {
        temp += a[k * N + row - k] * b[(row - k) * N + (N - k - 1)];
          }
      c[row] = temp;
  }
  else if (row >= N && row < 2 * N - 1 ){
  int temp = 0;
  for(int k = 0;k < 2 * N - (row + 1);k++)
{
  temp += a[(row + 1 + k -N) * N + (N - k - 1)] * b[(N - k -1) * N + (2 * N - k - 2 -row)];
}
  c[row] = temp;
}
}
// Fill in this function
void gpuThread(int N, int *matA, int *matB, int *output)
{

size_t bytes = N * N * sizeof(int);
size_t byte1 = (2 * N - 1) * sizeof(int);
      
// Allocate device memory
int *d_a, *d_b, *d_c;
cudaMalloc((void**)&d_a, bytes);
cudaMalloc((void**)&d_b, bytes);
cudaMalloc((void**)&d_c, byte1);
    
// Copy data to the device 
cudaMemcpy(d_a, matA, bytes, cudaMemcpyHostToDevice);
cudaMemcpy(d_b, matB, bytes, cudaMemcpyHostToDevice);

int THREADS = 32;

int BLOCKS = (2 * N - 1 + 31)/THREADS;

multi<<<BLOCKS,THREADS>>>(N,d_a,d_b,d_c);

//copy data back to the host
cudaMemcpy(output, d_c, byte1, cudaMemcpyDeviceToHost);

//successfull message
//cout<<"Completed Successfully\n";

//Free memory on device
cudaFree(d_a);
cudaFree(d_b);
cudaFree(d_c);

}

                                                                       

