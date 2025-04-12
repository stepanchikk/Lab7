#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeFirst() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* startNode) : current(startNode) {}

        bool hasNext() {
            return current != nullptr;
        }

        T next() {
            if (current) {
                T value = current->data;
                current = current->next;
                return value;
            }
            throw std::out_of_range("No more elements");
        }
    };

    Iterator getIterator() {
        return Iterator(head);
    }

    bool isEmpty() {
        return head == nullptr;
    }

    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
	setlocale(LC_ALL, "ukrainian"); // Встановлення української локалі для виводу
    // Ініціалізація генератора випадкових чисел
    std::srand(std::time(0));

    LinkedList<int> list;
    int choice, numElements, inputValue;

    std::cout << "Вибір способу введення даних:\n";
    std::cout << "1. Ручне введення\n";
    std::cout << "2. Випадкові числа\n";
    std::cout << "Ваш вибір (1 або 2): ";
    std::cin >> choice;

    std::cout << "Кількість елементів: ";
    std::cin >> numElements;

    if (choice == 1) {
        // Ручне введення елементів
        std::cout << "Введіть " << numElements << " елементів:\n";
        for (int i = 0; i < numElements; ++i) {
            std::cout << "Елемент " << (i + 1) << ": ";
            std::cin >> inputValue;
            list.append(inputValue);
        }
    }
    else if (choice == 2) {
        // Додавання випадкових чисел
        for (int i = 0; i < numElements; ++i) {
            list.append(std::rand() % 100);  // Генерація випадкових чисел від 0 до 99
        }
        std::cout << "Випадкові числа додано в список.\n";
    }
    else {
        std::cout << "Невірний вибір!\n";
        return 1;
    }

    std::cout << "Список після додавання елементів: ";
    list.display();

    // Тестування ітератора
    LinkedList<int>::Iterator it = list.getIterator();
    std::cout << "Прохід по елементах списку: ";
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << std::endl;

    char continueChoice;
    do {
        // Видалення першого елементу та перевірка результату
        list.removeFirst();
        std::cout << "Список після видалення першого елементу: ";
        list.display();

        // Перевірка, чи список порожній
        if (list.isEmpty()) {
            std::cout << "Список порожній. Програма завершується.\n";
            break;
        }

        // Запит на продовження
        std::cout << "Хочете продовжити видалення елементів? (y/n): ";
        std::cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
