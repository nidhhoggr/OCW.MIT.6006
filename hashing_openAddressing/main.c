#include "oa_hash.h"

int oa_hash(oa_hash_table *table, int key, int trial_count) {
  int hashed_key = (key + trial_count) % table->size;
  printf("Hashed key of %d is %d\n", key, hashed_key);
  return hashed_key;
}

oa_hash_table * oa_table_doubling(oa_hash_table *old_table) {

  printf("doubling new table\n");

  oa_hash_table * new_table = oa_create(old_table->size * 2);

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

  if(table->available_slots < (int)(table->size / 6)) {
    table = oa_table_doubling(table);
  }

  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  while(table->entries[hashed_key] != NULL) {
    printf("Hashed key already exists: %d\n", hashed_key);
    /*detect an override*/
    if(table->entries[hashed_key]->key == key) {
      table->entries[hashed_key]->value = value;
      break;
    }
    hashed_key = oa_hash(table, key, ++trial_count);
  }
  
  if(table->entries[hashed_key] == NULL) {
    table->entries[hashed_key] = (oa_hash_table_entry*) malloc( sizeof(oa_hash_table_entry));
    table->entries[hashed_key]->value = value;
    table->entries[hashed_key]->key = key;
    table->available_slots--;
  }

  return table;
}

int oa_delete(oa_hash_table *table, int key) {

}

oa_hash_table_entry * oa_search(oa_hash_table *table, int key) {
  int trial_count = 0;

  int hashed_key = oa_hash(table, key, trial_count);

  int i;

  while(table->entries[hashed_key] != NULL && hashed_key < table->size) {
    if(key != table->entries[hashed_key]->key) {
      printf("Hashed key search collided:  hashed_key: %d, entry->key: %d\n", hashed_key, table->entries[hashed_key]->key);
      hashed_key = oa_hash(table, key, ++trial_count);
    }
    else {
      printf("Hashed key value: %d\n", table->entries[hashed_key]->value);
      break;
    }
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


int main( int argc, char **argv ) {

 oa_hash_table *my_table = oa_create(6);
 
 my_table = oa_insert(my_table, 0, 22);
 my_table = oa_insert(my_table, 12, 32);
 my_table = oa_insert(my_table, 5, 36);
 my_table = oa_insert(my_table, 89, 27);
 my_table = oa_insert(my_table, 52, 56);
 my_table = oa_insert(my_table, 51, 504);
 /*this value should override*/
 my_table = oa_insert(my_table, 52, 53);

 oa_hash_table_entry *my_entry = oa_search(my_table, 0);
 if(my_entry) {
  printf("My Entry: %d = %d expecting 22\n", my_entry->key, my_entry->value);
 }

 my_entry = oa_search(my_table, 12);
 if(my_entry) {
  printf("My Entry: %d = %d expecting 32\n", my_entry->key, my_entry->value);
 }

 my_entry = oa_search(my_table, 5);
 if(my_entry) {
  printf("My Entry: %d = %d expecting 36\n", my_entry->key, my_entry->value);
 }

 my_entry = oa_search(my_table, 89);
 if(my_entry) {
  printf("My Entry: %d = %d expecting 27\n", my_entry->key, my_entry->value);
 }

 my_entry = oa_search(my_table, 52);
 if(my_entry) {
  printf("My Entry: %d = %d expecting 56\n", my_entry->key, my_entry->value);
 }

 my_entry = oa_search(my_table, 51);
 if(my_entry) {
  printf("My Entry: %d = %d expexting 504\n", my_entry->key, my_entry->value);
 }

 oa_destroy(my_table);
}
