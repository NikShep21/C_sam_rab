#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для освобождения памяти
void freeMemory(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

// Функция для заполнения массива случайными числами
// Мы это еще не проходили, но я хотел сделать случайное заполнение, поэтому посмотрел в интернете
void fillArrayRandom(int** array, int rows, int cols) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100; 
        }
    }
}

// Поиск точки
bool isSaddlePoint(int** array, int rows, int cols, int row, int col) {
    int value = array[row][col];

   
    for (int j = 0; j < cols; ++j) {
        if (array[row][j] < value)
            return false;
    }

    
    for (int i = 0; i < rows; ++i) {
        if (array[i][col] > value)
            return false;
    }

    return true;
}

// Функция для вывода массива
void printArray(int** array, int rows, int cols) {
    cout << "Массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int m, n;

    cout << "Введите количество строк m: ";
    cin >> m;
    cout << "Введите количество столбцов n: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Размеры массива должны быть положительными числами" << endl;
        return 1;
    }

  
    int** A = new int*[m];
    for (int i = 0; i < m; ++i) {
        A[i] = new int[n];
    }

    
    cout << "Заполнить массив случайными числами? (1 - да, 0 - нет): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        fillArrayRandom(A, m, n);
        printArray(A, m, n); 
    } else {
        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }
    }
      //поиск точки
     for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isSaddlePoint(A, m, n, i, j)) {
                cout << "Седловая точка найдена на позиции: строка " << i + 1
                     << ", столбец " << j + 1 << endl;

                
                freeMemory(A, m);
                return 0;
            }
        }
    }

    cout << "0" << endl;

    freeMemory(A, m);
    return 0;
}
