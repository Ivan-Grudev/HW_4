#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <random>

using namespace std;

//���������� (���������� � ��������� �� 0 �� n)
random_device rd;
mt19937 gen(rd());
mt19937 gen_2(rd());
uniform_int_distribution<> dist(1,10);
uniform_int_distribution<> dist_2(0,10);

int Rand(int n)
{
    return dist(gen);
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
        cout << "p[" << i + 1 << "]: " << p[i];
        if (i < p.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

//������� ������ ������ n ����������
void print(vector <int> p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << i + 1 << ": " << p[i] << endl;
    }
    cout << endl;
}

int main()
{

    //������ ���-�� �1
    vector <int> p(10);
    iota(p.begin(), p.end(), 1);
    cout << "p is created: ";
    print(p);
    cout << endl;

    //�������� �������� � �1 ����� cin
    cout << "How many new elements do you want to add: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Input new element: ";
        cin >> x;
        p.push_back(x);
    }

//    cout << "size =  " << p.size() << endl;
    cout << "p after adding " << n << "new elements: ";
    print(p);
    cout << endl;

    //����������� �������� �1
    random_shuffle(p.begin(), p.end(), pointer_to_unary_function<int, int>(Rand));
    cout << "p after random_shuffle function: ";
    print(p);

    //������ ������������� ��������
    for (size_t i = 0; i < p.size() - 1; i++) {
        int n = p[i];
        int count = count_if(p.begin(), p.end(), [n](int elem){return elem == n;});
        if (count > 1) {
            p.erase(remove_if(p.begin() + i + 1, p.end(), [n](int elem){return elem == n;}), p.end());
        }
    }
    cout << "p after deleting all repeated elements: ";
    print(p);
    cout << endl;

    //����������� ������ ��������
    int c = count_if(p.begin(), p.end(), [](int elem){return elem % 2 != 0;});
    cout << "Amount of uneven elements: " << c << endl;

    //����� ������������ � ����������� �������� �������
    cout << "Max element: " << *max_element(p.begin(), p.end()) << ", Min element: " << *min_element(p.begin(), p.end()) << endl;

    //����� ������ ������� ������� �������
    auto it = find_if(p.begin(), p.end(), simple);
    cout << "first simple element: " << *it << endl;

    //����� � ������� �������� �������
    for_each(p.begin(), p.end(), make_sqr);
    cout << "p after make_sqr function: ";
    print(p);
    cout << endl;

    vector <int> p2(p.size());
    int r2 = 0;
    for (size_t i = 0; i < p.size(); i++) {
        p2[i] = dist_2(gen_2);
    }
    cout << "p2 is created: ";
    print(p2);
    cout << endl;

    //�������� ����� ��������� �2
    int res = accumulate(p2.begin(), p2.end(), 0, [](int sum, int elem){return sum += elem;});
    cout << "Summ of p2 elements: " << res << endl;

    //������� �������� ������������� ���������� ��������� �2 �� 1
    cout << "How many new elements do you want to replace with 1: ";
    int h;
    cin >> h;
    for_each(p2.begin(), p2.begin() + h, replace_1);
    cout << "p2 after replace_1 function: ";
    print(p2);
    cout << endl;

    //�������� �3 ��� ���������-������������� �������� �1 � �2
    sort(p.begin(), p.end());
    sort(p2.begin(), p2.end());

    vector <int> p3(p.size());
	cout << "set_difference(): ";
	set_difference(p.cbegin(), p.cend(), p2.cbegin(), p2.cend(), p3.begin());
    cout << "p3 is created: ";
    print(p3);
	cout << endl;

    //������ ���� ��������� ������������� ��������� ����
    for_each(p3.begin(), p3.end(), replace_0);
    cout << "p3 after replacing negative elements with 0: ";
    print(p3);
    cout << endl;
    //�������� ���� ������� ��������� �� �3
    p3.erase(remove_if(p3.begin(), p3.end(), [](int elem){return elem == 0;}), p3.end());
    cout << "p3 without 0: ";
    print(p3);
    cout << endl;

    //��������� ������� ���������� � �3 (�.�. ����� ��������� �3 �1 � �2 ���� ������� �������������, � ����� �� �3 ����
    //������� ��� ������� ��������, �� �3 ���������� ��������������� �� �����������, �������������� ��� "��������������"
    //���������� ������������� � �� ��������
    sort(p3.begin(), p3.end(), [](int elem_1, int elem_2){return elem_1 > elem_2;});
    cout << "p3 after reflection: ";
    print(p3);
    cout << endl;

    //����� ���������� ��� ��������� �3 (�.�. ����� ��������� �3 �1 � �2 ���� ������� �������������, � ����� �� �3 ����
    //������� ��� ������� ��������, � ��������� ���������� �� �������, �� ����������� ����� ���������� �������� ��������
    //3 ������ �������� �3)
    cout << "p3 top 3 elements: ";
    print(p3, 3);
    cout << endl;

    //���������� �1 � �2 �� �����������
    cout << "Sorted p and p2" << endl;
    sort(p.begin(), p.end());
    sort(p2.begin(), p2.end());
    cout << "p after sort: " << endl;
    print(p);
    cout << endl << "p2 after sort: ";
    print(p2);
    cout << endl;

    //�������� �4 �������� �1 � �2
    vector<int> p4(p.size() + p2.size());
    merge(p.begin(), p.end(), p2.begin(), p2.end(), p4.begin());
    cout << "p4 is created: ";
    print(p4);
    cout << endl;

    //��������� �������� ��� ������������� ������� 1 � �4
    cout << "Span's lenght: ";
    sort(p4.begin(), p4.end());
    int d = count_if(p4.begin(), p4.end(), [](int elem){return elem < 2 && elem > 0;});
    cout << d << endl;

    //����� ���� � �� �����
    cout << "All vectors finally" << endl;

    cout << "p: ";
    print(p);
    cout << endl << "p2: ";
    print(p2);
    cout << endl << "p3: ";
    print(p3);
    cout << endl << "p4: ";
    print(p4);

    return 0;
}
