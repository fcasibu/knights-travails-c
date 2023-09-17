#ifndef _POINT_H_
#define _POINT_H_

#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Point;

bool is_equal(Point p1, Point p2);

#endif
