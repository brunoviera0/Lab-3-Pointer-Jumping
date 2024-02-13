#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include "doctest.h"
#include "linkedlist.h"


TEST_CASE("pointer_jumping_edge_cases") {
    SUBCASE("empty_list") {
        struct node* empty_list = nullptr;
        pointer_jumping(empty_list);
        CHECK(empty_list == nullptr);
    }

    SUBCASE("single_element_list") {
        struct node* single_list = build_linked_list(1);
        pointer_jumping(single_list);
        CHECK(single_list->next == single_list);
        delete_linked_list(single_list, 1);
    }

    SUBCASE("multi_element_list") {
        struct node* multi_list = build_linked_list(3);
        pointer_jumping(multi_list);
        bool all_point_to_last = true;
        struct node* last = multi_list;
        while (last->next != last) {
            last = last->next;
        }
        for (struct node* current = multi_list; current != last; current = current->next) {
            if (current->next != last) {
                all_point_to_last = false;
                break;
            }
        }
        CHECK(all_point_to_last);
        CHECK(last->next == last); 
        delete_linked_list(multi_list, 3);
    }
}