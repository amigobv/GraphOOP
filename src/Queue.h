#ifndef QUEUE_H
#define QUEUE_H

#include <ostream>
#include "Vertex.h"

/*
  data = [ | | |x|x|x| | | | | | | | ]
          #     #     #               #
          0    start start+count      capacity
               dequeue enqueue
*/

class Queue {
  protected:
    int start, count, capacity;
    Vertex **data;        // *data[]
  private:
    inline int at(int i) const { return ((start + i) % capacity); }

  public:
    //explicit Queue(int capacity);
    Queue(int capacity);
    virtual ~Queue();

    virtual bool isEmpty() const;
    virtual bool isFull() const;

    virtual void enqueue(Vertex *item);
    virtual Vertex* dequeue();
            // verketung möglich         verkettung möglich
    friend std::ostream& operator << (std::ostream &os, const Queue &q);
    virtual void print(std::ostream &os) const;

    // add copy constructed
    Queue(const Queue &q);

    // add assignment operator
    virtual Queue &operator = (const Queue &q);
    virtual bool operator == (const Queue &q) const;

    virtual void deleteElements();
};

#endif // QUEUE_H
