#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;
typedef int TElem;

class SET
{
private:
	TElem *elem_mas;
	int num_elem;
	int num_elem_mass;
public:

	TElem GetElem(int idx) {return elem_mas[idx];};

	SET(int maxsize);
	SET(const SET&);
	~SET(void) {delete[]elem_mas;}

	int GetRoot();


	void CreateSetOne(TElem);
	void Combine(SET, SET); 
	void remove(SET); 
};