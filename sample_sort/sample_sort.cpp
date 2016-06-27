#include "priority_queue.hpp" 
#include <ctime> 

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите арность кучи" << endl;
	int a;
	cin >> a;
	DHeap<float> *heap = new DHeap <float> (a,0);
	cout << "Введите кол-во элементов" << endl;
	int b;
	cin >> b;
	int c;
	srand(time(NULL));
	for (int i = 0; i < b; i++)
	{
		c = 1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(10 - 1)));
		heap->push(c);
	}
	system("cls");
	cout << "Полученная куча: " << endl;
	heap -> print();

	cout << "Применяется пирамидальная сортировка... " << endl;
	cout << "Результат: " << endl;
	heap -> okych();
	heap -> Sort();
	heap -> print();

}
