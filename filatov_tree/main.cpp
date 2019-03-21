#include "IncludeSystem.h"

using namespace tree;

C_Tree A;
C_Tree B;
C_Tree Res;

void ThreadInput()
{
   int iTemp;
   int iChoice = 1;

   do
   {
      cin >> iTemp;
      A.Push(iTemp);

      cin >> iChoice;
   } while (iChoice);

   do
   {
      cin >> iTemp;
      B.Push(iTemp);

      cin >> iChoice;
   } while (iChoice);

   A.MakeCopy(Res);

   Res.Intersect(B);

   cout << A.ForwardPrint() << endl;
   cout << B.SymmetricPrint() << endl;
}

int main()
{
   sf::ContextSettings settings;
   settings.antialiasingLevel = 4;

   sf::RenderWindow window(sf::VideoMode(800, 800), "Tree visualizer", sf::Style::Close, settings);

   HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ThreadInput, 0, 0, 0);

   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
         {
            window.close();
         }
      }

      window.clear();

      A.DrawTree(window, sf::Vector2f(400.f, 30.f));
      B.DrawTree(window, sf::Vector2f(400.f, 280.f));
      Res.DrawTree(window, sf::Vector2f(400.f, 530.f));

      window.display();
   }

   TerminateThread(hThread, 0);

   return 0;
}