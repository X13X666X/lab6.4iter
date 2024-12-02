#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Функція для виведення масиву
void PrintArray(const double* array, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << setw(8) << array[i] << " ";
    }
    cout << endl;
}

// Функція для підрахунку кількості нульових елементів
int CountZeroElements(const double* array, const int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0.0) {
            ++count;
        }
    }
    return count;
}

// Функція для обчислення суми елементів після мінімального
double SumAfterMin(const double* array, const int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }

    double sum = 0;
    for (int i = minIndex + 1; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

// Функція для впорядкування непарних індексів за зростанням модулів
void SortOddIndicesByAbs(double* array, const int size) {
    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (abs(array[j]) < abs(array[i])) {
                // Переставляємо значення без swap
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    double* array = new double[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << "Original array: " << endl;
    PrintArray(array, n);

    int zeroCount = CountZeroElements(array, n);
    cout << "Number of zero elements: " << setw(8) << zeroCount << endl;

    double sum = SumAfterMin(array, n);
    cout << "Sum of elements after the minimum: " << setw(8) << sum << endl;

    SortOddIndicesByAbs(array, n);
    cout << "Array after sorting odd indices by absolute values: " << endl;
    PrintArray(array, n);

    delete[] array;
    return 0;
}