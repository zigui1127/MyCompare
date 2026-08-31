#include "Order.h"

#include <cstring>

namespace compare
{
	OrderRule_::OrderRule_(const std::string& str_)
	{
		if (str_.size() != 3)
			throw std::runtime_error("OrderRule_::OrderRule_(): 字符串长度小于3，无法构造OrderRule_对象");
		for (int i = 0; i < 3; i++)
			this->str_[i] = str_[i];
	}

	OrderRule_::OrderRule_(const char* str_)
	{
		if (str_ == nullptr || strlen(str_) != 3)
			throw std::runtime_error("OrderRule_::OrderRule_(): 字符串长度小于3，无法构造OrderRule_对象");
		for (int i = 0; i < 3; i++)
			this->str_[i] = str_[i];
	}

	OrderRule_::OrderRule_(OrderRule_ &&other_)
	{
		if (other_.str_ == nullptr || strlen(other_.str_) != 3)
			throw std::runtime_error("OrderRule_::OrderRule_(): 字符串长度小于3，无法构造OrderRule_对象");
		for (int i = 0; i < 3; i++)
			this->str_[i] = other_.str_[i];
	}

	bool OrderRule_::useEqual() const
	{
		if (this->str_[1] != '=' && this->str_[1] != '!')
			throw std::runtime_error("OrderRule_::useEqual(): str_[1]为非法字符");
		return (this->str_[1] == '=');
	}

	bool OrderRule_::useGreater() const
	{
		if (this->str_[2] != '>' && this->str_[2] != '!')
			throw std::runtime_error("OrderRule_::useGreater(): str_[2]为非法字符");
		return (this->str_[2] == '>');
	}

	bool OrderRule_::useLess() const
	{
		if (this->str_[0] != '<' && this->str_[0] != '!')
			throw std::runtime_error("OrderRule_::useLess(): str_[0]为非法字符");
		return (this->str_[0] == '<');
	}

	Order::Order(const Order& other_)
	{
		this->val_ = other_.val_;
	}

	Order& Order::operator=(const Order& other_)
	{
		this->val_ = other_.val_;
		return *this;
	}

	bool Order::operator==(const Order& other_) const
	{
		return (this->val_ == other_.val_);
	}

	bool Order::operator==(int val_) const
	{
		if (val_ != 0 || this->val_ == OrderValue_::cannot_compare_)
			throw std::runtime_error("Order::operator==(): 未知的操作: 与不为0的数比较或将cannot_compare与其它数字进行比较");

		return (this->val_ == static_cast<OrderValue_>(val_));
	}

	bool Order::operator>(int val_) const
	{
		if (val_ != 0 || this->val_ == OrderValue_::cannot_compare_)
			throw std::runtime_error("Order::operator>(): 未知的操作: 与不为0的数比较或将cannot_compare与其它数字进行比较");

		return (this->val_ > static_cast<OrderValue_>(val_));
	}

	bool Order::operator<(int val_) const
	{
		if (val_ != 0 || this->val_ == OrderValue_::cannot_compare_)
			throw std::runtime_error("Order::operator<(): 未知的操作: 与不为0的数比较或将cannot_compare与其它数字进行比较");

		return (this->val_ < static_cast<OrderValue_>(val_));
	}

	std::ostream &operator<<(std::ostream &os, const Order &order_)
	{
		if (order_.val_ == static_cast<OrderValue_>(0))	os << "小于";
		else if (order_.val_ == static_cast<OrderValue_>(1))	os << "等于";
		else if (order_.val_ == static_cast<OrderValue_>(2))	os << "大于";
		else	os << "无法比较";

		return os;
	}
} // Compare