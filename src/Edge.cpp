/*
 * Weighted.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: s1310307036
 */
#include <iostream>

#include "Edge.h"

using namespace std;

Edge::Edge (double weight) : weight(weight) {
//  cout << "Edge(" << weight << ") constructed" << endl;
}
/*
 *
 */
Edge::~Edge () {
//  cout << "~Edge(" << weight << ") destructed" << endl;
}
/*
 *
 */
double Edge::getWeight() const {
  return weight;
}
/*
 *
 */
void Edge::setWeight(double weight) {
  this->weight = weight;
}
