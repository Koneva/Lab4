#include "d-heap.hpp"

D_HEAP::D_HEAP(int size_ch, int size_mk)
{
	if(size_mk <= 0)
		throw exception("invalid size of mass");
	if(size_ch <= 0)
		throw exception("invalid namber of child");
	size_mass = size_mk;
	size_child = size_ch;
	size_tree = 0;
	keys = new ValType[size_mass];
	for(int i = 0; i < size_mass; i++)
		keys[i] = 0;
}
 
D_HEAP::D_HEAP(D_HEAP &heap)
{
	size_child = heap.size_child;
	size_mass = heap.size_mass;
	size_tree = heap.size_tree;
	keys = new ValType[size_mass];
		for (int i = 0; i < size_tree; i++)
			keys[i] = heap.keys[i];
}

D_HEAP::~D_HEAP()
{
	delete []keys;
}

void D_HEAP::Insert(ValType elem)
{
	if(size_tree == size_mass)
		throw exception ("heap is full");
	size_tree++;
	keys[size_tree - 1] = elem;
	SiftUp(size_tree - 1);

}

void D_HEAP::SiftUp(int idx_elem)
{
	if((idx_elem >= size_tree) || (idx_elem < 0)) 
		throw exception ("invalid idx of elem");

	if (idx_elem == 0) return;
	int idx_parent = (idx_elem - 1)/size_child;
	while((idx_parent != -1) && (keys[idx_elem] < keys[idx_parent]))
	{
		Transposition(idx_elem, idx_parent);
		idx_elem = idx_parent;
		idx_parent = (idx_elem)?(idx_elem - 1)/size_child : -1;
	}
}

void D_HEAP::Transposition(int idx_elem1, int idx_elem2)
{
	if(idx_elem1 < 0 || idx_elem2 < 0 || idx_elem1 >= size_tree || idx_elem2 >= size_tree)
		throw exception ("invalid idx");
	ValType tmp = keys[idx_elem1];
	keys[idx_elem1] = keys[idx_elem2];
	keys[idx_elem2] = tmp;
}
	
D_HEAP D_HEAP::operator=(const D_HEAP &heap) 
{
	if (this != &heap)
	{
		delete []keys;
		size_tree = heap.size_tree;
		size_mass = heap.size_mass;
		size_child = heap.size_child;
		keys = new ValType[size_mass];
		for (int i = 0; i < size_tree; i++)
			keys[i] = heap.keys[i];
	}
	return *this;
}

void D_HEAP::SiftDown(int idx_elem)
{
	if((idx_elem >= size_tree) || (idx_elem < 0)) 
		throw exception ("invalid idx of elem");

	int min_child = MinChild(idx_elem);
	while ((min_child != -1) && (keys[min_child] < keys[idx_elem]))
	{
		Transposition(min_child, idx_elem);
		idx_elem = min_child;
		min_child = MinChild(idx_elem);
	}
}

int D_HEAP::MinChild(int idx_parent)
{
	if((idx_parent >= size_tree) || (idx_parent < 0)) 
		throw exception ("invalid idx of elem");
	if (idx_parent * size_child + 1 > size_tree - 1) return -1;
	int idx_min = idx_parent * size_child + 1;
	int idx_max =	(idx_parent * (size_child) + size_child <= size_tree - 1) ?
					idx_parent * (size_child) + size_child : size_tree - 1;
	
	for(int i = idx_min; i <= idx_max; i++)
	{
		if (keys[idx_min] > keys[i])
			idx_min = i;
	}
	return idx_min;
}

void D_HEAP::RemoveIdx(int idx_elem)
{
	if((idx_elem >= size_tree) || (idx_elem < 0)) 
		throw exception ("invalid idx of elem");

	keys[idx_elem] = keys[size_tree--];
	SiftDown(idx_elem);
}

void D_HEAP::RemoveIdxMin()
{
	keys[0] = keys[size_tree--];
	SiftDown(0);
}

void D_HEAP::Hilling()
{
	for (int i = size_tree - 1; i >= 0; i--)
		SiftDown(i); 
}

int D_HEAP::operator==(const D_HEAP& heap)const
{
	if(size_mass != heap.size_mass || size_child != heap.size_child || size_tree != heap.size_tree)
		return 0;
	for (int i = 0; i < size_tree; i++)
			if (keys[i] != heap.keys[i])
				return 0;
	return 1;
}

int D_HEAP::operator!=(const D_HEAP& heap)const
{
	return !(*this == heap);
}