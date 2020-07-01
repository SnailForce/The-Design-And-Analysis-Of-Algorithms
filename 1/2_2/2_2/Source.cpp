#include <iostream>
using namespace std;
// 迭代
int myGet(int t, int z)
{
	int res = 0;
	while (t != 0)
	{
		res += t % z;
		t /= z;
	}
	return res;
}
void func1(int n)
{
	int count = 0;
	for (size_t i = 1; i <= n; i++)
	{
		if (myGet(i, 10) == myGet(i, 2))
		{
			count += 1;
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "func1: " << n << ": " << count << endl;
}
// 递归求二进制
int getB(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n % 2 + getB(n / 2);
	}
}
// 递归求十进制
int getT(int n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return n % 10 + getT(n / 10);
	}
}
void func2(int n)
{
	int count = 0;
	for (size_t i = 1; i <= n; i++)
	{
		if (getB(i) == getT(i))
		{
			count += 1;
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "func2: " << n << ": " << count << endl;
}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		func1(n);
		func2(n);
	}
}