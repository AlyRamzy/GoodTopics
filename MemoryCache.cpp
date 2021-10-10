#include <iostream>

#include "include/Array.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int hight = 1000;
    int width = 1000;
    int depth = 1000;

    nd::Array<int> arr(hight,width,depth);


    // Get starting timepoint
    auto start = high_resolution_clock::now();

    for(int i=0; i<hight; i++)
    {
        for(int j=0; j<width; j++)
        {
            for(int k=0; k<depth; k++)
            {
                arr(i,j,k) = 1;
            }
        }
    }
    
     // Get ending timepoint
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
  
    cout << "Time taken by loop while NOT taking into consideration cache: "
         << duration.count() << " milliseconds" << endl;



    // Get starting timepoint
    start = high_resolution_clock::now();

    for(int k=0; k<depth; k++)
    {
        for(int j=0; j<width; j++)
        {
            for(int i=0; i<hight; i++)
            {
                arr(i,j,k) = 1;
            }
        }
    }
    
     // Get ending timepoint
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
  
    cout << "Time taken by loop while taking into consideration cache: "
         << duration.count() << " milliseconds" << endl;

    return 0;
}