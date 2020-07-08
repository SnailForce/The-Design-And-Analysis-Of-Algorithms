#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

constexpr auto N = 10;
constexpr auto INF = 10000;

// vector<int> path;

class TSP
{
private:
	size_t numOfCity;
	size_t r;
	vector<vector<int>> distance;
	vector<vector<int>> dp;
	vector<vector<int>> path;
public:
	TSP();
	void getShortestDistance();
	void printDP();
};

TSP::TSP()
{
	cout << "input citys' distance " << endl;
	cin >> numOfCity;
	r = 1 << (numOfCity - 1);
	/*
	10000 8 5 36
	6 10000 9 5
	8 8 10000 5
	7 7 8 10000
	*/
	for (size_t i = 0; i < numOfCity; i++)
	{
		vector<int> tmp;
		for (size_t j = 0; j < numOfCity; j++)
		{
			int u;
			cin >> u;
			tmp.push_back(u);
		}
		distance.push_back(tmp);
	}
	for (size_t i = 0; i < numOfCity; i++)
	{
		vector<int> tmp;
		tmp.assign(r, INF);
		dp.push_back(tmp);
	}
}

void TSP::getShortestDistance()
{
	for (size_t i = 0; i < numOfCity; i++)
	{
		dp.at(i).at(0) = distance.at(i).at(0);
	}
	for (size_t j = 1; j < r; j++)
	{
		for (size_t i = 0; i < numOfCity; i++)
		{
			if (i > 0 && ((j >> (i - 1)) & 1) == 1)
			{
				continue;
			}
			for (size_t k = 1; k < numOfCity; k++)
			{
				if ((j >> (k - 1) & 1) == 1)
				{
					if (dp.at(i).at(j) > distance.at(i).at(k) + dp.at(k).at(j ^ (1 << (k - 1))))
					{
						dp.at(i).at(j) = distance.at(i).at(k) + dp.at(k).at(j ^ (1 << (k - 1)));
					}
				}
			}
		}
	}
}

void TSP::printDP()
{
	for (size_t i = 0; i < numOfCity; i++)
	{
		for (size_t j = 0; j < r; j++)
		{
			cout << dp.at(i).at(j) << "\t";
		}
		cout << endl;
	}
	cout << "The length of the shortest path is " << dp.at(0).back() << endl;
}

int main()
{
	auto task = new TSP();
	task->getShortestDistance();
	task->printDP();
	return 0;
}