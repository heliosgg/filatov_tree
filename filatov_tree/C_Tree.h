#pragma once

namespace tree
{
   typedef bool(*CompareFunc)(int, int); // left param goes right if true

   class node_t
   {
   private:

   public:
      int value;
      bool isEmpty;
      node_t* leftPtr;
      node_t* rightPtr;

      node_t() :
         value(0),
         isEmpty(true),
         leftPtr(nullptr),
         rightPtr(nullptr)
      {
      }

      void Push(int a, CompareFunc compare);
   };

   class C_Tree
   {
   private:
      CompareFunc compare = [](int el1, int el2) -> bool { return el1 > el2; };

      node_t* pRoot;
   public:
      C_Tree();

      void Push();
   };
}