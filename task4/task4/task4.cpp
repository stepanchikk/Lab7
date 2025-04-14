#include <iostream>
#include <cstdlib>
#include <ctime>

// Оголошення шаблонного класу Node (Вузол списку)
template <typename T>
class Node {
public:
    T data;    // Дані вузла
    Node* next; // Вказівник на наступний вузол

    // Конструктор для ініціалізації вузла
    Node(T value) : data(value), next(nullptr) {}
};

// Оголошення шаблонного класу LinkedList (Лінійний однозв'язний список)
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Головний вузол (початок списку)

public:
    // Конструктор для ініціалізації порожнього списку
    LinkedList() : head(nullptr) {}

    // Метод для додавання елемента в кінець списку
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);  // Створення нового вузла
        if (!head) { // Якщо список порожній
            head = newNode; // Новий вузол стає головним
            return;
        }
        Node<T>* temp = head;
        while (temp->next) { // Проходимо по списку до останнього елемента
            temp = temp->next;
        }
        temp->next = newNode; // Додаємо новий вузол в кінець списку
    }

    // Метод для видалення першого елемента списку
    void removeFirst() {
        if (!head) return; // Якщо список порожній, нічого не робимо
        Node<T>* temp = head;
        head = head->next; // Зсуваємо голову списку на наступний елемент
        delete temp; // Видаляємо перший елемент
    }

    // Метод для відображення елементів списку
    void display() {
        Node<T>* temp = head;
        while (temp) { // Проходимо по всіх елементах списку
            std::cout << temp->data << " "; // Виводимо значення елемента
            temp = temp->next; // Переходимо до наступного елемента
        }
        std::cout << std::endl;
    }

    // Оголошення класу-ітератора для проходу по списку
    class Iterator {
    private:
        Node<T>* current; // Поточний елемент, по якому проходить ітератор

    public:
        // Конструктор для ініціалізації ітератора на певному вузлі
        Iterator(Node<T>* startNode) : current(startNode) {}

        // Метод для перевірки наявності наступного елемента
        bool hasNext() {
            return current != nullptr; // Повертає true, якщо є наступний елемент
        }

        // Метод для отримання значення наступного елемента
        T next() {
            if (current) { // Якщо є наступний елемент
                T value = current->data; // Зберігаємо значення поточного елемента
                current = current->next; // Переходимо до наступного елемента
                return value; // Повертаємо значення
            }
            throw std::out_of_range("No more elements"); // Викидаємо виняток, якщо елементів більше немає
        }
    };

    // Метод для отримання ітератора
    Iterator getIterator() {
        return Iterator(head); // Повертаємо ітератор, що починається з голови списку
    }

    // Метод для перевірки, чи порожній список
    bool isEmpty() {
        return head == nullptr; // Повертає true, якщо список порожній
    }

    // Деструктор для очищення списку
    ~LinkedList() {
        while (head) { // Поки список не порожній
            Node<T>* temp = head;
            head = head->next; // Переміщаємо голову на наступний елемент
            delete temp; // Видаляємо поточний елемент
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukrainian"); // Встановлення української локалі для виводу

    // Ініціалізація генератора випадкових чисел
    std::srand(std::time(0)); 

    LinkedList<int> list; // Створення об'єкта списку
    int choice, numElements, inputValue;

    // Запит користувача на вибір способу введення даних
    std::cout << "Вибір способу введення даних:\n";
    std::cout << "1. Ручне введення\n";
    std::cout << "2. Випадкові числа\n";
    std::cout << "Ваш вибір (1 або 2): ";
    std::cin >> choice;

    // Запит на кількість елементів
    std::cout << "Кількість елементів: ";
    std::cin >> numElements;

    // Обробка вибору користувача
    if (choice == 1) {
        // Ручне введення елементів
        std::cout << "Введіть " << numElements << " елементів:\n";
        for (int i = 0; i < numElements; ++i) {
            std::cout << "Елемент " << (i + 1) << ": ";
            std::cin >> inputValue;
            list.append(inputValue); // Додаємо елемент у список
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
        return 1; // Завершення програми при невірному виборі
    }

    // Виведення списку після додавання елементів
    std::cout << "Список після додавання елементів: ";
    list.display();

    // Тестування ітератора
    LinkedList<int>::Iterator it = list.getIterator();
    std::cout << "Прохід по елементах списку: ";
    while (it.hasNext()) { // Пройти всі елементи списку
        std::cout << it.next() << " "; // Вивести наступний елемент
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

    return 0; // Завершення програми
}
