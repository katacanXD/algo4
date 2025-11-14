#include <iostream>
#include <vector>
#include <random>

#include "Bubble.h"
#include "Cocktail.h"
#include "Insertion.h"
#include "Selection.h"
#include "Shell.h"
#include "Quick.h"
#include "BinaryInsertion.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    cout << endl;
    vector<int> a(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, n*10);

    for (int i = 0; i < a.size(); i++) {
        a[i] = dist(gen);
    }

    /*cout << "Изначальный массив: " << endl;
    for (int& i : a) {
        cout << i << " ";
    }
    cout << endl << endl;*/

    int nomber;
    cout << "Выберите алгоритм: \n 1. Пузырьковая\n" << " 2. Шейкерная\n" <<
        " 3. Вставками\n" << " 4. Выбором\n" << " 5. Шелла\n"
        << " 6. Хоара\n" << " 7. Все сразу" << endl;
    cin >> nomber;

    switch(nomber) {
    case (1):
        Bubble::f(a);
        break;
    case (2):
        Cocktail::f(a);
        break;
    case (3):
        Insertion::f(a);
        break;
    case (4):
        Selection::f(a);
        break;
    case (5):
        Shell::f(a);
        break;
    case (6):
        Quick::f(a);
        break;
    case (7):
        Bubble::f(a);
        Cocktail::f(a);
        Insertion::f(a);
        Selection::f(a);
        Shell::f(a);
        Quick::f(a);
        BinaryInsertion::f(a);
    }
}
