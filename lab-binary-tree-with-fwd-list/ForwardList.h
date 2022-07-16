#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <exception>
#include <string>
#include "ForwardListNode.h"

using std::string;
using std::exception;

// Односвязный линейный список
// [head_] - указатель на корневой (первый) элемент
template <typename _Ty>
class ForwardList : public Printable
{
	ForwardListNode<_Ty>* head_;
public:
	// Возвращает сущность типа [ForwardList]
	ForwardList();

	// Возвращает сущность типа [TreeNode], копируя
	// сущность [other]
	ForwardList(const ForwardList<_Ty>& other);

	// Уничтожает сущность
	~ForwardList();

	// Добавляет новый узел в конец с данными [data]
	void pushBack(const _Ty& data);

	// Добавляет новый узел в начало с данными [data]
	void pushFront(const _Ty& data);

	// Удаляет первый узел
	void popFront();

	// Удаляет последний узел
	void popBack();

	// Добавляет новый узел в конец с данными [data] в приорите
	// возрастания, операюсь на функцию-компаратор [isGreater]
	void pushByPriorityAsc(const _Ty& data, bool (*isGreater)(const _Ty&, const _Ty&));

	// Добавляет новый узел в конец с данными [data] в приорите
	// убыванию, операюсь на функцию-компаратор [isGreater]
	void pushByPriorityDesc(const _Ty& data, bool (*isGreater)(const _Ty&, const _Ty&));

	// Информация о классе в виде данных типа [string]
	string toString() override;

	// Проверяет, пуст ли список
	bool isEmpty() const;

	// Возвращает данные, хранимые в корневом (первом) узле
	_Ty front() const;
};

#include "ForwardList.tpp"
#endif
