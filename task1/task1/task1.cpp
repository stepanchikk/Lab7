#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Шаблони для int і double
template <typename T>
T minValue(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// Функції для char*
const char* minValueStr(const char* a, const char* b) {
    return (strcmp(a, b) < 0) ? a : b;
}

const char* maxValueStr(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// Випадкові значення
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double getRandomDouble(double min, double max) {
    return min + (rand() / (double)RAND_MAX) * (max - min);
}

int main() {
	setlocale(LC_ALL, "ukr"); // Встановлюємо українську локаль
    srand(static_cast<unsigned int>(time(nullptr)));

    int mode;
    cout << "Виберіть режим (0 - ручне введення, 1 - випадкові дані): ";
    cin >> mode;

    // ==== int ====
    int a, b;
    if (mode) {
        a = getRandomInt(0, 100);
        b = getRandomInt(0, 100);
    }
    else {
        cout << "\nВведіть два цілі числа: ";
        cin >> a >> b;
    }
    cout << "[int] Мін: " << minValue(a, b) << ", Макс: " << maxValue(a, b) << endl;

    // ==== double ====
    double x, y;
    if (mode) {
        x = getRandomDouble(0.0, 100.0);
        y = getRandomDouble(0.0, 100.0);
    }
    else {
        cout << "\nВведіть два дробові числа: ";
        cin >> x >> y;
    }
    cout << "[double] Мін: " << minValue(x, y) << ", Макс: " << maxValue(x, y) << endl;

    // ==== char* ====
    char str1[100], str2[100];
    if (mode) {
        strcpy_s(str1, "apple");
        strcpy_s(str2, "banana");
    }
    else {
        cout << "\nВведіть два рядки: ";
        cin >> str1 >> str2;
    }
    cout << "[char*] Мін: " << minValueStr(str1, str2) << ", Макс: " << maxValueStr(str1, str2) << endl;

    return 0;
}
