#include <assert.h>
#include <stdlib.h>
#include "al_queue.h"

al_queue* al_queue_create(int queueSize) {
  al_queue *new_queue = malloc(sizeof(al_queue));
  assert(new_queue);
  new_queue->queue = malloc(queueSize * sizeof(int));
  new_queue->rear = -1;
  new_queue->front = -1;
  new_queue->length = 0;
  new_queue->maxLength = queueSize;
  return new_queue;
}

void al_queue_insert(al_queue *aq, int data) {
   assert(aq->rear < aq->maxLength);
   aq->rear++;
   aq->queue[aq->rear] = data;
   aq->length++;
}

int al_queue_pop(al_queue *aq) {
  assert(!al_queue_is_empty(aq));
  aq->length--;
  aq->front++;
  return aq->queue[aq->front]; 
}

bool al_queue_is_empty(al_queue *aq) {
  return aq->length == 0;
}

void al_queue_free(al_queue *aq) {
  if(aq->queue) {
    free(aq->queue);
  }
  free(aq);
}
