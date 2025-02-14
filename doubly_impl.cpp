#include <iostream>
#include <stdexcept>

struct Node {
    std::string m_elem;
    Node* m_next;
    Node* m_prev; // Pointer to the previous node
};

class DoublyLinkedList {
private:
    Node* m_head;
    Node* m_tail;

public:
    DoublyLinkedList() : m_head(nullptr), m_tail(nullptr) {}

    // Append to the tail (O(1))
    void append(const std::string& toInsert) {
        Node* newNode = new Node;
        newNode->m_elem = toInsert;
        newNode->m_next = nullptr;
        newNode->m_prev = m_tail; // Set new node's previous to the current tail

        if (m_tail != nullptr) {
            m_tail->m_next = newNode; // Set the current tail's next to the new node
        }
        m_tail = newNode; // Update tail to the new node

        if (m_head == nullptr) {
            m_head = newNode; // If the list was empty, head is the new node
        }
    }

    // Prepend to the head (O(1))
    void prepend(const std::string& toInsert) {
        Node* newNode = new Node;
        newNode->m_elem = toInsert;
        newNode->m_prev = nullptr;
        newNode->m_next = m_head; // Set new node's next to the current head

        if (m_head != nullptr) {
            m_head->m_prev = newNode; // Set current head's previous to the new node
        }
        m_head = newNode; // Update head to the new node

        if (m_tail == nullptr) {
            m_tail = newNode; // If the list was empty, tail is also the new node
        }
    }

    // Remove a node by value (O(n))
    void remove(const std::string& toRemove) {
        Node* temp = m_head;

        while (temp != nullptr) {
            if (temp->m_elem == toRemove) {
                if (temp->m_prev != nullptr) {
                    temp->m_prev->m_next = temp->m_next; // Bypass the current node
                } else {
                    m_head = temp->m_next; // If it's the head node, move head forward
                }

                if (temp->m_next != nullptr) {
                    temp->m_next->m_prev = temp->m_prev; // Bypass the current node
                } else {
                    m_tail = temp->m_prev; // If it's the tail node, move tail backward
                }

                delete temp; // Delete the node
                return;
            }
            temp = temp->m_next;
        }
        throw std::runtime_error("Element not found");
    }

    // Remove the tail node (O(1))
    void removeTail() {
        if (m_tail == nullptr) {
            throw std::runtime_error("No tail to remove: list is empty");
        }

        Node* temp = m_tail;
        if (m_head == m_tail) { // Single node scenario
            m_head = m_tail = nullptr;
        } else {
            m_tail = m_tail->m_prev; // Move tail to the previous node
            m_tail->m_next = nullptr; // Set new tail's next to nullptr
        }

        delete temp; // Delete the last node
    }

    // Get node at a specific index (O(n))
    Node* getAt(int index) {
        Node* temp = m_head;
        int count = 0;

        while (temp != nullptr) {
            if (count == index) {
                return temp;
            }
            count++;
            temp = temp->m_next;
        }

        throw std::out_of_range("Index out of range");
    }

    // Reverse the linked list (O(n))
    void reverse() {
        Node* temp = nullptr;
        Node* current = m_head;

        // Reverse the links of the list
        while (current != nullptr) {
            temp = current->m_prev;
            current->m_prev = current->m_next;
            current->m_next = temp;
            current = current->m_prev;
        }

        // Swap head and tail
        if (temp != nullptr) {
            m_head = temp->m_prev;
        }
    }

    // Print the list from head to tail
    void printList() const {
        Node* temp = m_head;
        while (temp != nullptr) {
            std::cout << temp->m_elem << " ";
            temp = temp->m_next;
        }
        std::cout << std::endl;
    }

    // Print the list from tail to head
    void printReverse() const {
        Node* temp = m_tail;
        while (temp != nullptr) {
            std::cout << temp->m_elem << " ";
            temp = temp->m_prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Append elements
    list.append("A");
    list.append("B");
    list.append("C");

    std::cout << "List after appending: ";
    list.printList();

    // Prepend an element
    list.prepend("D");
    std::cout << "List after prepending: ";
    list.printList();

    // Remove an element
    list.remove("B");
    std::cout << "List after removing B: ";
    list.printList();

    // Remove tail
    list.removeTail();
    std::cout << "List after removing tail: ";
    list.printList();

    // Get element at index
    try {
        Node* node = list.getAt(1);
        std::cout << "Node at index 1: " << node->m_elem << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Reverse the list
    list.reverse();
    std::cout << "List after reversing: ";
    list.printList();

    // Print the list in reverse order
    std::cout << "List in reverse order: ";
    list.printReverse();

    return 0;
}
