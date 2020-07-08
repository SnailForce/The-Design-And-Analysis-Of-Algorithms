#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

unsigned int n = 0;
vector<int> result;
vector<vector<int>> u;

int main()
{
	ifstream is("./data.txt", istream::in);
	ofstream os("./res.txt", ofstream::out);
	is >> n;
	for (size_t i = 0; i < n; i++)
	{
		int cur;
		is >> cur;
		u.push_back({cur, int(i) + 1});
	}
	sort(u.begin(), u.end(), [](const vector<int>& u1, const vector<int>& u2) {return u1.at(0) < u2.at(0); });
	for (size_t i = 0; i < n; i++)
	{
		int t = 0;
		for (size_t j = 0; j < i; j++)
		{
			t += u.at(j).at(0);
		}
		result.push_back(t);
	}
	int sum = 0;
	for (auto i = result.begin(); i < result.end(); i++)
	{
		sum += i.operator[](0);
	}
	os << "sorted data: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		os << u.at(i).at(0) << " " << u.at(i).at(1) << endl;
	}
	os << endl << "result: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		os << result.at(i) << " ";
	}
	os << endl;
	os << "sum: " << sum << endl;
	return 0;
}