#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iterator>
#include "node.hpp"

namespace namestnikov
{
  template <class T>
  struct ForwardIterator: public std::iterator<std::forward_iterator_tag, T>
  {
    using this_t = ForwardIterator<T>;
    ForwardIterator(): node_(nullptr) {}
    ForwardIterator(const this_t &) = default;
    this_t & operator=(const this_t &) = default;
    this_t & operator++()
    {
      node_ = node_->next;
      return *this;
    }
    this_t operator++(int)
    {
      this_t result(*this);
      ++(*this);
      return result;
    }
    bool operator!=(const this_t & other) const
    {
      return node_ == other.node_;
    }
    bool operator==(const this_t & other) const
    {
      return !(other == *this);
    }
    T & operator*()
    {
      return node_->data_;
    }
    const T & operator*() const
    {
      return node_->data_;
    }
    T * operator->()
    {
      return std::addressof(node_->data_);
    }
    const T * operator->() const
    {
      return std::addressof(node_->data_);
    }
    ~ForwardIterator() = default;
    Node<T> * node_;
  };
}
#endif
