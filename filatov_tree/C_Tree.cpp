#include "IncludeSystem.h"

tree::C_Tree::C_Tree() :
   m_pRoot(new node_t)
{
}

tree::C_Tree::~C_Tree()
{
   if (m_pRoot)
   {
      delete m_pRoot;
      m_pRoot = nullptr;
   }
}

void tree::C_Tree::Push(int a)
{
   m_pRoot->Push(a, compare);
}

void tree::C_Tree::Pop(int a)
{
   bool bRootToPop = !m_pRoot->isEmpty && m_pRoot->value == a;

   if (bRootToPop)
   {
      node_t* pNewRoot = new node_t;

      pNewRoot->PushSubtree(m_pRoot->leftPtr, compare);
      pNewRoot->PushSubtree(m_pRoot->rightPtr, compare);

      m_pRoot->leftPtr = nullptr;
      m_pRoot->rightPtr = nullptr;
      m_pRoot->isEmpty = true;
      m_pRoot->value = NULL;

      delete m_pRoot;

      m_pRoot = pNewRoot;

      return;
   }

   node_t* pParent = m_pRoot->FindParent(a);
   node_t* pToPop;

   pParent = m_pRoot->FindParent(a);

   if (pParent == nullptr)
   {
      return;
   }

   if (pParent->leftPtr && pParent->leftPtr->value == a)
   {
      pToPop = pParent->leftPtr;
      pParent->leftPtr = nullptr;
   }
   else
   {
      pToPop = pParent->rightPtr;
      pParent->rightPtr = nullptr;
   }

   m_pRoot->PushSubtree(pToPop->leftPtr, compare);
   m_pRoot->PushSubtree(pToPop->rightPtr, compare);

   delete pToPop;
}

void tree::C_Tree::Intersect(C_Tree& tree)
{
   node_t* pTemp = nullptr;

   while ((pTemp = m_pRoot->FindNotIntersected(tree.GetRoot(), compare)))
   {
      Pop(pTemp->value);
   }
}

bool tree::C_Tree::IsExist(int a)
{
   return m_pRoot->IsExist(a, compare);
}

string tree::C_Tree::ForwardPrint()
{
   string strResult("");

   m_pRoot->ForwardPrint(strResult);

   return strResult;
}

string tree::C_Tree::BackwardPrint()
{
   string strResult("");

   m_pRoot->BackwardPrint(strResult);

   return strResult;
}

string tree::C_Tree::SymmetricPrint()
{
   string strResult("");

   m_pRoot->SymmetricPrint(strResult);

   return strResult;
}

tree::node_t::~node_t()
{
   if (this->leftPtr)
   {
      delete this->leftPtr;
   }

   if (this->rightPtr)
   {
      delete this->rightPtr;
   }
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

void tree::node_t::SymmetricPrint(string& result)
{
   if (this->isEmpty)
   {
      return;
   }

   if (this->leftPtr)
   {
      this->leftPtr->SymmetricPrint(result);
   }

   result.append(to_string(this->value));
   result.append(" ");

   if (this->rightPtr)
   {
      this->rightPtr->SymmetricPrint(result);
   }
}

void tree::node_t::PushSubtree(node_t* subtree, CompareFunc compare)
{
   if (subtree == nullptr || subtree->isEmpty)
   {
      return;
   }

   this->Push(subtree->value, compare);

   if (subtree->leftPtr)
   {
      this->PushSubtree(subtree->leftPtr, compare);
   }

   if (subtree->rightPtr)
   {
      this->PushSubtree(subtree->rightPtr, compare);
   }
}

bool tree::node_t::IsExist(int a, CompareFunc compare)
{
   bool bResult = false;

   if (this == nullptr || this->isEmpty)
   {
      return false;
   }

   if (this->value == a)
   {
      return true;
   }

   if (compare(a, this->value))
   {
      return this->rightPtr->IsExist(a, compare);
   }
   else
   {
      return this->leftPtr->IsExist(a, compare);
   }
}

tree::node_t* tree::node_t::FindParent(int a)
{
   node_t* pTemp;

   if (this->isEmpty)
   {
      return nullptr;
   }

   if (this->leftPtr && !this->leftPtr->isEmpty)
   {
      if (this->leftPtr->value == a)
      {
         return this;
      }

      pTemp = this->leftPtr->FindParent(a);

      if (pTemp)
      {
         return pTemp;
      }
   }

   if (this->rightPtr && !this->rightPtr->isEmpty)
   {
      if (this->rightPtr->value == a)
      {
         return this;
      }

      pTemp = this->rightPtr->FindParent(a);

      if (pTemp)
      {
         return pTemp;
      }
   }

   return nullptr;
}

tree::node_t* tree::node_t::FindNotIntersected(node_t* another_tree,
   CompareFunc compare)
{
   node_t* pTemp = nullptr;

   if (this->isEmpty)
   {
      return nullptr;
   }

   if (!another_tree->IsExist(this->value, compare))
   {
      return this;
   }

   if (this->leftPtr)
   {
      pTemp = this->leftPtr->FindNotIntersected(another_tree, compare);

      if (pTemp)
      {
         return pTemp;
      }
   }

   if (this->rightPtr)
   {
      pTemp = this->rightPtr->FindNotIntersected(another_tree, compare);
   }

   return pTemp;
}
