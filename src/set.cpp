#include "set.hpp"

SET::SET(int maxsize)
{
	elem_mas = new TElem[maxsize]; 
	num_elem = 0;
	num_elem_mass = maxsize;
}

SET::SET(const SET &set)
{
	num_elem = set.num_elem;
	num_elem_mass = set.num_elem_mass;
	for(int i = 0; i < num_elem - 1; i++)
		elem_mas[i] = set.elem_mas[i];
}

void SET::CreateSetOne(TElem elem)
{
	elem_mas[elem] = elem;
	num_elem++; 
}
void SET::Combine(SET set1, SET set2)
{
	int root_child = set2.GetRoot();
	if(set1.num_elem_mass > set2.num_elem_mass)
	{
		SET set(set1);
		for(int i = 0; i < set2.num_elem_mass; i++)
		{
			if(set2.elem_mas[i] != -1)
				set.elem_mas[i] = set2.elem_mas[i];
			if(set.elem_mas[i] == root_child)
				set.elem_mas[i] = set1.GetRoot();
		}
	}
	else
	{
		SET set(set2);
		for(int i = 0; i < set1.num_elem_mass; i++)
			if(set1.elem_mas[i] != -1)
			{
				set.elem_mas[i] = set1.elem_mas[i];
				if(set.elem_mas[i] == i)
					set.elem_mas[root_child] = i;
			}
	}
	/*
	if(f == 1)
	{
		for(int i = 0; i < set.num_elem_mass; i++)
			set.elem_mas[i] = set1.elem_mas[i];
		
	}
	else
	{
		for(int i = 0; i < set.num_elem_mass; i++)
		{
			set.elem_mas[i] = set2.elem_mas[i];
			if(set.elem_mas[i] == root_child)
				set.elem_mas[i] = set1.GetRoot();
		}
	}*/
}

int SET::GetRoot()
{
	for(int i = 0; i < num_elem_mass; i++)
		if(elem_mas[i] = i) return i;
}