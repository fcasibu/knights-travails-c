#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "node.h"

typedef struct Queue {
  int size;
  int capacity;
  Node **nodes;
} Queue;

Queue *create_queue(int capacity);
bool is_queue_empty(Queue *queue);
void enqueue(Queue *queue, Node *node);
Node *dequeue(Queue *queue);
void free_queue(Queue *queue);

#endif
