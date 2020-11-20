#include<bits/stdc++.h>

using namespace std;

vector<int> heap;

void ShiftUp(int child)
{
	int parent = child / 2;
	while (parent > 0)
	{
		// 小堆
		if (heap[parent] > heap[child])
		{
			swap(heap[parent], heap[child]);
			child = parent;
			parent = child / 2;
		}
		else
			break;
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	// 数组第一个元素不用
	heap.push_back(0);
	while (N--)
	{
		int n;
		cin >> n;
		heap.push_back(n);
		ShiftUp(heap.size() - 1);
	}

	getchar();
	while (M--)
	{
		string str;
		int flg = 0; // 置零
		getline(cin, str);
		if (str[str.length() - 1] == 't')
		{
			int root;
			sscanf(str.c_str(), "%d", &root);
			if (heap[1] == root)
				flg = 1;
		}
		else if (str[str.length() - 1] == 's')
		{
			int x, y;
			sscanf(str.c_str(), "%d %*s %d", &x, &y);
			int idx1 = find(heap.begin() + 1, heap.end(), x) - heap.begin();
			int idx2 = find(heap.begin() + 1, heap.end(), y) - heap.begin();
			if (x != y && idx1 / 2 == idx2 / 2)
				flg = 1;
		}
		else
		{
			int x, y;
			char diff[10] = { 0 };
			sscanf(str.c_str(), "%d %*s %*s %s %*s %d", &x, diff, &y);
			int idx1 = find(heap.begin() + 1, heap.end(), x) - heap.begin();
			int idx2 = find(heap.begin() + 1, heap.end(), y) - heap.begin();
			if (strcmp(diff, "parent") == 0)
			{
				if (idx1 == idx2 / 2)
					flg = 1;
			}
			else
			{
				if (idx1 / 2 == idx2)
					flg = 1;
			}
		}
		if (flg)
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	return 0;
}