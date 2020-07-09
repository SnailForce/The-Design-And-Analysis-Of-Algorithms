#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

constexpr auto N = 10;
constexpr auto INF = 10000;

class TSP
{
private:
	size_t numOfCity;
	size_t r;
	vector<vector<int>> distance;
	vector<vector<int>> dp;
public:
	TSP();
	void getShortestDistance();
	void printDP();
};

TSP::TSP()
{
	cout << "input citys' num " << endl;
	cin >> numOfCity;
	r = 1 << (numOfCity - 1);  // dp矩阵每一行的维度
	cout << "input citys' distance " << endl;
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
		tmp.assign(r, INF);  // 初始化为最大值
		dp.push_back(tmp);
	}
}

void TSP::getShortestDistance()
{
	for (size_t i = 0; i < numOfCity; i++)
	{
		dp.at(i).at(0) = distance.at(i).at(0);  // 第一列相当于从源点直接到达目的点
	}
	for (size_t j = 1; j < r; j++)
	{
		for (size_t i = 0; i < numOfCity; i++)
		{
			// 判断该组合是否包含源点
			if (i > 0 && ((j >> (i - 1)) & 1) == 1)
			{
				continue;
			}
			for (size_t k = 1; k < numOfCity; k++)
			{
				// 判断k城市是否在当前组合j中
				if ((j >> (k - 1) & 1) == 1)
				{
					// dp方程
					if (dp.at(i).at(j) > distance.at(i).at(k) + dp.at(k).at(j ^ (1 << (k - 1))))
					{
						dp.at(i).at(j) = distance.at(i).at(k) + dp.at(k).at(j ^ (1 << (k - 1)));
					}
				}
			}
		}
	}
}
// 打印dp数组
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
	// 第一行最后一个刚好是结果
	cout << "The length of the shortest path is " << dp.at(0).back() << endl;
}

int main()
{
	auto task = new TSP();
	task->getShortestDistance();
	task->printDP();
	return 0;
}