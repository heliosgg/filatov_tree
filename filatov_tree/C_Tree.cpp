#include "IncludeSystem.h"

tree::C_Tree::C_Tree() :
   pRoot(new node_t)
{
}

tree::C_Tree::~C_Tree()
{
}

void tree::C_Tree::Push(int a)
{
   pRoot->Push(a, compare);
}

string tree::C_Tree::ForwardPrint()
{
   string strResult("");

   pRoot->ForwardPrint(strResult);

   return strResult;
}

string tree::C_Tree::BackwardPrint()
{
   string strResult("");

   pRoot->BackwardPrint(strResult);

   return strResult;
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

void tree::node_t::ForwardPrint(string& result)
{
   if (this->isEmpty)
   {
      return;
   }

   result.append(to_string(this->value));
   result.append(" ");

   if (this->leftPtr)
   {
      this->leftPtr->ForwardPrint(result);
   }

   if (this->rightPtr)
   {
      this->rightPtr->ForwardPrint(result);
   }
}

void tree::node_t::BackwardPrint(string& result)
{
   if (this->isEmpty)
   {
      return;
   }

   if (this->leftPtr)
   {
      this->leftPtr->BackwardPrint(result);
   }

   if (this->rightPtr)
   {
      this->rightPtr->BackwardPrint(result);
   }

   result.append(to_string(this->value));
   result.append(" ");
}
