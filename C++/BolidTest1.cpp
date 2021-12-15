#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cmath>
#define SIZEN 999
/*
тест 1:
	файл task1.txt
	Ввод: дуб <-> ничего
	Вывод: 57
тест 2:
	файл task1.txt
	Ввод: желая <-> ничего
	Вывод: 1
тест 3:
	файл task2.txt
	Вывод: С файлом проблемы
тест 4:
	файл task4.txt
	Вывод: С файлом проблемы
тест 5:
	файл task3.txt
	Ввод: Привет <-> Привет
	Вывод: Вы ввели два одинаковых слова...
тест 6:
	файл task3.txt
	Ввод: Привет <-> ничего
	Вывод: Какого-то слова нет
*/

using namespace std;

class Distance {
	string word1, word2;
public:
	Distance(string word1 = "", string word2 = "") {
		this->word1 = word1;
		this->word2 = word2;
	}
	void output() {
		cout << "word 1: " << word1 << ", word 2: " << word2 << endl;
	}
	int minDistance(string str[], int len) {
		int len1 = 0, len2 = 0;
		int array1[SIZEN], array2[SIZEN];				// массивы будут хранить расположение найденных слов в тексте
		int i, j, minDistance = INT_MAX;
		i = 0;
		while (i < len) {								// ищем все наличия слов в тексте
			if (str[i] == word1) {						// и записываем их порядковый номер
				array1[len1] = i;			
				len1 = len1 + 1;
			}
			if (str[i] == word2) {
				array2[len2] = i;
				len2 = len2 + 1;
			}
			i = i + 1;
		}
		if (len1 != 0 && len2 != 0) {
			for (i = 0; i < len1; i++) {
				for (j = 0; j < len2; j++) {
					if (abs(array1[i] - array2[j]) < minDistance) minDistance = abs(array1[i] - array2[j]);	// слова могут быть как слева, так и справа друг от друга
				}																							// ищем абсолютную разницу их порядковых номеров
			}
			return minDistance;	
		}
		else {								// если длина какого либо из массивов равна нулю, значит слово не нашли и искать расстояние не надо
			return 0;
		}

	}
};

bool my_empty(ifstream& pFile) {							// peek возвращает символ, который должен быть прочитан следующей функцией чтения потока
	return pFile.peek() == ifstream::traits_type::eof();	// проверка на код конца файла
}															//является файл пустым или нет


string changeWord(string word) {
	int i;
	i = 0;
	string s = "";
	if (word.length() > 0) {							
		while (word[i] != '\0') {
			if (isalnum(word[i]) || (word[i] >= 'а' && word[i] <= 'я' || word[i] >= 'А' && word[i] <= 'Я')) { // обязательно, чтобы символ был буквой или цифрой
				s += word[i];
			}
			i = i + 1;
		}
		return s;
	}
	else return "";
}

int main() {
	// руссификация консоли (2 способа)
	// 1 способ
	SetConsoleCP(1251);								// устанавливает нужную кодовую таблицу, на поток ввода
	SetConsoleOutputCP(1251);						// устанавливает нужную кодовую таблицу, на поток вывода
	// 2 способ
	setlocale(LC_ALL, "russian");					// настраивает локальные параметры в программе

	string str, word1, word2;
	string myStrArr[SIZEN];
	int len = 0;
	ifstream fin;
	fin.open("task1.txt");							// Открываем файл
	if (fin.is_open() && !my_empty(fin)) {			// проверка открыт ли файл и не пустой ли он
		printf("Файл открыт\nТекст из файла:\n");
		while (fin >> str) {
			str = changeWord(str);
			if (str.length() > 0) {					// записываем не пустую строку в массив строк
				myStrArr[len] = str;
				len = len + 1;
				cout << str << "\n";
			}
			
		}
		if (len >= 1) {
			printf("Введите 2 искомых слова\nПервое слово: ");
			cin >> word1;
			printf("Второе слово: ");
			cin >> word2;
			Distance distance(word1, word2);
			int minDistance;
			// distance.output();					// выводит два введённых слова
			if (word1 == word2) {					// если слова одинаковы, то расстояние между ними будет минимальное
				printf("Вы ввели два одинаковых слова...\n");
			}
			else{
				minDistance = distance.minDistance(myStrArr, len);
				if (minDistance != 0)				
					printf("Минимальное расстояние между этими словами = %d слов\n", minDistance - 1);
				else 
					printf("Какого-то слова нет\n");
			}
		}
		else {
			printf("Пусто\n");
		}
		fin.close();
	}
	else {
		printf("С файлом проблемы\n");
	}
	
	system("pause");
}