#include "gtest.h"
#include "d-heap.hpp"

TEST(D_HEAP, can_create_heap)
{
	D_HEAP *heap;
	ASSERT_NO_THROW(heap = new D_HEAP(2,5));
}

TEST(D_HEAP, can_copy_heap)
{
	D_HEAP *heap = new D_HEAP(2,5);
	ASSERT_NO_THROW(heap = new D_HEAP(*heap));
}

TEST(D_HEAP, can_right_copy_heap)
{
	D_HEAP *heap = new D_HEAP(2,5);
	D_HEAP *heap_new = new D_HEAP(*heap);
	EXPECT_EQ(heap_new -> GetSizeChild(), 2);
}

TEST(Heap, can_insert)
{
	D_HEAP *h = new D_HEAP(2,5);
	ASSERT_NO_THROW(h -> Insert(15));
}

TEST(Heap, can_true_insert)
{	
	D_HEAP *h = new D_HEAP(2,1);
	h -> Insert(15);
	EXPECT_EQ(h -> GetKey(0),15);
}

void D_HEAP::RemoveIdx(int idx_elem)
{
	keys[idx_elem] = keys[size_mass--];
	SiftDown(idx_elem);
}

void D_HEAP::RemoveIdxMin()
{
	keys[0] = keys[size_mass--];
	SiftDown(0);
}

void D_HEAP::Sort()
{
	int tmp = size_tree;
    for (int i = size_tree - 1; i > 0; i--) 
        RemoveIdx(0);
    size_tree = tmp;
}

void D_HEAP::Hilling()
{
	for (int i = size_tree - 1; i >= 0; i--)
		SiftDown(i); 
}
