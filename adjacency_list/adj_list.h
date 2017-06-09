#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

#define TRUE  1
#define FALSE 0

typedef struct _al_node {
  int dest;
  int is_visited;
  struct _al_node *next;
} al_node;

typedef struct _al_list {
  int edge_count;
  struct _al_node *head;// pointer to head node of list
} al_list;

typedef struct _al_graph {
  int vertex_count;
  int is_directed;
  struct _al_list **lists;
} al_graph;

al_graph* al_graph_create(int num_of_vertices, int is_directed);
void al_list_free(al_list *list);
void al_graph_free(al_graph *graph);
al_node* al_node_create(int dest);
void al_graph_insert_edge(al_graph *graph, int src, int dest);
void al_graph_print(al_graph *graph);
