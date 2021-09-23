#include "GameObject.h"
#include "utils.h"
#include "Rect.h"

void GameObject::Update() {

}

GameObject::GameObject() {

}

GameObject::GameObject(Vector2 position, Graphics gfx) {
    SetPosition(position);
    SetGfx(gfx);
}


const Vector2 &GameObject::GetPosition() const {
    return position;
}

void GameObject::SetPosition(const Vector2 &position) {
    GameObject::position = position;
}

const Graphics &GameObject::GetGfx() const {
    return gfx;
}

void GameObject::SetGfx(const Graphics &gfx) {
    GameObject::gfx = gfx;
}

bool GameObject::CollideWith(const GameObject& other, bool filterSpaces) {

    Rect thisRect;
    thisRect.size = {static_cast<float>(gfx.GetCurrentFrame()->GetWidth()),
                     static_cast<float>(gfx.GetCurrentFrame()->GetHeight())};
    thisRect.position = position - thisRect.size/2.f;

    Rect otherRect;
    otherRect.size = {static_cast<float>(other.gfx.GetCurrentFrame()->GetWidth()),
                     static_cast<float>(other.gfx.GetCurrentFrame()->GetHeight())};
    otherRect.position = other.position - otherRect.size/2.f;

    Rect overlappingArea;
    bool aabbCollide = Rect::areOverlapping(thisRect, otherRect, &overlappingArea);
    if(aabbCollide) {

        // Filter spaces
        for(int y = 0; y < overlappingArea.size.y; ++y) {
            for(int x = 0; x < overlappingArea.size.x; ++x) {

                Vector2 currPixel = Vector2{static_cast<float>(x), static_cast<float>(y)};

                Vector2 c1Pos = overlappingArea.position - thisRect.position + currPixel;
                Vector2 c2Pos = overlappingArea.position - otherRect.position + currPixel;

                char c1 = gfx.GetCurrentFrame()->GetAsciiArt()(c1Pos.y, c1Pos.x);
                char c2 = other.gfx.GetCurrentFrame()->GetAsciiArt()(c2Pos.y, c2Pos.x);

                if(c1 != ' ' && c2 != ' ') {
                    return true;
                }

            }
        }

    }

    return false;
}

Vector2 GameObject::GetOrigin() const {
    return position + gfx.GetCurrentFrame()->GetCenterOffset();
}

