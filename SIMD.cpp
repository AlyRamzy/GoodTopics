#include <iostream>

#include <immintrin.h>

#include "include/Array.h"
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

union simd512
{
	__m512 reg;
	float f32[16];
};

union simd256
{
	__m256 reg;
	float f32[8];
};

/*
    Note : in simple operation like addition between two arrays simd will be overhead
    but once the instructions are more complex the power of the simd operations will be shown
*/
int main()
{
    int hight = 512;
    int width = 512;
    int depth = 512;

    nd::Array<float> arr1(hight,width,depth);
    
    for(int i=0; i< hight*width*depth; ++i)
    {
        arr1[i] = i;
    }

    nd::Array<float> result1(hight,width,depth);
    nd::Array<float> result2(hight,width,depth);

    auto start = high_resolution_clock::now();
    // for each element in the array get its sqrt
    for(int i=0; i< hight*width*depth; ++i)
    {
        result1[i] = sqrt(arr1[i]);
    }

     // Get ending timepoint
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
  
    cout << "Time taken by Adding two arrays without SIMD: "
         << duration.count() << " milliseconds" << endl;


    start = high_resolution_clock::now();
    for(int i=0; i< hight*width*depth; i+=8)
    {
        simd256 reg1;
        simd256 reg2;
        simd256 result;

        reg1.reg = _mm256_set_ps(arr1[i],arr1[i+1],arr1[i+2],arr1[i+3],arr1[i+4],
                                arr1[i+5],arr1[i+6],arr1[i+7]);

        result.reg = _mm256_sqrt_ps(reg1.reg);

        result2[i] = result.f32[7];
        result2[i+1] = result.f32[6];
        result2[i+2] = result.f32[5];
        result2[i+3] = result.f32[4];
        result2[i+4] = result.f32[3];
        result2[i+5] = result.f32[2];
        result2[i+6] = result.f32[1];
        result2[i+7] = result.f32[0];  
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by Adding two arrays WITH SIMD: "
         << duration.count() << " milliseconds" << endl;
    /*
    simd256 reg1;
    simd256 reg2;
    simd256 result;

    reg1.reg = _mm256_set_ps(1,2,3,4,5,6,7,8);

    reg2.reg = _mm256_set_ps(1,2,3,4,5,6,7,8);

    result.reg = _mm256_add_ps(reg1.reg, reg2.reg);

    cout<<endl<<result.f32[0]<<endl<<result.f32[1]<<endl<<result.f32[2]<<endl<<result.f32[3]<<endl<<result.f32[4]<<endl<<result.f32[5]<<endl<<result.f32[6]<<endl<<result.f32[7]<<endl;
    */

    cout << (result2 == result1);

    return 0;
}