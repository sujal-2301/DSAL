#include <iostream>
using namespace std;
#include <string.h>
struct node
{
   int data;
   int weight;
   char city[10];
   node *next;
};
class graph
{
public:
   int n;
   node *G[10];
   void mapping();
   void insert(int, int, int);
   void readgraph();
   void vertices();
   void edges();
   void Display();
   void Prims();
};
void graph::mapping()
{
   node *p;
   cout << "ENTER THE NUMBER OF CITIES";
   cin >> n;
   for (int i = 0; i < n; i++)
      G[i] = NULL;
   cout << "\n ENTER" << n << "nmes of cities\n";
   for (int i = 0; i < n; i++)
   {
      cout << i << "";
      p = new node;
      p->data = i;
      p->weight = 0;
      cin >> p->city;
      p->next = NULL;
      G[i] = p;
   }
}
void graph::Display()
{
   int i;
   node *p;
   for (i = 0; i < n; i++)
   {
      p = G[i];
      while (p != NULL)
      {
         cout << p->city << " ";

         p = p->next;
      }
      cout << endl;
   }
}
void graph::readgraph()
{
   int i, vi, vj, e, w;
   char ch;
   cout << "\n Enter the number of edges(connection between cities)";
   cin >> e;
   cout << "\n Enter integer numbers 0 through " << n << endl;
   for (i = 0; i < e; i++)
   {
      cout << "\nEnter an edge & cost (u,v,w) :";
      cin >> vi >> vj >> w;
      insert(vi, vj, w);
      insert(vj, vi, w);
   }
}
void graph::insert(int vi, int vj, int w)
{
   node *p, *q;
   q = new node; // acquire memory for the new node
   q->data = vj;
   strcpy(q->city, G[vj]->city);
   q->weight = w;
   q->next = NULL;
   p = G[vi]; // Header vertex
   while (p->next != NULL)
      p = p->next;
   p->next = q;
}
void graph::Prims()
{
   node *p;
   int m, min_wt = 0;
   int v, v1, v2, wt;
   int i, j;
   int visited[10], vertex[10], city[10];
   // Initialization
   for (i = 0; i < n; i++)
   {
      visited[i] = 0; // identify whether vertex visited
      vertex[i] = -1; // visited vertex inserted
   }
   vertex[0] = 0;
   visited[0] = 1;
   cout << "\nCity connected with minimum cost are\n";
   cout << G[0]->city;
   for (i = 0; i < n - 1; i++) // No. of vertices to visit
   {
      m = 9999;                // set max value to find minimum cost
      for (j = 0; j <= i; j++) // check all edges of vistited vertex
      {
         v = vertex[j]; // get element from set of vertex
         p = G[v];      // get header node

         p = p->next;

         while (p) // if p != NULL
         {
            if (visited[p->data] == 0) // identify whether vertex

            {
               wt = p->weight;
               if (m > wt)
               {
                  m = wt;
                  v1 = v;
                  v2 = p->data;
               }
            }
            p = p->next;
         }
      }
      cout << " " << G[v2]->city;
      min_wt += m;
      vertex[j] = v2;
      visited[v2] = 1;
   }
   cout << "\n Minimum cost is " << min_wt << endl;
   cout << endl;
}

int main()
{
   graph o;
   o.mapping();
   o.readgraph();
   o.Display();
   o.Prims();
}
