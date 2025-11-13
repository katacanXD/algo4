#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Insertion
{
public:
    static void f(vector<int>& vec) {
        cout << "Сортировка вставками" << endl;

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 1; i < vec.size(); ++i) {
            int key = vec[i];
            int j = i - 1;

            while (j >= 0 && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
                /*for (int i : vec) {
                    cout << i << " ";
                }
                cout << endl;*/
            }

            vec[j + 1] = key;

        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        cout << "Время выполнения: " << duration.count() << " наносекунд" << endl;

        /*for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;*/
    }
};