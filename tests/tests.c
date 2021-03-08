#include <helium/data/dll.h>
#include <helium/debug/unit.h>
#include <string.h>
int main()
{

    int a = 10;

    TEST_EQUAL(a, 10);

    DLL new_list = DoublyLinkedList();

    char *friends[6] = {"Monica", "Ross", "Rachel", "Phoebe", "Chandler", "Joey"};

    new_list.append(&friends[0], &new_list);
    new_list.append(&friends[1], &new_list);
    new_list.append(&friends[2], &new_list);
    new_list.append(&friends[3], &new_list);
    new_list.append(&friends[4], &new_list);
    new_list.append(&friends[5], &new_list);
    
    new_list.print_str(&new_list);
 
    log(INFO, "INFO");
    log(DEBUG, "DEBUG");
    log(WARNING, "WARNING");
    log(ERROR, "ERROR");

    return 0;
}
