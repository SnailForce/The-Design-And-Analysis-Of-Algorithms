#include <iostream>
using namespace std;
// 这道题结果就是2^(n-1)
int func(int cur)
{
	if (cur == 1)
	{
		return 1;
	}
	int count = 1;
	for (size_t i = 1; i < cur; i++)
	{
		count += func(i);
	}
	return count;
}
void main()
{
	int cur;
	cout << "Input: ";
	while (cin >> cur && cur > 0)
	{
		// int res = func(cur);
		// cout << res << endl;
		cout << "Output: " << (1 << (cur - 1)) << endl;
		cout << "Input: ";
	}
}