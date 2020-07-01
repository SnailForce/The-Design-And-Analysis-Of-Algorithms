#include <iostream>
using namespace std;
int euclid(int, int);

int main()
{
	cout << euclid(1, 0) << endl;
	cout << euclid(1910, 101) << endl;
}

int euclid(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return euclid(b, a % b);
}