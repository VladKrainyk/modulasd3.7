#include <iostream>
#include <cstdlib>
#include <ctime>

// ������� ��� ������ ������
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ������� ��� ���������� ������� ���������� �����
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
    // ������������ ���������� ���������� �����
    srand(time(NULL));

    // �������� ������ ������
    int size;
    std::cout << "������ ����� ������ (������� �����): ";
    std::cin >> size;

    // �������� �� ������� �����
    if (size % 2 == 0) {
        std::cerr << "����� ������ �� ���� ��������!" << std::endl;
        return 1;
    }

    // ��������� ������ �� ���� ���������� ����������� �������
    int* arr = new int[size];
    std::cout << "���������� �����: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // �������� �������� ����� � ������� �� 0 �� 99
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // ���������� ������ ������� ���������� �����
    shellSort(arr, size);

    // ��������� ������������� ������
    std::cout << "³����������� �����: ";
    printArray(arr, size);

    // ��������� ���'��, �� ���� ������� ��� ������
    delete[] arr;

    return 0;
}


