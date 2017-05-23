#include <stdio.h>
#include <stdlib.h>

typedef struct _oa_hash_table_entry {
  int key;
  int value;
  int isDeleted;
} oa_hash_table_entry;

typedef struct _oa_hash_table {
 int size;
 int available_slots;
 struct _oa_hash_table_entry **entries; 
} oa_hash_table;

int oa_hash(oa_hash_table *table, int key, int trial_count);
oa_hash_table * oa_table_doubling(oa_hash_table *old_table);
oa_hash_table * oa_insert(oa_hash_table *table, int key, int value);
int oa_delete(oa_hash_table *table, int key);
oa_hash_table_entry * oa_search(oa_hash_table *table, int key);
void oa_destroy(oa_hash_table *table);
oa_hash_table * oa_create(int size);
