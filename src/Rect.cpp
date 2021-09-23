//
// Created by etien on 23/09/2021.
//

#include "Rect.h"


bool Rect::areOverlapping(const Rect& rectangle1, const Rect& rectangle2, Rect* outputOverlappingAera) {
    const float intersectionX1 = fmax(rectangle1.position.x, rectangle2.position.x);
    const float intersectionX2 = fmin(rectangle1.position.x + rectangle1.size.w, rectangle2.position.x + rectangle2.size.w);
    if (intersectionX2 < intersectionX1) {
        return false;
    }

    const float intersectionY1 = fmax(rectangle1.position.y, rectangle2.position.y);
    const float intersectionY2 = fmin(rectangle1.position.y + rectangle1.size.h, rectangle2.position.y + rectangle2.size.h);
    if (intersectionY2 < intersectionY1) {
        return false;
    }

    if(outputOverlappingAera != nullptr) {
        *outputOverlappingAera = Rect{
                {intersectionX1, intersectionY1},
                {intersectionX2 - intersectionX1, intersectionY2 - intersectionY1}
        };
    }

    return true;
}