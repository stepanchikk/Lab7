#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Шаблонна функція сортування методом Шелла
template <typename T>
void shellSort(T arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i]; //Зберігаємо поточний елемент
            int j; //Змінна для внутрішнього циклу
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; //Зсуваємо більший елемент вперед
            }
            arr[j] = temp;
        }
    }
}

// Функція для виведення масиву
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція для введення масиву з клавіатури
template <typename T>
void inputArray(T arr[], int size) {
    cout << "Введіть " << size << " елементів: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Функція для генерації випадкових чисел
void generateRandomNumbers(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

// Функція для генерації випадкових рядків
void generateRandomStrings(string arr[], int size, int strLength) {
    const string chars = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < size; i++) {
        string s;
        for (int j = 0; j < strLength; j++) {
            s += chars[rand() % chars.length()];
        }
        arr[i] = s;
    }
}

// Головне меню
int main() {
	setlocale(LC_ALL, "Ukrainian"); 
    srand(time(0)); 

    int choice, size;
    cout << "1. Сортування чисел\n2. Сортування рядків\nВиберіть тип даних: ";
    cin >> choice;

    cout << "Введіть кількість елементів: ";
    cin >> size;

    int dataType;
    cout << "\n1. Ввести дані вручну\n2. Згенерувати випадкові дані\nВиберіть спосіб: ";
    cin >> dataType;

    if (choice == 1) { // Для чисел
        int* numbers = new int[size];

        if (dataType == 1) {
            inputArray(numbers, size);
        }
        else {
            int min, max;
            cout << "Введіть мінімальне значення: ";
            cin >> min;
            cout << "Введіть максимальне значення: ";
            cin >> max;
            generateRandomNumbers(numbers, size, min, max);
        }

        cout << "\nДо сортування: ";
        printArray(numbers, size);

        shellSort(numbers, size);

        cout << "Після сортування: ";
        printArray(numbers, size);

        delete[] numbers;
    }
    else { // Для рядків
        string* words = new string[size];

        if (dataType == 1) {
            cout << "Введіть " << size << " рядків:\n";
            for (int i = 0; i < size; i++) {
                cout << i + 1 << ": ";
                cin >> words[i];
            }
        }
        else {
            int strLength;
            cout << "Введіть довжину рядків: ";
            cin >> strLength;
            generateRandomStrings(words, size, strLength);
        }

        cout << "\nДо сортування: ";
        printArray(words, size);

        shellSort(words, size);

        cout << "Після сортування: ";
        printArray(words, size);

        delete[] words;
    }

    return 0;
}
