#ifndef BINARY_TREE_TPP
#define BINARY_TREE_TPP
#include "BinaryTree.h"

template <typename _Ty>
void BinaryTree<_Ty>::addMethod_(TreeNode<_Ty>* node, const _Ty& data)
{
	if (isGreater_(node->getData(), data))
	{
		if (node->getLeft() != nullptr)
		{
			addMethod_(node->getLeft(), data);
		}
		else
		{
			TreeNode<_Ty>* newNode = new TreeNode<_Ty>(data);
			node->setLeft(newNode);
		}
	}
	else if (!isGreater_(node->getData(), data))
	{
		if (node->getRight() != nullptr)
		{
			addMethod_(node->getRight(), data);
		}
		else
		{
			TreeNode<_Ty>* newNode = new TreeNode<_Ty>(data);
			node->setRight(newNode);
		}
	}
	else
	{
		throw exception("Try to add data, that already contained");
	}
}

template <typename _Ty>
BinaryTree<_Ty>::BinaryTree(bool (*isGreater)(const _Ty&, const _Ty&)) :
	head_(nullptr),
	isGreater_(isGreater)
{
}

template <typename _Ty>
void BinaryTree<_Ty>::copyElementsMethod_(TreeNode<_Ty>* node)
{
	if(node == nullptr)
	{
		return;
	}
	add(node->getData());
	copyElementsMethod_(node->getLeft());
	copyElementsMethod_(node->getRight());
}

template<typename _Ty>
BinaryTree<_Ty>::BinaryTree(const BinaryTree<_Ty>& other)
: isGreater_(other.isGreater_)
{
	copyElementsMethod_(other.head_);
}

template <typename _Ty>
BinaryTree<_Ty>::~BinaryTree()
{
	clear();
}

template <typename _Ty>
void BinaryTree<_Ty>::clear()
{
	clearMethod_(head_);
}

template <typename _Ty>
bool BinaryTree<_Ty>::isEmpty() const
{
	return head_ == nullptr;
}

template <typename _Ty>
void BinaryTree<_Ty>::add(const _Ty& data)
{
	if (isEmpty())
	{
		head_ = new TreeNode<_Ty>(data);
		return;
	}
	addMethod_(head_, data);
}


template <typename _Ty>
void BinaryTree<_Ty>::toStringMethod_(TreeNode<_Ty>* node,
                                      string& output,
                                      int spaceBefore,
                                      const int& spaceBetween,
                                      const size_t& level,
                                      const size_t& stopLevel)
{
	if (node == nullptr || level >= stopLevel)
	{
		return;
	}

	spaceBefore += spaceBetween;
	toStringMethod_(node->getRight(), output, spaceBefore, spaceBetween, level + 1, stopLevel);

	output += "\n";
	for (int i = spaceBetween; i < spaceBefore; i++)
	{
		output += " ";
	}
	output += node->toString() + '\n';

	toStringMethod_(node->getLeft(), output, spaceBefore, spaceBetween, level + 1, stopLevel);
}

template <typename _Ty>
void BinaryTree<_Ty>::clearMethod_(TreeNode<_Ty>* node)
{
	if (node == nullptr)
	{
		return;
	}
	clearMethod_(node->getLeft());
	clearMethod_(node->getRight());

	delete node;
}

template <typename _Ty>
string BinaryTree<_Ty>::toString(const size_t& stopLevel)
{
	string output;
	toStringMethod_(head_, output, 5, 10, 0, stopLevel);
	return output;
}
template <typename _Ty>
string BinaryTree<_Ty>::toString()
{
	string output;
	toStringMethod_(head_, output);
	return output;
}
#endif
