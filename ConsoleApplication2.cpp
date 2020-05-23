#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <cctype>


using namespace std;

int palindrom(char* a);
void menu();
void kount(char* a);
void slov_v_stroke(int& n, int& c);
void Chisloli(char* t);
void sort(char** a, int size);
void line(int a[], int n);

int main()
{
	setlocale(LC_ALL, "Russian");

	int choose=10;
	
		menu();
		cout << "Задание № ";
		cin >> choose;
		if (choose== 1) {
			cout << "Считает количество символов в строке." << endl;
			cin.clear();
			cin.ignore();
			int i, n = 0;
			char* s = new char[100];
			cout << "Vvedite stroky- ";
			cin.getline(s, 255);
			for (i = 0; s[i] != '\0'; i++) n++;
			cout << "Количество символов в строке: " << n << endl;
			cout << endl;
		}
		if (choose == 2) {
			cout << "Составляет предложения из заранее подготовленных слов." << endl;
			cout << "Порядок слов: article, существительное, глагол, предлог, article и существительное. " << endl;
			cin.clear();
			cin.ignore();
			int arts, nos, ves, pres;
			char* art[100];
			{
				ifstream fin("z2.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						art[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << art[i] << " "
				arts = n;
				cout << endl;
			}
			char* no[100];// = { "boy", "girl", "cat", "city", "car" };
			{
				ifstream fin("z2.2.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						no[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << no[i] << " ";
				nos = n;
			}
			char* ve[100];// = { "drove", "worked", "ran", "walked", "write" };
			{
				ifstream fin("z2.3.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						ve[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << ve[i] << " ";
				ves = n;
			}
			char* pre[100];// = { "to", "from", "over", "under", "in" };
			//int pres = sizeof(pre) / sizeof(pre[0]);
			{
				ifstream fin("z2.4.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						pre[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << pre[i] << " ";
				pres = n;
			}
			int N;
			cout << "Количество предложений = ";
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				const int max_N = 256;
				char offer[max_N];
				sprintf(offer, "%s %s %s %s %s %s.", art[rand() % arts], no[rand() % nos], ve[rand() % ves], pre[rand() % pres], art[rand() % arts], no[rand() % nos]);
				offer[0] = toupper(offer[0]);
				cout << offer << endl;
			}
			cout << endl;
		}
		if(choose==3) {
			cout << "Определяет является ли строка палиндромом." << endl;
			cin.clear();
			cin.ignore();
			char* s = new char[100];
			cout << "При использовании Русского языка, программа будет выдовать не верные результаты," << endl;
			cout << "поэтому рекомендуется использовать латинский алфовит." << endl;
			cout << "Введите строку - ";
			cin.getline(s, 255);
			if (palindrom(s)) cout << "Строка является Палиндромом!" << endl;
			else cout << "Строка не является Палиндромом!" << endl;
		}
		if (choose == 4) {
			cout << "Считает количество слов , а также количество предложений." << endl;
			cin.clear();
			cin.ignore();
			char* s = new char[100];
			cout << "Vvedite stroky- ";
			cin.getline(s, 255);
			kount(s);
		}
		if (choose == 5) {
			cout << "Конвертирует строку в целое число" << endl;
			cin.clear();
			cin.ignore();
			int i, n = 0;
			char* s = new char[100];
			cout << "Vvedite stroky- ";
			cin.getline(s, 255);
			Chisloli(s);
		}
		if (choose == 6) {
			int n = 0, c = 0;
			slov_v_stroke(n, c);
			cout <<c<< " Количество слов в строке: " << n << endl;
			cout << endl;
		}
		if (choose == 7) {
			int n = 0, c = 0, k = 0;
			int size = 0;
			slov_v_stroke(n, c);
			char* arr[20];
			char* s = new char[100];
			ifstream fin("text.txt");
			if (!fin) {
				cout << "ошибка открытия файла" << endl;
				return 1;
			}
			while (!fin.eof())
			{
				fin.getline(s, 100, '\c');
				k++;
				char seps[] = " ,.;!?"; // Строка разделителей
				char* token; // указатель на новой слово
				token = strtok(s, seps);// находим первое слово
				while (token != NULL) {
					if (k == c) { arr[size++] = token; /*tolower(arr[size][0]);*/ }
					token = strtok(NULL, seps); ;// выделяем следующее слово
				}
			}
			sort(arr, size); // Сортируем
			/*for (int i = 0; i < size; i++)
			{
			for (int j = 0; j < strlen(arr[i]); j++)
			{
			cout << arr[i][j];
			}
			cout << endl;
			}*/
		}
}
void menu()
{
	cout << "1 - Задание 1" << endl;
	cout << "2 - Задание 2" << endl;
	cout << "3 - Задание 3" << endl;
	cout << "4 - Задание 4" << endl;
	cout << "5 - 7 вариант- 1 задание" << endl;
	cout << "6 - 7 вариант- 2 задание" << endl;
	cout << "7 - 7 вариант- 3 задание" << endl;
	cout << "0 - EXIT" << endl;
}

/*
Функция на вход получает символьный массив а.
Функция предназначена для проверки, является ли введенная строка палиндромом или нет.
Функция возвращает 1 или 0.
1 - строка является палиндромом.
0 - строа не является палиндромом.
*/

int palindrom(char* a)

{
	char* b = new char[100];
	int n = strlen(a);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (isalpha(a[i])) {
			b[k++] = tolower(a[i]);
		}
	}
	b[k] = '\0';
	bool t = 1;
	for (int i = 0, j = strlen(b) - 1; i < j; i++, j--)
	{
		if ((b[i]) != b[j])
		{
			t = 0;
		}
	}
	return t;
}

/*
Функция на вход получункция на вход полу
для подсчёта количество слов и предложений в строке.
*/

void kount(char* a)

{
	int i;
	char* b = new char[100];
		strcpy(b, a);
		char seps[] = " ,.;!?";
		char seps1[] = ".!?";
		char* token;
		token = strtok(b, seps);
		int n = 1,m=0;
		while (token != NULL) {
			token = strtok(NULL, seps); n++;
		}
		n--;
		cout << "Количество слов: " << n << endl;
		for (i = 0; i < strlen(a); i++)
		{
			if (a[i] == '.' || a[i] == '!' || a[i] == '?') m++;
		}
	cout << "Количество предложений: " << m << endl;
}


/*
Функция на вход получает переменные n и c.
Переменная "n" считает количество слов в строке.
Переменная "c" считает количество строк в текстовом файле.
*/

void slov_v_stroke(int& n, int& c)
{
	char* s = new char[100];
	ifstream fin("text.txt");
	if (!fin) {
		cout << "ошибка открытия файла" << endl;
		exit;
	}
	while (!fin.eof())
	{
		fin.getline(s, 100, '\c');
		c++;
		char seps[] = " ,.;!?"; // Строка разделителей
		char* token; // указатель на новой слово
		token = strtok(s, seps); //находим первое слово
		n = 0; //n - количество слов
		while (token != NULL) {
			token = strtok(NULL, seps); n++;
			// выделяем следующее слово
		}
	}
}

/*
Функция на вход получает символьный массив t.
Функция предназначена для вроверки, является ли символ числом.
И если символ является числом, тогда записать его как целое число.
*/

void Chisloli(char* t)
{
	int n = 0, i;
	double f = 0;
	n = strlen(t);
	for (i = 0; i < n; i++)
	{
		if ((t[i] <= '9') && (t[i] >= '0')) f = f * 10 + (t[i] - 48); // Вычитание по таблицу ASCII кода.
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((t[j] <= '9') && (t[j] >= '0'))
				{
					double d = (t[j] - 48);
					f = f + d; 
				}
			}
			if (t[0] == '-') f = f * (-1);
			if (f != 0) printf("%.3f \n", f);
			return;
		}
	}
	if (t[0] == '-') f = f * (-1);

	if (f != 0) cout << f << endl;
}

void sort(char** a, int size)

{
	char seps[] = " ";
	int* b = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (isupper(a[i][0]))
		{
			a[i][0] = tolower(a[i][0]);
		}
		int t = a[i][0];
		b[i] = t;
		// cout << (char)t << endl;
		//cout << t << " " << a[i] << endl;
	}

	line(b, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if ((char)b[i] == a[j][0]) { cout << a[j] << endl; a[j] = seps; break; }
	}
}

void line(int a[], int n)

{
	int i, j, min, mink = 0, t;
	for (i = 0; i < n - 1; i++)
	{
		min = a[i];
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				mink = j;
			}
		}
		if (a[i] > min)
		{
			t = a[i];
			a[i] = a[mink];
			a[mink] = t;
		}
	}
}