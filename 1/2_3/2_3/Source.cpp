#include <iostream>
#include <vector>
using namespace std;
int count = 0;
int func(vector<int> v, int start, int end)
{
	
	if (start >= end)
	{
		return -1;
	}
	else if (v.at(start) == v.at(end))
	{
		func(v, start + 1, end - 1);
	}
	else if (v.at(start) < v.at(end))
	{
		::count += 1;
		v.at(start + 1) += v.at(start);
		func(v, start + 1, end);
	}
	else if (v.at(start) > v.at(end))
	{
		::count += 1;
		v.at(end - 1) += v.at(end);
		func(v, start, end - 1);
	}
	return ::count;
}

int main()
{
	int cur;
	int s;
	while (cin >> s && s != 0)
	{
		vector<int> v;
		for (size_t i = 0; i < s; i++)
		{
			cin >> cur;
			v.push_back(cur);
		}
		::count = 0;
		cout << "count: " << func(v, 0, s - 1) << endl;
	}
	system("pause");
	return 0;
}