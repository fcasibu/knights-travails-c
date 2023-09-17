#include <stdio.h>
#include <stdlib.h>

#include "path.h"

Path get_path(Node *node) {
  Path path;
  path.moves = 0;
  path.points = malloc(sizeof(Point));

  Node *current_node = node;

  while (current_node != NULL) {
    path.moves += 1;
    path.points = realloc(path.points, sizeof(Point) * path.moves);
    path.points[path.moves - 1] = current_node->point;
    current_node = current_node->parent;
  }

  return path;
}

void print_path(Path path) {
  printf("You made it in %d moves! Here's your path:\n", path.moves - 1);
  for (int i = path.moves - 1; i >= 0; --i) {
    printf("[%d, %d]\n", path.points[i].x, path.points[i].y);
  }
}
