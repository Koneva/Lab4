#include "bs_tree.hpp" 

void main()
{   
	BSNode *root = new BSNode();

    root -> key = 6;
    root -> Left = new BSNode();
	root -> Parent = 0;
    root -> Left -> key = 2;
	root -> Left -> Parent = root;
    root -> Left -> Left = new BSNode();
    root -> Left -> Left -> key = 0;
	root -> Left -> Left -> Parent = root -> Left;
    root -> Left -> Left -> Left = 0;
    root -> Left -> Left -> Right = new BSNode();
	root -> Left -> Left -> Right -> key = 1;
	root -> Left -> Left -> Right -> Parent = root -> Left -> Left;
	root -> Left -> Left -> Right -> Left = 0;
	root -> Left -> Left -> Right -> Right = 0;
    root -> Left -> Right = new BSNode();
    root -> Left -> Right -> key = 4;
	root -> Left -> Right -> Parent = root -> Left;
    root -> Left -> Right -> Left = 0;
	root -> Left -> Right -> Right = new BSNode();
	root -> Left -> Right -> Right -> key = 5;
	root -> Left -> Right -> Right -> Parent = root -> Left -> Right;
    root -> Left -> Right -> Right -> Left = 0;
    root -> Left -> Right -> Right -> Right = 0;
    root -> Right = new BSNode();
    root -> Right -> key = 8;
	root -> Right -> Parent = root;
    root -> Right -> Left = new BSNode();
    root -> Right -> Left -> key = 7;
	root -> Right -> Left -> Parent = root -> Right;
    root -> Right -> Left -> Left = 0;
    root -> Right -> Left -> Right = 0;
    root -> Right -> Right = new BSNode();
	root -> Right -> Right -> key = 9;
	root -> Right -> Right -> Parent = root -> Right;
	root -> Right -> Right -> Left = 0;
	root -> Right -> Right -> Right = 0;

	BSTree bstree(root);

	bstree.FindKey(root, 5);                     //����� ���� � �������� ������
	bstree.FindMin(root);                        //����� ������������ ��������
	bstree.FindMax(root);                        //����� ������������� ��������

	bstree.FindNext(root);                       //����� ���������� ��������
	bstree.FindPrevious(root);                   //����� ����������� ��������
	

	bstree.workaround_wide_queue(root);
	cout<<endl;
	//�������
	BSNode *node = new BSNode();
	node -> key = 3;
	bstree.Insert(node); 

	bstree.workaround_wide_queue(root);

	//��������
	ValType dkey = 4;
	bstree.Remove(root, dkey);

	bstree.workaround_wide_queue(root);
    return;
}