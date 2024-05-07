#include <iostream>
using namespace std;

// Node structure of Tree
// create a structure of node
class node
{
public:
	int data;
	node *left;	 // left link
	node *right; // right link
};

// ADT for creating a BST
class Tree
{

public:
	int h, Flag;
	Tree()
	{
		h = 0;	  // variable to find height
		Flag = 0; // Searching Flag
	}
	void insert(node *, node *); // function to insert node
	void Height(node *, int);
	void Search(node *, int);
	void Inorder(node *);
	void Mirror(node *);
};

// Insert a node into BST
void Tree::insert(node *root, node *s)
{
	// insert at right
	if (s->data > root->data)
	{
		if (root->right == NULL)
			root->right = s;
		else
			insert(root->right, s);
	}
	// insert at left
	if (s->data <= root->data)
	{
		if (root->left == NULL)
			root->left = s;
		else
			insert(root->left, s);
	}
}

// Display In-order of BST
void Tree::Inorder(node *T)
{
	if (T)
	{
		Inorder(T->left);
		cout << " " << T->data;
		Inorder(T->right);
	}
}
// Find Height of the BST
void Tree::Height(node *root, int k)
{
	int i;

	if (root)
	{
		if (k > h)
			h = k;
		Height(root->right, k + 1);
		Height(root->left, k + 1);
	}
}

// Get Mirror Image of BST
void Tree::Mirror(node *root)
{
	node *temp;
	if (root)
	{
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		Mirror(root->left);
		Mirror(root->right);
	}
}

// Search a key value from BST
void Tree::Search(node *root, int k)
{
	int i;
	if (root)
	{
		if (k == root->data)
			Flag = 1;
		else if (k < root->data)
			Search(root->left, k);
		else
			Search(root->right, k);
	}
}

int main()
{
	int ch, c, key;
	char temp;
	node *root, *s;
	Tree t;

	root = new node;
	root = NULL;

	do
	{
		cout << "\n 1. Create & Insert New Node"
			 << "\n 2. Display-Inorder"
			 << "\n 3. Height of the Tree"
			 << "\n 4. Mirror Image"
			 << "\n 5. Search a value"
			 << "\n 6. Exit" << endl;
		cout << "\n Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			do
			{
				s = new node;
				s->left = NULL;
				s->right = NULL;

				cout << "\n ENTER DATA : ";
				cin >> s->data;

				if (root == NULL)
					root = s;
				else
					t.insert(root, s);

				cout << "\n WANT TO ENTER MORE ELEMENTS(y/n) : ";
				cin >> temp;
			} while (temp == 'y');
			break;
		case 2:
			t.Inorder(root);
			break;
		case 3:
			t.Height(root, 1);
			cout << "Height of Tree : " << t.h;
			break;
		case 4:
			t.Mirror(root);
			t.Inorder(root);
			break;
		case 5:
			cout << "\n Enter the value to be searched : ";
			cin >> key;
			t.Search(root, key);
			if (t.Flag == 1)
				cout << "Key Found Successfully\n";
			else
				cout << "Key Not Found \n";
			t.Flag = 0;
			break;
		default:
			cout << "\n You have Successfully exited \n";
			break;
		}
	} while (ch != 6);

	return 0;
}
