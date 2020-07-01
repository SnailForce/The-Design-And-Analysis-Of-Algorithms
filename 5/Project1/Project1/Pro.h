#pragma once
class pro
{
public:
	pro(int, int);
	~pro();
	int getStart() const;
	int getEnd() const;
	int getTime() const;

private:
	int start;
	int end;
};
