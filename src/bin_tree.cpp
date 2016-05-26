#include "bin_tree.hpp"

BinTree::BinTree(Node* root)
{
	this -> root = root;
}

BinTree::~BinTree()
{
	root = NULL;
}

BinTree::BinTree(const BinTree &btree)
{
	if(btree.root == 0) return;
	this -> root = btree.root;
	BinTree btree1(root);

}

//обход вширину без рекурсии с использованием очереди
void BinTree::workaround_wide_queue (Node* node)
{
	queue <Node*> q;

	q.push(node);
	while(!q.empty())
	{
		Node* tmp = q.front();
		cout << tmp -> key << endl;
		q.pop();

		if(tmp -> Left != 0)
			q.push(tmp -> Left);
		if(tmp -> Right != 0)
			q.push(tmp -> Right);
	}
}

//обход  в пр€мом пор€дке с рекурсией
void BinTree::workaround_straight_rec (Node* node)
{
	if (node == 0) return;

	cout << node -> key << endl;
	workaround_straight_rec (node -> Left);
	workaround_straight_rec (node -> Right);
}

void BinTree::workaround_back_rec (Node* node)
{
	if (node == 0) return;

	workaround_back_rec (node -> Right);
	workaround_back_rec (node -> Left);
	cout << node -> key << endl;
}

void BinTree::workaround_sym_rec (Node* node)
{
	if (node == 0) return;

	workaround_sym_rec (node -> Right);
	cout << node -> key << endl;
	workaround_sym_rec (node -> Left);
}

//обход в пр€мом пор€дке без рекурсии с использование стека
void BinTree::workaround_stack (Node* node)
{
	if (node == 0) return;

	stack <Node*> s;
	s.push(node);

	while (!s.empty())
	{
		Node* tmp = s.top();
		cout << tmp -> key << endl;
		s.pop();

		if (tmp -> Right != 0)
			s.push(tmp -> Right);
		if (tmp -> Left != 0)
			s.push(tmp -> Left);
	}
}

void BinTree::insert(Node* node)
{
	int i = 0;
	ValType n;

	cout << "" << endl;
	cin >> i ; 
	Node* node1 = new Node;
	cout << "" << endl;
	cin >> n;
	node1 -> key = n;
	 
	if (i = 0)
		node -> Left = node1;
	if (i = 1)
		node -> Right = node1;
}
