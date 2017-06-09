#include <stdbool.h>
#include "al_queue.h"

typedef struct _al_node {
  int dest;
  struct _al_node *next;
} al_node;

typedef struct _al_list {
  int edge_count;
  struct _al_node *head;// pointer to head node of list
} al_list;

typedef struct _al_graph {
  int vertex_count;
  bool is_directed;
  struct _al_list **lists;
} al_graph;

al_queue * al_queue_create(int queueSize);
void al_queue_insert(al_queue *aq, int data);
int al_queue_pop(al_queue *aq);
