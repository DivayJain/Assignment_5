//Student ID - 1024030294
//Assignment 5 Question 1 submitted

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

    // (a) Insertion at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at beginning.\n";
    }

    // (b) Insertion at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << val << " inserted at end.\n";
    }

    // (c) Insert before a specific value
    void insertBefore(int val, int beforeVal) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == beforeVal) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != beforeVal) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << beforeVal << " not found in the list.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted before " << beforeVal << ".\n";
    }

    // (c) Insert after a specific value
    void insertAfter(int val, int afterVal) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterVal) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << afterVal << " not found in the list.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted after " << afterVal << ".\n";
    }

    // (d) Deletion from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // (e) Deletion from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Deletion of a specific node
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            cout << val << " deleted.\n";
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << val << " not found.\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        cout << val << " deleted.\n";
        delete toDelete;
    }

    // (g) Search for a node and display its position
    void searchNode(int val) {
        int pos = 1;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << val << " not found in the list.\n";
    }

    // (h) Display all node values
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, refVal;

    while (true) {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display All Nodes\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value before which to insert: ";
            cin >> refVal;
            list.insertBefore(val, refVal);
            break;
        case 4:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter value after which to insert: ";
            cin >> refVal;
            list.insertAfter(val, refVal);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            list.searchNode(val);
            break;
        case 9:
            list.display();
            break;
        case 10:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
