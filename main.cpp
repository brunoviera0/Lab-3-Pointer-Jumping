#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
    struct node * linked_list = build_linked_list(3);
    cout << "Original linked list:" << endl;
    print_linked_list(linked_list, 3);

    cout << "Linked list after pointer jumping:" << endl;
    pointer_jumping(linked_list);
    print_linked_list(linked_list, 3);

    delete_linked_list(linked_list, 3);

    return 0;
}
