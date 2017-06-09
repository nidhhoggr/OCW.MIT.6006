#include "al_debug.h"
#include "al_queue.c"

void main() {

  int popped;

  al_queue *new_queue = al_queue_create(18);
  
  al_queue_insert(new_queue, 15);
  popped = al_queue_pop(new_queue);
  assert(popped == 15);
  al_queue_insert(new_queue, 14);
  al_queue_insert(new_queue, 13);
  al_queue_insert(new_queue, 12);
  popped = al_queue_pop(new_queue);
  assert(popped == 14);
  al_queue_insert(new_queue, 11);
  popped = al_queue_pop(new_queue);
  assert(popped == 13);
  al_queue_insert(new_queue, 10);
  al_queue_insert(new_queue, 9);
  popped = al_queue_pop(new_queue);
  assert(popped == 12);
  al_queue_insert(new_queue, 8);
  popped = al_queue_pop(new_queue);
  assert(popped == 11);
  al_queue_insert(new_queue, 7);
  al_queue_insert(new_queue, 6);
  al_queue_insert(new_queue, 5);
  popped = al_queue_pop(new_queue);
  assert(popped == 10);
  al_queue_insert(new_queue, 4);
  al_queue_insert(new_queue, 3);
  al_queue_insert(new_queue, 2);
  al_queue_insert(new_queue, 1);
  popped = al_queue_pop(new_queue);
  assert(popped == 9);
  popped = al_queue_pop(new_queue);
  assert(popped == 8);
  popped = al_queue_pop(new_queue);
  assert(popped == 7);
  popped = al_queue_pop(new_queue);
  assert(popped == 6);
  popped = al_queue_pop(new_queue);
  assert(popped == 5);
  popped = al_queue_pop(new_queue);
  assert(popped == 4);
  popped = al_queue_pop(new_queue);
  assert(popped == 3);
  popped = al_queue_pop(new_queue);
  assert(popped == 2);
  popped = al_queue_pop(new_queue);
  assert(popped == 1);

  al_queue_free(new_queue);



  new_queue = al_queue_create(18);

  al_queue_insert(new_queue, 55);
  popped = al_queue_pop(new_queue);
  assert(popped == 55);
  al_queue_insert(new_queue, 54);
  al_queue_insert(new_queue, 53);
  al_queue_insert(new_queue, 52);
  popped = al_queue_pop(new_queue);
  assert(popped == 54);
  al_queue_insert(new_queue, 51);
  popped = al_queue_pop(new_queue);
  assert(popped == 53);
  al_queue_insert(new_queue, 50);
  al_queue_insert(new_queue, 49);
  popped = al_queue_pop(new_queue);
  assert(popped == 52);
  al_queue_insert(new_queue, 48);
  popped = al_queue_pop(new_queue);
  assert(popped == 51);
  al_queue_insert(new_queue, 47);
  al_queue_insert(new_queue, 46);
  al_queue_insert(new_queue, 45);
  popped = al_queue_pop(new_queue);
  assert(popped == 50);
  al_queue_insert(new_queue, 44);
  al_queue_insert(new_queue, 43);
  al_queue_insert(new_queue, 42);
  al_queue_insert(new_queue, 41);
  popped = al_queue_pop(new_queue);
  assert(popped == 49);
  popped = al_queue_pop(new_queue);
  assert(popped == 48);
  popped = al_queue_pop(new_queue);
  assert(popped == 47);
  popped = al_queue_pop(new_queue);
  assert(popped == 46);
  popped = al_queue_pop(new_queue);
  assert(popped == 45);
  popped = al_queue_pop(new_queue);
  assert(popped == 44);
  popped = al_queue_pop(new_queue);
  assert(popped == 43);
  popped = al_queue_pop(new_queue);
  assert(popped == 42);
  popped = al_queue_pop(new_queue);
  assert(popped == 41);


  al_queue_free(new_queue);
}
