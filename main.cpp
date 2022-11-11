#include "io.h"
#include "book.h"
#include "menu.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int userChoice = 0;
    int Size = 0;
    string fileAddress = "";
    ifstream file;
    int input2InInput = 0;
    string thirdFileAdress = "";
    ofstream thirdFile;
    string secondName = "";;
    string str;;
    int i = 0;
    setlocale(LC_ALL, "Rus");
    
    cout << "����������� ������ ����� 1. ������� 4. ������� �.�. 415. �������: ���������� ����������� �����"
        "��� ��������� ���������� �������.������ � ������ ����������� � ������� ������� Set,Get,Show." << endl;
    do { 
        cout << "����." << endl;
        cout << "1 - ���������� ������" << endl;
        cout << "2 - �������� ����" << endl;
        cout << "3 - �����" << endl;
        if(!(cin >> userChoice)) {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "������� �� �����...�������� ��� ���!" << endl;
            cin >> userChoice;
        }
        //cin >> userChoice;
        //cin.get();

        if (userChoice == 1)  // ���� ������ �������
        {
            cout << "������� ���������� ����" << endl;
            cin >> Size;
            if (Size == 0)
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "\n������������ �������� =(" << endl <<"�������� ��� ���!\n" << endl;
                cout << "������� ���������� ����" << endl;
                cin >> Size;
            }
        }
        if (userChoice == 2)
        {
            cout << "�������� �����:" << endl;
            cin.get();
            getline(cin, fileAddress);
            cout << "������� ���������� ����:" << endl;
            cin >> Size;
            /*while (!file.eof()) {
                 getline(file, str, '\n');
                 i++;
                 if (i == 6) {  
                     Size++;
                     i = 0;
                 }
            }
            cout << "���������� ����:" << endl;
            cout << Size  << endl;*/

        }
        Book* array = new Book[Size];
        switch (userChoice) {
        case keyboardInput:

            for (int i = 0; i < Size; i++) {
                string bookname, name, lastName, patronymic, publishingoffice;
                int yearOfIssue = 0;
                cin.get();  //� �������
                cout << "������� �������� �����" << endl;
                getline(cin, bookname);

                cout << "������� ��� ������" << endl;
                getline(cin, name);

                cout << "������� ������� ������" << endl;
                getline(cin, lastName);

                cout << "������� �������� ������" << endl;
                getline(cin, patronymic);

                cout << "������� �������� ������������" << endl;
                getline(cin, publishingoffice);

                cout << "������� ��� ������� �����" << endl;
                cin >> yearOfIssue;

               array[i] = Book(bookname, name, lastName, patronymic, publishingoffice,
                    yearOfIssue);
               array[i].getData();

            }
            
            /*for (int i = 0; i < Size; i++) {
                array[i].getData();
                cout << "\n" << endl;
            }*/
            cout << "1 - ��������� ������, �������� ������������� � ����� ����. " << endl;
            cout << "2 - ��������� ������, �������� ������������� � ������������ ����." << endl;
            cout << "3 � ����� ������ ����� - ������,�������� ������������� �� ����������" << endl;
            if (!(cin >> input2InInput)) {
                cout << ("����������") << endl;
            }
           //cin >> input2InInput;
            if (input2InInput == 2) {
                cout << "�������� �����:" << endl;
                cin.get();
                getline(cin, thirdFileAdress);
                thirdFile.open(thirdFileAdress, ofstream::trunc);
                for (int i = 0; i < Size; i++) {
                    thirdFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                    thirdFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl << array[i].getYear() << endl;
                }
                thirdFile.close();
                cout << "���� �������" << endl;
            }
            else if (input2InInput == 1) {
                cout << "�������� �����:" << endl;
                cin >> secondName;
                thirdFile.open(secondName);
                for (int i = 0; i < Size; i++) {
                    thirdFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                    thirdFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl << array[i].getYear() << endl;
                }
                cout << "���� �������" << endl;
                thirdFile.close();
            }
            else if (input2InInput == 3) {
                cout << "������ ����� ������������� ��� ����������..." << endl;
            }


            Submenu(array, Size);
            delete[] array;
            array = nullptr;
            break;
        case fileInput:
            file.open(fileAddress);
            cin.clear();
            cin.ignore();
            for (int i = 0; i < Size; i++) {
                string bookname, name, lastName, patronymic, publishingoffice;
                int yearOfIssue;

                    //file >> bookname;
                    getline(file, bookname);

                    //file >> name;
                    getline(file, name);

                    //file >> lastName;
                    getline(file, lastName);

                    //file >> patronymic;
                    getline(file, patronymic);

                    //file >> publishingoffice;
                    getline(file, publishingoffice);

                    file >> yearOfIssue;
    
                    array[i] = Book(bookname, name, lastName, patronymic,
                        publishingoffice, yearOfIssue);
                
            }
            for (int i = 0; i < Size; i++) { 
                array[i].getData();
            }
            Submenu(array, Size);
            delete[] array;
            array = nullptr;
            file.close();
            break;
        case quit:
            cout << "���������� ������ ;)" << endl;
            break;
            return 0;
        default:
            cout << "����� �� ����������!!" << endl;
            break;
        }
    } while (userChoice != quit);

    system("pause");
}