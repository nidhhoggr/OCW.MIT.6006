# Open Addressing Hashing

https://www.youtube.com/watch?v=rvdJDijO2Ro

Gathered from lecture 10 regarding open addressing version of hashing.

This is a form of hashing that solves the problem of key collisions without having to store 
collided values in a linked list. Instead probing is used to pick another available slot. The probing
mechanism is used in insertion, deletion and search operations.

## Probing Techniques
1. linear
>  linear probing is iteratively probing the adjacent slot by `k = h(k) + r % s` where h is hash function, r is the retry count and s is the table size. This creates issues with the time complexity because the next availble adjacent slot will most likley always be occupied that is the next slot was instead randomly chosen. This increases the time complexity of all the operations to a linear constant factor where the the constant is the size of the clusters. To avoid the the next method of probing are more preferred. 
1. quadratic
> `k = h(k) + r^2 % s`
1. double hashing
  double hashing is used to be morerandomly find the next slot which will reduce the amount of clusters in the table. This typically requires to seperate hashing algorithms taking the following form: `k = (h(k) + h2(k)*r ) % s`.
1. uniform theory
  
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
