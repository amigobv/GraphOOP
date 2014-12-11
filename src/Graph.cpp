/*
 * Graph.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: s1310307036
 */
#include <iostream>
#include <string>
#include "Vertex.h"

#include "Graph.h"
#include "Queue.h"

using namespace std;

/*
 * Ctor
 */
Graph::Graph (int max) : nodeCounter(0), capacity(max) {
  matrix = new Vertex*[capacity];

  for (int i = 0; i < capacity; i++) {
    matrix[i] = new Vertex[capacity];
  }

  cout << "Graph(" << capacity << ") constructed" << endl;
}
/*
 * Dtor
 */
Graph::~Graph () {
  for (int i = 0; i < capacity; i++) {
    delete[] matrix[i];
    matrix[i] = nullptr;
  }
  delete[] matrix;
  matrix = nullptr;

  cout << "~Graph(" << capacity << ") destructed" << endl;
}
/*
 *
 */
bool Graph::isEmpty() const{
  return nodeCounter == 0;
}
/*
 *
 */
bool Graph::isFull() const{
  return nodeCounter == capacity;
}
/*
 *
 */
int Graph::getSize() const{
  return capacity;
}
/*
 *
 */
bool Graph::exist(const Vertex &v) const {
  for (int i = 0; i < nodeCounter; i++) {

    if (matrix[i][i].getName() == v.getName()) {
      return true;
    }
  }

  return false;
}
/*
 *
 */
int Graph::getIndex(const Vertex &v) const {
  for (int i = 0; i < nodeCounter; i++) {

    if (matrix[i][0].getName() == v.getName()){
      return i;
    }
  }

  return capacity;
}
/*
 *
 */
void Graph::addVertex(Vertex *v) {
  if (!this->isFull() && !this->exist(*v)) {

    /*TODO: copy and assignment constructor is needed */
    matrix[0][nodeCounter].setName(v->getName());
    matrix[nodeCounter][0].setName(v->getName());
    matrix[nodeCounter][nodeCounter] = *v;
    nodeCounter++;
  }

  cout << "Vertex added " << nodeCounter << endl;
}
/*
 *
 */
void Graph::addEdge(const Vertex *start, const Vertex *end, double weight) {
  Vertex v = *end;
  int i = getIndex(*start);
  v.setWeight(weight);

  if (i == capacity and !this->isFull()) {
    matrix[nodeCounter][nodeCounter] = start;
    nodeCounter++;
  }

  int j = getIndex(*end);
  if (j == capacity and !this->isFull()) {
    matrix[nodeCounter][nodeCounter] = end;
    nodeCounter++;
  }

  matrix[i][j].setWeight(v.getWeight());
}
/*
 *
 */
void Graph::removeEdge(const Vertex *start, const Vertex *end) {
  if (this->isEmpty())
    return;

  if (exist(*start) && exist(*end)) {
    int i = getIndex(*start);
    int j = getIndex(*end);
    matrix[i][j].setWeight(0);
  }
}
/*
 *
 */
void Graph::removeAllVertexes() {
  if (this->isEmpty())
    return;

  for(int i = 0; i < nodeCounter; i++) {
    for(int j = 0; j < nodeCounter; j++) {
      matrix[i][j].setName("");
      matrix[i][j].setWeight(0);
    }
  }
  nodeCounter = 0;
}
/*
 *
 */
void Graph::removeAllEdges() {
  if (this->isEmpty())
    return;

  for(int i = 0; i < nodeCounter; i++) {
      for(int j = 0; j < nodeCounter; j++) {
        matrix[i][j].setWeight(0);
      }
    }
}
/*
 *
 */
void Graph::visitDepth(bool visited[], int n) const {
  if (visited == nullptr)
    return;

  visited[n] = true;

  for(int i = 0; i < capacity; i++) {
    double wght = matrix[n][i].getWeight();
    string name = matrix[0][i].getName();
    if(wght != 0 && !visited[i])
    {
      cout << name << '(' << wght << ')' << ", ";
      visitDepth(visited, i);
    }
  }
}
/*
 *
 */
void Graph::printDepthFirst(const Vertex* start) const {
  bool *visited = new bool[capacity];
  int n = 0;
  int idx = this->getIndex(*start);

  for(n = 0; n < capacity; n++){
    visited[n] = false;
  }

  cout << matrix[idx][0].getName() << ", ";
  for(n = idx; n < capacity; n++){
    if(!visited[n]) {
      visitDepth(visited, n);
    }
  }
  cout << endl;

  delete[] visited;
  visited = nullptr;
}

/*
 *
 */
void Graph::printBreadthFirst(const Vertex* start) const {
  Queue *gQueue = new Queue(capacity);
  bool *visited = new bool[capacity];
  int i = 0;
  Vertex *cur;

  for(i = 0; i < capacity; i++){
    visited[i] = false;
  }

  gQueue->enqueue((Vertex *)start);

  i = 0;
  while(!gQueue->isEmpty()){
    cur = gQueue->dequeue();

    cout << cur->getName() << '(' << cur->getWeight() << ')' << ", ";
    if (!visited[i]) {
      visited[i] = true;

      for (int j = 0; j < capacity; j++){
        if (matrix[i][j].getWeight() != 0 && !visited[j]){
          Vertex *next = &matrix[i][j];
          next->setName(matrix[i][0].getName());
          gQueue->enqueue(next);
        }
      }
    }
    i++;
  }

  cout << endl;

  delete gQueue;
  delete[] visited;
  gQueue = nullptr;
  visited = nullptr;
}
/*
 *
 */
ostream& operator << (ostream &os, const Graph &g) {
  if(g.isEmpty())
    return os;

  os << "\t";
  for (int i = 0; i< g.nodeCounter; i++) {
    os << g.matrix[0][i].getName() << '\t';
  }
  os << endl;

  for (int i = 0; i < g.nodeCounter; i++) {
    os << g.matrix[i][0].getName() << '\t';
    for (int j = 0; j < g.nodeCounter; j++) {
      os << g.matrix[i][j].getWeight() << '\t';
    }
    os << endl;
  }

  return os;
}

