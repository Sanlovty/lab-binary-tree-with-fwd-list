#ifndef FORWARD_LIST_NODE_H
#define FORWARD_LIST_NODE_H

#include <type_traits>
#include "Printable.h"
using std::is_base_of_v;

// ���� ������������ ��������� ������
// [data_] - ������, ���������� � ����
// [next_] - ��������� �� ��������� ����
template <typename _Ty>
class ForwardListNode : public Printable
{
	// ��� ������ [toString] ��� [_Ty] ������ � ���� ����� ����������� ������ ������
	// toString(), ����� ������ ������������� �� [Printable], ����� ���� �����������
	// ���������� ��� `_Ty.toString()`
	static_assert(is_base_of_v<Printable, _Ty>, "_Ty must inherit from Printable");

	_Ty data_;
	ForwardListNode<_Ty>* next_;
public:
	// ���������� �������� ���� [ForwardListNode]
	ForwardListNode();

	// ���������� �������� ���� [ForwardListNode], �������� ����:
	// [data_] ���������� [data]
	ForwardListNode(const _Ty& data);

	// ���������� �������� ���� [ForwardListNode], �������� ����:
	// [data_] ���������� [data]
	// [next_] ���������� [next]
	ForwardListNode(const _Ty& data, ForwardListNode<_Ty>* next);

	// ���������� ��������� �� ��������� ����
	ForwardListNode<_Ty>* getNext() const;

	// ���������� ������, ���������� � ����
	_Ty getData() const;


	// ������������� �������� [next_] ���������� [next] ����� ������
	void setNext(ForwardListNode<_Ty>* next);

	// ������������� �������� [next_] ���������� [next] ����� ���������
	void setNext(ForwardListNode<_Ty>& next);

	// ������������� �������� [data_] ���������� [data]
	void setData(const _Ty& data);

	// ���������� � ������ � ���� ������ ���� [string]
	string toString() override;
};

#include "ForwardListNode.tpp"
#endif
