// COMSC-210 | Lab 17 | Seoyeon An
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

void addFront(Node *&head, float val);
void addTail(Node *&head, float val);

void deleteNode(Node *&head, int pos);
void insertNode(Node *&head, int pos, float val);
void deleteList(Node *&head);



int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % RAND_MAX_VAL;
        addFront(head, tmp_val);
        
        // adds node at head
        // if (!head) {
        //     head = newVal;
        //     newVal->next = nullptr;
        //     newVal->value = tmp_val;
        // }
        // else {
        //     newVal->next = head;
        //     newVal->value = tmp_val;
        //     head = newVal;
        // }
    }
    output(head);

    
    cout << "Which node to delete? " << endl;
    output(head);

    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);
    output(head);
    }

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    // count = 1;
    // current = head;
    // while (current) {
    //     cout << "[" << count++ << "] " << current->value << endl;
    //     current = current->next;
    // }
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
  
    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void addTail(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}



void deleteNode(Node *&head, int pos) {
    if (!head || pos < 1) return;

    // delete head
    if (pos == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *prev = head;
    Node *current = head->next;
    int index = 2;

    
    delete current;
}

void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}