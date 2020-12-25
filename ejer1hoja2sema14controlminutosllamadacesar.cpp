#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
using namespace System;

int ingresapositivo()
{
	int n;
	do {
		cout << "ingresa filas/columnas: "; cin >> n;
	} while (n < 0 || n>50);
	return n;
}
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
	cout << "#fila" << "\t" << "oficina" << "\t" << "min" << "\t" << "tipo " << "\t" << "pre" << "\t" << endl;
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << tabla[i][j] << "\t";
		cout << endl;
	}
}
void mayorcantidadminutos(int *n, float **  tabla)

{
	float suma1 = 0, suma2 = 0, suma3 = 0;
	float m1 = 0, m2 = 0, m3 = 0;
	for (int i = 0; i < *n; i++)
	{

		if (tabla[i][1] == 1 && tabla[i][2] > m1)
			m1 = tabla[i][2];
		if (tabla[i][1] == 2 && tabla[i][2] > m2)
			m2 = tabla[i][2];
		if (tabla[i][1] == 3 && tabla[i][2] > m3)
			m3 = tabla[i][2];
	}
	cout << "el mayor de la oficina 1 es : " << m1 << endl;
	cout << "el mayor de la oficina 2 es : " << m2 << endl;
	cout << "el mayor de la oficina 3 es : " << m3 << endl;

	for (int i = 0; i < *n; i++)
	{

		if (tabla[i][1] == 1)

			suma1 = suma1 + tabla[i][2];

		if (tabla[i][1] == 2)
			suma2 = suma2 + tabla[i][2];
		if (tabla[i][1] == 3)
			suma3 = suma3 + tabla[i][2];
	}

	cout << "minutos totales de la oficina 1 es : " << suma1 << endl;
	cout << "minutos totales de la oficina 2 es : " << suma2 << endl;
	cout << "minutos totales de la oficina 3 es : " << suma3 << endl;

	if (suma1 > suma2  && suma1 > suma3)
		cout << "la oficina 1 tiene la mayor cantidad de minutos : " << suma1 << endl;
	if (suma2 > suma1 && suma2 > suma3)
		cout << "la oficina 2 tiene la mayor cantidad de minutos : " << suma2 << endl;
	if (suma3 > suma1 && suma3 > suma2)
		cout << "la oficina 3 tiene la mayor cantidad de minutos : " << suma3 << endl;

}
void montototalpagarxtipollamada(int *n, float **  tabla)
{
	float suma1 = 0, suma2 = 0, suma3 = 0;
	for (int i = 0; i < *n; i++)
	{
		if (tabla[i][3] == 1)
			suma1 = suma1 + tabla[i][4];
		if (tabla[i][3] == 2)
			suma2 = suma2 + tabla[i][4];
		if (tabla[i][3] == 3)
			suma3 = suma3 + tabla[i][4];
	}
	cout << "total pagar x tipo llamada local es: " << suma1 << endl;
	cout << "total pagar x tipo llamada celular es: " << suma2 << endl;
	cout << "total pagar x tipo llamada internacional es: " << suma3 << endl;
}
void tiempopromedioxtipollamadaoficinaventas(int *n, float **  tabla)
{
	float sumalocal = 0, sumacel = 0, sumainter = 0;
	int contador1 = 0, contador2 = 0, contador3 = 0;
	for (int i = 0; i < *n; i++)
	{
		if (tabla[i][1] == 3 && tabla[i][3] == 1)
		{
			sumalocal += tabla[i][2];
			contador1++;
		}
		if (tabla[i][1] == 3 && tabla[i][3] == 2)
		{
			sumacel += tabla[i][2];
			contador2++;
		}
		if (tabla[i][1] == 3 && tabla[i][3] == 3)
		{
			sumainter += tabla[i][2];
			contador3++;
		}
	}
	cout << "Tiempo promedio por tipo de llamada de la oficina de ventas " << endl;
	if (contador1 != 0)
		cout << "tipo de llamada local:  " << sumalocal / contador1 << endl;
	if (contador2 != 0)
		cout << "tipo de llamada celular:  " << sumacel / contador2 << endl;
	if (contador3 != 0)
		cout << "tipo de llamada internacional:  " << sumainter / contador3;
	
}






int main()
{
	int n = ingresapositivo();
	int m = ingresapositivo();
	float **tabla;
	tabla = new float*[n];
	for (int i = 0; i < n; i++)
		tabla[i] = new float[m];
	generavalores(&n, tabla);
	salidadatos(&n, tabla);
	mayorcantidadminutos(&n, tabla);
	montototalpagarxtipollamada(&n, tabla);
	tiempopromedioxtipollamadaoficinaventas(&n, tabla);
	for (int i = 0; i < n; i++)
		delete[] tabla[i];
	delete[] tabla;
	_getch();
}