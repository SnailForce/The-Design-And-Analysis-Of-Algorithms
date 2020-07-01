#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	int res = 0;
	int n = 20;
	for (size_t i = 0; i <= n; i++)
	{
		for (size_t j = 0; j <= n / 2; j++)
		{
			for (size_t k = 0; k <= n / 5; k++)
			{
				res = i * 1 + j * 2 + k * 5;
				if (res == n)
				{
					cout << "1: " << i << " j: " << j << " k: " << k << endl;
					count += 1;
				}
				else if (res > n)
				{
					break;
				}
			}
			if (i * 1 + j * 2 > n)
			{
				break;
			}
		}
		
	}
	cout << "count: " << count << endl;
}