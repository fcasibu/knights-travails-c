#ifndef _VALIDMOVES_H_
#define _VALIDMOVES_H_

#include "node.h"
#include "point.h"

typedef struct {
  int size;
  Point *points;
} ValidMoves;

ValidMoves *get_valid_moves(Point point);
void free_valid_moves(ValidMoves *moves);

#endif
