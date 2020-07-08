#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
constexpr auto MAX = 20;
int cur = 0, result = 10000;
vector<int> data;
vector<int> machine;
vector<vector<int>> task;
vector<vector<int>> res;
void getData(ifstream& is)
{
	int tmp;
	// machine num
	is >> tmp;
	::machine.assign(tmp, 0);
	while (!is.eof())
	{
		is >> tmp;
		::data.push_back(tmp);
	}
	vector<int> t(::data.size(), 0);
	for (size_t i = 0; i < ::machine.size(); i++)
	{
		task.push_back(t);
	}
}
void dfs(unsigned int u)
{
	if (u == ::data.size())
	{
		// max machine element
		cur = *max_element(machine.begin(), machine.end());
		// update result
		if (cur < result)
		{
			result = cur;
			::res.assign(::task.begin(), ::task.end());
			return;
		}
	}
	else
	{
		for (size_t i = 0; i < ::machine.size(); i++)
		{
			if (::machine.at(i) + ::data.at(u) > result)
			{
				continue;
			}
			else
			{
				::machine.at(i) += ::data.at(u);
				::task.at(i).push_back(::data.at(u));
				dfs(u + 1);
				::machine.at(i) -= ::data.at(u);
				::task.at(i).pop_back();
			}
		}
	}
}
int main()
{
	ifstream is("./data.txt", ifstream::in);
	// input data
	getData(is);
	// reverse data
	sort(::data.rbegin(), ::data.rend());
	dfs(0);
	cout << "result: " << ::result << endl;
	int index = 1;
	for (auto m : ::res)
	{
		cout << "machine " << index << ": ";
		for (auto t : m)
		{
			if (t != 0)
			{
				cout << t << " ";

			}
		}
		cout << endl;
		++index;
	}
}