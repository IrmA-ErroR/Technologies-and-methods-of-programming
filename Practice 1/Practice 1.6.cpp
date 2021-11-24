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

	int empty();
	void puch_back(int x); 
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
		myL.puch_back(random_input(LOW, HIGH));
	}
	
	//myL.show();
	//myL.del();
	myL.show();
	int min = myL.Min();
	int max = myL.Max();
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	myL.sort(min, max);
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
	Node* current = last;
	int n = 0;
	while (current != nullptr)
	{
		n++;
		//cout << current << endl;
		cout << n << " " << current->data << endl;
		//cout << current->next << endl;
		//cout << endl;
		current = current->next;
	}
}


int Queue::empty() 
{	
	return first == nullptr;
}

void Queue::puch_back(int x)
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
		newItem->next = last;
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
	for (MNode = last, node = last->next; node; node = node->next)
		if (MNode->data < node->data)
			MNode = node;
	return MNode->data;
}
int Queue::Min()
{
	Node* MNode, * node;
	for (MNode = last, node = last->next; node; node = node->next)
		if (MNode->data > node->data)
			MNode = node;

	return MNode->data;

}

void List::sort(int min, int max)
{
	Node* temp = last;
	cout << "Сортировка" << endl;
	int min_key = min;
	int max_key = max;
	int arr[] = { 0 };
	int brr[] = { 0 };
	int length_1 = length;
	int size = max - min + 1;

	cout << "С 1" << endl; //потом убрать
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
		cout << arr[i] << " ";
	}
	cout << "\nС 2" << endl; //потом убрать
	for (int j = 0; j < length; j++)
	{
		while (temp != nullptr)
		{
			int x = (temp->data) - min_key;
			arr[x]++;
			temp = temp->next;
		}
	}
	for (int i = 0; i < size; i++) //потом убрать
	{
		cout << "i-" << i << " " << arr[i] << endl;
	}

	cout << "\nС 3" << endl; //потом убрать

	for (int i = size-1; i >= 0; i--)
	{
		int y = length_1 - arr[i];
		arr[i] = y;
		length_1 = y;
		cout << "i-" << i << " " << arr[i] << endl;
	}
	cout << "\nС 4" << endl; //потом убрать

	for (int i = 0; i < length; i++)
	{
		int z = temp->data - min;
		brr[arr[z]] = temp->data;
		arr[z]++;
		temp = temp->next;
		cout << "i-" << i << " " << brr[i] << endl;

	}

	cout << "С 5" << endl; //потом убрать

	for (int i = 0; i < length; i++)
	{
		temp->data = brr[i];
		temp = temp->next;
	}
}

int List::getter(int index)
{

	if (empty() != 1)
	{
		Node* node = last;
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
			Node* current = last;
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
				puch_back(value);
			}				
			else
			{
				for (int i = length + 1; i < index; i++)
				{
					puch_back(0);
				}
				puch_back(value);
			}
		}
	}
	else { cout << "Очередь пуста!" << endl;}
}
