#pragma once
#include <iostream>

const bool black = 1;
const bool red = 0;
template<typename T> struct Node
{
	T _val;
	bool _color;
	Node<T>* _left;
	Node<T>* _right;
	Node<T>* _parent;
};

template<typename T> class RBT
{
private:
	Node<T>* _root;
	Node<T>* _nil;
public:
	RBT();
	bool color_(const T&) const;
	Node<T>* root_() const;
	Node<T>* nil_()const;
	void left_rotate(Node<T>*);
	void right_rotate(Node<T>*);
	void insert_fix(Node<T>*);
	void insert(const T&);
	void display(Node<T>*, unsigned int) const;
	Node<T>* search(const T&) const;
};

template<typename T>
RBT<T>::RBT()
{
	_nil = new Node<T>;
	_nil->_left = _nil->_parent = _nil->_right = nullptr;
	_nil->_color = black;
	_root = _nil;
}

template<typename T>
bool RBT<T>::color_(const T& value)const
{
	return search(value)->_color;
}

template<typename T>
Node<T>* RBT<T>::root_()const
{
	return _root;
}

template<typename T>
Node<T>* RBT<T>::nil_()const
{
	return _nil;
}

template<typename T>
void RBT<T>::left_rotate(Node<T>* current)
{
	Node<T>* temp = current->_right;
	current->_right = temp->_left;
	if (temp->_left != _nil)
	{
		temp->_left->_parent = current;
	}
	if (temp != _nil)
	{
		temp->_parent = current->_parent;
	}
	if (current->_parent != _nil)
	{
		if (current == current->_parent->_left)
		{
			current->_parent->_left = temp;
		}
		else
		{
			current->_parent->_right = temp;
		}
	}
	else
	{
		_root = temp;
	}
	temp->_left = current;
	if (current != _nil)
	{
		current->_parent = temp;
	}
}

template<typename T>
void RBT<T>::right_rotate(Node<T> *current)
{
	Node<T> *temp = current->_left;
	current->_left = temp->_right;
	if (temp->_right != _nil)
	{
		temp->_right->_parent = current;
	}
	if (temp != _nil)
	{
		temp->_parent = current->_parent;
	}
	if (current->_parent != _nil)
	{
		if (current == current->_parent->_right)
		{
			current->_parent->_right = temp;
		}
		else
		{
			current->_parent->_left = temp;
		}
	}
	else
	{
		_root = temp;
	}
	temp->_right = current;
	if (current != _nil)
	{
		current->_parent = temp;
	}
}

template<typename T>
void RBT<T>::insert_fix(Node<T>* current)
{
	while (current != _root && current->_parent->_color == red)
	{
		if (current->_parent == current->_parent->_parent->_left)
		{
			Node<T>* temp = current->_parent->_parent->_right;
			if (temp->_color == red)
			{
				current->_parent->_color = black;
				temp->_color = black;
				current->_parent->_parent->_color = red;
				current = current->_parent->_parent;
			}
			else
			{
				if (current == current->_parent->_right)
				{
					current = current->_parent;
					left_rotate(current);
				}
				current->_parent->_color = black;
				current->_parent->_parent->_color = red;
				right_rotate(current->_parent->_parent);
			}
		}
		else
		{
			Node<T>* temp = current->_parent->_parent->_left;
			if (temp->_color == red)
			{
				current->_parent->_color = black;
				temp->_color = black;
				current->_parent->_parent->_color = red;
				current = current->_parent->_parent;
			}
			else
			{
				if (current == current->_parent->_left)
				{
					current = current->_parent;
					right_rotate(current);
				}
				current->_parent->_color = black;
				current->_parent->_parent->_color = red;
				left_rotate(current->_parent->_parent);
			}
		}
	}
	_root->_color = black;
}

template<typename T>
void RBT<T>::insert(const T& val)
{
	if (search(val))
	{
		std::cout << "This value's already added in the tree\n";
		return;
	}
	Node<T>* dau = new Node<T>;
	dau->_val = val;
	dau->_color = red;
	dau->_left = dau->_right = dau->_parent = _nil;
	Node<T>* par = _nil;
	Node<T>* temp = _root;
	if (_root == _nil)
	{
		_root = dau;
		_root->_color = black;
		return;
	}
	while (temp != _nil)
	{
		if (dau->_val == temp->_val)
		{
			return;
		}
		par = temp;
		if (val < temp->_val)
		{
			temp = temp->_left;
		}
		else
		{
			temp = temp->_right;
		}
	}
	if (val < par->_val)
	{
		par->_left = dau;
	}
	else
	{
		par->_right = dau;
	}
	dau->_parent = par;
	insert_fix(dau);
}

template<typename T>
void RBT<T>::display(Node<T>* temp, unsigned int level) const
{
	try
	{
		if (_root == _nil)
		{
			throw 2;
		}
		if (temp != _nil)
		{
			display(temp->_right, level + 1);
			
			for (unsigned int i = 0; i < level; i++)
			{
				std::cout << "____";
			}
			std::cout << "(" << temp->_color << ")";
			std::cout << temp->_val << "\n";
			display(temp->_left, level + 1);
		}
	}
	catch (int i)
	{
		std::cout << "There is nothing to print\nError #2\n";
	}
}

template<typename T>
Node<T>* RBT<T>::search(const T& value) const
{
	Node<T>* current = _root;
	while (current != _nil)
	{
		if (value == current->_val)
		{
			return current;
		}
		else
		{
			if (value < current->_val)
			{
				current = current->_left;
			}
			else
			{
				current = current->_right;
			}
		}
	}
	return 0;
}