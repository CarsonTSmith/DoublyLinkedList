# DoublyLinkedList

Compiled under WSL2 Ubuntu with GCC's g++.\n
g++ -std=c++11 -g -Wall -Werror main.cpp -o main

Ran under Valgrind with no memory leaks detected.

```console
carson@CarsonPC:/mnt/c/Projects/LinkedList$ valgrind --leak-check=yes ./main
==17962== Memcheck, a memory error detector
==17962== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==17962== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==17962== Command: ./main
==17962==
2 3 1
1 3 2
==17962==
==17962== HEAP SUMMARY:
==17962==     in use at exit: 0 bytes in 0 blocks
==17962==   total heap usage: 5 allocs, 5 frees, 73,800 bytes allocated
==17962==
==17962== All heap blocks were freed -- no leaks are possible
==17962==
==17962== For lists of detected and suppressed errors, rerun with: -s
==17962== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

