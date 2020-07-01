#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	for (size_t i = 0; i < 1000000; i++)
	{
		int c1, c2;
		// 计算两种方式所需的船数
		c1 = i / 10 + (i % 10 ? 1 : 0);
		c2 = i / 12 + (i % 12 ? 1 : 0);
		if (i % 10 == 8 && c1 == c2 + 1)
		{
			cout << i << endl;
			count += 1;
		}
	}
	cout << "count: " << count << endl;
	return 0;
}