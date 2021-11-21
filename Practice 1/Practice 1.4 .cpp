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
	void Get(); 

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
	void get_last(); 

	int Max();
	int Min();
	
};

class List : public Queue
{
public:
	void get(int index);
	void set(int index, int value);
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
	myL.get(index);
	cout << "Введите индекс элемента и значение (set): " << endl;
	cin >> index >> value;
	myL.set(index, value);
	return 0;
}

void Queue::show()
{
	cout << "Вывод списка" << endl;
	Node* current = last;
	while (current != nullptr)
	{
		//cout << current << endl;
		cout << current->data << endl;
		/*cout << current->next << endl;
		cout << endl;*/
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

void Queue::get_last()
{
	cout << "Получение последнего элемента" << endl;
	Node* temp = last;

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
	int size = max - min + 1;

	cout << "С 1" << endl;
	for (int i = 0; i < size; i++) arr[i] = 0;
	cout << "С 2" << endl;
	for (int j = 0; j < size ; j++) //ломается здесь
	{
		while (temp != nullptr)
		{
			int x = (temp->data) - min_key;
			arr[x]++;
			temp = temp->next;
		}
		cout << arr[j] << endl;
	}
	cout << "С 3" << endl;

	for (int i = size; i <= 0; i--)
	{
		arr[i] = size - arr[i] ;
		size = arr[i];
		cout << arr[i] << endl;
	}
	cout << "С 4" << endl;
	for (int i = 0; i < size; i++)
	{

	}
	cout << "С 5" << endl;

	


	/*int i, j;
	static int b[] = { 0 };
	cout << "С 1" << endl;

	for (j = 0; j < size; j++)
	{
		arr[j] = 0; // обнуление всех счетчиков
		cout << arr[j] << endl;
	}
	cout << "С 2" << endl;
	for (i = min_key; i <= max_key; i++)
	{
		while (temp != nullptr)
		{		
			arr[(temp->data) + 1] ++; //подсчитывает во втором счетчике количество 0, третьем счетчике — количество 1
			temp = temp->next;  
		}
		cout << arr[i] << endl;
	}
	cout << "С 3" << endl;
	for (j = 0; j < size-1; j++)
	{
		arr[j] += arr[j + 1]; // складывает все эти числа, после чего каждый счетчик содержит количество ключей, меньших или равных соответствующему ключу
		cout << arr[j] << endl;
	}
	cout << "С 4" << endl;
	for (i = min; i <= max; i++)
	{
		b[arr[(temp->data)]++] = (temp->data); // перемещает ключи во вспомогательный массив b в соответствии со значениями этих индексов
		cout << arr[i] << endl;
	}
	cout << "С 5" << endl;
	for (i = min; i <= max; i++)
	{
		(temp->data) = b[i]; //последний цикл возвращает отсортированный файл
		cout << b[i] << endl;
	}*/
}

void List::get(int index)
{
}

void List::set(int index, int value)
{
}
