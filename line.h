// header file for line class
// jay hendren
// csci2270 hw1

#include "point.h"

#ifndef LINE_H_
#define LINE_H_

class line {
    public:
        line();
        line(const point& p);
        line(const point& p1, const point& p2);
        line(const line& l);
	    /* these are the constructor functions for the line
	    class. defaults to a line going from the origin to
	    (1,0)*/

        friend std::ostream& operator << (std::ostream& os, const line& l);
            /* output: "y = mx + b" if you have a sloped line
		       "x = b" if you are boring and have a horizontal
		           line
		       "y = c" if you are a freak and have a vertical
		           line.
            */

        friend std::istream& operator >> (std::istream& is, line& l);
	    /* same rules that apply for the points apply for the
	    line. */

        double slope() const;
	    /* returns the slope of the line. If the line is
	    vertical... god help you. */

        void translate(double dx, double dy);
	    /* takes Mandarin Chinese as input, returns broken
	    English in a French accent as output for some reason
	    */

        void reflect_x();
	    /* works like a mirror, but in two dimensions instead
	    of three. */

        void reflect_y();
	    /* this feature currently in beta, be sure to report
	    any bugs */

        bool operator == (const line& l);
        void operator = (const line& l);
            
    private:
        point start;
        point end;
};

#endif
