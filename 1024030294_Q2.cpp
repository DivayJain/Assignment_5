//Student ID - 1024030294
// Assignment 5 Question 2 submitted

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
        while (temp->next != nullptr) temp = temp->next;
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

    // Count occurrences of a given key
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    // Delete all occurrences of a given key
    void deleteAllOccurrences(int key) {
        // delete from beginning while head matches key
        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        // delete from rest of the list
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
    }
};

int main() {
    SinglyLinkedList list;
    int n, val, key;

    cout << "Enter number of elements in list: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "List: ";
    list.display();

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Key " << key << " occurs " << count << " times.\n";

    list.deleteAllOccurrences(key);

    cout << "List after deleting all occurrences of " << key << ": ";
    list.display();

    return 0;
}
