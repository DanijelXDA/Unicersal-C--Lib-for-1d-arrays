///////////////////////////////////////////
/* The C++ library with primary methods  */
/* For manipulating with one dimensional */
/*              array                    */
/*          Author: Danijel Jovanovic    */
/*          Date: 22/06/2018             */
///////////////////////////////////////////

#ifndef ONEDARRAY_HPP_INCLUDED
#define ONEDARRAY_HPP_INCLUDED

#include <iostream>
using namespace std;

// class definition for 1D Array

template<class T>
class Array {
    private:
        T *pArr;
        int arrSize;
    public:
        Array() { // Empty constructor definition
            pArr = NULL; // Not initialized yet
            arrSize = 0; // By default array has 0 elements
        }

        Array(T *arrF, int arrSize) { // Constructor with parameters
            this -> arrSize = arrSize; // Setting private field of class with forwarded parameter
            pArr = new T[arrSize]; // Dynamic allocation for elements of array

            for(int i = 0; i < arrSize; ++i)
               pArr[i] = arrF[i]; // Setting array from class with forwarded array
        }

        ~Array(void) { // Destructor which free ups dynamically allocated memory and sets the size of array with 0
            arrSize = 0;
            delete []pArr;
        }

        int getArraySize(void) { // Method which returns array size
            return arrSize;
        }

        T *getFirstElementOfArray(void) { // Method which returns the address of first element of array
            return pArr;
        }

        bool setArraySize(int newSize) { // Method which sets new array size
            bool success = false;

            if(newSize > 1) {
                arrSize = newSize;
                success = true;
            } else {
                arrSize = 0;
            }
            return success;
        }

        T *arrSort(void) {
            T *temp = new T[arrSize];

            for(int i = 0; i < arrSize; ++i) // Rewriting elements of array
                *(temp + i) = *(pArr + i);

            // Sorting elements of array (from lower to higher value)
            for(int i = 0; i < arrSize - 1; ++i) {
                for(int j = i + 1; j < arrSize; ++j) {
                    if( temp[i] > temp[j] ) {
                        T n = temp[i];
                        temp[i] = temp[j];
                        temp[j] = n;
                    }
                }
            }
            return temp;
        }

        // Method which calculates sum of elements in array
        T arrSum(void) {
            T sum = 0;

            for(int i = 0; i < arrSize; ++i) // Rewriting elements of array
                sum += *(pArr + i);

            return sum;
        }

        // Method which calculates multiplication of elements in array
        T arrMul(void) {
            T mul = 1;

            for(int i = 0; i < arrSize; ++i) // Rewriting elements of array
                mul *= *(pArr + i);

            return mul;
        }

        // Redefining << operator
        friend ostream& operator<<(ostream& out, const Array &a) {
            if(a.arrSize == 0) {
                out << "Array has no elements..." << endl;
            } else {
                out << "Array looks: " << endl;

                for(int i = 0; i < a.arrSize; i++)
                    out << "\tarr[" << i << "] = " << a.pArr[i] << " " << endl;
            }
            return out;
        }

};

#endif // 1DARRAY_HPP_INCLUDED
