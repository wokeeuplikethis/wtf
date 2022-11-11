#include "io.h"
#include "book.h"


void Subsubmenu(Book array[], int Size)
{
    int thirdChoice = 0;
    string secondFileAddress = "";
    int inputinInput = 0;
    do {
        cout << "1 - Сохранить данные в файл" << endl;
        cout << "2 - Вернуться в подменю" << endl;
        cin >> thirdChoice;
        ofstream secondFile;
        switch (thirdChoice) {
        case saveDataOld:
            cout << "1 - Cохранить результат в существующий файл" << endl;
            cout << "2 - Сохранить результат в новый файл" << endl;
            cin >> inputinInput;
            if (inputinInput == 1) {
                cout << "Название файла:" << endl;
                cin.get();
                getline(cin, secondFileAddress);
                secondFile.open(secondFileAddress, ofstream::trunc);
                for (int i = 0; i < Size; i++) {

                    secondFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                    secondFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl;
                    secondFile << array[i].getYear() << endl;

                }
                secondFile.close();
                cout << "Файл сохранён" << endl;
            }
            else if (inputinInput == 2) {
                string nameFile = "";
                cout << "Название файла:" << endl;
                cin >> nameFile;
                secondFile.open(nameFile);
                if (secondFile.is_open()) {
                    for (int i = 0; i < Size; i++) {

                        secondFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                        secondFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl;
                        secondFile << array[i].getYear() << endl;
                    }
                }
                else {
                    cout << "Операция не удалась..." << endl;
                }
                secondFile.close();
                cout << "Файл сохранён!" << endl;
            }
            else {
                cout << "Такого пункта не существует..." << endl;
            }
            break;
        case notSaveDate:
            cout << "Данные не будут сохранены..." << endl;
            break;
        default:
            cout << "Такой пункт в меню не существует!" << endl;
            break;
        }
    } while (thirdChoice != notSaveDate);
}
void Submenu(Book array[], int Size)
{
    int secondChoice = 0;
    string NameAuthor = "";
    string LastNameAuthor = "";
    string PatronymicAuthor = "";
    string NameOfPublishingOffice = "";
    int minYearOfIssue = 0;
    Book* resultArray = 0;
    int resultSize = 0;
    do {
        cout << "Перед вами подменю." << endl;
        cout << "1 - Список книг,по имени автора. " << endl;
        cout << "2 - Список книг,по издательству." << endl;
        cout << "3 - Список книг,выпущенных после введеного года." << endl;
        cout << "4 - Переход к начальному меню." << endl;
        cin >> secondChoice;
        switch (secondChoice) {
        case listOfBooksByAuthor:
            resultSize = 0;
            cin.get();
            cout << "Введите имя автора" << endl;
            getline(cin,NameAuthor);
            cout << "Введите фамилию автора" << endl;
            getline(cin,LastNameAuthor);
            cout << "Введите отчество автора" << endl;
            getline(cin,PatronymicAuthor);
            for (int i = 0; i < Size; i++) {
                if (array[i].getName() == NameAuthor and array[i].getLastName() == LastNameAuthor
                    and array[i].getPatronymic() == PatronymicAuthor)
                {
                    array[i].getData();
                    resultSize++;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getName() == NameAuthor and array[i].getLastName() == LastNameAuthor
                    and array[i].getPatronymic() == PatronymicAuthor) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            Subsubmenu(resultArray, resultSize);
            break;
        case listOfBooksByPublishingOffice:
            resultSize = 0;
            cout << "Введите название издательства" << endl;
            cin.get();
            getline(cin,NameOfPublishingOffice);
            for (int i = 0; i < Size; i++) {
                if (array[i].getPublishingOffice() == NameOfPublishingOffice) {
                    array[i].getData();
                    resultSize++;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getPublishingOffice() == NameOfPublishingOffice) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            Subsubmenu(resultArray, resultSize);
            break;
        case listOfBooksByYearOfIssue:
            resultSize = 0;
            cout << "Введите год после которого были изданы книги" << endl;
            cin >> minYearOfIssue;
            for (int i = 0; i < Size; i++) {
                if (array[i].getYear() >= minYearOfIssue) {
                    array[i].getData();
                    resultSize++;

                }
                else {
                    cout << "Нет книг изданных после этого года..." << endl;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getYear() >= minYearOfIssue) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            Subsubmenu(resultArray, resultSize);
        case backToTheBeginning:
            cout << "Возвращение в начало..." << endl;
            break;
        default:
            cout << "Пункт в меню не существует!" << endl;
            break;
        }

    } while (secondChoice != backToTheBeginning);
};