#include "mylist.h"

#include <cassert> // assert

int main(int argc, char *argv[])
{
    int i = 1;
    int j = 2;
    int k = 3;
    MyList<int> list;

    // Tests invalid index when inserting
    assert(list.insert(-1, i) == nullptr);

    // Tests basic insert when list is empty
    // 1
    assert(list.insert(0, i) != nullptr);

    // Tests insert when list is non-empty
    // 2 1
    assert(list.insert(0, j) != nullptr);
    assert(*(list.get(0)) == j);
    assert(*(list.get(1)) == i);

    // Tests insert into middle of list
    // 2 3 1
    assert(list.insert(1, k) != nullptr);
    assert(*(list.get(0)) == j);
    assert(*(list.get(1)) == k);
    assert(*(list.get(2)) == i);

    list.print();

    // Test deleting from middle of list
    // 2 1
    assert(list.remove(1) == true);
    assert(*(list.get(0)) == j);
    assert(*(list.get(1)) == i);

    // Tests removing from end of list
    // 2
    assert(list.remove(1) == true);
    assert(*(list.get(0)) == j);

    // Tests removing head
    // Blank list
    assert(list.remove(0) == true);
    assert(list.get(0) == nullptr);


    return 0;
}