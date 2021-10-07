#pragma once

namespace nd
{
    template <typename T>
    class Array
    {
        T* arr;
        int hight;
        int width;
        int depth;
        
        public:
        Array(int hight, int width, int depth)
        {
            this->hight = hight;
            this->width = width;
            this->depth = depth;

            arr =new T [hight*width*depth];
        }

        ~Array()
        {
            delete arr;
        }

        T& operator () (int i, int j, int k)
        {
            return arr[i + j*width + k*width*hight];
        }
    };
}