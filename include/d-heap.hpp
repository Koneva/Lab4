#include <iostream>
#include <cstdlib>

using namespace std;
typedef int ValType;

class D_HEAP{
private:
		ValType* keys;
		int size_child;
		int size_tree;
		int size_mass;
public:

		D_HEAP(int,int);
		D_HEAP(D_HEAP&);
		~D_HEAP();

		int operator==(const D_HEAP&)const;
		int operator!=(const D_HEAP&)const;
		//ValType operator[](int idx)const {return keys[idx];};
		D_HEAP operator=(const D_HEAP&);
		
		ValType GetKey(int idx) {	if(idx < 0) throw exception ("invalid idx");
									if(idx >= size_tree) throw exception ("invalid idx");
									return keys[idx];};
		int GetSizeChild() {return size_child;};
		int GetSizeMass() {return size_mass;};
		int GetSizeTree() {return size_tree;};

		void Transposition(int,int);
		void Insert(ValType);
		void SiftUp(int);
		void SiftDown(int);
		int MinChild(int);
		void Hilling();

		void RemoveIdx(int);
		void RemoveIdxMin();   //удалить минимального насленика
};