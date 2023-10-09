#include "linked_list.h"

namespace LinkedList {

    void createNewList(Node *&root) {
        root = nullptr;
    }

    int getCount(Node *&root) {
        int elementCounter = 0;

        if (root != nullptr) {
            Node *node = root;
            while (node != nullptr) {
                elementCounter++;
                node = node->next;
            }
        }

        return elementCounter;
    }

    void printList(Node *&root) {
        std::cout << "Anzahl der Elemente: " << getCount(root) << std::endl;

        if (root != nullptr) {
            Node *node = root;

            while (node->next != nullptr) {
                std::cout << node->content << ", ";
                node = node->next;
            }
            std::cout << node->content << std::endl;
        } else {
            std::cout << "Die Liste ist leer!";
        }
    }

    void addEntry(Node *&root, char *content) {
        Node *nodeToAdd = new Node;
        strcpy(nodeToAdd->content, content);
        nodeToAdd->next = nullptr;

        if (root != nullptr) {
            Node *node = root;
            while (node->next != nullptr) {
                node = node->next;
            }

            node->next = nodeToAdd;
        } else {
            root = nodeToAdd;
        }
    }

    Node *getEntry(Node *&root, unsigned int index) {
        if (getCount(root) >= index) {
            Node *node = root;
            int counter = 0;
            while (node != nullptr) {
                if (counter == index) {
                    return node;
                } else {
                    node = node->next;
                }
                counter++;
            }
            return nullptr;
        } else {
            return nullptr;
        }
    }

    void deleteEntryAtIndex(Node *&root, unsigned int index) {
        if (getCount(root) >= index) {
            if (index == 0) {

                Node *nodeToDelete = root;
                root = root->next;
                delete nodeToDelete;

            } else if(index == getCount(root) - 1){
                Node *node = root;

                while (node->next->next != nullptr) {
                    node = node->next;
                }

                Node *nodeToDelete = node->next;
                node->next = nullptr;
                delete nodeToDelete;
            }else{
                Node *node = root;
                int counter = 0;

                while (node != nullptr) {
                    if (counter == index - 1) {
                        Node *nodeToDelete = node->next;
                        node->next = node->next->next;
                        delete nodeToDelete;
                        return;
                    }

                    counter++;
                    node = node->next;
                }
            }
        }
    }

    void clearList(Node *&root) {
        if (root != nullptr) {
            Node *node = root->next;
            while (node != nullptr) {
                Node *nodeToDelete = node;
                node = node->next;
                delete nodeToDelete;
            }

            Node *nodeToDelete = root;
            delete nodeToDelete;
            root = nullptr;
        }
    }
}