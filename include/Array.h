#pragma once
#include <string.h>
#include<iostream>
using namespace std;
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

        T& operator [] (int i)
        {
            return arr[i];
        }

       bool operator ==(const Array<T>& other) const
		{
			if (width != other.width || hight != other.hight || depth != other.depth)
			{
				return false;
			}

			for (size_t i = 0; i < hight*width*depth; ++i)
				if (arr[i] != other.arr[i])
					return false;

			return true;
		}

        nd::Array<T> pad_v1( int pad_size, T pad_value)
        {
            auto out = nd::Array<T>(width +  2 * pad_size, hight +  2 * pad_size, depth +  2 * pad_size);

            for (size_t i = 0; i < out.hight*out.width*out.depth; ++i)
                out.arr[i] = pad_value;

            for (size_t k = 0; k < depth; ++k)
		    {
                for (size_t j = 0 ; j < hight; ++j)
                {
                    for (size_t i = 0; i < width; ++i)
                    {
                        out(i + pad_size, j + pad_size, k + pad_size) = this->operator()(i, j, k);
                    }
                }
		    }

            return out;
        }

        nd::Array<T> pad_v2( int pad_size, T pad_value)
        {
            auto out = nd::Array<T>(width +  2 * pad_size, hight +  2 * pad_size, depth +  2 * pad_size);

            for (size_t k = 0; k < out.depth; ++k)
		    {
                for (size_t j = 0 ; j < out.hight; ++j)
                {
                    for (size_t i = 0; i < out.width; ++i)
                    {
                        if(i < pad_size || i >= width+pad_size || j < pad_size || j >= hight+pad_size || k < pad_size || k >= depth+pad_size )
                            out(i, j, k) = pad_value;
                        else
                            out(i, j, k) = this->operator()(i-pad_size, j-pad_size, k-pad_size);
                    }
                }
		    }

            return out;
        }
    };
}