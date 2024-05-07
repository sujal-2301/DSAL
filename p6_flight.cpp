#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 20; // Maximum number of vertices
struct node         // Node structure of graph
{
    node *next;
    char vertex;
};
// Graph ADT
class graph // Graph
{
public:
    node *G[MAX]; // heads of the linked list
    graph()
    {
        // Initialize all heads of linked lists to NULL
        for (int i = 0; i < MAX; ++i)
        {
            G[i] = NULL;
        }
    }
    void insert(char vi, char vj); // insert an edge (vi,vj)
    void readgraph();
    void Display();
};
// Display Adjacency List
void graph::Display()
{
    node *p;
    for (int i = 0; i < MAX; i++)
    {
        if (G[i] != NULL)
        {
            cout << (char)('A' + i) << " ";
            p = G[i];
            while (p != NULL)
            {
                cout << "-> " << p->vertex << " ";
                p = p->next;
            }
        }
        cout << endl;
    }
}
// Read Graph
void graph::readgraph()
{
    char vi, vj;
    char ch;
    do
    {
        cout << "\nEnter an edge (u,v) :";
        cin >> vi >> vj;
        insert(vi, vj);
        insert(vj, vi);
        cout << "Do you want to continue?(y/n) : ";
        cin >> ch;
    } while (ch != 'n');
}
// Insert an edge
void graph::insert(char vi, char vj)
{
    node *p, *q;
    q = new node; // acquire memory for the new node
    q->vertex = vj;
    q->next = NULL;
    if (G[vi - 'A'] == NULL)
    { // insert the node in the linked list for the vertex no. vi
        G[vi - 'A'] = q;
    }
    else
    {
        // go to the end of linked list
        p = G[vi - 'A'];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}
int main()
{
    graph gList;
    cout << "Enter graph (Adjacency List Representation):" << endl;
    gList.readgraph();
    cout << "\nAdjacency List Representation:" << endl;
    gList.Display();
    return 0;
}
