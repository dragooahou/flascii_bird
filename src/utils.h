//
// Created by etien on 20/09/2021.
//

#pragma once

#include <string>

#define INDEX_2DTO1D(x, y, sizeY) x*sizeY+y

namespace utils {

    //Returns the last Win32 error, in string format. Returns an empty string if there is no error.
    std::string GetLastErrorAsString();


};


