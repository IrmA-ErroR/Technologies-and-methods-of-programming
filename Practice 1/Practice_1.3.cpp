#include <iostream>
#include <cstdlib>
#include <ctime>


#define LENGTH 10


#define random_input(l,h) (rand() % (h) - (l))

#define LOW (0)
#define HIGH (100)

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
	Queue myQ; 
	List myL;
	cout << "Вседите длину списка: \n";
	cin >> len;
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		myQ.puch_back(random_input(LOW, HIGH));
	}
	
	//myQ.show();
	//myQ.del();
	myQ.show();
	int min = myQ.Min();
	int max = myQ.Max();
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	int num = myQ.Max() - myQ.Min();
	myL.sort(min, max);
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
	cout << "Сортировка" << endl;
	int min_key = min;
	int max_key = max;
	int arr[] = { 0 };
	int size = max - min + 1;
	for (int j = 0; j < size; j ++) arr[j] = 0;

	//for (int i = l; i <= r; i++) cnt[a[i] + 1] + +;
	
}
	/*void distcount(int a[], int l, int r)
	{
		int i, cnt[M];
		static int b[maxN];
		for (int j = 0; j < M; j + +) cnt[j] = 0; // обнуление всех счетчиков
		for (int i = l; i <= r; i++) cnt[a[i] + 1] + +; //подсчитывает во втором счетчике количество 0, третьем счетчике — количество 1
		for (j = 1; j < M; j + +) cnt[j] += cnt[j - 1]; // складывает все эти числа, после чего каждый счетчик содержит количество ключей, меньших или равных соответствующему ключу
		for (i = l; i <= r; i++) b[cnt[a[i]]++] = a[i]; // перемещает ключи во вспомогательный массив b в соответствии со значениями этих индексов
		for (i = l; i <= r; i++) a[i] = b[i]; //последний цикл возвращает отсортированный файл в файл a
	}*/




	/*support = [0 for i in range(n)]
	for element in temp :
support[element.age - min_key] += 1
size = len(temp)
for i in range(n - 1, -1, -1) :
	size -= support[i]
	support[i] = size
	result = [None for i in range(len(temp))]
	for element in temp :
result[support[element.age - min_key]] = element
support[element.age - min_key] += 1
return result*/


