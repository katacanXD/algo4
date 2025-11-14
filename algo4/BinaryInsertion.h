#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class BinaryInsertion {
public:
    static void f(vector<int> vec) {
        cout << "Бинарная сортировка вставками" << endl;

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 1; i < vec.size(); ++i) {
            int key = vec[i];
            int left = 0;
            int right = i;

            while (left < right) {
                int mid = left + (right - left) / 2;
                if (key < vec[mid]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }

            for (int j = i; j > left; --j) {
                vec[j] = vec[j - 1];
            }
            vec[left] = key;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        cout << "Время выполнения: " << duration.count() << " наносекунд" << endl;
    }
};