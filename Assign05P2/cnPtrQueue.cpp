#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP2020_A5P2
{
   cnPtrQueue::cnPtrQueue() : numItems(0){}

   bool cnPtrQueue::empty()const{return numItems == 0;}

   typename cnPtrQueue::size_type cnPtrQueue::size()const {return numItems;}

   CS3358_SP2020_A5P2::CNode* cnPtrQueue::front()
   {
      assert(!empty());
      if(inStack.empty())
      {
         do
         {
            outStack.push(inStack.top());
            inStack.pop();
         }while(!inStack.empty());
      }
      return outStack.top();
   }

   void cnPtrQueue::push(CNode* cnPtr) 
   {
      inStack.push(cnPtr);
      ++numItems;
   }

   void cnPtrQueue::pop()
   {
      if(inStack.empty())
      {
         do
         {
            outStack.push(inStack.top());
            inStack.pop();
         }while(!inStack.empty());
      }
      outStack.pop();
      --numItems;
   }
}
