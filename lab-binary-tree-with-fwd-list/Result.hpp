#ifndef RESULT_TYPE_HPP
#define RESULT_TYPE_HPP
#include <string>
#include "Printable.h"
using std::string;
using std::to_string;

// ������ ����������
// [surname] - �������
// [averageValue] - ������� ����
struct Result : public Printable
{
	string surname;
	double averageValue = 0;

	// ���������� � ������ � ���� ������ ���� [string]
	string toString() override
	{
		return string('(' + surname + ", " + to_string(averageValue) + ')');
	}
};
#endif
