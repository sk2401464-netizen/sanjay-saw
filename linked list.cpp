#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Node inserted at the beginning.\n";
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Node inserted at the end.\n";
}

// Function to insert a node after a given node
void insertAfter(int key, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node with value " << key << " not found.\n";
    } else {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted after " << key << ".\n";
    }
}

// Function to traverse and display the linked list
void traverseList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main menu-driven program
int main() {
    int choice, value, key;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Given Node\n";
        cout << "4. Traverse List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtEnd(value);
            break;

        case 3:
            cout << "Enter the key (existing node value): ";
            cin >> key;
            cout << "Enter value to insert after " << key << ": ";
            cin >> value;
            insertAfter(key, value);
            break;

        case 4:
            traverseList();
            break;

        case 5:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

