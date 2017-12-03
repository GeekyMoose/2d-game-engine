#include "grid/Point2D.h"

#include <cmath>


Point2D::Point2D() {
    this->m_x = 0;
    this->m_y = 0;
}

Point2D::Point2D(const int x, const int y) {
    this->m_x = x;
    this->m_y = y;
}

Point2D& Point2D::translate(const int x, const int y) {
    this->m_x += x;
    this->m_y += y;
    return *this;
}

float Point2D::squareDistance(const Point2D& other) {
    const float a = (other.getX() - this->m_x);
    const float b = (other.getY() - this->m_y);
    return (a*a) + (b*b);
}

float Point2D::distance(const Point2D& other) {
    return std::sqrt(this->squareDistance(other));
}


// -----------------------------------------------------------------------------
// Operator overload
// -----------------------------------------------------------------------------
bool Point2D::operator==(const Point2D& other) const {
    return this->m_x == other.getX() && this->m_y == other.getY();
}

bool Point2D::operator!=(const Point2D& other) const {
    return !(*this == other);
}

Point2D& Point2D::operator+(const int scalar) {
    this->m_x += scalar;
    this->m_y += scalar;
    return *this;
}

Point2D& Point2D::operator-(const int scalar) {
    return *this + (-scalar);
}

Point2D& Point2D::operator+(const Point2D& other) {
    this->m_x += other.getX();
    this->m_y += other.getY();
    return *this;
}

Point2D& Point2D::operator-(const Point2D& other) {
    this->m_x -= other.getX();
    this->m_y -= other.getY();
    return *this;
}


// -------------------------------------------------------------------------
// Getters - Setters
// -------------------------------------------------------------------------
int Point2D::getX() const {
    return this->m_x;
}

int Point2D::getY() const {
    return this->m_y;
}
