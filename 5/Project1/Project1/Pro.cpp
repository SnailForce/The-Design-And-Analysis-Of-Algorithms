#include <vector>
#include "Pro.h"

pro::pro(int start, int end)
{
	this->start = start;
	this->end = end;
}

pro::~pro()
{
}

int pro::getStart() const
{
	return this->start;
}

int pro::getEnd() const
{
	return this->end;
}

int pro::getTime() const
{
	return this->getEnd() - this->getStart();
}