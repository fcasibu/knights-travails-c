#ifndef _NODE_H_
#define _NODE_H_

#include "point.h"

typedef struct Node {
  struct Node *parent;
  Point point;
} Node;

Node *create_node(Point point, Node *parent);
void free_node(Node *node);

#endif
