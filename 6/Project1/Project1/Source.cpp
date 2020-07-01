#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
// �������
constexpr auto MAX = 20;
unsigned int n, m;
vector<vector<int>> weight;
vector<vector<int>> value;
vector<int> bestX;
vector<int> x(MAX, 0);
unsigned int maxCost;
unsigned int curWeight, curValue, resWeight = 0xffffffff;
// �ݹ�
void bfs(unsigned int t)
{
	if (t == n)
	{
		resWeight = curWeight;
		bestX.assign(x.begin(), x.end());
	}
	else
	{
		for (size_t i = 0; i < m; i++)
		{
			// �жϳɱ��Ƿ񳬹�Ԥ���Լ���ǰ�����Ƿ񳬹��������
			if (curValue + value.at(t).at(i) <= maxCost && curWeight + weight.at(t).at(i) < resWeight)
			{
				// i��0��ʼ�������̴�1��ʼ
				x.at(t) = i + 1;
				curWeight += weight.at(t).at(i);
				curValue += value.at(t).at(i);
				bfs(t + 1);
				// ����
				curWeight -= weight.at(t).at(i);
				curValue -= value.at(t).at(i);
			}
		}
	}
}
int main()
{
	// ��ȡ�ļ�
	string infile = "./data.txt";
	vector<string> data;
	// ֻ��ģʽ
	ifstream is(infile, ifstream::in);
	if (is)
	{
		while (!is.eof())
		{
			string s;
			getline(is, s);
			if (s != "")
			{
				data.push_back(s);
			}
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	is.close();
	n = stoi(data.at(0));
	m = stoi(data.at(1));
	maxCost = stoi(data.at(2));
	cout << "n: " << n << " m: " << m << " cost: " << maxCost << endl;

	// ����������
	/*
	cout << "n: ";
	cin >> n;
	cout << "m: ";
	cin >> m;
	cout << "cost: ";
	cin >> maxCost;
	*/

	for (size_t i = 0; i < n; i++)
	{
		string cur = data.at(i + 3);
		stringstream input(cur);
		string res;
		vector<int> tmp;
		while (input >> res)
		{
			tmp.push_back(stoi(res));
		}
		weight.push_back(tmp);
	}
	for (size_t i = 0; i < n; i++)
	{
		string cur = data.at(i + n + 3);
		stringstream input(cur);
		string res;
		vector<int> tmp;
		while (input >> res)
		{
			tmp.push_back(stoi(res));
		}
		value.push_back(tmp);
	}
	// ��ӡ
	cout << "weight: " << endl;
	for (auto u : weight)
	{
		for (auto r : u)
		{
			cout << r << " ";
		}
		cout << endl;
	}
	cout << "value: " << endl;
	for (auto u : value)
	{
		for (auto r : u)
		{
			cout << r << " ";
		}
		cout << endl;
	}
	bfs(0);
	cout << "-- res --" << endl;
	cout << "best x: ";
	for (size_t u = 0; u < n; u++)
	{
		cout << bestX.at(u) << " ";
	}
	cout << endl;
	cout << "best weight: " << resWeight << endl;

	return 0;
}