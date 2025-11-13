#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Selection
{
public:
    static void f(vector<int>& vec) {
        cout << "Сортировка выбором" << endl;

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < vec.size() - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < vec[min_index]) {
                    min_index = j;
                }
            }

            if (min_index != i) {
                swap(vec[i], vec[min_index]);
            }

            /*for (int k : vec) {
                cout << k << " ";
            }
            cout << endl;*/
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

