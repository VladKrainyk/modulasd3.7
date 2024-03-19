#include <iostream>
#include <cstdlib>
#include <ctime>

// Функція для виводу масиву
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функція для сортування методом сортування Шелла
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    // Встановлення генератора випадкових чисел
    srand(time(NULL));

    // Введення розміру масиву
    int size;
    std::cout << "Введіть розмір масиву (непарне число): ";
    std::cin >> size;

    // Перевірка на непарне число
    if (size % 2 == 0) {
        std::cerr << "Розмір масиву має бути непарним!" << std::endl;
        return 1;
    }

    // Створення масиву та його заповнення випадковими числами
    int* arr = new int[size];
    std::cout << "Випадковий масив: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Генеруємо випадкові числа в діапазоні від 0 до 99
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Сортування масиву методом сортування Шелла
    shellSort(arr, size);

    // Виведення відсортованого масиву
    std::cout << "Відсортований масив: ";
    printArray(arr, size);

    // Звільнення пам'яті, що була виділена для масиву
    delete[] arr;

    return 0;
}


