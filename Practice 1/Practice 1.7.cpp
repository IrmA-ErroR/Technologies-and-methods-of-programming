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

	Queue() {};
	~Queue() {};

	bool empty();
	void push_back(int x); 
	void show();
	void del();
	int get_last(); 

	int Max();
	int Min();
	
};

class List : public Queue
{
public:
	int getter(int index);
	void setter(int index, int value);
	void sort(int x, int y);

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
		myL.push_back(random_input(LOW, HIGH));
	}
	
	//myL.show();
	//myL.del();
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
	cout << "Введите индекс элемента и значение (set): " << endl;
	cin >> index >> value;
	myL.setter(index, value);
	myL.show();
	return 0;
}

void Queue::show()
{
	cout << "Вывод списка" << endl;
	Node* current = first;
	int n = 0;
	while (current != nullptr)
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


void Queue::del()
{
	cout << "Удаление" << endl;
	Node* temp = last;
	int date_ = 0;

	if (length != 0)
	{
		temp = last->next;
		date_ = last->data;
		delete last;
		last = temp;
	}
	else
	{
		cout << "Очередь пуста" << endl;
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
	int* brr = new int[size];
	int length_1 = length;

	cout << "С 1" << endl; //потом убрать
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
		cout << arr[i] << " ";
	}
	cout << "\nС 2" << endl; //потом убрать

	Node* cur = first;
	for (int j = 0; j < length; j++)
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

	cout << endl << "arr: " << endl;
	for (int i = 0; i < size; i++) //потом убрать
	{
		cout << "i-" << i << " " << arr[i] << endl;
	}

	cout << endl << "\nС 3" << endl; //потом убрать

	for (int i = size - 1; i >= 0; --i)
	{
		int y = length_1 - arr[i];
		arr[i] = y;
		length_1 = y;
		cout << "i-" << i << " " << arr[i] << endl;
	}
	cout << "\nС 4" << endl; //потом убрать

	for (int i = 0; i < size; ++i)
	{
		brr[i] = 0;
	}

	cur = first;
	for (int i = 0; i < length; i++)
	{
		while (cur != nullptr)
		{
			int z = (cur->data) - min_key;
			brr[arr[z]] = cur->data; //только 1 элемент в массиве 
			++arr[z];
			cur = cur->next;
			cout << "i-" << i << " " << brr[i] << endl;
		}
	}

	cout << "С 5" << endl; //потом убрать
	cur = first;
	for (int i = 0; i < length; i++)
	{
		while (cur != nullptr)
		{
			cur->data = brr[i];
			cur = cur->next;
		}
	}

	delete[] arr;
	delete[] brr;

}

int List::getter(int index)
{

	if (empty() != 1)
	{
		Node* node = first;
		int size_1 = length;
		int value1 = NULL;
		if (index <= length)
		{
			for (int i = 1; i < size_1 + 1; i++)
			{
				if (i == index)
				{
					value1 = get_last();
				}
				node = node->next;
			}
			cout << "Значение: " << value1 << endl;
			return value1;

		}

		else { cout << "Индекс превышает длину списка" << endl; }

		return 0;

	}
	else { cout << "Очередь пуста" << endl; }
}

void List::setter(int index, int value)
{
	if (empty() != 1)
	{
		if (index <= length)
		{
			Node* current = first;
			Node* newItem = new Node;
			int size_1 = length;
			for (int i = 1; i < size_1; i++)
			{
				if (i = index - 1)
				{
					newItem->next = current->next; //если менять 1, то ломается
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
