# MyCompare库
## compare 命名空间

compare 命名空间是用在存放 Order 类的一个命名空间，内置了许多(1个)函数，以及N个内部类，以后还会更新内部内容，那就再说

## 用法
``` cpp
#include "Order.h"
using namespace compare;

int a = 0, b = 1;   // 这是核心
/*
 * compare()函数 
 * 用来生成Order类的引用，可用来和great，equal，less进行==比较，同时，一个单独的Order对象可以和数字进行比较
*/
Order o = compare(a, b, "<!>"); // 这里"<!>"代表使用<, >，但废除==，一般情况下不用填，默认参数是"<=>"

std::cout << o << std::endl;    // 可以直接输出Order对象，至于效果，你自己用的时候不就知道了？

```

## Order 类的一些说明

* Order 类允许使用拷贝、移动构造和赋值，但移动构造、移动赋值没有单独写出。
* 被废除的运算符compare函数是**不会**使用的。比如，如果你废除了==运算符，那么即使a == b，也只会返回*cannot_compare*
* Order类内置了*great*, _less_, _equal_ 和 _cannot_compare_ 四个静态变量，同时，内置了 _operator<<_ ，可以**直接** cout << 使用

## compare 库 API 约定

### Order 对象数字比较特殊规则
为了1:1还原C++内置的`compare`库, 所有 _Order_ 对象均可与整数进行比较，但**仅限于与 0 比较**

以上就是说明，总体来说，就没了。