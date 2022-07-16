#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
#include "TreeNode.h"
using std::string;
using std::exception;

// �������� ������
// [head_] - ��������� �� �������� ����
// [isGreater_] - ��������� �� �������-���������� ��� ��������� ���� ��������� ���� [_Ty]
template <typename _Ty>
class BinaryTree : public Printable
{
	TreeNode<_Ty>* head_;
	bool (*isGreater_)(const _Ty&, const _Ty&);

	// ����������� ����� ���������� ������ ���� � ������� [data],
	// ������� �������� �������� ���������� � ���� [node]
	void addMethod_(TreeNode<_Ty>* node, const _Ty& data);

	// ����������� ����� ������ ���������� ������������� ������ �
	// [output], ������� �������� �������� � ���� [node]
	// � ������ ��� ���� ������ �� [stopLevel]. [spaceBefore] �
	// [spaceBetween] ��� ���� ������ �����������, ����������� �� ������
	// ����� � ����� ������ ��������������. [level] �� � ��� ����� ������
	// �������� ��������� ���������������� ����������.
	void toStringMethod_(TreeNode<_Ty>* node,
	                     string& output,
	                     int spaceBefore = 0,
	                     const int& spaceBetween = 10,
	                     const size_t& level = 0,
	                     const size_t& stopLevel = SIZE_MAX);

	void copyElementsMethod_(TreeNode<_Ty>* node);

	// ����������� ����� �������� ���� ����� � ������, ������� � [node]
	void clearMethod_(TreeNode<_Ty>* node);

public:
	// ���������� �������� ���� [BinaryTree], �������� ����:
	// [isGreater_] ���������� [isGreater]
	BinaryTree(bool (*isGreater)(const _Ty&, const _Ty&));

	// ���������� �������� ���� [BinaryTree], �������
	// �������� [other]
	BinaryTree(const BinaryTree<_Ty>& other);

	// ���������� ��������
	~BinaryTree();

	// ������� ������
	void clear();

	// ���������, ����� �� ������
	bool isEmpty() const;

	// ��������� ����� ���� � ������� [data] 
	void add(const _Ty& data);

	// ���������� � ������ � ���� ������ ���� [string], �� [stopLevel] ���� ������
	string toString(const size_t& stopLevel);

	// ���������� � ������ � ���� ������ ���� [string]
	string toString() override;
};


#include "BinaryTree.tpp"
#endif
