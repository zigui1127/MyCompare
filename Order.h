#ifndef AAA_COMPARE_H
#define AAA_COMPARE_H

#include <string>
#include <cstdint>

namespace compare
{
	class OrderRule_
	{
	private:
		char str_[3];
	public:
		OrderRule_() = delete;
		OrderRule_(const std::string&);
		OrderRule_(const char*);
		~OrderRule_() = default;

		OrderRule_(const OrderRule_&) = delete;
		OrderRule_(OrderRule_&&) = delete;
		OrderRule_ &operator=(const OrderRule_&) = delete;
		OrderRule_ &operator=(OrderRule_&&) = delete;

		[[nodiscard]] bool useLess() const;
		[[nodiscard]] bool useGreater() const;
		[[nodiscard]] bool useEqual() const;
	};
	class Order
	{
	private:
		uint8_t val_;
		Order() = delete;
		Order(int val): val_(val) {}
	public:
		Order(const Order&);
		Order &operator=(const Order&);
		~Order() = default;

		bool operator==(const Order&) const;

		bool operator<(int) const;
		bool operator>(int) const;
		bool operator==(int) const;

		bool operator<=(const Order&) const = delete;
		bool operator>=(const Order&) const = delete;

		static Order buildGreater_() {return Order(2);}
		static Order buildLess_() {return Order(0);}
		static Order buildEqual_() {return Order(1);}
		static Order buildCannotCompare_() {return Order(3);}

		friend std::ostream &operator<<(std::ostream &, const Order &);
	};

	inline const Order greater = Order::buildGreater_();
	inline const Order less = Order::buildLess_();
	inline const Order equal = Order::buildEqual_();
	inline const Order cannot_compare = Order::buildCannotCompare_();

	template<typename T_>
	const Order &compare(const T_ &a, const T_ &b, const OrderRule_ &rules_ = "<=>")
	{
		if (rules_.useLess() && a < b)		return less;
		if (rules_.useEqual() && a == b)	return equal;
		if (rules_.useGreater() && a > b)	return greater;
		return cannot_compare;
	}
} // Compare

#endif //AAA_COMPARE_H
