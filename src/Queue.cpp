#include <iostream>
#include <cassert>
#include "Queue.h"

using namespace std;

Queue::Queue(int capacity)
  : start(0), count(0), capacity(capacity), data(nullptr) {

  data = new Vertex*[capacity];
}

Queue::~Queue() {
  delete[] data;  /* delete on nullptr is ok*/
  data = nullptr;
}

bool Queue::isEmpty() const {
  return count == 0;
}

bool Queue::isFull() const {
  return count == capacity;
}

void Queue::enqueue(Vertex* item) {
  assert(!isFull());

  data[at(count)] = item;
  count++;
}

Vertex* Queue::dequeue() {
  assert(!isEmpty());
  Vertex *item = data[start];
  start = at(1);
  --count;

  return item;
}

void Queue::print(ostream &os) const {
  os << '[';
  for (int i = 0; i < count; i++) {
    if (i > 0)
      os << ", ";
    os << *data[at(i)];  /* pointer wird gespeichert => derefenzierung notwendig*/
  }
  os << ']' << flush;
}

ostream& operator << (ostream &os, const Queue &q) {
  q.print(os);
  return os;
}

Queue::Queue(const Queue &q)
  :start(q.start), count(q.count), capacity(q.capacity) {

  cout << "Queue(const Queue&) copy constructer" << endl;
  data = new Vertex*[capacity];
  for (int i = 0; i < q.count; i++) {
    data[at(i)] = q.data[q.at(i)];  // NOTE: only referendes are copied
  }
}

Queue& Queue::operator=(const Queue& q) {
  cout << "Queue::operator=(const Queue&)" << endl;
  if (this == &q)
    return *this;

  // if capacity to small, free data
  if (capacity != q.capacity) {
    // NOTE: we are not freeing the data
    delete[] data;
    capacity = q.capacity;
    data = new Vertex*[capacity];
  }

  start = q.start;
  count = q.count;
  for (int i = 0; i < count; i++) {
    data[at(i)] = q.data[q.at(i)];
  }

  return *this;
}

bool Queue::operator == (const Queue& q) const {
  if (this == &q)
    return true;

  if (this->count != q.count ||
      this->capacity != q.capacity)
    return false;

  for (int i = 0; i < count; i++) {
    if (!(*data[at(i)] == *q.data[at(i)]))
      return false;
  }

  return true;
}

void Queue::deleteElements()
{
  while (!isEmpty()) {
    delete dequeue();
  }
}




