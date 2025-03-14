#include "books.h"

void output_file_name(ofstream& fout) {
	if (fout.is_open()) {
		fout.close();
	}
	cout << "Введите название файла: ";
	bool f = 0;
	string file_name;
	while (getline(cin, file_name)) {
		fout.open(file_name);
		if (!fout.is_open()) {
			if (f == 0) {
				f = 1;
				continue;
			}
			cout << "Не найден такой файл.\n";
			cout << "Введите название файла: ";
		}
		else
			break;
	}
}

void input_file_name(ifstream& fin) {
	if (fin.is_open()) {
		fin.close();
	}
	cout << "Введите название файла: ";
	string file_name;
	bool f = 0;
	while (getline(cin, file_name)) {
		fin.open(file_name);
		if (!fin.is_open()) {
			if (f == 0) {
				f = 1;
				continue;
			}
			cout << "Не найден такой файл.\n";
			cout << "Введите название файла: ";
		}
		else
			break;
	}
}

int input_type() {
	int ch1;
	cout << "Выберете тип ввода данных: 1 - текстовый файл, 2 - бинарный файл, 3 - в консоли: ";
	while (cin >> ch1) {
		if (ch1 == 1) {
			break;
		}
		else if (ch1 == 2 || ch1 == 3)
			break;
		else if (ch1 != 1 && ch1 != 2 && ch1 != 3) {
			cout << "Некоректный ввод.\n";
			cout << "Выберете тип ввода данных: 1 - текстовый файл, 2 - бинарный файл, 3 - в консоли: ";
		}
	}
	return ch1;
}

int output_type() {
	int ch2;
	cout << "Выберете способ вывода результатов: 1 - в текстовый файл, 2 - в бинарный файл, 3 - в консоль: ";
	while (cin >> ch2) {
		if (ch2 == 1) {
			break;
		}
		else if (ch2 == 2)
			break;
		else if (ch2 != 1 && ch2 != 2) {
			cout << "Некоректный ввод.\n";
			cout << "Выберете способ вывода результатов: 1 - в текстовый файл, 2 - в бинарный файл, 3 - в консоль: ";
		}
	}
	return ch2;
}

void printTable(const book* books, int count) {
	cout << left << setw(10) << "Номер" << setw(30) << "Название книги" << setw(10) << "Год издания\n";
	cout << setfill('-') << setw(60) << "" << setfill(' ') << '\n';

	int mx = 0;	
	for (int i = 0; i < count; i++) {
		cout << left << setw(10) << i + 1 << setw(30) << books[i].name << setw(10) << books[i].year << '\n';
		if (books[i].year > mx)
			mx = books[i].year;
	}

	cout << setfill('-') << setw(60) << "" << setfill(' ') << '\n';
	cout << left << setw(10) << "Макс. год:" << setw(30) << "" << setw(10) << mx << '\n';
}