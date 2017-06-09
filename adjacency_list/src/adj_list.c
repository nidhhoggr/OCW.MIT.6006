#include <stdlib.h>
#include <assert.h>
#include "al_debug.h"
#include "adj_list.h"
#include "al_queue.c"

int createCalled = 0;

al_graph* al_graph_create(int num_of_vertices, bool is_directed)
{
    al_graph *graph = malloc(sizeof(al_graph));
    assert(graph);
    graph->vertex_count = num_of_vertices;
    graph->is_directed = is_directed;
 
    graph->lists = malloc(num_of_vertices * sizeof(al_list*));
    assert(graph->lists);
 
    int i;
    for (i = 0; i < num_of_vertices; ++i) {
      graph->lists[i] = malloc(sizeof(al_list));
      assert(graph->lists[i]);
      graph->lists[i]->head = NULL;
      graph->lists[i]->edge_count = 0;
    }
 
    return graph;
}

void al_list_free(al_list *list) {
  al_node *tmp;
  al_node *head = list->head;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    DEBUG_PRINT(("Freeing edge with dest: %d\n", tmp->dest));
    free(tmp);
  }
}

void al_graph_free(al_graph *graph) {
  int i;
  al_list *pCrawl;
  for (i = 0; i < graph->vertex_count; ++i) {
    pCrawl = graph->lists[i];
    al_list_free(pCrawl);
  }
  free(graph->lists);
  free(graph);
}

al_node* al_node_create(al_graph *graph, int dest) {
  al_node *newNode = malloc(sizeof(al_node));
  assert(newNode);
  newNode->dest = dest;
  newNode->next = NULL;
  return newNode;
}

void al_graph_insert_edge(al_graph *graph, int src, int dest) {

  al_node *newNode = al_node_create(graph, dest);
  newNode->next = graph->lists[src]->head;
  graph->lists[src]->head = newNode;
  graph->lists[src]->edge_count++;

  //undirected graph edges are bidirectional
  if(!graph->is_directed) {
    newNode = al_node_create(graph, src);
    newNode->next = graph->lists[dest]->head;
    graph->lists[dest]->head = newNode;
    graph->lists[dest]->edge_count++;
  }
}

void al_graph_do_dfs(al_graph *graph, int src, bool visited[], al_queue *traversalQueue) { 
  al_node *pCrawl = graph->lists[src]->head;
  while (pCrawl) {
    DEBUG_PRINT((" ITER: %d-%d\n", src, pCrawl->dest));
    if(!visited[pCrawl->dest]) {
      DEBUG_PRINT(("-> %d\n", pCrawl->dest));
      al_queue_insert(traversalQueue, pCrawl->dest);
      visited[pCrawl->dest] = true;
      al_graph_do_dfs(graph, pCrawl->dest, visited, traversalQueue); 
    }
    else {
      DEBUG_PRINT(("Was already visited %d  - %d\n", pCrawl->dest, visited[pCrawl->dest]));
    }
    pCrawl = pCrawl->next;
  }
}

al_queue* al_graph_dfs(al_graph *graph, int start) {
  int i;
  bool visited[graph->vertex_count];
  for (i = 0; i < graph->vertex_count; i++) {
    visited[i] = false;
  }
  al_queue *traversalQueue = al_queue_create(graph->vertex_count);
  al_graph_do_dfs(graph, start, visited, traversalQueue);
  return traversalQueue;
}

al_queue* al_graph_bfs(al_graph *graph, int start) {

  int i;
  bool visited[graph->vertex_count];
  for (i = 0; i < graph->vertex_count; i++) {
    visited[i] = false;
  }

  al_node *pCrawl = graph->lists[start]->head;
  al_queue *traversalQueue = al_queue_create(graph->vertex_count);
  al_queue *bfs_queue = al_queue_create(graph->vertex_count);
  al_queue_insert(bfs_queue, start);
  al_queue_insert(traversalQueue, start);
  DEBUG_PRINT(("BFS node: %d\n", start));

  int vertexSrc;
  while (!al_queue_is_empty(bfs_queue)) {
    vertexSrc = al_queue_pop(bfs_queue);
    DEBUG_PRINT(("BFS queue pop: %d\n", vertexSrc));
    pCrawl = graph->lists[vertexSrc]->head;
    while(pCrawl) {
      if(visited[pCrawl->dest] == false) {
        visited[pCrawl->dest] = true;
        al_queue_insert(bfs_queue, pCrawl->dest);
        DEBUG_PRINT(("BFS node: %d\n", pCrawl->dest));
        al_queue_insert(traversalQueue, pCrawl->dest);
      }
      else {
        DEBUG_PRINT(("%d has been visited\n", pCrawl->dest));
      }
      pCrawl = pCrawl->next;
    }
  }
  al_queue_free(bfs_queue);

  return traversalQueue;
}

void al_graph_print(al_graph *graph) {
  int i;
  for (i = 0; i < graph->vertex_count; ++i) {
    al_node *pCrawl = graph->lists[i]->head;
    printf("\n Adjacency list of vertex %d\n head ", i);
    while (pCrawl) {
      printf("-> %d", pCrawl->dest);
      pCrawl = pCrawl->next;
    }
    printf("\n");
  }
}
