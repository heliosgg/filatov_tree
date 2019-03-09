#include "IncludeSystem.h"

using namespace tree;

int main()
{
   C_Tree pTree;
   int iTemp;

   for (int i = 0; i < 6; i++)
   {
      cin >> iTemp;
      pTree.Push(iTemp);
   }

   cout << pTree.BackwardPrint().c_str() << endl;

   system("pause");

   return 0;
}