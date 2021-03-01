#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int Rand(int n)
{
    return rand() % n ;
}

int simple(int n){
    for(int i = 2; i <= n/2; i++) if ((n % i) == 0) return 0;
return 1;
}

void make_sqr (int &n) {
    n = n * n;
}

void replace_1 (int &n) {
    n = 1;
}

void replace_0 (int &n) {
    if (n < 0) {
        n = 0;
    }
}

void print(vector <int> p) {
    for (size_t i = 0; i < p.size(); i++) {
        cout << i << ": " << p[i] << endl;
    }
    cout << endl;
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

//    //Добавляю элементы в П1 через cin
//    cout << "How many new elements do you want to add: ";
//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        int x;
//        cout << "Input new element: ";
//        cin >> x;
//        p.push_back(x);
//    }
//
//    cout << "size =  " << p.size() << endl;
    print(p);
//
//    //Перемешиваю элементы П1
//    random_shuffle(p.begin(), p.end(), pointer_to_unary_function<int, int>(Rand));
//
//    print(p);

//    //Удаляю повторяющиеся элементы
//    for (int i = 0; i < p.size() - 1; i++) {
//        int n = p[i];
//        int count = count_if(p.begin(), p.end(), [n](int elem){return elem == n;});
//        if (count > 1) {
//            p.erase(remove_if(p.begin() + i + 1, p.end(), [n](int elem){return elem == n;}), p.end());
//        }
//    }
//
//    print(p);

//    //Подсчитываю чётные элементы
//    int c = count_if(p.begin(), p.end(), [](int elem){return elem % 2 != 0;});
//    cout << "Amount of uneven elements: " << c << endl;
//
//    //Нашёл максимальный и минимальный элементы вектора
//    cout << "Max element: " << *max_element(p.begin(), p.end()) << ", Min element: " << *min_element(p.begin(), p.end()) << endl;
//
//    //Нашёл первый простой элемент вектора
//    auto it = find_if(p.begin(), p.end(), simple);
//    cout << "first simple element: " << *it << endl;

//    //Возвёл в квадрат элементы вектора
//    for_each(p.begin(), p.end(), make_sqr);
//    for (size_t i = 0; i < p.size(); i++) {
//        cout << i << ": " << p[i] << endl;
//    }
//    cout << endl;

    vector <int> p2(p.size());
    int r2 = 0;
    for (size_t i = 0; i < p.size(); i++) {
        srand(time(0) * r2++ * 7);
        p2[i] = rand() % 10;
    }

    for (size_t i = 0; i < p2.size(); i++) {
        cout << i << ": " << p2[i] << endl;
    }
    cout << endl;

    //Посчитал сумму элементов П2
//    int res = accumulate(p2.begin(), p2.end(), 0, [](int sum, int elem){return sum += elem;});
//    cout << "Summ p2: " << res << endl;

//    //Заменил введённое пользователем количество элементов П2 на 1
//    cout << "How many new elements do you want to replace with 1: ";
//    int h;
//    cin >> h;
//
//    for_each(p2.begin(), p2.begin() + h, replace_1);
//    for (size_t i = 0; i < p2.size(); i++) {
//        cout << i << ": " << p2[i] << endl;
//    }
//    cout << endl;

    sort(p.begin(), p.end());
    sort(p2.begin(), p2.end());

    vector <int> p3(p.size());
	cout << "set_difference(): ";
	set_difference(
		p.cbegin(), p.cend(),
		p2.cbegin(), p2.cend(),
		p3.begin());
	cout << endl;

    print(p3);

    for_each(p3.begin(), p3.end(), replace_0);
    print(p3);

   return 0;
}
