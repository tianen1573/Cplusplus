

------

[TOC]

### 基础语法

##### 命名空间

> - 在C/C++中，变量、函数和类都是大量存在的, 这些变量、函数和类的名称若都存在于全局/局部作用域中, 可能会导致很多冲突. 使用命名空间的目的是对标识符的名称进行本地, 存放在各个不同的域中, 以避免命名冲突或名字污染, **namespace**关键字的出现就是针对这种问题的。
>
>
> - 定义命名空间，需要使用到**namespace**关键字，后面跟命名空间的名字，然后接一对{}即可，{}中即为命名空间的成员。
>

###### 命名空间定义

> 1. 定义命名空间
>
> ```c++
> namespace N1 // N1为命名空间的名称
> {}
> ```
>
> 2. 命名空间可嵌套
>
> ```c++
> namespace N1
> {
> 	int a;
>     int b;
>     namespace N2
>     {
>         int c;
>         int d;
> 	}
> }
> ```
>
> 3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
>
> ```
> // ps：一个工程中的test.h和上面test.cpp中两个N1会被合并成一个
> ```
>
> **注意：一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中**

###### 命名空间使用

> - ```
>     加命名空间名称及作用域限定符 N::a//每次使用都要限定, 推荐
>     ```
>
> - ```
>     使用using将命名空间中成员引入 using N::a//只取出a, 推荐
>     ```
>
> - ```
>     使用using namespace 命名空间名称引入 using namespace N//全部取出, OJ时推荐
>     ```
>

------



##### 缺省参数

> **缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实参则采用该 形参的缺省值，否则使用指定的实参。**
>
> ```C++
> void fun(int a = 10)
> {
>     cout << a * a << endl;
> }
> 
> int main()
> {
>     fun();//不传参, 此时形参a默认为10
>     fun(1);//传参, 指定实参
>     
>     return 0;
> }
> ```
>

###### 分类

> - 全缺省
>
> ```c++
> void fun(int a = 10, int b = 20, int c = 30)
> {
>      cout << "a = " << a << endl;
>      cout << "b = " << b << endl;
>      cout << "c = " << c << endl;
> }
> ```
>
> - 半缺省
>
> ~~~c++
> void fun(int a, int b, int c = 30)
> {
>      cout << "a = " << a << endl;
>      cout << "b = " << b << endl;
>      cout << "c = " << c << endl;
> }
> 
> ~~~
>

###### 注意事项

> 1. 半缺省参数必须从右往左依次来给出，不能间隔着给  
>
> ```c++
> //err
> void fun(int a = 10, int b, int c = 30)
> {}
> //必须从右至左
> 
> //在传参时,从左至右一次给形参赋值
> ```
>
> 2. 缺省参数不能在函数声明和定义中同时出现
>
> ```C++
> //原因
> 
> // a.h
> void fun(int a = 10);
> // a.cpp
> void fun(int a = 20)
> {}
> // 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省值。
> ```
>
> 3. 缺省值必须是常量或者全局变量
>
> ```c++
> //err
> int i = 0;//局部变量
> void fun(int a, int b = i, int c = 30)
> ```
>
> 4. C语言不支持（编译器不支持）

------

##### 函数重载

>  函数重载：是函数的一种特殊情况，C++允许在**同一作用域中**声明几个功能类似的**同名函数**，这些 同名函数 的**形参列表(参数个数 或 类型 或 类型顺序)不同**，常用来处理实现功能类似数据类型不同的问题。

###### 实现形式

> **同一作用域, 函数名相同, 形参列表不同, 和返回类型无关**
>
> ```C++
> //参数类型不同，参数顺序不同，参数个数不同
> int add(int a, int b);
> double add(double a, double b);//a-类型不同
> int add(int a, int b, int c);//a-个数不同
> void add(int a, char b);
> void add(char b, int a);//c-顺序不同
> ```
>

###### 为什么C++支持函数重载, 而C不

> **C++在编译阶段会对函数进行名字修饰, 通常以某种规则对函数 + 形参类型 进行转换作为函数的新名字**
>
> - 首先, 明确C++源码到程序的四个阶段: 预处理, 编译, 汇编, 链接
> - 在**编译阶段**, C++编译器会对函数进行**名字修饰**, 以某种方式将函数名转化为符合语法的**新名字**, 如以 函数名+形参类型 进行转化, 则 `fun(int, int)` 和`fun(int, double)` 转化后 为 `fii`和`fid`, 两个函数的名字就有了区分, 函数名和地址会一起存放在符号表中.
> -  在**链接阶段**, 若是同文件的函数调用, 在编译阶段就会CALL, 而不同文件的函数调用, 需要用**函数名**去文件的**符号表查函数对应的地址**. C++的函数经过转换, 同名函数可以区分. 而C就无法进行区分, 报错
>

###### extern "C"

> - 有时候在C++工程中可能需要将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，将该函数按照C语言规则来编译。
>
> - C++调用C库，需要引用头文件时extern "C",告诉编译器,以c语言的方式在该头文件寻找函数/变量
>
> - C调用C++库，需要 条件编译 + extern "C" h文件
>     - 条件编译: 编译时,文件 按 C语言规则编译制表
>     
>     - extern "C": 按照C语言标准查找函数
>     
>         
>

###### Other

> ```
> C++中 前置重载为正常重载, 后置重载需要在形参里增加一个int做标识
> 前置 Ref& operator++()
> 后置 Ref operator++(int)
> ```
>
> **两篇博客:**
> https://www.cnblogs.com/skynet/archive/2010/09/05/1818636.html
> https://blog.csdn.net/lioncolumn/article/details/10376891

------



#####    引用

> 引用不是新定义一个变量，而是给已存在变量取了一个**别名**，编译器不会为引用变量开辟内存空间，它和 **它引用的变量共用同一块内存空间**。

###### 使用

> 1. 
>
>     ```
>     //类型& 引用变量名(对象名) = 引用实体；
>     void TestRef()
>     {
>          int a = 10;
>          int& ra = a;//引用类型
>          printf("%p\n", &a);
>          printf("%p\n", &ra);
>     }
>     
>     void test()
>     {
>         int a = 10;
>         int& ra = a;
>         const int b = 10;
>         const int& crb = b;
>     }
>     ```
>
> 2. 做参数
>
>     ```c++
>     //相当于实参传指针(传址), 修改形参的值也会修改实参的值, 并且不会进行拷贝实参生成形参操作
>     void fun(int a, int& b)
>     {
>         a =  10;
>         b = 10;
>     }
>     
>     int main()
>     {
>         int a = 1, b = 1;
>         fun(a, b);
>         cout << a << ' ' << b << endl;
>         //1, 10
>     }
>     ```
>
> 3. 做返回值
>
>     ```c++
>     //返回值类型若为引用类型, 此时编译器不会拷贝返回值,则要求在函数结束时, 返回值的生命周期还在, 即返回值不能随函数结束而回收, 否则会发生内存泄漏
>                                                                                                         
>     int& fun()
>     {
>         static int a = 10;//全局域, 文件内而访问
>         int b = 10;//局部变量, 随函数结束而释放
>                                                                                                             
>         return b;//内存泄漏
>         //return a;//
>     }
>                                                                                                         
>     int main()
>     { 
>         int val = fun();
>         //接受到某个变量的引用, fun()结束时, b所在的空间已被释放, 造成内存泄漏
>                                                                                                             
>         return 0;
>     }
>     ```
>

###### 注意事项

> 1. 引用特性
>     - 引用在定义时必须初始化
>     - 一个变量可以有多个引用
>     - 一个引用在定义后就无法更改
>
> 2. 引用和指针的区别
>     - 引用在定义时必须初始化，指针没有要求
>     - 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型
>     - 没有NULL引用，但有NULL指针
>     - 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占4个字节)(数组和申请堆空间除外)
>     - 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
>     - 有多级指针，但是没有多级引用
>     - 访问实体方式不同，指针需要显式解引用，引用编译器自己处理
>     - 引用比指针使用起来相对更安全
>
> **引用的底层实现是用指针实现的**

------



##### 内联函数--建议性关键字

> **以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数调用建立栈帧 的开销，内联函数提升程序运行的效率。**

###### 简单了解

> ![image-20221002203826494](%E5%9B%BE%E7%89%87/README/image-20221002203826494.png)
>
> ![image-20221002204552313](%E5%9B%BE%E7%89%87/README/image-20221002204552313.png)
>
> 如果在上述函数前增加inline关键字将其改成内联函数，在编译期间编译器会用函数体替换函数的调用。 
>
> 查看方式：
>
> 1. 在release模式下，查看编译器生成的汇编代码中是否存在call Add 
>
> 2. 在debug模式下，需要对编译器进行设置，否则不会展开(因为debug模式下，编译器默认不会对代码进 行优化，以下给出vs2013的设置方式)
>
>     ![image-20221002204514881](%E5%9B%BE%E7%89%87/README/image-20221002204514881.png)
>

###### 特性

> - inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环/递归的函数不适宜使用作为内联函数。
> - inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
> - inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。(.cpp文件调用函数->通过.h文件的函数声明找出地址->call地址, 但inline展开后, 不会进符号表, 即没有这个函数了, call不到)
>

------



##### 面试问题

> **宏的优缺点？** 
>
> 优点： 
>
> 1. 增强代码的复用性
> 2. 提高性能。
>
> 缺点： 
>
> 1. 不方便调试宏。（因为预编译阶段进行了替换） 
> 2. 导致代码可读性差，可维护性差，容易误用。
> 3. 没有类型安全的检查 。
>
> **C++有哪些技术替代宏？**
>
> 1. 常量定义 换用const enum
> 2. 短小函数定义 换用内联函数
>
> **宏和define的区别**
>
> ![1658315233880](%E5%9B%BE%E7%89%87/README/1658315233880.png)

-----



##### extern & static

> ```
> extern 声明的全局变量， 写入符号表， 整个项目就一个
> static 修饰的变量，不写入符号表，仅当前文件
> ```
>

------



##### auto--自动推导变量类型

> auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，**auto声明的变量必须由编译器在编译时期推导而得。**
>
> 使用auto定义变量时必须对其**进行初始化**，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。因此auto**并非是一种“类型”的声明**，而是一个类型**声明时的“占位符”**，编译器在编译期会将auto**替换为变量实际的类型**。
>

###### 使用细则

> 1. auto与指针和引用结合起来使用, 用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&
>
>     ```c++
>     int main()
>     {
>         int x = 10;
>     
>         auto a = &x;//指针
>         auto* b = &x;//指针
>         auto& c = x;//引用
>     
>         return 0;
>     }
>     ```
>
> 2. 在同一行定义多个变量, 当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，因为编译器实际只对第一个类型进行推导，然后用推导出来的类型定义其他变量.
>
>     ```c++
>     void TestAuto()
>     {
>         auto a = 1, b = 2; 
>         auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
>     }
>     ```
>

###### auto不能推导的场景

> -  auto不能作为函数的参数
>
>     ```c++
>     // 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
>     void TestAuto(auto a)
>     {}
>     ```
>
> - auto不能直接用来声明数组
>
>     ```c++
>     void TestAuto()
>     {
>         int a[] = {1,2,3};
>         auto b[] = {4，5，6};
>     }
>     ```
>
> - 为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法
>
> - auto在实际中最常见的优势用法就是跟C++11提供的新式for循环，还有lambda表达式等进行配合使用。
>

#####  基于范围的for循环(C++11)

###### 范围for的语法

> 在C++98中如果要遍历一个数组，可以按照以下方式进行：
>
> ```C++
> void TestFor()
> {
>     int array[] = { 1, 2, 3, 4, 5 };
>     for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
>         array[i] *= 2;
> 
>     for (int* p = array; p < array + sizeof(array)/ sizeof(array[0]); ++p)
>         cout << *p << endl;
> }
> ```
>
> 对于一个**有范围的集合**而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。因此C++11中 引入了基于范围的for循环。for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量， 第二部分则表示被迭代的范围。
>
> ```C++
> void TestFor()
> {
>      int array[] = { 1, 2, 3, 4, 5 };
>      for(auto& e : array)
>      e *= 2;
> 
>      for(auto e : array)
>      cout << e << " ";
> 
>      return 0;
> }
> ```
>

###### 使用条件

> **范围for强调有范围的集合**: 对于数组而言，就是数组中第一个元素和最后一个元素的范围；对于类而言，应该提供begin和end的 方法，begin和end就是for循环迭代的范围。
>
> ~~~C++
> void fun(int arr[])
> {
>     for(auto val : arr)//此时编译器不了解arr的范围
>     {
>         cout << val << ' ';
>     }
> }
> 
> int main()
> {
>     int arr[] = {1, 2, 3, 4};
>     for(auto val : arr)//此时编译器了解arr的范围
>     {
>         cout << val << ' ';
>     }
>     
>     fun(arr)//err
>     
>     return 0;
> }
> ~~~
>
> **迭代的对象要实现++和--的操作。**

------



##### nullptr

> 1. NULL为假空指针,实为 宏 (int)0, nullptr 为 真空指针
> 2. 在使用nullptr表示指针空值时，不需要包含头文件，因为nullptr是C++11作为新关键字引入的。
> 3. 在C++11中，sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同。
> 4. 为了提高代码的健壮性，在后续表示指针空值时建议最好使用nullptr。
>

------



### 类和对象

> C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题。
>
> C++是基于面向对象的，关注的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成。
>

##### class关键字

> class为定义类的关键字，ClassName为类的名字，{}中为类的主体，注意类定义结束时后面分号不能省 略。
>
> 类体中内容称为类的成员：类中的变量称为类的属性或成员变量; 类中的函数称为类的方法或者成员函数。
>
> ```c++
> class className
> {
>  // 类体：由成员函数和成员变量组成
>  
> }; // 一定要注意后面的分号
> ```
>

**类的两种定义方式：**

> 1. 声明和定义全部放在类体中，需注意：成员函数如果在类中定义，编译器可能会将其当成内联函数处理。![image-20221003112234023](%E5%9B%BE%E7%89%87/README/image-20221003112234023.png)
> 2. 类声明放在.h文件中，成员函数定义放在.cpp文件中，注意：成员函数名前需要加类名::![image-20221003112255057](%E5%9B%BE%E7%89%87/README/image-20221003112255057.png)
>
> **一般情况下，更期望采用第二种方式。**

------



##### C++中struct和class的区别是什么？

> C++需要兼容C语言，所以C++中struct可以当成结构体去使用。
>
> 另外C++中struct还可以用来定义类。 和class定义类是一样的，区别是**struct的成员默认访问方式是public，class的成员默认访问方式是private。**

------



#####  类的访问限定符及封装

>  C++实现封装的方式：用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限**选择性**的将其接口提供给外部的用户使用。

###### 访问限定符:

> ![image-20221003113327586](%E5%9B%BE%E7%89%87/README/image-20221003113327586.png)
>
> - public修饰的成员在类外可以直接被访问 
> - protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
> - 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止 
> - class的默认访问权限为private，struct为public(因为struct要兼容C)
> - **注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别**
>

###### 封装：

> 将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行 交互。

------



#####  类的作用域

> 类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员，需要使用 :: 作用域解析符 指明成员属于哪个类域
>
> ```c++
> class Person
> {
>     public:
>     void PrintPersonInfo();
>     private:
>     char _name[20];
>     char _gender[3];
>     int _age;
> };
> // 这里需要指定PrintPersonInfo是属于Person这个类域
> void Person::PrintPersonInfo()
> {
>  	cout<<_name<<" "_gender<<" "<<_age<<endl;
> }
> ```
>

------



##### 类的实例化

> 用类类型创建对象的过程，称为类的实例化 
>
> 1. 类只是一个模型一样的东西，限定了类有哪些成员，定义出一个类并没有分配实际的内存空间来存储它 
> 2. 一个类可以实例化出多个对象，实例化出的对象 占用实际的物理空间，存储类成员变量 
> 3. 做个比方。类实例化出对象就像现实中使用建筑设计图建造出房子，类就像是设计图，只设计出需要什 么东西，但是并没有实体的建筑存在，同样类也只是一个设计，实例化出的对象才能实际存储数据，占用物理空间  
>

------



##### 类对象内存大小

> - 类成员函数存放在公共代码区，不与成员变量存在同一区域，不算大小
> - 调用类成员函数代码，会在类作用域找函数，在编译时转换成call
> - 无成员函数的类，内存默认为1(需要分配空间获取地址)
> - 结论：一个类的大小，实际就是该类中”成员变量”之和，当然也要进行内存对齐，注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类。
>

------



##### this指针

> C++编译器给每个“非静态的成员函数“增加了一个隐藏的指针参数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有成员变量的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编译器自动完成。
>

###### this指针的特性

> 1. this指针的**类型**：类类型* const
> 2. 只能在“成员函数”的内部使用
> 3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this形参。所以对象中不存储this指针。
> 4. this指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户传递
> 5. this指针存在函数形参列表里, 可以通过强转变成空指针
>

###### 面试题

> 1. this指针存在哪里？
> 2. this指针可以为空吗？
>
> ```C++
> // 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
> class A
> {
> public:
>     void Print()
>     {
>         cout << "Print()" << endl;//空对象可以访问成员方法
>     }
> private:
>  	int _a;
> };
> int main()
> {
>     A* p = nullptr;
>     p->Print();
>     return 0;
> }
> // 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
> class A
> { 
> public:
>     void PrintA() 
>     {
>         cout<<_a<<endl;//空对象无成员变量
>     }
> private:
>  	int _a;
> };
> int main()
> {
>     A* p = nullptr;
>     p->PrintA();
>     return 0;
> }
> ```
>

------



##### 六大默认成员函数

![image-20221003120500028](%E5%9B%BE%E7%89%87/README/image-20221003120500028.png)

###### 构造函数：

> 构造函数是一个特殊的成员函数，**名字与类名相同**,创建类类型对象时由**编译器自动调用**，保证每个数据成员都有一个合适的初始值，并且在对象的生命周期内**只调用一次**。需要注意的是，构造函数的虽然名称叫构造，但是构造函数的主要任务并不是开空间创建对象，而是**初始化对象**。
>
> **其特征如下：**
>
> 1. 函数名与类名相同。
> 2. 无返回值。
> 3. 对象实例化时编译器自动调用对应的构造函数。
> 4. 构造函数可以重载。
> 5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦用户显式定义编译器将不再生成。
> 6. **无参的构造函数**和**全缺省的构造函数**都称为默认构造函数，并且默认构造函数只能有一个。注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数
>
> **注意：**
>
> C++11 中针对内置类型成员不初始化的缺陷，又打了补丁，即：内置类型成员变量在**类中声明时可以给默认值**。
>
> **编译器默认构造函数：**
>
> - 对内置类型不进行处理。
> - 对自定义类型，调用自定义类型的默认构造参数

###### 析构函数:

> 与构造函数功能相反，析构函数不是完成对象的销毁，局部对象销毁工作是由编译器完成的。而对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。
>
> **其特征如下：**
>
> 1. 析构函数名是在类名前加上字符 ~。
> 2. 无参数无返回值。
> 3. 一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
> 4. 对象生命周期结束时，C++编译系统系统自动调用析构函数。
>
> **编译器自动生成的析构函数:**
>
> - 对内置类型不处理
>
> - 会对自定类型成员调用它的析构函数

###### 拷贝构造函数:

> 只有单个形参，该形参是对**本类类型对象的引用**(一般常用const修饰)，在用已存在的类类型对象**创建新对象时**由编译器自动调用。
>
> **其特征如下：**
>
> 1. 拷贝构造函数是构造函数的一个重载形式。
> 2. 拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用。**//重点**
> 3. 若未显示定义，系统生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝我们叫做浅拷贝，或者值拷贝。//如果申请了堆空间,则对应的指针会指向同一块空间
> 4. 初始化赋值即int a = b; 会调用拷贝构造, 而不是赋值--**编译器优化**



###### 赋值运算符重载:

  **运算符重载 :**

> C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
>
> - 函数名字为：关键字operator后面接需要重载的运算符符号。
> - 函数原型：返回值类型 operator操作符(参数列表)
> - 注意:
>     1. 不能通过连接其他符号来创建新的操作符：比如operator@ 
>     2. 重载操作符必须有一个类类型或者枚举类型的操作数
>     3. 用于内置类型的操作符，其含义不能改变，例如：内置的整型+，不 能改变其含义
>     4. 作为类成员的重载函数时，其形参看起来比操作数数目少1, 因为成员函数的操作符有一个默认的形参this，限定为第一个形参
>     5. .* 、:: 、sizeof 、?: 、. 注意**以上5个运算符不能重载**。这个经常在笔试选择题中出现。
>     6. 赋值运算符在类中不显式实现时，编译器会生成一份默认的，此时用户在类外再将赋值运算符重载为全局的，就和编译器生成的默认赋值运算符冲突了，故赋值运算符只能重载成成员函数

**赋值运算符重载:**

> 1. 赋值运算符重载格式
>
>     - 参数类型: const T&，传递引用可以提高传参效率
>     - 返回值: T&，返回引用可以提高返回的效率，有返回值目的是为了支持连续赋值
>     - 检测是否自己给自己赋值
>     - 返回*this: 要复合连续赋值的含义
>
> 2. 赋值运算符只能重载成类的成员函数不能重载成全局函数
>
>     ```c++
>     class Date
>     {
>     public:
>      Date(int year = 1900, int month = 1, int day = 1)
>      {
>      _year = year;
>      _month = month;
>      _day = day;
>      }
>      int _year;
>      int _month;
>      int _day;
>     };
>     // 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
>     Date& operator=(Date& left, const Date& right)
>     {
>      if (&left != &right)
>      {
>      left._year = right._year;
>      left._month = right._month;
>      left._day = right._day;
>      }
>      return left;
>     }
>     // 编译失败：
>     // error C2801: “operator =”必须是非静态成员
>     ```
>
>     **原因：**赋值运算符如果不显式实现，编译器会生成一个默认的。此时用户再在类外自己实现一个全局的 赋值运算符重载，就和编译器在类中生成的默认赋值运算符重载冲突了，故赋值运算符重载只能是类的 成员函数。
>
> 3. 一个类如果没有显式定义赋值运算符重载，编译器也会生成一个，完成对象**按字节序的值拷贝**

 **前置++和后置++重载:**

> ~~~C++
> class Date
> {
> public:
>     Date(int year = 1900, int month = 1, int day = 1)
>     {
>         _year = year;
>         _month = month;
>         _day = day;
>     }
>  // 前置++：返回+1之后的结果
>  // 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
>     Date& operator++()
>     {
>         _day += 1;
>         return *this;
>     }
>  // 后置++：
>  // 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
>  // C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传
> 递
>  // 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存一份，
> 然后给this+1
>  // 而temp是临时对象，因此只能以值的方式返回，不能返回引用
>     Date operator++(int)
> {
>     Date temp(*this);
>     _day += 1;
>     return temp;
> }
> private:
>     int _year;
>     int _month;
>     int _day;
> };
> int main()
> {
>     Date d;
>     Date d1(2022, 1, 13);
>     d = d1++; // d: 2022,1,13 d1:2022,1,14
>     d = ++d1; // d: 2022,1,15 d1:2022,1,15
>     return 0;
> }
> ~~~

######  取地址及const取地址操作符重载

> 这两个运算符一般不需要重载，使用编译器生成的默认取地址的重载即可，只有特殊情况，才需要重载，比如想让别人获取到指定的内容！

###### const成员

> 将const修饰的类成员函数称之为const成员函数，const修饰类成员函数，实际修饰该成员函数隐含的this 指针，表明在该成员函数中不能对类的任何成员进行修改。
>
> **形式:**
>
> ```
>  typeReturn name(typeElem ) const
> ```

------



##### 详解C++_const



------



##### 匿名对象

匿名对象生命周期只有一行, 若被const引用, 则其声明周期会延长

形式:

```c++
className(2022, 10, 2)//没有对象名,生命周期为一行
```

------



#####   初始化列表

###### 构造函数体赋值

> 在创建对象时，编译器通过调用构造函数，给对象中各个成员变量一个合适的初始值。
>
> ~~~c++
> class Date
> {
> public:
>     Date(int year, int month, int day)
>     {
>         _year = year;
>         _month = month;
>         _day = day;
>     }
> private:
>     int _year;
>     int _month;
>     int _day;
> };
> 
> ~~~
>
> 虽然上述构造函数调用之后，对象中已经有了一个初始值，但是不能将其称为对对象中成员变量的初始化， **构造函数体中的语句只能将其称为赋初值，而不能称作初始化**。因为初始化只能初始化一次，而构造函数体 内可以多次赋值。

######  初始化列表

> 初始化列表：以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括 号中的初始值或表达式。
>
> ~~~C++
> ClassName (int a, int b, int c, ClassName1 cn1)
> 	: _a(a)
> 	, _b(b)
> 	, _c(c)
> 	, _cn1(cn1)
> 	{
> 		///	
> 	}
> ~~~
>
> **注意:**
>
> 1. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次) 
> 2.  类中包含以下成员，必须放在初始化列表位置进行初始化：
>     - 引用成员变量
>     - const成员变量
>     - 自定义类型成员(且该类没有默认构造函数时)
> 3. 尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，一定会先使 用初始化列表初始化
> 4. 成员变量在类中**声明次序就是其在初始化列表中的初始化顺序**，与其在初始化列表中的先后次序无关

#####  explicit关键字:

> 构造函数不仅可以构造与初始化对象，对于单个参数或者除第一个参数无默认值其余均有默认值的构造函 数，还具有类型转换的作用。
>
> ~~~C++
> class Date
> {
>   public:
>     // 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
>     // explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
>     explicit Date(int year)
>         :_year(year)
>         {}
>     /*
>  // 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
>  // explicit修饰构造函数，禁止类型转换
>  explicit Date(int year, int month = 1, int day = 1)
>  : _year(year)
>  , _month(month)
>  , _day(day)
>  {}
>  */
>     Date& operator=(const Date& d)
>     {
>         if (this != &d)
>         {
>             _year = d._year;
>             _month = d._month;
>             _day = d._day;
>         }
>         return *this;
>     }
>   private:
>     int _year;
>     int _month;
>     int _day;
> };
> void Test()
> {
>     Date d1(2022);
>     // 用一个整形变量给日期类型对象赋值
>     // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
>     d1 = 2023;
>     // 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
> }
> ~~~
>
> 用explicit修饰构造函数，将会禁止构造函数的隐式转换。 

------



##### 静态类成员:

> 声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用static修饰的 成员函数，称之为静态成员函数。静态成员变量一定要在类外进行初始化
>
> **特性:**
>
> - 静态成员为所有类对象所共享，不属于某个具体的对象，存放在静态区
> - 静态成员变量必须在类外定义，定义时不添加static关键字，类中只是声明
> - 类静态成员可用 类名::静态成员 或者 对象.静态成员 来访问
> - 静态成员函数没有隐藏的this指针，不能访问任何非静态成员, 只能访问静态成员变量
> - 静态成员也是类的成员，受public、protected、private 访问限定符的限制
>
> **面试题:**
>
> 1. 实现一个类，计算程序中创建出了多少个类对象。
>
> ~~~C++
> class A
> {
>     public:
>     A() { ++_scount; }
>     A(const A& t) { ++_scount; }
>     ~A() { --_scount; }
>     static int GetACount() { return _scount; }
>     private:
>     static int _scount;
> };
> int A::_scount = 0;
> void TestA()
> {
>     cout << A::GetACount() << endl;
>     A a1, a2;
>     A a3(a1);
>     cout << A::GetACount() << endl;
> }
> ~~~
>
> 2. 静态成员函数可以调用非静态成员函数吗？
> 3. 非静态成员函数可以调用类的静态成员函数吗？

------



##### 友元:

>  友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多 用。 
>
> 友元分为：友元函数和友元类 

###### 友元函数:

> **问题：**现在尝试去重载operator<<，然后发现没办法将operator<<重载成成员函数。因为cout的输出流对 象和隐含的this指针在抢占第一个参数的位置。this指针默认是第一个参数也就是左操作数了。但是实际使用 中cout需要是第一个形参对象，才能正常使用。所以要将operator<<重载成全局函数。但又会导致类外没办 法访问成员，此时就需要友元来解决。operator>>同理。
>
> ~~~C++
> class Date
> {
>     public:
>     Date(int year, int month, int day)
>         : _year(year)
>             , _month(month)
>             , _day(day)
>         {}
>     // d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
>     // 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
>     ostream& operator<<(ostream& _cout)
>     {
>         _cout << _year << "-" << _month << "-" << _day << endl;
>         return _cout;
>     }
>     private:
>     int _year;
>     int _month;
>     int _day;
> };
> ~~~
>
> 友元函数可以**直接访问类的私有成员**，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声 明，声明时需要加friend关键字。
>
> ~~~C++
> class Date
> {
>     friend ostream& operator<<(ostream& _cout, const Date& d);
>     friend istream& operator>>(istream& _cin, Date& d);
>     public:
>     Date(int year = 1900, int month = 1, int day = 1)
>         : _year(year)
>             , _month(month)
>             , _day(day)
>         {}
>     private:
>     int _year;
>     int _month;
>     int _day;
> };
> ostream& operator<<(ostream& _cout, const Date& d)
> {
>     _cout << d._year << "-" << d._month << "-" << d._day;
>     return _cout;
> }
> istream& operator>>(istream& _cin, Date& d)
> {
>     _cin >> d._year;
>     _cin >> d._month;
>     _cin >> d._day;
>     return _cin;
> }
> int main()
> {
>     Date d;
>     cin >> d;
>     cout << d << endl;
>     return 0;
> }
> ~~~
>
> **特性:**
>
> - 友元函数可访问类的私有和保护成员，但不是类的成员函数 
> - 友元函数不能用const修饰 
> - 友元函数可以在类定义的任何地方声明，不受类访问限定符限制 
> - 一个函数可以是多个类的友元函数 
> - 友元函数的调用与普通函数的调用原理相同
>
> 

###### 友元类

> **特性:**
>
> - 友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。 
>
> - 友元关系是单向的，不具有交换性。 
>
>     比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time 类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。 
>
> - 友元关系不能传递 如果B是A的友元，C是B的友元，则不能说明C时A的友元。 
>
> - 友元关系不能继承。
>
> ```c++
> class Time
> {
>     friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成
>     员变量
>         public:
>     Time(int hour = 0, int minute = 0, int second = 0)
>         : _hour(hour)
>             , _minute(minute)
>             , _second(second)
>         {}
> 
>     private:
>     int _hour;
>     int _minute;
>     int _second;
> };
> class Date
> {
>     public:
>     Date(int year = 1900, int month = 1, int day = 1)
>         : _year(year)
>             , _month(month)
>             , _day(day)
>         {}
> 
>     void SetTimeOfDate(int hour, int minute, int second)
>     {
>         // 直接访问时间类私有的成员变量
>         _t._hour = hour;
>         _t._minute = minute;
>         _t._second = second;
>     }
> 
>     private:
>     int _year;
>     int _month;
>     int _day;
>     Time _t;
> };
> ```
>

------



##### 内部类:

>  **概念：**
>
> 如果一个类定义在另一个类的内部，这个内部类就叫做内部类。内部类是一个独立的类，它不属于外部类，更不能通过外部类的对象去访问内部类的成员。外部类对内部类没有任何优越的访问权限。
>
>  **注意：**
>
> **内部类就是外部类的友元类**，参见友元类的定义，内部类可以通过外部类的对象参数来访问外部类中 的所有成员。但是外部类不是内部类的友元。  
>
>  **特性：** 
>   1. 内部类可以定义在外部类的public、protected、private都是可以的, 受访问限制符和外部类类域。 
>   2. 注意内部类可以直接访问外部类中的static成员，不需要外部类的对象/类名。 
>   3. sizeof(外部类)=外部类，和内部类没有任何关系。 
>
> ~~~c++
> class A
> {
>     private:
>     static int k;
>     int h;
>     public:
>     class B // B天生就是A的友元
>     {
>         public:
>         void foo(const A& a)
>         {
>             cout << k << endl;//OK
>             cout << a.h << endl;//OK
>         }
>     };
> };
> int A::k = 1;
> int main()
> {
>     A::B b;
>     b.foo(A());
> 
>     return 0;
> }
> ~~~

------

##### 小知识

> ```
> Class w{...};
> 匿名类:
> w(val); //生命周期为一行
> 编译器优化:
> 构造 + 拷贝构造 ----> 编译器优化 ----> 合二为一
> eg: w w2(w()); //直接构造w2
> 结论: 
> 一连串语句, 可能会发生编译器优化.
> ```
>

------



### C/C++内存管理:

##### C/C++内存分配

> ~~~C++
> int globalVar = 1;
> static int staticGlobalVar = 1;
> void Test()
> {
>     static int staticVar = 1;
>     int localVar = 1;
>     int num1[10] = { 1, 2, 3, 4 };
>     char char2[] = "abcd";
>     const char* pChar3 = "abcd";
>     int* ptr1 = (int*)malloc(sizeof(int) * 4);
>     int* ptr2 = (int*)calloc(4, sizeof(int));
>     int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
>     free(ptr1);
>     free(ptr3);
> }
> 1. 选择题：
>     选项: A.栈  B.堆  C.数据段(静态区)  D.代码段(常量区)
>         globalVar在哪里？____   staticGlobalVar在哪里？____
>         staticVar在哪里？____   localVar在哪里？____
>         num1 在哪里？____
> 
>         char2在哪里？____   *char2在哪里？___
>         pChar3在哪里？____      *pChar3在哪里？____
>         ptr1在哪里？____        *ptr1在哪里？____
> 2. 填空题：
>         sizeof(num1) = ____; sizeof(char2) = ____;            	   strlen(char2) = ____;sizeof(pChar3) = ____;     			strlen(pChar3) = ____;sizeof(ptr1) = ____;
> 3. sizeof 和 strlen 区别？
> ~~~
>
> ![image-20221003144506575](%E5%9B%BE%E7%89%87/README/image-20221003144506575.png)
>
> **说明:**
>
> 1. **栈又叫堆栈**--非静态局部变量/函数参数/返回值等等，栈是向下增长的。 
> 2. **内存映射段**是高效的I/O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口 创建共享共享内存，做进程间通信。（Linux课程如果没学到这块，现在只需要了解一下） 
> 3. **堆**用于程序运行时动态内存分配，堆是可以上增长的。 
> 4. **数据段**--存储全局数据和静态数据。 
> 5. **代码段**--可执行的代码/只读常量。

------

##### C语言中动态内存管理方式：malloc/calloc/realloc/free

> ~~~C++
> void Test ()
> {
>  int* p1 = (int*) malloc(sizeof(int));
>  free(p1);
>  // 1.malloc/calloc/realloc的区别是什么？
>  int* p2 = (int*)calloc(4, sizeof (int));
>  int* p3 = (int*)realloc(p2, sizeof(int)*10);
>  // 这里需要free(p2)吗？
>  free(p3 );
> }
> ~~~
>
> **面试题:**
>
> 1. malloc/calloc/realloc的区别？
>
>     ~~~
>     relloc第一个参数为空指针时, 相当于malloc, 需要包含stdlib.h头文件
>     ~~~
>
> 2. malloc的实现原理？ [glibc中malloc实现原理](https://www.bilibili.com/video/BV117411w7o2/?spm_id_from=333.788.videocard.0)
>
> 3. ![image-20221031133601791](%E5%9B%BE%E7%89%87/README/image-20221031133601791.png)

##### C++动态内存管理方式: new/delete

> C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力，而且使用起来比较麻烦，因 此C++又提出了自己的内存管理方式：通过**new和delete**操作符进行动态内存管理。
>
> 1. 内置类型
>
>     ~~~C++
>     和C语言没本质区别, 只是简化了语句
>     ---------申请new:
>     int *p1 = new int;//申请大小为int的空间
>     int *p2 = new int[5];//申请大小为 int * 5 的空间
>     int *p3 = new int(5);//初始化
>     int *p4 = new int[5]{1, 2, 3};//c++11支持, 98不支持
>     -----------释放delete:
>     delete p1;//
>     delete[] p2;//释放连续空间, 需要对应
>     delete p3;
>     delete[] p4;
>     ----------------
>     如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是： new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申请空间失败时会抛异常，malloc会返回NULL。
>     ~~~
>
> 2. 自定义类型
>
>     ~~~C++
>     申请new:
>     new不仅会申请堆空间, 还会进行初始化(调用构造函数)
>     释放delete:
>     delete释放空间, 并且会调用析构函数
>     ~~~
>
> 3. 失败处理
>
>     ~~~C++
>     malloc失败会返回(int)0
>     new失败会抛出异常错误
>     ~~~
>
> 4. 原理
>
>     ~~~C++
>     ---new的原理
>     1. 调用operator new函数申请空间
>     2. 在申请的空间上执行构造函数，完成对象的构造
>     ---delete的原理
>     1. 在空间上执行析构函数，完成对象中资源的清理工作
>     2. 调用operator delete函数释放对象的空间
>     ---new T[N]的原理//////注意
>     1. 调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
>     2. 在申请的空间上执行N次构造函数
>     ---delete[]的原理
>     1. 在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理
>     2. 调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间
>     ~~~
>
>     - 对于内置类型, new[]申请的空间, 可以用delete释放, 不会报错, 但不建议这样做
>     - 对于自置类型, new[]申请的空间, 必须用delete[]释放, 否则会运行失败

#####  operator new与operator delete函数:

> new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是系统提供的全局函数，**new在底层调用operator new全局函数来申请空间，delete在底层通过operator delete全局函数来释放空间。**
>
> ~~~C++
> /*
> operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
> 失败，尝试执行空               间不足应对措施，如果改应对措施用户设置了，则继续申请，否
> 则抛异常。
> */
> void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
> {
>     // try to allocate size bytes
>     void *p;
>     while ((p = malloc(size)) == 0)
>         if (_callnewh(size) == 0)
>         {
>             // report no memory
>             // 如果申请内存失败了，这里会抛出bad_alloc 类型异常
>             static const std::bad_alloc nomem;
>             _RAISE(nomem);
>         }
>     return (p);
> }
> /*
> operator delete: 该函数最终是通过free来释放空间的
> */
> void operator delete(void *pUserData)
> {
>     _CrtMemBlockHeader * pHead;
>     RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
>     if (pUserData == NULL)
>         return;
>     _mlock(_HEAP_LOCK);  /* block other threads */
>     __TRY
>         /* get a pointer to memory block header */
>         pHead = pHdr(pUserData);
>     /* verify block type */
>     _ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
>     _free_dbg( pUserData, pHead->nBlockUse );
>     __FINALLY
>         _munlock(_HEAP_LOCK);  /* release other threads */
>     __END_TRY_FINALLY
>         return;
> }
> /*
> free的实现
> */
> #define   free(p)               _free_dbg(p, _NORMAL_BLOCK)
> ~~~
>
> 通过上述两个全局函数的实现知道，operator new 实际也是通过malloc来申请空间，如果 malloc申请空间成功就直接返回，否则执行用户提供的空间不足应对措施，如果用户提供该措施 就继续申请，否则就抛异常。operator delete 最终是通过free来释放空间的。
>
>  **重载operator new与operator delete:**
>
> ```
>  一般情况下不需要对 operator new 和 operator delete进行重载，除非在申请和释放空间 时候有某些特殊的需求。比如：在使用new和delete申请和释放空间时，打印一些日志信息，可 以简单帮助用户来检测是否存在内存泄漏。 
> ```
>

##### 只允许在堆或栈上创建对象

> [(12条消息) C++ 如何让类对象只在堆或栈上创建_stashblog的博客-CSDN博客_c++创建堆对象](https://blog.csdn.net/qq_30835655/article/details/68938861)
>
> [(12条消息) C++如何限制只能在堆或栈上创建对象？_sstinky的博客-CSDN博客](https://blog.csdn.net/sstinky/article/details/103718720)

##### 常见内存管理面试题:

> 1. malloc/free和new/delete的区别
>
>   - malloc/free和new/delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。不同的地方是：
>   - malloc和free是函数，new和delete是操作符
>   - malloc申请的空间不会初始化，new可以初始化
>   - malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可，如果是多个对象，[]中指定对象个数即可
>   - malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
>   - malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常
>   - 申请自定义类型对象时，malloc/free只会开辟空间，不会调用构造函数与析构函数，而new在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成空间中资源的清理
>
> 2. 内存泄漏
>
>   - 什么是内存泄漏，内存泄漏的危害
>
>       ```
>       什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况，野指针问题也属于内存泄漏。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。
>       内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死。
>       ```
>
>   - 内存泄漏分类（了解）
>
>       ```
>       C/C++程序中一般我们关心两种方面的内存泄漏：
>       堆内存泄漏(Heap leak):
>       堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak。
>       系统资源泄漏:
>       指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定
>       ```
>
>   - 如何检测内存泄漏（了解）
>
>       ```
>       在vs下，可以使用windows操作系统提供的_CrtDumpMemoryLeaks() 函数进行简单检测，该函数只报出了大概泄漏了多少个字节，没有其他更准确的位置信息。
>       因此写代码时一定要小心，尤其是动态内存操作时，一定要记着释放。但有些情况下总是防不胜防，简单的可以采用上述方式快速定位下。如果工程比较大，内存泄漏位置比较多，不太好查时一般都是借助第三方内存泄漏检测工具处理的。
>       在linux下内存泄漏检测：linux下几款内存泄漏检测工具
>       在windows下使用第三方工具：VLD工具说明
>       其他工具：内存泄漏工具比较
>       ```
>
>   - 如何避免内存泄漏
>
>       - 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps：
>           这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题。需要下一条智能指针来管理才有保证。
>       - 采用RAII思想或者智能指针来管理资源。
>       - 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项。
>       - 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵。
>
>       
>
> 3. 总结一下:
>
>   内存泄漏非常常见，解决方案分为两种：
>
>   ```
>   1、事前预防型。如智能指针等。
>   2、事后查错型。如泄漏检测工具
>   ```
>
>   

------



### Date类

运用学过的知识, 实现一个日期类









------



### STL

**书籍推荐: <<STL源码剖析>> 侯捷**

#### 泛型编程:

##### 初识泛型思想

> 如何实现一个通用的交换函数呢？
>
> ~~~C++
> void Swap(int& left, int& right)
> {
>     int temp = left;
>     left = right;
>     right = temp;
> }
> void Swap(double& left, double& right)
> {
>     double temp = left;
>     left = right;
>     right = temp;
> }
> void Swap(char& left, char& right)
> {
>     char temp = left;
>     left = right;
>     right = temp;
> }
> ......
> 
> ~~~
>
> 使用函数重载虽然可以实现，但是有一下几个不好的地方： 
>
> 1. 重载的函数仅仅是类型不同，代码复用率比较低，只要有新类型出现时，就需要用户自己增加对应的函数 
> 2. 代码的可维护性比较低，一个出错可能所有的重载均出错 
>
> **那能否告诉编译器一个模子，让编译器根据不同的类型利用该模子来生成代码呢？**
>
> 在C++中，存在这样一个模具，通过给这个模具中填充类型，生成具体类型的代码，那将会节省许多头发。这就是泛型编程。
>
> **泛型编程：**编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础。
>
> ![image-20221003163649554](%E5%9B%BE%E7%89%87/README/image-20221003163649554.png)

------



##### 函数模板:

###### 概念

> 函数模板代表了一个函数家族，该函数模板与类型无关，在**使用时被参数化**，根据实参类型产生函数的特定 类型版本。

###### 格式

> ```c++
> 关键字: template, typename
> 格式: template<typename 模板类型名字>
> eg: 
> 	template<typename T>
> 	void Swap(T& left, T& rig)
> 	{
> 		T temp = left;
> 		left = rig;
> 		rig = tmep;
> 	}
> //一个模板类型列表和一个函数模板严格地一一对应
> ```
>

###### 原理

> 函数模板是一个蓝图，它本身并不是函数，是编译器用使用方式产生特定具体类型函数的模具。所以其实模板就是将本来应该我们做的重复的事情交给了编译器
>
> 在**编译器编译阶段**，对于模板函数的使用，编译器需要根据传入的实参类型来推演生成对应类型的函数以供调用。
>
> 比如：当用double类型使用函数模板时，编译器通过对实参类型的推演，将T确定为double类型，然后产生一份专门处理double类型的代码，对于字符类型也是如此--**推断在传参前。**

------

###### 函数模板的实例化

> 用不同类型的参数使用函数模板时，称为函数模板的实例化。模板参数实例化分为：隐式实例化和显式实例化。
>
> 1. 隐式实例化：让编译器根据实参推演模板参数的实际类型
>
>     ~~~C++
>     template<class T>
>     T Add(const T& left, const T& right)
>     {
>         return left + right;
>     }
>     int main()
>     {
>         int a1 = 10, a2 = 20;
>         double d1 = 10.0, d2 = 20.0;
>         Add(a1, a2);
>         Add(d1, d2);
>     
>         /*
>      该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
>      通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
>      编译器无法确定此处到底该将T确定为int 或者 double类型而报错
>      注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
>      Add(a1, d1);
>      */
>     
>         // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
>         Add(a, (int)d);
>     	return 0;
>     }
>     ~~~
>
> 2. 显式实例化：在函数名后的<>中指定模板参数的实际类型
>
>     ~~~C++
>     int main(void)
>     {
>         int a = 10;
>         double b = 20.0;
>                                                                                                     
>         // 显式实例化
>         Add<int>(a, b);
>         return 0;
>     }
>     ~~~
>
>     **如果类型不匹配，编译器会尝试进行隐式类型转换，如果无法转换成功编译器将会报错。**

##### 模板参数的匹配原则

> 1. 一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函 数
>
>     ~~~c++
>     // 专门处理int的加法函数
>     int Add(int left, int right)
>     {
>         return left + right;
>     }
>     // 通用加法函数
>     template<class T>
>         T Add(T left, T right)
>     {
>         return left + right;
>     }
>     void Test()
>     {
>         Add(1, 2); // 与非模板函数匹配，编译器不需要特化
>         Add<int>(1, 2); // 调用编译器特化的Add版本
>     }
>
> 2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模 板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
>
>     ~~~C++
>     // 专门处理int的加法函数
>     int Add(int left, int right)
>     {
>         return left + right;
>     }
>     // 通用加法函数
>     template<class T1, class T2>
>     T1 Add(T1 left, T2 right)
>     {
>         return left + right;
>     }
>     void Test()
>     {
>         Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
>         Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
>     }
>     ~~~
>
> 3. 模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
>
>     ```
>     模板中不允许使用auto
>     typedef与模板，取决于编译顺序
>     ```
> 
>

##### 类模板:

###### 格式

> ```c++
> template<class T1, class T2, ..., class Tn>
> class 类模板名
> {
>  // 类内成员定义--存在模板类型成员
> }; 
> 1. 在类中使用模板类型, 就是类模板
> 2. 类模板都是显示实例化
> 3. 模板类不支持分离编译, 即声明和定义必须在同一个文件
> ```
>

###### 实例化

> 类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后**强制跟<>**，然后将实例化的类型放在<>中
>
> ~~~c++
> // Vector类模板的名字，Vector<int>才是类
> Vector<int> s1;
> Vector<double> s2;

###### 注意注意注意注意注意注意注意注意注

> 1. 模板参数列表, 和其函数模板, 类模板是一一对应的
>
> 2. 类模板/函数模板 只是一种声明, 并不是定义, 由编译器在编译阶段推导出来的模板函数/模板类才是定义
>
> 3. **类模板实例化只会实例化需要的部分**，若存在未用到函数，则不会实例化改函数

------

##### 模板的特化

------

#### STL容器

##### string类:

> **新思想**
> ```
> 深拷贝原理
> 深现代写法原理
> 复用思想
> 初识原生迭代器
> ```
>
> ###### vs和g++下string结构的说明
> ```
> 注意：下述结构是在32位平台下进行验证，32位平台下指针占4个字节。
> --vs下string的结构:
> string总共占28个字节，内部结构稍微复杂一点，先是有一个联合体，联合体用来定义string中字符串的存储空间：当字符串长度小于16时，使用内部固定的字符数组来存放;当字符串长度大于等于16时，从堆上开辟空间.
> 这种设计也是有一定道理的，大多数情况下字符串的长度都小于16，那string对象创建好之后，内部已经有了16个字符数组的固定空间，不需要通过堆创建，效率高。 其次：还有一个size_t字段保存字符串长度，一个size_t字段保存从堆上开辟空间总的容量 最后：还有一个指针做一些其他事情。 故总共占16+4+4+4=28个字节。
> --g++下string的结构 
> G++下，string是通过写时拷贝实现的，string对象总共占4个字节，内部只包含了一个指针，该指 针将来指向一块堆空间，内部包含了如下字段： 
> 1. 空间总大小 
> 2. 字符串有效长度 
> 3. 引用计数
> 4. 指向堆空间的指针，用来存储字符串。
> struct _Rep_base
> {
> 	size_type _M_length; 
> 	size_type _M_capacity; 
> 	_Atomic_word _M_refcount; 
> };
> ```
>
> ###### 浅拷贝/深拷贝/写时拷贝
>
> ```
> --浅拷贝:
> 值拷贝, 仅仅按字节拷贝内容, 而不考虑实际[也称位拷贝，编译器只是将对象中的值拷贝过来。如果对象中管理资源，最后就会导致多个对象共 享同一份资源，当一个对象销毁时就会将该资源释放掉，而此时另一些对象不知道该资源已经被释放，以为 还有效，所以当继续对资源进项操作时，就会发生发生了访问违规。]
> --深拷贝:
> 自写拷贝, 按真实逻辑拷贝内容, 比如申请到堆上的空间[如果一个类中涉及到资源的管理，其拷贝构造函数、赋值运算符重载以及析构函数必须要显式给出。一般情 况都是按照深拷贝方式提供。]
> --写时拷贝:
> 延迟拷贝奇数, 当构造对象只进行读操作时, 和被拷贝对象共享空间, 当需要进行写操作时, 才进行拷贝[写时拷贝就是一种拖延症，是在浅拷贝的基础之上增加了引用计数的方式来实现的。 引用计数：用来记录资源使用者的个数。在构造时，将资源的计数给成1，每增加一个对象使用该资源，就给 计数增加1，当某个对象被销毁时，先给该计数减1，然后再检查是否需要释放资源，如果计数为1，说明该 对象时资源的最后一个使用者，将该资源释放；否则就不能释放，因为还有其他对象在使用该资源。]
> ```
>
> ###### 全代码
>
> [String模拟实现参考](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/string%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/String.h)
>
> ```c++
> #pragma once
> 
> #include<iostream>
> #include<assert.h>
> #include<string>
> #include<algorithm>
> using namespace std;
> 
> namespace Bit
> {
> 
> 	/*using std::cout;
> 	using std::cin;
> 	using std::endl;*/
> 
> 	class string
> 	{
> 
> 		typedef char* iterator;
> 		typedef const char* const_iterator;
> 	public:
> 
> #pragma region 其他
> 		//swap
> 		void swap(string& str)
> 		{
> 			std::swap(_str, str._str);
> 			std::swap(_size, str._size);
> 			std::swap(_capacity, str._capacity);
> 		}
> 
> 		//c指针
> 		const char* c_str() const
> 		{
> 			return _str;
> 		}	 
> #pragma endregion
> 
> #pragma region 构造函数
> 		//无参
> 		// _str(nullptr) 错误: 转换成c指针 用cout输出的结束条件为 *p = '\0', 解引用了空指针
> 		// _str("\0") 错误: 常量字符串默认存在'\0'
> 		string()
> 			: _str(new char[1])
> 			, _size(0)
> 			, _capacity(0)
> 		{
> 			_str[0] = '\0';
> 		}
> 
> 		//常量字符串
> 		string(const char* str)
> 		{
> 			size_t len = strlen(str);
> 			_size = len;
> 			_capacity = len;
> 			_str = new char[len + 1];
> 
> 			strcpy(_str, str);
> 		}
> 		////常量字符串全缺省默认构造
> 		//string(const char* str = "")
> 		//{
> 		//	size_t len = strlen(str);
> 		//	_size = len;
> 		//	_capacity = len;
> 		//	_str = new char[len + 1];
> 		//	
> 		//	strcpy(_str, str);
> 		//}
> 
> 		//常量字符串前n个字符
> 		string(const char* str, size_t n)
> 		{
> 			size_t len = strlen(str);
> 			len = len > n ? n : len;
> 
> 			_size = _capacity = len;
> 			_str = new char[_capacity + 1];
> 
> 			//strcpy 遇到\0结束, 不支持此前结束
> 			for (size_t i = 0; i < _size; i++)
> 			{
> 				_str[i] = str[i];
> 			}
> 			_str[_size] = '\0';
> 
> 		}
> 
> 		//n个字符 ch
> 		string(size_t n, char ch)
> 			:_str(new char[n + 1])
> 			, _size(n)
> 			, _capacity(n)
> 		{
> 			for (size_t i = 0; i < _size; i++)
> 			{
> 				_str[i] = ch;
> 			}
> 			_str[_size] = '\0';
> 		}
> 
> 		/*拷贝构造*/
> 		////传统写法
> 		//string(const string& str)
> 		//	:_str(new char[str._capacity + 1])
> 		//	, _size(str._size)
> 		//	, _capacity(str._capacity)
> 		//{
> 		//	//string对象可包含'\0', 而strcpy无法copy'\0'
> 		//	memcpy(_str, str._str, _capacity + 1);
> 		//}
> 		//
> 		//现代写法
> 		string(const string& str)
> 			: _str(nullptr)
> 			, _size(0)
> 			, _capacity(0)
> 		{
> 			string tmp(str._str);
> 			swap(tmp);
> 		}
> 
> 		//sting对象 第 pos位置的 后n个字符
> 		string(const string& str, size_t pos, size_t n = npos)
> 
> 		{
> 			assert(pos < str._size);//合法下标
> 			*this = str.substr(pos, n);
> 
> 			//*this += str.substr(pos, n);
> 
> 			//错误语句
> 			// substr的返回值具有const属性, 无法修改, 不能作为swap的实参传递
> 			//swap(str.substr(pos, n));
> 		}  
> 
> 		//析构函数
> 		~string()
> 		{
> 			delete[] _str;
> 			_str = nullptr;
> 			_size = _capacity = 0;
> 		}
> #pragma endregion
> 
> #pragma region 空间操作
> 		//reserve
> 		void reserve(size_t n)
> 		{
> 			if (n <= _size) return;
> 
> 			char* tmp = new char[n + 1];
> 
> 			memcpy(tmp, _str, _capacity + 1);
> 
> 			delete[] _str;
> 			_str = tmp;
> 			tmp = nullptr;
> 			_capacity = n;
> 		}
> 		//resize
> 		void resize(size_t n, char ch = '\0')
> 		{
> 			if (n > _size)
> 			{
> 				reserve(n);
> 				for (_size; _size < n; _size++)
> 				{
> 					_str[_size] = ch;
> 				}
> 				_str[_size] = '\0';
> 			}
> 			else
> 			{
> 				_str[n] = '\0';
> 				_size = n;
> 			}
> 		}
> 
> 		//size
> 		size_t size() const
> 		{
> 			return _size;
> 		}
> 		//capacity
> 		size_t capacity() const
> 		{
> 			return _capacity;
> 		}
> 
> 		//clear()
> 		void clear()
> 		{
> 			_str[0] = '\0';
> 			_size = 0;
> 		}
> #pragma endregion
> 
> #pragma region 增删改查
> 
> 		//push_back
> 		void push_back(char ch)
> 		{
> 			//是否扩容
> 			if (_size == _capacity)
> 			{
> 				reserve(_capacity == 0 ? 4 : _capacity * 2);
> 			}
> 
> 			_str[_size] = ch;
> 			_size++;
> 			_str[_size] = '\0';
> 		}
> 		//append
> 		void append(const char* str)
> 		{
> 			size_t len = strlen(str);
> 
> 			if (len + _size > _capacity)
> 			{
> 				reserve(len + _size);
> 			}
> 
> 			strcpy(_str + _size, str);
> 			//strcat(_str + _size, str);
> 
> 			_size += len;
> 		}
> 		void append(const string& str)
> 		{
> 			size_t len = str._size;
> 
> 			if (len + _size > _capacity)
> 			{
> 				reserve(len + _size);
> 			}
> 
> 			memcpy(_str + _size, str._str, str._size + 1);
> 
> 			_size += len;
> 		}
> 
> 		//substr
> 		string substr(size_t pos, size_t len = npos) const
> 		{
> 			assert(pos < _size);//合法下标
> 			size_t realLen = len;
> 			//len = 1, 对应的是 提取pos位置的元素
> 			if (len == npos || pos + len > _size)
> 			{
> 				realLen = _size - pos;
> 			}
> 
> 			string tmp;
> 			for (size_t i = 0; i < realLen; i++)
> 			{
> 				tmp += _str[pos + i];
> 			}
> 
> 			return tmp;
> 		}
> 
> 		//instert -- 引用返回值 可作为 右值或参数
> 		string& insert(size_t pos, char ch)
> 		{
> 			assert(pos < _size);
> 
> 			if (_size == _capacity)
> 			{
> 				reserve(_capacity == 0 ? 4 : _capacity * 2);
> 			}
> 
> 			size_t end = ++_size;
> 
> 			while (end > pos)
> 			{
> 				_str[end] = _str[end - 1];
> 				end--;
> 			}
> 
> 			_str[pos] = ch;
> 
> 			return *this;
> 		}
> 		string& insert(size_t pos, const char* str)
> 		{
> 			assert(pos < _size);
> 
> 			size_t len = strlen(str);
> 
> 			if (_size + len > _capacity)
> 			{
> 				reserve(_size + len);
> 			}
> 
> 			size_t end = _size + len;
> 
> 			while (end >= pos + len)
> 			{
> 				_str[end] = _str[end - len];
> 				end--;
> 			}
> 
> 			strncpy(_str + pos, str, len);//不拷贝'\0', 只拷贝有效字符
> 			//memcpy(_str + pos, str, len);
> 			_size += len;
> 
> 			return *this;
> 		}
> 		string& insert(size_t pos, const string& str)
> 		{
> 			assert(pos < _size);
> 
> 			size_t len = str._size;
> 
> 			if (_size + len > _capacity)
> 			{
> 				reserve(_size + len);
> 			}
> 
> 			size_t end = _size + len;
> 
> 			while (end >= pos + len)
> 			{
> 				_str[end] = _str[end - len];
> 				end--;
> 			}
> 
> 			//strncpy(_str + pos, str._str, len);//不拷贝'\0', 只拷贝有效字符
> 			memcpy(_str + pos, str._str, len);
> 			_size += len;
> 
> 			return *this;
> 		}
> 		/*
> 		* 复用
> 		* 对于substring 和 buffer 可以通过 (转换成string)截断 + substr 实现
> 		*/
> 
> 		//find
> 		size_t find(char ch, size_t pos = 0) const
> 		{
> 			assert(pos < _size);
> 
> 			for (size_t i = pos; i < _size; ++i)
> 			{
> 				if (ch == _str[i])
> 				{
> 					return i;
> 				}
> 			}
> 
> 			return npos;
> 		}
> 		size_t find(const char* sub, size_t pos = 0) const
> 		{
> 			assert(sub);
> 			assert(pos < _size);
> 
> 			const char* ptr = strstr(_str + pos, sub);//cstrig库函数, 返回匹配的第一个字符的地址
> 			if (ptr == nullptr)
> 			{
> 				return npos;
> 			}
> 			else
> 			{
> 				return ptr - _str;
> 			}
> 		}
> 
> 		//erase
> 		string& erase(size_t pos = 0, size_t len = npos)
> 		{
> 			assert(pos < _size);
> 
> 			if (len == npos || pos + len >= _size)
> 			{
> 				_str[pos] = '\0';
> 				_size = pos;
> 			}
> 			else
> 			{
> 				memcpy(_str + pos, _str + pos + len, _size - pos - len + 1);
> 				_size -= len;
> 			}
> 
> 			return *this;
> 		}
> #pragma endregion
> 
> #pragma region 操作符重载
> 
> 		//逻辑操作符
> 		bool operator>(const string& str) const
> 		{
> 			return strcmp(_str, str._str) > 0;
> 		}
> 		bool operator==(const string& str) const
> 		{
> 			return strcmp(_str, str._str) == 0;
> 		}
> 		bool operator>=(const string& str) const
> 		{
> 			return *this > str || *this == str;
> 		}
> 		bool operator<=(const string& str) const
> 		{
> 			return !(*this > str);
> 		}
> 		bool operator<(const string& str) const
> 		{
> 			return !(*this >= str);
> 		}
> 		bool operator!=(const string& str) const
> 		{
> 			return !(*this == str);
> 		}
> 
> 		//运算操作符
> 		string& operator=(string str)
> 		{
> 			swap(str);
> 			return *this;
> 		}
> 
> 		string& operator+=(const char ch)
> 		{
> 			push_back(ch);
> 			return *this;
> 		}
> 		string operator+(const char ch)
> 		{
> 			string tmp(*this);
> 			tmp += ch;
> 			return tmp;
> 		}
> 		string& operator+=(const string& str)
> 		{
> 			append(str);
> 			return *this;
> 		}
> 		string operator+(const string& str)
> 		{
> 			string tmp(*this);
> 			tmp.append(str);
> 			return tmp;
> 		}
> 		string& operator+=(const char* str)
> 		{
> 			append(str);
> 			return *this;
> 		}
> 		string operator+(const char* str)
> 		{
> 			string tmp(*this);
> 			tmp.append(str);
> 			return tmp;
> 		}
> 
> 		//[]
> 		char& operator[](size_t pos)
> 		{
> 			assert(pos < _size);
> 			return _str[pos];
> 		}
> 		const char& operator[](size_t pos) const
> 		{
> 			assert(pos < _size);
> 			return _str[pos];
> 		}		
> #pragma endregion
> 
> #pragma region 迭代器
> 
> 		iterator begin()
> 		{
> 			return _str;
> 		}
> 
> 		iterator end()
> 		{
> 			return _str + _size;
> 		}
> 
> 
> 		const_iterator begin() const
> 		{
> 			return _str;
> 		}
> 
> 		const_iterator end() const
> 		{
> 			return _str + _size;
> 		}
> #pragma endregion
> 
> #pragma region 成员变量
> 	private:
> 		size_t _capacity;//最大有效存储长度
> 		size_t _size;//实际长度
> 		char* _str;//字符串地址
> 	public:
> 
> 		//静态成员变量 : 声明定义分离
> 		static size_t npos;
> 		//C++11特性 : 加上const可直接在类内定义静态变量
> 		//const static size_t npos = -1;  
> #pragma endregion
> 
> 	};
> 
> 	size_t string::npos = -1;
> 
> #pragma region 输入输出
> 	//<<
> 	ostream& operator<<(std::ostream& out, const string& str)
> 	{
> 		for (size_t i = 0; i < str.size(); ++i)
> 		{
> 			out << str[i];
> 		}
> 		return out;
> 	}
> 
> 	////>> -- 基础版本
> 	//istream& operator>>(istream& in, string& str)
> 	//{
> 	//	//清理并设置初始容量
> 	//	str.clear();
> 	//	str.reserve(64);
> 	//
> 	//	char ch;
> 	//
> 	//	ch = in.get();
> 	//	while (ch != ' ' && ch != '\n')
> 	//	{
> 	//		str += ch;
> 	//		ch = in.get();
> 	//	}
> 	//
> 	//	return in;
> 	//}
> 
> 	//升级版--减少扩容操作
> 	istream& operator>>(istream& in, string& str)
> 	{
> 		//清理并设置初始容量
> 		str.clear();
> 		str.reserve(64);
> 
> 		const int N = 32;
> 		char buff[N];
> 		size_t i = 0;
> 
> 		char ch;
> 
> 		ch = in.get();
> 		while (ch != ' ' && ch != '\n')
> 		{
> 			buff[i++] = ch;
> 
> 			if (i == N - 1)
> 			{
> 				buff[i] = '\0';
> 				str += buff;
> 				i = 0;
> 			}
> 
> 			ch = in.get();
> 		}
> 
> 		buff[i] = '\0';
> 		str += buff;
> 
> 		return in;
> 	}
> #pragma endregion
> 
> 	//构造
> 	void test1()
> 	{
> 		cout << "MyString" << endl;
> 		string s1;
> 		string s2("String");
> 		string s3("HelloSTL", 5);
> 		string s4(20, 'o');
> 		string s5(s2);
> 		string s6(s4, 10);
> 
> 		cout << s1 << endl;
> 		cout << s2 << endl;
> 		cout << s3 << endl;
> 		cout << s4 << endl;
> 		cout << s5 << endl;
> 		cout << s6 << endl;
> 
> 	}
> 	//操作符
> 	void test2()
> 	{
> 		string s1("helloSTl");
> 		string s2;
> 
> 		cin >> s1 >> s2;
> 		cout << s1 << endl << s2 << endl;
> 		s2 = s1;
> 		cout << s1 << endl << s2 << endl;
> 	}
> 	void test3()
> 	{
> 		string s1("Hello");
> 		string s2("Mystring");
> 
> 		cout << s1 + '!' << endl;
> 		cout << s1 + " Bit" << endl;
> 		cout << s1 + s2 << endl;
> 
> 
> 		cout << (s1 += '!') << endl;
> 		cout << (s1 += " Bit") << endl;
> 		cout << (s1 += s2) << endl;
> 	}
> 	//增删改查
> 	void DealUrl(const string& url)
> 	{
> 		size_t pos1 = url.find("://");
> 		if (pos1 == string::npos)
> 		{
> 			cout << "非法url" << endl;
> 			return;
> 		}
> 		// 休息到16:08继续
> 		string protocol = url.substr(0, pos1);
> 		cout << protocol << endl;
> 
> 		size_t pos2 = url.find('/', pos1 + 3);
> 		if (pos2 == string::npos)
> 		{
> 			cout << "非法url" << endl;
> 			return;
> 		}
> 		string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
> 		cout << domain << endl;
> 
> 		string uri = url.substr(pos2 + 1);
> 		cout << uri << endl << endl;
> 	}
> 	void test4()
> 	{
> 		string url1 = "https://cplusplus.com/reference/string/string/";
> 		string url2 = "https://image.baidu.com/search/detail?ct=503316480&z=0&ipn=d&word=ascall&step_word=&hs=0&pn=0&spn=0&di=7108135681917976577&pi=0&rn=1&tn=baiduimagedetail&is=0%2C0&istype=0&ie=utf-8&oe=utf-8&in=&cl=2&lm=-1&st=undefined&cs=2613959014%2C543572025&os=2740573600%2C1059518451&simid=2613959014%2C543572025&adpicid=0&lpn=0&ln=179&fr=&fmq=1660115697093_R&fm=&ic=undefined&s=undefined&hd=undefined&latest=undefined&copyright=undefined&se=&sme=&tab=0&width=undefined&height=undefined&face=undefined&ist=&jit=&cg=&bdtype=0&oriquery=&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.php.cn%2Fupload%2Fimage%2F147%2F157%2F796%2F1593765739620093.png%26refer%3Dhttp%3A%2F%2Fimg.php.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Dauto%3Fsec%3D1662707704%26t%3Da68cb238bbb3f99d0554098c785d526e&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Brir_z%26e3BvgAzdH3FuwqAzdH3F9c9amd_z%26e3Bip4s&gsm=1&rpstart=0&rpnum=0&islist=&querylist=&nojc=undefined&dyTabStr=MCwzLDIsNCw2LDEsNSw3LDgsOQ%3D%3D";
> 		string url3 = "ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf";
> 
> 		DealUrl(url1);
> 		DealUrl(url2);
> 		DealUrl(url3);
> 	}
> 	void test5()
> 	{
> 		string s1;
> 		s1.resize(20);
> 		cout << s1 << endl;
> 
> 		string s2("hello");
> 		s2.resize(20, 'x');
> 		cout << s2 << endl;
> 		s2.resize(10);
> 		cout << s2 << endl;
> 
> 	}
> 	void test6()
> 	{
> 		string s("12345678");
> 		string s1("12345678");
> 
> 		cout << s.erase(0, 5) << endl;
> 		cout << s1.erase(6, 9) << endl;
> 		cout << string("123456").erase();
> 
> 	}
> 
> }
> 
> 
> 
> 
> ```
>
> ###### 构造函数
> ```c++
> //无参
> 	//---------注意
> 	// _str(nullptr) 错误: 转换成c指针 用cout输出的结束条件为 *p = '\0', 解引用了空指针
> 	// _str("\0") 错误: 常量字符串默认存在'\0'
> 	string()
> 		: _str(new char[1])
> 		, _size(0)
> 		, _capacity(0)
> 	{
> 		_str[0] = '\0';
> 	}
> 
> //常量字符串
> 	string(const char* str)
> 	{
> 		size_t len = strlen(str);
> 		_size = len;
> 		_capacity = len;
> 		_str = new char[len + 1];
> 		//使用strcpy拷贝, 符合常量字符串以'\0'结尾的规范
> 		strcpy(_str, str);
> 	}
> 	////常量字符串全缺省默认构造
> 	//string(const char* str = "")
> 	//{
> 	//	size_t len = strlen(str);
> 	//	_size = len;
> 	//	_capacity = len;
> 	//	_str = new char[len + 1];
> 	//	
> 	//	strcpy(_str, str);
> 	//}
> 
> //常量字符串前n个字符
> 	string(const char* str, size_t n)
> 	{
> 		//确定实际长度
> 		size_t len = strlen(str);
> 		len = len > n ? n : len;
> 
> 		_size = _capacity = len;
> 		_str = new char[_capacity + 1];
> 
> 		//strcpy 遇到\0结束, 不支持提前结束
> 		for (size_t i = 0; i < _size; i++)
> 		{
> 			_str[i] = str[i];
> 		}
> 		_str[_size] = '\0';
> 
> 	}
> 
> //n个字符 ch
> 	string(size_t n, char ch)
> 		:_str(new char[n + 1])//初始化列表初始化
> 		, _size(n)
> 		, _capacity(n)
> 	{
> 		for (size_t i = 0; i < _size; i++)
> 		{
> 			_str[i] = ch;
> 		}
> 		_str[_size] = '\0';
> 	}
> 
> /*拷贝构造*/
> 	////传统写法
> 	//string(const string& str)
> 	//	:_str(new char[str._capacity + 1])
> 	//	, _size(str._size)
> 	//	, _capacity(str._capacity)
> 	//{
> 	//	//string对象可包含'\0', 而strcpy无法copy'\0'
> 	//	memcpy(_str, str._str, _capacity + 1);
> 	//}
> 	//
> 
> 	//现代写法
> 	string(const string& str)
> 		: _str(nullptr)
> 		, _size(0)
> 		, _capacity(0)
> 	{
> 		string tmp(str._str);//调用常量字符串构造, 复用代码
> 		swap(tmp);//交换
> 	}
> 
> //sting对象 第 pos位置的 后n个字符
> 	string(const string& str, size_t pos, size_t n = npos)
> 
> 	{
> 		assert(pos < str._size);//合法下标
> 
> 		*this = str.substr(pos, n);//调用substr, 此处偷懒
> 
> 		//*this += str.substr(pos, n);
> 
> 		//错误语句
> 		// substr的返回值具有const属性, 无法修改, 不能作为swap的实参传递
> 		//swap(str.substr(pos, n));
> 	}  
> 
> //析构函数
> 	~string()
> 	{
> 		delete[] _str;
> 		_str = nullptr;
> 		_size = _capacity = 0;
> 	}
> ```
>
> ###### 空间操作
> ```c++
> //reserve
> 	//仅扩充空间大小
> 	void reserve(size_t n)
> 	{
> 		//仅扩充, 不缩小
> 		if (n <= _size) return;
> 
> 		char* tmp = new char[n + 1];
> 
> 		//string中可包含'\0', strcpy遇到'\0', 可能发生截断,应该按字节拷贝
> 		memcpy(tmp, _str, _capacity + 1);
> 
> 		delete[] _str;
> 		_str = tmp;
> 		tmp = nullptr;
> 		_capacity = n;
> 	}
> //resize
> 	//扩充/缩减长度 ---> 扩充空间
> 	void resize(size_t n, char ch = '\0')
> 	{
> 		if (n > _size)
> 		{
> 			//判断扩容
> 			reserve(n);
> 			//填充字符
> 			for (_size; _size < n; _size++)
> 			{
> 				_str[_size] = ch;
> 			}
> 			_str[_size] = '\0';
> 		}
> 		else//缩减长度
> 		{
> 			_str[n] = '\0';
> 			_size = n;
> 		}
> 	}
> //size
> 	size_t size() const
> 	{
> 		return _size;
> 	}
> //capacity
> 	size_t capacity() const
> 	{
> 		return _capacity;
> 	}
> //clear()
> 	//仅改变字符串长度
> 	void clear()
> 	{
> 		_str[0] = '\0';
> 		_size = 0;
> 	}
> ```
>
> ###### 增删改查
> ```c++	
> //push_back
> 	void push_back(char ch)
> 	{
> 		//是否扩容
> 		if (_size == _capacity)
> 		{
> 			reserve(_capacity == 0 ? 4 : _capacity * 2);
> 		}
> 
> 		_str[_size] = ch;
> 		_size++;
> 		_str[_size] = '\0';
> 	}
> //append
> 	void append(const char* str)
> 	{
> 		size_t len = strlen(str);
> 
> 		//是否扩容
> 		if (len + _size > _capacity)
> 		{
> 			reserve(len + _size);
> 		}
> 
> 		strcpy(_str + _size, str);
> 		//strcat(_str + _size, str);
> 
> 		_size += len;
> 	}
> 	void append(const string& str)
> 	{
> 		size_t len = str._size;
> 
> 		if (len + _size > _capacity)
> 		{
> 			reserve(len + _size);
> 		}
> 
> 		memcpy(_str + _size, str._str, str._size + 1);
> 
> 		_size += len;
> 	}
> //substr
> 	string substr(size_t pos, size_t len = npos) const
> 	{
> 		assert(pos < _size);//合法下标
> 		size_t realLen = len;
> 
> 		//判断是否超出string长度
> 		//len = 1, 对应的是 提取pos位置的元素
> 		if (len == npos || pos + len > _size)
> 		{
> 			realLen = _size - pos;
> 		}
> 
> 		string tmp;
> 		for (size_t i = 0; i < realLen; i++)
> 		{
> 			tmp += _str[pos + i];
> 		}
> 
> 		return tmp;//返回的临时对象为const属性
> 	}
> //instert -- 引用返回值 可作为 右值或参数
> 	string& insert(size_t pos, char ch)
> 	{
> 		assert(pos < _size);
> 
> 		if (_size == _capacity)
> 		{
> 			reserve(_capacity == 0 ? 4 : _capacity * 2);
> 		}
> 
> 		size_t end = ++_size;
> 
> 		while (end > pos)
> 		{
> 			_str[end] = _str[end - 1];
> 			end--;
> 		}
> 
> 		_str[pos] = ch;
> 
> 		return *this;
> 	}
> 	string& insert(size_t pos, const char* str)
> 	{
> 		assert(pos < _size);
> 
> 		size_t len = strlen(str);
> 
> 		if (_size + len > _capacity)
> 		{
> 			reserve(_size + len);
> 		}
> 
> 		size_t end = _size + len;
> 
> 		while (end >= pos + len)
> 		{
> 			_str[end] = _str[end - len];
> 			end--;
> 		}
> 
> 		strncpy(_str + pos, str, len);//不拷贝'\0', 只拷贝有效字符
> 		//memcpy(_str + pos, str, len);
> 		_size += len;
> 
> 		return *this;
> 	}
> 	string& insert(size_t pos, const string& str)
> 	{
> 		assert(pos < _size);
> 
> 		size_t len = str._size;
> 
> 		if (_size + len > _capacity)
> 		{
> 			reserve(_size + len);
> 		}
> 
> 		size_t end = _size + len;
> 
> 		while (end >= pos + len)
> 		{
> 			_str[end] = _str[end - len];
> 			end--;
> 		}
> 
> 		memcpy(_str + pos, str._str, len);
> 		_size += len;
> 
> 		return *this;
> 	}
> 	/*
> 	* 复用
> 	* 对于substring 和 buffer 可以通过 (转换成string)截断 + substr 实现
> 	*/
> 
> //find
> 	size_t find(char ch, size_t pos = 0) const
> 	{
> 		assert(pos < _size);
> 
> 		for (size_t i = pos; i < _size; ++i)
> 		{
> 			if (ch == _str[i])
> 			{
> 				return i;
> 			}
> 		}
> 
> 		return npos;
> 	}
> 	size_t find(const char* sub, size_t pos = 0) const
> 	{
> 		assert(sub);
> 		assert(pos < _size);
> 
> 		const char* ptr = strstr(_str + pos, sub);//cstrig库函数, 返回匹配的第一个字符的地址
> 		if (ptr == nullptr)
> 		{
> 			return npos;
> 		}
> 		else
> 		{
> 			return ptr - _str;
> 		}
> 	}
> 
> //erase
> 	string& erase(size_t pos = 0, size_t len = npos)
> 	{
> 		assert(pos < _size);
> 
> 		if (len == npos || pos + len >= _size)
> 		{
> 			_str[pos] = '\0';
> 			_size = pos;
> 		}
> 		else
> 		{
> 			memcpy(_str + pos, _str + pos + len, _size - pos - len + 1);
> 			_size -= len;
> 		}
> 
> 		return *this;
> 	}
> ```
>
> ###### 操作符重载
> ```c++	
> //逻辑操作符
> 	bool operator>(const string& str) const
> 	{
> 		return strcmp(_str, str._str) > 0;
> 	}
> 	bool operator==(const string& str) const
> 	{
> 		return strcmp(_str, str._str) == 0;
> 	}
> 	bool operator>=(const string& str) const
> 	{
> 		return *this > str || *this == str;
> 	}
> 	bool operator<=(const string& str) const
> 	{
> 		return !(*this > str);
> 	}
> 	bool operator<(const string& str) const
> 	{
> 		return !(*this >= str);
> 	}
> 	bool operator!=(const string& str) const
> 	{
> 		return !(*this == str);
> 	}
> 
> //运算操作符
> 	string& operator=(string str)
> 	{
> 		swap(str);
> 		return *this;
> 	}
> 
> 	string& operator+=(const char ch)
> 	{
> 		push_back(ch);
> 		return *this;
> 	}
> 	string operator+(const char ch)
> 	{
> 		string tmp(*this);
> 		tmp += ch;
> 		return tmp;
> 	}
> 
> 	string& operator+=(const string& str)
> 	{
> 		append(str);
> 		return *this;
> 	}
> 	string operator+(const string& str)
> 	{
> 		string tmp(*this);
> 		tmp.append(str);
> 		return tmp;
> 	}
> 
> 	string& operator+=(const char* str)
> 	{
> 		append(str);
> 		return *this;
> 	}
> 	string operator+(const char* str)
> 	{
> 		string tmp(*this);
> 		tmp.append(str);
> 		return tmp;
> 	}
> 
> //[]
> 	char& operator[](size_t pos)
> 	{
> 		assert(pos < _size);
> 		return _str[pos];
> 	}
> 	const char& operator[](size_t pos) const
> 	{
> 		assert(pos < _size);
> 		return _str[pos];
> 	}		
> ```
>
> ###### 迭代器/其他
> ```c++
> //迭代器	
> 	iterator begin()
> 	{
> 		return _str;
> 	}
> 
> 	iterator end()
> 	{
> 		return _str + _size;
> 	}
> 
> 
> 	const_iterator begin() const
> 	{
> 		return _str;
> 	}
> 
> 	const_iterator end() const
> 	{
> 		return _str + _size;
> 	}
> //其他
> 	//swap
> 	void swap(string& str)
> 	{
> 		std::swap(_str, str._str);
> 		std::swap(_size, str._size);
> 		std::swap(_capacity, str._capacity);
> 	}
> 
> 	//c指针
> 	const char* c_str() const
> 	{
> 		return _str;
> 	}	 
> ```
>
> ###### 输入输出
> ```c++
> //<<
> 	ostream& operator<<(std::ostream& out, const string& str)
> 	{
> 		for (size_t i = 0; i < str.size(); ++i)
> 		{
> 			out << str[i];
> 		}
> 		return out;
> 	}
> 
> //>> 
> 	//基础版本
> 	//istream& operator>>(istream& in, string& str)
> 	//{
> 	//	//清理并设置初始容量
> 	//	str.clear();
> 	//	str.reserve(64);
> 	//
> 	//	char ch;
> 	//
> 	//	ch = in.get();
> 	//	while (ch != ' ' && ch != '\n')
> 	//	{
> 	//		str += ch;
> 	//		ch = in.get();
> 	//	}
> 	//
> 	//	return in;
> 	//}
> 
> 	//升级版--减少前期扩容操作
> 	istream& operator>>(istream& in, string& str)
> 	{
> 		//清理并设置初始容量
> 		str.clear();
> 		str.reserve(64);
> 
> 		const int N = 32;
> 		char buff[N];
> 		size_t i = 0;
> 
> 		char ch;
> 
> 		ch = in.get();
> 		while (ch != ' ' && ch != '\n')
> 		{
> 			buff[i++] = ch;
> 
> 			if (i == N - 1)
> 			{
> 				buff[i] = '\0';
> 				str += buff;
> 				i = 0;
> 			}
> 
> 			ch = in.get();
> 		}
> 
> 		buff[i] = '\0';
> 		str += buff;
> 
> 		return in;
> 	}
> ```
>
> ###### 阅读推荐
> <a href = "https://coolshell.cn/articles/10478.html">酷壳-陈浩-C++面试中string类的一种正确写法</a>
> <a href = "https://blog.csdn.net/haoel/article/details/1491219?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166368282316782414956992%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166368282316782414956992&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-1491219-null-null.nonecase&utm_term=string%E7%B1%BB%E5%88%B0%E5%BA%95%E6%80%8E%E4%B9%88%E5%95%A6&spm=1018.2226.3001.4450">strig类到底怎么啦</a>
> [C++ STL string的Copy-On-Write技术](https://coolshell.cn/articles/12199.html) 
> [C++的std::string的“读时也拷贝”技术](https://coolshell.cn/articles/1443.html)



##### vector类

> **新思想**
> ```
> 泛型编程--模板成员变量
> 迭代器失效问题
> 深拷贝嵌套问题
> ```
>
> **自写模板--迭代器失效**
> ```
> 迭代器失效问题: insert(), erase()
> insert: 发生扩容 使pos指向的空间非法, 野指针; 插入后, pos不再指向原来的 [逻辑位置], 运行结果不符合逻辑, std::insert()返回插入的元素的迭代器
> erase: 发生缩容, 使pos指向的空间非法, 野指针; 逻辑问题. erase()根据编译器规则不同, 会有不同的结果. 不建议erase后立即访问, std::erase()返回删除元素的后一个元素的迭代器
> ```
>
> **其他**
> ```
> capacity的代码在vs和g++下分别运行会发现，vs下capacity是按1.5倍增长的，g++是按2倍增长的。 这个问题经常会考察，不要固化的认为，vector增容都是2倍，具体增长多少是根据具体的需求定义 的。vs是PJ版本STL，g++是SGI版本STL。 reserve只负责开辟空间，如果确定知道需要用多少空间，reserve可以缓解vector增容的代价缺陷问 题。 resize在开空间的同时还会进行初始化，影响size。
> ```
>
> ###### 全代码
>
> [Vector模拟实现](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/vector%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/Vector.h)
>
> ```c++
> #pragma once
> 
> #include<iostream>
> #include<vector>
> #include<assert.h>
> 
> using namespace std;
> 
> namespace qlz
> {
> 	template<class T>//模板类型
> 
> 	class vector
> 	{
> 	public:
> #pragma region TypedefAndIterator
> 		//vector迭代器是原生指针, 我们声明两个迭代器, 类型为模板类型指针;
> 		typedef T* iterator;
> 		typedef const T* const_iterator;
> 
> 		iterator begin()
> 		{
> 			return _start;
> 		}
> 		iterator end()
> 		{
> 			return _finish;
> 		}
> 		//const_iterator begin() const, 构成函数重载
> 		//因为第一个形参, 即对象的指针是不同类型, 一个是非const指针, 一个是const指针
> 		const_iterator cbegin() const
> 		{
> 			return _start;
> 		}
> 		const_iterator cend() const
> 		{
> 			return _finish;
> 		}
> 
> #pragma endregion
> 
> #pragma region 构造函数
> 
> 		//无参默认构造
> 		vector()
> 			:_start(nullptr)
> 			, _finish(nullptr)
> 			, _endOfStorage(nullptr)
> 		{}
> 
> 		//拷贝构造
> 		vector(const vector<T>& vec)
> 			:_start(nullptr)
> 			, _finish(nullptr)
> 			, _endOfStorage(nullptr)
> 		{
> 			reverse(vec.capacity());
> 
> 			/*for (size_t i = 0; i < vec.size(); i++)
> 			{
> 				_start[i] = vec._start[i];
> 			}
> 
> 			_finish = _start + vec.size();
> 			_endOfStorage = _start + vec.capacity();*/
> 
> 			//迭代器实现
> 			iterator it = begin();
> 			const_iterator vit = vec.cbegin();
> 			while (vit != vec.cend())
> 			{
> 				//已设置容量
> 				*it++ = *vit++;
> 			}
> 			_finish = it;
> 
> 		}
> 
> 		//n个元素
> 		vector(size_t n, const T& val = T())
> 			//注意成员变量声明顺序
> 			:_start(new T[n])
> 			, _finish(_start + n)
> 			, _endOfStorage(_start + n)
> 		{
> 			for (size_t i = 0; i < n; i++)
> 			{
> 				//已设置容量
> 				_start[i] = val;
> 			}
> 		}
> 		/*
> 		* 理论上将，提供了vector(size_t n, const T& value = T())之后
> 		* vector(int n, const T& value = T())就不需要提供了，但是对于：
> 		* vector<int> v(10, 10);
> 		* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
> 		* 就不会走vector(size_t n, const T& value = T())这个构造方法，
> 		* 因为 vector(InputIterator first, InputIterator last) 模板Inpu实例化为int时, 形参列表更符合
> 		* 但是10 和 10根本不是一个区间，编译时就报错了
> 		* 故需要该构造方法, 防止跑到迭代器构造函数
> 		*/
> 		vector(int n, const T& val = T())
> 			//注意成员变量声明顺序
> 			:_start(new T[n])
> 			, _finish(_start + n)
> 			, _endOfStorage(_start + n)
> 		{
> 			for (int i = 0; i < n; i++)
> 			{
> 				//已设置容量
> 				_start[i] = val;
> 			}
> 		}
> 
> 		//迭代器构造
> 		template<class InputIterator>//迭代器模板
> 		vector(InputIterator first, InputIterator last)
> 		{
> 			//复用push_back
> 			while (first != last)
> 			{
> 				//未确定容量, 调用push_back, 每次询问是否需要扩容
> 				push_back(*first);
> 				++first;
> 			}
> 		}
> 
> 		~vector()
> 		{
> 			delete[] _start;
> 			_start = _finish = _endOfStorage = nullptr;
> 		}
> 
> 
> #pragma endregion
> 
> #pragma region 空间
> 
> 	private:
> 		bool Full()
> 		{
> 			if (_finish == _endOfStorage)
> 			{
> 				return true;
> 			}
> 
> 			return false;
> 		}
> 	public:
> 		size_t capacity() const
> 		{
> 			return _endOfStorage - _start;
> 		}
> 
> 		size_t size() const
> 		{
> 			return _finish - _start;
> 		}
> 
> 		bool empty() const
> 		{
> 			if (_finish == _start)
> 			{
> 				return true;
> 			}
> 
> 			return false;
> 		}
> 
> 		void reverse(size_t n)
> 		{
> 			if (n <= capacity())
> 			{
> 				return;
> 			}
> 
> 			size_t oldSize = size();
> 
> 			T* tmp = new T[n];
> 
> 			for (size_t i = 0; i < oldSize; i++)
> 			{
> 				tmp[i] = _start[i];//模板类型T的赋值运算
> 			}
> 			delete[] _start;
> 
> 			_start = tmp;
> 			tmp = nullptr;
> 			_finish = _start + oldSize;
> 			_endOfStorage = _start + n;
> 
> 		}
> 
> 		void resize(size_t n, const T& val = T())
> 		{
> 			if (n <= _finish - _start)
> 			{
> 				_finish = _start + n;
> 			}
> 			else
> 			{
> 				reverse(n);
> 
> 				iterator cur = _finish;
> 				_finish = _start + n;
> 				while (cur != _finish)
> 				{
> 					//已经确定容量到位, 直接使用赋值, 减少调用
> 					*cur = val;
> 					cur++;
> 				}
> 			}
> 		}
> 
> #pragma endregion
> 
> #pragma region Other
> 
> 		//接受形参的引用, 将形参替换为空对象
> 		void swap(vector<T>& vec)
> 		{
> 			::swap(_start, vec._start);
> 			::swap(_finish, vec._finish);
> 			::swap(_endOfStorage, vec._endOfStorage);
> 		}
> 
> #pragma endregion
> 
> #pragma region 增删改查
> 
> 		//传元素引用, 防止无意义的深拷贝
> 		iterator insert(iterator it, const T& val)
> 		{
> 			assert(it <= _finish);//合法插入
> 
> 			if (Full())
> 			{
> 				size_t pos = it - _start;
> 
> 				reverse(capacity() == 0 ? 2 : capacity() * 2);
> 
> 				it = _start + pos;//重置插入位置迭代器, 防止迭代器失效
> 			}
> 
> 			iterator end = _finish - 1;//_finish所在地址, 为新的vector最后一个元素的位置
> 
> 			while (end >= it)
> 			{
> 				*(end + 1) = *end;
> 				end--;
> 			}
> 
> 			*it = val;
> 			_finish++;
> 			return it;//返回插入位置的迭代器
> 		}
> 
> 		//复用insert
> 		void push_back(const T& val)
> 		{
> 			insert(_finish, val);
> 		}
> 
> 		//返回被删除的位置的迭代器
> 		iterator erase(iterator it)
> 		{
> 			assert(!empty());//非空
> 
> 			// 挪动数据进行删除
> 			iterator begin = it;
> 			while (begin != _finish - 1) {
> 				*begin = *(begin + 1);
> 				++begin;
> 			}
> 
> 			--_finish;
> 			return it;
> 		}
> 
> 		//复用erase
> 		void pop_back()
> 		{
> 			erase(_finish - 1);
> 		}
> 
> #pragma endregion
> 
> 
> #pragma region 操作符AND访问
> 
> 		vector<T>& operator= (vector<T> vec)
> 		{
> 			swap(vec);
> 			return *this;
> 		}
> 
> 		T& operator[](size_t pos)
> 		{
> 			assert(pos < size());
> 			return _start[pos];
> 		}
> 
> 		const T& operator[](size_t pos)const
> 		{
> 			assert(pos < size());
> 			return _start[pos];
> 		}
> 
> 		T& front()
> 		{
> 			return *_start;
> 		}
> 
> 		const T& front()const
> 		{
> 			return *_start;
> 		}
> 
> 		T& back()
> 		{
> 			return *(_finish - 1);
> 		}
> 
> 		const T& back()const
> 		{
> 			return *(_finish - 1);
> 		}
> 
> #pragma endregion
> 
> 
> 	private:
> 
> 		//左闭右开
> 		//没必要设置初始值, 因为会频繁使用初始化列表
> 		iterator _start;//头
> 		iterator _finish;//尾 == 头指针 + 实际大小
> 		iterator _endOfStorage;// == 头指针 + 最大容量
> 	};
> 
> 	void Test1()
> 	{
> 		qlz::vector<int> v1;
> 		qlz::vector<int> v2(10, 5);
> 
> 		int array[] = { 1,2,3,4,5 };
> 		qlz::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
> 
> 		qlz::vector<int> v4(v3);
> 
> 		for (size_t i = 0; i < v2.size(); ++i)
> 		{
> 			cout << v2[i] << " ";
> 		}
> 		cout << endl;
> 
> 		auto it = v3.begin();
> 		while (it != v3.end())
> 		{
> 			cout << *it << " ";
> 			++it;
> 		}
> 		cout << endl;
> 
> 		for (auto e : v4)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 	}
> 
> 	void Test2()
> 	{
> 		qlz::vector<int> v;
> 		v.push_back(1);
> 		v.push_back(2);
> 		v.push_back(3);
> 		v.push_back(4);
> 		v.push_back(5);
> 		cout << v.size() << endl;
> 		cout << v.capacity() << endl;
> 		cout << v.front() << endl;
> 		cout << v.back() << endl;
> 		cout << v[0] << endl;
> 		for (auto e : v)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 
> 		v.pop_back();
> 		v.pop_back();
> 		for (auto e : v)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 
> 		v.insert(v.begin(), 0);
> 		for (auto e : v)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 
> 		v.erase(v.begin() + 1);
> 		for (auto e : v)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 	}
> 
> 	void Test3()
> 	{
> 		vector<int*> vec;
> 		int a = 1, b = 2, c = 3;
> 		vec.push_back(&a);
> 		vec.push_back(&c);
> 		vec.push_back(&b);
> 
> 		for (auto& ptr : vec)
> 		{
> 			cout << *ptr << ' ';
> 		}
> 
> 
> 	}
> }
> ```
>
> ###### 构造函数
> ```c++
> //无参默认构造
> 	vector()
> 		:_start(nullptr)
> 		, _finish(nullptr)
> 		, _endOfStorage(nullptr)
> 	{}
> 
> //拷贝构造
> 	vector(const vector<T>& vec)
> 		:_start(nullptr)
> 		, _finish(nullptr)
> 		, _endOfStorage(nullptr)
> 	{
> 		reverse(vec.capacity());
> 
> 		/*for (size_t i = 0; i < vec.size(); i++)
> 		{
> 			_start[i] = vec._start[i];
> 		}
> 
> 		_finish = _start + vec.size();
> 		_endOfStorage = _start + vec.capacity();*/
> 
> 		//迭代器实现
> 		iterator it = begin();
> 		const_iterator vit = vec.cbegin();
> 		while (vit != vec.cend())
> 		{
> 			//已设置容量
> 			*it++ = *vit++;
> 		}
> 		_finish = it;
> 
> 	}
> 
> //n个元素
> 	vector(size_t n, const T& val = T())
> 		//注意成员变量声明顺序
> 		:_start(new T[n])
> 		, _finish(_start + n)
> 		, _endOfStorage(_start + n)
> 	{
> 		for (size_t i = 0; i < n; i++)
> 		{
> 			//已设置容量
> 			_start[i] = val;
> 		}
> 	}
> 	/*
> 	* 理论上将，提供了vector(size_t n, const T& value = T())之后
> 	* vector(int n, const T& value = T())就不需要提供了，但是对于：
> 	* vector<int> v(10, 10);
> 	* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
> 	* 就不会走vector(size_t n, const T& value = T())这个构造方法，
> 	* 因为 vector(InputIterator first, InputIterator last) 模板Inpu实例化为int时, 形参列表更符合
> 	* 但是10 和 10根本不是一个区间，编译时就报错了
> 	* 故需要该构造方法, 防止跑到迭代器构造函数
> 	*/
> 	vector(int n, const T& val = T())
> 		//注意成员变量声明顺序
> 		:_start(new T[n])
> 		, _finish(_start + n)
> 		, _endOfStorage(_start + n)
> 	{
> 		for (int i = 0; i < n; i++)
> 		{
> 			//已设置容量
> 			_start[i] = val;
> 		}
> 	}
> 
> //迭代器构造
> 	template<class InputIterator>//迭代器模板
> 	vector(InputIterator first, InputIterator last)
> 	{
> 		//复用push_back
> 		while (first != last)
> 		{
> 			//未确定容量, 调用push_back, 每次询问是否需要扩容
> 			push_back(*first);
> 			++first;
> 		}
> 	}
> //析构
> 	~vector()
> 	{
> 		delete[] _start;
> 		_start = _finish = _endOfStorage = nullptr;
> 	}
> ```
>
> ###### 空间操作
> ```c++
> private:
> 	bool Full()//私有化
> 	{
> 		if (_finish == _endOfStorage)
> 		{
> 			return true;
> 		}
> 
> 		return false;
> 	}
> public:
> 	size_t capacity() const
> 	{
> 		return _endOfStorage - _start;
> 	}
> 
> 	size_t size() const
> 	{
> 		return _finish - _start;
> 	}
> 
> 	bool empty() const
> 	{
> 		if (_finish == _start)
> 		{
> 			return true;
> 		}
> 
> 		return false;
> 	}
> 
> 	void reverse(size_t n)
> 	{
> 		if (n <= capacity())
> 		{
> 			return;
> 		}
> 
> 		size_t oldSize = size();
> 
> 		T* tmp = new T[n];
> 
> 		for (size_t i = 0; i < oldSize; i++)
> 		{
> 			tmp[i] = _start[i];//模板类型T的赋值运算
> 		}
> 		delete[] _start;
> 
> 		_start = tmp;
> 		tmp = nullptr;
> 		_finish = _start + oldSize;
> 		_endOfStorage = _start + n;
> 
> 	}
> 
> 	void resize(size_t n, const T& val = T())
> 	{
> 		if (n <= _finish - _start)
> 		{
> 			_finish = _start + n;
> 		}
> 		else
> 		{
> 			reverse(n);
> 
> 			iterator cur = _finish;
> 			_finish = _start + n;
> 			while (cur != _finish)
> 			{
> 				//已经确定容量到位, 直接使用赋值, 减少调用
> 				*cur = val;
> 				cur++;
> 			}
> 		}
> 	}
> ```
>
> ###### 增删改查
> ```c++
> //传元素引用, 防止无意义的深拷贝
> 	iterator insert(iterator it, const T& val)
> 	{
> 		assert(it <= _finish);//合法插入
> 
> 		if (Full())
> 		{
> 			size_t pos = it - _start;
> 
> 			reverse(capacity() == 0 ? 2 : capacity() * 2);
> 
> 			it = _start + pos;//重置插入位置迭代器, 防止迭代器失效
> 		}
> 
> 		iterator end = _finish - 1;//_finish所在地址, 为新的vector最后一个元素的位置
> 
> 		while (end >= it)
> 		{
> 			*(end + 1) = *end;
> 			end--;
> 		}
> 
> 		*it = val;
> 		_finish++;
> 		return it;//返回插入位置的迭代器
> 	}
> 
> //复用insert
> 	void push_back(const T& val)
> 	{
> 		insert(_finish, val);
> 	}
> 
> //返回被删除的位置的迭代器
> 	iterator erase(iterator it)
> 	{
> 		assert(!empty());//非空
> 
> 		// 挪动数据进行删除
> 		iterator begin = it;
> 		while (begin != _finish - 1) {
> 			*begin = *(begin + 1);
> 			++begin;
> 		}
> 
> 		--_finish;
> 		return it;
> 	}
> 
> //复用erase
> 	void pop_back()
> 	{
> 		erase(_finish - 1);
> 	}
> ```
>
> ###### 操作符重载
> ```c++
> vector<T>& operator= (vector<T> vec)
> 	{
> 		swap(vec);
> 		return *this;
> 	}
> 
> 	T& operator[](size_t pos)
> 	{
> 		assert(pos < size());
> 		return _start[pos];
> 	}
> 
> 	const T& operator[](size_t pos)const
> 	{
> 		assert(pos < size());
> 		return _start[pos];
> 	}
> 
> 	T& front()
> 	{
> 		return *_start;
> 	}
> 
> 	const T& front()const
> 	{
> 		return *_start;
> 	}
> 
> 	T& back()
> 	{
> 		return *(_finish - 1);
> 	}
> 
> 	const T& back()const
> 	{
> 		return *(_finish - 1);
> 	}
> ```
>
> ###### 迭代器/其他
> ```c++
> //vector迭代器是原生指针, 我们声明两个迭代器, 类型为模板类型指针;
> 	typedef T* iterator;
> 	typedef const T* const_iterator;
> 
> 	iterator begin()
> 	{
> 		return _start;
> 	}
> 	iterator end()
> 	{
> 		return _finish;
> 	}
> 	//const_iterator begin() const, 构成函数重载
> 	//因为第一个形参, 即对象的指针是不同类型, 一个是非const指针, 一个是const指针
> 	const_iterator cbegin() const
> 	{
> 		return _start;
> 	}
> 	const_iterator cend() const
> 	{
> 		return _finish;
> 	}
> 
> //接受形参的引用, 将形参替换为空对象
> 	void swap(vector<T>& vec)
> 	{
> 		::swap(_start, vec._start);
> 		::swap(_finish, vec._finish);
> 		::swap(_endOfStorage, vec._endOfStorage);
> 	}
> ```
>



##### list类

> **新思想**
> ```
> 泛型编程
> 
> 泛型编程---通过模板类型列表的不同,形参实例化不同, 最终实现泛型编程
> 复用思想---适配器
> 非原生指针迭代器--封装原生指针, 形成迭代器类, 并重载运算符, 向原生指针靠拢
> 
> 重点迭代器
> 
> ```
>
> ###### 全代码
>
> [List的模拟实现](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/List%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/List.h)
>
> ```
> #pragma once
> 
> #include<assert.h>
> #include<iostream>
> #include<list>
> 
> using namespace std;
> 
> 
> namespace qlz
> {
> 
> 	template<typename T>//数据类型
> 	//节点结构
> 	struct list_node 
> 	{
> 		T _data;//元素
> 		list_node<T>* _next;//后指针
> 		list_node<T>* _prev;//前指针
> 
> 		list_node(const T& x = T())//默认构造
> 			:_data(x)
> 			, _next(nullptr)
> 			, _prev(nullptr)
> 		{}
> 
> 	};
> 
> 
> 	/*
> 	* 1. 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用, 两种迭代器属于相同的类型
> 	* 2. 通过实例化的区别, 生成const迭代器, 和非const迭代器, 两种迭代器属于不同的类型, 指定 引用返回, 指针返回的类型
> 	* typedef _list_iterator<T, T&, T*>             iterator;
> 	* typedef _list_iterator<T, const T&, const T*> const_iterator;
> 	* 
> 	* List 的迭代器
> 	* 迭代器有两种实现方式，具体应根据容器底层数据结构实现：
> 	*   1. 原生态指针，比如：vector
> 	*   2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
> 	* 	 1. 指针可以解引用，迭代器的类中必须重载operator*()
> 	* 	 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
> 	* 	 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
> 	* 		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前             移动，所以需要重载，如果是forward_list就不需要重载--
> 	* 	 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
> 	*/
> 	//正向迭代器
> 	template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
> 	struct _list_iterator
> 	{
> 	public:
> 		typedef list_node<T> Node;
> 		typedef _list_iterator<T, Ref, Ptr> iterator;
> 
> 		//使用 std::find() 需要这些 
> 		typedef bidirectional_iterator_tag iterator_category;
> 		typedef T value_type;
> 		typedef Ptr pointer;
> 		typedef Ref reference;
> 		typedef ptrdiff_t difference_type;
> 
> 		//反向迭代器需要这些
> 		typedef Ref Ref;
> 		typedef Ptr Ptr;
> 
> 		Node* _node;
> 
> 		//指针类型, 浅拷贝即可
> 		_list_iterator(Node* node = nullptr)
> 			:_node(node)
> 		{}
> 		//默认生成的拷贝构造为浅拷贝, 可使用
> 		/*_list_iterator(const iterator& it)
> 			:_node(it._node)
> 		{}*/
> 
> 		//!=
> 		bool operator!=(const iterator& it) const
> 		{
> 			return _node != it._node;
> 		}
> 
> 		//==
> 		bool operator==(const iterator& it) const
> 		{
> 			return _node == it._node;
> 		}
> 
> 
> 		/* 对于循环双向带头链表
> 		* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
> 		* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
> 		* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
> 		* 所以需要对 (*). / -> 重载
> 		* ++, -- 同理
> 		*/
> 
> 		//*
> 		// 注意模板类型
> 		// const T& operator*()
> 		// T& operator*()
> 		Ref operator*()
> 		{
> 			return (_node->_data);
> 		}
> 
> 		//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
> 		Ptr operator->()
> 		{
> 			return &(operator*());
> 		}
> 
> 		// ++it
> 		iterator& operator++()
> 		{
> 			_node = _node->_next;
> 			return *this;
> 		}
> 
> 		// it++
> 		iterator operator++(int)
> 		{
> 			iterator tmp(*this);
> 			_node = _node->_next;
> 			return tmp;
> 		}
> 
> 		// --it
> 		iterator& operator--()
> 		{
> 			_node = _node->_prev;
> 			return *this;
> 		}
> 
> 		// it--
> 		iterator operator--(int)
> 		{
> 			iterator tmp(*this);
> 			_node = _node->_prev;
> 			return tmp;
> 		}
> 
> 	};
> 
> 	/*反向迭代器(重写逻辑)*/
> 	//template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
> 	//struct _reverse_list_iterator
> 	//{
> 	//	typedef list_node<T> Node;
> 	//	typedef _reverse_list_iterator<T, Ref, Ptr> reverse_iterator;
> 	//
> 	//	Node* _node;
> 	//
> 	//	//指针类型, 浅拷贝即可
> 	//	_reverse_list_iterator(Node* node = nullptr)
> 	//		:_node(node)
> 	//	{}
> 	//
> 	//	//!=
> 	//	bool operator!=(const reverse_iterator& it) const
> 	//	{
> 	//		return _node != it._node;
> 	//	}
> 	//
> 	//	//==
> 	//	bool operator==(const reverse_iterator& it) const
> 	//	{
> 	//		return _node == it._node;
> 	//	}
> 	//
> 	//
> 	//	/* 对于循环双向带头链表
> 	//	* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
> 	//	* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
> 	//	* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
> 	//	* 所以需要对 (*). / -> 重载
> 	//	* ++, -- 同理
> 	//	*/
> 	//
> 	//	//*
> 	//	// 注意模板类型
> 	//	// const T& operator*()
> 	//	// T& operator*()
> 	//	Ref operator*()
> 	//	{
> 	//		Node* tmp= _node->_prev;
> 	//		return (tmp->_data);
> 	//	}
> 	//
> 	//	//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
> 	//	Ptr operator->()
> 	//	{
> 	//		return &(operator*());
> 	//	}
> 	//
> 	//	// ++it
> 	//	reverse_iterator& operator++()
> 	//	{
> 	//		_node = _node->_prev;
> 	//		return *this;
> 	//	}
> 	//
> 	//	// it++
> 	//	reverse_iterator operator++(int)
> 	//	{
> 	//		reverse_iterator tmp(*this);
> 	//		_node = _node->_prev;
> 	//		return tmp;
> 	//	}
> 	//
> 	//	// --it
> 	//	reverse_iterator& operator--()
> 	//	{
> 	//		_node = _node->_next;
> 	//		return *this;
> 	//	}
> 	//
> 	//	// it--
> 	//	reverse_iterator operator--(int)
> 	//	{
> 	//		iterator tmp(*this);
> 	//		_node = _node->_next;
> 	//		return tmp;
> 	//	}
> 	//
> 	//};
> 	/*反向迭代器(适配器)*/
> 	template<class iterator>
> 	struct _reverse_list_iterator
> 	{
> 	public:
> 		// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
> 		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
> 		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
> 		typedef typename iterator::Ref Ref;
> 		typedef typename iterator::Ptr Ptr;
> 		typedef _reverse_list_iterator<iterator> reverse_iterator;
> 	public:
> 		// 构造
> 		_reverse_list_iterator(iterator it)
> 			: _rit(it)
> 		{}
> 
> 		//////////////////////////////////////////////
> 		// 具有指针类似行为
> 		Ref operator*()
> 		{
> 			iterator temp(_rit);
> 			--temp;
> 			return *temp;
> 		}
> 
> 		Ptr operator->()
> 		{
> 			return &(operator*());
> 		}
> 
> 		// 迭代器支持移动
> 		reverse_iterator& operator++()
> 		{
> 			--_rit;
> 			return *this;
> 		}
> 
> 		reverse_iterator operator++(int)
> 		{
> 			reverse_iterator temp(*this);
> 			--_rit;
> 			return temp;
> 		}
> 
> 		reverse_iterator& operator--()
> 		{
> 			++_rit;
> 			return *this;
> 		}
> 
> 		reverse_iterator operator--(int)
> 		{
> 			reverse_iterator temp(*this);
> 			++_rit;
> 			return temp;
> 		}
> 
> 		// 迭代器支持比较
> 		bool operator!=(const reverse_iterator& l)const
> 		{
> 			return _rit != l._rit;
> 		}
> 
> 		bool operator==(const reverse_iterator& l)const
> 		{
> 			return _rit != l._rit;
> 		}
> 
> 		iterator _rit;
> 	};
> 
> 	//List
> 	template<typename T>
> 	class list//双向带头循环链表
> 	{
> 
> 	public:
> 		typedef list_node<T> Node;
> 		//通过实例化的区别, 生成const迭代器, 和非const迭代器
> 		typedef _list_iterator<T, T&, T*> iterator;
> 		typedef _list_iterator<T, const T&, const T*> const_iterator;		
> 		/*
> 		* 仍然可以 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用
> 		* eg
> 		* typedef const _list_iterator<T, T&, T*> const_iterator;
> 		* 
> 		* const iterator begin() const
> 		* {
> 		* 	return const iterator(_head->_next);
> 		* }
> 		*
> 		* const iterator end() const
> 		* {
> 		* 	return const iterator(_head);
> 		* }
> 		* 
> 		* T& operator*()
> 		* {
> 		* 	return (it->_data);
> 		* }
> 		* const T& operator*() const
> 		* {
> 		* 	return (it->_data);
> 		* }
> 		*/
> 
> 		/*反向迭代器(不复用)*/
> 		/*typedef _reverse_list_iterator<T, T&, T*> reverse_iterator;
> 		typedef _reverse_list_iterator<T, const T&, const T*> const_reverse_iterator;*/
> 		/*反向迭代器(复用)*/
> 		typedef _reverse_list_iterator<iterator> reverse_iterator;
> 		typedef _reverse_list_iterator<const_iterator> const_reverse_iterator;
> 
> 
> 
> #pragma region 构造函数
> 		list()
> 		{
> 			_head = new Node;
> 			_head->_next = _head;
> 			_head->_prev = _head;
> 		}
> 
> 		list(size_t n, const T& value = T())
> 		{
> 			_head = new Node;
> 			_head->_next = _head;
> 			_head->_prev = _head;
> 
> 			for (int i = 0; i < n; ++i)
> 				push_back(value);
> 		}
> 		list(int n, const T& value = T())
> 		{
> 			_head = new Node;
> 			_head->_next = _head;
> 			_head->_prev = _head;
> 
> 			for (int i = 0; i < n; ++i)
> 				push_back(value);
> 		}
> 
> 		template <class Iterator>
> 		list(Iterator first, Iterator last)
> 		{
> 			_head = new Node;
> 			_head->_next = _head;
> 			_head->_prev = _head;
> 
> 			while (first != last)
> 			{
> 				push_back(*first);
> 				++first;
> 			}
> 		}
> 
> 		list(const list<T>& l)
> 		{
> 			_head = new Node;
> 			_head->_next = _head;
> 			_head->_prev = _head;
> 
> 			// 用l中的元素构造临时的temp,然后与当前对象交换
> 			list<T> temp(l.begin(), l.end());
> 			this->swap(temp);
> 		}
> 
> 		list<T>& operator=(list<T> l)
> 		{
> 			this->swap(l);
> 			return *this;
> 		}
> 
> #pragma endregion
> 
> #pragma region 空间
> 
> 		//内置交换
> 		void swap(list<T>& l)
> 		{
> 			std::swap(_head, l._head);
> 		}
> 
> 		//判空
> 		bool empty()const
> 		{
> 			return _head->_next == _head;
> 		}
> 
> 		//元素个数
> 		size_t size()const
> 		{
> 			Node* cur = _head->_next;
> 			size_t count = 0;
> 			while (cur != _head)
> 			{
> 				count++;
> 				cur = cur->_next;
> 			}
> 
> 			return count;
> 		}
> 
> 		//设置元素个数
> 		void resize(size_t newsize, const T& val = T())
> 		{
> 			size_t oldsize = size();
> 			if (newsize <= oldsize)
> 			{
> 				// 有效元素个数减少到newsize
> 				while (newsize < oldsize)
> 				{
> 					pop_back();
> 					oldsize--;
> 				}
> 			}
> 			else
> 			{
> 				while (oldsize < newsize)
> 				{
> 					push_back(val);
> 					oldsize++;
> 				}
> 			}
> 		}
> 
> 		//清空
> 		void clear()
> 		{
> 			Node* cur = _head->_next;
> 
> 			// 采用头删除删除
> 			while (cur != _head)
> 			{
> 				_head->_next = cur->_next;
> 				delete cur;
> 				cur = _head->_next;
> 			}
> 			//只保留头节点
> 			_head->_next = _head->_prev = _head;
> 		}
> 
> #pragma endregion
> 
> #pragma region 迭代器
> 		const_iterator begin() const//const对象
> 		{
> 			return const_iterator(_head->_next);
> 		}
> 
> 		const_iterator end() const//const对象
> 		{
> 			return const_iterator(_head);
> 		}
> 
> 		iterator begin()
> 		{
> 			return iterator(_head->_next);
> 		}
> 
> 		iterator end()
> 		{
> 			return iterator(_head);
> 		}
> 
> 
> 		/*反向迭代器(不复用正向)*/
> 		//const_reverse_iterator rbegin() const//const对象
> 		//{
> 		//	return const_reverse_iterator(_head);
> 		//}
> 		//const_reverse_iterator rend() const//const对象
> 		//{
> 		//	return const_reverse_iterator(_head->_next);
> 		//}
> 		//reverse_iterator rbegin()
> 		//{
> 		//	return reverse_iterator(_head);
> 		//}
> 		//reverse_iterator rend()
> 		//{
> 		//	return reverse_iterator(_head->_next);
> 		//}
> 		/*反向迭代器(复用正向)*/
> 		const_reverse_iterator rbegin() const//const对象
> 		{
> 			return const_reverse_iterator(end());
> 		}
> 		const_reverse_iterator rend() const//const对象
> 		{
> 			return const_reverse_iterator(begin());
> 		}
> 		reverse_iterator rbegin()
> 		{
> 			return reverse_iterator(end());
> 		}
> 		reverse_iterator rend()
> 		{
> 			return reverse_iterator(begin());
> 		}
> #pragma endregion
> 
> #pragma region 增删
> 		void push_back(const T& val)
> 		{
> 			Node* node = new Node(val);
> 
> 			Node* tail = _head->_prev;
> 			tail->_next = node;
> 			node->_prev = tail;
> 			node->_next = _head;
> 			_head->_prev = node;
> 		}
> 
> 		//返回当前节点迭代器
> 		iterator insert(iterator pos, const T& x)
> 		{
> 			Node* cur = pos._node;
> 			Node* prev = cur->_prev;
> 
> 			Node* newnode = new Node(x);
> 
> 			// prev newnode cur
> 			prev->_next = newnode;
> 			newnode->_prev = prev;
> 			newnode->_next = cur;
> 			cur->_prev = newnode;
> 
> 			return iterator(newnode);
> 		}
> 
> 		//返回下一个节点的迭代器
> 		iterator erase(iterator pos)
> 		{
> 			assert(pos != end());
> 
> 			Node* cur = pos._node;
> 			Node* prev = cur->_prev;
> 			Node* next = cur->_next;
> 
> 			prev->_next = next;
> 			next->_prev = prev;
> 			delete cur;
> 
> 			return iterator(next);
> 		}
> 
> 		void push_front(const T& x)
> 		{
> 			insert(begin(), x);
> 		}
> 
> 		void pop_back()
> 		{
> 			erase(--end());
> 		}
> 
> 		void pop_front()
> 		{
> 			erase(begin());
> 		}
> #pragma endregion
> 
> #pragma region 访问
> 		//不支持[]
> 		T& front()
> 		{
> 			return _head->_next->_val;
> 		}
> 		const T& front()const
> 		{
> 			return _head->_next->_val;
> 		}
> 		T& back()
> 		{
> 			return _head->_prev->_val;
> 		}
> 		const T& back()const
> 		{
> 			return _head->_prev->_val;
> 		}
> #pragma endregion
> 
> 
> 	private:
> 		Node* _head;//头节点
> 	};
> 
> 
> 
> #pragma region 测试
> 
> 	/*void ttest1()
> 		{
> 			list<int> lis1;
> 
> 			lis1.push_back(1);
> 			lis1.push_back(2);
> 			lis1.push_back(3);
> 
> 
> 		}
> 
> 		struct pPos
> 		{
> 			int _a1;
> 			int _a2;
> 
> 			pPos(int a1 = 0, int a2 = 0)
> 				:_a1(a1)
> 				, _a2(a2)
> 			{}
> 		};
> 
> 		void ttest2()
> 		{
> 			int x = 10;
> 			int* p1 = &x;
> 
> 			cout << *p1 << endl;
> 
> 			pPos aa;
> 			pPos* p2 = &aa;
> 			p2->_a1;
> 			p2->_a2;
> 
> 			list<pPos> lt;
> 			lt.push_back(pPos(10, 20));
> 			lt.push_back(pPos(10, 21));
> 
> 			list<pPos>::iterator it = lt.begin();
> 
> 			cout << endl;
> 		}
> 
> 		void FFunc(const list<int>& l)
> 		{
> 			list<int>::const_iterator it = l.begin();
> 
> 			*it;
> 
> 			cout << endl;
> 		}*/
> 
> 	void test1()
> 	{
> 		list<int> lt;
> 		lt.push_back(1);
> 		lt.push_back(2);
> 		lt.push_back(3);
> 		lt.push_back(4);
> 		lt.push_back(5);
> 
> 		list<int>::iterator it = lt.begin();
> 		while (it != lt.end())
> 		{
> 			cout << *it << " ";
> 			++it;
> 		}
> 		cout << endl;
> 
> 		it = lt.begin();
> 		while (it != lt.end())
> 		{
> 			*it *= 2;
> 			++it;
> 		}
> 		cout << endl;
> 
> 		for (auto e : lt)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 	}
> 	struct Pos
> 	{
> 		int _a1;
> 		int _a2;
> 
> 		Pos(int a1 = 0, int a2 = 0)
> 			:_a1(a1)
> 			, _a2(a2)
> 		{}
> 	};
> 	void test2()
> 	{
> 		int x = 10;
> 		int* p1 = &x;
> 
> 		cout << *p1 << endl;
> 
> 		Pos aa;
> 		Pos* p2 = &aa;
> 		p2->_a1;
> 		p2->_a2;
> 
> 		list<Pos> lt;
> 		lt.push_back(Pos(10, 20));
> 		lt.push_back(Pos(10, 21));
> 
> 		list<Pos>::iterator it = lt.begin();
> 		while (it != lt.end())
> 		{
> 			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
> 			cout << it->_a1 << ":" << it->_a2 << endl;
> 
> 			++it;
> 		}
> 		cout << endl;
> 	}
> 	void Func(const list<int>& l)
> 	{
> 		list<int>::const_iterator it = l.begin();
> 		while (it != l.end())
> 		{
> 			//*it = 10;
> 
> 			cout << *it << " ";
> 			++it;
> 		}
> 		cout << endl;
> 	}
> 	void test3()
> 	{
> 		list<int> lt;
> 		lt.push_back(1);
> 		lt.push_back(2);
> 		lt.push_back(3);
> 		lt.push_back(4);
> 		lt.push_back(5);
> 
> 		Func(lt);
> 	}
> 	void test4()
> 	{
> 		list<int> lt;
> 		lt.push_back(1);
> 		lt.push_back(2);
> 		lt.push_back(3);
> 		lt.push_back(4);
> 		lt.push_back(5);
> 
> 		list<int>::iterator it = lt.begin();
> 		while (it != lt.end())
> 		{
> 			cout << *it << " ";
> 			++it;
> 		}
> 		cout << endl;
> 
> 		it = lt.begin();
> 		while (it != lt.end())
> 		{
> 			*it *= 2;
> 			++it;
> 		}
> 		cout << endl;
> 
> 		for (auto e : lt)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 
> 		lt.push_front(10);
> 		lt.push_front(20);
> 		lt.push_front(30);
> 		lt.push_front(40);
> 
> 		lt.pop_back();
> 		lt.pop_back();
> 
> 		for (auto e : lt)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 
> 		auto pos = find(lt.begin(), lt.end(), 4);
> 		if (pos != lt.end())
> 		{
> 			// pos是否会失效？不会
> 			lt.insert(pos, 40);
> 			//lt.insert(pos, 30);
> 			*pos *= 100;
> 		}
> 
> 		for (auto e : lt)
> 		{
> 			cout << e << " ";
> 		}
> 		cout << endl;
> 	}
> 	void test5()
> 	{
> 		list<int> l1;
> 		l1.push_back(4);
> 		l1.push_back(1);
> 		l1.push_back(3);
> 		l1.push_back(2);
> 
> 		/*auto it = l1.begin();
> 		cout << *it << endl;
> 
> 		auto rit = l1.rbegin();
> 
> 		cout << *rit;*/
> 
> 		for (auto rit = l1.rbegin(); rit != l1.rend(); rit++)
> 			cout << *rit << endl;
> 
> 
> 
> 	}
> #pragma endregion
> 
> 
> }
> 
> ```
>
> ###### 构造函数
> ```C++
> list()
> {
> 	_head = new Node;
> 	_head->_next = _head;
> 	_head->_prev = _head;
> }
> 
> list(size_t n, const T& value = T())
> {
> 	_head = new Node;
> 	_head->_next = _head;
> 	_head->_prev = _head;
> 
> 	for (int i = 0; i < n; ++i)
> 		push_back(value);
> }
> list(int n, const T& value = T())
> {
> 	_head = new Node;
> 	_head->_next = _head;
> 	_head->_prev = _head;
> 
> 	for (int i = 0; i < n; ++i)
> 		push_back(value);
> }
> 
> template <class Iterator>
> list(Iterator first, Iterator last)
> {
> 	_head = new Node;
> 	_head->_next = _head;
> 	_head->_prev = _head;
> 
> 	while (first != last)
> 	{
> 		push_back(*first);
> 		++first;
> 	}
> }
> 
> list(const list<T>& l)
> {
> 	_head = new Node;
> 	_head->_next = _head;
> 	_head->_prev = _head;
> 
> 	// 用l中的元素构造临时的temp,然后与当前对象交换
> 	list<T> temp(l.begin(), l.end());
> 	this->swap(temp);
> }
> 
> list<T>& operator=(list<T> l)
> {
> 	this->swap(l);
> 	return *this;
> }
> ```
>
> ###### 空间操作
> ```c++
> //内置交换
> void swap(list<T>& l)
> {
> 	std::swap(_head, l._head);
> }
> 
> //判空
> bool empty()const
> {
> 	return _head->_next == _head;
> }
> 
> //元素个数
> size_t size()const
> {
> 	Node* cur = _head->_next;
> 	size_t count = 0;
> 	while (cur != _head)
> 	{
> 		count++;
> 		cur = cur->_next;
> 	}
> 
> 	return count;
> }
> 
> //设置元素个数
> void resize(size_t newsize, const T& val = T())
> {
> 	size_t oldsize = size();
> 	if (newsize <= oldsize)
> 	{
> 		// 有效元素个数减少到newsize
> 		while (newsize < oldsize)
> 		{
> 			pop_back();
> 			oldsize--;
> 		}
> 	}
> 	else
> 	{
> 		while (oldsize < newsize)
> 		{
> 			push_back(val);
> 			oldsize++;
> 		}
> 	}
> }
> 
> //清空
> void clear()
> {
> 	Node* cur = _head->_next;
> 
> 	// 采用头删除删除
> 	while (cur != _head)
> 	{
> 		_head->_next = cur->_next;
> 		delete cur;
> 		cur = _head->_next;
> 	}
> 	//只保留头节点
> 	_head->_next = _head->_prev = _head;
> }
> ```
>
> ###### 增删
> ```c++
> void push_back(const T& val)
> {
> 	Node* node = new Node(val);
> 
> 	Node* tail = _head->_prev;
> 	tail->_next = node;
> 	node->_prev = tail;
> 	node->_next = _head;
> 	_head->_prev = node;
> }
> 
> //返回当前节点迭代器
> iterator insert(iterator pos, const T& x)
> {
> 	Node* cur = pos._node;
> 	Node* prev = cur->_prev;
> 
> 	Node* newnode = new Node(x);
> 
> 	// prev newnode cur
> 	prev->_next = newnode;
> 	newnode->_prev = prev;
> 	newnode->_next = cur;
> 	cur->_prev = newnode;
> 
> 	return iterator(newnode);
> }
> 
> //返回下一个节点的迭代器
> iterator erase(iterator pos)
> {
> 	assert(pos != end());
> 
> 	Node* cur = pos._node;
> 	Node* prev = cur->_prev;
> 	Node* next = cur->_next;
> 
> 	prev->_next = next;
> 	next->_prev = prev;
> 	delete cur;
> 
> 	return iterator(next);
> }
> 
> void push_front(const T& x)
> {
> 	insert(begin(), x);
> }
> 
> void pop_back()
> {
> 	erase(--end());
> }
> 
> void pop_front()
> {
> 	erase(begin());
> }
> ```
>
> ###### 迭代器
>
> **模板类声明**
> ```c++
> //迭代器模板类声明
> typedef list_node<T> Node;
> //通过实例化的区别, 生成const迭代器, 和非const迭代器
> typedef _list_iterator<T, T&, T*> iterator;
> typedef _list_iterator<T, const T&, const T*> const_iterator;		
> //仍然可以 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用
> 
> /*反向迭代器(不复用)*/
> /*typedef _reverse_list_iterator<T, T&, T*> reverse_iterator;
> typedef _reverse_list_iterator<T, const T&, const T*> const_reverse_iterator;*/
> /*反向迭代器(复用)*/
> typedef _reverse_list_iterator<iterator> reverse_iterator;
> typedef _reverse_list_iterator<const_iterator> const_reverse_iterator;
> 
> //----------------------------------------------------------------------------
> ```
> **模板类**
> ```c++
> //迭代器模板类
> /*
> * 1. 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用, 两种迭代器属于相同的类型
> * 2. 通过实例化的区别, 生成const迭代器, 和非const迭代器, 两种迭代器属于不同的类型, 指定 引用返回, 指针返回的类型
> * typedef _list_iterator<T, T&, T*>             iterator;
> * typedef _list_iterator<T, const T&, const T*> const_iterator;
> * 
> * List 的迭代器
> * 迭代器有两种实现方式，具体应根据容器底层数据结构实现：
> *   1. 原生态指针，比如：vector
> *   2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
> * 	 1. 指针可以解引用，迭代器的类中必须重载operator*()
> * 	 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
> * 	 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
> * 		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前             移动，所以需要重载，如果是forward_list就不需要重载--
> * 	 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
> */
> //正向迭代器
> template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
> struct _list_iterator
> {
> public:
> 	typedef list_node<T> Node;
> 	typedef _list_iterator<T, Ref, Ptr> iterator;
> 
> 	//使用 std::find() 需要这些 
> 	typedef bidirectional_iterator_tag iterator_category;
> 	typedef T value_type;
> 	typedef Ptr pointer;
> 	typedef Ref reference;
> 	typedef ptrdiff_t difference_type;
> 
> 	//反向迭代器需要这些
> 	typedef Ref Ref;
> 	typedef Ptr Ptr;
> 
> 	Node* _node;
> 
> 	//指针类型, 浅拷贝即可
> 	_list_iterator(Node* node = nullptr)
> 		:_node(node)
> 	{}
> 	//默认生成的拷贝构造为浅拷贝, 可使用
> 	/*_list_iterator(const iterator& it)
> 		:_node(it._node)
> 	{}*/
> 
> 	//!=
> 	bool operator!=(const iterator& it) const
> 	{
> 		return _node != it._node;
> 	}
> 
> 	//==
> 	bool operator==(const iterator& it) const
> 	{
> 		return _node == it._node;
> 	}
> 
> 
> 	/* 对于循环双向带头链表
> 	* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
> 	* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
> 	* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
> 	* 所以需要对 (*). / -> 重载
> 	* ++, -- 同理
> 	*/
> 
> 	//*
> 	// 注意模板类型
> 	// const T& operator*()
> 	// T& operator*()
> 	Ref operator*()
> 	{
> 		return (_node->_data);
> 	}
> 
> 	//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
> 	Ptr operator->()
> 	{
> 		return &(operator*());
> 	}
> 
> 	// ++it
> 	iterator& operator++()
> 	{
> 		_node = _node->_next;
> 		return *this;
> 	}
> 
> 	// it++
> 	iterator operator++(int)
> 	{
> 		iterator tmp(*this);
> 		_node = _node->_next;
> 		return tmp;
> 	}
> 
> 	// --it
> 	iterator& operator--()
> 	{
> 		_node = _node->_prev;
> 		return *this;
> 	}
> 
> 	// it--
> 	iterator operator--(int)
> 	{
> 		iterator tmp(*this);
> 		_node = _node->_prev;
> 		return tmp;
> 	}
> 
> };
> 
> /*反向迭代器(重写逻辑)*/
> //template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
> //struct _reverse_list_iterator
> //{
> //	typedef list_node<T> Node;
> //	typedef _reverse_list_iterator<T, Ref, Ptr> reverse_iterator;
> //
> //	Node* _node;
> //
> //	//指针类型, 浅拷贝即可
> //	_reverse_list_iterator(Node* node = nullptr)
> //		:_node(node)
> //	{}
> //
> //	//!=
> //	bool operator!=(const reverse_iterator& it) const
> //	{
> //		return _node != it._node;
> //	}
> //
> //	//==
> //	bool operator==(const reverse_iterator& it) const
> //	{
> //		return _node == it._node;
> //	}
> //
> //
> //	/* 对于循环双向带头链表
> //	* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
> //	* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
> //	* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
> //	* 所以需要对 (*). / -> 重载
> //	* ++, -- 同理
> //	*/
> //
> //	//*
> //	// 注意模板类型
> //	// const T& operator*()
> //	// T& operator*()
> //	Ref operator*()
> //	{
> //		Node* tmp= _node->_prev;
> //		return (tmp->_data);
> //	}
> //
> //	//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
> //	Ptr operator->()
> //	{
> //		return &(operator*());
> //	}
> //
> //	// ++it
> //	reverse_iterator& operator++()
> //	{
> //		_node = _node->_prev;
> //		return *this;
> //	}
> //
> //	// it++
> //	reverse_iterator operator++(int)
> //	{
> //		reverse_iterator tmp(*this);
> //		_node = _node->_prev;
> //		return tmp;
> //	}
> //
> //	// --it
> //	reverse_iterator& operator--()
> //	{
> //		_node = _node->_next;
> //		return *this;
> //	}
> //
> //	// it--
> //	reverse_iterator operator--(int)
> //	{
> //		iterator tmp(*this);
> //		_node = _node->_next;
> //		return tmp;
> //	}
> //
> //};
> /*反向迭代器(适配器)*/
> template<class iterator>
> struct _reverse_list_iterator
> {
> public:
> 	// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
> 	// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
> 	// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
> 	typedef typename iterator::Ref Ref;
> 	typedef typename iterator::Ptr Ptr;
> 	typedef _reverse_list_iterator<iterator> reverse_iterator;
> public:
> 	// 构造
> 	_reverse_list_iterator(iterator it)
> 		: _rit(it)
> 	{}
> 
> 	//////////////////////////////////////////////
> 	// 具有指针类似行为
> 	Ref operator*()
> 	{
> 		iterator temp(_rit);
> 		--temp;
> 		return *temp;
> 	}
> 
> 	Ptr operator->()
> 	{
> 		return &(operator*());
> 	}
> 
> 	// 迭代器支持移动
> 	reverse_iterator& operator++()
> 	{
> 		--_rit;
> 		return *this;
> 	}
> 
> 	reverse_iterator operator++(int)
> 	{
> 		reverse_iterator temp(*this);
> 		--_rit;
> 		return temp;
> 	}
> 
> 	reverse_iterator& operator--()
> 	{
> 		++_rit;
> 		return *this;
> 	}
> 
> 	reverse_iterator operator--(int)
> 	{
> 		reverse_iterator temp(*this);
> 		++_rit;
> 		return temp;
> 	}
> 
> 	// 迭代器支持比较
> 	bool operator!=(const reverse_iterator& l)const
> 	{
> 		return _rit != l._rit;
> 	}
> 
> 	bool operator==(const reverse_iterator& l)const
> 	{
> 		return _rit != l._rit;
> 	}
> 
> 	iterator _rit;
> };
> 
> //---------------------------------------------------------------------------------
> ```
> **函数**
> ```
> //迭代器函数
> const_iterator begin() const//const对象
> {
> 	return const_iterator(_head->_next);
> }
> 
> const_iterator end() const//const对象
> {
> 	return const_iterator(_head);
> }
> 
> iterator begin()
> {
> 	return iterator(_head->_next);
> }
> 
> iterator end()
> {
> 	return iterator(_head);
> }
> 
> 
> /*反向迭代器(不复用正向)*/
> //const_reverse_iterator rbegin() const//const对象
> //{
> //	return const_reverse_iterator(_head);
> //}
> //const_reverse_iterator rend() const//const对象
> //{
> //	return const_reverse_iterator(_head->_next);
> //}
> //reverse_iterator rbegin()
> //{
> //	return reverse_iterator(_head);
> //}
> //reverse_iterator rend()
> //{
> //	return reverse_iterator(_head->_next);
> //}
> /*反向迭代器(复用正向)*/
> const_reverse_iterator rbegin() const//const对象
> {
> 	return const_reverse_iterator(end());
> }
> const_reverse_iterator rend() const//const对象
> {
> 	return const_reverse_iterator(begin());
> }
> reverse_iterator rbegin()
> {
> 	return reverse_iterator(end());
> }
> reverse_iterator rend()
> {
> 	return reverse_iterator(begin());
> }
> 
> ```
>
> 

### 继承

##### 继承的基本概念和定义

###### 概念

> **继承(inheritance)机制是面向对象程序设计使代码可以复用的最重要的手段**，它允许程序员在保持原有类特性的基础上进行扩展，增加功能，这样产生新的类，称派生类。继承呈现了面向对象 程序设计的层次结构，体现了由简单到复杂的认知过程。以前我们接触的复用都是函数复用，继承是类设计层次的复用。
>
> ~~~c++
> class Person
> {
>     public:
>     void Print()
>     {
>         cout << "name:" << _name << endl;
>         cout << "age:" << _age << endl;
>     }
>     protected:
>     string _name = "peter"; // 姓名
>     int _age = 18;  // 年龄
> };
> // 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
> class Student : public Person
> {
>     protected:
>     int _stuid; // 学号
> };
> class Teacher : public Person
> {
>     protected:
>     int _jobid; // 工号
> };
> int main()
> {
>     Student s;
>     Teacher t;
>     s.Print();
>     t.Print();
>     return 0;
> }
> ~~~

###### 定义格式

> 1. 定义格式： 下面我们看到Person是父类，也称作基类。Student是子类，也称作派生类。
>
>     ![image-20221020141552758](%E5%9B%BE%E7%89%87/README/image-20221020141552758.png)
>
> 2. 继承关系
>
>     ![image-20221020141634603](%E5%9B%BE%E7%89%87/README/image-20221020141634603.png)

###### 继承的基类成员访问权限的变化

> | 类成员/继承方式      |       public继承       | protected继承          | private继承          |
> | -------------------- | :--------------------: | ---------------------- | -------------------- |
> | 基类的public成员     |   派生类的public成员   | 派生类的protected 成员 | 派生类的private 成员 |
> | 基类的protected 成员 | 派生类的protected 成员 | 派生类的protected 成员 | 派生类的private 成员 |
> | 基类的private成 员   |    在派生类中不可见    | 在派生类中不可见       | 在派生类中不可 见    |
>
> 即：
>
> 1. 基类private成员在派生类中无论以什么方式继承都是不可见的。这里的**不可见是指基类的私 有成员还是被继承到了派生类对象中，但是语法上限制派生类对象不管在类里面还是类外面 都不能去访问它。** 
> 2. 基类private成员在派生类中是不能被访问，如果基类成员不想在类外直接被访问，但需要在 派生类中能访问，就定义为protected。**可以看出保护成员限定符是因继承才出现的。**
> 3. 实际上面的表格我们进行一下总结会发现，基类的私有成员在子类都是不可见。基类的其他 成员在子类的访问方式 == Min(成员在基类的访问限定符，继承方式)，public > protected  > private。 
> 4. 使用关键字**class时默认的继承方式是private，使用struct时默认的继承方式是public**，不过 **最好显示的写出继承方式。**
> 5. **在实际运用中一般使用都是public继承，几乎很少使用protetced/private继承**，也不提倡 使用protetced/private继承，因为protetced/private继承下来的成员都只能在派生类的类里 面使用，实际中扩展维护性不强。
>
> ~~~C++
> // 实例演示三种继承关系下基类成员的各类型成员访问关系的变化  
> class Person
> {
> public
>  void Print ()
>  {
>  cout<<_name <<endl;
>  }
> protected :
>  string _name ; // 姓名
> private :
>  int _age ; // 年龄
> };
> //class Student : protected Person
> //class Student : private Person
> class Student : public Person
> {
> protected :
>  int _stunum ; // 学号
> };
> ~~~

##### 基类和派生类 对象赋值转换

> - **派生类对象 可以赋值给 基类的对象 / 基类的指针 / 基类的引用。**这里有个形象的说法叫**切片 或者切割**。寓意把派生类中父类那部分切来赋值过去。 
> - **基类对象不能赋值给派生类对象。** 
> - **基类的指针或者引用可以通过强制类型转换赋值给派生类的指针或者引用。** **但是必须是基类 的指针是指向派生类对象时才是安全的。**(如：基类的引用是被派生类赋值的， 则这个基类引用可以强转成对应子类的引用) 这里基类如果是多态类型，可以使用RTTI(RunTime Type Information)的dynamic_cast 来进行识别后进行安全转换。（ps：这个我们后 面再讲解，这里先了解一下）
>
> ![image-20221020143620244](%E5%9B%BE%E7%89%87/README/image-20221020143620244.png)
>
> ~~~C++
> class Person
> {
>     protected :
>     string _name; // 姓名
>     string _sex;  // 性别
>     int _age; // 年龄
> };
> class Student : public Person
> {
>     public :
>     int _No ; // 学号
> };
> void Test ()
> {
>     Student sobj ;
>     // 1.子类对象可以赋值给父类对象/指针/引用
>     Person pobj = sobj ;
>     Person* pp = &sobj;
>     Person& rp = sobj;
> 
>     //2.基类对象不能赋值给派生类对象
>     sobj = pobj;
> 
>     // 3.基类的指针可以通过强制类型转换赋值给派生类的指针
>     pp = &sobj;
>     Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
>     ps1->_No = 10;
> 
>     pp = &pobj;
>     Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
>     ps2->_No = 10;
> }
> ~~~
> **注意**：这种转换不属于类型转换，而是特殊语法
>
> ![image-20221015092045923](%E5%9B%BE%E7%89%87/README/image-20221015092045923.png)

------



##### 继承中的作用域

> 1. 在继承体系中基类和派生类都有独立的作用域。 
> 2. **子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏， 也叫重定义。（在子类成员函数中，可以使用 基类::基类成员 显示访问）** 
> 3. 需要注意的是**如果是成员函数的隐藏，只需要函数名相同就构成隐藏**。 
> 4. 注意在实际中在继承体系里面最好不要定义同名的成员。
>
> ~~~C++
> // Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
> class Person
> {
>     protected :
>     string _name = "小李子"; // 姓名
>     int _num = 111;   // 身份证号
> };
> class Student : public Person
> {
>     public:
>     void Print()
>     {
>         cout<<" 姓名:"<<_name<< endl;
>         cout<<" 身份证号:"<<Person::_num<< endl;
>         cout<<" 学号:"<<_num<<endl;
>     }
>     protected:
>     int _num = 999; // 学号
> };
> void Test()
> {
>     Student s1;
>     s1.Print();
> };
> 
> ~~~
>
> ~~~C++
> // B中的fun和A中的fun不是构成重载，因为不是在同一作用域
> // B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
> class A
> {
>     public:
>     void fun()
>     {
>         cout << "func()" << endl;
>     }
> };
> class B : public A
> {
>     public:
>     void fun(int i)
>     {
>         A::fun();
>         cout << "func(int i)->" <<i<<endl;
>     }
> };
> void Test()
> {
>     B b;
>     b.fun(10);
> };
> ~~~

------



##### 派生类的默认成员函数

> 6个默认成员函数，“默认”的意思就是指我们不写，编译器会变我们自动生成一个，那么在派生类 中，这几个成员函数是如何生成的呢？ 
>
> 1. **派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。**如果**基类没有默认 的构造函数**，则**必须在派生类构造函数的初始化列表阶段显示调用。** 
> 2. 派生类的拷贝构造函数**必须调用基类的拷贝构造完成基类的拷贝初始化**。 
> 3. 派生类的operator=**必须要调用基类的operator=完成基类的复制。** 
> 4. **派生类的析构函数会在被调用完成后自动调用基类的析构函数清理基类成员。**因为这样才能 保证派生类对象先清理派生类成员再清理基类成员的顺序。
> 5. **派生类对象初始化先调用基类构造再调派生类构造。** 
> 6.  **派生类对象析构清理先调用派生类析构再调基类的析构。** 
> 7. 因为后续一些场景析构函数需要构成重写，重写的条件之一是函数名相同(这个我们后面会讲 解)。那么**编译器会对析构函数名进行特殊处理，处理成destrutor()，所以父类析构函数不加 virtual的情况下，子类析构函数和父类析构函数构成隐藏关系。**
>
> ![image-20221020145447885](%E5%9B%BE%E7%89%87/README/image-20221020145447885.png)
>
> ~~~C++
> class Person
> {
>     public :
>     Person(const char* name = "peter")
>         : _name(name )
>         {
>             cout<<"Person()" <<endl;
>         }
> 
>     Person(const Person& p)
>         : _name(p._name)
>         {
>             cout<<"Person(const Person& p)" <<endl;
>         }
> 
>     Person& operator=(const Person& p )
>     {
>         cout<<"Person operator=(const Person& p)"<< endl;
>         if (this != &p)
>             _name = p ._name;
> 
>         return *this ;
>     }
> 
>     ~Person()
>     {
>         cout<<"~Person()" <<endl;
>     }
>     protected :
>     string _name ; // 姓名
> };
> class Student : public Person
> {
>     public :
>     Student(const char* name, int num)
>         : Person(name )
>             , _num(num )
>         {
>             cout<<"Student()" <<endl;
>         }
> 
>     Student(const Student& s)
>         : Person(s)
>             , _num(s ._num)
>         {
>             cout<<"Student(const Student& s)" <<endl ;
>         }
> 
>     Student& operator = (const Student& s )
>     {
>         cout<<"Student& operator= (const Student& s)"<< endl;
>         if (this != &s)
>         {
>             Person::operator =(s);
>             _num = s ._num;
>         }
>         return *this ;
>     } 
> 
>     ~Student()
>     {
>         cout<<"~Student()" <<endl;
>     }
>     protected :
>     int _num ; //学号
> };
> void Test ()
> {
>     Student s1 ("jack", 18);
>     Student s2 (s1);
>     Student s3 ("rose", 17);
>     s1 = s3 ;
> }
> 
> ~~~
>
> 

------

##### 继承与友元

> 友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员 
>
> ~~~C++
> class Student;
> class Person
> {
>     public:
>     friend void Display(const Person& p, const Student& s);
>     protected:
>     string _name; // 姓名
> };
> class Student : public Person
> {
>     protected:
>     int _stuNum; // 学号
> };
> void Display(const Person& p, const Student& s)
> {
>     cout << p._name << endl;
>     cout << s._stuNum << endl;
> }
> void main()
> {
>     Person p;
>     Student s;
>     Display(p, s);
> }
> 
> ~~~
>
> 

------

##### 继承与静态成员

> 基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子 类，都只有一个static成员实例 。
>
> ~~~C++
> class Person
> {
>     public :
>     Person () {++ _count ;}
>     protected :
>     string _name ; // 姓名
>     public :
>     static int _count; // 统计人的个数。
> };
> int Person :: _count = 0;
> class Student : public Person
> {
>     protected :
>     int _stuNum ; // 学号
> };
> class Graduate : public Student
> {
>     protected :
>     string _seminarCourse ; // 研究科目
> };
> void TestPerson()
> {
>     Student s1 ;
>     Student s2 ;
>     Student s3 ;
>     Graduate s4 ;
>     cout <<" 人数 :"<< Person ::_count << endl;
>     Student ::_count = 0;
>     cout <<" 人数 :"<< Person ::_count << endl;
> }
> 
> ~~~
>
> 

------

##### 复杂的菱形继承及菱形虚拟继承

###### 继承方式

> **单继承：**一个子类只有一个直接父类时称这个继承关系为单继承
>
> ![image-20221020145902743](%E5%9B%BE%E7%89%87/README/image-20221020145902743.png)
>
> **多继承：**一个子类有两个或以上直接父类时称这个继承关系为多继承
>
> ![image-20221020145949271](%E5%9B%BE%E7%89%87/README/image-20221020145949271.png)
>
> **菱形继承：**菱形继承是多继承的一种特殊情况。
>
> ![image-20221020150007884](%E5%9B%BE%E7%89%87/README/image-20221020150007884.png)

###### 菱形继承的问题 与 虚拟继承

> **菱形继承的问题：从下面的对象成员模型构造，可以看出菱形继承有数据冗余和二义性的问题。 在Assistant的对象中Person成员会有两份。**
>
> ![image-20221020150043641](%E5%9B%BE%E7%89%87/README/image-20221020150043641.png)
>
> ~~~C++
> class Person
> {
>     public :
>     string _name ; // 姓名
> };
> class Student : public Person
> {
>     protected :
>     int _num ; //学号
> };
> class Teacher : public Person
> {
>     protected :
>     int _id ; // 职工编号
> };
> class Assistant : public Student, public Teacher
> {
>     protected :
>     string _majorCourse ; // 主修课程
> };
> void Test ()
> {
>     // 这样会有二义性无法明确知道访问的是哪一个
>     Assistant a ;
>     a._name = "peter";
>     // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
>     a.Student::_name = "xxx";
>     a.Teacher::_name = "yyy";
> }
> 
> ~~~
>
> **虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在Student和 Teacher的继承Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地方去使用。**
>
> ~~~C++
> class Person
> {
> public :
>  string _name ; // 姓名
> };
> class Student : virtual public Person
> {
> protected :
>  int _num ; //学号
> };
> class Teacher : virtual public Person
> {
> protected :
>  int _id ; // 职工编号
> };
> class Assistant : public Student, public Teacher
> {
> protected :
>  string _majorCourse ; // 主修课程
> };
> void Test ()
> {
>  Assistant a ;
>  a._name = "peter";
> }
> ~~~
>
> **虚拟继承解决数据冗余和二义性的原理** 
>
> 为了研究虚拟继承原理，我们给出了一个简化的菱形虚拟继承体系，再借助内存窗口观察对象成 员的模型。
>
> ~~~C++
> class A
> {
>     public:
>     int _a;
> };
> // class B : public A
> class B : virtual public A
> {
>     public:
>     int _b;
> };
> // class C : public A
> class C : virtual public A
> {
>     public:
>     int _c;
> };
> class D : public B, public C
> {
>     public:
>     int _d;
> };
> int main()
> {
>     D d;
>     d.B::_a = 1;
>     d.C::_a = 2;
>     d._b = 3;
>     d._c = 4;
>     d._d = 5;
>     return 0;
> }
> ~~~
>
> 下图是菱形继承的内存对象成员模型：这里可以看到数据冗余
>
> ![image-20221020150405408](%E5%9B%BE%E7%89%87/README/image-20221020150405408.png)
>
> 下图是菱形虚拟继承的内存对象成员模型：这里可以分析出D对象中将A放到的了对象组成的最下 面，这个A同时属于B和C，那么B和C如何去找到公共的A呢？**这里是通过了B和C的两个指针，指 向的一张表。这两个指针叫虚基表指针，这两个表叫虚基表。虚基表中存的偏移量。通过偏移量 可以找到下面的A。**
>
> ![image-20221020150441865](%E5%9B%BE%E7%89%87/README/image-20221020150441865.png)
>
> ~~~C++
>      // 有童鞋会有疑问为什么D中B和C部分要去找属于自己的A？那么大家看看当下面的赋值发生时，d是不是要去找出B/C成员中的A才能赋值过去？
> D d;
> B b = d;
> C c = d;
> ~~~
> 
>下面是上面的Person关系菱形虚拟继承的原理解释：
> 
>![image-20221020150526890](%E5%9B%BE%E7%89%87/README/image-20221020150526890.png)

------



##### 继承的总结和反思

> 1. 很多人说C++语法复杂，其实多继承就是一个体现。有了多继承，就存在菱形继承，有了菱 形继承就有菱形虚拟继承，底层实现就很复杂。所以一般不建议设计出多继承，一定不要设 计出菱形继承。否则在复杂度及性能上都有问题。 
>
> 2.  多继承可以认为是C++的缺陷之一，很多后来的OO语言都没有多继承，如Java。 
>
> 3. 继承和组合
>
>     - public继承是一种is-a的关系。也就是说每个派生类对象都是一个基类对象。 
>     - 组合是一种has-a的关系。假设B组合了A，每个B对象中都有一个A对象。
>     - 优先使用对象组合，而不是类继承 。[优先使用对象组合，而不是类继承 - 残雪余香 - 博客园 (cnblogs.com)](https://www.cnblogs.com/nexiyi/archive/2013/06/16/3138568.html)
>     - 继承允许你根据基类的实现来定义派生类的实现。这种通过生成派生类的复用通常被称 为白箱复用(white-box reuse)。术语“白箱”是相对可视性而言：在继承方式中，基类的 内部细节对子类可见 。继承一定程度破坏了基类的封装，基类的改变，对派生类有很 大的影响。派生类和基类间的依赖关系很强，耦合度高。 
>     - 对象组合是类继承之外的另一种复用选择。新的更复杂的功能可以通过组装或组合对象 来获得。对象组合要求被组合的对象具有良好定义的接口。这种复用风格被称为黑箱复 用(black-box reuse)，因为对象的内部细节是不可见的。对象只以“黑箱”的形式出现。 组合类之间没有很强的依赖关系，耦合度低。优先使用对象组合有助于你保持每个类被 封装。 
>     - 实际尽量多去用组合。组合的耦合度低，代码维护性好。不过继承也有用武之地的，有 些关系就适合继承那就用继承，另外要实现多态，也必须要继承。类之间的关系可以用 继承，可以用组合，就用组合。
>
>     ~~~C++
>     // Car和BMW Car和Benz构成is-a的关系
>     class Car{
>         protected:
>         string _colour = "白色"; // 颜色
>         string _num = "陕ABIT00"; // 车牌号
>     };
>                                                                                             
>     class BMW : public Car{
>         public:
>         void Drive() {cout << "好开-操控" << endl;}
>     };
>                                                                                             
>     class Benz : public Car{
>         public:
>         void Drive() {cout << "好坐-舒适" << endl;}
>     };
>                                                                                             
>     // Tire和Car构成has-a的关系
>                                                                                             
>     class Tire{
>         protected:
>         string _brand = "Michelin";  // 品牌
>         size_t _size = 17;         // 尺寸
>                                                                                             
>     };
>                                                                                             
>     class Car{
>         protected:
>         string _colour = "白色"; // 颜色
>         string _num = "陕ABIT00"; // 车牌号
>         Tire _t; // 轮胎
>     }; 
>     ~~~
>
>     

------

##### 笔试面试

> 1. 什么是菱形继承？菱形继承的问题是什么？ 
> 2. 什么是菱形虚拟继承？如何解决数据冗余和二义性的 
> 3. 继承和组合的区别？什么时候用继承？什么时候用组合？

------



### 多态

多态的概念：通俗来说，就是多种形态，具体点就是去完成某个行为，当不同的对象去完成时会 产生出不同的状态。

##### 定义及实现

###### 多态的构成条件

> 多态是在不同继承关系的类对象，去调用同一函数，产生了不同的行为。比如Student继承了 Person。Person对象买票全价，Student对象买票半价。 
>
> 那么在继承中要构成多态还有两个条件： 
>
> 1. **必须通过基类的指针或者引用调用虚函数**
> 2. **被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写**
>
> ![image-20221020153736497](%E5%9B%BE%E7%89%87/README/image-20221020153736497.png)

###### 虚函数

> 虚函数：
>
> 即被virtual修饰的**类成员函数**称为虚函数。
>
> ~~~c++
> class Person {
>     public:
>     virtual void BuyTicket() { cout << "买票-全价" << endl;}
> };
> ~~~

###### 虚函数的重写

> 虚函数的重写(覆盖)：派生类中有一个跟基类完全相同的虚函数(即派生类虚函数与基类虚函数的 返回值类型、函数名字、参数列表完全相同)，称子类的虚函数重写了基类的虚函数。
>
> ~~~C++
> class Person {
>     public:
>     virtual void BuyTicket() { cout << "买票-全价" << endl; }
> };
> class Student : public Person {
>     public:
>     virtual void BuyTicket() { cout << "买票-半价" << endl; }
>     /*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
>     为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
>     这样使用*/
>     /*void BuyTicket() { cout << "买票-半价" << endl; }*/
> };
> void Func(Person& p)
> { p.BuyTicket(); }
> int main()
> {
>     Person ps;
>     Student st;
>     Func(ps);
>     Func(st);
>     return 0;
> }
> 
> ~~~
>
> **虚函数重写的两个例外**： 
>
> 1. **协变(基类与派生类虚函数返回值类型不同)** 
>
>     派生类重写基类虚函数时，与基类虚函数返回值类型不同。**即基类虚函数返回基类对象的指 针或者引用，派生类虚函数返回派生类对象的指针或者引用时，称为协变。**（了解）
>
>     ~~~C++
>     class A{};
>     class B : public A {};
>     class Person {
>         public:
>         virtual A* f() {return new A;}
>     };
>     class Student : public Person {
>         public:
>         virtual B* f() {return new B;}
>     };
>     
>     ~~~
>
> 2. **析构函数的重写(基类与派生类析构函数的名字不同)**
>
>     如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字， 都与基类的析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同， 看起来违背了重写的规则，其实不然，这**里可以理解为编译器对析构函数的名称做了特殊处 理，编译后析构函数的名称统一处理成destructor。**
>
>     ~~~C++
>     class Person {
>         public:
>         virtual ~Person() {cout << "~Person()" << endl;}
>     };
>     class Student : public Person {
>         public:
>         virtual ~Student() { cout << "~Student()" << endl; }
>     };
>     // 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
>     数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
>         int main()
>     {
>         Person* p1 = new Person;
>         Person* p2 = new Student;
>         delete p1;
>         delete p2;
>         return 0;
>     }
>                                                                                             
>     ~~~

------

#####  C++11 override 和 final

> 从上面可以看出，C++对函数重写的要求比较严格，但是有些情况下由于疏忽，可能会导致函数 名字母次序写反而无法构成重载，而这种错误在编译期间是不会报出的，只有在程序运行时没有 得到预期结果才来debug会得不偿失，因此：**C++11提供了override和final两个关键字，可以帮 助用户检测是否重写。**
>
> 1. **final：修饰虚函数，表示该虚函数不能再被重写**
>
>     ~~~C++
>     class Car
>     {
>         public:
>         virtual void Drive() final {}
>     };
>     class Benz :public Car
>     {
>         public:
>         virtual void Drive() {cout << "Benz-舒适" << endl;}
>     };
>     ~~~
>
> 2.  **override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错**。
>
>     ~~~C++
>     class Car{
>         public:
>         virtual void Drive(){}
>     };
>     class Benz :public Car {
>         public:
>         virtual void Drive() override {cout << "Benz-舒适" << endl;}
>     };
>     ~~~
>
>     

------

##### 重载、覆盖(重写)、隐藏(重定义)的对比



> ![image-20221020164121890](%E5%9B%BE%E7%89%87/README/image-20221020164121890.png)

------

##### 建议

###### 不实现多态不要将函数定义为虚函数

> ~~~C++
> 存在虚函数就会产生虚表， 有虚表就会运行时决议， 浪费时间空间
> ~~~

###### 析构函数建议定义为虚函数

> ~~~c++
> 父类* str1 = new 父类;
> 父类* str2 = new 子类;
> delete str1;
> delete str2;
> 若不把析构函数定义为虚函数， 不满足多态，则delete父类类型指针，会调用两次父类的析构
> ~~~
>
> 

------

##### 抽象类

###### 抽象类

> **在虚函数的后面写上 =0 ，则这个函数为纯虚函数。**包含纯虚函数的类叫做抽象类（**也叫接口 类**），抽象类不能实例化出对象。**派生类继承后也不能实例化出对象，只有重写全部纯虚函数，派生类才能实例化出对象，否则派生类仍是抽象类，不能实例化对象**。纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。
>
> ~~~C++
> class Car
> {
>     public:
>     virtual void Drive() = 0;
> };
> class Benz :public Car
> {
>     public:
>     virtual void Drive()
>     {
>         cout << "Benz-舒适" << endl;
>     }
> };
> class BMW :public Car
> {
>     public:
>     virtual void Drive()
>     {
>         cout << "BMW-操控" << endl;
>     }
> };
> void Test()
> {
>     Car* pBenz = new Benz;
>     pBenz->Drive();
>     Car* pBMW = new BMW;
>     pBMW->Drive();
> }
> ~~~

###### 接口继承和实现继承

> 普通函数的继承是一种实现继承，派生类继承了基类函数，可以使用函数，继承的是函数的实 现。虚函数的继承是一种接口继承，派生类继承的是基类虚函数的接口，目的是为了重写，达成 多态，继承的是接口。所以如果不实现多态，不要把函数定义成虚函数。**因为存在虚函数就会产生虚表， 有虚表就会运行时决议， 浪费时间空间。**

------

##### 多态的原理

###### 虚函数表

> ~~~C++
> // 这里常考一道笔试题：sizeof(Base)是多少？
> class Base
> {
>  public:
>  virtual void Func1()
>  {
>      cout << "Func1()" << endl;
>  }
>  private:
>  int _b = 1;
> };
> 
> ~~~
>
> 通过观察测试我们发现b对象是8bytes，**除了_b成员，还多一个__vfptr放在对象的前面(注意有些 平台可能会放到对象的最后面，这个跟平台有关)，对象中的这个指针我们叫做虚函数表指针(v代 表virtual，f代表function)。**一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数 的地址要被放到虚函数表中，虚函数表也简称虚表，。那么派生类中这个表放了些什么呢？我们 接着往下分析
>
> ![image-20221020165130484](%E5%9B%BE%E7%89%87/README/image-20221020165130484.png)
>
> ~~~C++
> // 针对上面的代码我们做出以下改造
> // 1.我们增加一个派生类Derive去继承Base
> // 2.Derive中重写Func1
> // 3.Base再增加一个虚函数Func2和一个普通函数Func3
> class Base
> {
>     public:
>     virtual void Func1()
>     {
>         cout << "Base::Func1()" << endl;
>     }
>     virtual void Func2()
>     {
>         cout << "Base::Func2()" << endl;
>     }
>     void Func3()
>     {
>         cout << "Base::Func3()" << endl;
>     }
>     private:
>     int _b = 1;
> };
> class Derive : public Base
> {
>     public:
>     virtual void Func1()
>     {
>         cout << "Derive::Func1()" << endl;
>     }
>     private:
>     int _d = 2;
> };
> int main()
> {
>     Base b;
>     Derive d;
>     return 0;
> }
> 
> ~~~
>
> **通过观察和测试，我们发现了以下几点问题：** 
>
> 1. 派生类对象d中也有一个虚表指针，d对象由两部分构成，一部分是父类继承下来的成员，虚表指针也就是父类部分的，另一部分是自己的成员。 
>
> 2. **基类b对象和派生类d对象虚表是不一样的，**这里我们发现Func1完成了重写，所以**d的虚表 中存的是重写的Derive::Func1，**所以虚函数的重写也叫作覆盖，覆盖就是指虚表中虚函数 的覆盖。重写是语法的叫法，覆盖是原理层的叫法。 
>
> 3. 另外**Func2继承下来后是虚函数，所以放进了虚表，Func3也继承下来了，但是不是虚函 数，所以不会放进虚表。** 
>
> 4.  **虚函数表本质是一个存虚函数指针的指针数组，一般情况这个数组最后面放了一个nullptr。**
>
> 5. 总结一下派生类的虚表生成：
>
>     - 先将**基类中的虚表内容拷贝一份到派生类虚表中** 
>     - 如果派生 类重写了基类中某个虚函数，用派生类自己的**虚函数覆盖虚表中基类的虚函数** 
>     - **派生类自己 新增加的虚函数按其在派生类中的声明次序增加到派生类虚表的最后。** 
>
> 6. 这里还有一个童鞋们很容易混淆的问题：虚函数存在哪的？虚表存在哪的？ **答：虚函数存在 虚表，虚表存在对象中。注意上面的回答的错的。**但是很多童鞋都是这样深以为然的。注意 **虚表存的是虚函数指针，不是虚函数，虚函数和普通函数一样的，都是存在代码段的，只是 他的指针又存到了虚表中。另外对象中存的不是虚表，存的是虚表指针。那么虚表存在哪的 呢？实际我们去验证一下会发现vs下是存在代码段的，**Linux g++下大家自己去验证？
>
>     ![image-20221020170157379](%E5%9B%BE%E7%89%87/README/image-20221020170157379.png)

------

###### 多态的原理▲

> 上面分析了这个半天了那么多态的原理到底是什么？还记得这里Func函数传Person调用的 Person::BuyTicket，传Student调用的是Student::BuyTicket
>
> ![image-20221020170939096](%E5%9B%BE%E7%89%87/README/image-20221020170939096.png)
>
> ~~~C++
> class Person {
>     public:
>     virtual void BuyTicket() { cout << "买票-全价" << endl; }
> };
> class Student : public Person {
>     public:
>     virtual void BuyTicket() { cout << "买票-半价" << endl; }
> };
> void Func(Person& p)
> {
>     p.BuyTicket();
> }
> int main()
> {
>     Person Mike;
>     Func(Mike);
>     Student Johnson;
>     Func(Johnson);
>     return 0;
> }
> ~~~
>
> 1. 观察下图的红色箭头我们看到，p是指向mike对象时，p->BuyTicket在mike的虚表中找到虚 函数是Person::BuyTicket。 
>
> 2. 观察下图的蓝色箭头我们看到，p是指向johnson对象时，p->BuyTicket在johson的虚表中 找到虚函数是Student::BuyTicket。
>
> 3. 这样就实现出了不同对象去完成同一行为时，展现出不同的形态。
>
> 4. 反过来思考我们要达到多态，有两个条件，一个是虚函数覆盖，一个是对象的指针或引用调 用虚函数。反思一下为什么？ 
>
> 5.  再通过下面的汇编代码分析，看出**满足多态以后的函数调用，不是在编译时确定的，是运行 起来以后到对象的中取找的。不满足多态的函数调用时编译时确认好的。**
>
>     ![image-20221020171058295](%E5%9B%BE%E7%89%87/README/image-20221020171058295.png)
>
>     ~~~C++
>     void Func(Person* p)
>     {
>         p->BuyTicket();
>     }
>     int main()
>     {
>         Person mike;
>         Func(&mike);
>         mike.BuyTicket();
>                                                                             
>         return 0;
>     }
>     // 以下汇编代码中跟你这个问题不相关的都被去掉了
>     void Func(Person* p)
>     {
>         //...
>             p->BuyTicket();
>         // p中存的是mike对象的指针，将p移动到eax中
>         001940DE  mov         eax,dword ptr [p]
>             // [eax]就是取eax值指向的内容，这里相当于把mike对象头4个字节(虚表指针)移动到了edx
>             001940E1  mov         edx,dword ptr [eax]
>             // [edx]就是取edx值指向的内容，这里相当于把虚表中的头4字节存的虚函数指针移动到了eax
>             00B823EE  mov         eax,dword ptr [edx]
>             // call eax中存虚函数的指针。这里可以看出满足多态的调用，不是在编译时确定的，是运行起来以后到对象的中取找的。
>             001940EA  call        eax  
>             001940EC  cmp         esi,esp  
>     }
>     int main()
>     {
>         ... 
>             // 首先BuyTicket虽然是虚函数，但是mike是对象，不满足多态的条件，所以这里是普通函数的调用转换成地址时，是在编译时已经从符号表确认了函数的地址，直接call 地址
>             mike.BuyTicket();
>         00195182  lea         ecx,[mike]
>         00195185  call        Person::BuyTicket (01914F6h)  
>             ... 
>     }
>                                                                             
>     ~~~
>
>     

###### 动态绑定与静态绑定

> 1. 静态绑定又称为前期绑定(早绑定)，在程序编译期间确定了程序的行为，也称为静态多态， 比如：函数重载，模板编程
> 2. 动态绑定又称后期绑定(晚绑定)，是在程序运行期间，根据具体拿到的类型确定程序的具体 行为，调用具体的函数，也称为动态多态。 
> 3. 本小节之前(5.2小节)买票的汇编代码很好的解释了什么是静态(编译器)绑定和动态(运行时)绑 定。

------

##### 单继承和多继承关系的虚函数表

> 需要注意的是在单继承和多继承关系中，下面我们去关注的是派生类对象的虚表模型，因为基类 的虚表模型前面我们已经看过了，没什么需要特别研究的

###### 单继承中的虚函数表

> ~~~C++
> class Base { 
>     public :
>     virtual void func1() { cout<<"Base::func1" <<endl;}
>     virtual void func2() {cout<<"Base::func2" <<endl;}
>     private :
>     int a;
> };
> class Derive :public Base { 
>     public :
>     virtual void func1() {cout<<"Derive::func1" <<endl;}
>     virtual void func3() {cout<<"Derive::func3" <<endl;}
>     virtual void func4() {cout<<"Derive::func4" <<endl;}
>     private :
>     int b;
> };
> 
> ~~~
>
> 观察下图中的监视窗口中我们发现看不见func3和func4。这里是编译器的监视窗口故意隐藏了这 两个函数，也可以认为是他的一个小bug。那么我们如何查看d的虚表呢？下面我们使用代码打印 出虚表中的函数。
>
> ![image-20221020171810440](%E5%9B%BE%E7%89%87/README/image-20221020171810440.png)
>
> ~~~C++
> typedef void(*VFPTR) ();
> void PrintVTable(VFPTR vTable[])
> {
>     // 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
>     cout << " 虚表地址>" << vTable << endl;
>     for (int i = 0; vTable[i] != nullptr; ++i)
>     {
>         printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
>         VFPTR f = vTable[i];
>         f();
>     }
>     cout << endl;
> }
> int main()
> {
>     Base b;
>     Derive d;
>     // 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr
>     // 1.先取b的地址，强转成一个int*的指针
>     // 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
>     // 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
>     // 4.虚表指针传递给PrintVTable进行打印虚表
>     // 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的-生成-清理解决方案，再编译就好了。
>     VFPTR* vTableb = (VFPTR*)(*(int*)&b);
>     PrintVTable(vTableb);
>     VFPTR* vTabled = (VFPTR*)(*(int*)&d);
>     PrintVTable(vTabled);
>     return 0;
> }
> 
> ~~~
>
> ![image-20221020171905028](%E5%9B%BE%E7%89%87/README/image-20221020171905028.png)

###### 多继承中的虚函数表

> ~~~C++
> class Base1 {
>  public:
>  virtual void func1() {cout << "Base1::func1" << endl;}
>  virtual void func2() {cout << "Base1::func2" << endl;}
>  private:
>  int b1;
> };
> class Base2 {
>  public:
>  virtual void func1() {cout << "Base2::func1" << endl;}
>  virtual void func2() {cout << "Base2::func2" << endl;}
>  private:
>  int b2;
> };
> class Derive : public Base1, public Base2 {
>  public:
>  virtual void func1() {cout << "Derive::func1" << endl;}
>  virtual void func3() {cout << "Derive::func3" << endl;}
>  private:
>  int d1;
> };
> typedef void(*VFPTR) ();
> void PrintVTable(VFPTR vTable[])
> {
>  cout << " 虚表地址>" << vTable << endl;
>  for (int i = 0; vTable[i] != nullptr; ++i)
>  {
>      printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
>      VFPTR f = vTable[i];
>      f();
>  }
>  cout << endl;
> }
> int main()
> {
>  Derive d;
>  VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
>  PrintVTable(vTableb1);
>  VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d+sizeof(Base1)));
>  PrintVTable(vTableb2);
>  return 0;
> }
> 
> ~~~
>
> 观察下图可以看出：多继承派生类的未重写的/新增的虚函数放在**第一个继承基类部分的虚函数表**中
>
> ![image-20221020172015696](%E5%9B%BE%E7%89%87/README/image-20221020172015696.png)
>
> **为什么两个父类的虚表中， func1的地址不一样▲**
>
> ~~~c++
> 因为VS编译器， call的地址，不是函数的地址， 而是一条jump指令的地址， 跳转到这个指令， 通过这个指令去call原函数
> ~~~
>
> 

######  菱形继承、菱形虚拟继承

> 实际中我们不建议设计出菱形继承及菱形虚拟继承，一方面太复杂容易出问题，另一方面这样的 模型，访问基类成员有一定得性能损耗。所以菱形继承、菱形虚拟继承我们的虚表我们就不看 了，一般我们也不需要研究清楚，因为实际中很少用。如果好奇心比较强的宝宝，可以去看下面 的两篇链接文章。
>
> 1. [C++ 虚函数表解析 | 酷 壳 - CoolShell](https://coolshell.cn/articles/12165.html)
> 2. [C++ 对象的内存布局 | 酷 壳 - CoolShell](https://coolshell.cn/articles/12176.html)

------

##### 相关试题

###### 概念考察

> 1. 下面哪种面向对象的方法可以让你变得富有( )  A: 继承 B: 封装 C: 多态 D: 抽象 
>
> 2. ( )是面向对象程序设计语言中的一种机制。这种机制实现了方法的定义与具体的对象无关， 而对方法的调用则可以关联于具体的对象。 A: 继承 B: 模板 C: 对象的自身引用 D: 动态绑定 
>
> 3.  面向对象设计中的继承和组合，下面说法错误的是？（） A：继承允许我们覆盖重写父类的实现细节，父类的实现对于子类是可见的，是一种静态复 用，也称为白盒复用 B：组合的对象不需要关心各自的实现细节，之间的关系是在运行时候才确定的，是一种动 态复用，也称为黑盒复用 C：优先使用继承，而不是组合，是面向对象设计的第二原则 D：继承可以使子类能自动继承父类的接口，但在设计模式中认为这是一种破坏了父类的封 装性的表现 
>
> 4. 以下关于纯虚函数的说法,正确的是( ) A：声明纯虚函数的类不能实例化对象 B：声明纯虚函数的类是虚基类 C：子类必须实现基类的纯虚函数 D：纯虚函数必须是空函数 
>
> 5. 关于虚函数的描述正确的是( ) A：派生类的虚函数与基类的虚函数具有不同的参数个数和类型 B：内联函数不能是虚函数 C：派生类必须重新定义基类的虚函数 D：虚函数可以是一个static型的函数  
>
> 6. 关于虚表说法正确的是（ ） A：一个类只能有一张虚表 B：基类中有虚函数，如果子类中没有重写基类的虚函数，此时子类与基类共用同一张虚表 C：虚表是在运行期间动态生成的 D：一个类的不同对象共享该类的虚表 
>
> 7. 假设A类中有虚函数，B继承自A，B重写A中的虚函数，也没有定义任何虚函数，则（ ） A：A类对象的前4个字节存储虚表地址，B类对象前4个字节不是虚表地址 B：A类对象和B类对象前4个字节存储的都是虚基表的地址 C：A类对象和B类对象前4个字节存储的虚表地址相同 D：A类和B类虚表中虚函数个数相同，但A类和B类使用的不是同一张虚表
>
> 8. 下面程序输出结果是什么? （）
>
>     ~~~C++
>     #include<iostream>
>     using namespace std;
>     class A{
>         public:
>         A(char *s) { cout<<s<<endl; }
>         ~A(){}
>     };
>     class B:virtual public A
>     {
>         public:
>         B(char *s1,char*s2):A(s1) { cout<<s2<<endl; }
>     };
>     class C:virtual public A
>     {
>         public:
>         C(char *s1,char*s2):A(s1) { cout<<s2<<endl; }
>     };
>     class D:public B,public C
>     {
>         public:
>         D(char *s1,char *s2,char *s3,char *s4):B(s1,s2),C(s1,s3),A(s1)
>         { cout<<s4<<endl;}
>     };
>     int main() {
>         D *p=new D("class A","class B","class C","class D");
>         delete p;
>         return 0;
>     }
>
>     ~~~
>
>     A：class A class B class C class D B：class D class B class C class A C：class D class C class B class A D：class A class C class B class D 
>
> 9. 多继承中指针偏移问题？下面说法正确的是( )
>
>     ~~~C++
>     class Base1 {  public:  int _b1; };
>     class Base2 {  public:  int _b2; };
>     class Derive : public Base1, public Base2 { public: int _d; };
>     int main(){
>         Derive d;
>         Base1* p1 = &d;
>         Base2* p2 = &d;
>         Derive* p3 = &d;
>         return 0;
>     }
>                             
>     ~~~
>
>     A：p1 == p2 == p3 B：p1 < p2 < p3 C：p1 == p3 != p2 D：p1 != p2 != p3
>
>
> 10. **以下程序输出结果是什么（）**
>
>     ~~~C++
>     class A
>     {
>         public:
>         virtual void func(int val = 1){ std::cout<<"A->"<< val <<std::endl;}
>         virtual void test(){ func();}
>     };
>                             
>     class B : public A
>     {
>         public:
>         void func(int val=0){ std::cout<<"B->"<< val <<std::endl; }
>     };
>                             
>     int main(int argc ,char* argv[])
>     {
>         B*p = new B;
>         p->test();
>         return 0;
>     }
>     //仅重写方法体
>     ~~~
>     
>     A: A->0 B: B->1 C: A->1 D: B->0 E: 编译出错 F: 以上都不正确
>
> ~~~C++
> 参考答案：
>    1. A   2. D   3. C   4. A   5. B
>    6. D   7. D   8. A   9. C   10. B
> ~~~
>
> 

###### 问答题

> 1. 什么是多态？答：参考本节课件内容 
> 2. 什么是重载、重写(覆盖)、重定义(隐藏)？答：参考本节课件内容
> 3. 多态的实现原理？答：参考本节课件内容 
> 4. inline函数可以是虚函数吗？答：可以，不过编译器就忽略inline属性，这个函数就不再是 inline，因为虚函数要放到虚表中去。
> 5. 静态成员可以是虚函数吗？答：不能，因为静态成员函数没有this指针，使用类型::成员函数 的调用方式无法访问虚函数表，所以静态成员函数无法放进虚函数表。 
> 6. 构造函数可以是虚函数吗？答：不能，因为对象中的虚函数表指针是在构造函数初始化列表 阶段才初始化的。 
> 7. 析构函数可以是虚函数吗？什么场景下析构函数是虚函数？答：可以，并且最好把基类的析 构函数定义成虚函数。参考本节课件内容 
> 8. 对象访问普通函数快还是虚函数更快？答：首先如果是普通对象，是一样快的。如果是指针 对象或者是引用对象，则调用的普通函数快，因为构成多态，运行时调用虚函数需要到虚函 数表中去查找。 
> 9. 虚函数表是在什么阶段生成的，存在哪的？答：虚函数表是在编译阶段就生成的，一般情况 下存在代码段(常量区)的。 
> 10. C++菱形继承的问题？虚继承的原理？答：参考继承课件。注意这里不要把虚函数表和虚基 表搞混了。 
> 11. 什么是抽象类？抽象类的作用？答：参考（3.抽象类）。抽象类强制重写了虚函数，另外抽 象类体现出了接口继承关系。

