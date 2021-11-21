# GoodTopics
This repo will contains implementation for some intersting topics in cpp

## MemoryCache
Run The MemoryCache.cpp example, you will notice that taking into consideration the "cache hit" will give you 3x better performance while looping on 3d image.

## BranchPrediction
Run The BranchPrediction.cpp example, you will notice that looping on the image twice is better than looping on image once with if condition inside loop as this will cause the branch predictor to predict to jump or not and it may predict wrong.

## SIMD (single instruction multiple data)
Run The SIMD.cpp example with compile option -msse3 you can found it in cmake script, you will notice that using simd is much faster and note that in simple operation like addition between two arrays simd will be overhead but once the instructions are more complex the power of the simd operations will be shown


## Resources 
1- https://godbolt.org/ converts cpp code to machine assembly code
2- https://www.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/libraries/intel-c-class-libraries/c-classes-and-simd-operations.html
3- https://www.codeproject.com/Articles/874396/Crunching-Numbers-with-AVX-and-AVX
4- https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#