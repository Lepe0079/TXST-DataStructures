/* Daniel Lepe
   Data Structures 3358
   05/05/20*/

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

QueueCLL::QueueCLL() : numItems(0)
{
   rear_ptr = new Node;
   rear_ptr->link = rear_ptr;
   rear_ptr->data = -1;
}

QueueCLL::QueueCLL(const QueueCLL& src) : numItems(src.numItems)
{
   Node* cursor = src.rear_ptr->link;
   rear_ptr = new Node;
   rear_ptr->link = rear_ptr;
   rear_ptr->data = -1;
   numItems = 0;

   while(numItems != src.numItems)
   {
      push(cursor->data);
      cursor = cursor->link;
   }

}

QueueCLL::~QueueCLL()
{
   if(!rear_ptr)//short case
   {
      delete rear_ptr;
      rear_ptr = 0;
      return; 
   }

   Node* cursor = rear_ptr;
   Node* next;
   while(cursor != rear_ptr)
   {
      next = cursor->link;
      delete cursor;
      cursor = next;
   }
   delete cursor;
   rear_ptr = 0;
   cursor = 0;
   next = 0; 
}

QueueCLL& QueueCLL::operator=(const QueueCLL& rhs)
{
   if(this == &rhs)//self case
      return *this;

   if(rhs.numItems == 0)//zero case
   {
      while(!empty())
         pop();
      rear_ptr->data = -1;
      rear_ptr->link = rear_ptr;
      numItems = 0;
      return *this;
   }
   
   Node* newData = new Node;
   Node* rhsCursor = rhs.rear_ptr;

   newData->link = newData;
   newData->data = rhsCursor->data;
   
   while(!empty())
      pop();
   
   delete rear_ptr;
   rear_ptr = newData;
   
   while(numItems < rhs.numItems)
   {
      rhsCursor = rhsCursor->link;
      push(rhsCursor->data);
   }
   return *this;
}

void QueueCLL::push(const value_type& entry)
{
   if(numItems == 0)
   {
      rear_ptr->data = entry;
      ++numItems;
      return;
   }

   Node* newData = new Node;
   newData->data = entry;
   newData->link = rear_ptr->link;
   rear_ptr->link = newData;
   rear_ptr = newData;

   ++numItems;   
   
}

QueueCLL::value_type QueueCLL::front( ) const
{
   assert(size() > 0);
   return rear_ptr->link->data;
}

void QueueCLL::pop( )
{
   assert(size() > 0);
   Node* temp = rear_ptr->link;
   rear_ptr->link = temp->link;
   delete temp;
   temp = 0;
   --numItems;
}

QueueCLL::size_type QueueCLL::size() const {return numItems;}

bool QueueCLL::empty() const {return (numItems == 0);}

QueueCLL::value_type QueueCLL::peek(size_type n) const
{
   assert(size() > 0);
   if(rear_ptr->link == rear_ptr)
      return rear_ptr->data;

   size_type traversal = 0;

   if(n > numItems)
      traversal = n % numItems;//shorten the trip
   else
      traversal = n;

   Node* index = rear_ptr->link;

   for(size_type i = 1; i < traversal; ++i)
      index = index->link;

   return index->data;
}

