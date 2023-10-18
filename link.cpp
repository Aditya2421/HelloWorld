#include <iostream>

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr)
            return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr)
            return;

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    
    // Destructor to release memory
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);

    myList.display();

    myList.deleteNode(2);
    myList.display();

    return 0;
}
