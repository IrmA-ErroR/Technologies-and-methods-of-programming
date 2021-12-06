#include <iostream>
#include <cstdlib>
#include <ctime>


#define LENGTH 10


#define random_input(l,h) (rand() % (h) - (l))

#define LOW (0)
#define HIGH (10)

using namespace std;

struct Node  
{
	int data; //поле данных
	Node* next; // указатель на следующий элемент

	void Set(int x, Node* y)
	{
		data = x;
		next = y;
	}

};

class Queue
{
public:
	Node* first = nullptr; //указатель на первый элемент очереди 
	Node* last = nullptr; // указатель на последний элемент очереди
	int length = 0; // счетчик длины очереди

	Queue() {}; //конструктор
	~Queue() {}; // деструктор 

	bool empty(); //проверка на пустоту 
	void push_back(int x); //добавление в конец очереди
	void show(); //вывод очереди
	int del(); // удаление последнего элемента
	int get_last(); //вывод последнего элемента

	int Max(); //получение максимума
	int Min(); //получение минримума
	
};

class List : public Queue
{
public:
	int getter(int index); //функция получения значения по индексу
	void setter(int index, int value); //функция добавление нового элемента в середину
	void sort(int x, int y); //функция сортировки

};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Поехали!\n";
	int len;
	int index = 0;
	int value = 0;
	List myL;
	cout << "Вседите длину списка: \n";
	cin >> len;
	srand(time(NULL));
	for (int i = 0; i < len; i++) 
	{
		myL.push_back(random_input(LOW, HIGH)); //заполнение очереди рандомными значениями
	}
	
	myL.show();
	int min = myL.Min();
	int max = myL.Max();
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	myL.sort(min, max);
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

void Queue::show()
{
	cout << "Вывод списка" << endl;
	Node* current = first;
	int n = 0;
	while (current != nullptr && n < length)
	{
		++n;
		//cout << current << endl;
		cout << n << " " << current->data << endl;
		//cout << current->next << endl;
		//cout << endl;
		current = current->next;
	}	
}


bool Queue::empty() 
{	
	return first == nullptr;
}

void Queue::push_back(int x)
{
	cout << "Добавление элемента в конец" << endl;
	Node* newItem = new Node;
	newItem->Set(x, nullptr);

	if (first == nullptr)
	{
		first = newItem;
		last = newItem;
	}
	else
	{
		last->next = newItem;
		last = newItem;
	}
	++length; 
}


int Queue::del()
{
	cout << "Удаление" << endl;
	Node* temp;
	int date_ = 0;
	if (length != 0 )
	{
		temp = first->next;
		date_ = first->data;
		delete first;
		first = temp;
		length--;
		return date_;
	}
	else
	{
		cout << "Очередь пуста" << endl;
		return 0;
	}

}

int Queue::get_last()
{
	cout << "Получение последнего элемента" << endl;
	Node* temp = last;
	return temp->data;
}

int Queue::Max()
{
	Node* MNode, * node;
	for (MNode = first, node = first->next; node; node = node->next)
		if (MNode->data < node->data)
			MNode = node;
	return MNode->data;
}
int Queue::Min()
{
	Node* MNode, * node;
	for (MNode = first, node = first->next; node; node = node->next)
		if (MNode->data > node->data)
			MNode = node;

	return MNode->data;

}

void List::sort(int min, int max)
{
	cout << "Сортировка" << endl;
	int min_key = min;
	int max_key = max;

	int size = max - min + 1;
	int* arr = new int[size];
	int* brr = new int[length];
	int length_1 = length;

	cout <<  " c1 ";
	for (int i = 0; i < size; i++) //обнуление вспомогательного массива
	{
		arr[i] = 0;
		cout << arr[i] << " ";
	}

	cout << "\n c2" << endl;
	Node* cur = first;
	for (int j = 0; j < length; j++) //подсчет количества различных значений 
	{
		while (cur != nullptr)
		{
			int x = (cur->data) - min_key;
			if (x < size)
				++arr[x];
			else
				cout << "!!! ALARM !!!   size:" << size << " x: " << x << endl;
			cur = cur->next;
		}
	}
	for (int i = 0; i < size; i++) //потом убрать
	{
		cout << "i-" << i << " " << arr[i] << endl;
	}


	cout << " c3"<< endl;
	for (int i = size - 1; i >= 0; --i) //вычисление новых индексов
	{
		int y = length_1 - arr[i];
		arr[i] = y;
		length_1 = y;
		cout << "i-" << i << " " << arr[i] << endl;
	}
	


	cout << " c4" << endl;
	for (int i = 0; i < length; ++i) //обнуление вспомогательного массива 
	{
		brr[i] = 0;
	}
	
	cur = first;	
	while (cur != nullptr) //копирование data в вспомогательный массив 
	{
		int z = (cur->data) - min_key;
		int index = arr[z];
		brr[index] = cur->data; 
		cur = cur->next;
		++arr[z];
	}
	for (int i = 0; i < size; i++) //потом убрать
	{
		cout << "i-" << i << " " << arr[i] << endl;
	}
	for (int i = 0; i < length; i++) //потом убрать
	{
		cout << "i-" << i << " " << brr[i] << endl;
	}


 	cout << " c5" << endl;
	cur = first;	
	int curSortedItem = 0;
	while (cur != nullptr && curSortedItem < length) //перенос data по вычесленным индексам
	{
		cur->data = brr[curSortedItem];
		cout << brr[curSortedItem] << " ";
		cur = cur->next;

		++curSortedItem; 
	}
	delete [] brr;
	delete [] arr; 
}

int List::getter(int index) //?
{
	if (empty() != 1)
	{
		Node* node = first;
		int size_1 = length;
		int value1 = NULL;
		if (index <= length)
		{	
			for (int i = 1; i < size_1+1; i++)
			{
				if (i == index)
				{
					value1 = node->data ;
					
				}
				node = node->next;
			}
			cout << "Значение: " << value1 << endl;
			return value1;
		}
		else 
		{ 
			cout << "Неправильный индекс" << endl; 
		}

	}
	else
	{
		cout << "Очередь пуста" << endl;
		return 0;
	}
}

void List::setter(int index, int value)//ломается
{
	if (empty() != 1)
	{
		if (index <= length)
		{
			Node* current = first;
			Node* newItem = new Node;
			int size_1 = length;
			for (int i = 0; i < size_1; i++)
			{
				if (i == index - 1)
				{
					newItem->next = current->next; 
					newItem->data = value;
					current->next = newItem;
				}
				current = current->next;
				i++;
				length++;
			}
		}
		else
		{
			if (index == length + 1)
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
