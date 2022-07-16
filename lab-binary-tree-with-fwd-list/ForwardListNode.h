#ifndef FORWARD_LIST_NODE_H
#define FORWARD_LIST_NODE_H

#include <type_traits>
#include "Printable.h"
using std::is_base_of_v;

// ”зел односв€зного линейного списка
// [data_] - данные, хран€щиес€ в узле
// [next_] - указатель на следующий узел
template <typename _Ty>
class ForwardListNode : public Printable
{
	// ƒл€ метода [toString] тип [_Ty] должен в себе иметь возможность вызова метода
	// toString(), иначе говор€ наследоватьс€ от [Printable], чтобы была возможнсоть
	// испольнить код `_Ty.toString()`
	static_assert(is_base_of_v<Printable, _Ty>, "_Ty must inherit from Printable");

	_Ty data_;
	ForwardListNode<_Ty>* next_;
public:
	// ¬озвращает сущность типа [ForwardListNode]
	ForwardListNode();

	// ¬озвращает сущность типа [ForwardListNode], заполн€€ пол€:
	// [data_] параметром [data]
	ForwardListNode(const _Ty& data);

	// ¬озвращает сущность типа [ForwardListNode], заполн€€ пол€:
	// [data_] параметром [data]
	// [next_] параметром [next]
	ForwardListNode(const _Ty& data, ForwardListNode<_Ty>* next);

	// ¬озвращает указатель на следующий узел
	ForwardListNode<_Ty>* getNext() const;

	// ¬озвращает данные, хран€щиес€ в узле
	_Ty getData() const;


	// ”станавливает значение [next_] параметром [next] через ссылку
	void setNext(ForwardListNode<_Ty>* next);

	// ”станавливает значение [next_] параметром [next] через указатель
	void setNext(ForwardListNode<_Ty>& next);

	// ”станавливает значение [data_] параметром [data]
	void setData(const _Ty& data);

	// »нформаци€ о классе в виде данных типа [string]
	string toString() override;
};

#include "ForwardListNode.tpp"
#endif
