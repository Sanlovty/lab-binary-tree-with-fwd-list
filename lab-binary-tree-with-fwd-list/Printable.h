#ifndef PRINTABLE_TYPE_H
#define PRINTABLE_TYPE_H
#include <string>
using std::string;

// Интерфейс для классов со строковым представлением
class Printable
{
public:
	// Информация о классе в виде данных типа [string]
	virtual string toString() = 0;
};
#endif
