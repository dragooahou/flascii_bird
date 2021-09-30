//
// Created by etien on 23/09/2021.
//

#pragma once


#include "Vector2.h"

struct Rect {
    Vector2 position;
    Vector2 size;

    static bool areOverlapping(const Rect& rectangle1, const Rect& rectangle2, Rect* outputOverlappingAera = nullptr);

};

