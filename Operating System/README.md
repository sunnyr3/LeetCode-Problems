**1. How do you find out if there is a memory leak?**

The best way is to compile and excute through Valgrind.

**2. Memory leak, memory allocation, and how processes manage memory.**

Fisrt, memory leak occurs when you allocate memory to heap but do not manually garbage collect (de-allocate memory) when objects are no longer relevant. So you have an entity allocating heap memory, but no entity deallocating the memory when no longer needed.