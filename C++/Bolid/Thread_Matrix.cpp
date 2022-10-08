/*
input_a.txt:
3 5 4
1 0 2
8 3 7
3 5 4

input_b.txt:
8 5 3 3
0 3 2 4
-4 1 8 5

input_cub.txt:
3 4 6
5 9 0
1 2 7

output.txt:
3 5 4
1 0 2
8 3 7
3 5 4
Size = 3 x 4

8 5 3 3
0 3 2 4
-4 1 8 5
Size = 4 x 3

3 4 6
5 9 0
1 2 7
Size = 3 x 3

Determinant Matrix = 55
62 64 75
31 26 36
68 29 62
Size = 3 x 3

65 68 81
36 35 36
69 31 69
Size = 3 x 3

59 60 69
26 17 36
67 27 55
Size = 3 x 3
*/

/*
Работа с многопоточным программированием на примере класса матрицы
*/

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

class Matrix {
	vector <vector <int>> myMatrix;
	int determ = 0;
public:
	Matrix() {};
	Matrix(string file) {
		ifstream inPut(file);
		while (!inPut.eof()) {
			char ch = ' ';
			int k;
			vector <int> Vec;
			while (ch != '\n' && !inPut.eof()) {
				inPut >> k;
				inPut.get(ch);
				Vec.push_back(k);
			}
			myMatrix.push_back(Vec);
		}
		inPut.close();
	}

	Matrix operator+(Matrix const& a) {
		unique_lock<mutex> ul(mtx);
		cout << "\nBegin thread = " << this_thread::get_id() << endl;
		Matrix result(*this);
		if (a.myMatrix.size() != result.myMatrix.size()) {
			cout << "Matrix addition is impossible!";
			exit(1);
		}
		for (int i = 0; i < a.myMatrix.size(); i++) {
			if (a.myMatrix[i].size() != result.myMatrix[i].size()) {
				cout << "MATRIX addition is impossible!";
				exit(1);
			}
			for (int j = 0; j < a.myMatrix[i].size(); j++) {
				result.myMatrix[i][j] += a.myMatrix[i][j];
			}
		}
		cout << "\nEnd thread = " << this_thread::get_id() << endl;
		return result;
	};

	Matrix operator-(Matrix const& a) {
		unique_lock<mutex> ul(mtx);
		cout << "\nBegin thread = " << this_thread::get_id() << endl;
		Matrix result(*this);
		if (a.myMatrix.size() != result.myMatrix.size()) {
			cout << "Matrix difference is impossible!";
			exit(1);
		}
		for (int i = 0; i < a.myMatrix.size(); i++) {
			if (a.myMatrix[i].size() != result.myMatrix[i].size()) {
				cout << "MATRIX difference is impossible!";
				exit(1);
			}
			for (int j = 0; j < a.myMatrix[i].size(); j++) {
				result.myMatrix[i][j] -= a.myMatrix[i][j];
			}
		}
		cout << "\nEnd thread = " << this_thread::get_id() << endl;
		return result;
	};

	Matrix operator*(Matrix const& a) {
		unique_lock<mutex> ul(mtx);
		cout << "\nBegin thread = " << this_thread::get_id() << endl;
		Matrix b(*this);
		if (b.myMatrix[0].size() != a.myMatrix.size()) {
			cout << "Matrix multiplication is impossible!";
			exit(1);
		}
		Matrix result;
		for (int k = 0; k < b.myMatrix.size(); k++) {
			vector <int> vec;
			for (int i = 0; i < b.myMatrix.size(); i++) {
				int sum = 0;
				for (int j = 0; j < a.myMatrix.size(); j++) {
					sum += (b.myMatrix[k][j] * a.myMatrix[j][i]);
				}
				vec.push_back(sum);
			}
			result.myMatrix.push_back(vec);
		}
		cout << "\nEnd thread = " << this_thread::get_id() << endl;
		
		return result;

	}

	void determinant() {
		unique_lock <mutex> ul(mtx);
		cout << "\nBegin thread = " << this_thread::get_id() << endl;
		Matrix result;

		if (this->myMatrix.size() != this->myMatrix[0].size()) {
			cout << "Matrix determinant is impossible!";
			exit(1);
		}
		for (int k = 0; k < this->myMatrix.size(); k++) {
			vector <int> vec;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < this->myMatrix[k].size(); j++)
					vec.push_back(this->myMatrix[k][j]);

			result.myMatrix.push_back(vec);
		}

		determ = 0;
		for (int i = 0; i < this->myMatrix.size(); i++) {
			int temp = 1;
			for (int j = 0; j < this->myMatrix.size(); j++) {
				temp *= result.myMatrix[j][j + i];
			}
			determ += temp;
		}
		for (int i = 0; i < this->myMatrix.size(); i++) {
			int temp = 1;
			for (int j = this->myMatrix.size() - 1, k = 0; j >= 0, k < this->myMatrix.size(); j--, k++) {
				temp *= result.myMatrix[j][i + k];
			}
			determ -= temp;
		}
		
		cout << "\nEnd thread = " << this_thread::get_id() << endl;

	}

	int get_determ() {
		return determ;
	}

	void output() {
		for (int i = 0; i < myMatrix.size(); i++) {
			for (int j = 0; j < myMatrix[i].size(); j++)
				cout << myMatrix[i][j] << ' ';
			cout << endl;
		}
		cout << "Size = " << myMatrix[0].size() << " x " << myMatrix.size() << "\n\n";
	}

	void file_output() {
		fstream file;
		file.open("output.txt", ios::app);

		for (int i = 0; i < myMatrix.size(); i++) {
			for (int j = 0; j < myMatrix[i].size(); j++)
				file << myMatrix[i][j] << ' ';
			file << endl;
		}
		file << "Size = " << myMatrix[0].size() << " x " << myMatrix.size() << "\n\n";
		if (determ != 0)
			file << "Determinant Matrix = " << determ << endl;

		file.close();
	}
};

int main() {
	fstream file("output.txt", ios::out);
	file.close();
	Matrix a("input_a.txt");
	Matrix b("input_b.txt");

	cout << "Matrix A:\n";
	a.output();
	a.file_output();
	cout << "\nMatrix B:\n";
	b.output();
	b.file_output();

	Matrix e;
	thread t1([&]() { e = (b * a); });

	Matrix Cub("input_cub.txt");
	thread t2([&]() {Cub.determinant(); });

	Matrix c;
	thread t3([&]() {c = (e + Cub); });

	Matrix d;
	thread t4([&]() {d = (e - Cub); });

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << "\nMatrix Cub:\n";
	Cub.output();
	Cub.file_output();
	cout << "\nDeterminant Matrix Cub = " << Cub.get_determ() << endl;

	cout << "\nMatrix Umnoj:\n";
	e.output();
	e.file_output();

	cout << "\nMatrix Plus (Umnoj + Cub):\n";
	c.output();
	c.file_output();

	cout << "\nMatrix Minus (Umnoj - Cub):\n";
	d.output();
	d.file_output();

	cout << "\nMatrix A after:\n";
	a.output();
	cout << "\nMatrix B after:\n";
	b.output();

}