#pragma once

class point
{

public:

    int x, y;

    point			    () {};
    point	    (int x, int y);
    point   operator+  (const point& other) const;
    point   operator-  (const point& other) const;
    point   operator*  (int scale) const;
    void   operator+=  (const point& other);
    void   operator-=  (const point& other);
    void   operator*=  (int scale);
    bool   operator==   (const point& other) const;
    bool   operator!=   (const point& other) const;
    bool   isEqual	    (const point& other) const;

    void swap         ();
    void swap         (point& other);
};
