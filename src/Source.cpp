#include <iostream>

using namespace std;

class disjoin_set
{
private:
	int *parent;
	int *main_parent;
	int *rank;
	int size;
	void select_parents(int** arr, int n) {
		for (int i = 0; i < n; i++) {
			int x = arr[i][0];
			int y = arr[i][1];
			Union(x, y);
		}
	}
	int find_main_parents() {
		int count=0;
		for (int i = 0; i < size; i++) {
			main_parent[i] = Find(i);
			if (main_parent[i] == i) {
				count++;
			}
		}
		return count;
	}
public:

	disjoin_set(int s)
	{
		size = s;
		parent = new int[size];
		rank = new int[size];
		main_parent = new int[size];
		for (int i = 0; i < size; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int Find(int x_) { //сжатие путей
		int x = x_;
		int p = parent[x_];

		while (p != x) {
			x = p;
			p = parent[p];
		}
		while (x_!=p)
		{
			x = parent[x_];
			parent[x_] = p;
			x_ = x;
		}
		return p;
	}

	void Union(int x, int y)
	{
		int s1 = Find(x);
		int s2 = Find(y);
		int r1 = rank[s1];
		int r2 = rank[s2];
		if (r1<r2) {
			parent[s1] = s2;
		}
		else{
			parent[s2] = s1;
			if (r1 == r2)
				rank[s1] = rank[s2] + 1;
		}
	}

	void FindComponents(int** arr, int n)
	{
		select_parents(arr,n);
		int count_parents = find_main_parents();
		for (int j = 0; j < count_parents; j++)
		{
			cout << "Component [" << j << "] = {";
			int cur_component=-1;
			int i = 0;
			for (int k = 0; k < size; k++)
			{
				if (main_parent[k]!=-1)
				{
					cur_component = main_parent[k];
					i = k;
					break;
				}
			}
			for (; i < size; i++)
			{
				if (main_parent[i] == cur_component)
				{
					main_parent[i] = -1;
					cout << " " << i;
				}		
			}
			cout << " } " << endl;
		}

	}

	~disjoin_set()
	{
		delete[] parent;
		delete[] rank;
		delete[] main_parent;
	}
};


int main()
{
	int  n; 
	int vertix = 0;
	//int E[n][2];//строк столбцов
	//E[0][0] = 0; E[0][1] = 1;
	//E[1][0] = 0; E[1][1] = 2;
	//E[2][0] = 1; E[2][1] = 2;
	//E[3][0] = 3; E[3][1] = 4;
	//E[4][0] = 4; E[4][1] = 5;
	//E[5][0] = 5; E[5][1] = 3;
	//E[6][0] = 6; E[6][1] = 7;

	cout << "Enter the number of vertex: ";
	cin >> vertix;

	cout << "Enter the number of relations: ";
	cin >> n;

	int **E;
	E = new int *[n];
	for (int i = 0; i < n; i++) {
		E[i] = new int[2];
	}

	cout << "Enter the relations: "<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "N"<<i<<endl;
		cout << "  1 element = ";
		cin >> E[i][0];
		cout << "  2 element = ";
		cin >> E[i][1];
		cout << endl;
	}

	disjoin_set ds(vertix);
	ds.FindComponents(E,n);

	getchar();
	return 0;
}