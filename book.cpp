#include "book.h"


void Book::getData()
{
	cout << "������: \n" << endl 
		<< "�������� �����:  " << bookname << endl
		<< "��� ������:  " << name << endl
		<< "������� ������:  " << lastName << endl 
		<< "�������� ������:  " << patronymic << endl
		<< "������������:  " << publishingoffice << endl 
		<< "��� �������  " << yearOfIssue << endl;
}

string Book::getBookName()
{
	return bookname;

}

string Book::getName()
{
	return name;
}

string Book::getLastName()
{
	return lastName;
}

string Book::getPatronymic()
{
	return patronymic;
}

string Book::getPublishingOffice()
{
	return publishingoffice;
}

int Book::getYear()
{
	return yearOfIssue;
}

