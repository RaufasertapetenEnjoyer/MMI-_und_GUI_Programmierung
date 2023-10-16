#include <iostream>
#include "linked_list.h"
using namespace LinkedList;
int main(int argc, const char * argv[]) {

    // Create empty list
    Node* root;
    createNewList(root);
    // Add same elements
    addEntry(root, "Alice");
    addEntry(root, "Bob");
    addEntry(root, "Charles");
    addEntry(root, "David");
    // Output list
    printList(root);

    // Delete second entry (optional)
    deleteEntryAtIndex(root, 1);
    printList(root);

    // Output second entry
    printf("Second entry: %s\n", getEntry(root, 1)->content);

    // Clear entire list
    printf("Count before clear: %d\n", getCount(root));
    clearList(root);
    printf("Count after clear: %d\n", getCount(root));
    return 0;
}