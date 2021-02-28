#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int Rand(int n)
{
    return rand() % n ;
}

int main()
{
    //создаю пос-ть П1
    vector <int> p(10);
    int r = 0;
    for (int i = 0; i < 10; i++) {
        srand(time(0) * r++ * 7);
        p[i] = rand() % 10 + 1;
    }
    cout << endl;

    //Добавляю элементы в П1 через cin
    cout << "How many new elements do you want to add: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Input new element: ";
        cin >> x;
        p.push_back(x);
    }

    cout << "size =  " << p.size() << endl;
    for (size_t i = 0; i < p.size(); i++) {
        cout << i << ": " << p[i] << endl;
    }
    cout << endl;

    //Перемешиваю элементы П1
    random_shuffle(p.begin(), p.end(), pointer_to_unary_function<int, int>(Rand));

    for (size_t i = 0; i < p.size(); i++) {
        cout << i << ": " << p[i] << endl;
    }
    cout << endl;



    return 0;
}
