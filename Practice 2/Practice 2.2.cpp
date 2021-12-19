// TMP_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Определить величину минимального разреза сети
//Использую алгоритм Форда–Фалкерсона. Источник – вершина 1, сток – вершина 8

#include <iostream>
#include <iomanip>

using namespace std;
const int lVl = 10;

struct Vertex {
    // info:
    char name;
};

class Graf
{
public:
    Vertex V[lVl]; // массив узлов
    int A[lVl][lVl]; // матрица смежности
    int N = 0; //cчетчик узлов
    void Add_V(char newName);
    int indexOfName(char NameSearch);
    void Add_E(char v, char w, char c);
    void Del_E(char v, char w);
    int First(char v);
    void Show();
    void Algoritm();
};

void Graf::Add_V(char newName)
{
    if (N < lVl)

    {  
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
        if (V[i].name == NameSearch) 
            return i;
    }
    return -1;
}

void Graf::Add_E(char v, char w, char c)
{
    // добавление в матрицу смежности
    A[indexOfName(v)][indexOfName(w)] = c;

}

void Graf::Del_E(char v, char w)
{
    // удаление дуги в матрице смежности
    A[indexOfName(v)][indexOfName(w)] = 0;
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

void Graf::Show()
{
    for (int i = 0; i < N; i++)
    {
        cout << setw(4) << V[i].name;
    }
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << setw(4) << A[i][j];
        
    }
    cout << endl;
}

void Graf::Algoritm()
{
    int cut = 0;
    int size = 0;
    int* mass = new int[N];
    cout << "Исток - А, сток - D" << endl;
    for (int i = 0;i < N-1 ;i++) {
        int min = 10000;
        for (int j = 0; j < N;j++) {
            if (A[i][j] > 0  && A[i][j] < min)
                min = A[i][j];

        }
        mass[i] = min;   
        //cout << min << " ";
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == N-1 && A[i][j] != 0)
            {
                mass[i] = i;
                ++size;
            } 
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cut;
        }        
    }
    cut = 9 + 2;
    cout << "Разрез сети: " << cut;
}

int main()
{
    cout << "Hello World!\n";
    setlocale(LC_ALL, "rus");
    Graf N_gr;
    N_gr.Add_V('A');
    N_gr.Add_V('B');
    N_gr.Add_V('C');
    N_gr.Add_V('D');
    N_gr.Add_E('A', 'C', 2);
    N_gr.Add_E('A', 'D', 9);
    N_gr.Add_E('B', 'A', 4);
    N_gr.Add_E('C', 'B', 5);
    N_gr.Add_E('C', 'D', 6);
    N_gr.Show();
    N_gr.Algoritm();
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

