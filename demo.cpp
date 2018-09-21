#include "1DArray.hpp"

int main()
{
    // Test
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

    // v2
    int mul = a2.arrMul();

    cout << endl << endl << "Multiplication of elements (object a2) is: " << mul << endl;


    int index = a3.arrFind(5);
    if( index >= 0 )
        cout << endl << "Element has been found. Index is: " << index << endl;
    else
        cout << endl << "Requested element hasn't found in array!" << endl;

    // Object a2
    int i = a2.arrFind(3);
    if( i >= 0 )
        cout << endl << "Element has been found. Index is: " << i << endl;
    else
        cout << endl << "Requested element hasn't found in array!" << endl;


    return 0;
}
