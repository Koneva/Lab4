#include "gtest.h"
#include "bs_tree.hpp"

TEST(BSTree, can_sreate_node)
{
	ASSERT_NO_THROW(BSNode *root = new BSNode());
}

TEST(BSTree, can_create_tree)
{
	BSNode *root = new BSNode();
	ASSERT_NO_THROW(BSTree *bstree = new BSTree(root));
}

TEST(BSTree, can_insert_elem)
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
	BSNode* new_node =  new BSNode();
	new_node -> key = 3;
	ASSERT_NO_THROW(bstree.Insert(new_node));
}

TEST(BSTree, can_right_insert_elem)
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
	BSNode* new_node =  new BSNode();
	new_node -> key = 3;
	bstree.Insert(new_node);
	EXPECT_EQ(root -> Left -> Right -> key, 3);
}

TEST(BSTree, can_workaround_wide_queue)
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
	ASSERT_NO_THROW(bstree.workaround_wide_queue(root));
}