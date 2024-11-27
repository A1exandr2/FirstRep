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

// ������� ��� ����� ������ ������
void inputTrains(TRAIN trains[], int count) 
{
    cin.ignore(); // ���������� ������ ����� ������ ����� ����������� �����
    for (int i = 0; i < count; ++i) 
    {
        cout << "������� ���������� � ������ #" << (i + 1) << ":\n";
        cout << "����� ����������: ";
        getline(cin, trains[i].punct); // ���������� getline ��� ����������� �����
        cout << "����� ������: ";
        getline(cin, trains[i].trainNumber); // ���������� getline
        cout << "����� �����������: ";
        getline(cin, trains[i].time); // ���������� getline
        cout << endl;
    }
}

// ������� ��� ���������� ������ ������� �� �������
void sortTrains(TRAIN trains[], int count) 
{
    sort(trains, trains + count, [](const TRAIN& a, const TRAIN& b) 
        {
        return a.trainNumber < b.trainNumber;
        });
}

// ������� ��� ������ ������ �� ������
void searchTrainByNumber(TRAIN trains[], int count, const string& trainNumber) 
{
    for (int i = 0; i < count; ++i) 
    {
        if (trains[i].trainNumber == trainNumber) 
        {
            cout << "����� ������!" << endl;
            cout << "����� ����������: " << trains[i].punct << endl;
            cout << "����� ������: " << trains[i].trainNumber << endl;
            cout << "����� �����������: " << trains[i].time << endl;
            return;
        }
    }
    cout << "����� � ������� " << trainNumber << " �� ������." << endl;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    const int TRAIN_COUNT = 8; // ���������� �������
    TRAIN trains[TRAIN_COUNT];

    // ���� ������ � �������
    inputTrains(trains, TRAIN_COUNT);

    // ���������� ������� �� �������
    sortTrains(trains, TRAIN_COUNT);

    // ����� ������ �� ������
    string trainNumber;
    cout << "������� ����� ������ ��� ������: ";
    getline(cin, trainNumber); // ���������� getline ��� ����������� �����

    searchTrainByNumber(trains, TRAIN_COUNT, trainNumber);

    return 0;
}
