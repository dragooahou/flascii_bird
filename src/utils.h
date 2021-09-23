//
// Created by etien on 20/09/2021.
//

#pragma once

#include <string>
#include <functional>

#define INDEX_2DTO1D(x, y, sizeY) x*sizeY+y


namespace utils {

    //Returns the last Win32 error, in string format. Returns an empty string if there is no error.
    std::string GetLastErrorAsString();

    template<typename T>
    void memcpy_if(T* dst, T* src, size_t size, const std::function<bool(T elem_to_cpy)>& filter) {
        for(int i = 0; i < size; ++i) {
            if (filter(src[i])) {
                dst[i] = src[i];
            }
        }
    }

};


