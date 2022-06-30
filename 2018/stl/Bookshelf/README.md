Main point in Deque:(benefits)
The complexity (efficiency) of common operations on deques is as follows:
Random access - constant O(1)
Insertion or removal of elements at the end or beginning - constant O(1)
Insertion or removal of elements - linear O(n)

The storage of a deque is automatically expanded and contracted as needed. Expansion of a deque is cheaper than the expansion of a std::vector because it does not involve copying of the existing elements to a new memory location. On the other hand, deques typically have large minimal memory cost; a deque holding just one element has to allocate its full internal array (e.g. 8 times the object size on 64-bit libstdc++; 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++).
