#include <stdlib.h>

#include "point.h"
#include "util.h"
#include "validmoves.h"

#define KNIGHT_MOVES 8
#define BOARD_SIZE 8

bool is_valid(int x, int y) {
  return x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE;
}

ValidMoves *get_valid_moves(Point point) {
  ValidMoves *valid_moves = malloc(sizeof(ValidMoves));
  valid_moves->size = KNIGHT_MOVES;
  valid_moves->points = malloc(sizeof(Point) * valid_moves->size);
  int move_offsets[KNIGHT_MOVES][2] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                                       {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

  for (int i = 0; i < valid_moves->size; ++i) {
    valid_moves->points[i] =
        (Point){point.x + move_offsets[i][0], point.y + move_offsets[i][1]};
  }

  int new_size = 0;
  for (int i = 0; i < valid_moves->size; ++i) {
    if (is_valid(valid_moves->points[i].x, valid_moves->points[i].y)) {

      valid_moves->points[new_size] = valid_moves->points[i];
      new_size += 1;
    }
  }

  valid_moves->size = new_size;

  return valid_moves;
}

void free_valid_moves(ValidMoves *moves) {
  if (moves == NULL) {
    return;
  }
  if (moves->points != NULL) {
    free(moves->points);
  }

  free(moves);
}
