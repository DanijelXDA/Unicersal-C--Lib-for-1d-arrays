#include "1DArray.hpp"

int main()
{
    int niz[5] = {1, 5, 2, 3, 4};
    double nizDouble[3] = {5.555, 4.52222, 10.01};

    Array <int>a1;
    Array <int>a2(niz, 5);
    Array <double>a3(nizDouble, 3);

    cout << "a1: " << endl;
    cout << a1 << endl;

    cout << "a2: " << endl;
    cout << a2 << endl;

    cout << "a3: " << endl;
    cout << a3 << endl;

    int *sorted = a2.arrSort();

    int sum = a2.arrSum();

    cout << "Sorted array looks: " << endl;
    for(int i = 0; i < a2.getArraySize(); ++i) {
        cout << "\tarr[" << i << "] = " << sorted[i] << " " << endl;
    }

    cout << endl << endl << "Sum of elements (object a2) is: " << sum << endl;

    return 0;
}
