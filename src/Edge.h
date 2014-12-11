/*
 * Weighted.h
 *
 *  Created on: Dec 8, 2014
 *      Author: s1310307036
 */

#ifndef EDGE_H_
#define EDGE_H_

class Edge {
  private:
    double weight;

  public:
    Edge (double weight = 0);
    virtual ~Edge ();

    virtual double getWeight() const;
    virtual void   setWeight(double weight);
};

#endif /* EDGE_H_ */
