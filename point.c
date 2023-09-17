#include <stdbool.h>

#include "point.h"

bool is_equal(Point p1, Point p2) { return p1.x == p2.x && p1.y == p2.y; }
