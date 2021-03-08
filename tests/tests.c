#include <helium/data/dll.h>
#include <helium/debug/unit.h>
#include <string.h>

#define TO_STRING(x) *(char **)x
int main()
{

    DLL new_list = DoublyLinkedList();

    char *friends[6] = {"Monica", "Ross", "Rachel", "Phoebe", "Chandler", "Joey"};

    new_list.append(&friends[0], &new_list);
    new_list.append(&friends[1], &new_list);
    new_list.append(&friends[2], &new_list);
    new_list.append(&friends[3], &new_list);
    new_list.append(&friends[4], &new_list);
    new_list.append(&friends[5], &new_list);

    log(INFO, "Testing dll.get_data():");

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(1, &new_list)), "Monica"), 0);

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(2, &new_list)), "Ross"), 0);

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(3, &new_list)), "Rachel"), 0);

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(4, &new_list)), "Phoebe"), 0);

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(5, &new_list)), "Chandler"), 0);

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(6, &new_list)), "Joey"), 0);

    return 0;
}
