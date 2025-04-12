#include <iostream>
#include <cstdlib>
#include <ctime>

// Шаблон класу для елементу списку
template <typename T>
class Node {
public:
    T data;          // Дані елементу
    Node* next;      // Вказівник на наступний елемент

    Node(T value) : data(value), next(nullptr) {} // Конструктор
};

// Шаблон класу для однозв'язного списку
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Голова списку

public:
    LinkedList() : head(nullptr) {} // Конструктор

    // Додавання елементу в кінець списку
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Виведення всіх елементів списку
    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Генерація випадкових чисел і додавання до списку
    void generateRandomList() {
        std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел

        // Генеруємо кількість елементів списку від 5 до 15
        int size = 5 + std::rand() % 11;  // Генерація випадкового числа від 5 до 15

        // Генеруємо мінімальне та максимальне значення для випадкових чисел
        int min = std::rand() % 20 + 1;  // Мінімальне значення від 1 до 20
        int max = std::rand() % 80 + 20; // Максимальне значення від 20 до 100

        std::cout << "Кількість елементів: " << size << std::endl;
        std::cout << "Мінімальне значення: " << min << std::endl;
        std::cout << "Максимальне значення: " << max << std::endl;

        // Генерація випадкових чисел і додавання їх до списку
        for (int i = 0; i < size; i++) {
            T randomValue = min + std::rand() % (max - min + 1); // Генерація випадкового числа
            append(randomValue);
        }
    }
};


int main() {
	setlocale(LC_ALL, "Ukrainian"); 
    int choice;
    std::cout << "Виберіть дію:\n1. Ввести числа вручну\n2. Згенерувати випадкові числа\n";
    std::cin >> choice;

    if (choice == 1) {
        LinkedList<int> list;

        int size;
        std::cout << "Введіть кількість елементів: ";
        std::cin >> size;

        for (int i = 0; i < size; i++) {
            int value;
            std::cout << "Введіть елемент #" << i + 1 << ": ";
            std::cin >> value;
            list.append(value); // Додаємо елемент в список
        }

        std::cout << "Список: ";
        list.display(); // Виводимо список

    }
    else if (choice == 2) {
        LinkedList<int> list;

        // Генерація випадкових чисел
        list.generateRandomList(); // Програма автоматично генерує кількість елементів і діапазон чисел

        std::cout << "Список (випадкові числа): ";
        list.display(); // Виводимо список
    }
    else {
        std::cout << "Невірний вибір!\n";
    }

    return 0;
}
