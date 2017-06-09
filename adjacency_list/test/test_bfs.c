#include "adj_list.c"

int main() {

    al_queue *traversalQueue;

    al_graph *graph = al_graph_create(18, true);
    al_graph_insert_edge(graph, 0, 2);
    al_graph_insert_edge(graph, 0, 14);
    al_graph_insert_edge(graph, 1, 4);
    al_graph_insert_edge(graph, 1, 5);
    al_graph_insert_edge(graph, 2, 1);
    al_graph_insert_edge(graph, 2, 5);
    al_graph_insert_edge(graph, 2, 6);
    al_graph_insert_edge(graph, 3, 2);
    al_graph_insert_edge(graph, 3, 17);
    al_graph_insert_edge(graph, 4, 1);
    al_graph_insert_edge(graph, 4, 7);
    al_graph_insert_edge(graph, 5, 2);
    al_graph_insert_edge(graph, 5, 4);
    al_graph_insert_edge(graph, 5, 8);
    al_graph_insert_edge(graph, 5, 9);
    al_graph_insert_edge(graph, 6, 2);
    al_graph_insert_edge(graph, 6, 3);
    al_graph_insert_edge(graph, 8, 5);
    al_graph_insert_edge(graph, 8, 7);
    al_graph_insert_edge(graph, 8, 12);
    al_graph_insert_edge(graph, 9, 5);
    al_graph_insert_edge(graph, 9, 10);
    al_graph_insert_edge(graph, 10, 17);
    al_graph_insert_edge(graph, 11, 8);
    al_graph_insert_edge(graph, 12, 9);
    al_graph_insert_edge(graph, 13, 9);
    al_graph_insert_edge(graph, 13, 10);
    al_graph_insert_edge(graph, 13, 16);
    al_graph_insert_edge(graph, 14, 7);
    al_graph_insert_edge(graph, 15, 12);
    al_graph_insert_edge(graph, 15, 17);
    al_graph_insert_edge(graph, 16, 12);
    al_graph_insert_edge(graph, 17, 13);
    al_graph_insert_edge(graph, 17, 16);
    DEBUG_PRINT(("Starting from vertex 0\n"));
    int popped;
    traversalQueue = al_graph_bfs(graph, 0);
    int expected[18] = {0,14,2,7,6,5,1,3,9,8,4,17,10,12,16,13};
    int key = 0;
    while(!al_queue_is_empty(traversalQueue)) {
      popped = al_queue_pop(traversalQueue);
      assert(popped == expected[key++]);
      //DEBUG_PRINT(("expected %d to be %d\n", popped, expected[key++]));
    }
    al_queue_free(traversalQueue);
    DEBUG_PRINT(("\n\nStarting from vertex 15\n"));
    traversalQueue = al_graph_bfs(graph, 15);
    int expectedNext[18] = {15,17,12,16,13,9,10,5,8,4,2,7,1,6,3};
    key = 0;
    while(!al_queue_is_empty(traversalQueue)) {
      popped = al_queue_pop(traversalQueue);
      assert(popped == expectedNext[key++]);
      //DEBUG_PRINT(("expected %d to be %d\n", popped, expectedNext[key++]));
    }
    al_queue_free(traversalQueue);
    al_graph_free(graph);
    return 0;
}
