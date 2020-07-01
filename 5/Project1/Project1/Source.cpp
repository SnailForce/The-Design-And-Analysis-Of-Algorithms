#include <iostream>
#include <vector>
#include <algorithm>

#include "Pro.h"

using namespace std;

int count = 0;
// 按照结束时间降序，若结束时间相同，按照开始时间降序
bool mySort(const pro p1, const pro p2)
{
	if (p1.getEnd() != p2.getEnd())
	{
		return p1.getEnd() > p2.getEnd();
	}
	else
	{
		return p1.getStart() > p2.getStart();
	}
}

void func(const vector<pro>& pros)
{
	if (pros.size() <= 0)
	{
		return;
	}
	int start = pros[0].getEnd();
	for (auto p : pros)
	{
		if (p.getEnd() <= start)
		{
			::count += p.getEnd() - p.getStart();
			start = p.getStart();
		}
	}
}

void test1()
{
	/*
	4
	1 2
	3 5
	1 4
	4 5
	*/
	vector<pro> pros;
	size_t n;
	int s, e;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> s >> e;
		pros.push_back(pro(s, e));
	}
	cout << "--- sort pros ---" << endl;
	sort(pros.begin(), pros.end(), mySort);
	for (auto p : pros)
	{
		cout << p.getStart() << " " << p.getEnd() << endl;
	}
	func(pros);
	cout << "--- res ---" << endl;
	cout << ::count << endl;
}

int temp = 0, ans = 0;
bool flag = false;

void dfs(vector<pro>& pros, int i)
{
	::flag = false;
	for (size_t j = 1; j < pros.size(); j++)
	{
		if (pros.at(j).getStart() >= pros.at(i).getEnd())
		{
			int u = pros.at(j).getTime();
			temp += u;
			dfs(pros, j);
			temp -= u;
			::flag = true;
		}
	}
	// 判断是否遍历结束
	if (::flag == false)
	{
		if (temp > ans)
		{
			ans = temp;
		}
	}
}

void test2()
{
	/*
	4
	1 2
	3 5
	1 4
	4 5
	*/
	vector<pro> pros;
	size_t n;
	int s, e;
	cin >> n;
	pros.push_back(pro(0, 0));
	for (size_t i = 1; i <= n; i++)
	{
		cin >> s >> e;
		pros.push_back(pro(s, e));
	}
	dfs(pros, 0);
	cout << "--- res ---" << endl;
	cout << ::ans << endl;
}

int main()
{
	test2();

	return 0;
}