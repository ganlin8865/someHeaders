#include "littletools.h"


using namespace std;

//About Sort

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) 
    {
        int key = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && arr[j] > key) 
        { 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

//About Random

int RandomInt(int L, int R)
{
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(L, R);
    return dis(gen);
}

float RandomFloat(double L, double R)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(L, R);
    return dis(gen);
}
