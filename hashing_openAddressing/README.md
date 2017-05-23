# Open Addressing Hashing

https://www.youtube.com/watch?v=rvdJDijO2Ro

Gathered from lecture 10 regarding open addressing version of hashing.

This is a form of hashing that solves the problem of key collisions without having to store 
collided values in a linked list. Instead probing is used to pick another available slot. The probing
mechanism is used in insertion, deletion and search operations.

## Table Doubling

Table doubling is an approach to dynamically resize the capcity of the table. It is a liner operation because it has to copy all of the element from an existing table to a new table of `n` size bigger where `n` is the `TABLE_DOUBLING_FACTOR`

## `is_deleted` Flag

The is deleted flag is necessary on table entry because the search operation is terminated when probing a lost of a NULL value. INstead we set it to deleted so the search operation can continue probing other slots.


## Constants

### TABLE_DOUBLING_FACTOR

The amount to multiply by the current table size when creating a new table

### TABLE_DOUBLING_THRESHOLD

The percentage of the current table size to be matched against remaining slots. If the threshold
is reached table doubling event method is called.
