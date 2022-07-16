#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
#include "TreeNode.h"
using std::string;
using std::exception;

// Бинарное дерево
// [head_] - указатель на корневой узел
// [isGreater_] - указатель на функцию-компоратор для сравнения двух элементов типа [_Ty]
template <typename _Ty>
class BinaryTree : public Printable
{
	TreeNode<_Ty>* head_;
	bool (*isGreater_)(const _Ty&, const _Ty&);

	// Рекурсивный метод добавления нового узла с данными [data],
	// который начинает рекурсию добавления с узла [node]
	void addMethod_(TreeNode<_Ty>* node, const _Ty& data);

	// Рекурсивный метод вывода строкового представления дерева в
	// [output], который начинает рекурсию с узла [node]
	// и выводи все слои дерева до [stopLevel]. [spaceBefore] и
	// [spaceBetween] при этом служат параметрами, отвечающими за отсупы
	// после и между узлами соответственно. [level] же в своё время просто
	// является локальной переиспользуемой переменной.
	void toStringMethod_(TreeNode<_Ty>* node,
	                     string& output,
	                     int spaceBefore = 0,
	                     const int& spaceBetween = 10,
	                     const size_t& level = 0,
	                     const size_t& stopLevel = SIZE_MAX);

	void copyElementsMethod_(TreeNode<_Ty>* node);

	// Рекурсивный метод удаления всех узлов в дереве, начиная с [node]
	void clearMethod_(TreeNode<_Ty>* node);

public:
	// Возвращает сущность типа [BinaryTree], заполняя поля:
	// [isGreater_] параметром [isGreater]
	BinaryTree(bool (*isGreater)(const _Ty&, const _Ty&));

	// Возвращает сущность типа [BinaryTree], копируя
	// сущность [other]
	BinaryTree(const BinaryTree<_Ty>& other);

	// Уничтожает сущность
	~BinaryTree();

	// Очищает дерево
	void clear();

	// Проверяет, пусто ли дерево
	bool isEmpty() const;

	// Добавляет новый узел с данными [data] 
	void add(const _Ty& data);

	// Информация о классе в виде данных типа [string], до [stopLevel] слоя дерева
	string toString(const size_t& stopLevel);

	// Информация о классе в виде данных типа [string]
	string toString() override;
};


#include "BinaryTree.tpp"
#endif
