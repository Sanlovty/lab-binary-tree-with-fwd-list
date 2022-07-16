#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <type_traits>
#include "Printable.h"
using std::is_base_of_v;

// ���� ������
// [data_] - ������, ������� �������� � ����
// [left_] - ��������� �� ����� ����-������
// [right_] - ��������� �� ������ ����-������
template <typename _Ty>
class TreeNode : public Printable
{
	// ��� ������ [toString] ��� [_Ty] ������ � ���� ����� ����������� ������ ������
	// toString(), ����� ������ ������������� �� [Printable], ����� ���� �����������
	// ���������� ��� `_Ty.toString()`
	static_assert(is_base_of_v<Printable, _Ty>, "_Ty must inherit from Printable");

	_Ty data_;
	TreeNode<_Ty>* left_;
	TreeNode<_Ty>* right_;

public:
	// ���������� �������� ���� [TreeNode]
	TreeNode();

	// ���������� �������� ���� [TreeNode], �������� ����:
	// [data_] ���������� [data]
	TreeNode(const _Ty& data);

	// ���������� �������� ���� [TreeNode], �������� ����:
	// [data_] ���������� [data]
	// [left_] ���������� [left] ����� ���������
	// [right_] ���������� [right] ����� ���������
	TreeNode(const _Ty& data,
	         TreeNode<_Ty>* left,
	         TreeNode<_Ty>* right);

	// ���������� �������� ���� [TreeNode], �������� ����:
	// [data_] ���������� [data]
	// [left_] ���������� [left] ����� ������
	// [right_] ���������� [right] ����� ������
	TreeNode(const _Ty& data,
	         TreeNode<_Ty>& left,
	         TreeNode<_Ty>& right);

	// ���������, ���� �� ����� ����-������
	bool isLeftEmpty() const;

	// ���������, ���� �� ������ ����-������
	bool isRightEmpty() const;

	// ���������, ����� �� ��� ����-������
	bool isBothEmpty() const;

	// �������� [isBothEmpty]
	bool isBothNotEmpty() const;

	// ���������� ������, ���������� � ����
	_Ty getData() const;

	// ���������� ��������� �� ����� ����-������
	TreeNode<_Ty>* getLeft() const;

	// ���������� ��������� �� ������ ����-������
	TreeNode<_Ty>* getRight() const;

	// ������������� �������� [data_] ���������� [data]
	void setData(const _Ty& data);

	// ������������� �������� [left_] ���������� [left] ����� ���������
	void setLeft(TreeNode<_Ty>* left);

	// ������������� �������� [left_] ���������� [left] ����� ������
	void setLeft(TreeNode<_Ty>& left);

	// ������������� �������� [right_] ���������� [right] ����� ���������
	void setRight(TreeNode<_Ty>* right);

	// ������������� �������� [right_] ���������� [right] ����� ������
	void setRight(TreeNode<_Ty>& right);

	// ���������� � ������ � ���� ������ ���� [string]
	string toString() override;
};

#include "TreeNode.tpp"
#endif
