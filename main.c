#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "path.h"
#include "point.h"
#include "queue.h"
#include "set.h"
#include "validmoves.h"

void search(Point start, Point end);

int main() {
  puts("\nstart: [0,0], end: [1, 2]");
  search((Point){0, .0}, (Point){1, 2});
  puts("\nstart: [0,0], end: [3, 3]");
  search((Point){0, 0}, (Point){3, 3});
  puts("\nstart: [3,3], end: [0, 0]");
  search((Point){3, 3}, (Point){0, 0});
  puts("\nstart: [3,3], end: [4, 3]");
  search((Point){3, 3}, (Point){4, 3});
  puts("\nstart: [7,7], end: [0, 0]");
  search((Point){7, 7}, (Point){0, 0});
}

void search(Point start, Point end) {
  Queue *queue = create_queue(8);
  HashSet *s = create_hash_set(8);
  enqueue(queue, create_node(start, NULL));
  add_to_set(s, start);

  while (!is_queue_empty(queue)) {
    Node *node = dequeue(queue);

    if (is_equal(node->point, end)) {
      Path path = get_path(node);
      print_path(path);
      if (path.points != NULL) {
        free(path.points);
        path.points = NULL;
      }
      break;
    }

    ValidMoves *moves = get_valid_moves(node->point);

    for (int i = 0; i < moves->size; ++i) {
      Point current_point = moves->points[i];
      if (has(s, current_point)) {
        continue;
      }

      add_to_set(s, current_point);
      enqueue(queue, create_node(current_point, node));
    }

    free_valid_moves(moves);
  }

  free_queue(queue);
  free_set(s);
}
