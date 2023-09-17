#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "queue.h"

bool is_queue_full(Queue *queue) { return queue->size >= queue->capacity; }

void resize_queue(Queue *queue, int new_capacity) {
  Node **new_nodes = malloc(sizeof(Node *) * new_capacity);

  for (int i = 0; i < queue->capacity; ++i) {
    new_nodes[i] = queue->nodes[i];
  }

  free(queue->nodes);
  queue->nodes = new_nodes;
  queue->capacity = new_capacity;
}

Queue *create_queue(int capacity) {
  Queue *queue = malloc(sizeof(Queue));
  queue->nodes = malloc(sizeof(Node *) * capacity);
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

bool is_queue_empty(Queue *queue) { return queue->size == 0; }

void enqueue(Queue *queue, Node *node) {
  if (is_queue_full(queue)) {
    resize_queue(queue, queue->capacity * 2);
  }
  queue->size += 1;
  queue->nodes[queue->size - 1] = node;
}

Node *dequeue(Queue *queue) {
  if (is_queue_empty(queue)) {
    return NULL;
  }
  Node *node = queue->nodes[0];
  memmove(queue->nodes, queue->nodes + 1, sizeof(Node *) * queue->size);
  queue->size -= 1;
  return node;
}

void free_queue(Queue *queue) {
  if (queue == NULL) {
    return;
  }

  for (int i = 0; i < queue->size; ++i) {
    free_node(queue->nodes[i]);
    queue->nodes[i] = NULL;
  }

  if (queue->nodes != NULL) {
    free(queue->nodes);
    queue->nodes = NULL;
  }

  free(queue);
}
