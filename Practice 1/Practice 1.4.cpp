#include <iostream>

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
	Node* first = nullptr; //указатель на первый элемент очереди 
	Node* last = nullptr; // указатель на последний элемент очереди
	int length = 0; // счетчик длины очереди
public:
	Queue() {};
	~Queue() {};
	int empty();
	void puch_back(int x);
	void show();
	void del();
	void get_last();

	void sort();
	
};


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Поехали!\n";

	Queue myQ;

	myQ.puch_back(5);
	myQ.puch_back(7);
	myQ.show();
	
	myQ.sort();


	return 0;
}

void Queue::show()
{
	cout << "Вывод списка" << endl;
	Node* current = last;
	while (current != nullptr)
	{
		cout << current << endl;
		cout << current->data << endl;
		cout << current->next << endl;
		cout << endl;
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

}

void Queue::get_last()
{
	cout << "Получение последнего элемента" << endl;
	Node* temp = last;

}


void Queue::sort()
{
	cout << "Сортировка" << endl;
	Node* temp = last;
	Node* min;
	Node* min;
	//max.
	while (temp != nullptr)
	{
		//if ()
		cout << temp << endl;
		cout << temp->data << endl;
		cout << temp->next << endl;
		cout << endl;
		temp = temp->next;

	}
}

