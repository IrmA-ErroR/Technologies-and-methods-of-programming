// TMP_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
const int lVl = 10;

struct Vertex {
    // info:
    char name;
};
/*struct Uzel_LS // структура узла
{
    int name_v; // номер узла в массиве V
    float chain; // цена дуги
    Uzel_LS* next; // yказатель на следующий узел
};

struct Versh_ls
{
    //info
    Vertex info;
    Uzel_LS* head;
};*/

class Graf
{
public:
    Vertex V[lVl]; // массив узлов
    int A[lVl][lVl]; // матрица смежности
    //float C[lVl][lVl];
    //Versh_ls V_LS[lVl]; // список смежности
    int N = 0; //cчетчик узлов
    void Add_V(char newName);
    int indexOfName(char NameSearch);
    void Add_E(char v, char w, float c);
    void Del_E(char v, char w);
    int First(char v);
    void Show();
    void Algoritm();
};

void Graf::Add_V(char newName)
{
    if (N < lVl)

    {  //добавление в список смежности
        //V_LS[N].info.name = newName;
        //V_LS[N].head = nullptr;

        //добавление в матрицу смежности
        V[N].name = newName;

        for (int i = 0; i < lVl; i++) // инициализация
        {
            A[N][i] = 0;
            A[i][N] = 0; //матрица смежности
        }
        N++; // количество вершин
    }
    else
    {
        cout << "\n Error";
    }
}

int Graf::indexOfName(char NameSearch)
{
    for (int i = 0; i < N; i++)
    {
        if (V[i].name == NameSearch) //if (V_LS[i].info.name == NameSearch)
            return i;
    }
    return -1;
}

void Graf::Add_E(char v, char w, float c)
{
    // добавление в матрицу смежности
    A[indexOfName(v)][indexOfName(w)] = 1;
    //C[indexOfName(v)][indexOfName(w)] = c;

    //добавление в список смежности
    /*Uzel_LS* p;
    p = new Uzel_LS;
    p->chain = c;
    p->name_v = indexOfName(w);
    p->next = V_LS[indexOfName(v)].head;
    V_LS[indexOfName(v)].head = p;*/
}

void Graf::Del_E(char v, char w)
{
    // удаление дуги в матрице смежности
    A[indexOfName(v)][indexOfName(w)] = 0;
    //C[indexOfName(v)][indexOfName(w)] = 0;

    // удаление дуги в списке смежности
    /*Uzel_LS* cur, * prev;
    for (cur = V_LS[indexOfName(v)].head, prev = nullptr;(cur); prev = cur, cur = cur->next)
        if (cur->name_v == indexOfName(w))
            break;
    if (cur)
    {
        if (prev)
            prev->next = cur->next;
        else // удаление из головы
            V_LS[indexOfName(v)].head = cur->next;
        delete cur;
        return 1;
    }
    else return 0;*/
}

int Graf::First(char v)
{
    for (int i = 0; i < N; i++)
    {
        if (A[indexOfName(v)][i])
            return i;
    }
    return 0;
}


int main()
{
    cout << "Hello World!\n";
    Graf N_gr;
    N_gr.Add_V('A');
    N_gr.Add_V('B');
    N_gr.Add_V('C');
    N_gr.Add_V('D');
    N_gr.Add_E('A', 'D', 7);
    N_gr.Add_E('B', 'D', 8);
    N_gr.Add_E('C', 'D', 4);
    N_gr.Add_E('D', 'D', 6);
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

