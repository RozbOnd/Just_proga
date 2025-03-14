#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <clocale>
using namespace std;

struct book {
	string name;
	int year;
};

void addRecord(book*& books, int& size) {
	book* newBooks = new book[size + 1];

	for (int i = 0; i < size; i++)
		newBooks[i] = books[i];

	cout << "Введите название книги: ";
	cin.ignore();
	getline(cin, newBooks[size].name);
	cout << "Введите год издания: ";
	cin >> newBooks[size].year;
	size++;
	delete[] books;
	books = newBooks;
}

void delRecord(book*& books, int& size) {

	if (size == 0) {
		cerr << "Записей нет, удаление невозможно.\n";
		return;
	}

	book* newBooks = new book[size - 1];

	int ind;
	cout << "Введите номер записи для удаления: ";
	cin >> ind;
	cin.ignore();

	if (ind < 1 || ind > size) {
		cerr << "Неверный номер записи.\n";
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