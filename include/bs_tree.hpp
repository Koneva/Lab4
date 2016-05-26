#include <iostream>
#include <stack>
#include <queue>

using namespace std;
typedef int ValType;

class BSNode 
{
public:
	BSNode* Left;
	BSNode* Right;
	BSNode* Parent;
	ValType key;

	//BSNode() { *this -> Left = 0; *this -> Right = 0; *this -> Parent = 0;};
	/*BSNode(ValType elem) { BSNode* bsnode = new BSNode();
							bsnode -> key = elem;}*/

	BSNode operator = (const BSNode* node) { Left = node -> Left;
											Right = node -> Right;
											Parent = node -> Parent;
											key = node -> key;
											return *this;};
};

class BSTree
{
private:
	BSNode* root;
public:
	BSTree(BSNode* node) {root = node;};

	//�����
	BSNode* FindKey(BSNode*, ValType);               //����� ���� � �������� ������
	BSNode* FindMin(BSNode*);                        //����� ������������ ��������
	BSNode* FindMax(BSNode*);                        //����� ������������� ��������

	BSNode* FindNext(BSNode*);                       //����� ���������� ��������
	BSNode* FindPrevious(BSNode*);                   //����� ����������� ��������

	//�������
	void Insert(BSNode*); 

	//��������
	void Remove(BSNode*, ValType);

	void workaround_wide_queue (BSNode*);
	void workaround_back_rec (BSNode*);
};