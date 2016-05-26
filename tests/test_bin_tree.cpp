#include "gtest.h"
#include "bin_tree.hpp"

TEST(BinTree, can_sreate_node)
{
	ASSERT_NO_THROW(Node *root = new Node());
}
TEST(BinTree, can_create_tree)
{
	Node *root = new Node();
	ASSERT_NO_THROW(BinTree *bintree = new BinTree(root));
}

TEST(BinTree, can_workaround_stack)
{
	Node *root = new Node();

    root -> key = 6;
    root -> Left = new Node();
    root -> Left -> key = 2;
    root -> Left -> Left = new Node();
    root -> Left -> Left -> key = 0;
    root -> Left -> Left -> Left = 0;
    root -> Left -> Left -> Right = new Node();
	root -> Left -> Left -> Right -> key = 1;
	root -> Left -> Left -> Right -> Left = 0;
	root -> Left -> Left -> Right -> Right = 0;
    root -> Left -> Right = new Node();
    root -> Left -> Right -> key = 4;
    root -> Left -> Right -> Left = 0;
	root -> Left -> Right -> Right = new Node();
	root -> Left -> Right -> Right -> key = 5;
    root -> Left -> Right -> Right -> Left = 0;
    root -> Left -> Right -> Right -> Right = 0;
    root -> Right = new Node();
    root -> Right -> key = 8;
    root -> Right -> Left = new Node();
    root -> Right -> Left -> key = 7;
    root -> Right -> Left -> Left = 0;
    root -> Right -> Left -> Right = 0;
    root -> Right -> Right = new Node();
	root -> Right -> Right -> key = 9;
	root -> Right -> Right -> Left = 0;
	root -> Right -> Right -> Right = 0;

	BinTree bintree(root);

	ASSERT_NO_THROW(bintree.workaround_stack(root));
}

TEST(BinTree, can_workaround_sym_rec)
{
	Node *root = new Node();

    root -> key = 6;
    root -> Left = new Node();
    root -> Left -> key = 2;
    root -> Left -> Left = new Node();
    root -> Left -> Left -> key = 0;
    root -> Left -> Left -> Left = 0;
    root -> Left -> Left -> Right = new Node();
	root -> Left -> Left -> Right -> key = 1;
	root -> Left -> Left -> Right -> Left = 0;
	root -> Left -> Left -> Right -> Right = 0;
    root -> Left -> Right = new Node();
    root -> Left -> Right -> key = 4;
    root -> Left -> Right -> Left = 0;
	root -> Left -> Right -> Right = new Node();
	root -> Left -> Right -> Right -> key = 5;
    root -> Left -> Right -> Right -> Left = 0;
    root -> Left -> Right -> Right -> Right = 0;
    root -> Right = new Node();
    root -> Right -> key = 8;
    root -> Right -> Left = new Node();
    root -> Right -> Left -> key = 7;
    root -> Right -> Left -> Left = 0;
    root -> Right -> Left -> Right = 0;
    root -> Right -> Right = new Node();
	root -> Right -> Right -> key = 9;
	root -> Right -> Right -> Left = 0;
	root -> Right -> Right -> Right = 0;

	BinTree bintree(root);

	ASSERT_NO_THROW(bintree.workaround_sym_rec (root));
}

TEST(BinTree, can_workaround_back_rec)
{
	Node *root = new Node();

    root -> key = 6;
    root -> Left = new Node();
    root -> Left -> key = 2;
    root -> Left -> Left = new Node();
    root -> Left -> Left -> key = 0;
    root -> Left -> Left -> Left = 0;
    root -> Left -> Left -> Right = new Node();
	root -> Left -> Left -> Right -> key = 1;
	root -> Left -> Left -> Right -> Left = 0;
	root -> Left -> Left -> Right -> Right = 0;
    root -> Left -> Right = new Node();
    root -> Left -> Right -> key = 4;
    root -> Left -> Right -> Left = 0;
	root -> Left -> Right -> Right = new Node();
	root -> Left -> Right -> Right -> key = 5;
    root -> Left -> Right -> Right -> Left = 0;
    root -> Left -> Right -> Right -> Right = 0;
    root -> Right = new Node();
    root -> Right -> key = 8;
    root -> Right -> Left = new Node();
    root -> Right -> Left -> key = 7;
    root -> Right -> Left -> Left = 0;
    root -> Right -> Left -> Right = 0;
    root -> Right -> Right = new Node();
	root -> Right -> Right -> key = 9;
	root -> Right -> Right -> Left = 0;
	root -> Right -> Right -> Right = 0;
	
	BinTree bintree(root);

	ASSERT_NO_THROW(bintree.workaround_back_rec (root));
}

TEST(BinTree, can_workaround_straight_rec)
{
	Node *root = new Node();

    root -> key = 6;
    root -> Left = new Node();
    root -> Left -> key = 2;
    root -> Left -> Left = new Node();
    root -> Left -> Left -> key = 0;
    root -> Left -> Left -> Left = 0;
    root -> Left -> Left -> Right = new Node();
	root -> Left -> Left -> Right -> key = 1;
	root -> Left -> Left -> Right -> Left = 0;
	root -> Left -> Left -> Right -> Right = 0;
    root -> Left -> Right = new Node();
    root -> Left -> Right -> key = 4;
    root -> Left -> Right -> Left = 0;
	root -> Left -> Right -> Right = new Node();
	root -> Left -> Right -> Right -> key = 5;
    root -> Left -> Right -> Right -> Left = 0;
    root -> Left -> Right -> Right -> Right = 0;
    root -> Right = new Node();
    root -> Right -> key = 8;
    root -> Right -> Left = new Node();
    root -> Right -> Left -> key = 7;
    root -> Right -> Left -> Left = 0;
    root -> Right -> Left -> Right = 0;
    root -> Right -> Right = new Node();
	root -> Right -> Right -> key = 9;
	root -> Right -> Right -> Left = 0;
	root -> Right -> Right -> Right = 0;
	
	BinTree bintree(root);

	ASSERT_NO_THROW(bintree.workaround_straight_rec (root));
}

TEST(BinTree, can_workaround_wide_queue)
{
	Node *root = new Node();

    root -> key = 6;
    root -> Left = new Node();
    root -> Left -> key = 2;
    root -> Left -> Left = new Node();
    root -> Left -> Left -> key = 0;
    root -> Left -> Left -> Left = 0;
    root -> Left -> Left -> Right = new Node();
	root -> Left -> Left -> Right -> key = 1;
	root -> Left -> Left -> Right -> Left = 0;
	root -> Left -> Left -> Right -> Right = 0;
    root -> Left -> Right = new Node();
    root -> Left -> Right -> key = 4;
    root -> Left -> Right -> Left = 0;
	root -> Left -> Right -> Right = new Node();
	root -> Left -> Right -> Right -> key = 5;
    root -> Left -> Right -> Right -> Left = 0;
    root -> Left -> Right -> Right -> Right = 0;
    root -> Right = new Node();
    root -> Right -> key = 8;
    root -> Right -> Left = new Node();
    root -> Right -> Left -> key = 7;
    root -> Right -> Left -> Left = 0;
    root -> Right -> Left -> Right = 0;
    root -> Right -> Right = new Node();
	root -> Right -> Right -> key = 9;
	root -> Right -> Right -> Left = 0;
	root -> Right -> Right -> Right = 0;
	
	BinTree bintree(root);

	ASSERT_NO_THROW(bintree.workaround_wide_queue(root));
}