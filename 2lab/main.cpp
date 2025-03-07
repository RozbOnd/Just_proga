<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

struct book {
	char* name = new char[300];
	int year;
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void output_file_name(ofstream& fout) {
	if (fout.is_open()) {
		fout.close();
	}
	cout << "������� �������� �����: ";
	bool f = 0;
	char* file_name = new char[256];
	while (cin.getline(file_name, 256)) {
		fout.open(file_name);
		if (!fout.is_open()) {
			if (f == 0) {
				f = 1;
				continue;
			}
			cout << "�� ������ ����� ����.\n";
			cout << "������� �������� �����: ";
		}
		else
			break;
	}
}

void input_file_name(ifstream& fin) {
	if (fin.is_open()) {
		fin.close();
	}
	cout << "������� �������� �����: ";
	char* file_name = new char[256];
	bool f = 0;
	while (cin.getline(file_name, 256)) {
		fin.open(file_name);
		if (!fin.is_open()) {
			if (f == 0) {
				f = 1;
				continue;
			}
			cout << "�� ������ ����� ����.\n";
			cout << "������� �������� �����: ";
		}
		else
			break;
	}
}

int input_type() {
	int ch1;
	cout << "�������� ��� ����� ������: 1 - ��������� ����, 2 - �������� ����, 3 - � �������: ";
	while (cin >> ch1) {
		if (ch1 == 1) {
			break;
		}
		else if (ch1 == 2 || ch1 == 3)
			break;
		else if (ch1 != 1 && ch1 != 2 && ch1 != 3) {
			cout << "����������� ����.\n";
			cout << "�������� ��� ����� ������: 1 - ��������� ����, 2 - �������� ����, 3 - � �������: ";
		}
	}
	return ch1;
}

int output_type() {
	int ch2;
	cout << "�������� ������ ������ �����������: 1 - � ��������� ����, 2 - � �������� ����, 3 - � �������: ";
	while (cin >> ch2) {
		if (ch2 == 1) {
			break;
		}
		else if (ch2 == 2)
			break;
		else if (ch2 != 1 && ch2 != 2) {
			cout << "����������� ����.\n";
			cout << "�������� ������ ������ �����������: 1 - � ��������� ����, 2 - � �������� ����, 3 - � �������: ";
		}
	}
	return ch2;
}

void printTable(const book* books, int count) {
	cout << left << setw(10) << "�����" << setw(30) << "�������� �����" << setw(10) << "���\n";
	cout << setfill('-') << setw(50) << "" << setfill(' ') << '\n';

	int mx = 0;	
	for (int i = 0; i < count; i++) {
		cout << left << setw(10) << i + 1 << setw(30) << books[i].name << setw(10) << books[i].year << '\n';
		if (books[i].year > mx)
			mx = books[i].year;
	}

	cout << setfill('-') << setw(50) << "" << setfill(' ') << '\n';
	cout << left << setw(10) << "����. ���:" << setw(30) << "" << setw(10) << mx << '\n';
}

void addRecord(book*& books, int& size) {
	book* newBooks = new book[size + 1];

	for (int i = 0; i < size; i++)
		newBooks[i] = books[i];

	cout << "������� �������� �����: ";
	cin.ignore();
	cin.getline(newBooks[size].name, 300);
	cout << "������� ��� �������: ";
	cin >> newBooks[size].year;
	size++;
	delete[] books;
	books = newBooks;
}

void delRecord(book*& books, int& size) {

	if (size == 0) {
		cerr << "������� ���, �������� ����������.\n";
		return;
	}

	book* newBooks = new book[size - 1];

	int ind;
	cout << "������� ����� ������ ��� ��������: ";
	cin >> ind;
	cin.ignore();

	if (ind < 1 || ind > size) {
		cerr << "�������� ����� ������.\n";
		return;
	}
	ind--;
	int cur_i = 0;
	for (int i = 0; i < size; i++)
		if (i != ind) newBooks[cur_i++] = books[i];

	size--;
	delete[] books;
	books = newBooks;
}

int main() {
	setlocale(LC_ALL, "Russian");

	/*ifstream fin;
	ofstream fout;
	int ch1 = input_type();
	if (ch1 == 1) input_file_name(fin);

	int ch2 = output_type();
	if (ch2 == 1) output_file_name(fout), fout << fixed << setprecision(4);
	else cout << fixed << setprecision(4);*/


	book* books;
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	books = new book[size];
	for (int i = 0; i < size; i++) {
		cout << "������� �������� " << i + 1 << " �����: ";
		cin.ignore();
		cin.getline(books[i].name, 300);
		cout << "������� ��� ������� �����: ";
		cin >> books[i].year;
		cout << '\n';
	}

	printTable(books, size);

	cout << '\n';

	addRecord(books, size);
	printTable(books, size);

	cout << '\n';
	delRecord(books, size);
	printTable(books, size);

	/*fin.close();
	fout.close();*/


	return 0;
}
=======

>>>>>>> 66d86d61117a1576a3e99af4a25861c434c382af
