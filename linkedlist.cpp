#include "linkedlist.h"
#include <iostream>

using namespace std;

struct node *build_linked_list(int number_of_nodes) {
    if (number_of_nodes == 0) 
        return nullptr;

    struct node *head = new node{0, nullptr};
    
    struct node *current = head;
    for (int i = 1; i < number_of_nodes; i++) {
        current->next = new node{i, nullptr};
        current = current->next;
    }
    current->next = current; 
    return head;
}

void pointer_jumping(struct node *head) {
    if (head == nullptr) 
        return;

    struct node *last = head;
    
    while (last->next != last){
        last = last->next;
    }

    struct node *current = head;
    
    while (current != last) {
        struct node *next = current->next;
        current->next = last; 
        current = next;
    }
}

void print_linked_list(struct node *first, int number_of_nodes) {
    struct node *current = first;
    while (current->next != current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << current->data << " (last)" << endl;
}

int delete_linked_list(struct node* first, int number_of_nodes) {
    if (first == nullptr) return 0;

    struct node* current = first;
    struct node* next = nullptr;

    while (current->next != current) {
        next = current->next;
        delete current;
        current = next;
    }
    delete current;

    return 1;
}