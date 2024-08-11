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
};


class Graph {
public:
  vector<Node*> nodes;

  void addNode (Node* node) {
    nodes.push_back(node);
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
};


int main () {
  Node* one = new Node(1);
  Node* two = new Node(2);
  Node* three = new Node(3);
  Node* four = new Node(4);
  Node* five = new Node(5);
  Node* six = new Node(6);
  one->addNext(two);
  one->addNext(three);
  two->addNext(six);
  three->addNext(four);
  five->addNext(one);
  six->addNext(four);

  Graph* graph = new Graph();
  graph->addNode(one);
  graph->addNode(two);
  graph->addNode(three);
  graph->addNode(four);
  graph->addNode(five);
  graph->addNode(six);

  cout << graph->routeBetweenNodes(five, six) << endl;

  return 0;
}
