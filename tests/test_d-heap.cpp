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
	EXPECT_EQ(*heap,*heap_new);
}

TEST(D_HEAP, can_insert)
{
	D_HEAP *h = new D_HEAP(2,5);
	ASSERT_NO_THROW(h -> Insert(15));
}

TEST(D_HEAP, can_true_insert)
{	
	D_HEAP *h = new D_HEAP(2,2);
	h -> Insert(15);
	h -> Insert(0);
	EXPECT_EQ(h -> GetKey(0),0);
}

TEST(D_HEAP , can_get_size_tree)
{
	D_HEAP h(2,10);
	ASSERT_NO_THROW(h.GetSizeTree());
}

TEST(D_HEAP , can_get_size_child)
{
	D_HEAP h(2,10);
	ASSERT_NO_THROW(h.GetSizeChild());
}

TEST(D_HEAP , can_get_size_mass)
{
	D_HEAP h(2,10);
	ASSERT_NO_THROW(h.GetSizeMass());
}

TEST(D_HEAP , can_get_key)
{
	D_HEAP h(2,10);
	for(int i = 0; i < 10; i++)
		h.Insert(i);
	ASSERT_NO_THROW(h.GetKey(5));
}

TEST(D_HEAP, getkey_works_propenly)
{
	D_HEAP h(2,10);
	for(int i = 0; i < 10; i++)
		h.Insert(i);
	EXPECT_EQ(h.GetKey(0), 0);
}

TEST(D_HEAP , cant_get_key_by_invalid_idx)
{
	D_HEAP h(2,10);
	ASSERT_ANY_THROW(h.GetKey(-1));
	ASSERT_ANY_THROW(h.GetKey(0));
}

TEST(D_HEAP , cant_insert_elem_to_full_heap)
{
	D_HEAP h(2,2);
	for(int i = 0; i < 2; i++)
		h.Insert(i);
	ASSERT_ANY_THROW(h.Insert(3));
}

TEST(D_HEAP , cant_siftup_elem_with_invalid_idx)
{
	D_HEAP h(2,3);
	ASSERT_ANY_THROW(h.SiftUp(-1));
	ASSERT_ANY_THROW(h.SiftUp(4));
}

TEST(D_HEAP , cant_transposition_elem_with_invalid_idx)
{
	D_HEAP h(2,3);
	ASSERT_ANY_THROW(h.Transposition(-1,1));
	ASSERT_ANY_THROW(h.Transposition(1,-1));
	ASSERT_ANY_THROW(h.Transposition(4,1));
	ASSERT_ANY_THROW(h.Transposition(1,4));
}

TEST(D_HEAP , cant_siftdown_elem_with_invalid_idx)
{
	D_HEAP h(2,3);
	ASSERT_ANY_THROW(h.SiftDown(-1));
	ASSERT_ANY_THROW(h.SiftDown(4));
}

TEST(D_HEAP , can_assigne)
{
	D_HEAP h1(2,3);
	D_HEAP h2(3,4);
	ASSERT_NO_THROW(h1 = h2);
}

TEST(D_HEAP , assigned_heap_is_equal_to_source_one)
{
	D_HEAP h(2,3);
	for(int i = 0; i < 3; i++)
		h.Insert(3);
	D_HEAP h2(2,3);
	h2 = h;
	ASSERT_EQ(h,h2);
}

TEST(D_HEAP , can_get_min_child)
{
	D_HEAP h(2,4);
	h.Insert(0);
	h.Insert(3);
	h.Insert(2);
	ASSERT_NO_THROW(h.MinChild(0));
}

TEST(D_HEAP , can_get_min_child_true)
{
	D_HEAP h(2,4);
	h.Insert(0);
	h.Insert(3);
	h.Insert(2);
	EXPECT_EQ(h.GetKey(h.MinChild(0)), 2);
}

TEST(D_HEAP, hilling_works)
{
	D_HEAP a(2, 10);
	for(int i = 0; i < 10; i++)
		a.Insert(i);
	D_HEAP b(a);
	b.Transposition(0,9);
	b.Hilling();
	EXPECT_EQ(a,b);
}

TEST(D_HEAP, swap_does_not_change_sizeTree)
{
	D_HEAP a(2, 10);
	for(int i = 0; i < 10; i++)
		a.Insert(i);
	int tmp = a.GetSizeTree();
	a.Transposition(0, 9);
	EXPECT_EQ(tmp, a.GetSizeTree());
}

TEST(D_HEAP, siftUp_does_not_change_sizeTree)
{
	D_HEAP a(2, 10);
	for(int i = 0; i < 10; i++)
		a.Insert(i);
	int tmp = a.GetSizeTree();
	a.Transposition(0, 9);
	a.SiftUp(9);
	EXPECT_EQ(tmp, a.GetSizeTree());
}

TEST(D_HEAP, siftDown_does_not_change_sizeTree)
{
	D_HEAP a(2, 10);
	for(int i = 0; i < 10; i++)
		a.Insert(i);
	int tmp = a.GetSizeTree();
	a.Transposition(0, 9);
	a.SiftDown(0);
	EXPECT_EQ(tmp, a.GetSizeTree());
}

TEST(D_HEAP, heapify_does_not_change_sizeTree)
{
	D_HEAP a(2, 10);
	for(int i = 0; i < 10; i++)
		a.Insert(i);
	int tmp = a.GetSizeTree();
	a.Transposition(0, 9);
	a.Hilling();
	EXPECT_EQ(tmp, a.GetSizeTree());
}