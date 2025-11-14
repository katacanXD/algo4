#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Selection {
public:
    static void f(vector<int> vec) {
        cout << "Сортировка выбором (оптимизированная)" << endl;

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < vec.size() - 1; ++i) {
            int min_index = i;
            int min_value = vec[i];  // Сохраняем значение

            for (int j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < min_value) {  // Сравниваем с сохраненным значением
                    min_index = j;
                    min_value = vec[j];
                }
            }

            if (min_index != i) {
                // Прямое присваивание вместо swap
                vec[min_index] = vec[i];
                vec[i] = min_value;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        cout << "Время выполнения: " << duration.count() << " наносекунд" << endl;
    }
};

