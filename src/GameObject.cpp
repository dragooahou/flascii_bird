#include "GameObject.h"
#include "utils.h"
#include "Rect.h"

void GameObject::Update() {

}

int GameObject::GetId() const {
    return ID;
}

void GameObject::SetId(int id) {
    ID = id;
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
    thisRect.position = position;
    thisRect.size = {static_cast<float>(gfx.GetCurrentFrame()->GetWidth()),
                     static_cast<float>(gfx.GetCurrentFrame()->GetHeight())};

    Rect otherRect;
    otherRect.position = other.position;
    otherRect.size = {static_cast<float>(other.gfx.GetCurrentFrame()->GetWidth()),
                     static_cast<float>(other.gfx.GetCurrentFrame()->GetHeight())};

    Rect overlappingArea;
    bool aabbCollide = Rect::areOverlapping(thisRect, otherRect, &overlappingArea);
    if(aabbCollide) {

        // Filter spaces
        for(int y = 0; y < overlappingArea.size.y; ++y) {
            for(int x = 0; x < overlappingArea.size.x; ++x) {

                Vector2 c1Pos = overlappingArea.position - position + Vector2{static_cast<float>(x), static_cast<float>(y)};
                Vector2 c2Pos = overlappingArea.position - other.position + Vector2{static_cast<float>(x), static_cast<float>(y)};

                char c1 = gfx.GetCurrentFrame()->GetAsciiArt()(c1Pos.y, c1Pos.y);
                char c2 = other.gfx.GetCurrentFrame()->GetAsciiArt()(c2Pos.y, c2Pos.y);

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

