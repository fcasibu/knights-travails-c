#include <stdlib.h>

#include "node.h"

Node *create_node(Point point, Node *parent) {
  Node *node = malloc(sizeof(Node));
  node->parent = parent;
  node->point = point;
  return node;
}

void free_node(Node *node) {
  if (node == NULL) {
    return;
  }

  /* // somehow doesn't work */
  /* if (node->parent) { */
  /*   free_node(node->parent); */
  /* } */

  free(node);
}
