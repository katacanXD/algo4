#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class Quick
{
public:
    static void f(vector<int> vec) {
        cout << "Быстрая сортировка" << endl;

        auto start = std::chrono::high_resolution_clock::now();


        quickSort(vec, 0, vec.size() - 1);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        cout << "Время выполнения: " << duration.count() << " наносекунд" << endl;

        /*for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;*/
    }

private:
    static void quickSort (vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            int pivot = arr[mid];

            swap(arr[mid], arr[high]);

            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (arr[j] <= pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }

            swap(arr[i + 1], arr[high]);
            int pivotIndex = i + 1;

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }
};