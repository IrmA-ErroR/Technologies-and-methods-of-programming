// TMP_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>

using namespace std;

class Queue {
    static const int SIZE = 100;
    int* queue;
    int data;
    int frnt, rear;
public:
    Queue();
    void push(int num);
    void out();
    int size();
    void pop();
    int front();
    int back();
    void sort();
};
//Конструктор
Queue::Queue() {
    queue = new int[SIZE];
    frnt = rear = 0;
}
//Вывод элементов очереди
void Queue::out() {
    for (int i = frnt + 1;i < rear + 1;i++)
        cout << " " << queue[i];
}
//Помещение элемента в очередь
void Queue::push(int num) {
    if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
        cout << "очередь полна" << endl;
        return;
    }
    rear++;
    if (rear == SIZE) rear = 0;
    queue[rear] = num;
}
// Извлечение элемента из очереди
void Queue::pop() {
    if (frnt == rear) {
        cout << "очередь пуста" << endl;
        return;
    }
    frnt++;
    if (frnt == SIZE) frnt = 0;
}
//Определение размера очереди
int Queue::size() {
    int s = 0;
    for (int i = frnt; i < rear; i++)
        s++;
    return s;
}
// Последний элемент очереди
int Queue::back() {
    return queue[rear];
}
// Первый элемент очереди
int Queue::front() {
    return queue[frnt + 1];
}

void Queue::sort()
{
    int min, max, index, len, x; // х - первое значение в списке
    int size = SIZE;
    min = max = x;
    for (int i = frnt + 1;i < rear + 1;i++)
    {
        if (x < min)
        {
        min = x;
        }
        if (x > max)
        {
            max = x;
        }
    }
    cout << "min - " << min << "; max - " << max << endl;
    len = max - min + 1;

    int* temp = new int[len]();

    for (int i = frnt + 1;i < rear + 1;i++)
    {
        temp[i] = 0;
        cout << temp[i] << endl;
    }
    for (int i = frnt + 1;i < rear + 1;i++)
    {
        index = x - min;
        temp[index] += 1;
    }
    for (int i = len; i > -1; i--)
    {
        size -= temp[i];
        temp[i] = size;
        cout << temp[i] << endl;
    }
    
}
int main() {
    Queue queue1;
    int i;
    system("chcp 1251");
    system("cls");
    for (i = 1; i <= 5; i++)
        queue1.push(i);
    cout << "Изначальная очередь ";
    queue1.out();
    cout << endl;
    cout << "введите еще элемент: ";
    cin >> i;
    queue1.push(i);
    cout << "теперь очередь имеет следующий вид" << endl;
    queue1.out();
    cout << endl << "Размер очереди:" << endl;
    cout << queue1.size();
    cout << endl << "последний элемент:" << endl;
    cout << queue1.back();
    cout << endl << "первый элемент" << endl;
    cout << queue1.front();
    cout << endl << "удаление элемента";
    queue1.pop();
    cout << endl << "текущие данные";
    queue1.out();
    cout << endl << "еще одно добавление элемента";
    queue1.push(i);
    queue1.out();
    cout << endl;
    cin.get(); cin.get();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
