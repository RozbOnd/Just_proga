#include "books.h"
#include "in_out.h"
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

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
	cout << "Введите размер массива: ";
	cin >> size;
	books = new book[size];
	for (int i = 0; i < size; i++) {
		cout << "Введите название " << i + 1 << " книги: ";
		cin.ignore();
		getline(cin, books[i].name);
		cout << "Введите год издания книги: ";
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