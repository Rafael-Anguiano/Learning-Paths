/**
 * Palindrome LinkedList
 * Implement a function to check if a linkedlist is palindrome
 */

#include <iostream>
#include <vector>

using namespace std;

class Node {
    int data;
    Node * next = nullptr;

    Node (int d) {
        data = d;
    }

    void printList() {
        Node * curr = this;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};


bool isPalindromeList (Node * head) {
    Node * curr = head;
    vector<int>stack;
    while(curr != nullptr) {
        stack.push_back(curr->data);
        curr = curr->next;
    }
    while(head != nullptr) {
        if(head->data != stack[stack.size()-1] ) {
            return false;
        }
        stack.pop_back();
        head = head->next;
    }
    return true;
}


int main () {
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    cout << isPalindromeList(head) ? "Is Palindrome" : "Is not Palindrome" << endl;
    return 0;
}