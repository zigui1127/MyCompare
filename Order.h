#ifndef AAA_COMPARE_H
#define AAA_COMPARE_H

#include <string>
#include <cstdint>

namespace compare
{
	enum class OrderValue_ : std::uint8_t
	{
		less_				= 0,
		equal_				= 1,
		greater_			= 2,
		cannot_compare_		= 3
	};

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
		OrderRule_(OrderRule_&&);
		OrderRule_ &operator=(const OrderRule_&) = delete;
		OrderRule_ &operator=(OrderRule_&&) = delete;

		[[nodiscard]] bool useLess() const;
		[[nodiscard]] bool useGreater() const;
		[[nodiscard]] bool useEqual() const;
	};
	class Order
	{
	private:
		OrderValue_ val_;
		Order() = delete;
		Order(const OrderValue_ &other_) : val_(other_) {}
		Order(int val) : val_(static_cast<OrderValue_>(val)) {}
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

		static Order buildGreater_() {return {OrderValue_::greater_};}
		static Order buildLess_() {return {OrderValue_::less_};}
		static Order buildEqual_() {return {OrderValue_::equal_};}
		static Order buildCannotCompare_() {return {OrderValue_::cannot_compare_};}

		friend std::ostream &operator<<(std::ostream &, const Order &);
	};

	inline const Order greater			= Order::buildGreater_();
	inline const Order less				= Order::buildLess_();
	inline const Order equal			= Order::buildEqual_();
	inline const Order cannot_compare	= Order::buildCannotCompare_();

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
