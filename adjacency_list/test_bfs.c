#include "adj_list.c"

int main() {
    al_graph *graph = al_graph_create(18, TRUE);
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
    al_graph_bfs(graph, 0);
    al_graph_free(graph);
    return 0;
}
