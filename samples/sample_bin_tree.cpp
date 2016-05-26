#include "bin_tree.hpp" 

void main()
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

	//bintree.workaround_wide_queue(root);
	//bintree.workaround_straight_rec (root);
	bintree.workaround_back_rec (root);
	//bintree.workaround_sym_rec (root);
	//bintree.workaround_stack (root);
    return;
}