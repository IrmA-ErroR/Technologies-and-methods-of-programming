#include "stdafx.h"
#include <locale.h>
#include <ctime>
#include "windows.h"
#include <iostream>
using namespace std;

struct Node
{
// указатель на следующий элемент в очереди
Node *next;
// значение элемента в очереди
int value;
};

class Ochered
{
public:
// Колличество элементов в списке
int N;
int i;
int size = 0;
int size_1 = NULL;
// Счетчик колличества операций
unsigned long long int N_op = 0;
// указатель на первый элемент
Node *head;
// указатель на хвост очереди
Node *tail;
  
// инициализация очереди
void Init() //2
{
head = NULL; //1
// При инициализации head и tail = NULL
tail = head; //1
}

// добавление элемента в начало очереди, x - значение этого элемента
void Add(int x) //(3+2+2)+(1+2+1)+2=13
{
// создание нового элемента
Node *node = new Node; //3
// в поле next данного элемента записывается NULL
node->next = NULL; //2
// в поле value записывается значение ячейки очереди int
node->value = x; //2
// после инициализации и при создании первого элемента мы проходим по ветке else
if (tail != NULL) //1
{
/* добавление элемента через хвост в очереди,
tail указывает на первый элемент в очереди перед добавляемым
в поле next первого элемента записывается адрес нового первого элемента*/
  tail->next = node; //2
// tail начинает указывать на новый элемент в очереди
tail = node; //1
}

else
{
// хвост указывает на первый элемент в очереди
tail = node; //1
// голова указывает на первый элемент в очереди
head = tail; //1
}
size++; //2
}
// проверка очереди на пустоту
bool Isempty() //1
{
//true, если head = NULL; false, если head указывает на какой-либо элемент в очереди
return head == NULL; //1
}

// удаление элемента из конца очереди
int Del() //1+(2+2+2+1+2+2+2)=14
{
int val = NULL; //1
// если очередь не пуста
if (Isempty() != 1) //2
{
// создаем указатель на структуру
Node *tmp;
// в указателюь tmp кладем ссылку на next предпоследнего элемента в очереди
tmp = head->next; //2
// в val записываем значение последнего элемента в очереди
val = head->value; //2
// удаляем объект по указателю head (последний элемент в очереди)
delete head;
// head начинает указывать на предпоcледний элемент в очереди (последний удален)
head = tmp; //1
// После удаления последнего элемента из очереди происходит повторная инициализация
if (Isempty() == 1) //2
{
Init(); //2
}
size--; //2
// возвращаем значение последнего элемента в очереди
return val;
}
else { cout << "Очередь пуста!" << endl; }
return 0;
}

// получение значения из конца очереди
int Value() //3
{
// если очередь не пуста
if (Isempty() != 1) //2
{
// через указатель head получить значение value последнего элемента в очереди
return head->value; //1
}
else { cout << "Очередь пуста!" << endl; }
return 0;
}
};

// Класс наследник
class Numbers : public Ochered
{
public:
// получение значения из списка, x - номер элемента в списке
int get(int x) //2+1+1+(1+33n)=5+33n
{
// если очередь не пуста
if (Isempty() != 1) //2
{
size_1 = size; //1
int val1 = NULL; //1
// Перебор всех значений в списке
for (int i = 1; i < size_1 + 1; i++) //1+∑(1+4+1+27)=1+∑(33)=1+33𝑛𝑛1𝑛1
{
if (i == x) //1
{
// Когда i доходит до номера получаемого элемента, то в val записывается значение данного элемента
val1 = Value(); //4
}

// Перебор начинается только в случае если x не равен нулю

if (x != 1) //1
{
// Вначале элемент удаляется из конца очереди, и сразу же добавляется в начало очереди, и так в цикле пока не восстановится первоначальное состояние очереди
Add(Del()); //14+13=27
}

else
{
// В противном случае сразу выходим из цикла for
break;
}
}

// Возвращается значение элемента под номером x из очереди
return val1;
}
else { cout << "Очередь пуста!" << endl; }
return 0;
}

// установка значения элемента в списке, x - номер элемента в списке, y - значение элемента в списке

void set(int x, int y) //2+3+31n=5+31n

{

// если очередь не пуста

if (Isempty() != 1) //2

{

if (x <= size) //1+1+1+31n=3+31n

{

size_1 = size; //1

for (int i = 1; i < size_1 + 1; i++) //1+∑(1+2+1+27)𝑛1=1+31𝑛

{

if (i == x) //1

{

// Запись значения y в список

head->value = y; //2

}

if (x != 1) //1

{

Add(Del()); //14+13=27

}

else

{

break;

}

}

}

// Если элемент устанавливается за пределы изначального списка

else //1+2+1+∑(13)+13𝑥𝑛+1=17+ ∑(13)𝑥𝑛+1

{

if (x == size + 1) //2

{

//Если номер элемента в списке на 1 больше размера очереди, значит элемент добавляется в начало очереди

Add(y);

}

else

{

for (i = size + 1; i < x; i++) //1+∑(13)𝑥𝑛+1

{

// В противном случае очередь заполняется нулями

Add(0); //13

}

Add(y); //13

}

}

}

else { cout << "Очередь пуста!" << endl; }

}

void sort(int N)

{

int s, f, d, i, j, g, k, p;

s = 1; //1

do

{

s = 1 - s; //2

d = 1; //1

f = 1; //1

if (s == 0) //1

{

i = 1; //1

j = N; //1

k = N + 1; //2

g = 2 * N; //2

}

else

{

i = N + 1; //2

j = 2 * N; //2

k = 1; //1

g = N; //1

}

while (i != j)//∑(1+11+132𝑛+10+128𝑛+2+2+132𝑛+12+130𝑛2+13𝑛+𝑛11+1+1+1+1)=∑(43+405𝑛+130𝑛2)=43𝑛+405𝑛2+130𝑛3𝑛1

{

// if(K[i]<K[j])

if (get(i) > get(j))//(5+∑(33)2𝑛1)+(5+∑(33)2𝑛1)+1=5+66𝑛+5+66𝑛+1= 11+132𝑛
{
// R[k] = R[j];
set(k, get(j));//(5+∑(33)2𝑛1)+(5+∑(31)2𝑛1)=5+66𝑛+5+62𝑛= 10+128𝑛
k = k + d; //2
j = j - 1; //2
// if (!(K[j+1]<=K[j]))
if (get(j + 1) <= get(j)) //5+66n+1+5+66n+1=132n+12
{
}
else
{
do
{
// R[k]=R[i];
set(k, get(i)); //10+128n
k = k + d; //2
i = i + 1; //2

}
// while(!K[i-1]>=K[i]);

while (get(i - 1) < get(i)); //∑(10+128𝑛+2+2+2+5+𝑛/2166𝑛+5+66𝑛)=∑(10)+∑(128𝑛)+∑(2)+∑(2)+∑(2)+∑(5)+∑(66𝑛)+∑(5)+∑(66𝑛)𝑛/21𝑛/21𝑛/21𝑛/21𝑛/21=𝑛/21𝑛/21𝑛/21𝑛/2110𝑛2+128𝑛22+2𝑛2+2𝑛2+2𝑛2+5𝑛2+66𝑛22+5𝑛2+66𝑛22=5𝑛+64𝑛2+𝑛+𝑛+𝑛+33𝑛2+33𝑛2+5𝑛=130𝑛2+13𝑛
f = 0; //1
d = -d; //1
p = k; //1
k = g; //1
g = p; //1
}
}
else
{
// R[k]=R[i];
set(k, get(i));
k = k + d; //2
i = i + 1; //2
// if(K[i-1]<=K[i])
if (get(i - 1) <= get(i)) //…+2
{
}
else
{
do
{
// R[k] = R[j];
set(k, get(j));
k = k + d; //2
j = j - 1; //2
}
// while(K[j+1]>=K[j]);
while (get(j + 1) < get(j)); //…+2
f = 0; //1
d = -d; //1
p = k; //1
k = g; //1
g = p; //1
}
}
}
//R[k]=R[i];
set(k, get(i)); //10+128n
} while (f != 1); //log2(𝑛)∗(2+1+1+1+1+1+2+2+43𝑛+405𝑛2+130𝑛3+10+128𝑛+1)=log2(𝑛)∗(22+171𝑛+405𝑛2+130𝑛3)
if (s == 0) //1
{
for (int i = 1; i <= N; i++)//1+∑(128𝑛+11)=1+∑(128𝑛)+∑(11)=1+128𝑛2+𝑛1𝑛1𝑛111𝑛
{
// R[i] = R[i+n];
set(i, get(i + N)); //128𝑛+11
}
}
size_1 = size; //1
for (int i = 1; i <= size_1; i++) //1+∑(27+2)=1+∑(29)=1+58𝑛2𝑛12𝑛1
{
if (i <= size / 2) //2
{
Add(Del()); //27
}
else
{
Del();
}
}
}
};

int main()
{
setlocale(LC_ALL, "ru");
srand(time(NULL));
// Схема эксперимента
// Инициализация очереди и заполнение хранилища ключей
int i, t_s, t_f;
// Хранилище ключей
int Key[3000];
int N = 300;
Numbers list;
list.Init();
for (i = 0; i < 3000; i++)
{
// Заполнение хранилища ключей случайными числами до 1000
Key[i] = rand() % 999;
}
for (i = 0; i < 10; i++)
{
for (int z = N - 300; z < N; z++)
{
list.Add(Key[z]);
}
list.N_op = 0;
t_s = GetTickCount();
list.sort(N);
t_f = GetTickCount();
cout << "Номер сортировки: " << i + 1 << " Колличество отсортированных элементов: " << N << " Время сортировки (ms): " << t_f - t_s << " Колличество операций (N_op): " << list.N_op << endl; // Шаг в 300 элементов
N = N + 300;
}
return 0;
}

F(n)= 1+log2(𝑛)∗(22+171𝑛+405𝑛2+130𝑛3)+1+1+128𝑛2+11𝑛+1+1+58𝑛=log2(𝑛)∗(22+171𝑛+405𝑛2+130𝑛3)+5+69𝑛+128𝑛2

O(F(n))= log2(𝑛)∗(𝑛3)
