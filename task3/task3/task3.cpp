#include <iostream>  
#include <cstdlib>  
#include <ctime>     

// Шаблон класу для вузла списку
template <typename T>
class Node {
public:
    T data;          // Дані вузла
    Node* next;      // Вказівник на наступний вузол

    // Конструктор: встановлює значення та вказівник на наступний елемент як nullptr
    Node(T value) : data(value), next(nullptr) {}
};

// Шаблон класу для однозв'язного списку
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Вказівник на перший елемент списку

public:
    // Конструктор: створює порожній список
    LinkedList() : head(nullptr) {}

    // Додавання елементу в кінець списку
    void append(T value) {
        Node<T>* newNode = new Node<T>(value); // створюємо новий вузол
        if (!head) {
            head = newNode; // якщо список порожній — це перший елемент
        } else {
            Node<T>* temp = head;
            while (temp->next) {  // йдемо до останнього вузла
                temp = temp->next;
            }
            temp->next = newNode; // додаємо вузол в кінець
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
        int size = 5 + std::rand() % 11;

        // Генеруємо мінімальне та максимальне значення
        int min = std::rand() % 20 + 1;   // від 1 до 20
        int max = std::rand() % 80 + 20;  // від 20 до 100

        // Виводимо інформацію
        std::cout << "Кількість елементів: " << size << std::endl;
        std::cout << "Мінімальне значення: " << min << std::endl;
        std::cout << "Максимальне значення: " << max << std::endl;

        // Генерація і додавання чисел до списку
        for (int i = 0; i < size; i++) {
            T randomValue = min + std::rand() % (max - min + 1);
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
        LinkedList<int> list; // створюємо список

        int size;
        std::cout << "Введіть кількість елементів: ";
        std::cin >> size;

        // Ручне введення елементів
        for (int i = 0; i < size; i++) {
            int value;
            std::cout << "Введіть елемент #" << i + 1 << ": ";
            std::cin >> value;
            list.append(value);
        }

        std::cout << "Список: ";
        list.display(); // Вивід списку
    } else if (choice == 2) {
        LinkedList<int> list; // створюємо список

        list.generateRandomList(); 

        std::cout << "Список (випадкові числа): ";
        list.display(); // Вивід
    } else {
        std::cout << "Невірний вибір!\n";
    }

    return 0; 
}
