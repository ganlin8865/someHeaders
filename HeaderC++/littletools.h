#pragma once
#ifndef LITTLETOOLS_H
#define LITTLETOOLS_H

#include <random>
#include <algorithm>

//About Sort

void BubbleSort(int arr[], int size);
void InsertionSort(int arr[], int size);
void QuickSort(int arr[]);

//About Random

int RandomInt(int L, int R);
float RandomFloat(double L, double R);

#endif

