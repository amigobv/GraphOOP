/*
 * Graph.h
 *
 *  Created on: Dec 7, 2014
 *      Author: s1310307036
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include "Edge.h"
#include "Vertex.h"

class Graph {
  private:
    typedef Vertex* VertexObj;
    Vertex    **matrix;
    int       nodeCounter;
    const int capacity;

    bool exist(const Vertex &v) const;
    int getIndex(const Vertex &v) const;
    void visitDepth(bool *visited, int node) const;
    void visitBreadth(bool visited[], int n) const;

  public:
    Graph (int max);
//    Graph (Graph &q);
    virtual ~Graph ();

    virtual bool isEmpty() const;
    virtual bool isFull() const;
    virtual int getSize() const;
    virtual void addVertex(Vertex *x);
    virtual void addEdge(const Vertex *start, const Vertex *end, double weight);
    virtual void removeEdge(const Vertex *start, const Vertex *end);
    virtual void removeAllVertexes();
    virtual void removeAllEdges();
    virtual void printDepthFirst(const Vertex *start) const;
    virtual void printBreadthFirst(const Vertex *start) const;

    friend std::ostream& operator << (std::ostream &os, const Graph &g);
};

#endif /* GRAPH_H_ */
