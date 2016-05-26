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

	//поиск
	BSNode* FindKey(BSNode*, ValType);               //поиск узла с заданным ключом
	BSNode* FindMin(BSNode*);                        //поиск минимального элемента
	BSNode* FindMax(BSNode*);                        //поиск максимального элемента

	BSNode* FindNext(BSNode*);                       //поиск следующего элемента
	BSNode* FindPrevious(BSNode*);                   //поиск предыдущего элемента

	//вставка
	void Insert(BSNode*); 

	//удаление
	void Remove(BSNode*, ValType);

	void workaround_wide_queue (BSNode*);
	void workaround_back_rec (BSNode*);
};