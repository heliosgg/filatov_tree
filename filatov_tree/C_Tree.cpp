#include "IncludeSystem.h"

tree::C_Tree::C_Tree() :
   pRoot(new node_t)
{
}

void tree::node_t::Push(int a, CompareFunc compare)
{
   if (this->isEmpty)
   {
      this->value = a;
      this->isEmpty = false;
      return;
   }

   if (this->value == a)
   {
      return;
   }

   if (compare(a, this->value))
   {
      if (this->rightPtr == nullptr)
      {
         this->rightPtr = new node_t;
      }

      rightPtr->Push(a, compare);
   }
   else
   {
      if (this->leftPtr == nullptr)
      {
         this->leftPtr = new node_t;
      }

      leftPtr->Push(a, compare);
   }
}
