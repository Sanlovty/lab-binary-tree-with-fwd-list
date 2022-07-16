#ifndef TREE_NODE_TPP
#define TREE_NODE_TPP

#include "TreeNode.h"

template <typename _Ty>
TreeNode<_Ty>::TreeNode() :
data_(_Ty()),
left_(nullptr),
right_(nullptr)
{
}

template <typename _Ty>
TreeNode<_Ty>::TreeNode(const _Ty& data) :
data_(data),
left_(nullptr),
right_(nullptr)
{
}

template <typename _Ty>
TreeNode<_Ty>::TreeNode(
	const _Ty& data,
	TreeNode<_Ty>* left,
	TreeNode<_Ty>* right) :
data_(data),
left_(left),
right_(right)
{
}

template <typename _Ty>
TreeNode<_Ty>::TreeNode(
	const _Ty& data, 
	TreeNode<_Ty>& left,
	TreeNode<_Ty>& right) :
data_(data),
left_(&left),
right_(&right)
{
}

template <typename _Ty>
bool TreeNode<_Ty>::isLeftEmpty() const
{
	return left_ == nullptr;
}

template <typename _Ty>
bool TreeNode<_Ty>::isRightEmpty() const
{
	return right_ == nullptr;
}

template <typename _Ty>
bool TreeNode<_Ty>::isBothEmpty() const
{
	return left_ == nullptr && right_ == nullptr;
}

template <typename _Ty>
bool TreeNode<_Ty>::isBothNotEmpty() const
{
	return left_ != nullptr && right_ != nullptr;
}

template <typename _Ty>
_Ty TreeNode<_Ty>::getData() const
{
	return data_;
}

template <typename _Ty>
TreeNode<_Ty>* TreeNode<_Ty>::getLeft() const
{
	return left_;
}

template <typename _Ty>
TreeNode<_Ty>* TreeNode<_Ty>::getRight() const
{
	return right_;
}

template <typename _Ty>
void TreeNode<_Ty>::setData(const _Ty& data)
{
	data_ = data;
}

template <typename _Ty>
void TreeNode<_Ty>::setLeft(TreeNode<_Ty>* left)
{
	left_ = left;
}

template <typename _Ty>
void TreeNode<_Ty>::setLeft(TreeNode<_Ty>& left)
{
	left_ = &left;
}
template <typename _Ty>
void TreeNode<_Ty>::setRight(TreeNode<_Ty>* right)
{
	right_ = right;
}

template <typename _Ty>
void TreeNode<_Ty>::setRight(TreeNode<_Ty>& right)
{
	right_ = &right;
}

template <typename _Ty>
string TreeNode<_Ty>::toString()
{
	return data_.toString();
}
#endif
