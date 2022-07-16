#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <type_traits>
#include "Printable.h"
using std::is_base_of_v;

// Узел дерева
// [data_] - данные, которые хранятся в узле
// [left_] - указатель на левый узел-ребёнок
// [right_] - указатель на правый узел-ребёнок
template <typename _Ty>
class TreeNode : public Printable
{
	// Для метода [toString] тип [_Ty] должен в себе иметь возможность вызова метода
	// toString(), иначе говоря наследоваться от [Printable], чтобы была возможнсоть
	// испольнить код `_Ty.toString()`
	static_assert(is_base_of_v<Printable, _Ty>, "_Ty must inherit from Printable");

	_Ty data_;
	TreeNode<_Ty>* left_;
	TreeNode<_Ty>* right_;

public:
	// Возвращает сущность типа [TreeNode]
	TreeNode();

	// Возвращает сущность типа [TreeNode], заполняя поля:
	// [data_] параметром [data]
	TreeNode(const _Ty& data);

	// Возвращает сущность типа [TreeNode], заполняя поля:
	// [data_] параметром [data]
	// [left_] параметром [left] через указатель
	// [right_] параметром [right] через указатель
	TreeNode(const _Ty& data,
	         TreeNode<_Ty>* left,
	         TreeNode<_Ty>* right);

	// Возвращает сущность типа [TreeNode], заполняя поля:
	// [data_] параметром [data]
	// [left_] параметром [left] через ссылку
	// [right_] параметром [right] через ссылку
	TreeNode(const _Ty& data,
	         TreeNode<_Ty>& left,
	         TreeNode<_Ty>& right);

	// Проверяет, пуст ли левый узел-ребёнок
	bool isLeftEmpty() const;

	// Проверяет, пуст ли правый узел-ребёнок
	bool isRightEmpty() const;

	// Проверяет, пусты ли оба узла-ребёнка
	bool isBothEmpty() const;

	// Инверсия [isBothEmpty]
	bool isBothNotEmpty() const;

	// Возвращает данные, хранящиеся в узле
	_Ty getData() const;

	// Возвращает указатель на левый узел-ребёнок
	TreeNode<_Ty>* getLeft() const;

	// Возвращает указатель на правый узел-ребёнок
	TreeNode<_Ty>* getRight() const;

	// Устанавливает значение [data_] параметром [data]
	void setData(const _Ty& data);

	// Устанавливает значение [left_] параметром [left] через указатель
	void setLeft(TreeNode<_Ty>* left);

	// Устанавливает значение [left_] параметром [left] через ссылку
	void setLeft(TreeNode<_Ty>& left);

	// Устанавливает значение [right_] параметром [right] через указатель
	void setRight(TreeNode<_Ty>* right);

	// Устанавливает значение [right_] параметром [right] через ссылку
	void setRight(TreeNode<_Ty>& right);

	// Информация о классе в виде данных типа [string]
	string toString() override;
};

#include "TreeNode.tpp"
#endif
