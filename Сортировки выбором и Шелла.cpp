// Сортировки выбором и Шелла.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
#define N 8

int arr[N];

void Rand()
{
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 201 - 100;
    }
    cout << "BEFORE: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void Selection()
{
    for (int i = 0; i < N; i++)
    {
        int key = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[key]) key = j;
        }
        if (key != i) swap(arr[key], arr[i]);
    }
}
void Shell()
{
    int step = N / 2;
    while (step > 0)
    {
        for (int i = 0; i < N - step; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] < arr[j + step])
            {
                swap(arr[j], arr[j + step]);
                j--;
            }
        }
        step = step / 2;
    }
}
void Output()
{
    cout << "AFTER: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << "\t";
}

int main()
{
    setlocale(LC_ALL, "rus");
    Rand();

    //Selection();
    Shell();

    Output();
}

