/**
* Route Between Nodes:
* Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
*
* Example:
* Input: 
* 
*
* Output: Boolean
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    vector<Node*> next;
    bool visited;

    Node(int data) {
        this->data = data;
        this->next = {};
        this->visited = false;
    }

    void addNext(Node* node) {
      next.push_back(node);
    }
    void addNext(vector<Node*> nodes) {
      this->next = nodes;
    }
};


class Graph {
public:
  vector<Node*> nodes;

  void addNode (Node* node) {
    this->nodes.push_back(node);
  }
  void addNode (vector<Node*> nodes) {
    this->nodes = nodes;
  }

  bool routeBetweenNodes (Node* start, Node* end) {
    if (start == nullptr) return false;

    for (Node* node : start->next)
      if (node->data == end->data) return true;

    for (Node* node : start->next) {
      if (node->visited) continue;

      bool result = routeBetweenNodes(node, end);
      if (result) return result;
      node->visited = true;
    }
    return false;
  }

  bool breadthFirstSearch (Node* start, Node* end) {
    if (start == nullptr) return false;

    queue<Node*> q;
    q.push(start);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      if (curr->visited) continue;
      cout << "Curr: " << curr->data << endl;

      for (Node* child : curr->next) {
        if (child->data == end->data) {
          cout << "END: " << child->data << endl;
          return true;
        }
        if (!child->visited) q.push(child);
      }

      curr->visited = true;
    }
    cout << "Finished" << endl;

    return false;
  }
};


int main () {
  Node* zero = new Node(0);
  Node* one = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);
  Node* five = new Node(5);
  Node* six = new Node(6);
  Node* seven = new Node(7);
  Node* eight = new Node(8);
  Node* nine = new Node(9);
  Node* ten = new Node(10);

  /**
    * Conections
    */
  zero->addNext({five, nine});
  one->addNext({five, six});
  // two no have next
  three->addNext({zero});
  four->addNext({two});
  five->addNext({zero});
  six->addNext({four});
  seven->addNext({one, two, six});
  eight->addNext({zero, three});
  nine->addNext({four});
  ten->addNext({four, eight});


  Graph* graph = new Graph();
  graph->addNode({
    zero, one, two, three, four, five, six, seven, eight, nine, ten
  });

  cout << graph->routeBetweenNodes(seven, five) << endl;
  
  cout << "Breadth Firts Search " << endl; 
  cout << graph->breadthFirstSearch(seven, three) << endl;

  return 0;
}
