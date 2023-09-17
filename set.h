#ifndef _SET_H_
#define _SET_H_

#include "point.h"
#include <stdlib.h>

typedef struct {
  int size;
  int capacity;
  Point *points;
} HashSet;

HashSet *create_hash_set(int capacity);
void add_to_set(HashSet *set, Point point);
bool has(HashSet *set, Point point);
void free_set(HashSet *set);

#endif
