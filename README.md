# MyCompare库

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

tips: 被废除的运算符compare函数是不会使用的。比如，如果你废除了==运算符，那么即使a == b，也只会返回cannot_compare

嗯，对，就这么多

你跟我要其他的介绍？

你自己看源代码不就行了？

嗯，绝对不是我懒得凑字数

然后，这个README就结束了。

我懒得写后面了，反正拜拜了您嘞