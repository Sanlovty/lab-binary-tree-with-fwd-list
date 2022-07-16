#ifndef FORWARD_LIST_NODE_TPP
#define FORWARD_LIST_NODE_TPP
#include "ForwardListNode.h"

template<typename _Ty>
ForwardListNode<_Ty>::ForwardListNode() : data_(_Ty()), next_(nullptr)
{
}
template<typename _Ty>
ForwardListNode<_Ty>::ForwardListNode(const _Ty& data) : data_(data), next_(nullptr)
{
}
template<typename _Ty>
ForwardListNode<_Ty>::ForwardListNode(const _Ty& data, ForwardListNode<_Ty>* next) : data_(data), next_(next)
{
}
template<typename _Ty>
ForwardListNode<_Ty>* ForwardListNode<_Ty>::getNext() const
{
	return next_;
}
template<typename _Ty>
_Ty ForwardListNode<_Ty>::getData() const
{
	return data_;
}
template<typename _Ty>
void ForwardListNode<_Ty>::setNext(ForwardListNode<_Ty>* next)
{
	next_ = next;
}
template<typename _Ty>
void ForwardListNode<_Ty>::setNext(ForwardListNode<_Ty>& next)
{
	next_ = &next;
}
template<typename _Ty>
void ForwardListNode<_Ty>::setData(const _Ty& data)
{
	data_ = data;
}

template <typename _Ty>
string ForwardListNode<_Ty>::toString()
{
	return data_.toString();
}
#endif