# Performance-optimization-matrix-multiplication
Objective is to find the bottleneck in reference code and to optimize them for single thread, multiple thread and CUDA. All the extra implementation and optimization are present in headers of specific folder.
---------------------------------------
# Part A
This contains the optimization of single thread and multiple thread program of diagonal matrix multiplication. 
Single thread is optimization is done by making use of spatial locality of cache. In multiple thread the optimization was done considering the fact that there is no synchronization issue and achieve a lower cache miss.
---------------------------------------
# Part B
This part contain the cuda implementation of single thread program.
