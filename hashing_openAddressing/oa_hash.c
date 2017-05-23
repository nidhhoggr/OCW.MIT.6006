#include "oa_hash.h"

int oa_hash(oa_hash_table *table, int key, int trial_count) {
  int hashed_key = (key + trial_count) % table->size;
  printf("oa_hash(): hashed %d to %d\n", key, hashed_key);
  return hashed_key;
}

oa_hash_table * oa_table_doubling(oa_hash_table *old_table) {

  printf("oa_table_doubling(): of size: %d\n", old_table->size * DOUBLING_FACTOR);

  oa_hash_table * new_table = oa_create(old_table->size * DOUBLING_FACTOR);

  int i, val, key;

  for(i = 0; i < old_table->size; i++) {
    if(old_table->entries[i] != NULL) {
      key = old_table->entries[i]->key;
      val = old_table->entries[i]->value;
      oa_insert(new_table, key, val);
    }
  }
  
  oa_destroy(old_table);
   
  return new_table;
}

oa_hash_table * oa_insert(oa_hash_table *table, int key, int value) {

  printf("oa_insert(): %d => %d\n", key, value);
   
  if(table->available_slots < (int)(table->size * TABLE_DOUBLING_THRESHOLD)) {
    printf("\toa_insert(): launching table doubling %d %d\n", table->available_slots, (int)(table->size * .6));
    table = oa_table_doubling(table);
  }

  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  while(table->entries[hashed_key] != NULL) {
    /*detect an override*/
    if(table->entries[hashed_key]->key == key) {
      table->entries[hashed_key]->value = value;
      break;
    }
    else if(table->entries[hashed_key]->is_deleted == TRUE) {
      table->entries[hashed_key] = NULL;
      break;
    }
    hashed_key = oa_hash(table, key, ++trial_count);
  }
  
  if(table->entries[hashed_key] == NULL) {
    table->entries[hashed_key] = (oa_hash_table_entry*) malloc( sizeof(oa_hash_table_entry));
    table->entries[hashed_key]->value = value;
    table->entries[hashed_key]->key = key;
    table->entries[hashed_key]->is_deleted = FALSE;
    table->available_slots--;
  }

  return table;
}

int oa_delete(oa_hash_table *table, int key) {

  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  int i;

  while(table->entries[hashed_key] != NULL && key != table->entries[hashed_key]->key) {
      printf("\toa_delete(): key collision:  hashed_key: %d, entry->key: %d\n", hashed_key, table->entries[hashed_key]->key);
      hashed_key = oa_hash(table, key, ++trial_count);
  }

  if(table->entries[hashed_key] != NULL) {
    table->entries[hashed_key]->key = 0;
    table->entries[hashed_key]->value = 0;
    table->entries[hashed_key]->is_deleted = TRUE;
    return TRUE;
  }

  return FALSE;
}

oa_hash_table_entry * oa_search(oa_hash_table *table, int key) {
  
  printf("oa_search(): for key %d\n", key); 
  
  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  int i;

  while(table->entries[hashed_key] != NULL && key != table->entries[hashed_key]->key) {
      printf("\toa_search(): key collision hashed_key: %d, entry->key: %d\n", hashed_key, table->entries[hashed_key]->key);
      hashed_key = oa_hash(table, key, ++trial_count);
  }

  return table->entries[hashed_key];
}


void oa_destroy(oa_hash_table *table) {
  int i;
  for(i = 0; i < table->size; i++) {
    if(table->entries[i] != NULL) {
      free(table->entries[i]);
    }
  }
  free(table->entries);
  free(table);
}

oa_hash_table * oa_create(int size) {

  oa_hash_table *new_table = (oa_hash_table*) malloc(sizeof(oa_hash_table));
 
  new_table->entries = (oa_hash_table_entry**) malloc(sizeof(oa_hash_table_entry*) * size);

  new_table->size = size;

  new_table->available_slots = size;

  int i; 

  for(i = 0; i < size; i++) {
    new_table->entries[i] = NULL;
  }

  return new_table;
}
