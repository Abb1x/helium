#include <data/binary_tree.h>
#include <data/dll.h>
#include <data/vector.h>
#include <debug/unit.h>
#include <types/string.h>
#include <string.h>

#define TO_STRING(x) *(char **)x
#define TO_INT(x) *(int *)x
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

    for (int i = 1; i < 7; i++)
    {
        printf("\t");
        TEST_EQUAL(strcmp(TO_STRING(new_list.get_data(i, &new_list)), friends[i - 1]), 0);
    }
    printf("\n");
    Vector vector = Vector_new();

    char *hello_world[2] = {"Hello", "World!"};

    vector.push_back(&hello_world[0], &vector);
    vector.push_back(&hello_world[1], &vector);

    log(INFO, "Testing vector:");

    for (int i = 0; i < vector.size; i++)
    {
        printf("\t");
        TEST_EQUAL(strcmp(TO_STRING(vector.data[i]), hello_world[i]), 0);
    }

    printf("\n");

    BinaryTree bin_tree = BinaryTree_new(&hello_world[0]);
    bin_tree.root->left = BinaryTreeNewNode(&hello_world[1]);

    log(INFO, "Testing binary tree:");

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(bin_tree.root->data), "Hello"), 0);

    printf("\t");

    TEST_EQUAL(strcmp(TO_STRING(bin_tree.root->left->data), "World!"), 0);

    log(INFO, "Test done!");

    String str = String_new();

    str.set("Hello", &str);

    log(TEST, "%s:%d", str.buffer,str.length(&str));

    str.append(" World!",&str);
    
    log(TEST, "%s:%d", str.buffer);

    return 0;
}
