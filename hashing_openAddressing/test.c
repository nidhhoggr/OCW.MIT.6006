#include "oa_hash.c"

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
  DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting 0 = 22\n", my_entry->key, my_entry->value));
}

 my_entry = oa_search(my_table, 12);
 if(my_entry) {
  DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting 12 = 32\n", my_entry->key, my_entry->value));
 }

 my_entry = oa_search(my_table, 5);
 if(my_entry) {
  DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting 5 = 36\n", my_entry->key, my_entry->value));
 }

 my_entry = oa_search(my_table, 89);
 if(my_entry) {
  DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting  89 = 27\n", my_entry->key, my_entry->value));
 }

 my_entry = oa_search(my_table, 52);
 if(my_entry) {
  DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting 52 = 53\n", my_entry->key, my_entry->value));
 }

 my_entry = oa_search(my_table, 51);
 if(my_entry) {
  DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting 51 = 504\n", my_entry->key, my_entry->value));
 }

 if(oa_delete(my_table, 51)) {
   DEBUG_PRINT((" - testing(): Successfully deleted key of 51\n"));
   my_entry = oa_search(my_table, 51);
   if(my_entry == NULL) {
     DEBUG_PRINT((" - testing(): key 51 is empty as expected\n"));
   }
   my_table = oa_insert(my_table, 51, 504);
   my_entry = oa_search(my_table, 51);
   if(my_entry) {
    DEBUG_PRINT((" - testing(): My Entry: %d = %d expecting 51 = 504\n", my_entry->key, my_entry->value));
   }
 }

 oa_destroy(my_table);
}
