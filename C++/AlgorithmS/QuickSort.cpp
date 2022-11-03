// БЫСТРАЯ СОРТИРОВКА
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void QuickSort(int* arr, int size) {
	int i = 0;
	int j = size - 1;

	int mid = arr[size / 2];

	do {
		while (arr[i] > mid) i++; // поменять местами знаки больше/меньше 
		while (arr[j] < mid) j--; // в 15 и 16 строчке для сортировки по возрастанию
		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) QuickSort(arr, j + 1);
	if (i < size) QuickSort(&arr[i], size - i);
}

int main() {
	srand(time(NULL));
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n----------------------------------\n";
	QuickSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	delete[] arr;
	return 0;
}