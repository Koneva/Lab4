#include "bs_tree.hpp"

BSNode* BSTree::FindKey(BSNode* root, int key)
{
	root->Left = NULL;
	root->Right = NULL;
	root->Parent = NULL;
	if(root == 0) return NULL;
	while(root -> key != key)
	{
		if(key < root -> key)
			root = root -> Left;
		else
			root = root -> Right;
	}
	return root;
}

BSNode* BSTree::FindNext(BSNode* node)
{
	if(node == 0) return NULL;
	if(node -> Right !=0)
		return FindMin(node -> Right);
	while((node -> Parent != 0) && (node -> Parent -> Right == node))
		node = node -> Parent;
	return node -> Parent;
}

BSNode* BSTree::FindMin(BSNode* root)
{
	if(root == 0) return NULL;
	while(root -> Right != 0)
		root = root -> Right;
	return root;
}

BSNode* BSTree::FindMax(BSNode* root)
{
	if(root == 0) return NULL;
	while(root -> Left != 0)
		root = root -> Left;
	return root;
}

BSNode* BSTree::FindPrevious(BSNode* node)
{
	if(node == 0) return NULL;
	if(node -> Left != 0)
		return FindMax(node -> Left);
	while((node -> Parent != 0) && (node -> Parent -> Left == node))
		node = node -> Parent;
	return node -> Parent;
}

void BSTree::Insert(BSNode* node)
{

	if(root == 0) 
	{
		root = node;
		return;
	}
	BSNode* x = root;
	BSNode* y = x;
	while(x != 0)
	{
		y = x;
		if(x -> key <= node -> key)
			x = x -> Right;
		else
			x = x -> Left;
	}
		if(y -> key <= node -> key)
			y -> Right = node;
		else
			y -> Left = node;
		node -> Parent = y; 
}

void BSTree::Remove(BSNode * root, ValType k)
{
	BSNode* x = FindKey(root, k);
	if(x == 0) return;

	if((x -> Left == 0) && (x -> Right == 0))
	{
		if(x -> Parent -> Right = x)
			x -> Parent -> Right = 0;
		else
			x -> Parent -> Left = 0;
		delete x;
		return;
	}
	if((x -> Left == 0) && (x -> Right != 0))
	{
		BSNode* y = x -> Right;
		y -> Parent = x -> Parent;
		if(x -> Parent -> Right == x)
			x -> Parent -> Right = y;
		else
			x -> Parent -> Left = y;
		delete x;
		return;
	}
	if((x -> Left != 0) && (x -> Right == 0))
	{
		BSNode* y = x -> Left;
		y -> Parent = x -> Parent;
		if(x -> Parent -> Right == x)
			x -> Parent -> Right = y;
		else
			x -> Parent -> Left = y;
	}
	if((x -> Left != 0) && (x -> Right != 0))
	{
		BSNode* y = FindMin(x -> Right);
		x -> key = y -> key;
		if(y -> Right != 0)
		{
			y -> Parent -> Left  = y -> Right;
			y -> Right -> Parent = y -> Parent;
		}
		else
			y -> Parent -> Left = 0;
		delete y;
	}
}


void BSTree::workaround_back_rec (BSNode* node)
{
	if (node == 0) return;

	workaround_back_rec (node -> Right);
	workaround_back_rec (node -> Left);
	cout << node -> key << endl;
}

void BSTree::workaround_wide_queue (BSNode* node)
{
	queue <BSNode*> q;

	q.push(node);
	while(!q.empty())
	{
		BSNode* tmp = q.front();
		cout << tmp -> key << endl;
		q.pop();

		if(tmp -> Left != 0)
			q.push(tmp -> Left);
		if(tmp -> Right != 0)
			q.push(tmp -> Right);
	}
}
