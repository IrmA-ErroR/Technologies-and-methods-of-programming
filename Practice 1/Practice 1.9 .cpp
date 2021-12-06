#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"


#define LENGTH 10


#define random_input(l,h) (rand() % (h) - (l))

#define LOW (0)
#define HIGH (10)

using namespace std;

struct Node  
{
	int data; //поле данных
	Node* next; // указатель на следующий элемент

	void Set(int x, Node* y) //2
	{
		data = x; //1
		next = y; //1
	}

};

class Queue
{
public:
	Node* first = nullptr; //указатель на первый элемент очереди 
	Node* last = nullptr; // указатель на последний элемент очереди  
	int length = 0; // счетчик длины очереди 
	// Счетчик колличества операций

	unsigned long long int N_op = 0;

	Queue() {}; //конструктор //1
	~Queue() {}; // деструктор //1

	bool empty(); //проверка на пустоту 
	void push_back(int x); //добавление в конец очереди
	void show(); //вывод очереди
	int del(); // удаление последнего элемента
	int get_last(); //вывод последнего элемента

	int Max(); //получение максимума
	int Min(); //получение минимума
	
};

class List : public Queue
{
public:
	int getter(int index); // получение значения по индексу
	void setter(int index, int value); //добавление нового элемента в середину
	void sort(int x, int y); // сортировка

};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Поехали!\n";
	int len = 1;
	int index = 0;
	int value = 0;
	List myL;
	int t_s, t_f;
	while (len > 0) 
	{
		cout << "Вседите длину списка: \n";
		cin >> len;
		srand(time(NULL));
		for (int i = 0; i < len; i++) 
		{
			myL.push_back(random_input(LOW, HIGH)); //заполнение очереди рандомными значениями
		}
		int min = myL.Min();
		int max = myL.Max();
		cout << "Max: " << max << endl;
		cout << "Min: " << min << endl;
		t_s = GetTickCount64();
		myL.sort(min, max);
		t_f = GetTickCount64();
		cout << "Cортировкa: " << index + 1 << " Колличество элементов : " << len << " Время сортировки(ms): " << t_f - t_s << " N_op: " << myL.N_op << endl;
		++index;
	}
		
	
	myL.show();
	cout << "Введите индекс элемента (get): " << endl;
	cin >> index;
	myL.getter(index);
	cout << "Введите индекс нового элемента (set):" << endl;
	cin >> index;
	cout << "Введите новое значение элемента (set): " << endl;
	cin >> value;
	myL.setter(index, value);
	myL.show();
	myL.del();
	myL.show();
	
	return 0;
}

void Queue::show() // вывод очереди 
{
	cout << "Вывод списка" << endl;
	Node* current = first; //1
	int n = 0; //1
	while (current != nullptr && n < length) //
	{
		++n; //1
		current = current->next; //2
	}	
}


bool Queue::empty() //проверка на пустоту //1
{	
	return first == nullptr; //1
}

void Queue::push_back(int x) 
{
	//cout << "Добавление элемента в конец" << endl;
	Node* newItem = new Node; //3
	newItem->Set(x, nullptr); //1+1+2

	if (first == nullptr) //1
	{
		first = newItem; //1
		last = newItem; //1
	}
	else
	{
		last->next = newItem; //2
		last = newItem; //1
	}
	++length; //2
}


int Queue::del() //3+(2+2+1+1+1) = 10
{
	cout << "Удаление" << endl;
	Node* temp; //1
	int date_ = 0; //1
	if (length != 0 ) //1
	{
		temp = first->next; //2
		date_ = first->data; //2
		delete first; //1
		first = temp; //1
		length--; //1
		return date_;
	}
	else
	{
		cout << "Очередь пуста" << endl;
		return 0;
	}

}

int Queue::get_last() //3
{
	cout << "Получение последнего элемента" << endl;
	Node* temp = last; //2
	return temp->data; //1
}

int Queue::Max() //поиск максимума
{
	Node* MNode, * node; //2
	for (MNode = first, node = first->next; node; node = node->next) 
		if (MNode->data < node->data) //3
			MNode = node; //1
	return MNode->data; //1
}
int Queue::Min() //поиск минимума
{
	Node* MNode, * node; //2
	for (MNode = first, node = first->next; node; node = node->next)
		if (MNode->data > node->data) //3
			MNode = node; //1

	return MNode->data; //1

}

void List::sort(int min, int max)
{
	cout << "Сортировка" << endl;
	int min_key = min; //1
	int max_key = max; //1

	int size = max - min + 1; //3
	int* arr = new int[size]; //3
	int* brr = new int[length]; //3
	int length_1 = length;

	for (int i = 0; i < size; i++) //обнуление вспомогательного массива
	{
		arr[i] = 0; //1
	}

	Node* cur = first;
	for (int j = 0; j < length; j++) //подсчет количества различных значений 
	{
		while (cur != nullptr)
		{
			int x = (cur->data) - min_key; //3
			if (x < size) //1
				++arr[x]; //1
			else
				cout << "Ошибка size:" << size << " x: " << x << endl;
			cur = cur->next; //2
		}
	}

	for (int i = size - 1; i >= 0; --i) //вычисление новых индексов
	{
		int y = length_1 - arr[i]; //2
		arr[i] = y; //1
		length_1 = y; //1
	}

	for (int i = 0; i < length; ++i) //обнуление вспомогательного массива 
	{
		brr[i] = 0; //1
	}
	
	cur = first;	//1
	while (cur != nullptr) //копирование data в вспомогательный массив 
	{
		int z = (cur->data) - min_key; //3
		int index = arr[z]; //1
		brr[index] = cur->data; //2
		cur = cur->next; //2
		++arr[z]; //2
	}
	
	cur = first;	//1
	int curSortedItem = 0; //1
	while (cur != nullptr && curSortedItem < length) //перенос data по вычесленным индексам
	{
		cur->data = brr[curSortedItem]; //2
		cur = cur->next; //2

		++curSortedItem; //2
	}
	delete [] brr; //1
	delete [] arr; //1
}

int List::getter(int index) 
{
	if (empty() != 1) //1+1
	{
		Node* node = first; //2
		int size_1 = length; //1
		int value1 = NULL; //1
		if (index <= length) //1
		{	
			for (int i = 1; i < size_1+1; i++)
			{
				if (i == index) //1
				{
					value1 = node->data; //2
					
				}
				node = node->next; //2
			}
			cout << "Значение: " << value1 << endl;
			return value1; //1
		}
		else 
		{ 
			cout << "Неправильный индекс" << endl; 
		}

	}
	else
	{
		cout << "Очередь пуста" << endl;
		return 0; //1
	}
}

void List::setter(int index, int value)
{
	if (empty() != 1) //1
	{
		if (index <= length) //1
		{
			Node* current = first; //2
			Node* newItem = new Node; //3
			for (int i = 1; i < length + 1; i++)
			{
				if (i == index -1) //2
				{
					newItem->next = current->next; //3
					newItem->data = value; //2
					current->next = newItem; //2
					i++; //2
					length++; //2
				}
				current = current->next; //2						
			}
		}
		else
		{
			if (index == length + 1) //2
			{
				push_back(value);
			}				
			else
			{
				for (int i = length + 1; i < index; i++)
				{
					push_back(0);
				}
				push_back(value); 
			}
		}
	}
	else { cout << "Очередь пуста!" << endl;}
}
