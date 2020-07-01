#include <iostream>
using namespace std;
const int max = 100;
int res[max][max];
void func(int n, int cur1, int len, int cur2)
{
	// cur1:起始数字
	// cur2:起始坐标
	//  len:当前子块的大小

	// 子块大小为1/2 递归结束条件
	// 子块大小为1
	if (len == 1)
	{
		res[cur2][cur2] = cur1;
		return;
	}
	// 子块大小为2
	if (len == 2)
	{
		res[cur2][cur2] = cur1++;
		res[cur2][cur2 + 1] = cur1++;
		res[cur2 + 1][cur2 + 1] = cur1++;
		res[cur2 + 1][cur2] = cur1;
		return;
	}

	// start:当前子块起始数字
	// x1:当前子块起始横坐标
	// x2:当前子块结束横坐标
	int start = cur1;
	int x1 = cur2;
	int x2 = n - cur2 + 1;
	if (len >= 3)
	{
		// 顺时针一圈
		for (size_t i = x1; i <= x2; i++)
		{
			res[x1][i] = start++;
		}
		for (size_t i = x1 + 1; i <= x2; i++)
		{
			res[i][x2] = start++;
		}
		for (size_t i = x2 - 1; i >= x1; i--)
		{
			res[x2][i] = start++;
		}
		for (size_t i = x2 - 1; i >= x1 + 1; i--)
		{
			res[i][x1] = start++;
		}
		// 内部子块递归
		func(n, start, len - 2, cur2 + 1);
	}
}
// 打印
void disp(int cur)
{
	for (size_t i = 1; i <= cur; i++)
	{
		for (size_t j = 1; j <= cur; j++)
		{
			cout << res[i][j];
			if (j != cur)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}
int main()
{
	int cur;
	cout << "Input: ";
	while (cin >> cur && cur != 0)
	{
		func(cur,1 , cur, 1);
		disp(cur);
		cout << "Input: ";
	}
}