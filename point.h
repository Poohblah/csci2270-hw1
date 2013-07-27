// point class header file
// jay hendren
// csci2270 hw1

#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class point {
    public:
        point(double x = 0.0, double y = 0.0);
	  /* point class has two member variables, x and y,
	  representing a single point on a cartesian plane. It
	  defaults to the origin point if no arguments are given.*/

        point(const point& p);
	    /* You can also use a copy constructor to make a point.
	    Whoohoo, we're flying now. */

        double get_x() const;
            /* because we don't want x to be a public variable. */

        double get_y() const;
            /* see above, s/x/y/ */

        void set_x(double newx);
	    /* we don't want x to be a public variable, but this
	    function doesn't implement any error handling or type
	    casting, so as long as the value you pass in can be
	    cast as a double, it will turn into a double. So
	    essentially this function makes x a public variable as
	    long as you use this interface. */

        void set_y(double newy);
            /* again, see above. again, s/x/y/ */

        void translate(double dx, double dy);
	    /* does what it says - it moves the point by dx and dy.
	    This function also translates English input to German.
	    */

        void scale(double factor);
	    /* puts the point on the scale and returns its weight
	    in kg. */

        void reflect_x();
            /* reflects the point across the x axis. */

        void reflect_y();
	    /* by now, you're used to my search-and-replace comments,
	    so I'm not even going to bother anymore. */

        void rotate(double radians);
            /* C'mon baby, twist and shout! */

        void operator = (const point& p2);
	    /* we need to overload the assignment operator because
	    it already does exactly what we need it to do, and
	    that's not good enough - we need to tell it HOW to do
	    what it already knows how to do. */

        bool operator == (const point& p2);
	    /* does the same thing as the previous operator, but
	    does it twice. */

        friend std::istream& operator >> (std::istream& ins, point& target);
            /* I'm not your friend, guy! */

        friend std::ostream& operator << (std::ostream& outs, const point& source);
	    /* no error handling or anything done. So if your input
	    can be cast as a double, it WILL be cast as a double.
	    e.g.:
		Please type 2 values to define p3 
                asdfadsfadsfash;goihg
		p3 = (-92.4, 110)
	    */

    private: 
        double x; double y;
};

#endif
