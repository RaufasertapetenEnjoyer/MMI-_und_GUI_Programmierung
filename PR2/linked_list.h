#ifndef PR2_LINKED_LIST_H
#define PR2_LINKED_LIST_H
#include <iostream>
#include <cstring>
struct Node {
    char content[256];
    Node* next;
};

namespace LinkedList{
    void createNewList(Node *&root);
    int getCount(Node* &root);
    void printList(Node* &root);
    void addEntry(Node *&root, char *content);
    Node* getEntry(Node* &root, unsigned int index);
    void deleteEntryAtIndex(Node* &root, unsigned index);
    void clearList(Node* &root);
}




#endif //PR2_LINKED_LIST_H
