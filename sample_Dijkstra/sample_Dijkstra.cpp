#include <clocale>
#include <iostream>

using namespace std;

#include "algorithm.hpp"

typedef int typ;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите кол-во вершин" << endl;
	int n;
	cin >> n;

	cout << "Введите кол-во ребер" << endl;
	int m;
	cin >> m;
	Graph<typ> *graph = new Graph<typ> (n,m);
		typ *P = new typ(n); //кратчайший путь
		for (int i = 0; i <= n; i++)
			P[i] = 0;
	cout << "Генерирование графа:" << endl;
	cout << "Введите минимальное и максимальное значения веса графа" << endl;
	typ min, max;
	cin >> min;
	cin >> max;
	graph -> createGraph(min, max);
	system ("cls");
	
	cout << "Полученный граф: " << endl<<endl;
	graph -> print();

	cout << "Введите нвчальную вершину" << endl;
	int a;
	cin >> a; 

	cout << endl;	
	cout << "Применяется алгоритм Дейкстры..." << endl << endl;
	typ *dist = Algoritm<typ>::deykstra(a,P, graph);
	
	for (int i = 0; i < n; i++)
		cout << i << ' ';
	cout << "- вершины" <<  endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ' ;
	cout << "- кратчайшие пути" <<  endl << endl;
	for (int i = 0; i < n; i++)
			cout << P[i] << ' ';
	cout << "- предшествующие вершины " <<  endl << endl;

}	