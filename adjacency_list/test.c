#include "adj_list.c"

int main() {
    al_graph *graph = al_graph_create(5, TRUE);
    al_graph_insert_edge(graph, 0, 1);
    al_graph_insert_edge(graph, 0, 4);
    al_graph_insert_edge(graph, 1, 2);
    al_graph_insert_edge(graph, 1, 3);
    al_graph_insert_edge(graph, 1, 4);
    al_graph_insert_edge(graph, 2, 3);
    al_graph_insert_edge(graph, 3, 4);
    al_graph_print(graph);
    al_graph_free(graph);

    al_graph *graph2 = al_graph_create(5, FALSE);
    al_graph_insert_edge(graph2, 0, 1);
    al_graph_insert_edge(graph2, 0, 4);
    al_graph_insert_edge(graph2, 1, 2);
    al_graph_insert_edge(graph2, 1, 3);
    al_graph_insert_edge(graph2, 1, 4);
    al_graph_insert_edge(graph2, 2, 3);
    al_graph_insert_edge(graph2, 3, 4);
    al_graph_print(graph2);
    al_graph_free(graph2);

    return 0;
}
