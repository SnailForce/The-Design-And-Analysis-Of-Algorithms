#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int getCount = 0;
// ͳ����Ӳ��������
int getSum(const vector<int>& v, int left, int right)
{
	int sum = 0;
	for (size_t i = left; i <= right; ++i)
	{
		sum += v.at(i);
	}
	return sum;
}
// ��ƽ �ж�����Ӳ���Ƿ����
bool isEqual(const vector<int>& v, int l1, int r1, int l2, int r2)
{
	::getCount += 1;
	int sum1 = getSum(v, l1, r1);
	int sum2 = getSum(v, l2, r2);
	return sum1 == sum2 ? true : false;
}
// ���η�����
int search(vector<int>& co, int left, int right)
{
	int count = right - left + 1;
	// ��öӲ�ҵ�����������жϼ���
	if (count == 3)
	{
		if (isEqual(co, left, left, left + 1, left + 1))
		{
			return left + 2;
		}
		else if (isEqual(co, left, left, left + 2, left + 2))
		{
			return left + 1;
		}
		else
		{
			return left;
		}
	}
	int add = count / 3;
	if (count > 3)
	{
		// ���ȷ֣����޷����ȷ֣���ǰ��������ȣ�ʣ��Ϊ��������
		// ���˵�����ϸ�Ӳ���ڵ������֣������˵�����ϸ�Ӳ����ǰ������
		if (isEqual(co, left, left + add - 1, left + add, left + add * 2 - 1))
		{
			// 1 1 2
			if (right - left - add * 2 + 1 <= 2)
			{
				if (isEqual(co, left, left, left + add * 2, left + add * 2))
				{
					return left + add * 2 + 1;
				}
				else
				{
					return left + add * 2;
				}
			}
			else
			{
				return search(co, left + add * 2, right);
			}
		}
		else
		{
			if (add == 1)
			{
				if (isEqual(co, left + add * 2, left + add * 2, left, left))
				{
					return left + add;
				}
				else
				{
					return left;
				}
			}
			else
			{
				return search(co, left, left + add * 2 - 1);
			}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int cur = rand() % 50 + 3;
	cout << "Size is " << cur << endl;
	vector<int> coins(cur, 2);
	int cur2 = rand() % cur;
	cout << "The unqualified coins set in " << cur2 << endl;
	coins.at(cur2) = 1;
	int left = 0;
	int right = coins.size() - 1;
	for (int v : coins)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "The searched coins set in " << search(coins, left, right) << endl;
	cout << "Weighing times is :" << ::getCount << endl;

}