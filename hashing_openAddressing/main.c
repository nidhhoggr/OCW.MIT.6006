#include <stdio.h>
#include <stdlib.h>


typedef struct _oa_hash_table_entry {
  int key;
  int value;
  int isDeleted;
} oa_hash_table_entry;

typedef struct _oa_hash_table {
 int size;
 struct _oa_hash_table_entry **entries; 
} oa_hash_table;

int oa_hash(oa_hash_table *table, int key, int trial_count) {
  int hashed_key = key % table->size + trial_count;
  printf("Hashed key of %d is %d\n", key, hashed_key);
  return hashed_key;
}

oa_hash_table_entry * oa_insert(oa_hash_table *table, int key, int value) {

  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  while(table->entries[hashed_key] != NULL) {
    printf("Hashed key already exists: %d\n", hashed_key);
    hashed_key = oa_hash(table, key, ++trial_count);
  }

  table->entries[hashed_key] = (oa_hash_table_entry*) malloc( sizeof(oa_hash_table_entry));
  table->entries[hashed_key]->value = value;
  table->entries[hashed_key]->key = hashed_key;
}

int oa_delete(oa_hash_table *table, int key) {

}

oa_hash_table_entry * oa_search(oa_hash_table *table, int key) {

}

oa_hash_table * oa_create(int size) {

  oa_hash_table *new_table = (oa_hash_table*) malloc(sizeof(oa_hash_table));
 
  new_table->entries = (oa_hash_table_entry**) malloc(sizeof(oa_hash_table_entry*) * size);

  new_table->size = size;

  int i; 

  for(i = 0; i < size; i++) {
    new_table->entries[i] = NULL;
  }

  return new_table;
}


int main( int argc, char **argv ) {

 oa_hash_table *my_table = oa_create(33);
 
 oa_insert(my_table, 0, 22);
 oa_insert(my_table, 12, 32);
 oa_insert(my_table, 5, 36);
 oa_insert(my_table, 89, 27);
 oa_insert(my_table, 52, 56);
 oa_insert(my_table, 52, 504);
}
