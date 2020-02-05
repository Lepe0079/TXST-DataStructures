/* Daniel Lepe
   Data Structures 3358
   02/05/19*/

#include "IntSet.h"
#include <iostream>
#include <cassert>
using namespace std;

IntSet::IntSet()
{
   used = 0;
}

int IntSet::size() const
{
   return used;
}


bool IntSet::isEmpty() const
{
   return (used < 1); 
}

bool IntSet::contains(int anInt) const
{
   if(used == 0)
      return false;
   else
   {
      for(int i = 0; i < used; ++i)
      {
         if(data[i] == anInt)
            return true;
      }
   }

   return false;
}

bool IntSet::isSubsetOf(const IntSet& otherIntSet) const
{
   if(this->isEmpty() && !otherIntSet.isEmpty())
      return true;
   for(int i = 0; i < used; ++i)
   {
      if(!otherIntSet.contains(data[i]))
         return false;
   }
   return true;
}

void IntSet::DumpData(ostream& out) const
{  // already implemented ... DON'T change anything
   if (used > 0)
   {
      out << data[0];
      for (int i = 1; i < used; ++i)
         out << "  " << data[i];
   }
}

IntSet IntSet::unionWith(const IntSet& otherIntSet) const
{
   try
   {
      if((size() + (otherIntSet.subtract(*this)).size()) > MAX_SIZE)
         throw "sets are too large";
   }
   catch(const char* msg)
   {
      cerr << msg << endl;
   }
   IntSet temp;
   for(int i = 0; i < used; ++i)
      temp.add(data[i]);
   for(int e = 0; e < otherIntSet.size(); ++e)
   {
      if(!contains(otherIntSet.data[e]))
         temp.add(otherIntSet.data[e]);
   }
   return temp; 
}

IntSet IntSet::intersect(const IntSet& otherIntSet) const
{
   IntSet temp;
   for(int i = 0; i < used; ++i)
   {
      temp.add(data[i]);
      if(otherIntSet.contains(data[i]))
         temp.remove(data[i]);
   }
      

   return temp; 
}

IntSet IntSet::subtract(const IntSet& otherIntSet) const
{
   IntSet temp;
   for(int i = 0; i < used; ++i)
      temp.add(data[i]);
   for(int e = 0; e < otherIntSet.size(); ++e)
   {
      if(temp.contains(otherIntSet.data[e]))
         temp.remove(otherIntSet.data[e]);
   }
   return temp; 
}

void IntSet::reset()
{
   used = 0;
}

bool IntSet::add(int anInt)
{

   try
   {
      if(used >= MAX_SIZE)
         throw "set is full";
   }
   catch(const char* msg)
   {
      cerr << msg << endl;
      return false;
   }
   if(contains(anInt))
      return false;
   data[used] = anInt;
   ++used;   
   return true; 
}

bool IntSet::remove(int anInt)
{
   if(contains(anInt))
   {
      int location = 0;
      for(int i = 0; i < used; ++i)
      {
         if(data[i] == anInt)
            location = i;
      }
      if(location == MAX_SIZE-1)
         data[location] = 0;
      else
      {
         for( ;location < used-1; ++location)
         {
            data[location] = data[location+1];
         }
      }
      --used;
      return true;
   }
   return false;
}

bool equal(const IntSet& is1, const IntSet& is2)
{
   if(is1.size() == is2.size())
   {
      if(is1.isEmpty() && is2.isEmpty())
         return true;
      if(is1.isSubsetOf(is2))
         return true;
   }
   return false; 
}
