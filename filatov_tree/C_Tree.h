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
      ~node_t();

      void Push(int a, CompareFunc compare);
      void ForwardPrint(string& result);
      void BackwardPrint(string& result);
      void SymmetricPrint(string& result);
      void PushSubtree(node_t* subtree, CompareFunc compare); // forward walk

      bool IsExist(int a, CompareFunc compare);

      node_t* FindParent(int a);
      node_t* FindNotIntersected(node_t* another_tree, CompareFunc compare);
   };

   class C_Tree
   {
   private:
      CompareFunc compare = [](int el1, int el2) -> bool { return el1 > el2; };

      node_t* m_pRoot;
   public:
      C_Tree();
      ~C_Tree();

      void Push(int a);
      void Pop(int a);
      void Intersect(C_Tree& tree);

      bool IsExist(int a);

      string ForwardPrint();
      string BackwardPrint();
      string SymmetricPrint();

      node_t* GetRoot() { return m_pRoot; };
   };
}