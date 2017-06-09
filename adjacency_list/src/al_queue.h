#ifndef AL_QUEUE_H
#define AL_QUEUE_H

#include <stdbool.h>

typedef struct _al_queue {
  int *queue;
  int front;
  int rear;
  int length;
  int maxLength;
} al_queue;

al_queue * al_queue_create(int queueSize);
void al_queue_insert(al_queue *aq, int data);
int al_queue_pop(al_queue *aq);
bool al_queue_is_empty(al_queue *aq);
void al_queue_free(al_queue *aq);
#endif
