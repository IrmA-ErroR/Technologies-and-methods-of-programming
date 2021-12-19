#include<bits/stdc++.h>
using namespace std;
int mat[600][600];
int res;
// Алгоритм Стоера-Вагнера с примечанием, которое вы можете понять
 // Глобальный минимальный разрез неориентированного графа, используя аналогичный метод o (n ^ 3), чтобы найти прим, я узнал днем ​​...
 // Вначале для решения задачи используется максимальный поток перечисленных источника и приемника, а сложность составляет o (n ^ 5) timeout
 
void Mincut(int n) {
	int node[600], dist[600];
	bool visit[600];
	int i, prev, maxj, j, k;
	for (i = 0; i < n; i++)
		node[i] = i;
	while (n > 1) {
		int maxj = 1;
		 for (i = 1; i <n; i ++) {// инициализируем обрезанным размером обведенного набора
			dist[node[i]] = mat[node[0]][node[i]];
			if (dist[node[i]] > dist[node[maxj]])
				maxj = i;
		}
		prev = 0;
		memset(visit, false, sizeof(visit));
		visit[node[0]] = true;
		for (i = 1; i < n; i++) {
			 if (i == n-1) {// Осталась только последняя точка, не добавленная в набор, обновляем минимальный разрез
				res = min(res, dist[node[maxj]]);
				 for (k = 0; k <n; k ++) // Объединить последнюю точку и точки в наборе, который ее вывел
					mat[node[k]][node[prev]] = (mat[node[prev]][node[k]] += mat[node[k]][node[maxj]]);
				 node [maxj] = node [- n]; // Картинка после сжатия
			}
			visit[node[maxj]] = true;
			prev = maxj;
			maxj = -1;
			for (j = 1; j < n; j++)
				 if (! visit [node [j]]) {// Добавляем maxj, полученный в прошлый раз, к набору и объединяем смежные ребра в набор разрезов
					dist[node[j]] += mat[node[prev]][node[j]];
					if (maxj == -1 || dist[node[maxj]] < dist[node[j]])
						maxj = j;
				}
		}
 
	}
	return;
}
 
int main() {
	int n, m, a, b, v;
	while (scanf("%d%d", &n, &m) != EOF) {
		res = (1 << 29);
		memset(mat, 0, sizeof(mat));
		while (m--) {
			scanf("%d%d%d", &a, &b, &v);
			mat[a][b] += v;
			mat[b][a] += v;
		}
		Mincut(n);
		printf("%d\n", res);
	}
 
