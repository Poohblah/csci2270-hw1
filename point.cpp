#include "point.h"
#include <math.h>

// using namespace std;

point::point(double initx, double inity) {
    x = initx; y = inity;
}

point::point(const point& p) {
    x = p.x; y = p.y;
}

double point::get_x() const {
    return x;
}

double point::get_y() const {
    return y;
}

void point::set_x(double newx) {
    x = newx;
}

void point::set_y(double newy) {
    y = newy;
}

void point::translate(double dx, double dy) {
    x += dx; y += dy;
}

void point::scale(double factor) {
    x *= factor; y *= factor;
}

void point::reflect_x() {
    y *= -1;
}

void point::reflect_y() {
    x *= -1;
}

void point::rotate(double radians) {
    x = x * cos(radians) - y * sin(radians);
    y = x * sin(radians) + y * cos(radians);
}

void point::operator = (const point& p2) {
    x = p2.x; y = p2.y;
}

bool point::operator == (const point& p2) {
    return x == p2.x && y == p2.y;
}

std::istream& operator >> (std::istream& ins, point& target) {
    ins >> target.x;
    ins >> target.y;
    return ins;
}

std::ostream& operator << (std::ostream& outs, const point& source) {
    outs << "(" << source.x << ", " << source.y << ")";
    return outs;
}
