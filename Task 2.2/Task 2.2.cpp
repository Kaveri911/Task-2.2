#include <iostream>

using namespace std;

void inv(int* arr, int n)
{
    int* inverted_array = new int[n];

    for (int i = n - 1; i >= 0;)
    {
        for (int j = 0; j < n;)
        {
            inverted_array[i] = arr[j];
            i--;
            j++;
            break;
        }
    }
    cout << "Новый массив: ";
    for (int i = 0; i < n; i++)
    {
        cout<< inverted_array[i] << " ";
    }

    delete[]inverted_array;
}

void non_ub(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n;)
        {
            if (arr[i] <= arr[j])
            {
                int c = 0;

                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;

                c = 0;

                j++;
            }

            else
            {
                j++;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout<< arr[i] << " ";
    }
    cout << "Новый массив: ";
    cout<< arr[0] << " ";
}

void non_vozr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n;)
        {
            if (arr[i] >= arr[j])
            {
                int c = 0;

                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;

                c = 0;

                j++;
            }

            else
            {
                j++;
            }
        }
    }
    cout << "Новый массив: ";
    for (int i = 1; i < n; i++)
    {
        cout<< arr[i] << " ";
    }

    cout<< arr[0] << " ";
}

void fun(int* arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Сумма = " << sum << endl;
    if (sum < arr[0])
    {
        cout << "Сумма < 1-го элемента" << endl;
        inv(arr, n);
    }
    else if (sum == arr[0])
    {
        cout << "Сумма = 1-му элементу" << endl;
        non_ub(arr, n);
    }
    else if (sum > arr[0])
    {
        cout << "Сумма > 1-го элемента" << endl;
        non_vozr(arr, n);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n = rand() % 15 + 10;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 - 25;
        cout << arr[i] << " ";
    }
    cout << endl;
    void (*jj)(int*, int);

    jj = fun;
    (*jj)(arr, n);

    delete[] arr;

    return 0;
}