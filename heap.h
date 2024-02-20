#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
   * @brief Destroy the Heap object
   *
   */
  ~Heap();

  /**
   * @brief Push an item to the heap
   *
   * @param item item to heap
   */
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

  /**
   * @brief Remove the top priority item
   *
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   *
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   *
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void trickleDown(int value); // FINISH THIS
  void heapifyUp(int index);   // FIX THIS

  std::vector<T> heap;

  PComparator comparator;
  int m_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m = 2, PComparator c)
{
  m_ = m;
  comparator = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  // IS THIS CORRECT??
  for (int i = 0; i < heap.size(); i++)
  {
    item.pop_back(i);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item)
{
  heap.push_back(item);
  heaifyUp(heap.size() - 1); // IMPLEMENT THIS
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    heap[0];
  }
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  int numItems = heap.size();
  if (empty())
  {
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");
  }
  else
  {
    heap[0] = heap[numItems - 1];
    heap.pop_back();
    trickleDown(0); // FINISH THIS
  }
}
/*
// bool if the first argument has -- priority over the second.
 template <typename T, typename PComparator>
 void Heap<T, PComparator>::trickleDown(int value)
 {
   for (int i = 0; i < heap.size(); i++)
   {
     // check priority if necessary to swap or not -- if (arr[value]->getPriority() < arr[i]->getPriority())

     if (comparator(heap[i],heap[value]))
     {
       swap(arr[i], arr[value]);
     }
   }
 }
 */

// less-than check of two items in the heap then we will have a min-heap
// greater-than check of two items in the heap, we will have a max-heap
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  if (heap.size() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return (heap.size());
}

#endif
