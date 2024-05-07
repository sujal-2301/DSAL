#include <iostream>
using namespace std;

// Node structure of Tree
// create a structure of node
class node
{
public:
	int data;
	node *link[10]; // 10-ary tree
};
// ADT for creating a book
class Tree
{
public:
	void insertChap(node *);   // function to insert Chapter
	void insertSec(node *);	   // function to insert Section
	void insertSubSec(node *); // function to insert SubSection void display(node *); //function to display Book Index
};
// Insert chapters in a book
void Tree::insertChap(node *root)
{
	int chap;
	node *n;
	cout << "\nHow many chapters are in the Book?";
	cin >> chap;
	for (int i = 0; i < chap; i++)
	{

		n = new node;
		n->data = i + 1;
		for (int j = 0; j < 10; j++)
			n->link[j] = NULL;
		root->link[i] = n;
		insertSec(root->link[i]);
	}
}
// Insert section in a chapter
void Tree::insertSec(node *root)
{
	if (root->data != 0)
	{
		int sec;
		node *n;
		cout << "\nHow many sections are in the chapter " << root->data << "?";
		cin >> sec;
		for (int i = 0; i < sec; i++)
		{
			n = new node;
			n->data = i + 1;
			for (int j = 0; j < 10; j++)
				n->link[j] = NULL;
			root->link[i] = n;
			insertSubSec(root->link[i]);
		}
	}
}
// Insert subsection in a section
void Tree::insertSubSec(node *root)
{
	if (root->data != 0)
	{
		int subsec;
		node *n;
		cout << "\nHow many subsections are in the section " << root->data << "?";
		cin >> subsec;
		for (int i = 0; i < subsec; i++)
		{
			n = new node;
			n->data = i + 1;
			for (int j = 0; j < 10; j++)
				n->link[j] = NULL;
			root->link[i] = n;
		}
	}
	// Display a book index
}
void display(node *root)
{
	if (root)
	{
		cout << "\nBook Index";
		for (int i = 0; root->link[i] != NULL; i++)
		{
			node *ch;
			ch = root->link[i];
			cout << "\n"
				 << ch->data << " Chapter";
			for (int j = 0; ch->link[j] != NULL; j++)
			{
				node *s;
				s = ch->link[j];
				cout << endl;
				cout << "\t" << ch->data << "." << s->data << " Section";
				for (int k = 0; s->link[k] != NULL; k++)
				{
					node *ss;
					ss = s->link[k];
					cout << endl;
					cout << "\t\t" << ch->data << "." << s->data << "." << ss->data << " Subsection";
				}
			}
		}
	}
}

void menu()
{
	node *n = new node();
	Tree *t = new Tree();
	char ch = 'y';
	int option;
	while (ch == 'y')
	{
		cout << "********Welcome*******" << endl;
		cout << "1. Create Book" << endl;
		cout << "2. Display Book" << endl;
		cout << "Enter your choice : ";
		cin >> option;
		switch (option)
		{
		case 1:

			t->insertChap(n);
			t->insertSec(n);
			t->insertSubSec(n);
			cout << endl;
			break;

		case 2:
			display(n);
		}
		cout << endl
			 << "Do you want to continue?? y/n : ";
		cin >> ch;
	}
}
int main()
{

	menu();
	cout << endl
		 << "program ended!" << endl;
}
