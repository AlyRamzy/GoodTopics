#include <iostream>

#include "include/Array.h"
#include <chrono>

using namespace std;
using namespace std::chrono;



int main()
{
    int hight = 512;
    int width = 512;
    int depth = 512;

    nd::Array<int> arr(hight,width,depth);
    
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    auto pad_v1 = arr.pad_v1(4,10);
      // Get ending timepoint
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
  
    cout << "Time taken by Pad V1 while taking into consideration Branch Prediction: "
         << duration.count() << " milliseconds" << endl;


    start = high_resolution_clock::now();

    auto pad_v2 = arr.pad_v2(4,10);

      // Get ending timepoint
    stop = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(stop - start);
  
    cout << "Time taken by Pad V2 while NOT taking into consideration Branch Prediction: "
         << duration.count() << " milliseconds" << endl;

    cout << "Making Sure that both gives the same result : ";
    cout <<( pad_v1==pad_v2)<<endl;

    return 0;
}