#include <stdint.h>
#include <assert.h>
#include "oa_hash.h"

/**
 * The two hash functions below were taken from:
 * http://burtleburtle.net/bob/hash/integer.html
 */

uint32_t hash_one( int a) {
  a += ~(a<<15);
  a ^=  (a>>10);
  a +=  (a<<3);
  a ^=  (a>>6);
  a += ~(a<<11);
  a ^=  (a>>16);
  return a;
}

uint32_t hash_two( int a) {
  a = (a+0x7ed55d16) + (a<<12);
  a = (a^0xc761c23c) ^ (a>>19);
  a = (a+0x165667b1) + (a<<5);
  a = (a+0xd3a2646c) ^ (a<<9);
  a = (a+0xfd7046c5) + (a<<3);
  a = (a^0xb55a4f09) ^ (a>>16);
  return a;
}

int oa_hash(oa_hash_table *table, int key, int trial_count) {
  int hashed_key = abs(hash_one(key) + (hash_two(key) * trial_count) - trial_count) % table->size;
  DEBUG_PRINT(("oa_hash(): hashed %d to %d\n", key, hashed_key));
  return hashed_key;
}

oa_hash_table * oa_table_doubling(oa_hash_table *old_table) {

  DEBUG_PRINT(("oa_table_doubling(): of size: %d\n", old_table->size * DOUBLING_FACTOR));

  oa_hash_table * new_table = oa_create(old_table->size * DOUBLING_FACTOR);

  int i;

  for(i = 0; i < old_table->size; i++) {
    if(old_table->entries[i] != NULL) {
      oa_insert(new_table, old_table->entries[i]->key, old_table->entries[i]->value);
    }
  }
  
  oa_destroy(old_table);
   
  return new_table;
}

oa_hash_table * oa_insert(oa_hash_table *table, int key, int value) {

  DEBUG_PRINT(("oa_insert(): %d => %d\n", key, value));
   
  if(table->available_slots < (int)(table->size * TABLE_DOUBLING_THRESHOLD)) {
    DEBUG_PRINT(("\toa_insert(): launching table doubling %d %d\n", table->available_slots, (int)(table->size * TABLE_DOUBLING_THRESHOLD)));
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
      free(table->entries[hashed_key]);
      table->entries[hashed_key] = NULL;
      break;
    }
    hashed_key = oa_hash(table, key, ++trial_count);
  }
  
  table->entries[hashed_key] = malloc( sizeof(oa_hash_table_entry));
  assert(table->entries[hashed_key]);

  table->entries[hashed_key]->value = value;
  table->entries[hashed_key]->key = key;
  table->entries[hashed_key]->is_deleted = FALSE;
  table->available_slots--;

  return table;
}

int oa_delete(oa_hash_table *table, int key) {

  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  int i;

  while(table->entries[hashed_key] != NULL && key != table->entries[hashed_key]->key) {
      DEBUG_PRINT(("\toa_delete(): key collision:  hashed_key: %d, entry->key: %d\n", hashed_key, table->entries[hashed_key]->key));
      hashed_key = oa_hash(table, key, ++trial_count);
  }

  if(table->entries[hashed_key] != NULL) {
    table->entries[hashed_key]->key = 0;
    table->entries[hashed_key]->value = 0;
    table->entries[hashed_key]->is_deleted = TRUE;
    table->available_slots++;
    return TRUE;
  }

  return FALSE;
}

oa_hash_table_entry * oa_search(oa_hash_table *table, int key) {
  
  DEBUG_PRINT(("oa_search(): for key %d\n", key)); 
  
  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  int i;

  while(table->entries[hashed_key] != NULL && key != table->entries[hashed_key]->key) {
      DEBUG_PRINT(("\toa_search(): key collision hashed_key: %d, entry->key: %d\n", hashed_key, table->entries[hashed_key]->key));
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

  oa_hash_table *new_table = malloc(sizeof(oa_hash_table));
  assert(new_table);
 
  new_table->entries = malloc(sizeof(oa_hash_table_entry*) * size);
  assert(new_table->entries);

  new_table->size = size;

  new_table->available_slots = size;

  int i; 

  for(i = 0; i < size; i++) {
    new_table->entries[i] = NULL;
  }

  return new_table;
}
