#ifndef PRINTABLE_TYPE_H
#define PRINTABLE_TYPE_H
#include <string>
using std::string;

// ��������� ��� ������� �� ��������� ��������������
class Printable
{
public:
	// ���������� � ������ � ���� ������ ���� [string]
	virtual string toString() = 0;
};
#endif
