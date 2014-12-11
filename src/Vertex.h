/*
 * Vertex.h
 *
 *  Created on: Dec 7, 2014
 *      Author: s1310307036
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
#include <string>
#include "Edge.h"


class Vertex: public Edge {
  private:
    std::string name;

  public:
    Vertex ();
    Vertex (std::string name, double weight = 0);
    Vertex (const Vertex &v);
    virtual ~Vertex ();

    virtual std::string getName() const;
    virtual void setName(const std::string name);

    Vertex &operator = (const Vertex *v);
    bool operator == (const Vertex &v) const;

    friend std::ostream& operator << (std::ostream &os, const Vertex &v);
};

#endif /* VERTEX_H_ */
