#include "oa_hash.c"

int main( int argc, char **argv ) {

  oa_hash_table *my_table = oa_create(6);

  my_table = oa_insert(my_table, 0, 22);
  my_table = oa_insert(my_table, 12, 32);
  my_table = oa_insert(my_table, 5, 36);
  my_table = oa_insert(my_table, 89, 27);
  my_table = oa_insert(my_table, 52, 56);
  my_table = oa_insert(my_table, 51, 504);

  //this value should override
  my_table = oa_insert(my_table, 52, 53);

  oa_hash_table_entry *my_entry = oa_search(my_table, 0);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 0);
  assert(my_entry->value == 22);

  my_entry = oa_search(my_table, 12);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 12);
  assert(my_entry->value == 32);

  my_entry = oa_search(my_table, 5);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 5);
  assert(my_entry->value == 36);

  my_entry = oa_search(my_table, 89);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 89);
  assert(my_entry->value == 27);

  my_entry = oa_search(my_table, 52);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 52);
  assert(my_entry->value == 53);

  my_entry = oa_search(my_table, 51);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 51);
  assert(my_entry->value == 504);
  assert(oa_delete(my_table, 51));

  DEBUG_PRINT((" - testing(): Successfully deleted key of 51\n"));
  my_entry = oa_search(my_table, 51);
  DEBUG_PRINT((" - testing(): key 51 is empty as expected\n"));
  my_table = oa_insert(my_table, 51, 502);
  my_entry = oa_search(my_table, 51);
  DEBUG_PRINT((" - testing(): My Entry: %d = %d\n", my_entry->key, my_entry->value));
  assert(my_entry->key == 51);
  assert(my_entry->value == 502);

  oa_destroy(my_table);
}
