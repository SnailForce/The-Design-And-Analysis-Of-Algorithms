#include <iostream>
#include <fstream>

#include "grid.h"
// �к��к�ȷ��vector������ֵ
int grid::indexof(int row, int col) const
{
	return row * cols + col;
}
// �жϸ�λ���Ƿ��Ⱦ
bool grid::infected(int row, int col) const
{
	return area->operator[](indexof(row, col)) == INFECTED;
}
// δʹ��
bool grid::visited(int row, int col) const
{
	return true;
}
// ����
grid::grid(string file)
{
	ifstream gridFile;
	gridFile.open(file);

	gridFile >> rows;
	gridFile >> cols;

	area = new vector<bool>(rows * cols, NOT_INFECTED);
	marks = new vector<bool>(rows * cols, NOT_INFECTED);

	while (!gridFile.eof())
	{
		int row, col;
		gridFile >> row >> col;
		area->operator[](indexof(row, col)) = INFECTED;
	}
	gridFile.close();
}
// ����
grid::~grid()
{
	delete area;
	delete marks;
}
// ͳ�Ƹ�Ⱦ�������С
int grid::count(int row, int col)
{
	// ��������
	if (row < 0 || row >= rows || col < 0 || col >= cols)
	{
		return 0;
	}
	// δ��Ⱦ
	if (grid::area->operator[](indexof(row, col)) == NOT_INFECTED)
	{
		return 0;
	}
	// ��Ⱦ�ѱ��
	if (grid::marks->operator[](indexof(row, col)) == INFECTED)
	{
		return 0;
	}
	// ��Ⱦδ���
	grid::marks->operator[](indexof(row, col)) = INFECTED;
	// �ߵ���ǰ����������ǰΪ��Ⱦδ��ǣ���˼�һ��Ȼ��������Χ�Ź���
	return 1 + grid::count(row - 1, col - 1) + grid::count(row - 1, col) + grid::count(row - 1, col + 1) + grid::count(row, col - 1) + grid::count(row, col + 1) + grid::count(row + 1, col - 1) + grid::count(row + 1, col) + grid::count(row + 1, col + 1);
}
// �����
ostream& operator<<(ostream& stream, const grid& ob)
{
	for (size_t i = 0; i < ob.rows; ++i)
	{
		for (size_t j = 0; j < ob.cols; ++j)
		{
			stream << ob.area->operator[](ob.indexof(i, j));
			// Ŀ���������Ⱦ+�ű��
			if (ob.marks->operator[](ob.indexof(i, j)))
			{
				stream << "+";
			}
			else
			{
				stream << " ";
			}
			if (j < ob.cols - 1)
			{
				stream << " ";
			}
		}
		stream << endl;
	}
	stream << endl;
	return stream;
}
