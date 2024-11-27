#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TRAIN 
{
    string punct;
    string trainNumber;
    string time;
};

// Функция для ввода данных поезда
void inputTrains(TRAIN trains[], int count) 
{
    cin.ignore(); // Игнорируем символ новой строки после предыдущего ввода
    for (int i = 0; i < count; ++i) 
    {
        cout << "Введите информацию о поезде #" << (i + 1) << ":\n";
        cout << "Пункт назначения: ";
        getline(cin, trains[i].punct); // Используем getline для правильного ввода
        cout << "Номер поезда: ";
        getline(cin, trains[i].trainNumber); // Используем getline
        cout << "Время отправления: ";
        getline(cin, trains[i].time); // Используем getline
        cout << endl;
    }
}

// Функция для сортировки массив поездов по номерам
void sortTrains(TRAIN trains[], int count) 
{
    sort(trains, trains + count, [](const TRAIN& a, const TRAIN& b) 
        {
        return a.trainNumber < b.trainNumber;
        });
}

// Функция для поиска поезда по номеру
void searchTrainByNumber(TRAIN trains[], int count, const string& trainNumber) 
{
    for (int i = 0; i < count; ++i) 
    {
        if (trains[i].trainNumber == trainNumber) 
        {
            cout << "Поезд найден!" << endl;
            cout << "Пункт назначения: " << trains[i].punct << endl;
            cout << "Номер поезда: " << trains[i].trainNumber << endl;
            cout << "Время отправления: " << trains[i].time << endl;
            return;
        }
    }
    cout << "Поезд с номером " << trainNumber << " не найден." << endl;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    const int TRAIN_COUNT = 8; // Количество поездов
    TRAIN trains[TRAIN_COUNT];

    // Ввод данных о поездах
    inputTrains(trains, TRAIN_COUNT);

    // Сортировка поездов по номерам
    sortTrains(trains, TRAIN_COUNT);

    // Поиск поезда по номеру
    string trainNumber;
    cout << "Введите номер поезда для поиска: ";
    getline(cin, trainNumber); // Используем getline для корректного ввода

    searchTrainByNumber(trains, TRAIN_COUNT, trainNumber);

    return 0;
}
