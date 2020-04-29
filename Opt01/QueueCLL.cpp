// FILE: QueueCLL.cpp
// IMPLEMENTS: QueueCLL (see QueueCLL.h for documentation.)
//
// INVARIANT for the QueueCLL class:
//   1. The number of items in the QueueCLL is stored in the member
//      variable numItems.
//   2. The items themselves are stored in a circular linked list
//      of Nodes.
//      2.1 The member variable rear_ptr points to the rear of the
//          QueueCLL (tail node of the circular linked list).
//      2.2 The rear_ptr is set to the null address if the circular
//          linked list (thus queue) is empty.

#include <iostream>
#include <cassert>  // provides assert
#include <cstdlib>  // provides size_t
using namespace std;

#include "QueueCLL.h"   

QueueCLL::QueueCLL()
{
   cerr << "Not implemented yet" << endl;
}

QueueCLL::QueueCLL(const QueueCLL& src) : numItems(src.numItems)
{
   cerr << "Not implemented yet" << endl;
}

QueueCLL::~QueueCLL()
{
   cerr << "Not implemented yet" << endl;
}

QueueCLL& QueueCLL::operator=(const QueueCLL& rhs)
{
   cerr << "Not implemented yet" << endl;
   return *this;
}

void QueueCLL::push(const value_type& entry)
{
   cerr << "Not implemented yet" << endl;
}

QueueCLL::value_type QueueCLL::front( ) const
{
   cerr << "Not implemented yet" << endl;
   return 0; // dummy return value
}

void QueueCLL::pop( )
{
   cerr << "Not implemented yet" << endl;
}

QueueCLL::size_type QueueCLL::size() const
{
   cerr << "Not implemented yet" << endl;
   return 0; // dummy return value
}

bool QueueCLL::empty() const
{
   cerr << "Not implemented yet" << endl;
   return false; // dummy return value
}

QueueCLL::value_type QueueCLL::peek(size_type n) const
{
   cerr << "Not implemented yet" << endl;
   return 0; // dummy return value
}

