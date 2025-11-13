#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Bubble
{
public:
	static void f(vector<int>& vec) {
		cout << "BU BU BU" << endl;

        auto start = std::chrono::high_resolution_clock::now();

        bool swapped;
        int n = vec.size();

        for (int i = 0; i < n - 1; ++i) {
            swapped = false;

            for (int j = 0; j < n - i - 1; ++j) {
                if (vec[j] > vec[j + 1]) {
                    swap(vec[j], vec[j + 1]);
                    swapped = true;
                }
                /*for (int i : vec) {
                    cout << i << " ";
                }
                cout << endl;*/
            }

            if (!swapped) {
                break;
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

