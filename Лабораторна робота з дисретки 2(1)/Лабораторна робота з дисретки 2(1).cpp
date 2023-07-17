// Лабораторна робота з дисретки 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include <stdlib.h>
#include<cmath>

using namespace std;
int main() {

	setlocale(LC_ALL, "Rus");
	char Pok_M;
	const int one = 1, zero = 0;
	int Kil_pair, P_i, P_j, k = 0, Kil_on_Ref = 0, Kil_on_Sim = 0, Kil_on_A_Sim = 0;
	int Kil_Ant_Sim = 0, Kil_on_Tranz = 0, pok_Antsum = 0, pok_Asum = 0, pok_Ref_Three = 0, pok_Tranz_Three = 0, P = 0;
	cout << "Введiть кiлькiсть пар множини - "; cin >> Kil_pair;
	int i_mas[15], j_mas[15], bool_mas[4][4], ex_bool_mas[4][4], bool_mas_f[4][4], bool_mas_f1[4][4];

	for (int i = 0; i < Kil_pair; i++)
	{
		cin >> P_i; cin >> P_j;
		i_mas[i] = P_i;
		j_mas[i] = P_j;
	}
	cout << "A: " << "{";
	for (int i = 0; i < Kil_pair; i++)
	{
		cout << "(" << i_mas[i] << ";" << j_mas[i] << ")";
	}
	cout << "}";

	cout << endl << "\tMain" << endl;
	cout << "1 - Розробити алгоритм та програму побудови матрицi заданого вiдношення  " << endl;
	cout << "2 - Визначити, якi  властивостi має дане вiдношення." << endl;
	cout << "3 - Визначити чи є дане відношення вiдношенням еквівалентностi, часткового та строгого поряду." << endl;
	cout << "4 - Побудувати матрицю симетричного та рефлексивного замикання." << endl;
	do {
		cout << "---------------------------------------------------------------" << endl;
		cin >> Pok_M;
		switch (Pok_M)
		{
		case '1':
		{

			for (int i = 0; i < Kil_pair; i++)
			{
				int n1 = i_mas[i] - 1, n2 = j_mas[i] - 1;

				bool_mas[n1][n2] = one;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (bool_mas[i][j] != 1) bool_mas[i][j] = zero;

				}
			}
			for (int i = 0; i < 4; i++)
			{
				cout << "|";
				for (int j = 0; j < 4; j++)
				{
					cout << " " << bool_mas[i][j];
					ex_bool_mas[i][j] = bool_mas[i][j];
					bool_mas_f[i][j] = bool_mas[i][j];
					bool_mas_f1[i][j] = bool_mas[i][j];
				}
				cout << "|" << endl;
			}
			P++;
			break;
		}
		case '2':
		{
			for (int i = 0; i < 4; i++)
			{
				if (bool_mas[i][i] == zero) Kil_on_Ref++;
				for (int j = 0; j < 4; j++)
				{
					if (bool_mas[i][j] == bool_mas[j][i]) Kil_on_Sim++;
					if (i != j && bool_mas[i][j] == one && bool_mas[i][j] == bool_mas[j][i]) Kil_Ant_Sim++;
					if (i != j && bool_mas[i][j] == one && bool_mas[i][j] == bool_mas[j][i]) Kil_on_A_Sim++;
				}
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (bool_mas[i][j] == ex_bool_mas[j][i])
					{
						Kil_on_Tranz++;
					}
				}
			}
			if (Kil_on_Ref == 0) { cout << "Вiдношення Рефлексивне" << endl; pok_Ref_Three++; }
			if (Kil_on_Ref == 4) { cout << "Вiдношення Iррефлексивне" << endl; }
			if (Kil_on_Ref > 1 && Kil_on_Ref < 4) { cout << "Вiдношення НЕ рефлексивне" << endl; }
			if (Kil_on_Sim == 16) { cout << "Вiдношення симетричне" << endl; }
			if (Kil_Ant_Sim == 0 && Kil_on_Ref != 4) { cout << "Вiдношення Антисиметричне" << endl;  pok_Antsum++; }
			if (Kil_on_A_Sim == 0 && Kil_on_Ref == 4) {
				cout << "Вiдношення АААсиметричне" << endl; pok_Asum++;
			}
			if (Kil_on_Sim != 0 && Kil_on_Sim != 16 && pok_Antsum == 0 && pok_Asum == 0) { cout << "Вiдношення НЕ симетричне" << endl; }
			if (Kil_on_Tranz == 16) { cout << "Вiдношення Транзетивне" << endl; pok_Tranz_Three++; }
			else cout << "Вiдношення НЕ транзетивне" << endl;
			P++;
			break;
		}
		case '3':
		{

			if (pok_Ref_Three != 0 && Kil_on_Sim == 16 && pok_Tranz_Three != 0) cout << "Вiдношення еквiвалентностi" << endl;
			else cout << "Не є Вiдношенням еквiвалентностi" << endl;
			if (Kil_on_Ref == 0 && pok_Antsum != 0 && pok_Tranz_Three != 0) cout << "Вiдношення часткового порядку" << endl;
			else cout << "Не є Вiдношенням часткового порядку" << endl;
			if (Kil_on_Ref == 4 && pok_Asum != 0 && pok_Tranz_Three != 0) cout << "Вiдношення строгого порядку" << endl;
			// chast рефлексивність + антисеметрія + транзитивність
			//	антирефлексивність + асиметрія + транзитивне
			else cout << "Не є Вiдношенням строго порядку" << endl;
			P++;
			break;
		}
		case '4':
		{
			for (int i = 0; i < 4; i++)
			{
				if (bool_mas_f1[i][i] == zero) bool_mas_f1[i][i] = one;
				for (int j = 0; j < 4; j++)
				{
					if (bool_mas_f[i][j] == one && bool_mas_f[j][i] == zero) bool_mas_f[j][i] = one;
					if (bool_mas_f[i][j] == zero && bool_mas_f[j][i] == one) bool_mas_f[i][j] = one;
				}
			}
			if (Kil_on_Sim == 16) cout << "Відношення вже ітак симетричне" << endl;
			else {
				for (int i = 0; i < 4; i++)
				{
					cout << "|";
					for (int j = 0; j < 4; j++)
					{
						cout << " " << bool_mas_f[i][j];
					}
					cout << "|" << endl;
				}
			}
			cout << "---------------------------------------------------------------" << endl;
			if (Kil_on_Ref == 0) cout << "Відношення вже ітак рефлексивне" << endl;
			else {
				cout << endl;
				for (int i = 0; i < 4; i++)
				{
					cout << "|";
					for (int j = 0; j < 4; j++)
					{
						cout << " " << bool_mas_f1[i][j];
					}
					cout << "|" << endl;
				}
			}
			P++;
			break;
		}
		default:
			cout << "Не вiрне значення" << endl;
			break;
		}
	} while (P != 4);
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
