#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace nikitov
{
  template< typename T >
  class Node;

  template< typename T >
  class ListIterator: public std::iterator< std::bidirectional_iterator_tag, T >
  {
  public:
    ListIterator(Node< T >* node):
      node_(node)
    {}
    ListIterator(const ListIterator&) = default;
    ~ListIterator() = default;

    ListIterator& operator=(const ListIterator&) = default;
    ListIterator& operator++()
    {
      node_ = node_->next_;
      return *this;
    }
    ListIterator operator++(int)
    {
      ListIterator temp(*this);
      node_ = node_->next_;
      return temp;
    }
    ListIterator& operator--()
    {
      node_ = node_->prev_;
      return *this;
    }
    ListIterator operator--(int)
    {
      ListIterator temp(*this);
      node_ = node_->prev_;
      return temp;
    }
    ListIterator& advance(int n)
    {
      if (n > 0)
      {
        for (int i = 0; i != n; ++i)
        {
          node_ = node_->next_;
        }
      }
      else if (n < 0)
      {
        for (int i = 0; i != -n; ++i)
        {
          node_ = node_->prev_;
        }
      }
      return *this;
    }
    T& operator*()
    {
      return node_->value_;
    }
    T* operator->()
    {
      return std::addressof(node_->value_);
    }

    const T& operator*() const
    {
      return node_.value;
    }
    const T* operator->() const
    {
      return std::addressof(node_.value);
    }

    bool operator==(const ListIterator& other) const
    {
      return node_ == other.node_;
    }
    bool operator!=(const ListIterator& other) const
    {
      return node_ != other.node_;
    }

  private:
    Node< T >* node_;
  };
}
#endif
