//Student ID - 1024030294
//Assignment 5 Question 4 submitted

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;   // store next node
            current->next = prev;   // reverse current node's pointer
            prev = current;         // move prev ahead
            current = next;         // move current ahead
        }
        head = prev;                // update head to new first node
    }
};

int main() {
    SinglyLinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Original list: ";
    list.display();

    list.reverse();

    cout << "Reversed list: ";
    list.display();

    return 0;
}
