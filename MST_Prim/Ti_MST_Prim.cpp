// (c) Tivole

#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <stdbool.h>

using namespace std;

#define index(i, j, n) (i <= j) ? (i * n - (i - 1) * i / 2 + j - i) : (j * n - (j - 1) * j / 2 + i - j)

void Ti_Show(int*, int);
int minKey(int*, bool*, int);
void MST_Prim(int*, int*, int);


int main() {

	int i, n, *Graph = NULL, *ResultGraph = NULL;
	FILE *fin;

	fin = fopen("input.txt", "r");
	if (!fin) {
		printf("(!) Error while opening file. Perhaps it does not exist.\n");
		return 1;
	}

	fscanf(fin, "%d", &n);

	Graph = (int*)malloc((n*(n+1)/2) * sizeof(int));

	for(i = 0; i < n*(n+1)/2; i++)
		fscanf(fin, "%d", &Graph[i]);

	fclose(fin);

	ResultGraph = (int*)calloc((n*(n+1)/2), sizeof(int));

	Ti_Show(Graph, n);

	MST_Prim(Graph, ResultGraph, n);

	Ti_Show(ResultGraph, n);

	return 0;
}

void Ti_Show(int *a, int n) {

	int i,j;

	printf("\n_____");
	for(i = 0; i < n; i++) printf("________");
	printf("\n|   |  ");
	for(i = 0; i < n; i++) printf("      | ");
	printf("\n|   |  ");
	for(i = 0; i < n; i++) printf("  \033[34;1m%c\033[0m   | ", ('A' + i));
	printf("\n|___|_");
	for(i = 0; i < n; i++) printf("_______|");
	printf("\n");


	for(i = 0; i < n; i++) {
		printf("|   | ");
		for(j = 0; j < n; j++) printf("       |");
		printf("\n");
		printf("| \033[34;1m%c\033[0m | ", 'A'+i);
		for(j = 0; j < n; j++) {
			if(a[index(i, j, n)]) printf("  \033[32;1m%2d\033[0m   |", a[index(i, j, n)]);
			else printf("   \033[31;1m*\033[0m   |");
		}
		printf("\n|___|_");
		for(j = 0; j < n; j++) printf("_______|");
		printf("\n");
	}
	printf("\n\n");
	return;
}

int minKey(int *key, bool *mstSet, int n)  {
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (!mstSet[v] && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void MST_Prim(int *Graph, int *ResultGraph, int n)  {
	int i, j, k, parent[n], key[n];
	bool mstSet[n];

	for (i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (i = 0; i < n-1; i++) {
		k = minKey(key, mstSet, n);
		mstSet[k] = true;
		for (j = 0; j < n; j++)
			if (Graph[ index(k, j, n) ] && !mstSet[j] && Graph[ index(k, j, n) ] < key[j])
				parent[j] = k, key[j] = Graph[ index(k, j, n) ];
	}

	for(i = 0; i < n; i++) ResultGraph[ index(parent[i], i, n) ] = Graph[ index(i, parent[i], n) ];

	return;
}
