#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "point.h"
#include "set.h"

bool is_set_full(HashSet *set) { return set->size >= set->capacity; }

void resize_hash_set(HashSet *set, int new_capacity) {
  Point *new_points = malloc(sizeof(Point) * new_capacity);

  for (int i = 0; i < set->capacity; i++) {
    Point current_point = set->points[i];
    new_points[i] = current_point;
  }

  free(set->points);
  set->points = new_points;
  set->capacity = new_capacity;
}

// https://en.wikipedia.org/wiki/Jenkins_hash_function
uint32_t hash_key(Point point, int capacity) {
  const uint32_t key[2] = {(uint32_t)point.x, (uint32_t)point.y};

  size_t i = 0;
  uint32_t hash = 0;

  while (i != 2) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }

  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;

  return hash % capacity;
}

HashSet *create_hash_set(int capacity) {
  HashSet *set = malloc(sizeof(HashSet));
  set->capacity = capacity;
  set->size = 0;
  set->points = malloc(sizeof(Point) * capacity);
  return set;
}

void add_to_set(HashSet *set, Point point) {
  if (has(set, point)) {
    return;
  }

  if (is_set_full(set)) {
    resize_hash_set(set, set->capacity * 2);
  }

  set->size += 1;
  set->points[hash_key(point, set->capacity)] = point;
}

bool has(HashSet *set, Point point) {
  return is_equal(set->points[hash_key(point, set->capacity)], point);
}

void free_set(HashSet *set) {
  if (set == NULL)
    return;

  if (set->points != NULL) {
    free(set->points);
    set->points = NULL;
  }
  free(set);
}
