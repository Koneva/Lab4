#include "d-heap.hpp"

D_HEAP::D_HEAP(int size_ch, int size_mk)
{
	if(size_mk <= 0)
		throw exception("invalid size of mass");
	if(size_ch < 0)
		throw exception("invalid namber of child");
	size_mass = size_mk;
	size_child = size_ch;
	size_tree = 0;
	keys = new ValType[size_mass];
	for(int i = 0; i < size_mass; i++)
		keys[i] = 99;
}
 
D_HEAP::D_HEAP(D_HEAP &heap)
{
	size_child = heap.size_child;
	size_mass = heap.size_mass;
	size_tree = heap.size_tree;
	keys = new ValType[size_mass];
		for (int i = 0; i < size_mass; i++)
			keys[i] = heap.keys[i];
}

D_HEAP::~D_HEAP()
{
	delete []keys;
}

void D_HEAP::Insert(ValType elem)
{
	D_HEAP heap(size_mass++, size_child);
	heap = *this;
	heap.keys[heap.size_mass - 1] = elem;
	heap.SiftUp(size_mass - 1);
	*this = heap;
}

void D_HEAP::SiftUp(int idx_elem)
{
	if((idx_elem > size_mass) || (idx_elem < 0)) 
		throw exception ("invalid idx of elem");

	if (size_mass == 0) return;
	int idx_parent = (idx_elem - 1)/size_child;
	while((!idx_parent) && (keys[idx_elem] < keys[idx_parent]))
	{
		Transposition(idx_elem, idx_parent);
		idx_elem = idx_parent;
		idx_parent = (idx_elem - 1)/size_child;
	}
}

void D_HEAP::Transposition(int idx_elem1, int idx_elem2)
{
	ValType tmp = keys[idx_elem1];
	keys[idx_elem1] = keys[idx_elem2];
	keys[idx_elem2] = tmp;
}
	
D_HEAP D_HEAP::operator=(const D_HEAP &heap) 
{
	if (this != &heap)
	{
		delete []keys;
		size_mass = heap.size_mass;
		size_child = heap.size_child;
		keys = new ValType[size_mass];
		for (int i = 0; i < size_mass; i++)
			keys[i] = heap.keys[i];
	}
	return *this;
}

void D_HEAP::SiftDown(int idx_elem)
{
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
	int idx_child = idx_parent * size_child + 1;
	int idx_min = idx_child;
	
	int i = 1;
	while (i < size_child)
	{
		if (keys[idx_min] > keys[idx_child + i])
			idx_min = idx_child + i;
		i++;
	}
	return idx_min;
}