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
	void workaround_wide_queue (Node*);           //����� � ������ ����� �������
	void workaround_straight_rec (Node*);         //����� � ������ ������� � ���������
	void workaround_back_rec (Node*);             //����� � �������� ������� � ���������
	void workaround_sym_rec (Node*);              //������������ ����� � ���������
	void workaround_stack (Node*);                //����� � ������ ������� ����� ����
	void insert(Node*);                           //������� �������� !!!!!!!
};