#include <iostream>
#include <stack>
#include <queue>

using namespace std;
typedef int ValType;

class Node 
{
public:
	Node* Left;
	Node* Right;
	ValType key;
};

class BinTree
{
private:
	Node* root;
public:
	
	BinTree(Node*);
	BinTree(const BinTree&);
	~BinTree();

	void NewTree(Node*);
	void workaround_wide_queue (Node*);           //обход в ширину через очередь
	void workaround_straight_rec (Node*);         //обход в прямом порядке с рекурсией
	void workaround_back_rec (Node*);             //обход в обратном порядке с рекурсией
	void workaround_sym_rec (Node*);              //симметричный обход с рекурсией
	void workaround_stack (Node*);                //обход в прямом порядке через стек
	void insert(Node*);                           //вставка элемента !!!!!!!
};