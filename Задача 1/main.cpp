#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

//���������� (���������� � ��������� �� 0 �� n)
int Rand(int n)
{
    return rand() % n ;
}

//������� �� �������� �� ������� �����
int simple(int n){
    for(int i = 2; i <= n/2; i++) if ((n % i) == 0) return 0;
return 1;
}

//�������, ���������� �������� � �������
void make_sqr (int &n) {
    n = n * n;
}

//�������, ���������� �������� �� 1
void replace_1 (int &n) {
    n = 1;
}

//�������, ���������� ������������� �������� �� 0
void replace_0 (int &n) {
    if (n < 0) {
        n = 0;
    }
}

//������� ������
void print(vector <int> p) {
    for (size_t i = 0; i < p.size(); i++) {
        cout << "p[" << i << "]: " << p[i] << ", ";
    }
    cout << endl;
}

//������� ������ ������ n ����������
void print(vector <int> p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << i << ": " << p[i] << endl;
    }
    cout << endl;
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
    cout << "p:" << endl;
    print(p);
//
//    //����������� �������� �1
//    random_shuffle(p.begin(), p.end(), pointer_to_unary_function<int, int>(Rand));
//
//    print(p);

//    //������ ������������� ��������
//    for (int i = 0; i < p.size() - 1; i++) {
//        int n = p[i];
//        int count = count_if(p.begin(), p.end(), [n](int elem){return elem == n;});
//        if (count > 1) {
//            p.erase(remove_if(p.begin() + i + 1, p.end(), [n](int elem){return elem == n;}), p.end());
//        }
//    }
//
//    print(p);

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

//    //����� � ������� �������� �������
//    for_each(p.begin(), p.end(), make_sqr);
//    print(p);

    vector <int> p2(p.size());
    int r2 = 0;
    for (size_t i = 0; i < p.size(); i++) {
        srand(time(0) * r2++ * 7);
        p2[i] = rand() % 10;
    }
    cout << "p2:" << endl;
    print(p2);

    //�������� ����� ��������� �2
//    int res = accumulate(p2.begin(), p2.end(), 0, [](int sum, int elem){return sum += elem;});
//    cout << "Summ p2: " << res << endl;

//    //������� �������� ������������� ���������� ��������� �2 �� 1
//    cout << "How many new elements do you want to replace with 1: ";
//    int h;
//    cin >> h;
//
//    print(p2);

    //�������� �3 ��� ���������-������������� �������� �1 � �2
    sort(p.begin(), p.end());
    sort(p2.begin(), p2.end());

    vector <int> p3(p.size());
	cout << "set_difference(): ";
	set_difference(p.cbegin(), p.cend(), p2.cbegin(), p2.cend(), p3.begin());
	cout << endl;

    cout << "p3 is:" << endl;
    print(p3);

    //������ ���� ��������� ������������� ��������� ����
    for_each(p3.begin(), p3.end(), replace_0);
    cout << "p3 after replacing negative elements with 0:" << endl;
    print(p3);

    //�������� ���� ������� ��������� �� �3
    p3.erase(remove_if(p3.begin(), p3.end(), [](int elem){return elem == 0;}), p3.end());
    cout << "p3 without 0:" << endl;
    print(p3);

    //��������� ������� ���������� � �3 (�.�. ����� ��������� �3 �1 � �2 ���� ������� �������������, � ����� �� �3 ����
    //������� ��� ������� ��������, �� �3 ���������� ��������������� �� �����������, �������������� ��� "��������������"
    //���������� ������������� � �� ��������
    sort(p3.begin(), p3.end(), [](int elem_1, int elem_2){return elem_1 > elem_2;});
    cout << "p3 after reflection:" << endl;
    print(p3);

    //����� ���������� ��� ��������� �3 (�.�. ����� ��������� �3 �1 � �2 ���� ������� �������������, � ����� �� �3 ����
    //������� ��� ������� ��������, � ��������� ���������� �� �������, �� ����������� ����� ���������� �������� ��������
    //3 ������ �������� �3)
    cout << "p3 top 3 elements:" << endl;
    print(p3, 3);

    //���������� �1 � �2 �� �����������
    cout << "Sorted p and p2" << endl;
    sort(p.begin(), p.end());
    sort(p2.begin(), p2.end());
    cout << "p after sort: " << endl;
    print(p);
    cout << "p2 after sort: " << endl;
    print(p2);

    //�������� �4 �������� �1 � �2
    vector<int> p4(p.size() + p2.size());
    merge(p.begin(), p.end(), p2.begin(), p2.end(), p4.begin());
    cout << "p4: " << endl;
    print(p4);

    //��������� �������� ��� ������������� ������� 1 � �4
    cout << "Span's lenght: ";
    sort(p4.begin(), p4.end());
    int d = count_if(p4.begin(), p4.end(), [](int elem){return elem < 2 && elem > 0;});
    cout << d << endl;

    //����� ���� � �� �����
    cout << "p: " << endl;
    print(p);
    cout << "p2: " << endl;
    print(p2);
    cout << "p3: " << endl;
    print(p3);
    cout << "p4: " << endl;
    print(p4);

    return 0;
}
