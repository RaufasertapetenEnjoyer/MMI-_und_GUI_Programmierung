#include <iostream>
#include <memory>

using namespace std;

/**
 * This class describes a node in a linked list with content
 * and a pointer to the next element.
 */
template<typename T> class Node {
public:
    Node(T content, shared_ptr<Node<T>*> next) : m_content(content), m_next(std::move(next)) {
        cout << "Created node with content " << m_content << "." << endl;
    }
    ~Node() {
        cout << "Destroyed node with content " << m_content << "." << endl;
    }

    T getContent() { return m_content; }
    void setContent(T content) { m_content = content; }

    shared_ptr<Node<T>*> getNext() { return m_next; }
    void setNext(shared_ptr<Node<T>*> next) { m_next = next; }

private:
    T m_content;
    shared_ptr<Node<T>*> m_next;
};

/**
 * Adds a node with content to the end of a linked list starting at root.
 */
template<typename T> void addNode(shared_ptr<Node<T>*> &root, T content) {
    shared_ptr<Node<T>*> newNode = make_shared<Node<T>*> (new Node<T>(content, nullptr));
    if(root == nullptr) {
        root = newNode;
    } else {
        shared_ptr<Node<T>*> lastNode = root;
        Node<T>* next = dynamic_pointer_cast<Node<T>>(lastNode.get());
        for(; *&(lastNode.get()).getNext() != nullptr; lastNode = lastNode->getNext()) {

        }
        lastNode->setNext(newNode);
    }
}

/**
 * Inserts a node with content at given position to a linked list starting at root.
 */
template<typename T> void insertNode(shared_ptr<Node<T>*> &root, T content, size_t position) {
    if(root == nullptr) {
        addNode(root, content);
        return;
    }

    shared_ptr<Node<T>*> newNode = make_shared<Node<T>*>(new Node<T>(content, nullptr));
    if(position == 0) {
        newNode->setNext(root);
        root = newNode;
        return;
    }

    shared_ptr<Node<T>*> insertNode = root;
    for(size_t i = 0; i < position-1 && insertNode->getNext() != nullptr; insertNode = insertNode->getNext(), i++) {

    }
    newNode->setNext(insertNode->getNext());
    insertNode->setNext(newNode);
}

/**
 * Prints a linked list starting at root.
 */
template<typename T> void printList(shared_ptr<Node<T>*> &root) {
    cout << endl << "List:" << endl;
    for(shared_ptr<Node<T>*> element = root; element != nullptr; element = element->getNext()) {
        cout << "- " << element->getContent() << endl;
    }
    cout << endl;
}

/**
 * Main program
 */
int main(int argc, const char * argv[]) {
    // Create sample list
    shared_ptr<Node<int>*> root = nullptr;
    addNode(root, 2);
    addNode(root, 7);
    addNode(root, 5);
    addNode(root, 1);
    addNode(root, 9);
    insertNode(root, 77, 2);
    insertNode(root, 88, 0);
    insertNode(root, 99, 7);

    // Print list
    printList(root);

    // Free memory
    shared_ptr<Node<int>*> current = root;
    while(current != nullptr) {
        shared_ptr<Node<int>*> next = current->getNext();
        current = next;
    }
    return 0;
}