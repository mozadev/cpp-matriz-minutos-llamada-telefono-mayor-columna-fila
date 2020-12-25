#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>


using namespace std;
using namespace System;


void generavalores(int *n, float **  tabla)
{
	Random f;
	for (int i = 0; i < *n; i++)
	{
		tabla[i][0] = i + 1;
		tabla[i][1] = f.Next(1, 4);//oficina
		tabla[i][2] = f.Next(1, 31);//minutos
		tabla[i][3] = f.Next(1, 4);//tipo
		if (tabla[i][3] == 1)
			tabla[i][4] = tabla[i][2] * 0.30;
		if (tabla[i][3] == 2)
			tabla[i][4] = tabla[i][2] * 0.80;
		if (tabla[i][3] == 3)
			tabla[i][4] = tabla[i][2] * 1.50;
	}
}

void salidadatos(int *n, float **  tabla)
{
	cout << "#fila" << "\t" << "ofic" << "\t" << "min" << "\t" << "tipo" << "\t" << "pre" << "\t" << endl;
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << tabla[i][j] << "\t";
		cout << endl;
	}
}

void mayorllamadas(int *n, float **  tabla)

{

	float m1 = 0, m2 = 0, m3 = 0;
	for (int i = 0; i < *n; i++)
	{

		if (tabla[i][1] == 1 && tabla[i][2]>m1)
			m1 = tabla[i][2];
		if (tabla[i][1] == 2 && tabla[i][2]>m2)
			m2 = tabla[i][2];
		if (tabla[i][1] == 3 && tabla[i][2]>m3)
			m3 = tabla[i][2];
	}
	cout << "el mayor de la oficina 1 es : " << m1 << endl;
	cout << "el mayor de la oficina 2 es : " << m2 << endl;
	cout << "el mayor de la oficina 3 es : " << m3 << endl;

}
int main()
{
	int n=10;
	float **tabla;
	tabla = new float*[n];
	for (int i = 0; i < n; i++)
		tabla[i] = new float[5];
	generavalores(&n, tabla);
	salidadatos(&n, tabla);
	mayorllamadas(&n, tabla);
	for (int i = 0; i < n; i++)
		delete[] tabla[i];
	delete[] tabla;
	_getch();
}