/*
 * main.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: s1310307036
 */
#include <iostream>

#include "Graph.h"

using namespace std;

int main() {

  Graph *g = new Graph(10);
  Vertex *list[] = { new Vertex("0"), new Vertex("1"), new Vertex("2"),
                     new Vertex("3"), new Vertex("4"), new Vertex("5")
  };

  for(int i = 0; i < 6; i++)
    g->addVertex(list[i]);

//  cout << *g << endl;

  g->addEdge(list[0], list[1], 1);
  g->addEdge(list[0], list[4], 4);
  g->addEdge(list[1], list[2], 12);
  g->addEdge(list[1], list[3], 13);
  g->addEdge(list[2], list[1], 21);
  g->addEdge(list[2], list[5], 25);
  g->addEdge(list[3], list[1], 31);
  g->addEdge(list[3], list[4], 34);

  cout << *g << endl;

  g->printDepthFirst(list[0]);
  g->printBreadthFirst(list[0]);
//
//  g->removeEdge(filip, daniel);
//
//  cout << "remove edge Filip -> Daniel" << endl;
//  cout << *g << endl;
//
//  g->removeAllEdges();
//
//  cout << "remove all edges" << endl;
//  cout << *g << endl;
//
//  g->removeAllVertexes();
//
//  cout << "remove all vertexes" << endl;
//  cout << *g << endl;

  delete g;

  return 0;
}



