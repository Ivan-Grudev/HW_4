#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    vector <int> p(10);
    int r = 0;
    for (int i = 0; i < 10; i++) {
        srand(time(0) * r++ * 7);
        p[i] = rand() % 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << p[i] << endl;
    }


    return 0;
}
