#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Рекурсивна функція для створення матриці з випадковими елементами у заданому діапазоні
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0) {
    if (i >= rowCount) return; // умова виходу з рекурсії по рядках
    a[i][j] = Low + rand() % (High - Low + 1);

    if (j + 1 < colCount)
        Create(a, rowCount, colCount, Low, High, i, j + 1);  // наступний елемент в рядку
    else
        Create(a, rowCount, colCount, Low, High, i + 1, 0);  // перехід на наступний рядок
}

// Рекурсивна функція для виведення матриці у форматі таблиці
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i >= rowCount) return; // умова виходу з рекурсії по рядках

    cout << setw(4) << a[i][j];
    if (j + 1 < colCount)
        Print(a, rowCount, colCount, i, j + 1);  // наступний елемент в рядку
    else {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);  // перехід на наступний рядок
    }
}

// Рекурсивна функція для обміну рядків матриці
void Change(int** a, const int row1, const int row2, const int colCount, int j = 0) {
    if (j >= colCount) return; // умова виходу з рекурсії по стовпцях

    int tmp = a[row1][j];
    a[row1][j] = a[row2][j];
    a[row2][j] = tmp;
    Change(a, row1, row2, colCount, j + 1); // обмін наступного елемента в рядку
}

// Функція для сортування рядків матриці за умовами (не рекурсивна для спрощення)
void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++)
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
            if ((a[i1][0] > a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][3] < a[i1 + 1][3]))
                Change(a, i1, i1 + 1, colCount);
}

// Рекурсивна функція для обчислення суми та кількості елементів, що відповідають критерію
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0) {
    if (i >= rowCount) return; // умова виходу з рекурсії по рядках

    if (a[i][j] % 2 != 0 || a[i][j] >= 0) {  // критерій: непарні або невід'ємні
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    if (j + 1 < colCount)
        Calc(a, rowCount, colCount, S, k, i, j + 1);  // наступний елемент в рядку
    else
        Calc(a, rowCount, colCount, S, k, i + 1, 0);  // перехід на наступний рядок
}

int main() {
    srand((unsigned)time(NULL));
    const int Low = -12;        // мінімальне значення для генератора
    const int High = 23;        // максимальне значення для генератора
    const int rowCount = 7;     // кількість рядків матриці
    const int colCount = 6;     // кількість стовпців матриці

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Створення та виведення початкової матриці
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial Matrix:" << endl;
    Print(a, rowCount, colCount);

    // Сортування рядків матриці за умовами
    Sort(a, rowCount, colCount);
    cout << "Sorted Matrix:" << endl;
    Print(a, rowCount, colCount);

    // Обчислення кількості та суми елементів за критерієм та заміна на нулі
    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "Modified Matrix (with zeroed elements):" << endl;
    Print(a, rowCount, colCount);

    // Виведення результатів
    cout << "Sum (S) = " << S << endl;
    cout << "Count (k) = " << k << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
