#include <conio.h>
#include <iostream>

using namespace std;

#include "algorithm.hpp"

typedef float typ;

void main ()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	FILE *myfile;
	cout << "Введите тип приоритетной очереди: " << endl;
	cout << "1) d-куча" << endl;
	cout << "2) Бинарное деревo" << endl;
	cout << "3) таблица" << endl;
	cin >> k;
	system ("cls");
	int n;
	cout << "Введите кол-во вершин" << endl;		
	cin >> n;		
	cout << "Введите кол-во ребер" << endl;
	int m;
	cin >> m;

	Graph<typ> *graph = new Graph<typ> (n,m);
		
	int l;
	cout << "1) Генерирование графа" << endl;
	cout << "2) Введение графа вручную" << endl;
	cout << "3) Читение графа из файла" << endl;
	cin >> l;
	switch (l)
		{
	case 1:
		{
		cout << "Введите минимальное и максимальное значения веса" << endl;
		typ min, max;
		cin >> min;
		cin >> max;
		graph -> createGraph(min, max);
		break;
		}
	case 2:
		{
			for (int i = 0; i < m; i++)
		{
			cout << "Введите начальную вершину ребра, конечную вершину ребра и его вес" << endl;
			int a,b;
			typ c;
			cin >> a;
			cin >> b;
			cin >> c;
			graph -> addEdge(a,b,c);
		}
		break;	
		}
	case 3:
		{
			myfile = fopen ("C:\\file.txt", "r");
			int a = 0, b = 0 ,i = 0, tmp1 = 0, tmp2 = 0;
			typ c = 0;
			while (i < m)
			{
				fscanf (myfile, "%d%d%f\n", &a, &b, &c);
				if ((tmp1 == a) && (tmp2 == b))
					break;
				tmp1 = a;
				tmp2 = b;
				graph -> addEdge (a,b,c);
				i++;
			}
			fclose(myfile);
		}
		break;
	}
	
	system ("cls");

	cout << "Полученный граф: " << endl << endl;
	graph -> print();
		
	cout << "Применяется алгоритм Крускала..." << endl;
	Graph<typ> *res = new Graph<typ> (n,m);
	graph -> sort();
	
	PQueue<typ>* queue;
	int tmp2 = 0;
	if (k == 1)
		tmp2 = n;
	if (k == 3)
		tmp2 = m;
	make_queue<typ>::makeQueue(queue, k, tmp2);

	res = Algoritm<typ>::kruskal(graph, queue);
	cout << endl << endl;
	res -> print();
}

