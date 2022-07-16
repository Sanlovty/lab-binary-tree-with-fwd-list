#ifndef RESULT_TYPE_HPP
#define RESULT_TYPE_HPP
#include <string>
#include "Printable.h"
using std::string;
using std::to_string;

// Модель результата
// [surname] - фамилия
// [averageValue] - средний балл
struct Result : public Printable
{
	string surname;
	double averageValue = 0;

	// Информация о классе в виде данных типа [string]
	string toString() override
	{
		return string('(' + surname + ", " + to_string(averageValue) + ')');
	}
};
#endif
