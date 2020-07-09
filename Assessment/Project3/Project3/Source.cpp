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
	r = 1 << (numOfCity - 1);  // dp����ÿһ�е�ά��
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
		tmp.assign(r, INF);  // ��ʼ��Ϊ���ֵ
		dp.push_back(tmp);
	}
}

void TSP::getShortestDistance()
{
	for (size_t i = 0; i < numOfCity; i++)
	{
		dp.at(i).at(0) = distance.at(i).at(0);  // ��һ���൱�ڴ�Դ��ֱ�ӵ���Ŀ�ĵ�
	}
	for (size_t j = 1; j < r; j++)
	{
		for (size_t i = 0; i < numOfCity; i++)
		{
			// �жϸ�����Ƿ����Դ��
			if (i > 0 && ((j >> (i - 1)) & 1) == 1)
			{
				continue;
			}
			for (size_t k = 1; k < numOfCity; k++)
			{
				// �ж�k�����Ƿ��ڵ�ǰ���j��
				if ((j >> (k - 1) & 1) == 1)
				{
					// dp����
					if (dp.at(i).at(j) > distance.at(i).at(k) + dp.at(k).at(j ^ (1 << (k - 1))))
					{
						dp.at(i).at(j) = distance.at(i).at(k) + dp.at(k).at(j ^ (1 << (k - 1)));
					}
				}
			}
		}
	}
}
// ��ӡdp����
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
	// ��һ�����һ���պ��ǽ��
	cout << "The length of the shortest path is " << dp.at(0).back() << endl;
}

int main()
{
	auto task = new TSP();
	task->getShortestDistance();
	task->printDP();
	return 0;
}