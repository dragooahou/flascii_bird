//
// Created by etien on 22/09/2021.
//

#pragma once

#include <memory>

template<typename T>
class Matrix {

    size_t height;
    size_t width;
    std::unique_ptr<T[]> data;

public:

    Matrix()
    : height(3)
    , width(3)
    , data{std::make_unique<T[]>(height * width)} {
        std::memset(data.get(), 0, height * width * sizeof(T));
    }

    Matrix(size_t height, size_t width)
    : height(height)
    , width(width)
    , data{std::make_unique<T[]>(height * width)} {
        std::memset(data.get(), 0, height * width * sizeof(T));
    }

    Matrix(const Matrix& other)
    : height(other.height)
    , width(other.width)
    , data{std::make_unique<T[]>(height * width)} {
        std::memcpy(data.get(), other.data.get(), height * width * sizeof(T));
    }

    Matrix& operator=(const Matrix& other) {
        height = other.height;
        width = other.width;
        data = std::make_unique<T[]>(height * width);
        std::memcpy(data.get(), other.data.get(), height * width * sizeof(T));
        return *this;
    }

    T* operator[](size_t row) {
        return row * width + data.get();
    }

    T& operator()(size_t row, size_t column) {
        return data[row * width + column];
    }

    const T& operator()(size_t row, size_t column) const {
        return data[row * width + column];
    }

    size_t GetHeight() const {
        return height;
    }

    size_t GetWidth() const {
        return width;
    }

    const std::unique_ptr<T[]> &GetData() const {
        return data;
    }
};