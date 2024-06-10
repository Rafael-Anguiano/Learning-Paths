/**
 * Kth To Last
 * Implement an algorithm to find the kth to last element of a singly Linked List.
 */

#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
    int data;
    Node * next = nullptr;
    Node (int d) {
        data = d;
    }
    void printList () {
        Node * curr = this;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int kthToLast (Node * head, int k) {
    vector<int>values;
    while(head != nullptr) {
        values.push_back(head->data);
        head = head->next;
    }
    return values[values.size()-k];
}

int main () {
    Node * head = new Node(1);
    Node * curr = head;
    for(int i=2; i<=10; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    head->printList();
    cout << kthToLast(head, 3) << endl;
}