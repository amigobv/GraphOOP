/*
 * Vertex.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: s1310307036
 */
#include <iostream>
#include "Edge.h"
#include "Vertex.h"

using namespace std;
/*
 * Ctor
 */
Vertex::Vertex () : Edge(0), name("") {
//  cout << "Vertex(" << name << ") default constructed" << endl;
}

Vertex::Vertex (string name, double weight) : Edge(weight), name(name){
//  cout << "Vertex(" << name << ") constructed" << endl;
}
/*
 *
 */
Vertex::Vertex (const Vertex &v) : Edge(v.getWeight()), name(v.name) {
//  cout << "Vertex(const Vertex &) copy constructor" << endl;
}
/*
 * Dtor
 */
Vertex::~Vertex () {
//  cout << "~Vertex(" << name << ") destructed" << endl;
}
/*
 * Set Vertex name
 */
void Vertex::setName(const string name) {
  this->name = name;
}
/*
 * Get Vertex name
 */
string Vertex::getName() const {
  return this->name;
}
/*
 * Implementation of the comparison operator
 */
bool Vertex::operator == (const Vertex &v) const {
  return this->name == v.name;
}
/*
 *
 */
Vertex& Vertex::operator = (const Vertex *v) {
  cout << "Vertex::operator = (const Vertex*)" << endl;

  if (this != v) {
    this->name = v->name;
    this->setWeight(v->getWeight());
  }

  return *this;
}
/*
 * Implementation of the output operator
 */
ostream& operator << (ostream &os, const Vertex &v) {
  os << v.name << endl;
  return os;
}

