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
#include <string>

using namespace std;

enum STATE {
  UNVISITED,
  VISITING,
  VISITED
};

class Node {
public:
  int data;
  vector<Node*> next;
  STATE state;

  Node(int data) {
    this->data = data;
    this->next = {};
    this->state = UNVISITED;
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
      if (node->state == VISITED) continue;

      bool result = routeBetweenNodes(node, end);
      if (result) return result;
      node->state = VISITED;
    }
    return false;
  }

  bool breadthFirstSearch (Node* start, Node* end) {
    if (start == nullptr) return false;

    cout << "Search Started" << endl;
    queue<Node*> q;
    q.push(start);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      cout << "Curr: " << curr->data << endl;

      for (Node* child : curr->next) {
        if (child->data == end->data) {
          cout << "END: " << child->data << endl;
          return true;
        }
        if (child->state == UNVISITED) {
          q.push(child);
          child->state = VISITING;
        }
      }

      curr->state = VISITED;
    }

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
  six->addNext({eight});
  seven->addNext({one, two, six});
  eight->addNext({zero, three});
  nine->addNext({four});
  ten->addNext({four, eight});


  Graph* graph = new Graph();
  graph->addNode({
    zero, one, two, three, four, five, six, seven, eight, nine, ten
  });

  // cout << graph->routeBetweenNodes(seven, three) << endl;
  
  cout << "Breadth Firts Search " << endl;
  string result = graph->breadthFirstSearch(seven, ten) ? "Route Found" : "Route Not Found";
  cout << result << endl;

  return 0;
}
