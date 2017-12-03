#pragma once

#include "utils/platform.h"


/**
 * Defines a realy simple 2D point with pixel coordinates.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 */
class Point2D {
    private:
        int m_x;
        int m_y;


    public:
        Point2D();
        Point2D(const int x, const int y);


    public:
        Point2D& translate(const int x, const int y);
        float squareDistance(const Point2D& other) const;
        float distance(const Point2D& other) const;


    // -------------------------------------------------------------------------
    // Operator overload
    // -------------------------------------------------------------------------
    public:
        bool operator==(const Point2D& other) const;
        bool operator!=(const Point2D& other) const;
        Point2D& operator+(const int scalar);
        Point2D& operator-(const int scalar);
        Point2D& operator+(const Point2D& other);
        Point2D& operator-(const Point2D& other);


    // -------------------------------------------------------------------------
    // Getters - Setters
    // -------------------------------------------------------------------------
    public:
        int getX() const;
        int getY() const;
};


