#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int* generateArray(int size, int min, int max, int* array, int index) {
    if (index >= size) {
        return array;
    }
    array[index] = rand() % (max - min + 1) + min;
    return generateArray(size, min, max, array, index + 1);
}

int calcSumOfOdd(int array[], int size, int index) {
    if (index >= size) {
        return 0;
    }
    if (index % 2 != 0) {
        return array[index] + calcSumOfOdd(array, size, index + 1);
    }
    return calcSumOfOdd(array, size, index + 1);
}

int calcFirstNegative(int array[], int size, int index) {
    if (index >= size) {
        return -1;
    }
    if (array[index] < 0) {
        return index;
    }
    return calcFirstNegative(array, size, index + 1);
}

int calcLastNegative(int array[], int size, int index, int lastNegativeIdx) {
    if (index >= size) {
        return lastNegativeIdx;
    }
    if (array[index] < 0) {
        lastNegativeIdx = index;
    }
    return calcLastNegative(array, size, index + 1, lastNegativeIdx);
}

int calcSumBetweenNeg(int array[], int firstNegativeIdx, int lastNegativeIdx, int sum, int index) {
    if (index >= firstNegativeIdx && index <= lastNegativeIdx) {
        sum += array[index];
    }
    if (index >= lastNegativeIdx) {
        return sum;
    }
    return calcSumBetweenNeg(array, firstNegativeIdx, lastNegativeIdx, sum, index + 1);
}

void compressArray(int array[], int size, int index, int newIndex) {
    if (index >= size) {
        for (int i = newIndex; i < size; i++) {
            array[i] = 0;
        }
        return;
    }
    if (abs(array[index]) > 1) {
        array[newIndex] = array[index];
        compressArray(array, size, index + 1, newIndex + 1);
    }
    else {
        compressArray(array, size, index + 1, newIndex);
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int n;
    cout << "n = ";
    cin >> n;
    int* array = generateArray(n, -5, 5, new int[n], 0);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << array[i] << " ";
    }
    cout << endl;

    cout << "sum of elements with odd indices: " << calcSumOfOdd(array, n, 1) << endl;

    int firstNeg = calcFirstNegative(array, n, 0);
    if (firstNeg != -1) {
        int lastNeg = calcLastNegative(array, n, 0, -1);
        cout << "the sum of elements between the first and last negative elements: " << calcSumBetweenNeg(array, firstNeg, lastNeg, 0, 0) << endl;
    }
    else {
        cout << "-" << endl;
    }

    compressArray(array, n, 0, 0);

    cout << "modified array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}
