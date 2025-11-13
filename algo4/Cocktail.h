#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Cocktail
{
public:
    static void f(vector<int>& vec) {
        std::cout << "Шейкерная сортировка" << endl;

        auto start = std::chrono::high_resolution_clock::now();

        int left = 0;
        int right = vec.size() - 1;

        while (left < right) {
            int new_right = left;

            for (int i = left; i < right; ++i) {
                if (vec[i] > vec[i + 1]) {
                    swap(vec[i], vec[i + 1]);
                    new_right = i;
                }
            }
            right = new_right;

            int new_left = right;

            for (int i = right; i > left; --i) {
                if (vec[i] < vec[i - 1]) {
                    swap(vec[i], vec[i - 1]);
                    new_left = i;
                }
            }
            left = new_left;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        cout << "Время выполнения: " << duration.count() << " наносекунд" << endl;

        /*for (int i : vec) {
            cout << i << " ";
        }*/
    }
};

