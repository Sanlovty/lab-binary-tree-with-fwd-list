#ifndef FORWARD_LIST_TPP
#define FORWARD_LIST_TPP
#include "ForwardList.h"
using std::is_same;

template<typename _Ty>
ForwardList<_Ty>::ForwardList() : head_(nullptr)
{
}

template<typename _Ty>
ForwardList<_Ty>::ForwardList(const ForwardList<_Ty>& other)
{
	if (other.isEmpty())
	{
		head_ = nullptr;
		return;
	}
	head_ = new ForwardListNode<_Ty>(other.front());
	ForwardListNode<_Ty>* myIt = head_;
	ForwardListNode<_Ty>* otherIt = other.head_;
	while (otherIt->getNext() != nullptr)
	{
		otherIt = otherIt->getNext();
		ForwardListNode<_Ty>* newNode = new ForwardListNode<_Ty>(otherIt->getData());
		myIt->setNext(newNode);
		myIt = myIt->getNext();
	}
}

template<typename _Ty>
ForwardList<_Ty>::~ForwardList()
{
	while (!isEmpty())
	{
		popFront();
	}
}

template<typename _Ty>
void  ForwardList<_Ty>::pushBack(const _Ty& data)
{
	ForwardListNode<_Ty>* newNode = new ForwardListNode<_Ty>(data);
	if (isEmpty())
	{
		head_ = newNode;
		return;
	}
	ForwardListNode<_Ty>* it = head_;
	while (it->getNext() != nullptr)
	{
		it = it->getNext();
	}

	it->setNext(newNode);
}

template<typename _Ty>
void ForwardList<_Ty>::pushFront(const _Ty& data)
{
	ForwardListNode<_Ty>* newNode = new ForwardListNode<_Ty>(data, head_);
	if (isEmpty())
	{
		head_ = newNode;
		return;
	}
	head_ = newNode;
}

template<typename _Ty>
void ForwardList<_Ty>::popFront()
{
	if (isEmpty())
	{
		throw exception("Try to popFront element from empty list");
	}
	const ForwardListNode<_Ty>* willBeDeleted = head_;
	head_ = head_->getNext();
	delete willBeDeleted;
}

template<typename _Ty>
void ForwardList<_Ty>::popBack()
{
	if (isEmpty())
	{
		throw exception("Try to popBack element from empty list");
	}
	ForwardListNode<_Ty>* it = head_;
	if (it->getNext() == nullptr)
	{
		delete head_;
		head_ = nullptr;
		return;
	}
	while (it->getNext()->getNext() != nullptr)
	{
		it = it->getNext();
	}
	const ForwardListNode<_Ty>* willBeDeleted = it->getNext();
	it->setNext(nullptr);
	delete willBeDeleted;
}

template<typename _Ty>
void ForwardList<_Ty>::pushByPriorityAsc(const _Ty& data, bool (*isGreater)(const _Ty&,const _Ty&))
{
	if (isEmpty() || isGreater(head_->getData(), data))
	{
		pushFront(data);
		return;
	}
	if (head_->getNext() == nullptr)
	{
		if (isGreater(head_->getData(), data))
		{
			pushFront(data);
		}
		else
		{
			pushBack(data);
		}
		return;
	}
	ForwardListNode<_Ty>* it = head_;
	while (it->getNext() != nullptr && !isGreater(it->getNext()->getData(), data))
	{
		it = it->getNext();
	}
	ForwardListNode<_Ty>* newNode = new ForwardListNode<_Ty>(data, it->getNext());
	it->setNext(newNode);
}

template<typename _Ty>
void ForwardList<_Ty>::pushByPriorityDesc(const _Ty& data, bool (*isGreater)(const _Ty&,const _Ty&))
{
	if (isEmpty() || !isGreater(head_->getData(), data))
	{
		pushFront(data);
		return;
	}
	if (head_->getNext() == nullptr)
	{
		if (!isGreater(head_->getData(), data))
		{
			pushFront(data);
		}
		else
		{
			pushBack(data);
		}
		return;
	}
	ForwardListNode<_Ty>* it = head_;
	while (it->getNext() != nullptr && isGreater(it->getNext()->getData(), data))
	{
		it = it->getNext();
	}
	ForwardListNode<_Ty>* newNode = new ForwardListNode<_Ty>(data, it->getNext());
	it->setNext(newNode);
}

template <typename _Ty>
string ForwardList<_Ty>::toString()
{
	string str = "[";
	ForwardListNode<_Ty>* tmp = head_;
	while (tmp != nullptr)
	{
		str += ' ' + tmp->toString() + ',';
		tmp = tmp->getNext();
	}
	if (!isEmpty())
	{
		str[str.length() - 1] = ' ';
	}
	str += ']';
	return str;
}

template<typename _Ty>
bool ForwardList<_Ty>::isEmpty() const
{
	return head_ == nullptr;
}

template<typename _Ty>
_Ty ForwardList<_Ty>::front() const
{
	if (isEmpty())
	{
		throw exception("Try to take front element from empty list");
	}
	return head_->getData();
}
#endif
