#include "adj_list.c"

int main() {
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
    al_queue *tq = al_graph_dfs(graph, 0);
    int popped;
    int expected[18] = {14, 7, 2, 6, 3, 17, 16, 12, 9, 10, 5, 8, 4, 1 , 13};
    int i = 0;
    while(!al_queue_is_empty(tq)) {
      popped = al_queue_pop(tq); 
      assert(popped == expected[i++]);  
    }
    al_queue_free(tq);

    DEBUG_PRINT(("\n\nStarting from vertex 9\n"));
    tq = al_graph_dfs(graph, 9);
    int expectedNext[18] = {10, 17, 16, 12, 9, 5, 8, 7, 4, 1, 2, 6, 3, 13};
    i = 0;
    while(!al_queue_is_empty(tq)) {
      popped = al_queue_pop(tq); 
      assert(popped == expectedNext[i++]);  
    }
    al_queue_free(tq);

    al_graph_free(graph);

    return 0;
}
