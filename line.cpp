#include "line.h"
#include "point.cpp"

line::line() {
    start = point(0,0);
    end = point(1,0);
}

line::line(const point& p) {
    start = point(0,0);
    end = p;
}

line::line(const point& p1, const point& p2) {
    start = p1;
    end = p2;
}

line::line(const line& l) {
    start = l.start;
    end = l.end;
}

std::ostream& operator << (std::ostream& os, const line& l) {
    // output format: y=mx+b OR x=x OR y=y
    double m = l.slope();
    if (m == 0) {
        os << "x = " << l.start.get_x();
    } else if (l.start.get_x() - l.end.get_x() == 0) {
        os << "y = " << l.start.get_y();
    } else {
        double b = l.start.get_y() - m * l.start.get_x();
        os << "y = " << m << "x + " << b;
    }
    return os;
}

std::istream& operator >> (std::istream& is, line& l) {
    is >> l.start;
    is >> l.end;
    return is;
}

double line::slope() const {
    return (end.get_y() - start.get_y()) / (end.get_x() - start.get_x());
}

void line::translate(double dx, double dy) {
    start.translate(dx, dy);
    end.translate(dx, dy);
}

void line::reflect_x() {
    start.reflect_x();
    end.reflect_x();
}

void line::reflect_y() {
    start.reflect_y();
    end.reflect_y();
}

bool line::operator == (const line& l) {
    return start == l.start && end == l.end;
}

void line::operator = (const line& l) {
    start = l.start; 
    end = l.end;
}
