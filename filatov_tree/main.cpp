#include "IncludeSystem.h"

using namespace tree;

int main()
{
   C_Tree A;
   C_Tree B;
   int iTemp;

   for (int i = 0; i < 13; i++)
   {
      cin >> iTemp;
      A.Push(iTemp);
   }

   cout << "A:" << A.ForwardPrint().c_str() << endl;

   for (int i = 0; i < 6; i++)
   {
      cin >> iTemp;
      B.Push(iTemp);
   }

   cout << "B:" << B.ForwardPrint().c_str() << endl;

   A.Intersect(B);

   cout << "A(intersected):" << A.ForwardPrint().c_str() << endl;

   system("pause");

   return 0;
}