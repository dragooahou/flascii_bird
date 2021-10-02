//
// Created by etien on 30/09/2021.
//

#ifndef PROJET_ASCII_COLLIDERS_H
#define PROJET_ASCII_COLLIDERS_H

#include <vector>
#include <memory>

#include "Vector2.h"


namespace Colliders {

    struct ICollider;
    struct Rectangle;
    struct Circle;
    struct Compound;

    // The actual collision functions
    bool CollideImpl(const Rectangle& lhs, const Rectangle& rhs);
    bool CollideImpl(const Circle& lhs, const Circle& rhs);
    bool CollideImpl(const Circle& lhs, const Rectangle& rhs);

    bool CollideImpl(const Compound& lhs, const ICollider& rhs);


    // Function that call the right collision function automatically
    template<typename LhsT, typename RhsT>
    auto CollideCallRightFunc(const LhsT& lhs, const RhsT& rhs, int) -> decltype(CollideImpl(lhs, rhs)) {
        return CollideImpl(lhs, rhs);
    }

    template<typename LhsT, typename RhsT>
    auto CollideCallRightFunc(const LhsT& lhs, const RhsT& rhs, double) -> decltype(CollideImpl(rhs, lhs)) {
        return CollideImpl(rhs, lhs);
    }

    // The main collision function
    template<typename LhsT, typename RhsT>
    bool Collide(const LhsT& lhs, const RhsT& rhs) {
       return CollideCallRightFunc(lhs, rhs, 0);
    }


    // Colliders
    struct ICollider {
        Vector2 position;

        virtual bool CollideWith(const ICollider& other) const = 0;

        virtual bool CollideWith(const Rectangle& other) const = 0;
        virtual bool CollideWith(const Circle& other) const = 0;
        virtual bool CollideWith(const Compound& other) const = 0;

        virtual bool CollideWith(const Vector2& point) const = 0;

    };

    struct Rectangle : public ICollider {
        Vector2 size;

        bool CollideWith(const ICollider &other) const override;

        bool CollideWith(const Rectangle &other) const override;
        bool CollideWith(const Circle &other) const override;
        bool CollideWith(const Compound &other) const override;

        bool CollideWith(const Vector2 &point) const override;

    };

    struct Circle : public ICollider {
        float radius;

        bool CollideWith(const ICollider &other) const override;

        bool CollideWith(const Rectangle &other) const override;
        bool CollideWith(const Circle &other) const override;
        bool CollideWith(const Compound &other) const override;

        bool CollideWith(const Vector2 &point) const override;
    };

    struct Compound : public ICollider {
        std::vector<std::shared_ptr<ICollider>> colliders;

        bool CollideWith(const ICollider &other) const override;

        bool CollideWith(const Rectangle &other) const override;
        bool CollideWith(const Circle &other) const override;
        bool CollideWith(const Compound &other) const override;

        bool CollideWith(const Vector2 &point) const override;
    };

}

#endif //PROJET_ASCII_COLLIDERS_H
