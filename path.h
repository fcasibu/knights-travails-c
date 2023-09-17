#ifndef _PATH_H_
#define _PATH_H_

#include "node.h"
#include "point.h"

typedef struct {
  int moves;
  Point *points;
} Path;

Path get_path(Node *node);
void print_path(Path path);

#endif
