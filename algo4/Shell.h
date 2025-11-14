#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Shell
{
public:
    static void f(vector<int> vec) {
        cout << "Сортировка Шелла" << endl;

        auto start = std::chrono::high_resolution_clock::now();
        int n = vec.size();

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int current = vec[i];
                int position = i;

                while (position >= gap && vec[position - gap] > current) {
                    vec[position] = vec[position - gap];
                    position -= gap;
                }
                vec[position] = current;
            }
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

