#include <clocale>
#include <iostream>

using namespace std;

#include "algorithm.hpp"

typedef int typ;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "������� ���-�� ������" << endl;
	int n;
	cin >> n;

	cout << "������� ���-�� �����" << endl;
	int m;
	cin >> m;
	Graph<typ> *graph = new Graph<typ> (n,m);
		typ *P = new typ(n); //���������� ����
		for (int i = 0; i <= n; i++)
			P[i] = 0;
	cout << "������������� �����:" << endl;
	cout << "������� ����������� � ������������ �������� ���� �����" << endl;
	typ min, max;
	cin >> min;
	cin >> max;
	graph -> createGraph(min, max);
	system ("cls");
	
	cout << "���������� ����: " << endl<<endl;
	graph -> print();

	cout << "������� ��������� �������" << endl;
	int a;
	cin >> a; 

	cout << endl;	
	cout << "����������� �������� ��������..." << endl << endl;
	typ *dist = Algoritm<typ>::deykstra(a,P, graph);
	
	for (int i = 0; i < n; i++)
		cout << i << ' ';
	cout << "- �������" <<  endl << endl;
	for (int i = 0; i < n; i++)
		if (dist[i] == MAX_HTYPE)
			cout << 0 << ' ';
		else
			cout << dist[i] << ' ' ;
	cout << "- ���������� ����" <<  endl << endl;
	for (int i = 0; i < n; i++)
			cout << P[i] << ' ';
	cout << "- �������������� ������� " <<  endl << endl;

}	