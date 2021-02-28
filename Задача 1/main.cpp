#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

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

int main()
{
    //������ ���-�� �1
    vector <int> p(10);
    int r = 0;
    for (int i = 0; i < 10; i++) {
        srand(time(0) * r++ * 7);
        p[i] = rand() % 10 + 1;
    }
    cout << endl;

//    //�������� �������� � �1 ����� cin
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
    for (size_t i = 0; i < p.size(); i++) {
        cout << i << ": " << p[i] << endl;
    }
    cout << endl;
//
//    //����������� �������� �1
//    random_shuffle(p.begin(), p.end(), pointer_to_unary_function<int, int>(Rand));
//
//    for (size_t i = 0; i < p.size(); i++) {
//        cout << i << ": " << p[i] << endl;
//    }
//    cout << endl;

//    //������ ������������� ��������
//    for (int i = 0; i < p.size() - 1; i++) {
//        int n = p[i];
//        int count = count_if(p.begin(), p.end(), [n](int elem){return elem == n;});
//        if (count > 1) {
//            p.erase(remove_if(p.begin() + i + 1, p.end(), [n](int elem){return elem == n;}), p.end());
//        }
//    }
//
//    for (size_t i = 0; i < p.size(); i++) {
//        cout << i << ": " << p[i] << endl;
//    }
//    cout << endl;

//    //����������� ������ ��������
//    int c = count_if(p.begin(), p.end(), [](int elem){return elem % 2 != 0;});
//    cout << "Amount of uneven elements: " << c << endl;
//
//    //����� ������������ � ����������� �������� �������
//    cout << "Max element: " << *max_element(p.begin(), p.end()) << ", Min element: " << *min_element(p.begin(), p.end()) << endl;
//
//    //����� ������ ������� ������� �������
//    auto it = find_if(p.begin(), p.end(), simple);
//    cout << "first simple element: " << *it << endl;

    //����� � ������� �������� �������
    for_each(p.begin(), p.end(), make_sqr);
    for (size_t i = 0; i < p.size(); i++) {
        cout << i << ": " << p[i] << endl;
    }
    cout << endl;



   return 0;
}
