

------

[TOC]

### 基础语法

##### 命名空间

- 在C/C++中，变量、函数和类都是大量存在的，这些变量、函数和类的名称若都存在于全局/局部作用域中，可能会导致很多冲突。使用命名空间的目的是对标识符的名称进行本地化，存放在各个不同的域中，以避免命名冲突或名字污染，**namespace**关键字的出现就是针对这种问题的。


- 定义命名空间，需要使用到**namespace**关键字，后面跟命名空间的名字，然后接一对{}即可，{}中即为命名空间的成员。

###### 命名空间定义

1. 定义命名空间

```c++
namespace N1 // N1为命名空间的名称
{}
```

2. 命名空间可嵌套

```c++
namespace N1
{
	int a;
 int b;
 namespace N2
 {
     int c;
     int d;
	}
}
```

3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。

```
// ps：一个工程中的test.h和上面test.cpp中两个N1会被合并成一个
```

> **注意：一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中**

###### 命名空间使用

- ```
  加命名空间名称及作用域限定符 N::a//每次使用都要限定, 推荐

- ~~~
  使用using将命名空间中成员引入 using N::a//只取出a, 推荐
  ~~~
  
- ~~~
  使用using namespace 命名空间名称引入 using namespace N//全部取出, OJ时推荐




------



##### 缺省参数

> **缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实参则采用该 形参的缺省值，否则使用指定的实参。**
>
> ```C++
> void fun(int a = 10)
> {
>        cout << a * a << endl;
> }
> 
> int main()
> {
>        fun();//不传参, 此时形参a默认为10
>        fun(1);//传参, 指定实参
>     
>        return 0;
> }
> ```
>

###### 分类

- 全缺省

```c++
void fun(int a = 10, int b = 20, int c = 30)
{
     cout << "a = " << a << endl;
     cout << "b = " << b << endl;
     cout << "c = " << c << endl;
}
```

- 半缺省

~~~c++
void fun(int a, int b, int c = 30)
{
     cout << "a = " << a << endl;
     cout << "b = " << b << endl;
     cout << "c = " << c << endl;
}

~~~

###### 注意事项

1. 半缺省参数必须从右往左依次来给出，不能间隔着给  

```c++
//err
void fun(int a = 10, int b, int c = 30)
{}
//必须从右至左

//在传参时,从左至右依次给形参赋值
```

2. 缺省参数不能在函数声明和定义中同时出现

```C++
//原因

// a.h
void fun(int a = 10);
// a.cpp
void fun(int a = 20)
{}
// vs2019测试报错：fun重定义默认参数 
```

3. 缺省值必须是常量或者全局变量

```c++
//err

int i = 0;//局部变量
void fun(int a, int b = i, int c = 30)
```

4. C语言不支持（编译器不支持）

------

##### 函数重载

>  函数重载：是函数的一种特殊情况，C++允许在**同一作用域中**声明几个功能类似的**同名函数**，这些 同名函数 的**形参列表(参数个数 或 类型 或 类型顺序)不同**，常用来处理实现功能类似数据类型不同的问题。

###### 实现形式

- 同一作用域

- 函数名相同

- 形参列表不同

- 和返回类型无关

```C++
//参数类型不同，参数顺序不同，参数个数不同
int add(int a, int b);
double add(double a, double b);//a-类型不同
int add(int a, int b, int c);//a-个数不同
void add(int a, char b);
void add(char b, int a);//c-顺序不同
```

###### 为什么C++支持函数重载, 而C不支持

> **C++在编译阶段会对函数进行名字修饰, 通常以某种规则对函数 + 形参类型 进行转换作为函数的新名字**

- 首先, 明确C++源码到程序的四个阶段: 预处理, 编译, 汇编, 链接
- 在**编译阶段**, C++编译器会对函数进行**名字修饰**, 以某种方式将函数名转化为符合语法的**新名字**, 如以 函数名+形参类型 进行转化, 则 `fun(int, int)` 和`fun(int, double)` 转化后 为 `fii`和`fid`, 两个函数的名字就有了区分, 函数名和地址会一起存放在符号表中.
-  在**链接阶段**, 若是同文件的函数调用, 在编译阶段就会CALL, 而不同文件的函数调用, 需要用**函数名**去文件的**符号表查函数对应的地址**. C++的函数经过转换, 同名函数可以区分. 而C就无法进行区分, 报错

###### extern "C"

- 有时候在C++工程中可能需要将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，将该函数按照C语言规则来编译。

- C++调用C库，需要引用头文件时extern "C",告诉编译器,以C语言的方式在该头文件寻找函数/变量

- C调用C++库，需要 条件编译 + extern "C" h文件
    - 条件编译: 编译时,文件 按 C语言规则编译制表

     - extern "C": 按照C语言标准查找函数

 


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

1. 定义

    ```
    //类型& 引用变量名(对象名) = 引用实体；
    void TestRef()
    {
         int a = 10;
         int& ra = a;//引用类型
         printf("%p\n", &a);
         printf("%p\n", &ra);
    }

    void test()
    {
        int a = 10;
        int& ra = a;
        const int b = 10;
        const int& crb = b;
    }
    ```

2. 做参数

    ```c++
    //相当于实参传指针(传址), 修改形参的值也会修改实参的值, 并且不会进行拷贝实参生成形参操作
    void fun(int a, int& b)
    {
        a =  10;
        b = 10;
    }

    int main()
    {
        int a = 1, b = 1;
        fun(a, b);
        cout << a << ' ' << b << endl;
        //1, 10
    }
    ```

3. 做返回值

    ```c++
    //返回值类型若为引用类型, 此时编译器不会拷贝返回值,则要求在函数结束时, 返回值的生命周期还在, 即返回值不能随函数结束而回收, 否则会发生内存泄漏
    
    int& fun()
    {
        static int a = 10;//全局域, 文件内而访问
        int b = 10;//局部变量, 随函数结束而释放
    
        return b;//内存泄漏
        //return a;//
    }
    
    int main()
    { 
        int val = fun();
        //接受到某个变量的引用, fun()结束时, b所在的空间已被释放, 造成内存泄漏
    
        return 0;
    }
    ```



###### 注意事项

1. 引用特性
    - 引用在定义时必须初始化
    - 一个变量可以有多个引用
    - 一个引用在定义后就无法更改

2. 引用和指针的区别
    - 引用在定义时必须初始化，指针没有要求
    - 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型
    - 没有NULL引用，但有NULL指针
    - 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占4个字节)(数组和申请堆空间除外)
    - 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
    - 有多级指针，但是没有多级引用
    - 访问实体方式不同，指针需要显式解引用，引用编译器自己处理
    - 引用比指针使用起来相对更安全

> **引用的底层实现是用指针实现的**

------



##### 内联函数--建议性关键字

> **以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数调用建立栈帧 的开销，内联函数提升程序运行的效率。**

###### 简单了解

![image-20221002203826494](%E5%9B%BE%E7%89%87/README/image-20221002203826494.png)

![image-20221002204552313](%E5%9B%BE%E7%89%87/README/image-20221002204552313.png)

如果在上述函数前增加inline关键字将其改成内联函数，在编译期间编译器会用函数体替换函数的调用。 

**查看方式：**

1. 在release模式下，查看编译器生成的汇编代码中是否存在call Add 

2. 在debug模式下，需要对编译器进行设置，否则不会展开(因为debug模式下，编译器默认不会对代码进 行优化，以下给出vs2013的设置方式)

![image-20221002204514881](%E5%9B%BE%E7%89%87/README/image-20221002204514881.png)



###### 特性

- inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环/递归的函数不适宜使用作为内联函数。
- inline对于编译器而言**只是一个建议**，编译器会自动优化，如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
- inline**不建议声明和定义分离**，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。(.cpp文件调用函数->通过.h文件的函数声明找出地址->call地址, 但inline展开后, 不会进符号表, 即没有这个函数了, call不到)

------



##### 面试问题

###### 宏的优缺点？ 

优点： 

1. 增强代码的复用性
2. 提高性能。

缺点： 

1. 不方便调试宏。（因为预编译阶段进行了替换） 
2. 导致代码可读性差，可维护性差，容易误用。
3. 没有类型安全的检查 。

###### C++有哪些技术替代宏？

1. 常量定义 换用const enum
2. 短小函数定义 换用内联函数

###### 宏和define的区别

![1658315233880](%E5%9B%BE%E7%89%87/README/1658315233880.png)



##### extern & static

> ```
> extern 声明的全局变量， 写入符号表， 整个项目就一个
> static 修饰的变量，不写入符号表，仅当前文件可见可用
> ```
>

------



##### auto--自动推导变量类型

> auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，**auto声明的变量必须由编译器在编译时期推导而得。**
>
> 使用auto定义变量时必须对其**进行初始化**，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。因此auto**并非是一种“类型”的声明**，而是一个类型**声明时的“占位符”**，编译器在编译期会将auto**替换为变量实际的类型**。
>

###### 使用细则

1. auto与指针和引用结合起来使用, 用auto声明指针类型时，用auto和auto*没有任何区别，但用**auto声明引用类型时则必须加&**

    ```c++
    int main()
    {
        int x = 10;

        auto a = &x;//指针
        auto* b = &x;//指针
        auto& c = x;//引用

        return 0;
    }
    ```

2. 在同一行定义多个变量, 当在同一行声明多个变量时，这些变量**必须是相同的类型**，否则编译器将会报错，因为编译器实际只对第一个类型进行推导，然后用推导出来的类型定义其他变量.

    ```c++
    void TestAuto()
    {
        auto a = 1, b = 2; 
        auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
    }
    ```



###### auto不能推导的场景

-  auto不能**作为函数的参数**

    ```c++
    // 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
    void TestAuto(auto a)
    {}
    ```

- auto不能直接用来**声明数组**

    ```c++
    void TestAuto()
    {
        int a[] = {1,2,3};
        auto b[] = {4，5，6};
    }
    ```

- 为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法

- auto在实际中最常见的优势用法就是跟C++11提供的新式for循环，还有lambda表达式等进行配合使用。



#####  基于范围的for循环(C++11)

###### 范围for的语法

在C++98中如果要遍历一个数组，可以按照以下方式进行：

```C++
void TestFor()
{
 int array[] = { 1, 2, 3, 4, 5 };
 for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
     array[i] *= 2;

 for (int* p = array; p < array + sizeof(array)/ sizeof(array[0]); ++p)
     cout << *p << endl;
}
```

对于一个**有范围的集合**而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。

因此C++11中 引入了基于范围的for循环。for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量， 第二部分则表示被迭代的范围。

```C++
void TestFor()
{
  int array[] = { 1, 2, 3, 4, 5 };
  for(auto& e : array)
  e *= 2;

  for(auto e : array)
  cout << e << " ";

  return 0;
}
```

> 范围for的实现基于底层逻辑的迭代器，支持++的顺序迭代器
>
> c++11后关于迭代的变量的玩法非常炫酷

###### 使用条件

**范围for强调有范围的集合**: 对于数组而言，就是数组中第一个元素和最后一个元素的范围；对于类而言，应该提供begin和end的 方法，begin和end就是for循环迭代的范围。

~~~C++
void fun(int arr[])
{
 for(auto val : arr)//此时编译器不了解arr的范围
 {
     cout << val << ' ';
 }
}

int main()
{
 int arr[] = {1, 2, 3, 4};
 for(auto val : arr)//此时编译器了解arr的范围
 {
     cout << val << ' ';
 }

 fun(arr)//err

 return 0;
}
~~~

**迭代的对象要实现++和--的操作。**

------



##### nullptr

1. NULL为假空指针,实为 宏 (int)0, nullptr 为 真空指针
2. 在使用nullptr表示指针空值时，不需要包含头文件，因为nullptr是C++11作为新关键字引入的。
3. 在C++11中，sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同。
4. 为了提高代码的健壮性，在后续表示指针空值时建议最好使用nullptr。

------



### 类和对象

> C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题。
>
> C++是基于面向对象的，关注的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成。
>

##### class关键字

class为定义类的关键字，ClassName为类的名字，{}中为类的主体，注意类定义结束时后面分号不能省略。

类体中内容称为类的成员：类中的变量称为类的属性或成员变量; 类中的函数称为类的方法或者成员函数。

```c++
class className
{
// 类体：由成员函数和成员变量组成

}; // 一定要注意后面的分号
```

**类的两种定义方式：**

1. 声明和定义全部放在类体中，需注意：成员函数如果在类中定义，编译器可能会将其当成内联函数处理。![image-20221003112234023](%E5%9B%BE%E7%89%87/README/image-20221003112234023.png)
2. 类声明放在.h文件中，成员函数定义放在.cpp文件中，注意：成员函数名前需要加类名::![image-20221003112255057](%E5%9B%BE%E7%89%87/README/image-20221003112255057.png)

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

![image-20221003113327586](%E5%9B%BE%E7%89%87/README/image-20221003113327586.png)

- public修饰的成员在类外可以直接被访问 
- protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
- 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止 
- **class的默认访问权限为private，struct为public(因为struct要兼容C)**
- **注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别**

###### 封装：

> 将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行 交互。

------



#####  类的作用域

类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员，需要使用 :: 作用域解析符 指明成员属于哪个类域

```c++
class Person
{
 public:
 void PrintPersonInfo();
 private:
 char _name[20];
 char _gender[3];
 int _age;
};
// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo()
{
	cout<<_name<<" "_gender<<" "<<_age<<endl;
}
```


------



##### 类的实例化

用类类型创建对象的过程，称为类的实例化 

1. 类只是一个模型一样的东西，限定了类有哪些成员，定义出一个类并没有分配实际的内存空间来存储它 
2. 一个类可以实例化出多个对象，实例化出的对象 占用实际的物理空间，存储类成员变量 
3. 做个比方。类实例化出对象就像现实中使用建筑设计图建造出房子，类就像是设计图，只设计出需要什 么东西，但是并没有实体的建筑存在，同样类也只是一个设计，实例化出的对象才能实际存储数据，占用物理空间  

------



##### 类对象内存大小

- 类成员函数存放在公共代码区，**不与成员变量存在同一区域，不算大小**
- 调用类成员函数，会在类作用域找函数，在编译时转换成call
- 无成员函数/变量的类，内存默认为1(需要分配空间获取地址)
- 结论：一个类的大小，实际就是该类中”成员变量”之和，当然也要进行内存对齐，注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类。

------



##### this指针

> C++编译器给每个**“非静态的成员函数“**增加了一个隐藏的指针参数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有成员变量的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编译器自动完成。
>

###### this指针的特性

1. this指针的**类型**：类类型* const
2. 只能在“成员函数”的**内部使用**
3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，**编译器**将对象地址作为实参传递给this形参。所以**对象中不存储this指针。**
4. this指针是**成员函数第一个隐含的指针形参**，一般情况由编译器通过ecx寄存器自动传递，不需要用户传递
5. this指针存在函数形参列表里, 可以通过强转变成空指针

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

**其特征如下：**

1. 函数名与类名相同。
2. 无返回值。
3. 对象实例化时**编译器自动调用对应的构造函数。**
4. 构造函数可以重载。
5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦用户显式定义编译器将不再生成。
6. **无参的构造函数**和**全缺省的构造函数**都称为默认构造函数，并且默**认构造函数只能有一个**。注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数

**注意：**

> C++11 中针对内置类型成员不初始化的缺陷，又打了补丁，即：内置类型成员变量在**类中声明时可以给默认值。**
>

**编译器默认构造函数：**

- 对内置类型不进行处理。
- 对自定义类型，调用自定义类型的默认构造参数



###### 析构函数:

>  与构造函数功能相反，析构函数不是完成对象的销毁，**局部对象销毁工作是由编译器完成的**。而对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。

**其特征如下：**

1. 析构函数名是在类名前加上字符 ~。
2. 无参数无返回值。
3. 一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
4. **对象生命周期结束时，C++编译系统系统自动调用析构函数。**

**编译器自动生成的析构函数:**

- 对内置类型不处理

- 会对自定类型成员调用它的析构函数

###### 拷贝构造函数:

> 只有单个形参，该形参是对**本类类型对象的引用**(一般常用const修饰)，在用已存在的同类型对象**创建新对象时**由编译器自动调用。

**其特征如下：**

1. **拷贝构造函数是构造函数的一个重载形式。**
2. 拷贝构造函数的参数只有一个且必须**使用引用传参**，使用传值方式会引发无穷递归调用。**//重点**
3. 若未显示定义，系统生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝我们叫做**浅拷贝**，或者值拷贝。//如果申请了堆空间,则对应的指针会指向同一块空间
4. 初始化赋值即int a = b; 会调用拷贝构造, 而不是赋值--**编译器优化**

###### 赋值运算符重载:

**运算符重载 :**

> C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
>

- 函数名字为：关键字operator后面接需要重载的运算符符号。
- 函数原型：返回值类型 operator操作符(参数列表)
- 注意:
    1. 不能通过连接其他符号来创建新的操作符：比如operator@ 
    2. **重载操作符必须有一个类类型或者枚举类型的操作数** 
    3. 用于内置类型的操作符，其含义不能改变，例如：内置的整型+，不 能改变其含义
    4. 作为类成员的重载函数时，其形参看起来比操作数数目少1, 因为成员函数的操作符有一个默认的形参this，限定为第一个形参
    5. .* 、:: 、sizeof 、?: 、. 注意**以上5个运算符不能重载**。这个经常在笔试选择题中出现。
    6. **赋值运算符在类中不显式实现时，编译器会生成一份默认的，此时用户在类外再将赋值运算符重载为全局的，就和编译器生成的默认赋值运算符冲突了，故赋值运算符只能重载成成员函数**

**赋值运算符重载:**

1. 赋值运算符重载格式

    - 参数类型: const T&，传递引用可以提高传参效率
    - 返回值: T&，返回引用可以提高返回的效率，有返回值目的是为了支持连续赋值
    - 检测是否自己给自己赋值
    - 返回*this: 要复合连续赋值的含义

2. **赋值运算符只能重载成类的成员函数不能重载成全局函数**

    ```c++
    class Date
    {
    public:
     Date(int year = 1900, int month = 1, int day = 1)
     {
     _year = year;
     _month = month;
     _day = day;
     }
     int _year;
     int _month;
     int _day;
    };
    // 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
    Date& operator=(Date& left, const Date& right)
    {
     if (&left != &right)
     {
     left._year = right._year;
     left._month = right._month;
     left._day = right._day;
     }
     return left;
    }
    // 编译失败：
    // error C2801: “operator =”必须是非静态成员
    ```

    **原因：**赋值运算符如果不显式实现，编译器会生成一个默认的。此时用户再在类外自己实现一个全局的 赋值运算符重载，就和编译器在类中生成的默认赋值运算符重载冲突了，故赋值运算符重载只能是类的 成员函数。

3. 一个类如果没有显式定义赋值运算符重载，编译器也会生成一个，完成对象**按字节序的值拷贝**

 **前置++和后置++重载:**

~~~C++
class Date
{
public:
 Date(int year = 1900, int month = 1, int day = 1)
 {
     _year = year;
     _month = month;
     _day = day;
 }
// 前置++：返回+1之后的结果
// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
 Date& operator++()
 {
     _day += 1;
     return *this;
 }
// 后置++：
// 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传
递
// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存一份，
然后给this+1
// 而temp是临时对象，因此只能以值的方式返回，不能返回引用
 Date operator++(int)
{
 Date temp(*this);
 _day += 1;
 return temp;
}
private:
 int _year;
 int _month;
 int _day;
};
int main()
{
 Date d;
 Date d1(2022, 1, 13);
 d = d1++; // d: 2022,1,13 d1:2022,1,14
 d = ++d1; // d: 2022,1,15 d1:2022,1,15
 return 0;
}
~~~

######  取地址及const取地址操作符重载

> 这两个运算符一般不需要重载，使用编译器生成的默认取地址的重载即可，只有特殊情况，才需要重载，比如想让别人获取到指定的内容！

###### const成员

> 将const修饰的类成员函数称之为const成员函数，const修饰类成员函数，**实际修饰该成员函数隐含的this 指针**，表明在该成员函数中不能对类的任何成员进行修改。

**形式:**

> ```
> typeReturn name(typeElem ) const
> ```

------



##### 详解C++_const



------



##### 匿名对象

> 匿名对象生命周期只有一行, 若被const引用, 则其生命周期会延长
>

形式:

```c++
className(2022, 10, 2)//没有对象名,生命周期为一行
```

------



#####   初始化列表

###### 构造函数内赋值

> 在创建对象时，编译器通过调用构造函数，给对象中各个成员变量一个合适的初始值。
>

~~~c++
class Date
{
public:
 Date(int year, int month, int day)
 {
     _year = year;
     _month = month;
     _day = day;
 }
private:
 int _year;
 int _month;
 int _day;
};

~~~

虽然上述构造函数调用之后，对象中已经有了一个初始值，但是不能将其称为对对象中成员变量的初始化， **构造函数体中的语句只能将其称为赋初值，而不能称作初始化**。因为初始化只能初始化一次，而构造函数体内可以多次赋值。

######  初始化列表

> 初始化列表：以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括 号中的初始值或表达式。
>

~~~C++
ClassName (int a, int b, int c, ClassName1 cn1)
	: _a(a)
	, _b(b)
	, _c(c)
	, _cn1(cn1)
	{
		///	
	}
~~~

**注意:**

1. 每个成员变量在初始化列表中**只能出现一次**(初始化只能初始化一次) 
2.  **类中包含以下成员，必须放在初始化列表位置进行初始化：**
    - 引用成员变量
    - const成员变量
    - 自定义类型成员(且该类没有默认构造函数时)
3. 尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，一定会先使 用初始化列表初始化
4. 成员变量在类中**声明次序就是其在初始化列表中的初始化顺序**，与其在初始化列表中的先后次序无关

#####  explicit关键字

> 构造函数不仅可以构造与初始化对象，对于单个参数或者除第一个参数无默认值其余均有默认值的构造函数，还具有类型转换的作用。
>

~~~C++
class Date
{
public:
 // 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
 // explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
 explicit Date(int year)
     :_year(year)
     {}
 /*
// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
// explicit修饰构造函数，禁止类型转换
explicit Date(int year, int month = 1, int day = 1)
: _year(year)
, _month(month)
, _day(day)
{}
*/
 Date& operator=(const Date& d)
 {
     if (this != &d)
     {
         _year = d._year;
         _month = d._month;
         _day = d._day;
     }
     return *this;
 }
private:
 int _year;
 int _month;
 int _day;
};
void Test()
{
 Date d1(2022);
 // 用一个整形变量给日期类型对象赋值
 // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
 d1 = 2023;
 // 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
}
~~~

> 用explicit修饰构造函数，将会禁止构造函数的隐式转换。 

------



##### 静态类成员:

> 声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；
>
> 用static修饰的成员函数，称之为静态成员函数。**静态成员变量一定要在类外进行初始化**

**特性:**

- 静态成员为所有类对象所共享，不属于某个具体的对象，存放在静态区
- 静态成员变量必须在类外定义，定义时不添加static关键字，类中只是声明
- 类静态成员可用 类名::静态成员 或者 对象.静态成员 来访问
- **静态成员函数没有隐藏的this指针**，不能访问任何非静态成员, 只能访问静态成员变量
- 静态成员也是类的成员，受public、protected、private 访问限定符的限制

**面试题:**

1. 实现一个类，计算程序中创建出了多少个类对象。

~~~C++
class A
{
    public:
    A() { ++_scount; }
    A(const A& t) { ++_scount; }
    ~A() { --_scount; }
    static int GetACount() { return _scount; }
    private:
    static int _scount;
};
int A::_scount = 0;
void TestA()
{
    cout << A::GetACount() << endl;
    A a1, a2;
    A a3(a1);
    cout << A::GetACount() << endl;
}
~~~

2. 静态成员函数可以调用非静态成员函数吗？
3. 非静态成员函数可以调用类的静态成员函数吗？

------



##### 友元:

>  友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多 用。 
>
> 友元分为：友元函数和友元类 

###### 友元函数:

> **问题：**现在尝试去重载operator<<，然后发现没办法将operator<<重载成成员函数。因为cout的输出流对象和隐含的this指针在抢占第一个参数的位置。this指针默认是第一个参数也就是左操作数了。但是实际使用 中cout需要是第一个形参对象，才能正常使用。所以要将operator<<重载成全局函数。但又会导致类外没办 法访问成员，此时就需要友元来解决。operator>>同理。

~~~C++
class Date
{
 public:
 Date(int year, int month, int day)
     : _year(year)
         , _month(month)
         , _day(day)
     {}
 // d1 << cout; -> d1.operator<<(&d1, cout); 不符合常规调用
 // 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
 ostream& operator<<(ostream& _cout)
 {
     _cout << _year << "-" << _month << "-" << _day << endl;
     return _cout;
 }
 private:
 int _year;
 int _month;
 int _day;
};
~~~

> 友元函数可以**直接访问类的私有成员**，它是定义在类外部的普通函数，**不属于任何类**，但需要在类的内部声 明，声明时需要加friend关键字。
>

~~~C++
class Date
{
 friend ostream& operator<<(ostream& _cout, const Date& d);
 friend istream& operator>>(istream& _cin, Date& d);
 public:
 Date(int year = 1900, int month = 1, int day = 1)
     : _year(year)
         , _month(month)
         , _day(day)
     {}
 private:
 int _year;
 int _month;
 int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
 _cout << d._year << "-" << d._month << "-" << d._day;
 return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
 _cin >> d._year;
 _cin >> d._month;
 _cin >> d._day;
 return _cin;
}
int main()
{
 Date d;
 cin >> d;
 cout << d << endl;
 return 0;
}
~~~

**特性:**

- 友元函数可访问类的私有和保护成员，但不是类的成员函数 
- 友元函数不能用const修饰 
- 友元函数可以在类定义的任何地方声明，不受类访问限定符限制 
- 一个函数可以是多个类的友元函数 
- 友元函数的调用与普通函数的调用原理相同



###### 友元类

**特性:**

- 友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。 

- 友元关系是单向的，不具有交换性。 

    > 比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time 类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。 

- 友元关系不能传递 如果B是A的友元，C是B的友元，则不能说明C时A的友元。 

- 友元关系不能继承。

```c++
class Time
{
    friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成
    员变量
        public:
    Time(int hour = 0, int minute = 0, int second = 0)
        : _hour(hour)
            , _minute(minute)
            , _second(second)
        {}

    private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
    public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
            , _month(month)
            , _day(day)
        {}

    void SetTimeOfDate(int hour, int minute, int second)
    {
        // 直接访问时间类私有的成员变量
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

    private:
    int _year;
    int _month;
    int _day;
    Time _t;
};
```




------



##### 内部类:

> 如果一个类定义在另一个类的内部，这个内部类就叫做内部类。内部类是一个独立的类，它不属于外部类，更不能通过外部类的对象去访问内部类的成员。外部类对内部类没有任何优越的访问权限。
>

**注意：**

**内部类就是外部类的友元类**，参见友元类的定义，内部类可以通过外部类的对象参数来访问外部类中 的所有成员。但是外部类不是内部类的友元。  

**特性：** 
 1. 内部类可以定义在外部类的public、protected、private都是可以的, 受访问限制符和外部类类域。 
 2. 注意内部类可以直接访问外部类中的static成员，不需要外部类的对象/类名。 
 3. **sizeof(外部类)=外部类**，和内部类没有任何关系。 

~~~c++
class A
{
   private:
   static int k;
   int h;
   public:
   class B // B天生就是A的友元
   {
       public:
       void foo(const A& a)
       {
           cout << k << endl;//OK
           cout << a.h << endl;//OK
       }
   };
};
int A::k = 1;
int main()
{
   A::B b;
   b.foo(A());

   return 0;
}
~~~




------

##### 小知识

> ```
> Class w{...};
> 匿名类:
> w(val); //生命周期为一行
> 
> 
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

~~~C++
int globalVar = 1;
static int staticGlobalVar = 1;
void Test()
{
 static int staticVar = 1;
 int localVar = 1;
 int num1[10] = { 1, 2, 3, 4 };
 char char2[] = "abcd";
 const char* pChar3 = "abcd";
 int* ptr1 = (int*)malloc(sizeof(int) * 4);
 int* ptr2 = (int*)calloc(4, sizeof(int));
 int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
 free(ptr1);
 free(ptr3);
}
1. 选择题：
    选项: A.栈  B.堆  C.数据段(静态区)  D.代码段(常量区)
        globalVar在哪里？____   staticGlobalVar在哪里？____
        staticVar在哪里？____   localVar在哪里？____
        num1 在哪里？____

        char2在哪里？____   *char2在哪里？___
        pChar3在哪里？____      *pChar3在哪里？____
        ptr1在哪里？____        *ptr1在哪里？____
2. 填空题：
        sizeof(num1) = ____; sizeof(char2) = ____;            	   strlen(char2) = ____;sizeof(pChar3) = ____;     			strlen(pChar3) = ____;sizeof(ptr1) = ____;
3. sizeof 和 strlen 区别？
~~~

![image-20221003144506575](%E5%9B%BE%E7%89%87/README/image-20221003144506575.png)

**说明:**

1. **栈又叫堆栈**--非静态局部变量/函数参数/返回值等等，栈是向下增长的。 
2. **内存映射段**是高效的I/O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口 创建共享共享内存，做进程间通信。（Linux课程如果没学到这块，现在只需要了解一下） 
3. **堆**用于程序运行时动态内存分配，堆是可以上增长的。 
4. **数据段**--存储全局数据和静态数据。 
5. **代码段**--可执行的代码/只读常量。





------

##### C语言中动态内存管理方式：malloc/calloc/realloc/free

~~~C++
void Test ()
{
int* p1 = (int*) malloc(sizeof(int));
free(p1);
// 1.malloc/calloc/realloc的区别是什么？
int* p2 = (int*)calloc(4, sizeof (int));
int* p3 = (int*)realloc(p2, sizeof(int)*10);
// 这里需要free(p2)吗？
free(p3 );
}
~~~

**面试题:**

1. malloc/calloc/realloc的区别？

    ~~~
    relloc第一个参数为空指针时, 相当于malloc, 需要包含stdlib.h头文件
    ~~~

2. malloc的实现原理？ [glibc中malloc实现原理](https://www.bilibili.com/video/BV117411w7o2/?spm_id_from=333.788.videocard.0)

3. ![image-20221031133601791](%E5%9B%BE%E7%89%87/README/image-20221031133601791.png)

##### C++动态内存管理方式: new/delete

> C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力，而且使用起来比较麻烦，因 此C++又提出了自己的内存管理方式：通过**new和delete**操作符进行动态内存管理。
>

1. 内置类型

    ~~~C++
    和C语言没本质区别, 只是简化了语句
    ---------申请new:
    int *p1 = new int;//申请大小为int的空间
    int *p2 = new int[5];//申请大小为 int * 5 的空间
    int *p3 = new int(5);//初始化
    int *p4 = new int[5]{1, 2, 3};//c++11支持, 98不支持
    -----------释放delete:
    delete p1;//
    delete[] p2;//释放连续空间, 需要对应
    delete p3;
    delete[] p4;
    ----------------
    如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是： new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申请空间失败时会抛异常，malloc会返回NULL。
    ~~~

2. 自定义类型

    ~~~C++
    申请new:
    new不仅会申请堆空间, 还会进行初始化(调用构造函数)
    释放delete:
    delete释放空间, 并且会调用析构函数
    ~~~

3. 失败处理

    ~~~C++
    malloc失败会返回(int)0
    new失败会抛出异常错误
    ~~~

4. 原理

    ~~~C++
    ---new的原理
    1. 调用operator new函数申请空间
    2. 在申请的空间上执行构造函数，完成对象的构造
    ---delete的原理
    1. 在空间上执行析构函数，完成对象中资源的清理工作
    2. 调用operator delete函数释放对象的空间
    ---new T[N]的原理//////注意
    1. 调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
    2. 在申请的空间上执行N次构造函数
    ---delete[]的原理
    1. 在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理
    2. 调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间
    ~~~

    - 对于内置类型, new[]申请的空间, 可以用delete释放, 不会报错, 但不建议这样做
    - 对于自置类型, new[]申请的空间, 必须用delete[]释放, 否则会运行失败

#####  operator new与operator delete函数:

> new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是系统提供的全局函数，**new在底层调用operator new全局函数来申请空间，delete在底层通过operator delete全局函数来释放空间。**
>

~~~C++
/*
operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
失败，尝试执行空               间不足应对措施，如果改应对措施用户设置了，则继续申请，否
则抛异常。
*/
void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
{
 // try to allocate size bytes
 void *p;
 while ((p = malloc(size)) == 0)
     if (_callnewh(size) == 0)
     {
         // report no memory
         // 如果申请内存失败了，这里会抛出bad_alloc 类型异常
         static const std::bad_alloc nomem;
         _RAISE(nomem);
     }
 return (p);
}
/*
operator delete: 该函数最终是通过free来释放空间的
*/
void operator delete(void *pUserData)
{
 _CrtMemBlockHeader * pHead;
 RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
 if (pUserData == NULL)
     return;
 _mlock(_HEAP_LOCK);  /* block other threads */
 __TRY
     /* get a pointer to memory block header */
     pHead = pHdr(pUserData);
 /* verify block type */
 _ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
 _free_dbg( pUserData, pHead->nBlockUse );
 __FINALLY
     _munlock(_HEAP_LOCK);  /* release other threads */
 __END_TRY_FINALLY
     return;
}
/*
free的实现
*/
#define   free(p)               _free_dbg(p, _NORMAL_BLOCK)
~~~

通过上述两个全局函数的实现知道，operator new 实际也是通过malloc来申请空间，如果 malloc申请空间成功就直接返回，否则执行用户提供的空间不足应对措施，如果用户提供该措施 就继续申请，否则就抛异常。operator delete 最终是通过free来释放空间的。

**重载operator new与operator delete:**

```
一般情况下不需要对 operator new 和 operator delete进行重载，除非在申请和释放空间 时候有某些特殊的需求。比如：在使用new和delete申请和释放空间时，打印一些日志信息，可 以简单帮助用户来检测是否存在内存泄漏。 
```



##### 只允许在堆或栈上创建对象

> [(12条消息) C++ 如何让类对象只在堆或栈上创建_stashblog的博客-CSDN博客_c++创建堆对象](https://blog.csdn.net/qq_30835655/article/details/68938861)
>
> [(12条消息) C++如何限制只能在堆或栈上创建对象？_sstinky的博客-CSDN博客](https://blog.csdn.net/sstinky/article/details/103718720)

##### 常见内存管理面试题:

1. malloc/free和new/delete的区别
    - malloc/free和new/delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。不同的地方是：
    - malloc和free是函数，new和delete是操作符
    - malloc申请的空间不会初始化，new可以初始化
    - malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可，如果是多个对象，[]中指定对象个数即可
    - malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
    - malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常
    - 申请自定义类型对象时，malloc/free只会开辟空间，不会调用构造函数与析构函数，而new在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成空间中资源的清理

2. 内存泄漏

    - 什么是内存泄漏，内存泄漏的危害
        ~~~c++
        什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况，野指针问题也属于内存泄漏。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。
        内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死。
        ~~~

        

    - 内存泄漏分类（了解）
        ~~~
        C/C++程序中一般我们关心两种方面的内存泄漏：
        堆内存泄漏(Heap leak):
        堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak。
        系统资源泄漏:
        指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定
        ~~~

        

    - 如何检测内存泄漏（了解）
        ~~~
        在vs下，可以使用windows操作系统提供的_CrtDumpMemoryLeaks() 函数进行简单检测，该函数只报出了大概泄漏了多少个字节，没有其他更准确的位置信息。
        因此写代码时一定要小心，尤其是动态内存操作时，一定要记着释放。但有些情况下总是防不胜防，简单的可以采用上述方式快速定位下。如果工程比较大，内存泄漏位置比较多，不太好查时一般都是借助第三方内存泄漏检测工具处理的。
        在linux下内存泄漏检测：linux下几款内存泄漏检测工具
        在windows下使用第三方工具：VLD工具说明
        其他工具：内存泄漏工具比较
        ~~~

        

    - 如何避免内存泄漏

        - 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps：
            这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题。需要下一条智能指针来管理才有保证。
        - 采用RAII思想或者智能指针来管理资源。
        - 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项。
        - 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵。



3. 总结一下:

  内存泄漏非常常见，解决方案分为两种：

```
  1、事前预防型。如智能指针等。
  2、事后查错型。如泄漏检测工具
```



------



### 泛型编程

#### 泛型编程:

##### 初识泛型思想

如何实现一个通用的交换函数呢？

~~~C++
void Swap(int& left, int& right)
{
 int temp = left;
 left = right;
 right = temp;
}
void Swap(double& left, double& right)
{
 double temp = left;
 left = right;
 right = temp;
}
void Swap(char& left, char& right)
{
 char temp = left;
 left = right;
 right = temp;
}
......

~~~

使用函数重载虽然可以实现，但是有一下几个不好的地方： 

1. 重载的函数仅仅是类型不同，代码**复用率比较低**，只要有新类型出现时，就需要用户自己增加对应的函数 

2. 代码的可**维护性比较低**，一个出错可能所有的重载均出错 

**那能否告诉编译器一个模子，让编译器根据不同的类型利用该模子来生成代码呢？**

在C++中，存在这样一个模具，通过给这个模具中填充类型，生成具体类型的代码，那将会节省许多头发。这就是泛型编程。

> **泛型编程：**编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础。

![image-20221003163649554](%E5%9B%BE%E7%89%87/README/image-20221003163649554.png)




------



##### 函数模板:

> 函数模板代表了一个函数家族，该函数模板与类型无关，在**使用时被参数化**，根据实参类型产生函数的特定 类型版本。

###### 格式

```c++
关键字: template, typename
格式: template<typename 模板类型名字>
eg: 
	template<typename T>
	void Swap(T& left, T& rig)
	{
		T temp = left;
		left = rig;
		rig = tmep;
	}
//一个模板类型列表和一个函数模板严格地一一对应
```

###### 原理

- 函数模板是一个蓝图，它**本身并不是函数**，是编译器用来产生特定具体类型函数的模具。所以其实模板就是将本来应该我们做的重复的事情交给了编译器

- 在**编译器编译阶段**，对于模板函数的使用，编译器需要根据传入的实参类型来推演生成对应类型的函数以供调用。

- 比如：当用double类型使用函数模板时，编译器通过对实参类型的推演，将T确定为double类型，然后产生一份专门处理double类型的代码，对于字符类型也是如此--推断在传参前。

------

###### 函数模板的实例化

> 用不同类型的参数使用函数模板时，称为函数模板的实例化。模板参数实例化分为：隐式实例化和显式实例化。
>

1. 隐式实例化：让编译器根据实参推演模板参数的实际类型

    ~~~C++
    template<class T>
    T Add(const T& left, const T& right)
    {
        return left + right;
    }
    int main()
    {
        int a1 = 10, a2 = 20;
        double d1 = 10.0, d2 = 20.0;
        Add(a1, a2);
        Add(d1, d2);

        /*
     该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
     通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
     编译器无法确定此处到底该将T确定为int 或者 double类型而报错
     注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
     Add(a1, d1);
     */

        // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
        Add(a, (int)d);
    	return 0;
    }
    ~~~

2. 显式实例化：在函数名后的<>中指定模板参数的实际类型

    ~~~C++
    int main(void)
    {
        int a = 10;
        double b = 20.0;
    
        // 显式实例化
        Add<int>(a, b);
        return 0;
    }
    ~~~

    > **如果类型不匹配，编译器会尝试进行隐式类型转换，如果无法转换成功编译器将会报错。**

##### 模板参数的匹配原则

1. **一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函 数**

    ~~~c++
    // 专门处理int的加法函数
    int Add(int left, int right)
    {
        return left + right;
    }
    // 通用加法函数
    template<class T>
        T Add(T left, T right)
    {
        return left + right;
    }
    void Test()
    {
        Add(1, 2); // 与非模板函数匹配，编译器不需要特化
        Add<int>(1, 2); // 调用编译器特化的Add版本
    }

2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会**优先调用非模板函数**而不会从该模 板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板

    ~~~C++
    // 专门处理int的加法函数
    int Add(int left, int right)
    {
        return left + right;
    }
    // 通用加法函数
    template<class T1, class T2>
    T1 Add(T1 left, T2 right)
    {
        return left + right;
    }
    void Test()
    {
        Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
        Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
    }
    ~~~

3. 模板函数不允许自动类型转换，但普通函数可以进行自动类型转换

    ```
    模板中不允许使用auto
    typedef与模板，取决于编译顺序
    ```



##### 类模板:

###### 格式

```c++
template<class T1, class T2, ..., class Tn>
class 类模板名
{
// 类内成员定义--存在模板类型成员
}; 

```

1. 在类中使用模板类型, 就是类模板
2. 类模板都是**显示实例化**
3. 模板类**不支持分离编译**, 即声明和定义必须在同一个文件

###### 实例化

> 类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后**强制跟<>**，然后将实例化的类型放在<>中
>

~~~c++
// Vector类模板的名字，Vector<int>才是类
Vector<int> s1;
Vector<double> s2;
~~~



###### 注意注意注意注意注意注意注意注意注

1. 模板参数列表, 和其函数模板, 类模板是一一对应的

2. 类模板/函数模板 只是一种声明, 并不是定义, 由编译器在编译阶段推导出来的**模板函数/模板类才是定义**

3. **类模板实例化只会实例化需要的部分**，若存在未用到函数，则不会实例化改函数

------

##### 模板的特化

------

#### STL容器

##### string

###### 新思想

```
深拷贝原理
深拷贝现代写法
复用思想
初识原生迭代器
```

###### vs和g++下string结构的说明

```
注意：下述结构是在32位平台下进行验证，32位平台下指针占4个字节。
--vs下string的结构:
string总共占28个字节，内部结构稍微复杂一点，先是有一个联合体，联合体用来定义string中字符串的存储空间：当字符串长度小于16时，使用内部固定的字符数组来存放;当字符串长度大于等于16时，从堆上开辟空间.
这种设计也是有一定道理的，大多数情况下字符串的长度都小于16，那string对象创建好之后，内部已经有了16个字符数组的固定空间，不需要通过堆创建，效率高。 其次：还有一个size_t字段保存字符串长度，一个size_t字段保存从堆上开辟空间总的容量 最后：还有一个指针做一些其他事情。 故总共占16+4+4+4=28个字节。
--g++下string的结构 
G++下，string是通过写时拷贝实现的，string对象总共占4个字节，内部只包含了一个指针，该指 针将来指向一块堆空间，内部包含了如下字段： 
1. 空间总大小 
2. 字符串有效长度 
3. 引用计数
4. 指向堆空间的指针，用来存储字符串。
struct _Rep_base
{
	size_type _M_length; 
	size_type _M_capacity; 
	_Atomic_word _M_refcount; 
};
```

###### 浅拷贝/深拷贝/写时拷贝

```
--浅拷贝:
值拷贝, 仅仅按字节拷贝内容, 而不考虑实际[也称位拷贝，编译器只是将对象中的值拷贝过来。如果对象中管理资源，最后就会导致多个对象共 享同一份资源，当一个对象销毁时就会将该资源释放掉，而此时另一些对象不知道该资源已经被释放，以为 还有效，所以当继续对资源进项操作时，就会发生发生了访问违规。]
--深拷贝:
自写拷贝, 按真实逻辑拷贝内容, 比如申请到堆上的空间[如果一个类中涉及到资源的管理，其拷贝构造函数、赋值运算符重载以及析构函数必须要显式给出。一般情 况都是按照深拷贝方式提供。]
--写时拷贝:
延迟拷贝奇数, 当构造对象只进行读操作时, 和被拷贝对象共享空间, 当需要进行写操作时, 才进行拷贝[写时拷贝就是一种拖延症，是在浅拷贝的基础之上增加了引用计数的方式来实现的。 引用计数：用来记录资源使用者的个数。在构造时，将资源的计数给成1，每增加一个对象使用该资源，就给 计数增加1，当某个对象被销毁时，先给该计数减1，然后再检查是否需要释放资源，如果计数为1，说明该 对象时资源的最后一个使用者，将该资源释放；否则就不能释放，因为还有其他对象在使用该资源。]
```

###### 模拟实现

[String模拟实现参考](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/string%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/String.h)

```c++
#pragma once

#include<iostream>
#include<assert.h>
#include<string>
#include<algorithm>
using namespace std;

namespace qlz
{

	//命名空间的使用
	/*using std::cout;
	using std::cin;
	using std::endl;*/

	class string
	{

		typedef char* iterator;
		typedef const char* const_iterator;
	public:

		//swap，string的swap
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		//c指针，返回stringC语言下的指针
		const char* c_str() const
		{
			return _str;
		}
		 

		//无参
		// _str(nullptr) 错误: 转换成c指针 用cout输出的结束条件为 *p = '\0', 解引用了空指针
		// _str("\0") 错误: 常量字符串默认存在'\0'
		// 无参构造是应该是空字符串,即字符串只存在一个'\0'
		string()
			: _str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}

		//常量字符串
		string(const char* str)
		{
			size_t len = strlen(str);//strlen不包含\0
			_size = len;
			_capacity = len;
			_str = new char[len + 1];

			strcpy(_str, str);
		}

		////常量字符串全缺省默认构造
		//string(const char* str = "")
		//{
		//	size_t len = strlen(str);
		//	_size = len;
		//	_capacity = len;
		//	_str = new char[len + 1];
		//	
		//	strcpy(_str, str);//拷贝函数，遇到str的'\0'停止
		//}

		//常量字符串前n个字符
		string(const char* str, size_t n)
		{
			size_t len = strlen(str);
			len = len > n ? n : len;

			_size = _capacity = len;
			_str = new char[_capacity + 1];

			//strcpy 遇到\0结束, 不支持此前结束
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = str[i];
			}
			_str[_size] = '\0';

		}

		//n个字符ch
		string(size_t n, char ch)
			:_str(new char[n + 1])
			, _size(n)
			, _capacity(n)
		{
			for (size_t i = 0; i < _size; i++)
			{
				_str[i] = ch;
			}
			_str[_size] = '\0';
		}

		/*拷贝构造*/
		////传统写法
		//string(const string& str)
		//	:_str(new char[str._capacity + 1])
		//	, _size(str._size)
		//	, _capacity(str._capacity)
		//{
		//	//string对象可包含'\0', 而strcpy无法copy'\0'
		//	memcpy(_str, str._str, _capacity + 1);//按字节拷贝
		//}
		
		//现代写法
		//调用了c指针构造对象，然后交换内容
		string(const string& str)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(str._str);//C指针构造，不是拷贝构造
			swap(tmp);
		}

		//sting对象 第 pos位置的 后n个字符
		string(const string& str, size_t pos, size_t n = npos)
			
		{
			assert(pos < str._size);//合法下标
			*this = str.substr(pos, n);//调用赋值

			//*this += str.substr(pos, n);
			
			//错误语句
			// substr的返回值具有const属性, 无法修改, 不能作为swap的实参传递
			//swap(str.substr(pos, n));
		}  

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//reserve
		void reserve(size_t n)
		{
			if (n <= _size) return;

			char* tmp = new char[n + 1];

			memcpy(tmp, _str, _capacity + 1);

			delete[] _str;
			_str = tmp;
			tmp = nullptr;
			_capacity = n;
		}

		//resize
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (_size; _size < n; _size++)
				{
					_str[_size] = ch;
				}
				_str[_size] = '\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}

		//size
		size_t size() const
		{
			return _size;
		}

		//capacity
		size_t capacity() const
		{
			return _capacity;
		}

		//clear()
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//push_back
		void push_back(char ch)
		{
			//是否扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		//append
		void append(const char* str)
		{
			size_t len = strlen(str);

			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			strcpy(_str + _size, str);
			//strcat(_str + _size, str);

			_size += len;
		}
		void append(const string& str)
		{
			size_t len = str._size;

			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			memcpy(_str + _size, str._str, str._size + 1);

			_size += len;
		}

		//substr
		string substr(size_t pos, size_t len = npos) const
		{
			assert(pos < _size);//合法下标
			size_t realLen = len;
			//len = 1, 对应的是 提取pos位置的元素
			if (len == npos || pos + len > _size)
			{
				realLen = _size - pos;
			}

			string tmp;
			for (size_t i = 0; i < realLen; i++)
			{
				tmp += _str[pos + i];
			}

			return tmp;
		}

		//instert -- 引用返回值 可作为 右值或参数
		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			size_t end = ++_size;

			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;

			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);

			size_t len = strlen(str);

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;

			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str + pos, str, len);//不拷贝'\0', 只拷贝有效字符
			//memcpy(_str + pos, str, len);
			_size += len;

			return *this;
		}
		string& insert(size_t pos, const string& str)
		{
			assert(pos < _size);

			size_t len = str._size;

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + len;

			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}

			//strncpy(_str + pos, str._str, len);//不拷贝'\0', 只拷贝有效字符
			memcpy(_str + pos, str._str, len);
			_size += len;

			return *this;
		}

		/*
		* 复用
		* 对于substring 和 buffer 可以通过 (转换成string)截断 + substr 实现
		*/

		//find
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}

			return npos;
		}
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(sub);
			assert(pos < _size);

			const char* ptr = strstr(_str + pos, sub);//cstrig库函数, 返回匹配的第一个字符的地址
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		//erase
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				memcpy(_str + pos, _str + pos + len, _size - pos - len + 1);
				_size -= len;
			}

			return *this;
		}

		
		//逻辑操作符
		bool operator>(const string& str) const
		{
			return strcmp(_str, str._str) > 0;
		}
		bool operator==(const string& str) const
		{
			return strcmp(_str, str._str) == 0;
		}
		bool operator>=(const string& str) const
		{
			return *this > str || *this == str;
		}
		bool operator<=(const string& str) const
		{
			return !(*this > str);
		}
		bool operator<(const string& str) const
		{
			return !(*this >= str);
		}
		bool operator!=(const string& str) const
		{
			return !(*this == str);
		}

		//运算操作符
		string& operator=(string str)
		{
			swap(str);
			return *this;
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string operator+(const char ch)
		{
			string tmp(*this);
			tmp += ch;
			return tmp;
		}
		string& operator+=(const string& str)
		{
			append(str);
			return *this;
		}
		string operator+(const string& str)
		{
			string tmp(*this);
			tmp.append(str);
			return tmp;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		string operator+(const char* str)
		{
			string tmp(*this);
			tmp.append(str);
			return tmp;
		}
		
		//[]
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		
		
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}


	private:
		size_t _capacity;//最大有效存储长度
		size_t _size;//实际长度
		char* _str;//字符串地址
	public:

		//静态成员变量 : 声明定义分离
		static size_t npos;
		//C++11特性 : 加上const可直接在类内定义静态变量
		//const static size_t npos = -1;  

	};

	size_t string::npos = -1;

#pragma region 输入输出
	//<<
	ostream& operator<<(std::ostream& out, const string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			out << str[i];
		}
		return out;
	}

	////>> -- 基础版本
	//istream& operator>>(istream& in, string& str)
	//{
	//	//清理并设置初始容量
	//	str.clear();
	//	str.reserve(64);
	//
	//	char ch;
	//
	//	ch = in.get();
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		str += ch;
	//		ch = in.get();
	//	}
	//
	//	return in;
	//}
	
	//升级版--减少扩容操作
	istream& operator>>(istream& in, string& str)
	{
		//清理并设置初始容量
		str.clear();
		str.reserve(64);

		const int N = 32;
		char buff[N];
		size_t i = 0;
	
		char ch;
	
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;

			if (i == N - 1)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}

			ch = in.get();
		}

		buff[i] = '\0';
		str += buff;
	
		return in;
	}

#pragma endregion

	//构造
	void test1()
	{
		cout << "MyString" << endl;
		string s1;
		string s2("String");
		string s3("HelloSTL", 5);
		string s4(20, 'o');
		string s5(s2);
		string s6(s4, 10);

		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s4 << endl;
		cout << s5 << endl;
		cout << s6 << endl;

	}
	//操作符
	void test2()
	{
		string s1("helloSTl");
		string s2;

		cin >> s1 >> s2;
		cout << s1 << endl << s2 << endl;
		s2 = s1;
		cout << s1 << endl << s2 << endl;
	}
	void test3()
	{
		string s1("Hello");
		string s2("Mystring");

		cout << s1 + '!' << endl;
		cout << s1 + " qlz" << endl;
		cout << s1 + s2 << endl;


		cout << (s1 += '!') << endl;
		cout << (s1 += " qlz") << endl;
		cout << (s1 += s2) << endl;
	}
	//增删改查
	void DealUrl(const string& url)
	{
		size_t pos1 = url.find("://");
		if (pos1 == string::npos)
		{
			cout << "非法url" << endl;
			return;
		}
		// 休息到16:08继续
		string protocol = url.substr(0, pos1);
		cout << protocol << endl;

		size_t pos2 = url.find('/', pos1 + 3);
		if (pos2 == string::npos)
		{
			cout << "非法url" << endl;
			return;
		}
		string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
		cout << domain << endl;

		string uri = url.substr(pos2 + 1);
		cout << uri << endl << endl;
	}
	void test4()
	{
		string url1 = "https://cplusplus.com/reference/string/string/";
		string url2 = "https://image.baidu.com/search/detail?ct=503316480&z=0&ipn=d&word=ascall&step_word=&hs=0&pn=0&spn=0&di=7108135681917976577&pi=0&rn=1&tn=baiduimagedetail&is=0%2C0&istype=0&ie=utf-8&oe=utf-8&in=&cl=2&lm=-1&st=undefined&cs=2613959014%2C543572025&os=2740573600%2C1059518451&simid=2613959014%2C543572025&adpicid=0&lpn=0&ln=179&fr=&fmq=1660115697093_R&fm=&ic=undefined&s=undefined&hd=undefined&latest=undefined&copyright=undefined&se=&sme=&tab=0&width=undefined&height=undefined&face=undefined&ist=&jit=&cg=&bdtype=0&oriquery=&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.php.cn%2Fupload%2Fimage%2F147%2F157%2F796%2F1593765739620093.png%26refer%3Dhttp%3A%2F%2Fimg.php.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Dauto%3Fsec%3D1662707704%26t%3Da68cb238bbb3f99d0554098c785d526e&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Brir_z%26e3BvgAzdH3FuwqAzdH3F9c9amd_z%26e3Bip4s&gsm=1&rpstart=0&rpnum=0&islist=&querylist=&nojc=undefined&dyTabStr=MCwzLDIsNCw2LDEsNSw3LDgsOQ%3D%3D";
		string url3 = "ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf";

		DealUrl(url1);
		DealUrl(url2);
		DealUrl(url3);
	}
	void test5()
	{
		string s1;
		s1.resize(20);
		cout << s1 << endl;

		string s2("hello");
		s2.resize(20, 'x');
		cout << s2 << endl;
		s2.resize(10);
		cout << s2 << endl;

	}
	void test6()
	{
		string s("12345678");
		string s1("12345678");

		cout << s.erase(0, 5) << endl;
		cout << s1.erase(6, 9) << endl;
		cout << string("123456").erase();

	}

}

```

###### 阅读推荐

<a href = "https://coolshell.cn/articles/10478.html">酷壳-陈浩-C++面试中string类的一种正确写法</a>
		<a href = "https://blog.csdn.net/haoel/article/details/1491219?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166368282316782414956992%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166368282316782414956992&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-1491219-null-null.nonecase&utm_term=string%E7%B1%BB%E5%88%B0%E5%BA%95%E6%80%8E%E4%B9%88%E5%95%A6&spm=1018.2226.3001.4450">strig类到底怎么啦</a>
		[C++ STL string的Copy-On-Write技术](https://coolshell.cn/articles/12199.html) 
		[C++的std::string的“读时也拷贝”技术](https://coolshell.cn/articles/1443.html)

##### vector

###### 新思想

```
泛型编程--模板成员变量
迭代器失效问题
深拷贝嵌套问题
```

###### 迭代器失效

```
迭代器失效问题: insert(), erase()
insert: 发生扩容 使pos指向的空间非法, 野指针; 插入后, pos不再指向原来的 [逻辑位置], 运行结果不符合逻辑, std::insert()返回插入的元素的迭代器
erase: 发生缩容, 使pos指向的空间非法, 野指针; 逻辑问题. erase()根据编译器规则不同, 会有不同的结果. 不建议erase后立即访问, std::erase()返回删除元素的后一个元素的迭代器
```

###### 其他

```
capacity的代码在vs和g++下分别运行会发现，vs下capacity是按1.5倍增长的，g++是按2倍增长的。 这个问题经常会考察，不要固化的认为，vector增容都是2倍，具体增长多少是根据具体的需求定义 的。vs是PJ版本STL，g++是SGI版本STL。 reserve只负责开辟空间，如果确定知道需要用多少空间，reserve可以缓解vector增容的代价缺陷问 题。 resize在开空间的同时还会进行初始化，影响size。
```

###### 全代码

[Vector模拟实现](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/vector%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/Vector.h)

~~~c++
#pragma once

#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

namespace qlz
{
	template<class T>//模板类型

	class vector
	{
	public:

		//vector迭代器是原生指针, 我们声明两个迭代器, 类型为模板类型指针;
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		//const_iterator begin() const, 构成函数重载
		//因为第一个形参, 即对象的指针是不同类型, 一个是非const指针, 一个是const指针
		const_iterator cbegin() const
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}


		//无参默认构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		//拷贝构造
		vector(const vector<T>& vec)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reverse(vec.capacity());

			/*for (size_t i = 0; i < vec.size(); i++)
			{
				_start[i] = vec._start[i];
			}

			_finish = _start + vec.size();
			_endOfStorage = _start + vec.capacity();*/

			//迭代器实现
			iterator it = begin();
			const_iterator vit = vec.cbegin();
			while (vit != vec.cend())
			{
				//已设置容量
				*it++ = *vit++;
			}
			_finish = it;

		}

		//n个元素
		vector(size_t n, const T& val = T())
			//注意成员变量声明顺序
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (size_t i = 0; i < n; i++)
			{
				//已设置容量
				_start[i] = val;
			}
		}
		/*
		* 理论上将，提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 10);
		* 编译器在编译时，认为T已经被实例化为int，而10和10编译器会默认其为int类型,这两个类型相同
		* 本意是构造10个10，但是size_t 和 int 不是相同类型，恰好迭代器构造的两个模板参数是同一类型
		* 所以，就不会走vector(size_t n, const T& value = T())这个构造方法，而是迭代器构造
		* 因为 vector(InputIterator first, InputIterator last) 模板Inpu实例化为int时, 形参列表更符合
		* 但是10 和 10根本不是一个区间，编译时就报错了
		* 故需要该构造方法, 防止跑到迭代器构造函数
		*/
		vector(int n, const T& val = T())
			//注意成员变量声明顺序
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (int i = 0; i < n; i++)
			{
				//已设置容量
				_start[i] = val;
			}
		}

		//迭代器构造
		template<class InputIterator>//迭代器模板
		vector(InputIterator first, InputIterator last)
		{
			//复用push_back
			while (first != last)
			{
				//未确定容量, 调用push_back, 每次询问是否需要扩容
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}


	private:
		bool Full()
		{
			if (_finish == _endOfStorage)
			{
				return true;
			}

			return false;
		}
	public:
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		bool empty() const
		{
			if (_finish == _start)
			{
				return true;
			}

			return false;
		}

		void reverse(size_t n)
		{
			if (n <= capacity())
			{
				return;
			}

			size_t oldSize = size();

			T* tmp = new T[n];

			for (size_t i = 0; i < oldSize; i++)
			{
				tmp[i] = _start[i];//模板类型T的赋值运算
			}
			delete[] _start;

			_start = tmp;
			tmp = nullptr;
			_finish = _start + oldSize;
			_endOfStorage = _start + n;

		}

		void resize(size_t n, const T& val = T())
		{
			if (n <= _finish - _start)
			{
				_finish = _start + n;
			}
			else
			{
				reverse(n);

				iterator cur = _finish;
				_finish = _start + n;
				while (cur != _finish)
				{
					//已经确定容量到位, 直接使用赋值, 减少调用
					*cur = val;
					cur++;
				}
			}
		}


		//接受形参的引用, 将形参替换为空对象
		void swap(vector<T>& vec)
		{
			::swap(_start, vec._start);//std
			::swap(_finish, vec._finish);
			::swap(_endOfStorage, vec._endOfStorage);
		}



		//传元素引用, 防止无意义的深拷贝
		iterator insert(iterator it, const T& val)
		{
			assert(it <= _finish);//合法插入

			if (Full())
			{
				size_t pos = it - _start;

				reverse(capacity() == 0 ? 2 : capacity() * 2);

				it = _start + pos;//重置插入位置迭代器, 防止迭代器失效
			}

			iterator end = _finish - 1;//_finish所在地址, 为新的vector最后一个元素的位置

			while (end >= it)
			{
				*(end + 1) = *end;
				end--;
			}

			*it = val;
			_finish++;
			return it;//返回插入位置的迭代器
		}

		//复用insert
		void push_back(const T& val)
		{
			insert(_finish, val);
		}

		//返回被删除的位置的迭代器
		iterator erase(iterator it)
		{
			assert(!empty());//非空

			// 挪动数据进行删除
			iterator begin = it;
			while (begin != _finish - 1) {
				*begin = *(begin + 1);
				++begin;
			}

			--_finish;
			return it;
		}

		//复用erase
		void pop_back()
		{
			erase(_finish - 1);
		}

		vector<T>& operator= (vector<T> vec)
		{
			swap(vec);
			return *this;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}



	private:

		//左闭右开
		//没必要设置初始值, 因为会频繁使用初始化列表
		iterator _start;//头
		iterator _finish;//尾 == 头指针 + 实际大小
		iterator _endOfStorage;// == 头指针 + 最大容量
	};

	void Test1()
	{
		qlz::vector<int> v1;
		qlz::vector<int> v2(10, 5);

		int array[] = { 1,2,3,4,5 };
		qlz::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

		qlz::vector<int> v4(v3);

		for (size_t i = 0; i < v2.size(); ++i)
		{
			cout << v2[i] << " ";
		}
		cout << endl;

		auto it = v3.begin();
		while (it != v3.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Test2()
	{
		qlz::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		cout << v.front() << endl;
		cout << v.back() << endl;
		cout << v[0] << endl;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.pop_back();
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 0);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		/*qlz::vector<int> vvv;
		vvv.push_back(1);
		vvv.push_back(2);
		vvv.push_back(3);
		vvv.push_back(4);
		vvv.push_back(5);

		qlz::vector<char> vv;
		vv.push_back('a');
		vv.push_back('b');
		vv.push_back('c');
		vv.push_back('d');*/

	}

	void Test3()
	{
		vector<int*> vec;
		int a = 1, b = 2, c = 3;
		vec.push_back(&a);
		vec.push_back(&c);
		vec.push_back(&b);

		for (auto& ptr : vec)
		{
			cout << *ptr << ' ';
		}


	}
}
~~~

###### 注意

~~~C++
//n个元素
		vector(size_t n, const T& val = T())
			//注意成员变量声明顺序
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (size_t i = 0; i < n; i++)
			{
				//已设置容量
				_start[i] = val;
			}
		}
		/*
		* 理论上将，提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 10);
		* 编译器在编译时，认为T已经被实例化为int，而10和10编译器会默认其为int类型,这两个类型相同
		* 本意是构造10个10，但是size_t 和 int 不是相同类型，恰好迭代器构造的两个模板参数是同一类型
		* 所以，就不会走vector(size_t n, const T& value = T())这个构造方法，而是迭代器构造
		* 因为 vector(InputIterator first, InputIterator last) 模板Inpu实例化为int时, 形参列表更符合
		* 但是10 和 10根本不是一个区间，编译时就报错了
		* 故需要该构造方法, 防止跑到迭代器构造函数
		*/
		vector(int n, const T& val = T())
			//注意成员变量声明顺序
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_start + n)
		{
			for (int i = 0; i < n; i++)
			{
				//已设置容量
				_start[i] = val;
			}
		}

		//迭代器构造
		template<class InputIterator>//迭代器模板
		vector(InputIterator first, InputIterator last)
		{
			//复用push_back
			while (first != last)
			{
				//未确定容量, 调用push_back, 每次询问是否需要扩容
				push_back(*first);
				++first;
			}
		}
~~~

##### list

###### 新思想

```
泛型编程--通过模板类型列表的不同,形参实例化不同, 最终实现泛型编程
复用思想--适配器
非原生指针迭代器--封装原生指针, 形成迭代器类, 并重载运算符, 向原生指针靠拢
--重点迭代器
```

###### 全代码

[List的模拟实现](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/List%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/List.h)

~~~C++
#pragma once

#include<assert.h>
#include<iostream>
#include<list>

using namespace std;


namespace qlz
{
	//节点结构
	template<typename T>//数据类型
	struct list_node
	{
		T _data;//元素
		list_node<T>* _next;//后指针
		list_node<T>* _prev;//前指针

		list_node(const T& x = T())//默认构造
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}

	};


	//迭代器知识点
	/*
	* 1. 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用, 两种迭代器属于相同的类型
	* 2. 通过实例化的区别, 生成const迭代器, 和非const迭代器, 两种迭代器属于不同的类型, 指定 引用返回, 指针返回的类型
	* typedef _list_iterator<T, T&, T*>             iterator;
	* typedef _list_iterator<T, const T&, const T*> const_iterator;
	*
	* List 的迭代器
	* 迭代器有两种实现方式，具体应根据容器底层数据结构实现：
	*   1. 原生态指针，比如：vector
	*   2. 将原生态指针进行封装，因迭代器使用形式与指针完全相同，因此在自定义的类中必须实现以下方法：
	* 	 1. 指针可以解引用，迭代器的类中必须重载operator*()
	* 	 2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	* 	 3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	* 		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前移动，所以需要重载，如果是forward_list就不需要重载--
	* 	 4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
	*/

	//正向迭代器
	template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
	struct _list_iterator
	{
	public:
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> iterator;

		//使用 std::find() 需要这些 
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;

		//反向迭代器需要这些
		typedef Ref Ref;
		typedef Ptr Ptr;

		Node* _node;

		//指针类型, 浅拷贝即可
		_list_iterator(Node* node = nullptr)
			:_node(node)
		{}
		//默认生成的拷贝构造为浅拷贝, 可使用
		/*_list_iterator(const iterator& it)
			:_node(it._node)
		{}*/

		//!=
		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}

		//==
		bool operator==(const iterator& it) const
		{
			return _node == it._node;
		}


		/* 对于循环双向带头链表
		* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
		* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
		* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
		* 所以需要对 (*). / -> 重载
		* ++, -- 同理
		*/

		//*
		// 注意模板类型
		// const T& operator*()
		// T& operator*()
		Ref operator*()
		{
			return (_node->_data);
		}

		//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
		Ptr operator->()
		{
			return &(operator*());
		}

		// ++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		iterator operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// --it
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		// it--
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

	};

	/*反向迭代器(重写逻辑)*/
	//template<typename T, typename Ref, typename Ptr>//数据类型, 数据类型的引用, 数据类型的指针
	//struct _reverse_list_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef _reverse_list_iterator<T, Ref, Ptr> reverse_iterator;
	//
	//	Node* _node;
	//
	//	//指针类型, 浅拷贝即可
	//	_reverse_list_iterator(Node* node = nullptr)
	//		:_node(node)
	//	{}
	//
	//	//!=
	//	bool operator!=(const reverse_iterator& it) const
	//	{
	//		return _node != it._node;
	//	}
	//
	//	//==
	//	bool operator==(const reverse_iterator& it) const
	//	{
	//		return _node == it._node;
	//	}
	//
	//
	//	/* 对于循环双向带头链表
	//	* 在逻辑上, Node节点应该就是元素, 而实际上, Node节点 封装了元素和前后指针
	//	* 逻辑上, 迭代器为元素的"指针", 若元素为结构体类型, 则可以通过 (*). / -> 访问元素的成员变量
	//	* 但实际上, 迭代器为Node节点的指针, (*). / -> 访问的的是 Node节点的 元素和前后指针,
	//	* 所以需要对 (*). / -> 重载
	//	* ++, -- 同理
	//	*/
	//
	//	//*
	//	// 注意模板类型
	//	// const T& operator*()
	//	// T& operator*()
	//	Ref operator*()
	//	{
	//		Node* tmp= _node->_prev;
	//		return (tmp->_data);
	//	}
	//
	//	//->, 注意, 若元素为结构体类型, 编译器进行了优化, it->(得到元素地址)->_val1 -----> it->_val
	//	Ptr operator->()
	//	{
	//		return &(operator*());
	//	}
	//
	//	// ++it
	//	reverse_iterator& operator++()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}
	//
	//	// it++
	//	reverse_iterator operator++(int)
	//	{
	//		reverse_iterator tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}
	//
	//	// --it
	//	reverse_iterator& operator--()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//
	//	// it--
	//	reverse_iterator operator--(int)
	//	{
	//		iterator tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}
	//
	//};
	/*反向迭代器(适配器)*/
	template<class iterator>
	struct _reverse_list_iterator
	{
	public:
		// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
		typedef typename iterator::Ref Ref;
		typedef typename iterator::Ptr Ptr;
		typedef _reverse_list_iterator<iterator> reverse_iterator;
	public:
		// 构造
		_reverse_list_iterator(iterator it)
			: _rit(it)
		{}

		// 具有指针类似行为
		Ref operator*()
		{
			iterator temp(_rit);
			--temp;
			return *temp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		// 迭代器支持移动
		reverse_iterator& operator++()
		{
			--_rit;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp(*this);
			--_rit;
			return temp;
		}

		reverse_iterator& operator--()
		{
			++_rit;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			++_rit;
			return temp;
		}

		// 迭代器支持比较
		bool operator!=(const reverse_iterator& l)const
		{
			return _rit != l._rit;
		}

		bool operator==(const reverse_iterator& l)const
		{
			return _rit != l._rit;
		}

		iterator _rit;
	};

	//List
	template<typename T>
	class list//双向带头循环链表
	{

	public:
		typedef list_node<T> Node;
		//通过实例化的区别, 生成const迭代器, 和非const迭代器
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		/*
		* 仍然可以 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用
		* eg
		* typedef const _list_iterator<T, T&, T*> const_iterator;
		*
		* const iterator begin() const
		* {
		* 	return const iterator(_head->_next);
		* }
		*
		* const iterator end() const
		* {
		* 	return const iterator(_head);
		* }
		*
		* T& operator*()
		* {
		* 	return (it->_data);
		* }
		* const T& operator*() const
		* {
		* 	return (it->_data);
		* }
		*/

		/*反向迭代器(不复用)*/
		/*typedef _reverse_list_iterator<T, T&, T*> reverse_iterator;
		typedef _reverse_list_iterator<T, const T&, const T*> const_reverse_iterator;*/
		/*反向迭代器(复用)*/
		typedef _reverse_list_iterator<iterator> reverse_iterator;
		typedef _reverse_list_iterator<const_iterator> const_reverse_iterator;



		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(size_t n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; ++i)
				push_back(value);
		}

		list(int n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; ++i)
				push_back(value);
		}

		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			// 用l中的元素构造临时的temp,然后与当前对象交换
			list<T> temp(l.begin(), l.end());
			this->swap(temp);
		}

		list<T>& operator=(list<T> l)
		{
			this->swap(l);
			return *this;
		}


		//内置交换
		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
		}

		//判空
		bool empty()const
		{
			return _head->_next == _head;
		}

		//元素个数
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t count = 0;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}

			return count;
		}

		//设置元素个数
		void resize(size_t newsize, const T& val = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				// 有效元素个数减少到newsize
				while (newsize < oldsize)
				{
					pop_back();
					oldsize--;
				}
			}
			else
			{
				while (oldsize < newsize)
				{
					push_back(val);
					oldsize++;
				}
			}
		}

		//清空
		void clear()
		{
			Node* cur = _head->_next;

			// 采用头删除删除
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}
			//只保留头节点
			_head->_next = _head->_prev = _head;
		}

		const_iterator begin() const//const对象
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const//const对象
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}


		/*反向迭代器(不复用正向)*/
		//const_reverse_iterator rbegin() const//const对象
		//{
		//	return const_reverse_iterator(_head);
		//}
		//const_reverse_iterator rend() const//const对象
		//{
		//	return const_reverse_iterator(_head->_next);
		//}
		//reverse_iterator rbegin()
		//{
		//	return reverse_iterator(_head);
		//}
		//reverse_iterator rend()
		//{
		//	return reverse_iterator(_head->_next);
		//}
		/*反向迭代器(复用正向)*/
		const_reverse_iterator rbegin() const//const对象
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const//const对象
		{
			return const_reverse_iterator(begin());
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}


		void push_back(const T& val)
		{
			Node* node = new Node(val);

			Node* tail = _head->_prev;
			tail->_next = node;
			node->_prev = tail;
			node->_next = _head;
			_head->_prev = node;
		}

		//返回当前节点迭代器
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		//返回下一个节点的迭代器
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}


		//不支持[]
		T& front()
		{
			return _head->_next->_val;
		}
		const T& front()const
		{
			return _head->_next->_val;
		}
		T& back()
		{
			return _head->_prev->_val;
		}
		const T& back()const
		{
			return _head->_prev->_val;
		}


	private:
		Node* _head;//头节点
	};



#pragma region 测试

	/*void ttest1()
		{
			list<int> lis1;
			lis1.push_back(1);
			lis1.push_back(2);
			lis1.push_back(3);
		}
		struct pPos
		{
			int _a1;
			int _a2;
			pPos(int a1 = 0, int a2 = 0)
				:_a1(a1)
				, _a2(a2)
			{}
		};
		void ttest2()
		{
			int x = 10;
			int* p1 = &x;
			cout << *p1 << endl;
			pPos aa;
			pPos* p2 = &aa;
			p2->_a1;
			p2->_a2;
			list<pPos> lt;
			lt.push_back(pPos(10, 20));
			lt.push_back(pPos(10, 21));
			list<pPos>::iterator it = lt.begin();

			cout << endl;
		}
		void FFunc(const list<int>& l)
		{
			list<int>::const_iterator it = l.begin();
			*it;

			cout << endl;
		}*/

	void test11()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	struct Pos
	{
		int _a1;
		int _a2;

		Pos(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};
	void test22()
	{
		int x = 10;
		int* p1 = &x;

		cout << *p1 << endl;

		Pos aa;
		Pos* p2 = &aa;
		p2->_a1;
		p2->_a2;

		list<Pos> lt;
		lt.push_back(Pos(10, 20));
		lt.push_back(Pos(10, 21));

		list<Pos>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;

			++it;
		}
		cout << endl;
	}
	void Funcc(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test33()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		Funcc(lt);
	}
	void test44()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

		lt.pop_back();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = find(lt.begin(), lt.end(), 4);
		if (pos != lt.end())
		{
			// pos是否会失效？不会
			lt.insert(pos, 40);
			//lt.insert(pos, 30);
			*pos *= 100;
		}

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test55()
	{
		list<int> l1;
		l1.push_back(4);
		l1.push_back(1);
		l1.push_back(3);
		l1.push_back(2);

		/*auto it = l1.begin();
		cout << *it << endl;
		auto rit = l1.rbegin();
		cout << *rit;*/

		for (auto rit = l1.rbegin(); rit != l1.rend(); rit++)
			cout << *rit << endl;



	}
#pragma endregion

}
~~~



###### 适配器--反向迭代器

~~~C++
#define _CRT_SECURE_NO_WARNINGS 1

//此.h为反向迭代器适配器代码

namespace qlz
{
	//_iterator<class T>::iterator, T&, T*
	//_iterator<class T>::iterator, const T&, const T*
	template<class iterator>
	struct _reverse_iterator
	{
	public:
		// 注意：此处typename的作用是明确告诉编译器，Ref是Iterator类中的一个类型，而不是静态成员变量
		// 否则编译器编译时就不知道Ref是Iterator中的类型还是静态成员变量
		// 因为静态成员变量也是按照 类名::静态成员变量名 的方式访问的
		typedef typename iterator::Ref Ref;
		typedef typename iterator::Ptr Ptr;
		typedef _reverse_iterator<iterator> reverse_iterator;
	public:
		// 构造
		_reverse_iterator(iterator it)
			: _rit(it)
		{}

		// 具有指针类似行为
		Ref operator*()
		{
			iterator temp(_rit);
			--temp;
			return *temp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		// 迭代器支持移动
		reverse_iterator& operator++()
		{
			--_rit;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp(*this);
			--_rit;
			return temp;
		}

		reverse_iterator& operator--()
		{
			++_rit;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			++_rit;
			return temp;
		}

		// 迭代器支持比较
		bool operator!=(const reverse_iterator& l)const
		{
			return _rit != l._rit;
		}

		bool operator==(const reverse_iterator& l)const
		{
			return _rit == l._rit;
		}

		iterator _rit;
	};
}
~~~

##### stack/queue/priority_queue

> 这三个容器使用的都是复用思想，模板参数需要变量+实现了对应操作的数据结构
>
> 不关心底层的数据结构如何实现的
>
> 复用STL的双端队列queue

###### stack

~~~C++
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<deque>
#include<list>

using namespace std;


namespace qlz
{
	template<typename T, typename Container = deque<T> >
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top() const
		{
			return _con.back();
		}

		bool empty()  const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}
~~~



###### queue

~~~C++
#pragma once

#include<iostream>
#include<vector>
#include<deque>
#include<list>

using namespace std;

//适配器模式
namespace qlz
{
	template<class T, class Container = deque<T> >
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		T& back()
		{
			return _con.back();
		}

		T& front()
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}

		const T& front() const
		{
			return _con.front();
		}


		bool empty()  const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}
~~~



###### priority_queue

> 优先队列使用的是堆思想，需要随机读取，这里我们使用vector

~~~C++
#pragma once

#include<iostream>
#include<vector>
#include<deque>
#include<list>

using namespace std;

namespace qlz
{
	template <class T, class Container = vector<T>, class Compare = less<T> >
    //以下注释逻辑按大堆描述
	class priority_queue
	{
    public:

        //建堆往下走--小树向大数
        void adjust_down(size_t parent)
        {
            size_t child = parent * 2 + 1;
            while (child < _con.size())
            {
                // 选出左右孩子中大的那一个, 将大的升上去替换为父节点
                if (child + 1 < _con.size() && _cmp(_con[child], _con[child + 1]))
                {
                    ++child;
                }

                //判断是否比父节点大
                if (_cmp(_con[parent], _con[child]))
                {
                    std::swap(_con[child], _con[parent]);

                    //原节点下沉, 继续判断是否需要下沉
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        //插入往上走: 一直往上走, 找到属于自己的位置
        void adjust_up(size_t child)
        {
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                //if (_con[child] > _con[parent])
                //如果比父节点大, 交换
                if (_cmp(_con[parent], _con[child]))
                {
                    std::swap(_con[child], _con[parent]);
                    //往上走, 判断交换后是否比新的父节点大
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }

        priority_queue()
        {
            ;
        }

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _con.push(*first);               
                ++first;
            }
            //减一次得到真实下标, 再减一次除以2, 为得到父节点.
            //先建小的堆, 再根据得到的堆建大的堆
            for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
            {
                adjust_down(i);
            }
        }

        bool empty() const
        {
            return _con.empty();
        }

        size_t size() const
        {
            return _con.size();
        }

        const T& top() const 
        {
            return _con.front();
        }

        void push(const T& x)
        {
            _con.push_back(x);

            adjust_up(_con.size() - 1);//往上走, 找位置
        }

        void pop()
        {
            std::swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();

            adjust_down(0);//交换上去的为小元素, 从头建一次堆
        }

    private:

        Container _con;

        Compare _cmp;
	};
}

~~~

##### map/set

> map/set 高度依赖迭代器
>
> 复用红黑树树

###### RBTree

> **重难点：红黑树的旋转**

~~~C++
#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
#include<set>

using namespace std;

#define x first 
#define y second 

namespace myRBT
{
	enum Colour
	{
		RED,
		BLACK
	};

	//节点
	template<typename T>
	struct RBTNode
	{

		T _data;
		Colour _colour;
		struct RBTNode<T>* _left;
		struct RBTNode<T>* _right;
		struct RBTNode<T>* _parent;

		RBTNode(const T& data)
			:_data(data)
			, _colour(RED)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
		{}
	};

	//迭代器
	template<typename T, typename Ref, typename Ptr>
	struct __RBTreeIterator
	{
		typedef RBTNode<T> Node;
		typedef __RBTreeIterator<T, Ref, Ptr> Self;

		Node* _node;

		__RBTreeIterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}

		Self& operator++()
		{
			//左中右， 中序遍历， 
			
			//遍历到该节点时， 该节点为 ‘根节点’，访问右子树
			//若当前节点有右孩子，则++为其右子树的最左节点
			if (_node->_right)
			{
				Node* left = _node->_right;

				while (left->_left)
				{
					left = left->_left;
				}

				_node = left;
			}
			//若没有右子树，则这颗子树已经访问完了，向上至父亲为根节点的树
			//若原树为左子树， 则父节点还未访问， 若为右子树，则父节点的树所在的树也访问完毕
			//继续向上， 直至 有 作为左子树的节点出现 或者 全部访问完
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;

				//父节点不存在则为根节点
				//为右子树仍需向上遍历
				while (parent && cur == parent->_right)
				{
					parent = parent->_parent;
					cur = cur->_parent;
				}

				_node = parent;
			}


			return *this;
		}

		Self& operator--()
		{
			//左中右， 中序遍历， 

			//遍历到该节点时， 该节点为 ‘根节点’，则其上一个节点为左子树的最右节点
			//若当前节点有左孩子，则--为其左子树的最右节点
			if (_node->_left)
			{
				Node* right = _node->_left;

				while (right->_right)
				{
					right = right->_right;
				}

				_node = right;
			}
			//若没有左子树，则其父节点访问之后， 直接访问了该节点
			//若原树为左子树， 则父节点还未访问， 若为右子树，则父节点已被访问，且就是--
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;

				while (parent && cur == parent->_left)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}

				_node = parent;
			}


			return *this;
		}

	};

	template<typename K, typename T, typename KeyOfT>
	struct RBT
	{
	public:
		typedef RBTNode<T> Node;
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;


		RBT()
			:_root(nullptr)
		{}
		RBT(const RBT<K, T, KeyOfT>& rbt)
		{
			_root = _myCopy(rbt._root);
		}
		RBT<K, T, KeyOfT>& operator= (RBT<K, T, KeyOfT> rbt)//形参是深拷贝出来的， 在函数结束时会销毁
		{
			swap(_root, rbt._root);

			return (*this);
		}
		~RBT()
		{
			_Destory(_root);
		}

		iterator begin()
		{
			Node* left = _root;

			while (left && left->_left)
			{
				left = left->_left;
			}

			return iterator(left);
		}
		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator cbegin() const
		{
			Node* left = _root;

			while (left && left->_left)
			{
				left = left->_left;
			}

			return (const_iterator)left;
		}
		const_iterator cend() const
		{
			return (const_iterator)nullptr;
		}

		pair<iterator, bool> insert(const T& data)
		{
			KeyOfT kot;

			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_colour = BLACK;
				return make_pair(iterator(_root), true);
			}

			Node* parent = _root;
			Node* cur = _root;

			while (cur)
			{

				if (kot(data) > kot(cur->_data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(data) < kot(cur->_data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return make_pair(iterator(cur), false);
				}
			}

			//初始化新节点
			cur = new Node(data);
			cur->_parent = parent;
			if (kot(data) > kot(parent->_data))
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			Node* ret = cur;

			//控制平衡
			//父亲存在， 父亲为黑色,符合红黑树; 父亲为红色，进行调整
			//父亲不存在，则为根节点，只需调整根节点的颜色
			while (parent && parent->_colour == RED)
			{
				Node* grandfat = parent->_parent;
				assert(grandfat);//因为父节点为红色， 则其一定有一个黑色父节点
				assert(grandfat->_colour == BLACK);

				//叔叔在右边
				if (parent == grandfat->_left)
				{
					Node* uncle = grandfat->_right;
					//1. 叔叔存在， 且叔叔为红色
					//则 将父亲和叔叔变为黑色，爷爷变成红色，继续向上调整
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//令 cur = grandfat, 继续向上处理
						cur = grandfat;
						parent = cur->_parent;
					}
					//叔叔不存在，或者叔叔存在且为黑色
					//则 需要旋转并变色
					else
					{
						if (cur == parent->_left)
						{
							// 2. 左子树的左子树
							//    g
							//  p   u
							//c
							//爷爷节点右旋，父变黑，祖变红
							RotateR(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. 左子树的右子树
							//      g
							//  p       u
							//    c
							//父亲节点左旋，爷爷节点右旋，自己变黑，祖变红
							RotateL(parent);
							RotateR(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// 调整后符合红黑树
					}
				}
				else//叔叔在左边
				{
					Node* uncle = grandfat->_left;
					//1. 叔叔存在， 且叔叔为红色
					//则 将父亲和叔叔变为黑色，爷爷变成红色，继续向上调整
					if (uncle && uncle->_colour == RED)
					{
						parent->_colour = BLACK;
						uncle->_colour = BLACK;
						grandfat->_colour = RED;
						//令 cur = grandfat, 继续向上处理
						cur = grandfat;
						parent = cur->_parent;
					}
					//叔叔不存在，或者叔叔存在且为黑色
					//则 需要旋转并变色
					else
					{
						if (cur == parent->_right)
						{
							// 3. 右子树的右子树
							//    g
							//  u   p
							//        c
							//爷爷节点左旋，父变黑，祖变红
							RotateL(grandfat);
							grandfat->_colour = RED;
							parent->_colour = BLACK;
						}
						else
						{
							// 2. 右子树的左子树
							//      g
							//  u       p
							//        c
							//父亲节点右旋，爷爷节点左旋，自己变黑，祖变红
							RotateR(parent);
							RotateL(grandfat);
							cur->_colour = BLACK;
							grandfat->_colour = RED;
						}

						break;// 调整后符合红黑树
					}
				}

			}

			_root->_colour = BLACK;//根节点一定为黑色

			return make_pair(iterator(ret), true);

		}
		iterator find(const K& key)
		{
			KeyOfT kot;

			Node* cur = _root;

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return (iterator)cur;
				}
				else if (key > kot(cur->_data))
				{
					cur = cur->_right;
				}
				else
				{
					cur = cur->_left;
				}
			}

			return (iterator)nullptr;
		}


		bool IsBalance()
		{
			if (_root == nullptr)
			{
				return true;
			}

			if (_root->_colour == RED)
			{
				cout << "根节点的颜色为红色， 违法规则" << endl;
				return true;
			}

			// 黑色节点数量基准值
			int benchmark = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_colour == BLACK)
					++benchmark;

				cur = cur->_left;
			}

			return PrevCheck(_root, 0, benchmark);
		}

	private:
		Node* _myCopy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* cur = new Node(root->_data);
			cur->_left = _myCopy(root->_left);
			cur->_right = _myCopy(root->_right);

			return cur;
		}
		void _Destory(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Destory(root->_left);
			_Destory(root->_right);
			delete(root);
			root = nullptr;

			return;
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;//待左旋节点的右子树
			Node* subRL = subR->_left;//右子树的左子树

			parent->_right = subRL;//1. 将右左子树变成父节点的右子树
			if (subRL)
			{
				subRL->_parent = parent;//2. 更换右左子树的父节点
			}

			Node* Pparent = parent->_parent;//记录父节点的父节点

			subR->_left = parent;//3. 将父节点变成subR的左子树
			parent->_parent = subR;//4. 更换其父节点

			if (_root == parent)//如果是根节点
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				subR->_parent = Pparent;// 5. 更换父节点
				//父节点是左子树
				if (Pparent->_left == parent)
				{
					Pparent->_left = subR;// 6. 

				}
				else
				{
					Pparent->_right = subR;// 6. 
				}
			}


		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
			}

			Node* Pparent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;

			if (_root == parent)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				subL->_parent = Pparent;
				if (Pparent->_left == parent)
				{
					Pparent->_left = subL;
				}
				else
				{
					Pparent->_right = subL;
				}
			}

		}
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;

			RotateL(subL);
			RotateR(parent);

		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;

			RotateR(subR);
			RotateL(parent);

		}

		bool PrevCheck(Node* root, int blackNum, int& benchmark)
		{
			if (root == nullptr)
			{

				if (blackNum != benchmark)
				{
					cout << "某条路径的黑色节点的数量不相等" << endl;
					return false;
				}
				else
				{
					return true;
				}
			}

			if (root->_colour == BLACK)
			{
				++blackNum;
			}

			if (root->_colour == RED && root->_parent->_colour == RED)
			{
				cout << "存在连续的红色节点" << endl;
				return false;
			}

			return PrevCheck(root->_left, blackNum, benchmark)
				&& PrevCheck(root->_right, blackNum, benchmark);
		}

	private:
		Node* _root = nullptr;
	};
}
~~~

###### set

~~~c++
#pragma once

#include"RBTree.h"

namespace mySet
{
	template<typename K>
	class set
	{

		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
			typedef typename myRBT::RBT<K, K, SetKeyOfT>::iterator iterator;
			typedef typename myRBT::RBT<K, K, SetKeyOfT>::const_iterator const_iterator;

			iterator begin()
			{
				return _rbt.begin();
			}
			iterator end()
			{
				return _rbt.end();
			}

			iterator insert(const K& key)
			{
				return _rbt.insert(key).first;
			}

	private:
		myRBT::RBT<K, K, SetKeyOfT> _rbt;

	};

	void test_set()
	{
		set<int> s;

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		s.insert(3);
		s.insert(2);
		s.insert(1);
		s.insert(5);
		s.insert(3);
		s.insert(6);
		s.insert(4);
		s.insert(9);
		s.insert(7);


		it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}
~~~



###### map

~~~C++
#pragma once

#include"RBTree.h"

namespace mySet
{
	template<typename K>
	class set
	{

		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
			typedef typename myRBT::RBT<K, K, SetKeyOfT>::iterator iterator;
			typedef typename myRBT::RBT<K, K, SetKeyOfT>::const_iterator const_iterator;

			iterator begin()
			{
				return _rbt.begin();
			}
			iterator end()
			{
				return _rbt.end();
			}

			iterator insert(const K& key)
			{
				return _rbt.insert(key).first;
			}

	private:
		myRBT::RBT<K, K, SetKeyOfT> _rbt;

	};

	void test_set()
	{
		set<int> s;

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		s.insert(3);
		s.insert(2);
		s.insert(1);
		s.insert(5);
		s.insert(3);
		s.insert(6);
		s.insert(4);
		s.insert(9);
		s.insert(7);


		it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}
~~~

##### unordered_map/unordered_set

> unordered_map/set底层复用hash

###### HashBase

~~~C++
#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace myHash_bucket
{

	template<typename T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode()
		{}

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	//前置声明, 迭代器需要哈希表指针
	template<typename K, typename T, class ToINT, class KOT>
	class HashTable;

	template<typename K, typename T, class ToINT, class KOT>
	struct __hash_iterator
	{
	public:
		typedef HashNode<T> Node;
		typedef HashTable<K, T, ToINT, KOT> HT;
		typedef __hash_iterator<K, T, ToINT, KOT> Self;

		__hash_iterator()
		{}
		__hash_iterator(Node* node, HT* pht)
			:_node(node)
			, _ht(pht)
		{}
		__hash_iterator(const Self& it)
			:_node(it._node)
			, _ht(it._ht)
		{}
		~__hash_iterator()
		{}

		T& operator*() const
		{
			return _node->_data;
		}
		T* operator->() const
		{
			return &(_node->_data);
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				ToINT toint;
				KOT kot;

				//_tab是私有成员，不允许外界访问， 将迭代器声明为哈希表的友元类，即可
				size_t hashi = toint(kot(_node->_data)) % _ht->_tab.size();
				++hashi;

				for (; hashi < _ht->_tab.size(); ++hashi)
				{
					if (_ht->_tab[hashi])
					{
						_node = _ht->_tab[hashi];
						break;
					}
				}

				if (hashi == _ht->_tab.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}
		Self& operator++(int)
		{
			Self tmp(*this);

			++(*this);

			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

	private:
		Node* _node;
		HT* _ht;
	};

	template<typename K, typename T, class ToINT, class KOT>
	class HashTable
	{
		
	public:
		
		typedef HashNode<T> Node;

		//将迭代器声明为哈希表的友元
		template<class K, class T, class Hash, class KeyOfT>
		friend struct __hash_iterator;

		typedef __hash_iterator<K, T, ToINT, KOT> iterator;

		//素数表，素数作为被除数， 可以有效减少模相等，减少桶过长的问题
		inline size_t __stl_next_prime(size_t n)
		{
			static const size_t __stl_num_primes = 28;
			static const size_t __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (size_t i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return -1;
		}
	public:
		~HashTable()
		{
			for (size_t i = 0; i < _tab.size(); ++i)
			{
				Node* cur = _tab[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tab[i] = nullptr;
			}
		}

		iterator begin()
		{
			for (size_t i = 0; i < _tab.size(); ++i)
			{
				if (_tab[i])
				{
					return iterator(_tab[i], this);
				}
			}

			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		pair<iterator, bool> insert(const T& data)
		{
			KOT kot;
			ToINT toint;

			auto ret = find(kot(data));
			if (ret != end())
			{
				return make_pair(ret, false);
			}

			//负载因子为1,表示桶满了， 需要扩容
			if (_size == _tab.size())
			{
				//闭散列哈希表， 扩容时需要复用insert， 所以创建一个临时哈希表
				//而开散列哈希表， 其数据节点可以进行复用，不需要复用insert，所以只需创建一个临时vector
				vector<Node*> newTab;
				newTab.resize(__stl_next_prime(_tab.size()), nullptr);

				//将旧表数据映射迁移到新表
				for (auto& cur : _tab)
				{
					if (cur == nullptr) continue;

					Node* old = cur;

					while (cur)
					{
						Node* next = cur->_next;

						//头插
						size_t hashi = toint(kot(cur->_data)) % newTab.size();
						cur->_next = newTab[hashi];
						newTab[hashi] = cur;

						cur = next;
					}

					//置空
					old = nullptr;
				}

				_tab.swap(newTab);
			}

			//头插
			size_t hashi = toint(kot(data)) % _tab.size();
			Node* newNode = new Node(data);
			newNode->_next = _tab[hashi];
			_tab[hashi] = newNode;
			++_size;

			return make_pair(iterator(newNode, this), true);//构造迭代器时，需要哈希表指针

		}

		iterator find(const K& key)
		{
			if (_tab.size() == 0)
			{
				return end();
			}

			ToINT toint;
			KOT kot;
			size_t hashi = toint(key) % _tab.size();
			Node* cur = _tab[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}

				cur = cur->_next;
			}



			return end();
		}

		bool erase(const K& key)
		{
			if (_tab.size() == 0)
			{
				return false;
			}

			ToINT toint;
			KOT kot;
			size_t hashi = toint(key) % _tab.size();
			Node* prev = nullptr;
			Node* cur = _tab[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					break;
				}

				prev = cur;
				cur = cur->_next;
			}

			//不存在
			if (cur == nullptr)
			{
				return false;
			}
			else if (prev == nullptr)//为第一个
			{
				_tab[hashi] = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}

			delete cur;
			cur = nullptr;
			--_size;

			return true;
		}

		size_t size()
		{
			return _size;
		}

	private:
		vector<Node*> _tab;
		size_t _size = 0;
	};


~~~

###### unordered_map

~~~C++
#pragma once

#include"HashBase.h"

namespace myUnMap
{
	//将key转换为size_t类型
	template<typename K>
	struct HashToINT
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	//对string类型进行特化
	template<>
	struct HashToINT<string>
	{
		//BKDR思想
		size_t operator()(const string& key)
		{
			size_t res = 0;
			for (auto& ch : key)
			{
				res *= 131;
				res += ch;
			}

			return res;
		}
	};

	template<class K, class V, class ToINT = HashToINT<K>>
	class unordered_map
	{
	private:
		struct KeyOfT
		{
			//可不对K修饰，对pair整体修饰
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		//template<typename K, typename T, class ToINT, class KOT>
		typedef  myHash_bucket::HashTable<K, pair<const K, V>, HashToINT<K>, KeyOfT> HT;
		typedef typename HT::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<const K,V>& kv)
		{
			return _ht.insert(kv);
		}
		bool erase(const K& key)
		{
			return _ht.erase(key);
		}
		iterator find(const K& key)
		{
			return _ht.find(key);
		}
		size_t size()
		{
			return _ht.size();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));

			return ret.first->second;
		}

	private:
		HT _ht;

	};

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("left", "左边"));

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		unordered_map<string, int> countMap;
		string arr[] = { "苹果", "", "苹果", "梨子", "苹果", "苹果", "西瓜", "苹果", "西瓜", "西瓜", "西瓜" };
		for (auto e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}

		countMap.erase("苹果");
		countMap.erase("香蕉");
		cout << endl;

		auto itt = countMap.find("西瓜");
		if (itt != countMap.end())
		{
			cout << itt->first << ":" << itt->second << endl;
		}
		

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}

~~~



###### unordered_set

~~~C++
#pragma once

#include"HashBase.h"

namespace myUnSet
{
	//将key转换为size_t类型
	template<typename K>
	struct HashToINT
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	//对string类型进行特化
	template<>
	struct HashToINT<string>
	{
		//BKDR思想
		size_t operator()(const string& key)
		{
			size_t res = 0;
			for (auto& ch : key)
			{
				res *= 131;
				res += ch;
			}

			return res;
		}
	};

	template<class K, class ToINT = HashToINT<K>>
	class unordered_set
	{
	private:
		struct KeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		
	public:
		//template<typename K, typename T, class ToINT, class KOT>
		typedef  myHash_bucket::HashTable<K, const K, HashToINT<K>, KeyOfT> HT;
		typedef typename HT::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.insert(key);
		}
		bool erase(const K& key)
		{
			return _ht.erase(key);
		}
		iterator find(const K& key)
		{
			return _ht.find(key);
		}
		size_t size()
		{
			return _ht.size();
		}

	private:
		HT _ht;

	};

	void test_set()
	{
		unordered_set<int> s;
		s.insert(2);
		s.insert(3);
		s.insert(1);
		s.insert(2);
		s.insert(5);

		//unordered_set<int>::iterator it = s.begin();
		auto it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}

		auto find_1 = s.find(1);
		if (find_1 != s.end())
		{
			cout << *find_1;
		}

		cout << endl;
	}
}

~~~

###### 思想

~~~
模板特化
BKDR
K-V
~~~



### 继承

##### 继承的基本概念和定义

###### 概念

> **继承(inheritance)机制是面向对象程序设计使代码可以复用的最重要的手段**，它允许程序员在保持原有类特性的基础上进行扩展，增加功能，这样产生新的类，称派生类。
>
> 继承呈现了面向对象 程序设计的层次结构，体现了由简单到复杂的认知过程。以前我们接触的复用都是函数复用，继承是类设计层次的复用。

~~~c++
class Person
{
 public:
 void Print()
 {
     cout << "name:" << _name << endl;
     cout << "age:" << _age << endl;
 }
 protected:
 string _name = "peter"; // 姓名
 int _age = 18;  // 年龄
};
// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
class Student : public Person
{
 protected:
 int _stuid; // 学号
};
class Teacher : public Person
{
 protected:
 int _jobid; // 工号
};
int main()
{
 Student s;
 Teacher t;
 s.Print();
 t.Print();
 return 0;
}
~~~



###### 定义格式

1. 定义格式： 下面我们看到Person是父类，也称作基类。Student是子类，也称作派生类。

    ![image-20221020141552758](%E5%9B%BE%E7%89%87/README/image-20221020141552758.png)

2. 继承关系

    ![image-20221020141634603](%E5%9B%BE%E7%89%87/README/image-20221020141634603.png)

###### 继承的基类成员访问权限的变化

| 类成员/继承方式      |       public继承       | protected继承          | private继承          |
| -------------------- | :--------------------: | ---------------------- | -------------------- |
| 基类的public成员     |   派生类的public成员   | 派生类的protected 成员 | 派生类的private 成员 |
| 基类的protected 成员 | 派生类的protected 成员 | 派生类的protected 成员 | 派生类的private 成员 |
| 基类的private成 员   |    在派生类中不可见    | 在派生类中不可见       | 在派生类中不可见     |

即：

1. 基类private成员在派生类中无论以什么方式继承都是不可见的。这里的**不可见是指基类的私有成员还是被继承到了派生类对象中，但是语法上限制派生类对象不管在类里面还是类外面 都不能去访问它。** 
2. 基类private成员在派生类中是不能被访问，如果基类成员不想在类外直接被访问，但需要在派生类中能访问，就定义为protected。**可以看出保护成员限定符是因继承才出现的。**
3. 实际上面的表格我们进行一下总结会发现，基类的私有成员在子类都是不可见。基类的其他 成员在子类的访问方式 == Min(成员在基类的访问限定符，继承方式)，public > protected  > private。 
4. 使用关键字**class时默认的继承方式是private，使用struct时默认的继承方式是public**，不过 **最好显示的写出继承方式。**
5. **在实际运用中一般使用都是public继承，几乎很少使用protetced/private继承**，也不提倡 使用protetced/private继承，因为protetced/private继承下来的成员都只能在派生类的类里 面使用，实际中扩展维护性不强。

~~~C++
// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化  
class Person
{
public
 void Print ()
 {
 cout<<_name <<endl;
 }
protected :
 string _name ; // 姓名
private :
 int _age ; // 年龄
};
//class Student : protected Person
//class Student : private Person
class Student : public Person
{
protected :
 int _stunum ; // 学号
};
~~~



##### 基类和派生类 对象赋值转换

- **派生类对象 可以赋值给 基类的对象 / 基类的指针 / 基类的引用。**这里有个形象的说法叫**切片 或者切割**。寓意把派生类中父类那部分切来赋值过去。 
- **基类对象不能赋值给派生类对象。** 
- **基类的指针或者引用可以通过强制类型转换赋值给派生类的指针或者引用。** **但是必须是 基类的指针是指向派生类对象时 才是安全的。**

    > 如：基类的引用是被派生类赋值的， 则这个基类引用可以强转成对应子类的引用。这里基类如果是多态类型，可以使用RTTI(RunTime Type Information)的dynamic_cast 来进行识别后进行安全转换。

![image-20221020143620244](%E5%9B%BE%E7%89%87/README/image-20221020143620244.png)

~~~C++
class Person
{
    protected :
    string _name; // 姓名
    string _sex;  // 性别
    int _age; // 年龄
};
class Student : public Person
{
    public :
    int _No ; // 学号
};
void Test ()
{
    Student sobj ;
    // 1.子类对象可以赋值给父类对象/指针/引用
    Person pobj = sobj ;
    Person* pp = &sobj;
    Person& rp = sobj;

    //2.基类对象不能赋值给派生类对象
    sobj = pobj;

    // 3.基类的指针可以通过强制类型转换赋值给派生类的指针
    pp = &sobj;
    Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
    ps1->_No = 10;

    pp = &pobj;
    Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
    ps2->_No = 10;
}
~~~
> **注意**：这种转换不属于类型转换，而是特殊语法

![image-20221015092045923](%E5%9B%BE%E7%89%87/README/image-20221015092045923.png)

------



##### 继承中的作用域

1. 在继承体系中基类和派生类都有独立的作用域。 
2. **子类和父类中有同名成员，子类成员将屏蔽对父类同名成员的直接访问，这种情况叫隐藏， 也叫重定义。（在子类成员函数中，可以使用 基类::基类成员 显示访问）** 
3. 需要注意的是**如果是成员函数的隐藏，只需要函数名相同就构成隐藏，不关注形参列表**。 
4. 注意在实际中在继承体系里面最好不要定义同名的成员。

~~~C++
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
class Person
{
    protected :
    string _name = "小李子"; // 姓名
    int _num = 111;   // 身份证号
};
class Student : public Person
{
    public:
    void Print()
    {
        cout<<" 姓名:"<<_name<< endl;
        cout<<" 身份证号:"<<Person::_num<< endl;
        cout<<" 学号:"<<_num<<endl;
    }
    protected:
    int _num = 999; // 学号
};
void Test()
{
    Student s1;
    s1.Print();
};

~~~

~~~C++
// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
class A
{
    public:
    void fun()
    {
        cout << "func()" << endl;
    }
};
class B : public A
{
    public:
    void fun(int i)
    {
        A::fun();
        cout << "func(int i)->" <<i<<endl;
    }
};
void Test()
{
    B b;
    b.fun(10);
};
~~~





##### 派生类的默认成员函数

> 6个默认成员函数，“默认”的意思就是指我们不写，编译器会变我们自动生成一个，那么在派生类 中，这几个成员函数是如何生成的呢？ 

1. **派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。**如果**基类没有默认的构造函数**，则**必须在派生类构造函数的初始化列表阶段显示调用。** 
2. 派生类的拷贝构造函数**必须调用基类的拷贝构造完成基类的拷贝初始化**。 
3. 派生类的operator=**必须要调用基类的operator=完成基类的复制。** 
4. **派生类的析构函数会在被调用完成后自动调用基类的析构函数清理基类成员。**因为这样才能保证派生类对象先清理派生类成员再清理基类成员的顺序。
5. **派生类对象初始化先调用基类构造再调派生类构造。** 
6.  **派生类对象析构清理先调用派生类析构再调基类的析构。** 
7. 因为后续一些场景析构函数需要构成重写，重写的条件之一是函数名相同(这个我们后面会讲 解)。那么**编译器会对析构函数名进行特殊处理，处理成destrutor()，所以父类析构函数不加 virtual的情况下，子类析构函数和父类析构函数构成隐藏关系。**

![image-20221020145447885](%E5%9B%BE%E7%89%87/README/image-20221020145447885.png)

~~~C++
class Person
{
    public :
    Person(const char* name = "peter")
        : _name(name )
        {
            cout<<"Person()" <<endl;
        }

    Person(const Person& p)
        : _name(p._name)
        {
            cout<<"Person(const Person& p)" <<endl;
        }

    Person& operator=(const Person& p )
    {
        cout<<"Person operator=(const Person& p)"<< endl;
        if (this != &p)
            _name = p ._name;

        return *this ;
    }

    ~Person()
    {
        cout<<"~Person()" <<endl;
    }
    protected :
    string _name ; // 姓名
};
class Student : public Person
{
    public :
    Student(const char* name, int num)
        : Person(name )
            , _num(num )
        {
            cout<<"Student()" <<endl;
        }

    Student(const Student& s)
        : Person(s)
            , _num(s ._num)
        {
            cout<<"Student(const Student& s)" <<endl ;
        }

    Student& operator = (const Student& s )
    {
        cout<<"Student& operator= (const Student& s)"<< endl;
        if (this != &s)
        {
            Person::operator =(s);
            _num = s ._num;
        }
        return *this ;
    } 

    ~Student()
    {
        cout<<"~Student()" <<endl;
    }
    protected :
    int _num ; //学号
};
void Test ()
{
    Student s1 ("jack", 18);
    Student s2 (s1);
    Student s3 ("rose", 17);
    s1 = s3 ;
}

~~~



------

##### 继承与友元

> 友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员 
>

~~~C++
class Student;
class Person
{
 public:
 friend void Display(const Person& p, const Student& s);
 protected:
 string _name; // 姓名
};
class Student : public Person
{
 protected:
 int _stuNum; // 学号
};
void Display(const Person& p, const Student& s)
{
 cout << p._name << endl;
 cout << s._stuNum << endl;
}
void main()
{
 Person p;
 Student s;
 Display(p, s);
}

~~~



------

##### 继承与静态成员

> 基类定义了static静态成员，则**整个继承体系里面只有一个这样的成员**。无论派生出多少个子 类，都只有一个static成员实例 。
>

~~~C++
class Person
{
 public :
 Person () {++ _count ;}
 protected :
 string _name ; // 姓名
 public :
 static int _count; // 统计人的个数。
};
int Person :: _count = 0;
class Student : public Person
{
 protected :
 int _stuNum ; // 学号
};
class Graduate : public Student
{
 protected :
 string _seminarCourse ; // 研究科目
};
void TestPerson()
{
 Student s1 ;
 Student s2 ;
 Student s3 ;
 Graduate s4 ;
 cout <<" 人数 :"<< Person ::_count << endl;
 Student ::_count = 0;
 cout <<" 人数 :"<< Person ::_count << endl;
}

~~~



------

##### 复杂的菱形继承及菱形虚拟继承

###### 继承方式

- **单继承：**一个子类只有一个直接父类时称这个继承关系为单继承

    ![image-20221020145902743](%E5%9B%BE%E7%89%87/README/image-20221020145902743.png)

- **多继承：**一个子类有两个或以上直接父类时称这个继承关系为多继承

    ![image-20221020145949271](%E5%9B%BE%E7%89%87/README/image-20221020145949271.png)

- **菱形继承：**菱形继承是多继承的一种特殊情况。

    ![image-20221020150007884](%E5%9B%BE%E7%89%87/README/image-20221020150007884.png)



###### 菱形继承的问题

> **菱形继承的问题：从下面的对象成员模型构造，可以看出菱形继承有数据冗余和二义性的问题。 在Assistant的对象中Person成员会有两份。**

![image-20221020150043641](%E5%9B%BE%E7%89%87/README/image-20221020150043641.png)

~~~C++
class Person
{
public :
string _name ; // 姓名
};
class Student : public Person
{
protected :
int _num ; //学号
};
class Teacher : public Person
{
protected :
int _id ; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected :
string _majorCourse ; // 主修课程
};
void Test ()
{
// 这样会有二义性无法明确知道访问的是哪一个
Assistant a ;
a._name = "peter";
// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
a.Student::_name = "xxx";
a.Teacher::_name = "yyy";
}

~~~

###### 虚拟继承

> **虚拟继承可以解决菱形继承的二义性和数据冗余的问题。如上面的继承关系，在Student和 Teacher的继承Person时使用虚拟继承，即可解决问题。需要注意的是，虚拟继承不要在其他地方去使用。**

~~~C++
class Person
{
public :
string _name ; // 姓名
};
class Student : virtual public Person
{
protected :
int _num ; //学号
};
class Teacher : virtual public Person
{
protected :
int _id ; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected :
string _majorCourse ; // 主修课程
};
void Test ()
{
Assistant a ;
a._name = "peter";
}
~~~

###### 虚拟继承解决数据冗余和二义性的原理

为了研究虚拟继承原理，我们给出了一个简化的菱形虚拟继承体系，再借助内存窗口观察对象成 员的模型。

~~~C++
class A
{
public:
int _a;
};
// class B : public A
class B : virtual public A
{
public:
int _b;
};
// class C : public A
class C : virtual public A
{
public:
int _c;
};
class D : public B, public C
{
public:
int _d;
};
int main()
{
D d;
d.B::_a = 1;
d.C::_a = 2;
d._b = 3;
d._c = 4;
d._d = 5;
return 0;
}
~~~

下图是菱形继承的内存对象成员模型：这里可以看到数据冗余

![image-20221020150405408](%E5%9B%BE%E7%89%87/README/image-20221020150405408.png)

下图是菱形虚拟继承的内存对象成员模型：这里可以分析出D对象中将A放到的了对象组成的最下 面，这个A同时属于B和C，那么B和C如何去找到公共的A呢？

**这里是通过了B和C的两个指针，指向的一张表。这两个指针叫虚基表指针，这两个表叫虚基表。虚基表中存的偏移量。通过偏移量 可以找到下面的A。**

![image-20221020150441865](%E5%9B%BE%E7%89%87/README/image-20221020150441865.png)

~~~C++
// 有童鞋会有疑问为什么D中B和C部分要去找属于自己的A？那么大家看看当下面的赋值发生时，d是不是要去找出B/C成员中的A才能赋值过去？
D d;
B b = d;
C c = d;
~~~

下面是上面的Person关系菱形虚拟继承的原理解释：
![image-20221020150526890](%E5%9B%BE%E7%89%87/README/image-20221020150526890.png)










##### 继承的总结和反思

1. 很多人说C++语法复杂，其实多继承就是一个体现。有了多继承，就存在菱形继承，有了菱 形继承就有菱形虚拟继承，底层实现就很复杂。所以一般不建议设计出多继承，一定不要设 计出菱形继承。否则在复杂度及性能上都有问题。 

2.  多继承可以认为是C++的缺陷之一，很多后来的面向对象语言都没有多继承，如Java。 

3. 继承和组合

    - public继承是一种is-a的关系。也就是说每个派生类对象都是一个基类对象。 
    - 组合是一种has-a的关系。假设B组合了A，每个B对象中都有一个A对象。
    - **优先使用对象组合，而不是类继承** 。[优先使用对象组合，而不是类继承 - 残雪余香 - 博客园 (cnblogs.com)](https://www.cnblogs.com/nexiyi/archive/2013/06/16/3138568.html)
    - 继承允许你根据基类的实现来定义派生类的实现。这种通过生成派生类的复用通常被称 为白箱复用(white-box reuse)。术语“白箱”是相对可视性而言：在继承方式中，基类的 内部细节对子类可见 。继承一定程度破坏了基类的封装，基类的改变，对派生类有很 大的影响。派生类和基类间的依赖关系很强，耦合度高。 
    - 对象组合是类继承之外的另一种复用选择。新的更复杂的功能可以通过组装或组合对象 来获得。对象组合要求被组合的对象具有良好定义的接口。这种复用风格被称为黑箱复 用(black-box reuse)，因为对象的内部细节是不可见的。对象只以“黑箱”的形式出现。 组合类之间没有很强的依赖关系，耦合度低。优先使用对象组合有助于你保持每个类被 封装。 
    - 实际尽量多去用组合。组合的耦合度低，代码维护性好。不过继承也有用武之地的，有 些关系就适合继承那就用继承，另外要实现多态，也必须要继承。类之间的关系可以用 继承，可以用组合，就用组合。

    ~~~C++
    // Car和BMW Car和Benz构成is-a的关系
    class Car{
        protected:
        string _colour = "白色"; // 颜色
        string _num = "陕ABIT00"; // 车牌号
    };
    
    class BMW : public Car{
        public:
        void Drive() {cout << "好开-操控" << endl;}
    };
    
    class Benz : public Car{
        public:
        void Drive() {cout << "好坐-舒适" << endl;}
    };
    
    // Tire和Car构成has-a的关系
    
    class Tire{
        protected:
        string _brand = "Michelin";  // 品牌
        size_t _size = 17;         // 尺寸
    
    };
    
    class Car{
        protected:
        string _colour = "白色"; // 颜色
        string _num = "陕ABIT00"; // 车牌号
        Tire _t; // 轮胎
    }; 
    ~~~



------

##### 笔试面试

> 1. 什么是菱形继承？菱形继承的问题是什么？ 
> 2. 什么是菱形虚拟继承？如何解决数据冗余和二义性的 
> 3. 继承和组合的区别？什么时候用继承？什么时候用组合？
> 4. 虚基表哪里来？怎么判断派生类有几个虚基表？

------



### 多态

> 多态的概念：通俗来说，就是多种形态，具体点就是去完成某个行为，当不同的对象去完成时会 产生出不同的状态。
>

##### 定义及实现

###### 多态的构成条件

> 多态是同一个继承体系，不同继承关系的类对象，去调用同一函数，产生了不同的行为。比如Student继承了 Person。Person对象买票全价，Student对象买票半价。 
>

那么在继承中要构成多态还有两个条件： 

1. **必须通过基类的指针或者引用调用虚函数**
2. **被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写**

![image-20221020153736497](%E5%9B%BE%E7%89%87/README/image-20221020153736497.png)



###### 虚函数

> 被virtual修饰的**类成员函数**称为虚函数。
>

~~~c++
class Person {
 public:
 virtual void BuyTicket() { cout << "买票-全价" << endl;}
};
~~~



###### 虚函数的重写

> 虚函数的重写(覆盖)：派生类中有一个跟基类**完全相同**的虚函数(即派生类虚函数与基类虚函数的 返回值类型、函数名字、参数列表完全相同)，称子类的虚函数重写了基类的虚函数。
>

~~~C++
class Person {
 public:
 virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
 public:
 virtual void BuyTicket() { cout << "买票-半价" << endl; }
 /*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
 为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
 这样使用*/
 /*void BuyTicket() { cout << "买票-半价" << endl; }*/
};
void Func(Person& p)
{ p.BuyTicket(); }
int main()
{
 Person ps;
 Student st;
 Func(ps);
 Func(st);
 return 0;
}

~~~

**虚函数重写的两个例外**： 

1. **协变(基类与派生类虚函数返回值类型不同)** 

    派生类重写基类虚函数时，与基类虚函数返回值类型不同。**即基类虚函数返回基类对象的指 针或者引用，派生类虚函数返回派生类对象的指针或者引用时，称为协变。**（了解）

    ~~~C++
    class A{};
    class B : public A {};
    class Person {
        public:
        virtual A* f() {return new A;}
    };
    class Student : public Person {
        public:
        virtual B* f() {return new B;}
    };

    ~~~

2. **析构函数的重写(基类与派生类析构函数的名字不同)**

    如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字， 都与基类的析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同， 看起来违背了重写的规则，其实不然，这**里可以理解为编译器对析构函数的名称做了特殊处 理，编译后析构函数的名称统一处理成destructor。**

    ~~~C++
    class Person {
        public:
        virtual ~Person() {cout << "~Person()" << endl;}
    };
    class Student : public Person {
        public:
        virtual ~Student() { cout << "~Student()" << endl; }
    };
    // 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
    数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
        int main()
    {
        Person* p1 = new Person;
        Person* p2 = new Student;
        delete p1;
        delete p2;
        return 0;
    }
    
    ~~~



#####  C++11 override 和 final

> 从上面可以看出，C++对函数重写的要求比较严格，但是有些情况下由于疏忽，可能会导致函数 名字母次序写反而无法构成重载，而这种错误在编译期间是不会报出的，只有在程序运行时没有 得到预期结果才来debug会得不偿失，
>
> 因此：**C++11提供了override和final两个关键字，可以帮助用户检测是否重写。**

1. **final：修饰虚函数，表示该虚函数不能再被重写**

    ~~~C++
    class Car
    {
        public:
        virtual void Drive() final {}
    };
    class Benz :public Car
    {
        public:
        virtual void Drive() {cout << "Benz-舒适" << endl;}
    };
    ~~~

2.  **override: 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错**。

    ~~~C++
    class Car{
        public:
        virtual void Drive(){}
    };
    class Benz :public Car {
        public:
        virtual void Drive() override {cout << "Benz-舒适" << endl;}
    };
    ~~~



------

##### 重载、覆盖(重写)、隐藏(重定义)的对比

![image-20221020164121890](%E5%9B%BE%E7%89%87/README/image-20221020164121890.png)

------



##### 建议

###### 不实现多态不要将函数定义为虚函数

> ~~~C++
> 存在虚函数就会产生虚表， 有虚表就会运行时决议， 浪费时间空间
> ~~~

###### 析构函数建议定义为虚函数

~~~c++
父类* str1 = new 父类;
父类* str2 = new 子类;
delete str1;
delete str2;

~~~

> 若不把析构函数定义为虚函数， 不满足多态，则delete父类类型指针，会调用两次父类的析构

------

##### 抽象类

###### 抽象类

> **在虚函数的后面写上 =0 ，则这个函数为纯虚函数。**包含纯虚函数的类叫做抽象类（**也叫接口 类**），抽象类不能实例化出对象。**派生类继承后也不能实例化出对象，只有重写全部纯虚函数，派生类才能实例化出对象，否则派生类仍是抽象类，不能实例化对象**。纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。

~~~C++
class Car
{
 public:
 virtual void Drive() = 0;
};
class Benz :public Car
{
 public:
 virtual void Drive()
 {
     cout << "Benz-舒适" << endl;
 }
};
class BMW :public Car
{
 public:
 virtual void Drive()
 {
     cout << "BMW-操控" << endl;
 }
};
void Test()
{
 Car* pBenz = new Benz;
 pBenz->Drive();
 Car* pBMW = new BMW;
 pBMW->Drive();
}
~~~



###### 接口继承和实现继承

> 普通函数的继承是一种实现继承，派生类继承了基类函数，可以使用函数，继承的是函数的实现。虚函数的继承是一种接口继承，派生类继承的是基类虚函数的接口，目的是为了重写，达成多态，继承的是接口。
>
> 所以如果不实现多态，不要把函数定义成虚函数。**因为存在虚函数就会产生虚表， 有虚表就会运行时决议， 浪费时间空间。**

------

##### 多态的原理

###### 虚函数表

常考的一道笔试题：sizeof(Base)是多少？

~~~c++
class Base
{
public:
virtual void Func1()
{
  cout << "Func1()" << endl;
}
private:
int _b = 1;
};
~~~

通过观察测试我们发现b对象是8bytes，**除了_b成员，还多一个__vfptr放在对象的前面(注意有些 平台可能会放到对象的最后面，这个跟平台有关)，对象中的这个指针我们叫做虚函数表指针(v代 表virtual，f代表function)。**

一个含有虚函数的类中都**至少都有一个虚函数表指针**，因为虚函数 的地址要被放到虚函数表中，**虚函数表也简称虚表**。那么派生类中这个表放了些什么呢？我们接着往下分析

![image-20221020165130484](%E5%9B%BE%E7%89%87/README/image-20221020165130484.png)

~~~C++
// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
class Base
{
 public:
 virtual void Func1()
 {
     cout << "Base::Func1()" << endl;
 }
 virtual void Func2()
 {
     cout << "Base::Func2()" << endl;
 }
 void Func3()
 {
     cout << "Base::Func3()" << endl;
 }
 private:
 int _b = 1;
};
class Derive : public Base
{
 public:
 virtual void Func1()
 {
     cout << "Derive::Func1()" << endl;
 }
 private:
 int _d = 2;
};
int main()
{
 Base b;
 Derive d;
 return 0;
}

~~~

**通过观察和测试，我们发现了以下几点问题：** 

1. 派生类对象d中也有一个虚表指针，d对象由两部分构成，一部分是父类继承下来的成员，虚表指针也就是父类部分的，另一部分是自己的成员。 

2. **基类b对象和派生类d对象虚表是不一样的，**这里我们发现Func1完成了重写，所以**d的虚表 中存的是重写的Derive::Func1，**所以虚函数的重写也叫作覆盖，**覆盖就是指虚表中虚函数的覆盖**。重写是语法的叫法，覆盖是原理层的叫法。 

3. 另外**Func2继承下来后是虚函数，所以放进了虚表，Func3也继承下来了，但不是虚函数，所以不会放进虚表。** 

4. **虚函数表本质是一个存虚函数指针的指针数组，一般情况这个数组最后面放了一个nullptr。**

5. 总结一下派生类的虚表生成：

    - 先将**基类中的虚表内容拷贝一份到派生类虚表中** 
    - 如果派生类重写了基类中某个虚函数，用派生类自己的**虚函数覆盖虚表中基类的虚函数** 
    - **派生类自己新增加的虚函数按其在派生类中的声明次序增加到派生类虚表的最后。** 

6. 这里还有一个童鞋们很容易混淆的问题：虚函数存在哪的？虚表存在哪的？ 

    - **答：虚函数存在 虚表，虚表存在对象中。注意上面的回答的错的。**但是很多童鞋都是这样深以为然的。

    - 注意：**虚表存的是虚函数指针**，不是虚函数，虚函数和普通函数一样的，都是存在代码段的，只是他的指针又存到了虚表中。另外对**象中存的不是虚表，存的是虚表指针**。那么虚表存在哪的呢？实际我们去验证一下会发现vs下是**存在代码段的**。

    ![image-20221020170157379](%E5%9B%BE%E7%89%87/README/image-20221020170157379.png)



###### 多态的原理▲

上面分析了这个半天了那么多态的原理到底是什么？还记得这里Func函数传Person调用的 Person::BuyTicket，传Student调用的是Student::BuyTicket

![image-20221020170939096](%E5%9B%BE%E7%89%87/README/image-20221020170939096.png)

~~~C++
class Person {
 public:
 virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
 public:
 virtual void BuyTicket() { cout << "买票-半价" << endl; }
};
void Func(Person& p)
{
 p.BuyTicket();
}
int main()
{
 Person Mike;
 Func(Mike);
 Student Johnson;
 Func(Johnson);
 return 0;
}
~~~

1. 观察下图的红色箭头我们看到，p是指向mike对象时，p->BuyTicket在mike的虚表中找到虚 函数是Person::BuyTicket。 

2. 观察下图的蓝色箭头我们看到，p是指向johnson对象时，p->BuyTicket在johson的虚表中 找到虚函数是Student::BuyTicket。

3. 这样就实现出了不同对象去完成同一行为时，展现出不同的形态。

4. 反过来思考我们要达到多态，有**两个条件**，一个是虚函数覆盖，一个是对象的指针或引用调用虚函数。反思一下为什么？ 

5.  再通过下面的汇编代码分析，看出**满足多态以后的函数调用，不是在编译时确定的，是运行起来以后到对象的中取找的。不满足多态的函数调用时编译时确认好的。**

    ![image-20221020171058295](%E5%9B%BE%E7%89%87/README/image-20221020171058295.png)

    ~~~C++
    void Func(Person* p)
    {
        p->BuyTicket();
    }
    int main()
    {
        Person mike;
        Func(&mike);
        mike.BuyTicket();
    
        return 0;
    }
    // 以下汇编代码中跟你这个问题不相关的都被去掉了
    void Func(Person* p)
    {
        //...
            p->BuyTicket();
        // p中存的是mike对象的指针，将p移动到eax中
        001940DE  mov         eax,dword ptr [p]
            // [eax]就是取eax值指向的内容，这里相当于把mike对象头4个字节(虚表指针)移动到了edx
            001940E1  mov         edx,dword ptr [eax]
            // [edx]就是取edx值指向的内容，这里相当于把虚表中的头4字节存的虚函数指针移动到了eax
            00B823EE  mov         eax,dword ptr [edx]
            // call eax中存虚函数的指针。这里可以看出满足多态的调用，不是在编译时确定的，是运行起来以后到对象的中取找的。
            001940EA  call        eax  
            001940EC  cmp         esi,esp  
    }
    int main()
    {
        ... 
            // 首先BuyTicket虽然是虚函数，但是mike是对象，不满足多态的条件，所以这里是普通函数的调用转换成地址时，是在编译时已经从符号表确认了函数的地址，直接call 地址
            mike.BuyTicket();
        00195182  lea         ecx,[mike]
        00195185  call        Person::BuyTicket (01914F6h)  
            ... 
    }
    
    ~~~



###### 动态绑定与静态绑定

> 1. 静态绑定又称为前期绑定(早绑定)，在程序编译期间确定了程序的行为，也称为静态多态， 比如：函数重载，模板编程。
> 2. 动态绑定又称后期绑定(晚绑定)，是在程序运行期间，根据具体拿到的类型确定程序的具体行为，调用具体的函数，也称为动态多态。 
> 3. 本小节之前(5.2小节)买票的汇编代码很好的解释了什么是静态(编译器)绑定和动态(运行时)绑 定。

------

##### 单继承和多继承关系的虚函数表

> 需要注意的是在单继承和多继承关系中，下面我们去关注的是派生类对象的虚表模型，因为基类的虚表模型前面我们已经看过了，没什么需要特别研究的

###### 单继承中的虚函数表



~~~c++
class Base { 
 public :
 virtual void func1() { cout<<"Base::func1" <<endl;}
 virtual void func2() {cout<<"Base::func2" <<endl;}
 private :
 int a;
};
class Derive :public Base { 
 public :
 virtual void func1() {cout<<"Derive::func1" <<endl;}
 virtual void func3() {cout<<"Derive::func3" <<endl;}
 virtual void func4() {cout<<"Derive::func4" <<endl;}
 private :
 int b;
};
~~~

观察下图中的监视窗口中我们发现看不见func3和func4。这里是编译器的监视窗口故意隐藏了这两个函数，也可以认为是他的一个小bug。那么我们如何查看d的虚表呢？下面我们使用代码打印出虚表中的函数。

![image-20221020171810440](%E5%9B%BE%E7%89%87/README/image-20221020171810440.png)

~~~C++
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
 // 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
 cout << " 虚表地址>" << vTable << endl;
 for (int i = 0; vTable[i] != nullptr; ++i)
 {
     printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
     VFPTR f = vTable[i];
     f();
 }
 cout << endl;
}
int main()
{
 Base b;
 Derive d;
 // 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr
 // 1.先取b的地址，强转成一个int*的指针
 // 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
 // 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
 // 4.虚表指针传递给PrintVTable进行打印虚表
 // 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的-生成-清理解决方案，再编译就好了。
 VFPTR* vTableb = (VFPTR*)(*(int*)&b);
 PrintVTable(vTableb);
 VFPTR* vTabled = (VFPTR*)(*(int*)&d);
 PrintVTable(vTabled);
 return 0;
}
~~~

![image-20221020171905028](%E5%9B%BE%E7%89%87/README/image-20221020171905028.png)



###### 多继承中的虚函数表



~~~c++
class Base1 {
public:
virtual void func1() {cout << "Base1::func1" << endl;}
virtual void func2() {cout << "Base1::func2" << endl;}
private:
int b1;
};
class Base2 {
public:
virtual void func1() {cout << "Base2::func1" << endl;}
virtual void func2() {cout << "Base2::func2" << endl;}
private:
int b2;
};
class Derive : public Base1, public Base2 {
public:
virtual void func1() {cout << "Derive::func1" << endl;}
virtual void func3() {cout << "Derive::func3" << endl;}
private:
int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
cout << " 虚表地址>" << vTable << endl;
for (int i = 0; vTable[i] != nullptr; ++i)
{
  printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
  VFPTR f = vTable[i];
  f();
}
cout << endl;
}
int main()
{
Derive d;
VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
PrintVTable(vTableb1);
VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d+sizeof(Base1)));
PrintVTable(vTableb2);
return 0;
}
~~~

观察下图可以看出：多继承派生类的未重写的/新增的虚函数放在**第一个继承基类部分的虚函数表**中

![image-20221020172015696](%E5%9B%BE%E7%89%87/README/image-20221020172015696.png)

**为什么两个父类的虚表中， func1的地址不一样▲**

~~~c++
因为VS编译器， call的地址，不是函数的地址， 而是一条jump指令的地址， 跳转到这个指令， 通过这个指令去call原函数
~~~



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

### C++11

##### 列表初始化

> 在C++98中，标准允许使用花括号{}对数组或者结构体元素进行统一的列表初始值设定。
>
> C++11扩大了用大括号括起的列表(初始化列表)的使用范围，使其可用于所有的内置类型和用户自 定义的类型，使用初始化列表时，可添加等号(=)，也可不添加。
>
> 其实现底层原理为std::initializer_list

std::initializer_list的介绍文档： http://www.cplusplus.com/reference/initializer_list/initializer_list/

std::initializer_list一般是作为构造函数的参数，C++11对STL中的不少容器就增加 std::initializer_list作为参数的构造函数，这样初始化容器对象就更方便了。也可以作为operator= 的参数，这样就可以用大括号赋值。是支持列表初始化/赋值的关键。

http://www.cplusplus.com/reference/list/list/list/ 

http://www.cplusplus.com/reference/vector/vector/vector/ 

http://www.cplusplus.com/reference/map/map/map/ 

http://www.cplusplus.com/reference/vector/vector/operator=/

##### 多个关键字

###### auto

~~~C++
在C++98中auto是一个存储类型的说明符，表明变量是局部自动存储类型，但是局部域中定义局部的变量默认就是自动存储类型，所以auto就没什么价值了。
C++11中废弃auto原来的用法，将其用于实现自动类型推断。这样要求必须进行显示初始化，让编译器将定义对象的类型设置为初始化值的类型。
~~~

###### decltype

~~~C++
//关键字decltype将变量的类型声明为表达式指定的类型。
// decltype的一些使用使用场景
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
 decltype(t1 * t2) ret;
 cout << typeid(ret).name() << endl;
}
int main()
{
 const int x = 1;
 double y = 2.2;
 decltype(x * y) ret; // ret的类型是double
 decltype(&x) p;      // p的类型是int*
 cout << typeid(ret).name() << endl;
 cout << typeid(p).name() << endl;
 F(1, 'a');
 return 0;
}
~~~



###### nullptr

~~~C++
//由于C++中NULL被定义成字面量0，这样就可能回带来一些问题，因为0既能指针常量，又能表示整形常量。所以出于清晰和安全的角度考虑，C++11中新增了nullptr，用于表示空指针。
#ifndef NULL
#ifdef __cplusplus
#define NULL   0
#else
#define NULL   ((void *)0)
#endif
#endif
~~~



###### for : each

~~~C++
底层是迭代器，在编译阶段替换成迭代器遍历，使用范围for循环，迭代器需要支持++操作
~~~



##### STL变化

###### 新容器

用橘色圈起来是C++11中的一些几个新容器，但是实际最有用的是unordered_map和 unordered_set。这两个我们前面已经进行了非常详细的讲解，其他的大家了解一下即可。

![image-20221120214646334](%E5%9B%BE%E7%89%87/README/image-20221120214646334.png)



###### 新方法

~~~C++
如果我们再细细去看会发现基本每个容器中都增加了一些C++11的方法，但是其实很多都是用得比较少的。
比如提供了cbegin和cend方法返回const迭代器等等，但是实际意义不大，因为begin和end也是可以返回const迭代器的，这些都是属于锦上添花的操作。

实际上C++11更新后，容器中增加的新方法最后用的插入接口函数的右值引用版本：

http://www.cplusplus.com/reference/vector/vector/emplace_back/
http://www.cplusplus.com/reference/vector/vector/push_back/
http://www.cplusplus.com/reference/map/map/insert/
http://www.cplusplus.com/reference/map/map/emplace/

但是这些接口到底意义在哪？网上都说他们能提高效率，他们是如何提高效率的？
请看下面的右值引用和移动语义章节的讲解。另外emplace还涉及模板的可变参数，也需要再继续深入学习后面章节的知识。
~~~



##### 右值引用和移动语义▲

###### 左值引用和右值引用

> 传统的C++语法中就有引用的语法，而C++11中新增了的右值引用语法特性，所以从现在开始我们 之前学习的引用就叫做左值引用。无论左值引用还是右值引用，都是给对象取别名。 
>

什么是左值？什么是左值引用？ 

左值是一个表示数据的表达式(如变量名或解引用的指针)，我们**可以获取它的地址+可以对它赋值，左值可以出现赋值符号的左边，右值不能出现在赋值符号左边**。定义时const修饰符后的左值，不能给他赋值，但是可以取它的地址。左值引用就是给左值的引用，给左值取别名。

~~~C++
int main()
{
 // 以下的p、b、c、*p都是左值
 int* p = new int(0);
 int b = 1;
 const int c = 2;
 // 以下几个是对上面左值的左值引用
 int*& rp = p;
 int& rb = b;
 const int& rc = c;
 int& pvalue = *p;
 return 0;
}
~~~

什么是右值？什么是右值引用？ 

右值也是一个表示数据的表达式，如：字面常量、表达式返回值，函数返回值(这个不能是左值引 用返回)等等，**右值可以出现在赋值符号的右边，但是不能出现出现在赋值符号的左边，右值不能取地址**。右值引用就是对右值的引用，给右值取别名。

~~~C++
int main()
{
 double x = 1.1, y = 2.2;
 // 以下几个都是常见的右值
 10;
 x + y;
 fmin(x, y);
 // 以下几个都是对右值的右值引用
 int&& rr1 = 10;
 double&& rr2 = x + y;
 double&& rr3 = fmin(x, y);
 // 这里编译会报错：error C2106: “=”: 左操作数必须为左值
 10 = 1;
 x + y = 1;
 fmin(x, y) = 1;
 return 0;
}
~~~

> 需要注意的是右值是不能取地址的，但是给右值取别名后，会导致**右值被存储到特定位置，且可以取到该位置的地址**，也就是说例如：不能取字面量10的地址，但是rr1引用后，可以对rr1取地 址，也可以修改rr1。如果不想rr1被修改，可以用const int&& rr1 去引用，是不是感觉很神奇， 这个了解一下实际中右值引用的使用场景并不在于此，这个特性也不重要。
>



###### 左值引用与右值引用比较

左值引用总结： 

1. 左值引用只能引用左值，不能引用右值。 

2. 但是const左值引用既可引用左值，也可引用右值。

    ~~~C++
    int main()
    {
        // 左值引用只能引用左值，不能引用右值。
        int a = 10;
        int& ra1 = a;   // ra为a的别名
        //int& ra2 = 10;   // 编译失败，因为10是右值
        // const左值引用既可引用左值，也可引用右值。
        const int& ra3 = 10;
        const int& ra4 = a;
        return 0;
    }
    ~~~

右值引用总结： 

1. 右值引用只能右值，不能引用左值。

2. 但是右值引用可以move以后的左值。

    ~~~c++
    int main()
    {
        // 右值引用只能右值，不能引用左值。
        int&& r1 = 10;
        // error C2440: “初始化”: 无法从“int”转换为“int &&”
        // message : 无法将左值绑定到右值引用
        int a = 10;
        int&& r2 = a;
        // 右值引用可以引用move以后的左值
        int&& r3 = std::move(a);
     	return 0;
    }
    
    ~~~

    

###### 右值引用使用场景和意义

前面我们可以看到左值引用既可以引用左值和又可以引用右值，那为什么C++11还要提出右值引用呢？是不是化蛇添足呢？下面我们来看看左值引用的短板，右值引用是如何补齐这个短板的！

~~~C++
namespace bit
{
  class string
  {
  public:
      typedef char* iterator;
      iterator begin() 
      {
      	return _str;
      }
      iterator end()
      {
      	return _str + _size;
      }
      string(const char* str = "")
      :_size(strlen(str))
      , _capacity(_size)
      {
          //cout << "string(char* str)" << endl;
          _str = new char[_capacity + 1];
          strcpy(_str, str);
      }
      // s1.swap(s2)
      void swap(string& s)
      {
          ::swap(_str, s._str);
          ::swap(_size, s._size);
          ::swap(_capacity, s._capacity);
      }
      // 拷贝构造
      string(const string& s)
      :_str(nullptr)
      {
          cout << "string(const string& s) -- 深拷贝" << endl;
          string tmp(s._str);
          swap(tmp);
      }
      // 赋值重载
      string& operator=(const string& s)
      {
          cout << "string& operator=(string s) -- 深拷贝" << endl;
          string tmp(s);
          swap(tmp);
          return *this;
      }
      // 移动构造
      string(string&& s)
      :_str(nullptr)
      ,_size(0)
      ,_capacity(0)
      {
          cout << "string(string&& s) -- 移动语义" << endl;
          swap(s);
      }
      // 移动赋值
      string& operator=(string&& s)
      {
          cout << "string& operator=(string&& s) -- 移动语义" << endl;
          swap(s);
          return *this;
      }
      ~string()
      {
          delete[] _str;
          _str = nullptr;
      }
      char& operator[](size_t pos)
      {
          assert(pos < _size);
          return _str[pos];
      }
      void reserve(size_t n)
      {
          if (n > _capacity)
          {
              char* tmp = new char[n + 1];
              strcpy(tmp, _str);
              delete[] _str;
              _str = tmp;
              _capacity = n;
          }
      }
      void push_back(char ch)
      {
          if (_size >= _capacity)
          {
          	size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
          	reserve(newcapacity);
          }
          _str[_size] = ch;
          ++_size;
          _str[_size] = '\0';
      }
          //string operator+=(char ch)
      string& operator+=(char ch)
      {
          push_back(ch);
          return *this;
      }
      const char* c_str() const
      {
      	return _str;
      }
  private:
      char* _str;
      size_t _size;
      size_t _capacity; // 不包含最后做标识的\0
  };
}

~~~

**左值引用的使用场景**

> 做参数和做返回值都可以提高效率。
>

~~~C++
void func1(bit::string s)
{}
void func2(const bit::string& s)
{}
int main()
{
  bit::string s1("hello world");
  // func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
  func1(s1);
  func2(s1);
  // string operator+=(char ch) 传值返回存在深拷贝
  // string& operator+=(char ch) 传左值引用没有拷贝提高了效率
  s1 += '!';
  return 0;
}
~~~

**左值引用的短板**： 

但是当函数返回对象是一个局部变量，出了函数作用域就不存在了，就不能使用左值引用返回， 只能传值返回。例如：bit::string to_string(int value)函数中可以看到，这里只能使用传值返回， 传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。

![image-20221120220304508](%E5%9B%BE%E7%89%87/README/image-20221120220304508.png)

~~~C++
namespace bit
{
  bit::string to_string(int value)
  {
      bool flag = true;
      if (value < 0)
      {
          flag = false;
          value = 0 - value;
      }
      bit::string str;
      while (value > 0)
      {
          int x = value % 10;
          value /= 10;
          str += ('0' + x);
      }
      if (flag == false)
      {
      	str += '-';
      }
      std::reverse(str.begin(), str.end());
      return str;
  }
}
int main()
{
 // 在bit::string to_string(int value)函数中可以看到，这里
 // 只能使用传值返回，传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷
 贝构造)。
  bit::string ret1 = bit::to_string(1234);
  bit::string ret2 = bit::to_string(-1234);
  return 0;
}
~~~

![image-20221120220236045](%E5%9B%BE%E7%89%87/README/image-20221120220236045.png)

**右值引用和移动语义解决上述问题：** 

在bit::string中增加移动构造，**移动构造本质是将参数右值的资源窃取过来，占位已有，那么就不用做深拷贝了，所以它叫做移动构造，就是窃取别人的资源来构造自己。**

~~~C++
// 移动构造
string(string&& s)
:_str(nullptr)
,_size(0)
,_capacity(0)
{
  cout << "string(string&& s) -- 移动语义" << endl;
  swap(s);
}
int main()
{
  bit::string ret2 = bit::to_string(-1234);
  return 0;
}
~~~

再运行上面bit::to_string的两个调用，我们会发现，这里没有调用深拷贝的拷贝构造，而是调用 了移动构造，移动构造中没有新开空间，拷贝数据，所以效率提高了。

![image-20221120220219139](%E5%9B%BE%E7%89%87/README/image-20221120220219139.png)

**不仅仅有移动构造，还有移动赋值：**

在bit::string类中增加移动赋值函数，再去调用bit::to_string(1234)，不过这次是将 bit::to_string(1234)返回的右值对象赋值给ret1对象，这时调用的是移动构造。

~~~C++
// 移动赋值
string& operator=(string&& s)
{
 cout << "string& operator=(string&& s) -- 移动语义" << endl;
 swap(s);
 return *this;
}
int main()
{
  bit::string ret1;
  ret1 = bit::to_string(1234);
  return 0;
}
// 运行结果：
// string(string&& s) -- 移动语义
// string& operator=(string&& s) -- 移动语义
~~~

这里运行后，我们看到调用了一次移动构造和一次移动赋值。因为如果是用一个已经存在的对象 接收，编译器就没办法优化了。bit::to_string函数中会先用str生成构造生成一个临时对象，但是 我们可以看到，编译器很聪明的在这里把str识别成了右值，调用了移动构造。然后在把这个临时 对象做为bit::to_string函数调用的返回值赋值给ret1，这里调用的移动赋值。

**STL中的容器都是增加了移动构造和移动赋值：** 

http://www.cplusplus.com/reference/string/string/string/ 

http://www.cplusplus.com/reference/vector/vector/vector/



###### 右值引用引用左值及其一些更深入的使用场景分析

按照语法，右值引用只能引用右值，但右值引用一定不能引用左值吗？因为：有些场景下，可能真的需要用右值去引用左值实现移动语义。**当需要用右值引用引用一个左值时，可以通过move 函数将左值转化为右值。**

C++11中，std::move()函数位于头文件中，该函数名字具有迷惑性， 它**并不搬移任何东西，唯一的功能就是将一个左值强制转化为右值引用，然后实现移动语义。**

~~~C++
template<class _Ty>
inline typename remove_reference<_Ty>::type&& move(_Ty&& _Arg) _NOEXCEPT
{
 // forward _Arg as movable
  return ((typename remove_reference<_Ty>::type&&)_Arg);
}
int main()
{
  bit::string s1("hello world");
  // 这里s1是左值，调用的是拷贝构造
  bit::string s2(s1);
  // 这里我们把s1 move处理以后, 会被当成右值，调用移动构造
  // 但是这里要注意，一般是不要这样用的，因为我们会发现s1的
  // 资源被转移给了s3，s1被置空了。
  bit::string s3(std::move(s1));
  return 0;
}
~~~

**STL容器插入接口函数也增加了右值引用版本：**

http://www.cplusplus.com/reference/list/list/push_back/ 

http://www.cplusplus.com/reference/vector/vector/push_back/

~~~C++
void push_back (value_type&& val);
int main()
{
  list<bit::string> lt;
  bit::string s1("1111");
 // 这里调用的是拷贝构造
  lt.push_back(s1);
 // 下面调用都是移动构造
  lt.push_back("2222");
  lt.push_back(std::move(s1));
  return 0;
}

//运行结果：
// string(const string& s) -- 深拷贝
// string(string&& s) -- 移动语义
// string(string&& s) -- 移动语义

~~~

![image-20221120220742758](%E5%9B%BE%E7%89%87/README/image-20221120220742758.png)



###### 完美转发

**模板中的&& 万能引用**

~~~C++
void Fun(int &x){ cout << "左值引用" << endl; }
void Fun(const int &x){ cout << "const 左值引用" << endl; }
void Fun(int &&x){ cout << "右值引用" << endl; }
void Fun(const int &&x){ cout << "const 右值引用" << endl; }
// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
template<typename T>
void PerfectForward(T&& t)
{
 //传进来的是右值引用，但t作为实参，传给fun的是作者
	Fun(t);
}
int main()
{
  PerfectForward(10);           // 右值
  int a;
  PerfectForward(a);            // 左值
  PerfectForward(std::move(a)); // 右值
  const int b = 8;
  PerfectForward(b);      // const 左值
  PerfectForward(std::move(b)); // const 右值
  return 0;
}
~~~

**std::forward 完美转发在传参的过程中保留对象原生类型属性**

~~~C++
void Fun(int &x){ cout << "左值引用" << endl; }
void Fun(const int &x){ cout << "const 左值引用" << endl; }
void Fun(int &&x){ cout << "右值引用" << endl; }
void Fun(const int &&x){ cout << "const 右值引用" << endl; }
// std::forward<T>(t)在传参的过程中保持了t的原生类型属性。
template<typename T>
void PerfectForward(T&& t)
{
 //forward会在传参时保存t的原属性
 Fun(std::forward<T>(t));
}
int main()
{
  PerfectForward(10);           // 右值
  int a;
  PerfectForward(a);            // 左值
  PerfectForward(std::move(a)); // 右值
  const int b = 8;
  PerfectForward(b);      // const 左值
  PerfectForward(std::move(b)); // const 右值
  return 0;
}
~~~

**完美转发实际中的使用场景：**

~~~C++
template<class T>
struct ListNode
{
  ListNode* _next = nullptr;
  ListNode* _prev = nullptr;
  T _data;
};
template<class T>
class List
{
	typedef ListNode<T> Node;
public:
  List()
  {
      _head = new Node;
      _head->_next = _head;
      _head->_prev = _head;
  }
  void PushBack(T&& x)
  {
      //Insert(_head, x);
      Insert(_head, std::forward<T>(x));
  }
  void PushFront(T&& x)
  {
      //Insert(_head->_next, x);
      Insert(_head->_next, std::forward<T>(x));
  }
  void Insert(Node* pos, T&& x)
  {
      Node* prev = pos->_prev;
      Node* newnode = new Node;
      newnode->_data = std::forward<T>(x); // 关键位置
      // prev newnode pos
      prev->_next = newnode;
      newnode->_prev = prev;
      newnode->_next = pos;
      pos->_prev = newnode;
  }
  void Insert(Node* pos, const T& x)
  {
      Node* prev = pos->_prev;
      Node* newnode = new Node;
      newnode->_data = x; // 关键位置
      // prev newnode pos
      prev->_next = newnode;
     newnode->_prev = prev;
      newnode->_next = pos;
      pos->_prev = newnode;
  }
private:
	Node* _head;
};
int main()
{
  List<bit::string> lt;
  lt.PushBack("1111");
  lt.PushFront("2222");
  return 0;
}
~~~



##### 新的类功能

###### 默认成员函数

原来C++类中，有6个默认成员函数： 

1. 构造函数 
2. 析构函数 
3. 拷贝构造函数 
4.  拷贝赋值重载 
5.  取地址重载 
6.  const 取地址重载 

最后重要的是前4个，后两个用处不大。默认成员函数就是我们不写编译器会生成一个默认的。 

C++11 新增了两个：移动构造函数和移动赋值运算符重载。 

针对移动构造函数和移动赋值运算符重载有一些需要注意的点如下： 

1. 如果你**没有自己实现移动构造函数，且没有实现析构函数 、拷贝构造、拷贝赋值重载中的任意一个**。那么编译器会自动生成一个默认移动构造。默认生成的移动构造函数，对于内置类 型成员会执行逐成员**按字节拷贝**，自定义类型成员，则需要看这个成员是否实现移动构造， 如果**实现了就调用移动构造，没有实现就调用拷贝构造**。 
2. 如果你**没有自己实现移动赋值重载函数，且没有实现析构函数 、拷贝构造、拷贝赋值重载中 的任意一个**，那么编译器会自动生成一个默认移动赋值。默认生成的移动构造函数，对于内置类型成员会执行逐成员**按字节拷贝**，自定义类型成员，则需要看这个成员是否实现移动赋 值，如果**实现了就调用移动赋值，没有实现就调用拷贝赋值**。(默认移动赋值跟上面移动构造完全类似) 如果你提供了移动构造或者移动赋值，编译器不会自动提供拷贝构造和拷贝赋值。

~~~C++
// 以下代码在vs2013中不能体现，在vs2019下才能演示体现上面的特性。
class Person
{
public:
     Person(const char* name = "", int age = 0)
     :_name(name)
     , _age(age)
     {}
     /*Person(const Person& p)
    :_name(p._name)
     ,_age(p._age)
     {}*/
     /*Person& operator=(const Person& p)
     {
         if(this != &p)
         {
             _name = p._name;
             _age = p._age;
         }
     	return *this;
     }*/
     /*~Person()
     {}*/
private:
     bit::string _name;
     int _age;
};
int main()
{
     Person s1;
     Person s2 = s1;
     Person s3 = std::move(s1);
     Person s4;
     s4 = std::move(s2);
     return 0;
}

~~~



###### 类成员变量初始化 

> C++11允许在类声明时给成员变量初始缺省值，默认生成构造函数会使用这些缺省值初始化，这 个我们在类和对象默认就讲了，这里就不再细讲了。 
>



###### 强制生成默认函数的关键字default

> C++11可以让你更好的控制要使用的默认函数。假设你要使用某个默认的函数，但是因为一些原因这个函数没有默认生成。比如：我们提供了拷贝构造，就不会生成移动构造了，那么我们可以 使用default关键字显示指定移动构造生成。
>

~~~C++
class Person
{
public:
  Person(const char* name = "", int age = 0)
  :_name(name)
  , _age(age)
  {}
  Person(const Person& p)
  :_name(p._name)
  ,_age(p._age)
  {}
 Person(Person&& p) = default;
private:
  bit::string _name;
  int _age;
};
int main()
{
  Person s1;
  Person s2 = s1;
  Person s3 = std::move(s1);
  return 0;
}
~~~



###### 禁止生成默认函数的关键字delete

> 如果能想要限制某些默认函数的生成，在C++98中，将该函数设置成private，并且只声明补丁，这样只要其他人想要调用就会报错（私有函数只能友元/类成员函数调用）。
>
> 在C++11中更简单，只需在该函数声明加上=delete即 可，该语法指示编译器不生成对应函数的默认版本，称=delete修饰的函数为**删除函数**。

~~~C++
class Person
{
public:
  Person(const char* name = "", int age = 0)
  :_name(name)
  , _age(age)
  {}
  Person(const Person& p) = delete;
private:
  bit::string _name;
  int _age;
};
int main()
{
  Person s1;
  Person s2 = s1;
  Person s3 = std::move(s1);
  return 0;
}
~~~



###### 继承和多态中的final与override关键字

> 继承+多态

##### 可变参数模板

> C++11的新特性可变参数模板能够让您创建可以接受可变参数的函数模板和类模板，相比 C++98/03，类模版和函数模版中只能含固定数量的模版参数，可变模版参数无疑是一个巨大的改 。然而由于可变模版参数比较抽象，使用起来需要一定的技巧，所以这块还是比较晦涩的。现阶段呢，我们掌握一些基础的可变参数模板特性就够我们用了，所以这里我们点到为止，以后大 家如果有需要，再可以深入学习。 
>

下面就是一个基本可变参数的函数模板

~~~C++
// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
template <class ...Args>
void ShowList(Args... args)
{}
~~~

上面的参数args前面有省略号，所以它就是一个可变模版参数，我们把带省略号的参数称为“参数包”，它里面包含了0到N（N>=0）个模版参数。我们无法直接获取参数包args中的每个参数的， 只能通过展开参数包的方式来获取参数包中的每个参数，这是使用可变模版参数的一个主要特 点，也是最大的难点，即如何展开可变模版参数。由于语法不支持使用args[i]这样方式获取可变 参数，所以我们的用一些奇招来一一获取参数包的值。 

**1. 递归函数方式展开参数包**

~~~C++
// 递归终止函数
template <class T>
void ShowList(const T& t)
{
	 cout << t << endl;
}
// 展开函数
template <class T, class ...Args>
void ShowList(T value, Args... args)
{
  cout << value <<" ";
  ShowList(args...);
}
int main()
{
  ShowList(1);
  ShowList(1, 'A');
  ShowList(1, 'A', std::string("sort"));
  return 0;
}
~~~

**2. 逗号表达式展开参数包**

这种展开参数包的方式，不需要通过递归终止函数，是直接在expand函数体中展开的, printarg 不是一个递归终止函数，只是一个处理参数包中每一个参数的函数。这种就地展开参数包的方式 实现的关键是逗号表达式。我们知道逗号表达式会按顺序执行逗号前面的表达式。 

expand函数中的逗号表达式：(printarg(args), 0)，也是按照这个执行顺序，先执行 printarg(args)，再得到逗号表达式的结果0。同时还用到了C++11的另外一个特性——初始化列 表，通过初始化列表来初始化一个变长数组, {(printarg(args), 0)...}将会展开成((printarg(arg1),0),  (printarg(arg2),0), (printarg(arg3),0), etc... )，最终会创建一个元素值都为0的数组int arr[sizeof...(Args)]。由于是逗号表达式，在创建数组的过程中会先执行逗号表达式前面的部分printarg(args) 打印出参数，也就是说在构造int数组的过程中就将参数包展开了，这个数组的目的纯粹是为了在 数组构造的过程展开参数包

~~~C++
template <class T>
void PrintArg(T t)
{
	cout << t << " ";
}
//展开函数
template <class ...Args>
void ShowList(Args... args)
{
	int arr[] = { (PrintArg(args), 0)... };
	cout << endl;
}
int main()
{
  ShowList(1);
  ShowList(1, 'A');
  ShowList(1, 'A', std::string("sort"));
  return 0;
}
~~~

**STL**容器中的empalce相关接口函数： 

http://www.cplusplus.com/reference/vector/vector/emplace_back/ 

http://www.cplusplus.com/reference/list/list/emplace_back/

~~~C++
template <class... Args>
void emplace_back (Args&&... args);
~~~

首先我们看到的emplace系列的接口，支持模板的可变参数，并且万能引用。那么相对insert和 emplace系列接口的优势到底在哪里呢？

~~~C++
int main()
{
  std::list< std::pair<int, char> > mylist;
  // emplace_back支持可变参数，拿到构建pair对象的参数后自己去创建对象
  // 那么在这里我们可以看到除了用法上，和push_back没什么太大的区别
  mylist.emplace_back(10, 'a');
  mylist.emplace_back(20, 'b');
  mylist.emplace_back(make_pair(30, 'c'));
  mylist.push_back(make_pair(40, 'd'));
  mylist.push_back({ 50, 'e' });
  for (auto e : mylist)
  cout << e.first << ":" << e.second << endl;
  return 0;
}

int main()
{
 // 下面我们试一下带有拷贝构造和移动构造的bit::string，再试试呢
 // 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
 // 是先构造，再移动构造，其实也还好。
  std::list< std::pair<int, bit::string> > mylist;
  mylist.emplace_back(10, "sort");
  mylist.emplace_back(make_pair(20, "sort"));
  mylist.push_back(make_pair(30, "sort"));
  mylist.push_back({ 40, "sort"});
  return 0;
}
~~~



#### lambda表达式▲

##### 前言

在C++98中，如果想要对一个数据集合中的元素进行排序，可以使用std::sort方法。

~~~C++
#include <algorithm>
#include <functional>
int main()
{
int array[] = {4,1,8,5,3,7,0,9,2,6};
// 默认按照小于比较，排出来结果是升序
std::sort(array, array+sizeof(array)/sizeof(array[0]));
// 如果需要降序，需要改变元素的比较规则
std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
return 0;
}
~~~

如果待排序元素为自定义类型，需要用户定义排序时的比较规则：

~~~C++
struct Goods
{
  string _name;  // 名字
  double _price; // 价格
  int _evaluate; // 评价
  Goods(const char* str, double price, int evaluate)
  :_name(str)
  , _price(price)
  , _evaluate(evaluate)
  {}
};
struct ComparePriceLess
{
  bool operator()(const Goods& gl, const Goods& gr)
  {
  	return gl._price < gr._price;
  }
};
struct ComparePriceGreater
{
  bool operator()(const Goods& gl, const Goods& gr)
  {
  	return gl._price > gr._price;
  }
};
int main()
{
  vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 
  3 }, { "菠萝", 1.5, 4 } };
  sort(v.begin(), v.end(), ComparePriceLess());
  sort(v.begin(), v.end(), ComparePriceGreater());
}
~~~

随着C++语法的发展，**人们开始觉得上面的写法太复杂了，每次为了实现一个algorithm算法， 都要重新去写一个类，如果每次比较的逻辑不一样，还要去实现多个类，特别是相同类的命名， 这些都给编程者带来了极大的不便**。

因此，在C++11语法中出现了Lambda表达式。

##### lambda表达式

~~~C++
int main()
{
  vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 
  3 }, { "菠萝", 1.5, 4 } };
  sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){
  return g1._price < g2._price; });
  sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){
  return g1._price > g2._price; });
  sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){
  return g1._evaluate < g2._evaluate; });
  sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2){
  return g1._evaluate > g2._evaluate; });
}
~~~

> 上述代码就是使用C++11中的lambda表达式来解决，可以看出lambda表达式实际是一个匿名函数。
>
> lambda表达式书写格式：[capture-list] (parameters) mutable -> return-type { statement  } 
>



###### 1. lambda表达式各部分说明

- [capture-list] : 捕捉列表，该列表总是出现在lambda函数的开始位置，编译器根据[]来 判断接下来的代码是否为lambda函数，捕捉列表能够捕捉上下文中的变量供lambda 函数使用。 
- (parameters)：参数列表。与普通函数的参数列表一致，如果不需要参数传递，则可以 连同()一起省略 
- mutable：默认情况下，lambda函数总是一个const函数，mutable可以取消其常量性。使用该修饰符时，参数列表不可省略(即使参数为空)。
- ->returntype：返回值类型。用追踪返回类型形式声明函数的返回值类型，没有返回值时此部分可省略。返回值类型明确情况下，也可省略，由编译器对返回类型进行推导。 
- {statement}：函数体。在该函数体内，除了可以使用其参数外，还可以使用所有捕获到的变量。

**注意：** 

> 在lambda函数定义中，**参数列表和返回值类型都是可选部分**，**而捕捉列表和函数体可以为 空。**因此C++11中**最简单的lambda函数为：[]{}**; 该lambda函数不能做任何事情。
>

~~~C++
int main()
{
    // 最简单的lambda表达式, 该lambda表达式没有任何意义
   []{}; 

    // 省略参数列表和返回值类型，返回值类型由编译器推导为int
    int a = 3, b = 4;
   [=]{return a + 3; }; 

    // 省略了返回值类型，无返回值类型
    auto fun1 = [&](int c){b = a + c; }; 
    fun1(10)
    cout<<a<<" "<<b<<endl;

    // 各部分都很完善的lambda函数
    auto fun2 = [=, &b](int c)->int{return b += a+ c; }; 
    cout<<fun2(10)<<endl;

    // 复制捕捉x
    int x = 10;
    auto add_x = [x](int a) mutable { x *= 2; return a + x; }; 
    cout << add_x(10) << endl; 
    return 0;
}
~~~

通过上述例子可以看出，lambda表达式实际上可以理解为无名函数，该函数无法直接调 用，如果想要直接调用，可借助auto将其赋值给一个变量。

###### 2. 捕获列表说明

捕捉列表描述了上下文中那些数据可以被lambda使用，以及使用的方式传值还是传引用。 

- [var]：表示值传递方式捕捉变量
- [=]：表示值传递方式捕获所有父作用域中的变量(包括this) 
- [&var]：表示引用传递捕捉变量var 
- [&]：表示引用传递捕捉所有父作用域中的变量(包括this) 
- [this]：表示值传递方式捕捉当前的this指针

注意：

- 父作用域指包含lambda函数的语句块
- 语法上捕捉列表可由多个捕捉项组成，并以逗号分割。 比如：[=, &a, &b]：以引用传递的方式捕捉变量a和b，值传递方式捕捉其他所有变量。 [&，a, this]：值传递方式捕捉变量a和this，引用方式捕捉其他变量 
- 捕捉列表不允许变量重复传递，否则就会导致编译错误。 比如：[=, a]：=已经以值传递方式捕捉了所有变量，捕捉a重复
- 在块作用域以外的lambda函数捕捉列表必须为空。 
- 在块作用域中的lambda函数仅能捕捉父作用域中局部变量，捕捉任何非此作用域或者 非局部变量都  会导致编译报错。 
- lambda表达式之间不能相互赋值，即使看起来类型相同

~~~C++
void (*PF)();
int main()
{
     auto f1 = []{cout << "hello world" << endl; };
     auto f2 = []{cout << "hello world" << endl; };
        // 此处先不解释原因，等lambda表达式底层实现原理看完后，大家就清楚了
     //f1 = f2;   // 编译失败--->提示找不到operator=()
        // 允许使用一个lambda表达式拷贝构造一个新的副本
     auto f3(f2);
     f3();
     // 可以将lambda表达式赋值给相同类型的函数指针
     PF = f2;
     PF();
     return 0;
}

~~~



#### 函数对象与lanbda表达式

函数对象，又称为仿函数，即可以想函数一样使用的对象，就是在类中重载了operator()运算符的类对象。

~~~C++
class Rate
{
public:
  Rate(double rate): _rate(rate)
  {}
  double operator()(double money, int year)
  { return money * _rate * year;}
private:
	double _rate;
};
int main()
{
 // 函数对象
  double rate = 0.49;
  Rate r1(rate);
  r1(10000, 2);
 // lamber
  auto r2 = [=](double monty, int year)->double{return monty*rate*year; 
  };
  r2(10000, 2);
  return 0;
}
~~~

从使用方式上来看，函数对象与lambda表达式完全一样。 

函数对象将rate作为其成员变量，在定义对象时给出初始值即可，lambda表达式通过捕获列表可 以直接将该变量捕获到。

![image-20221121162001217](%E5%9B%BE%E7%89%87/README/image-20221121162001217.png)

实际在底层编译器对于lambda表达式的处理方式，完全就是按照函数对象的方式处理的，

即：如 果定义了一个lambda表达式，编译器会自动生成一个类，在该类中重载了operator()。



#### 包装器与绑定

##### **function包装器** 

function包装器 也叫作适配器。

C++中的function本质是一个类模板，也是一个包装器。 那么我们来看看，我们为什么需要function呢？

~~~C++
ret = func(x);
// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
// 是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
// 为什么呢？我们继续往下看
template<class F, class T>
T useF(F f, T x)
{
  static int count = 0;
  cout << "count:" << ++count << endl;
  cout << "count:" << &count << endl;
  return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
  double operator()(double d)
  {
  	return d / 3;
  }
};
int main()
{
  // 函数名
  cout << useF(f, 11.11) << endl;
  // 函数对象
  cout << useF(Functor(), 11.11) << endl;
  // lamber表达式
  cout << useF([](double d)->double{ return d/4; }, 11.11) << endl;
  return 0;
}

//count ： 1 ， 1 ， 1
~~~

**通过上面的程序验证，我们会发现useF函数模板实例化了三份。** 

**包装器可以很好的解决上面的问题**

~~~C++
// std::function在头文件<functional>
// 类模板原型如下
template <class T> function;     // undefined
template <class Ret, class... Args>
class function<Ret(Args...)>;
模板参数说明：
Ret: 被调用函数的返回类型
Args…：被调用函数的形参
~~~

~~~C++
// 使用方法如下：
#include <functional>
int f(int a, int b)
{
	return a + b;
}
struct Functor
{
public:
  int operator() (int a, int b)
  {
  	return a + b;
  }
};
class Plus
{
public:
  static int plusi(int a, int b)
  {
  	return a + b;
  }
  double plusd(double a, double b)
  {
  	return a + b;
  }
};
int main()
{
  // 函数名(函数指针)
  std::function<int(int, int)> func1 = f;
  cout << func1(1, 2) << endl;
  // 函数对象
  std::function<int(int, int)> func2 = Functor();
  cout << func2(1, 2) << endl;
  // lamber表达式
  std::function<int(int, int)> func3 = [](const int a, const int b) 
  {return a + b; };
  cout << func3(1, 2) << endl;

  // 类的成员函数
  std::function<int(int, int)> func4 = &Plus::plusi;
  cout << func4(1, 2) << endl;
  std::function<double(Plus, double, double)> func5 = &Plus::plusd;
  cout << func5(Plus(), 1.1, 2.2) << endl;
  return 0;
}
~~~

**有了包装器，如何解决模板的效率低下，实例化多份的问题呢？**

~~~C++
#include <functional>
template<class F, class T>
T useF(F f, T x)
{
  static int count = 0;
  cout << "count:" << ++count << endl;
  cout << "count:" << &count << endl;
  return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
  double operator()(double d)
  {
 	 return d / 3;
  }
};
int main()
{
  // 函数名
  std::function<double(double)> func1 = f;
  cout << useF(func1, 11.11) << endl;
  // 函数对象
  std::function<double(double)> func2 = Functor();
  cout << useF(func2, 11.11) << endl;
  // lamber表达式
  std::function<double(double)> func3 = [](double d)->double{ return d /
  4; };
  cout << useF(func3, 11.11) << endl;
  return 0;
}

// count ： 1， 2， 3
~~~

> 将 相同作用，同一用法 的不 同类型 的 代码/lambda/仿函数 包装成同一种类型。
>
> 但调用的还是原来的。

##### bind--绑定

> std::bind函数定义在头文件中，**是一个函数模板，它就像一个函数包装器(适配器)，接受一个可调用对象（callable object），生成一个新的可调用对象来“适应”原对象的参数列表。**
>
> 一般而 言，我们用它可以把一个原本接收N个参数的函数fun，通过绑定一些参数，返回一个接收M个（M 可以大于N，但这么做没什么意义）参数的新函数。
>
> 同时，使用std::bind函数还可以实现参数顺序调整等操作。

~~~C++
// 原型如下：
template <class Fn, class... Args>
/* unspecified */ 
bind (Fn&& fn, Args&&... args);

// with return type (2) 
template <class Ret, class Fn, class... Args>  
/* unspecified */ 
bind (Fn&& fn, Args&&... args);
~~~

可以将bind函数看作是一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。 

调用bind的一般形式：auto newCallable = bind(callable,arg_list); 

其中，newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的 callable的参数。**当我们调用newCallable时，newCallable会调用callable,并传给它arg_list中 的参数。** 

arg_list中的参数可能包含形如_n的名字，其中n是一个整数，这些参数是“占位符”，表示 newCallable的参数，它们占据了传递给newCallable的参数的“位置”。数值n表示生成的可调用对 象中参数的位置：_1为newCallable的第一个参数，_2为第二个参数，以此类推。

~~~C++
// 使用举例
#include <functional>
int Plus(int a, int b)
{
	return a + b;
}
class Sub
{
public:
  int sub(int a, int b)
  {
  	return a - b;
  }
};
int main()
{
  //表示绑定函数plus 参数分别由调用 func1 的第一，二个参数指定
  std::function<int(int, int)> func1 = std::bind(Plus, placeholders::_1, 
  placeholders::_2);
  //auto func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
  //func2的类型为 function<void(int, int, int)> 与func1类型一样
  //表示绑定函数 plus 的第一，二为： 1， 2
  auto  func2 = std::bind(Plus, 1, 2);   
  cout << func1(1, 2) << endl;
  cout << func2() << endl;
  Sub s;
  // 绑定成员函数
  std::function<int(int, int)> func3 = std::bind(&Sub::sub, s, 
  placeholders::_1, placeholders::_2);
  // 参数调换顺序
     std::function<int(int, int)> func4 = std::bind(&Sub::sub, s, 
  placeholders::_2, placeholders::_1);
  cout << func3(1, 2) << endl; 
  cout << func4(1, 2) << endl;
  return 0;
}
~~~



### Hash应用

#### Hash思想

##### 哈希概念

> 顺序结构以及平衡树中，元素关键码与其存储位置之间没有对应的关系，因此在查找一个元素 时，必须要经过关键码的多次比较。
>
> 顺序查找时间复杂度为O(N)，平衡树中为树的高度，即 O($log_2 N$)，搜索的效率取决于搜索过程中元素的比较次数。 
>
> 理想的搜索方法：可以不经过任何比较，一次直接从表中得到要搜索的元素。 如果构造一种存储结构，通过某种函数(hashFunc)使元素的存储位置与它的关键码之间能够建立 一一映射的关系，那么在查找时通过该函数可以很快找到该元素。
>
> 当向该结构中： 
>
> - 插入元素 根据待插入元素的关键码，以此函数计算出该元素的存储位置并按此位置进行存放 
> - 搜索元素 对元素的关键码进行同样的计算，把求得的函数值当做元素的存储位置，在结构中按此位置 取元素比较，若关键码相等，则搜索成功 
>
> 该方式即为**哈希(散列)方法**，哈希方法中使用的**转换函数称为哈希(散列)函数**，构造出来的结构称为**哈希表(Hash Table)(或者称散列表)**

###### eg

eg：数据集合{1，7，6，4，5，9}；

哈希函数设置为：hash(key) = key % capacity; capacity为存储元素底层空间总的大小。

![image-20230305125006484](%E5%9B%BE%E7%89%87/README/image-20230305125006484.png)

用该方法进行搜索不必进行多次关键码的比较，因此搜索的速度比较快 

问题：按照上述哈希方式，向集合中插入元素44，会出现什么问题？

###### 哈希冲突

> 对于两个数据元素的关键字$k_i$和 $k_j$(i != j)，有$k_i$ != $k_j$，但有：Hash($k_i$) ==  Hash($k_j$)，
>
> 即：不同关键字通过相同哈希哈数计算出相同的哈希地址，该种现象称为**哈希冲突或哈希碰撞**。
>
> **把具有不同关键码而具有相同哈希地址的数据元素称为“同义词”。**

###### 哈希函数

> 引起哈希冲突的一个原因可能是：哈希函数设计不够合理。

哈希函数设计原则： 

- 哈希函数的定义域必须包括需要存储的全部关键码，而如果散列表允许有m个地址时，其值 域必须在0到m-1之间 
- 哈希函数计算出来的地址能均匀分布在整个空间中 
- 哈希函数应该比较简单

常见哈希函数

1. 直接定址法--(常用) 

    > 取关键字的某个线性函数为散列地址：Hash（Key）= A*Key + B 
    >
    > 优点：简单、均匀 
    >
    > 缺点：需要事先知道关键字的分布情况 
    >
    > 使用场景：适合查找比较小且连续的情况
    >
    > 面试题：[字符串中第一个只出现一次字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

2. 除留余数法--(常用) 

    > 设散列表中允许的地址数为m，取一个不大于m，但最接近或者等于m的质数p作为除数， 按照哈希函数：Hash(key) = key% p(p<=m),将关键码转换成哈希地址 .

3. 平方取中法--(了解) 

    > 假设关键字为1234，对它平方就是1522756，抽取中间的3位227作为哈希地址； 再比如关键字为4321，对它平方就是18671041，抽取中间的3位671(或710)作为哈希地址 平方取中法比较适合：不知道关键字的分布，而位数又不是很大的情况 

4. 折叠法--(了解) 

    > 折叠法是将关键字从左到右分割成位数相等的几部分(最后一部分位数可以短些)，然后将这 几部分叠加求和，并按散列表表长，取后几位作为散列地址。 折叠法适合事先不需要知道关键字的分布，适合关键字位数比较多的情况 

5. 随机数法--(了解) 

    > 选择一个随机函数，取关键字的随机函数值为它的哈希地址，即H(key) = random(key),其中 random为随机数函数。 通常应用于关键字长度不等时采用此法 

6. 数学分析法--(了解) 

    > 设有n个d位数，每一位可能有r种不同的符号，这r种不同的符号在各位上出现的频率不一定 相同，可能在某些位上分布比较均匀，每种符号出现的机会均等，在某些位上分布不均匀只 有某几种符号经常出现。可根据散列表的大小，选择其中各种符号分布均匀的若干位作为散 列地址。例如：

哈希函数设计的越精妙，产生哈希冲突的可能性就越低，但是**无法避免哈希冲突**

解决哈希冲突两种常见的方法是：**闭散列和开散列**

###### 哈希冲突解决-闭散列

> 闭散列：也叫开放定址法，当发生哈希冲突时，如果哈希表未被装满，说明在哈希表中必然还有 空位置，那么可以把key存放到冲突位置中的“下一个” 空位置中去。那如何寻找下一个空位置 呢？

1. 线性探测

    > 比如eg中的场景，现在需要插入元素44，先通过哈希函数计算哈希地址，hashAddr为4， 因此44理论上应该插在该位置，但是该位置已经放了值为4的元素，即发生哈希冲突。 
    >
    > 线性探测：**从发生冲突的位置开始，依次向后探测，直到寻找到下一个空位置为止。**
    >
    > - 插入
    >
    >     - 通过哈希函数获取待插入元素在哈希表中的位置
    >
    >     - 如果该位置中没有元素则直接插入新元素，如果该位置中有元素发生哈希冲突， 使用线性探测找到下一个空位置，插入新元素
    >
    >         ![image-20230305131838249](%E5%9B%BE%E7%89%87/README/image-20230305131838249.png)
    >
    > - 删除
    >
    >     > 采用闭散列处理哈希冲突时，不能随便物理删除哈希表中已有的元素，若直接删除元素 会影响其他元素的搜索。比如删除元素4，如果直接删除掉，44查找起来可能会受影 响。因此线性探测**采用标记的伪删除法来删除一个元素**。
    >
    > - 思考：哈希表什么情况下进行扩容？如何扩容？
    >
    >     ![image-20230305132400077](%E5%9B%BE%E7%89%87/README/image-20230305132400077.png)
    >     
    >     ~~~C++
    >     void CheckCapacity()
    >     {
    >         if(_size * 10 / _ht.capacity() >= 7)
    >        {
    >             HashTable<K, V, HF> newHt(GetNextPrime(ht.capacity));
    >             for(size_t i = 0; i < _ht.capacity(); ++i)
    >            {
    >                 if(_ht[i]._state == EXIST)
    >                     newHt.Insert(_ht[i]._val);
    >            }
    >             
    >             Swap(newHt);
    >        }
    >     ~~~
    >     
    >     线性探测优点：实现非常简单。
    >     
    >     线性探测缺点：一旦发生哈希冲突，所有的冲突连在一起，容易产生数据“堆积”，即：不同 关键码占据了可利用的空位置，使得寻找某关键码的位置需要许多次比较，导致搜索效率降 低。如何缓解呢？

2. 二次探测

    > 线性探测的缺陷是产生冲突的数据堆积在一块，这与其找下一个空位置有关系，因为找空位 置的方式就是挨着往后逐个去找，因此二次探测为了避免该问题，找下一个空位置的方法 为：$H_i$ = ($H_0$ + $i^2$ )% m, 或者：$H_i$ = ($H_0$ - $i^2$ )% m。其中：i =  1,2,3…， $H_0$是通过散列函数Hash(x)对元素的关键码 key 进行计算得到的位置，m是表 的大小。
    >
    > 即在探测后发生冲突时，下一次探测加上一个额外的数。
    >
    > 对于eg中如果要插入44，产生冲突，使用解决后的情况为：![image-20230305132800356](%E5%9B%BE%E7%89%87/README/image-20230305132800356.png)
    >
    > 研究表明：当表的长度为质数且表装载因子a不超过0.5时，新的表项一定能够插入，而且任 何一个位置都不会被探查两次。因此只要表中有一半的空位置，就不会存在表满的问题。在 搜索时可以不考虑表装满的情况，但在插入时必须确保表的装载因子a不超过0.5，如果超出 必须考虑增容。

    闭散列最大的缺陷就是空间利用率比较低，这也是哈希的缺陷。

3. 代码实现

    ~~~C++
    #pragma once
    
    #include<iostream>
    #include<string>
    #include<vector>
    using namespace std;
    
    namespace myHash_base
    {
    	enum State
    	{
    		EMPTY,//空
    		EXIST,//存在
    		DELETE//已删除
    	};
    
    	template<typename K, typename V>
    	struct HashElem
    	{
    		pair<K, V> _kv;
    		State _st = EMPTY;
    
    		HashElem()
    		{}
    
    		HashElem(const pair<K, V>& kv)
    			:_kv(kv)
    		{}
    	};
    
    	//将key转换为size_t类型
    	template<typename K>
    	struct HashToINT
    	{
    		size_t operator()(const K& key)
    		{
    			return (size_t)key;
    		}
    	};
    	//对string类型进行特化
    	template<>
    	struct HashToINT<string>
    	{
    		//BKDR思想
    		size_t operator()(const string& key)
    		{
    			size_t res = 0;
    			for (auto& ch : key)
    			{
    				res *= 131;
    				res += ch;
    			}
    
    			return res;
    		}
    	};
    
    	template<typename K, typename V, class ToINT = HashToINT<K> >
    	class HashTable
    	{
    	public:
    		bool insert(const pair<K, V>& kv)
    		{
    			if (find(kv.first))
    			{
    				return false;
    			}
    
    			//负载因子为0.7
    			if (_tab.size() == 0 || 10 * _size / _tab.size() >= 7)
    			{
    				size_t newSize = _tab.size() == 0 ? 10 : _tab.size() * 2;
    
    				HashTable<K, V, ToINT> newHT;
    				newHT._tab.resize(newSize);
    
    				//将旧表数据映射迁移到新表
    				for (auto& e : _tab)
    				{
    					if (e._st == EXIST)
    					{
    						newHT.insert(e._kv);
    					}
    				}
    
    				_tab.swap(newHT._tab);
    			}
    
    			//线性探测
    			ToINT toint;
    			size_t hashi = toint(kv.first) % _tab.size();
    			//只有状态为存在， 才不可以占用该位置
    			while (_tab[hashi]._st == EXIST)
    			{
    				hashi++;
    				hashi %= _tab.size();
    			}
    			//更新位置状态
    			_tab[hashi]._kv = kv;
    			_tab[hashi]._st = EXIST;
    			++_size;
    
    			////二次探测
    			//ToINT toint;
    			//size_t start = toint(kv.first) % _tab.size();
    			//size_t hashi = start;
    			//int i = 0;
    			////只有状态为存在， 才不可以占用该位置
    			//while (_tab[hashi]._st == EXIST)
    			//{
    			//	++i;
    			//	hashi = start + i * i;
    			//	hashi %= _tab.size();
    			//	
    			//}
    			////更新位置状态
    			//_tab[hashi]._kv = kv;
    			//_tab[hashi]._st = EXIST;
    			//++_size;
    			return true;
    
    		}
    
    		HashElem<K, V>* find(const K& key)
    		{
    			if (_tab.size() == 0)
    			{
    				return (HashElem<K, V>*)(nullptr);
    			}
    
    			ToINT toint;
    
    			size_t start = toint(key) % _tab.size();
    			size_t hashi = start;
    			int i = 0;
    
    			//当某位置为空时， 则一定不存在
    			while (_tab[hashi]._st != EMPTY)
    			{
    				//1. 当前位置为删除状态，则key可能在其后面
    				//2. 当前位置不为key， 则key可能在其后面
    				//3. 只有状态为存在， 且值为key才是存在
    				if (_tab[hashi]._st != DELETE && _tab[hashi]._kv.first == key)
    				{
    					return (HashElem<K, V>*)(&_tab[hashi]);
    				}
    
    				//线性探测
    				hashi ++;
    				hashi %= _tab.size();
    				//存在全为删除态的可能
    				if (hashi == start)
    				{
    					break;//结束
    				}
    
    				////二次探测
    				//++i;
    				//hashi = start + i * i;
    				//hashi %= _tab.size();
    				////存在全为删除态的可能
    				//if (hashi == start)
    				//{
    				//	break;//结束
    				//}
    			}
    
    			return (HashElem<K, V>*)(nullptr);
    		}
    
    		bool erase(const K& key)
    		{
    			HashElem<K, V>* ret = find(key);
    
    			if (ret)
    			{
    				ret->_st = DELETE;
    				--_size;
    				return true;
    			}
    			else
    			{
    				return false;
    			}
    		}
    
    		void Print()
    		{
    			for (size_t i = 0; i < _tab.size(); ++i)
    			{
    				if (_tab[i]._st == EXIST)
    				{
    					printf("[%d:%d] ", i, _tab[i]._kv.first);
    				}
    				else
    				{
    					printf("[%d:*] ", i);
    				}
    			}
    			cout << endl;
    		}
    	private:
    		vector<HashElem<K, V>> _tab;
    		size_t _size = 0;
    	};
    
    	void TestHT1()
    	{
    		//int a[] = { 1, 11, 4, 15, 26, 7, 44, 9 };
    		int a[] = { 1, 11, 4, 15, 26, 7, 44 };
    		HashTable<int, int> ht;
    		for (auto e : a)
    		{
    			ht.insert(make_pair(e, e));
    		}
    
    		ht.Print();
    
    		ht.erase(4);
    		cout << ht.find(44)->_kv.first << endl;
    		cout << ht.find(4) << endl;
    		ht.Print();
    
    		ht.insert(make_pair(-2, -2));
    		ht.Print();
    
    		cout << ht.find(-2)->_kv.first << endl;
    	}
    	void TestHT2()
    	{
    		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
    
    		//HashTable<string, int, HashFuncString> countHT;
    		HashTable<string, int> countHT;
    		for (auto& str : arr)
    		{
    			auto ptr = countHT.find(str);
    			if (ptr)
    			{
    				ptr->_kv.second++;
    			}
    			else
    			{
    				countHT.insert(make_pair(str, 1));
    			}
    		}
    	}
    	void TestHT3()
    	{
    		HashToINT<string> hash;
    		cout << hash("abcd") << endl;
    		cout << hash("bcad") << endl;
    		cout << hash("eat") << endl;
    		cout << hash("ate") << endl;
    		cout << hash("abcd") << endl;
    		cout << hash("aadd") << endl << endl;
    
    		cout << hash("abcd") << endl;
    		cout << hash("bcad") << endl;
    		cout << hash("eat") << endl;
    		cout << hash("ate") << endl;
    		cout << hash("abcd") << endl;
    		cout << hash("aadd") << endl << endl;
    	}
    
    }
    ~~~

    

  ###### 哈希冲突解决-开散列

> 开散列法又叫链地址法(开链法)，首先对关键码集合用散列函数计算散列地址，具有相同地 址的关键码归于同一子集合，每一个子集合称为一个桶，各个桶中的元素通过一个单链表链 接起来，各链表的头结点存储在哈希表中。
>
> <img src="%E5%9B%BE%E7%89%87/README/image-20230305133247772.png" alt="image-20230305133247772" style="zoom: 67%;" /><img src="%E5%9B%BE%E7%89%87/README/image-20230305133256239.png" alt="image-20230305133256239" style="zoom: 67%;" />
>
> 从上图可以看出，**开散列中每个桶中放的都是发生哈希冲突的元素**。

1. 代码实现

    ~~~C++
    #pragma once
    
    #include<iostream>
    #include<string>
    #include<vector>
    using namespace std;
    
    namespace myHash_bucket
    {
    
    	template<typename K, typename V>
    	struct HashNode
    	{
    		pair<K, V> _kv;
    		HashNode<K, V>* _next;
    
    		HashNode()
    		{}
    
    		HashNode(const pair<K, V>& kv)
    			:_kv(kv)
    			, _next(nullptr)
    		{}
    	};
    
    	//将key转换为size_t类型
    	template<typename K>
    	struct HashToINT
    	{
    		size_t operator()(const K& key)
    		{
    			return (size_t)key;
    		}
    	};
    	//对string类型进行特化
    	template<>
    	struct HashToINT<string>
    	{
    		//BKDR思想
    		size_t operator()(const string& key)
    		{
    			size_t res = 0;
    			for (auto& ch : key)
    			{
    				res *= 131;
    				res += ch;
    			}
    
    			return res;
    		}
    	};
    
    	template<typename K, typename V, class ToINT = HashToINT<K> >
    	class HashTable
    	{
    		typedef HashNode<K, V> Node;
    	public:
    
    		//素数表，素数作为被除数， 可以有效减少模相等，减少桶过长的问题
    		inline size_t __stl_next_prime(size_t n)
    		{
    			static const size_t __stl_num_primes = 28;
    			static const size_t __stl_prime_list[__stl_num_primes] =
    			{
    				53, 97, 193, 389, 769,
    				1543, 3079, 6151, 12289, 24593,
    				49157, 98317, 196613, 393241, 786433,
    				1572869, 3145739, 6291469, 12582917, 25165843,
    				50331653, 100663319, 201326611, 402653189, 805306457,
    				1610612741, 3221225473, 4294967291
    			};
    
    			for (size_t i = 0; i < __stl_num_primes; ++i)
    			{
    				if (__stl_prime_list[i] > n)
    				{
    					return __stl_prime_list[i];
    				}
    			}
    
    			return -1;
    		}
    
    
    		bool insert(const pair<K, V>& kv)
    		{
    			if (find(kv.first))
    			{
    				return false;
    			}
    
    			//负载因子为1,表示桶满了， 需要扩容
    			if (_size == _tab.size())
    			{	
    				//闭散列哈希表， 扩容时需要复用insert， 所以创建一个临时哈希表
    				//而开散列哈希表， 其数据节点可以进行复用，不需要复用insert，所以只需创建一个临时vector
    				vector<Node*> newTab;
    				newTab.resize(__stl_next_prime(_tab.size()), nullptr);
    
    				//将旧表数据映射迁移到新表
    				for (auto& cur : _tab)
    				{
    					if (cur == nullptr) continue;
    
    					Node* old = cur;
    
    					while (cur)
    					{
    						Node* next = cur->_next;
    
    						//头插
    						size_t hashi = cur->_kv.first % newTab.size();
    						cur->_next = newTab[hashi];
    						newTab[hashi] = cur;
    
    						cur = next;
    					}
    					
    					//置空
    					old = nullptr;
    				}
    
    				_tab.swap(newTab);
    			}
    
    			//头插
    			ToINT toint;
    			size_t hashi = toint(kv.first) % _tab.size();
    			Node* newNode = new Node(kv);
    			newNode->_next = _tab[hashi];
    			_tab[hashi] = newNode;
    			++_size;
    
    			return true;
    
    		}
    
    		Node* find(const K& key)
    		{
    			if (_tab.size() == 0)
    			{
    				return (Node*)(nullptr);
    			}
    
    			ToINT toint;
    			size_t hashi = toint(key) % _tab.size();
    			Node* cur = _tab[hashi];
    			while(cur)
    			{
    				if (cur->_kv.first == key)
    				{
    					return cur;
    				}
    				
    				cur = cur->_next;
    			}
    
    			
    
    			return (Node*)(nullptr);
    		}
    
    		bool erase(const K& key)
    		{
    			if (_tab.size() == 0)
    			{
    				return (Node*)(nullptr);
    			}
    
    			ToINT toint;
    			size_t hashi = toint(key) % _tab.size();
    			Node* prev = nullptr;
    			Node* cur = _tab[hashi];
    			while (cur)
    			{
    				if (cur->_kv.first == key)
    				{
    					break;
    				}
    
    				prev = cur;
    				cur = cur->_next;
    			}
    
    			//不存在
    			if (cur == nullptr)
    			{
    				return false;
    			}
    			else if(prev == nullptr)//为第一个
    			{
    				_tab[hashi] = cur->_next;
    				delete cur;
    				cur = nullptr;
    			}
    			else
    			{
    				prev->_next = cur->_next;
    				delete cur;
    				cur = nullptr;
    			}
    
    			return true;
    		}
    
    		void Print()
    		{
    			int i = 0;
    			for (auto cur : _tab)
    			{
    				if (cur == nullptr)
    				{
    					++i;
    					continue;
    				}
    
    				while (cur)
    				{
    					printf("[%d : %d] ", i, cur->_kv.first);
    					cur = cur->_next;
    				}
    				++i;
    			}
    		}
    	private:
    		vector<Node*> _tab;
    		size_t _size = 0;
    	};
    
    	void TestHT1()
    	{
    		int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
    		HashTable<int, int> ht;
    		for (auto e : a)
    		{
    			ht.insert(make_pair(e, e));
    		}
    
    		ht.insert(make_pair(22, 22));
    	}
    	void TestHT2()
    	{
    		int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
    		HashTable<int, int> ht;
    		for (auto e : a)
    		{
    			ht.insert(make_pair(e, e));
    		}
    		ht.Print();
    	}
    	void TestHT3()
    	{
    		int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
    		HashTable<int, int> ht;
    		for (auto e : a)
    		{
    			ht.insert(make_pair(e, e));
    		}
    
    		ht.erase(8);
    		ht.erase(4);
    		ht.Print();
    
    	}
    
    }
    ~~~

    

2. 扩容问题

    > 桶的个数是一定的，随着元素的不断插入，每个桶中元素的个数不断增多，极端情况下，可 能会导致一个桶中链表节点非常多，会影响的哈希表的性能，因此在一定条件下需要对哈希 表进行增容，那该条件怎么确认呢？
    >
    > 开散列最好的情况是：每个哈希桶中刚好挂一个节点， 再继续插入元素时，每一次都会发生哈希冲突，因此，在元素个数刚好等于桶的个数时，可 以给哈希表增容。

    ~~~C++
    void _CheckCapacity()
    {
        size_t bucketCount = BucketCount();
        if(_size == bucketCount)
       {
            HashBucket<V, HF> newHt(bucketCount);
            for(size_t bucketIdx = 0; bucketIdx < bucketCount; ++bucketIdx)
           {
                PNode pCur = _ht[bucketIdx];
                while(pCur)
               {
                    // 将该节点从原哈希表中拆出来
                    _ht[bucketIdx] = pCur->_pNext;
                    
                    // 将该节点插入到新哈希表中
                    size_t bucketNo = newHt.HashFunc(pCur->_data);
                    pCur->_pNext = newHt._ht[bucketNo];
                    newHt._ht[bucketNo] = pCur;
                    pCur = _ht[bucketIdx];
               }
           }
            
            newHt._size = _size;
            this->Swap(newHt);
       }
    }
    ~~~

    

3. 思考

    > 1. 只能存储key为整形的元素，其他类型怎么解决？
    >
    >     ~~~C++
    >     / 哈希函数采用处理余数法，被模的key必须要为整形才可以处理，此处提供将key转化为
    >     整形的方法
    >     // 整形数据不需要转化
    >     template<class T>
    >     class DefHashF
    >     {
    >     public:
    >         size_t operator()(const T& val)
    >        {
    >             return val;
    >             }
    >     };
    >     // key为字符串类型，需要将其转化为整形
    >     class Str2Int
    >     {
    >     public:
    >         size_t operator()(const string& s)
    >        {
    >             const char* str = s.c_str();
    >             unsigned int seed = 131; // 31 131 1313 13131 131313
    >             unsigned int hash = 0;
    >             while (*str)
    >            {
    >                 hash = hash * seed + (*str++);
    >            }
    >             
    >             return (hash & 0x7FFFFFFF);
    >        }
    >     };
    >     // 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
    >     template<class V, class HF>
    >     class HashBucket
    >     {
    >         // ……
    >     private:
    >         size_t HashFunc(const V& data)
    >        {
    >             return HF()(data.first)%_ht.capacity();
    >        }
    >     };
    >     ~~~
    >
    > 2.  除留余数法，最好模一个素数，如何每次快速取一个类似两倍关系的素数？
    >
    >     ~~~C++
    >     //素数表，素数作为被除数， 可以有效减少模相等，减少桶过长的问题
    >     		inline size_t __stl_next_prime(size_t n)
    >     		{
    >     			static const size_t __stl_num_primes = 28;
    >     			static const size_t __stl_prime_list[__stl_num_primes] =
    >     			{
    >     				53, 97, 193, 389, 769,
    >     				1543, 3079, 6151, 12289, 24593,
    >     				49157, 98317, 196613, 393241, 786433,
    >     				1572869, 3145739, 6291469, 12582917, 25165843,
    >     				50331653, 100663319, 201326611, 402653189, 805306457,
    >     				1610612741, 3221225473, 4294967291
    >     			};
    >     
    >     			for (size_t i = 0; i < __stl_num_primes; ++i)
    >     			{
    >     				if (__stl_prime_list[i] > n)
    >     				{
    >     					return __stl_prime_list[i];
    >     				}
    >     			}
    >     
    >     			return -1;
    >     		}
    >     ~~~
    >
    >     

4. 开散列与闭散列比较

    > **应用链地址法处理溢出，需要增设链接指针，似乎增加了存储开销。**
    >
    > 事实上： **由于开地址法必须保持大量的空闲空间以确保搜索效率，如二次探查法要求装载因子a <=  0.7，而表项所占空间又比指针大的多，所以使用链地址法反而比开地址法节省存储空间。**


​    

#### Hash应用

##### 位图

1. 面试题

    给40亿个不重复的无符号整数，没排过序。给一个无符号整数，如何快速判断一个数是否在 这40亿个数中。【腾讯】 

    1. 遍历，时间复杂度O(N) 

    2. 排序(O(NlogN))，利用二分查找: logN 

    3. 位图解决 数据是否在给定的整形数据中，结果是在或者不在，刚好是两种状态，那么可以使用一 个二进制比特位来代表数据是否存在的信息，如果二进制比特位为1，代表存在，为0 代表不存在。比如：

        ![image-20230305142308203](%E5%9B%BE%E7%89%87/README/image-20230305142308203.png)

2. 位图概念

    > 所谓位图，就是用每一位来存放某种状态，适用于海量数据，数据无重复的场景。通常是用 来判断某个数据存不存在的。

3. 代码实现

    ~~~C++
    #pragma once
    
    #include<vector>
    
    using namespace std;
    
    class bitset
    {
    public:
        bitset(size_t bitCount)
            : _bit((bitCount >> 5) + 1), _bitCount(bitCount)
        {}
        // 将which比特位置1
        void set(size_t which)
        {
            if (which > _bitCount)
                return;
            size_t index = (which >> 5);
            size_t pos = which % 32;
            _bit[index] |= (1 << pos);
        }
        // 将which比特位置0
        void reset(size_t which)
        {
            if (which > _bitCount)
                return;
            size_t index = (which >> 5);
            size_t pos = which % 32;
            _bit[index] &= ~(1 << pos);
        }
        // 检测位图中which是否为1
        bool test(size_t which)
        {
            if (which > _bitCount)
                return false;
            size_t index = (which >> 5);
            size_t pos = which % 32;
            return _bit[index] & (1 << pos);
        }
        // 获取位图中比特位的总个数
        size_t size()const { return _bitCount; }
        // 位图中比特为1的个数
        size_t Count()const
        {
            int bitCntTable[256] = {
       0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
       3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
       3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
       4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
       3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
       6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
       4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
       6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
       3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
       4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
       6, 7, 6, 7, 7, 8 };
    
            size_t size = _bit.size();
            size_t count = 0;
            for (size_t i = 0; i < size; ++i)
            {
                int value = _bit[i];
                int j = 0;
                while (j < sizeof(_bit[0]))
                {
                    unsigned char c = value;
                    count += bitCntTable[c];
                    ++j;
                    value >>= 8;
                }
            }
            return count;
        }
    private:
        vector<int> _bit;
        size_t _bitCount;
    };
    
    ~~~

    4. 应用
        1. 快速查找某个数据是否在一个集合中 
        2. 排序 + 去重 
        3. 求两个集合的交集、并集等 
        4. 操作系统中磁盘块标记

##### 布隆过滤器

###### 提出与概念

我们在使用新闻客户端看新闻时，它会给我们不停地推荐新的内容，它每次推荐时要去重，去掉 些已经看过的内容。问题来了，新闻客户端推荐系统如何实现推送去重的？ 用服务器记录了用 户看过的所有历史记录，当推荐系统推荐新闻时会从每个用户的历史记录里进行筛选，过滤掉那 些已经存在的记录。 如何快速查找呢？ 

1. 用哈希表存储用户记录，缺点：浪费空间 
2. 用位图存储用户记录，缺点：位图一般只能处理整形，如果内容编号是字符串，就无法处理 了。 
3.  将哈希与位图结合，即布隆过滤器

> **布隆过滤器**是由布隆（Burton Howard Bloom）在1970年提出的 一种紧凑型的、比较巧妙的概 率型数据结构，特点是**高效地插入和查询**，可以用来告诉你 “**某样东西一定不存在或者可能存在**”，它是用多个哈希函数，将一个数据映射到位图结构中。此种方式**不仅可以提升查询效率，也 可以节省大量的内存空间**。
>
> ![image-20230305142740038](%E5%9B%BE%E7%89%87/README/image-20230305142740038.png)
>
> https://zhuanlan.zhihu.com/p/43263751/

###### 布隆过滤器的插入

![image-20230305142817886](%E5%9B%BE%E7%89%87/README/image-20230305142817886.png)

向布隆过滤器中插入："baidu"

![image-20230305142833491](%E5%9B%BE%E7%89%87/README/image-20230305142833491.png)

###### 布隆过滤器的查找

> 布隆过滤器的思想是将一个元素用多个哈希函数映射到一个位图中，因此被映射到的位置的比特 位一定为1。所以可以按照以下方式进行查找：**分别计算每个哈希值对应的比特位置存储的是否为 零，只要有一个为零，代表该元素一定不在哈希表中，否则可能在哈希表中。** 
>
> **注意：布隆过滤器如果说某个元素不存在时，该元素一定不存在，如果该元素存在时，该元素可 能存在，因为有些哈希函数存在一定的误判。** 
>
> 比如：在布隆过滤器中查找"alibaba"时，假设3个哈希函数计算的哈希值为：1、3、7，刚好和其 他元素的比特位重叠，此时布隆过滤器告诉该元素存在，但实该元素是不存在的。

###### 布隆过滤器的删除

> **布隆过滤器不能直接支持删除工作，因为在删除一个元素时，可能会影响其他元素。**
>
> 比如：删除上图中"tencent"元素，如果直接将该元素所对应的二进制比特位置0，“baidu”元素也 被删除了，因为这两个元素在多个哈希函数计算出的比特位上刚好有重叠。 
>
> 一种支持删除的方法：将布隆过滤器中的每个比特位扩展成一个小的计数器，插入元素时给k个计 数器(k个哈希函数计算出的哈希地址)加一，删除元素时，给k个计数器减一，通过多占用几倍存储 空间的代价来增加删除操作。
>
>  缺陷： 
>
> 1. 无法确认元素是否真正在布隆过滤器中 
> 2. 存在计数回绕

###### 布隆过滤器的优点

> 1. 增加和查询元素的时间复杂度为:O(K), (K为哈希函数的个数，一般比较小)，与数据量大小无关 
> 2. 哈希函数相互之间没有关系，方便硬件并行运算 
> 3. 布隆过滤器不需要存储元素本身，在某些对保密要求比较严格的场合有很大优势
> 4. 在能够承受一定的误判时，布隆过滤器比其他数据结构有这很大的空间优势 
> 5. 数据量很大时，布隆过滤器可以表示全集，其他数据结构不能 
> 6. 使用同一组散列函数的布隆过滤器可以进行交、并、差运算

###### 布隆过滤器的缺陷

> 1. 有误判率，即存在假阳性(False Position)，即不能准确判断元素是否在集合中(补救方法：再 建立一个白名单，存储可能会误判的数据) 
> 2. 不能获取元素本身
> 3. 一般情况下不能从布隆过滤器中删除元素 
> 4. 如果采用计数方式删除，可能会存在计数回绕问题

###### 模拟实现

~~~C++
#pragma once

#include<string>

using namespace std;

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};
struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};
struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};
template<size_t N,
	size_t X = 5,
	class K = string,
	class HashFunc1 = BKDRHash,
	class HashFunc2 = APHash,
	class HashFunc3 = DJBHash>
	class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t len = X * N;
		size_t index1 = HashFunc1()(key) % len;
		size_t index2 = HashFunc2()(key) % len;
		size_t index3 = HashFunc3()(key) % len;
		/* cout << index1 << endl;
		cout << index2 << endl;
		cout << index3 << endl<<endl;*/
		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}
	bool Test(const K& key)
	{
		size_t len = X * N;
		size_t index1 = HashFunc1()(key) % len;
		if (_bs.test(index1) == false)
			return false;
		size_t index2 = HashFunc2()(key) % len;
		if (_bs.test(index2) == false)
			return false;
		size_t index3 = HashFunc3()(key) % len;
		if (_bs.test(index3) == false)
			return false;
		return true;  // 存在误判的
	}
	// 不支持删除，删除可能会影响其他值。
	void Reset(const K& key);
private:
	bitset<X* N> _bs;
};

~~~

#### 面试题

##### 哈希切割

> 给一个超过100G大小的log file, log中存着IP地址, 设计算法找到出现次数最多的IP地址？ 
>
> 与上题条件相同，如何找到top K的IP？如何直接用Linux系统命令实现？

##### 位图应用

> 1. 给定100亿个整数，设计算法找到只出现一次的整数？
> 2. 给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集？
> 3. 位图应用变形：1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数

##### 布隆过滤器

> 1. 给两个文件，分别有100亿个query，我们只有1G内存，如何找到两个文件交集？分别给出 精确算法和近似算法 
> 2. 如何扩展BloomFilter使得它支持删除元素的操作

### 线程库



### 异常▲

#### C语言传统的处理错误的方式

> 传统的错误处理机制： 
>
> 1. 终止程序，如assert，缺陷：用户难以接受。如发生内存错误，除0错误时就会终止程序。
> 2.  返回错误码，缺陷：需要程序员自己去查找对应的错误。如系统的很多库的接口函数都是通过把错误码放到errno中，表示错误 
>
> 实际中C语言基本都是使用返回错误码的方式处理错误，部分情况下使用终止程序处理非常严重的 错误。

#### C++异常概念

> 异常是一种处理错误的方式，**当一个函数发现自己无法处理的错误时就可以抛出异常，让函数的直接或间接的调用者处理这个错误。** 
>

- throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。 
- catch: 在您想要处理问题的地方，通过异常处理程序捕获异常`.catch `关键字用于捕获异 常，可以有多个catch进行捕获。 
- try: try 块中的代码标识将被激活的特定异常,它后面通常跟着一个或多个 catch 块。

如果有一个块抛出一个异常，捕获异常的方法会使用 try 和 catch 关键字。try 块中放置可能抛 出异常的代码，try 块中的代码被称为保护代码。使用 try/catch 语句的语法如下所示：

~~~C++
try
{
  // 保护的标识代码
}catch( ExceptionName e1 )
{
  // catch 块
}catch( ExceptionName e2 )
{
  // catch 块
}catch( ExceptionName eN )
{
  // catch 块
}
~~~



####  异常的使用

##### 异常的抛出和捕获

###### 异常的抛出和匹配原则

1. 异常是通过抛出对象而引发的，该**对象的类型决定了**应该激活哪个catch的处理代码。
2. 被**选中的处理代码**是调用链中**与该对象类型匹配且离抛出异常位置最近**的那一个。 
3. 抛出异常对象后，会生成一个**异常对象的拷贝**，因为抛出的异常对象可能是一个临时对象， 所以会生成一个拷贝对象，这个拷贝的临时对象会在被catch以后销毁。（这里的处理类似 于函数的传值返回） 
4. catch(...)可以捕获**任意类型的异常**，问题是不知道异常错误是什么。 
5. 实际中抛出和捕获的匹配原则有个**例外**，并不都是类型完全匹配，可以**抛出的派生类对象， 使用基类捕获**，这个在实际中非常实用，我们后面会详细讲解这个（继承+多态）。

###### 在函数调用链中异常栈展开匹配原则

1. 首先检查throw本身是否在try块内部，如果是再查找匹配的catch语句。如果有匹配的，则调到catch的地方进行处理。 
2. 没有匹配的catch则退出当前函数栈，继续在调用函数的栈中进行查找匹配的catch。 
3. 如果到达main函数的栈，依旧没有匹配的，则终止程序。上述这个沿着调用链查找匹配的 catch子句的过程称为栈展开。所以实际中我们最后都要加一个catch(...)捕获任意类型的异 常，否则当有异常没捕获，程序就会直接终止。 
4. 找到匹配的catch子句并处理以后，会继续沿着catch子句后面继续执行。

![image-20221121170158156](%E5%9B%BE%E7%89%87/README/image-20221121170158156.png)

~~~C++
double Division(int a, int b)
{
    // 当b == 0时抛出异常
 if (b == 0)
   throw "Division by zero condition!";
    else
        return ((double)a / (double)b);
}
void Func()
{
     int len, time;
     cin >> len >> time;
     cout << Division(len, time) << endl;
}
int main()
{
     try 
     {
     	Func();
     }
     catch (const char* errmsg） 
     {
     	cout << errmsg << endl;
     }
     catch(...){
        cout<<"unkown exception"<<endl;           
     }
     return 0;
}
~~~



##### 异常的重新抛出

有可能单个的catch不能完全处理一个异常，在进行一些校正处理以后，希望再交给更外层的调用链函数来处理，catch则可以通过重新抛出将异常传递给更上层的函数进行处理。

~~~C++
double Division(int a, int b)
{
// 当b == 0时抛出异常
if (b == 0)
{
	 throw "Division by zero condition!";
}
return (double)a / (double)b;
}
void Func()
{
  // 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
  // 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
  // 重新抛出去。
  int* array = new int[10];
  try 
  {
      int len, time;
      cin >> len >> time;
      cout << Division(len, time) << endl;
  }
  catch (...)
  {
      cout << "delete []" << array << endl;
      delete[] array;
      throw;
  }
  // ...
  cout << "delete []" << array << endl;
  delete[] array;
}
int main()
{
  try
  {
  	Func();
  }
  catch (const char* errmsg)
  {
  	cout << errmsg << endl;
  }
  return 0;
}
~~~

> **非 常 地 抽 象**

#### 异常安全

- **构造函数完成对象的构造和初始化**，**最好不要**在构造函数中抛出异常，否则**可能导致对象不完整或没有完全初始化** 
- **析构函数主要完成资源的清理，最好不要**在析构函数内抛出异常，否则可能导致资源泄漏(内 存泄漏、句柄未关闭等) 
- **C++中异常经常会导致资源泄漏**的问题，比如在new和delete中抛出了异常，导致内存泄 漏，在lock和unlock之间抛出了异常导致死锁，C++经常使用RAII来解决以上问题，关于RAII 我们智能指针这节进行讲解。

#### 异常规范

1. 异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 可以在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型。 
2. 函数的后面接throw()，表示函数不抛异常。 
3. 若无异常接口声明，则此函数可以抛掷任何类型的异常。

~~~C++
// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
void fun() throw(A，B，C，D);
// 这里表示这个函数只会抛出bad_alloc的异常
void* operator new (std::size_t size) throw (std::bad_alloc);
// 这里表示这个函数不会抛出异常
void* operator delete (std::size_t size, void* ptr) throw();
// C++11 中新增的noexcept，表示不会抛异常
thread() noexcept;
thread (thread&& x) noexcept;
~~~



#### 自定义异常体系

> 实际使用中很多公司都会自定义自己的异常体系进行规范的异常管理，因为一个项目中如果大家 随意抛异常，那么外层的调用者基本就没办法玩了，所以实际中都会定义一套继承的规范体系。 这样大家抛出的都是继承的派生类对象，捕获一个基类就可以了
>

![image-20221121203926757](%E5%9B%BE%E7%89%87/README/image-20221121203926757.png)

~~~C++
// 服务器开发中通常使用的异常继承体系
class Exception
{
public:
  Exception(const string& errmsg, int id)
  :_errmsg(errmsg)
  ,_id(id)
  {}
  virtual string what() const
  {
      return _errmsg;
  }
protected:
  string _errmsg;
  int _id;
};
class SqlException : public Exception
{
public:
  SqlException(const string& errmsg, int id, const string& sql)
  :Exception(errmsg, id)
  , _sql(sql)
  {}
  virtual string what() const
  {
      string str = "SqlException:";
      str += _errmsg;
      str += "->";
      str += _sql;
      return str;
  }
private:
	const string _sql;
};
class CacheException : public Exception
{
public:
  CacheException(const string& errmsg, int id)
  :Exception(errmsg, id)
  {}
  virtual string what() const
  {
      string str = "CacheException:";
      str += _errmsg;
      return str;
  }
};
class HttpServerException : public Exception
{
public:
  HttpServerException(const string& errmsg, int id, const string& type)
  :Exception(errmsg, id)
  , _type(type)
  {}
  virtual string what() const
  {
      string str = "HttpServerException:";
      str += _type;
      str += ":";
      str += _errmsg;
      return str;
  }
private:
	const string _type;
};
void SQLMgr()
{
srand(time(0));
if (rand() % 7 == 0)
{
	throw SqlException("权限不足", 100, "select * from name = '张三'");
}
//throw "xxxxxx";
}
void CacheMgr()
{
  srand(time(0));
  if (rand() % 5 == 0)
  {
  	throw CacheException("权限不足", 100);
  }
  else if (rand() % 6 == 0)
  {
  	throw CacheException("数据不存在", 101);
  }
  SQLMgr();
}
void HttpServer()
{
  // ...
  srand(time(0));
  if (rand() % 3 == 0)
  {
  	throw HttpServerException("请求资源不存在", 100, "get");
  }
  else if (rand() % 4 == 0)
  {
  	throw HttpServerException("权限不足", 101, "post");
  }
  CacheMgr();
}
int main()
{
  while (1)
  {
      this_thread::sleep_for(chrono::seconds(1));
      try
      {
          HttpServer();
      }
      catch (const Exception& e) // 这里捕获父类对象就可以
      {
          // 多态
          cout << e.what() << endl;
      }
      catch (...)
      {
          cout << "Unkown Exception" << endl;
      }
  }
  return 0;
}
~~~



#### C++标准库的异常体系

> C++ 提供了一系列标准的异常，定义在std中，我们可以在程序中使用这些标准的异常。它们是以父 子类层次结构组织起来的，如下所示：
>

![image-20221121204319127](%E5%9B%BE%E7%89%87/README/image-20221121204319127.png)

![image-20221121204338057](%E5%9B%BE%E7%89%87/README/image-20221121204338057.png)

**说明：**实际中我们可以可以去继承exception类实现自己的异常类。但是实际中很多公司像上面一 样自己定义一套异常继承体系。因为C++标准库设计的不够好用。

~~~C++
int main()
{
  try
  {
      vector<int> v(10, 5);
      // 这里如果系统内存不够也会抛异常
      v.reserve(1000000000);
      // 这里越界会抛异常
      v.at(10) = 100; 
  }
  catch (const exception& e) // 这里捕获父类对象就可以
  {
  	cout << e.what() << endl;
  }
  catch (...)
  {
  	cout << "Unkown Exception" << endl;
  }
  return 0;
}
~~~



#### 异常的优缺点▲

##### C++异常的优点：

1. 异常对象定义好了，相比错误码的方式可以清晰准确的展示出错误的各种信息，甚至可以包 含堆栈调用的信息，这样可以帮助更好的定位程序的bug。

2. 返回错误码的传统方式有个很大的问题就是，在函数调用链中，深层的函数返回了错误，那 么我们得层层返回错误，最外层才能拿到错误，具体看下面的详细解释。

    ~~~C++
    // 1.下面这段伪代码我们可以看到ConnnectSql中出错了，先返回给ServerStart，ServerStart再返回给main函数，main函数再针对问题处理具体的错误。
      // 2.如果是异常体系，不管是ConnnectSql还是ServerStart及调用函数出错，都不用检查，因为抛出的异常异常会直接跳到main函数中catch捕获的地方，main函数直接处理错误。
    int ConnnectSql()
    {
        // 用户名密码错误
        if (...)
            return 1;
    
        // 权限不足
        if (...)
            return 2;
    }
    
    int ServerStart() 
    {
        if (int ret = ConnnectSql() < 0)
            return ret;
        int fd = socket();
        if（fd < 0）
            return errno;
    }
    
    int main()
    {
        if(ServerStart()<0)
            ...
    
         return 0;
    }
    ~~~

3. 很多的第三方库都包含异常，比如boost、gtest、gmock等等常用的库，那么我们使用它们也需要使用异常。 

4. 部分函数使用异常更好处理，比如构造函数没有返回值，不方便使用错误码方式处理。比如 T& operator这样的函数，如果pos越界了只能使用异常或者终止程序处理，没办法通过返回 值表示错误。



##### C++异常的缺点：

1. 异常会导致程序的执行流乱跳，并且非常的混乱，并且是运行时出错抛异常就会乱跳。这会 导致我们跟踪调试时以及分析程序时，比较困难。
2. 异常会有一些性能的开销。当然在现代硬件速度很快的情况下，这个影响基本忽略不计。
3.  C++没有垃圾回收机制，资源需要自己管理。有了异常非常容易导致内存泄漏、死锁等异常 安全问题。这个需要使用RAII来处理资源的管理问题。学习成本较高。
4.  C++标准库的异常体系定义得不好，导致大家各自定义各自的异常体系，非常的混乱。 
5. 异常尽量规范使用，否则后果不堪设想，随意抛异常，外层捕获的用户苦不堪言。所以异常 规范有两点 
    - 抛出异常类型都继承自一个基类。
    - 函数是否抛异常、抛什么异常，都 使用 func()，throw();的方式规范化。

> **总结：**异常总体而言，利大于弊，所以工程中我们还是鼓励使用异常的。另外OO的语言基本都是 用异常处理错误，这也可以看出这是大势所趋。

------

### 智能指针▲▲▲

#### 智能指针的产生原因

下面我们先分析一下下面这段程序有没有什么内存方面的问题？

提示一下：注意分析Func函数中的问题。

~~~C++
int div()
{
  int a, b;
  cin >> a >> b;
  if (b == 0)
  	throw invalid_argument("除0错误");
  return a / b;
}
void Func()
{
 // 1、如果p1这里new 抛异常会如何？
 // 2、如果p2这里new 抛异常会如何？
 // 3、如果div调用这里又会抛异常会如何？
  int* p1 = new int;
  int* p2 = new int;
  cout << div() << endl;
  delete p1;
  delete p2;
}
int main()
{
  try
  {
  	Func();
  }
  catch (exception& e)
  {
  	cout << e.what() << endl;
 }
  return 0;
}
~~~

问题分析：上面的问题分析出来我们发现有什么问题？

~~~
p1，p2申请的资源未能正常是否
~~~

> **智能指针就是用来解决此类问题的**

#### 智能指针思想

##### RAII思想

> RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的简单技术。
> 在对象构造时获取资源，接着控制对资源的访问使之在对象的生命周期内始终保持有效，**最后在对象析构的时候释放资源**。借此，我们实际上把管理一份资源的责任托管给了一个对象。这种做法有两大好处：
>
> - 不需要显式地释放资源。
> - 采用这种方式，对象所需的资源在其生命期内始终保持有效。
>

~~~C++
// 使用RAII思想设计的SmartPtr类
template<class T>
class SmartPtr {
public:
    SmartPtr(T* ptr = nullptr)
       : _ptr(ptr)
   {}
    ~SmartPtr()
   {
        if(_ptr)
            delete _ptr;
   }

private:
    T* _ptr;
};
int div()
{
 int a, b;
 cin >> a >> b;
 if (b == 0)
 	throw invalid_argument("除0错误");
 return a / b;
}
void Func()
{
 	SmartPtr<int> sp1(new int);
    SmartPtr<int> sp2(new int);
 	cout << div() << endl;
}
int main()
{
    try {
 Func();
   }
    catch(const exception& e)
   {
        cout<<e.what()<<endl;
   }
 return 0;
}
~~~



##### 智能指针原理

> 上述的SmartPtr还不能将其称为智能指针，因为它还不具有指针的行为。指针可以解引用，也可以通过->去访问所指空间中的内容，因此：**AutoPtr模板类中还得需要将* 、->重载下，才可让其 像指针一样去使用。**
>

~~~C++
template<class T>
class SmartPtr {
public:
SmartPtr(T* ptr = nullptr)
  : _ptr(ptr)
{}
~SmartPtr()
{
  if(_ptr)
      delete _ptr;
}
T& operator*() {return *_ptr;}
T* operator->() {return _ptr;}
private:
T* _ptr;
};
struct Date
{
 int _year;
int _month;
int _day;
};
int main()
{
SmartPtr<int> sp1(new int);
*sp1 = 10
cout<<*sp1<<endl;
SmartPtr<int> sparray(new Date);
// 需要注意的是这里应该是sparray.operator->()->_year = 2018;
// 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
sparray->_year = 2018;
sparray->_month = 1;
sparray->_day = 1;
}
~~~

**总结一下智能指针的原理：** 

1. RAII特性 
2. 重载operator*和opertaor->，具有像指针一样的行为。

#### 智能指针的使用及实现；

##### std::auto_ptr

> auto_ptr的实现原理：管理权转移的思想

https://cplusplus.com/reference/memory/auto_ptr/

C++98版本的库中就提供了auto_ptr的智能指针。下面演示的auto_ptr的使用及问题。

下面简化模拟实现了一份bit::auto_ptr来了解它的原理

~~~C++
// C++98 管理权转移 auto_ptr
namespace autoPtr
{
	template<class T>
	class my_auto_ptr
	{
	public:
		my_auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		my_auto_ptr(my_auto_ptr<T>& autoPtr)
			:_ptr(autoPtr._ptr)
		{
			autoPtr._ptr = nullptr;//将autoPtr的资源，转移给*this
		}
		my_auto_ptr<T>& operator=(my_auto_ptr<T>& autoPtr)
		{
			//检测是否自己给自己赋值
			if (this != &autoPtr)
			{
				//检测当前智能指针是否有资源---1
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = autoPtr._ptr;
				autoPtr._ptr = nullptr; // --2

				/* 如果没有检测自己给自己赋值
				* 第一个语句会将管理的资源释放
				* 第二个语句会将资源指针置空
				* 则原先那份资源被释放，泄露了
				*/
			}
		}

		~my_auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}
		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;

	};

	void func1()
	{
		my_auto_ptr<int> sp1(new int);
		my_auto_ptr<int> sp2(sp1); // 管理权转移

		// sp1悬空
		*sp2 = 10;
		cout << *sp2 << endl;
		//cout << *sp1 << endl; *sp1 == *nullptr
	}
}
~~~

> 结论：禁止使用auto_ptr

##### std::unique_ptr

> C++11中开始提供更靠谱的unique_ptr 
>
> unique_ptr的实现原理：**简单粗暴的防拷贝，下面简化模拟实现了一份UniquePtr来了解它的原 理**

https://cplusplus.com/reference/memory/unique_ptr/

~~~C++
// C++11出来之前，boost搞除了更好用的scoped_ptr/shared_ptr/weak_ptr
// C++11将boost库中智能指针精华部分吸收了过来
// C++11->unique_ptr/shared_ptr/weak_ptr

// 原理：简单粗暴 -- 防拷贝

namespace uniquePtr
{
	template<class T>
	class my_unique_ptr
	{
	public:
		my_unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~my_unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}
		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		my_unique_ptr(const my_unique_ptr<T>& sp) = delete;
		my_unique_ptr<T>& operator=(const my_unique_ptr<T>& sp) = delete;
	private:
		T* _ptr;
	};
}
void func1()
{
    uniquePtr::my_unique_ptr<int> sp1(new int);
    //uniquePtr::my_unique_ptr<int> sp2(sp1);

    std::unique_ptr<int> sp11(new int);
    //std::unique_ptr<int> sp2(sp1);
}
~~~

> 结论：简单粗暴

##### shared_ptr + weak_ptr

###### 使用

> C++11中开始提供更靠谱的并且支持拷贝的shared_ptr 
>
> shared_ptr的原理：是通过引用计数的方式来实现多个shared_ptr对象之间共享资源。
>
> https://cplusplus.com/reference/memory/shared_ptr/
>

1. shared_ptr在其内部，给**每个资源都维护了着一份计数，用来记录该份资源被几个对象共享**。 
2. 在**对象被销毁时(也就是析构函数调用)**，就说明自己不使用该资源了，对象的引用计数减 一。
3. 如果**引用计数是0**，就说明自己是最后一个使用该资源的对象，**必须释放该资源**； 
4. 如果**不是0**，就说明除了自己还有其他对象在使用该份资源，不能释放该资源，否则其他对象就成野指针了。
5. 为什么不能使用静态变量计数?

    > 因为，静态成员属于整个类，但计数是相对于资源即变量来说的，而静态成员是相对于类型来说的，同类型的不同资源使用的是同一个计数变量，不符合不同资源不同计数变量的要求

> weak_ptr的原理：向shared_ptr借使用权，不参与资源的管理，不会增加引用计数

1. 只使用，不负责
2. 解决shared_ptr的循环引用问题
3. weak_ptr和shared_ptr可以互相引用，weak_ptr作为辅助型指针使用，没有使用RAII思想

~~~C++
// 引用计数支持多个拷贝管理同一个资源，最后一个析构对象释放资源
namespace sharedPtr
{
    template<class T>
    class my_shared_ptr
    {
    public:
        my_shared_ptr(T* ptr = nullptr)
            :_ptr(ptr)
            , _pRefCount(new int(1))
            , _pmtx(new mutex)
        {}
        my_shared_ptr(const my_shared_ptr<T>& sp)
            :_ptr(sp._ptr)
            , _pRefCount(sp._pRefCount)
            , _pmtx(sp._pmtx)
        {
            AddRef();
        }
        void Release()
        {
            _pmtx->lock();
            bool flag = false;
            if (--(*_pRefCount) == 0 && _ptr)
            {
                cout << "delete:" << _ptr << endl;
                delete _ptr;
                delete _pRefCount;
                flag = true;
            }
            _pmtx->unlock();
            if (flag == true)
            {
                delete _pmtx;
            }
        }
        void AddRef()
        {
            _pmtx->lock();
            ++(*_pRefCount);
            _pmtx->unlock();
        }
        my_shared_ptr<T>& operator=(const my_shared_ptr<T>& sp)
        {
            //if (this != &sp) //不同的智能指针，可能指向同一份资源，用资源指针判断合理
            if (_ptr != sp._ptr)//如果不是同一份资源
            {
                Release();
                _ptr = sp._ptr;
                _pRefCount = sp._pRefCount;
                _pmtx = sp._pmtx;
                AddRef();
            }
            return *this;
        }
        int use_count()
        {
            return *_pRefCount;
        }
        ~my_shared_ptr()
        {
            Release();
        }
        // 像指针一样使用
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }
        T* get() const
        {
            return _ptr;
        }
    private:
        T* _ptr;
        int* _pRefCount;
        mutex* _pmtx;
    };

    // 简化版本的weak_ptr实现
    template<class T>
    class weak_ptr
    {
    public:
        weak_ptr()
            :_ptr(nullptr)
        {}
        weak_ptr(const shared_ptr<T>& sp)
            :_ptr(sp.get())
        {}
        weak_ptr<T>& operator=(const my_shared_ptr<T>& sp)
        {
            _ptr = sp.get();
            return *this;
        }
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }
    private:
        T* _ptr;
    };


    void func1()
    {

        my_shared_ptr<int> sp1(new int);// 语句1
        my_shared_ptr<int> sp2(sp1);
        my_shared_ptr<int> sp3(sp1);

        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;

        my_shared_ptr<int> sp4(new int);// 语句2
        my_shared_ptr<int> sp5(sp4);

        cout << sp4.use_count() << ' ' << sp5.use_count() << endl;

        sp1 = sp1;
        cout << sp1.use_count() << ' ' << sp3.use_count() << endl;
        sp1 = sp2;
        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;

        sp1 = sp4;
        cout << sp3.use_count() << ' ' << sp4.use_count() << endl;
        sp2 = sp4;
        cout << sp1.use_count() << ' ' << sp2.use_count() << ' ' << sp3.use_count() << endl;
        sp3 = sp4;// 此时 语句1 生成的资源 使用者为0 触发释放条件
        cout << sp1.use_count() << ' ' << sp4.use_count() << ' ' << sp3.use_count() << endl;

        *sp1 = 2;
        *sp2 = 3;

        // 函数结束时，智能指针全部析构了， 释放 语句2 生成的资源
    }
}
~~~

###### std::shared_ptr的线程安全问题 

通过下面的程序我们来测试shared_ptr的线程安全问题。需要注意的是shared_ptr的线程安全分为两方面： 

1. 智能指针对象中引用计数是多个智能指针对象共享的，两个线程中智能指针的引用计数同时 ++或--，这个操作不是原子的，引用计数原来是1，++了两次，可能还是2。这样引用计数就错乱了。会导致资源未释放或者程序崩溃的问题。所以只能指针中引用计数++、--是需要加锁的，也就是说引用计数的操作是线程安全的。 
2. 智能指针管理的对象存放在堆上，两个线程中同时去访问，会导致线程安全问题。

~~~C++
// 1.演示引用计数线程安全问题，就把AddRefCount和SubRefCount中的锁去掉
// 2.演示可能不出现线程安全问题，因为线程安全问题是偶现性问题，main函数的n改大一些概率就变大了，就容易出现了。
// 3.下面代码我们使用SharedPtr演示，是为了方便演示引用计数的线程安全问题，将代码中的SharedPtr换成shared_ptr进行测试，可以验证库的shared_ptr，发现结论是一样的。
struct Date
{
    int _year = 0;
    int _month = 0;
    int _day = 0;
};
void SharePtrFunc(bit::shared_ptr<Date>& sp, size_t n, mutex& mtx)
{
    cout << sp.get() << endl;
    for (size_t i = 0; i < n; ++i)
    {
        // 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
        bit::shared_ptr<Date> copy(sp);
        // 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并不一定是加了2n
        {
            unique_lock<mutex> lk(mtx);
            copy->_year++;
            copy->_month++;
            copy->_day++;
        }
    }
}
int main()
{
    bit::shared_ptr<Date> p(new Date);
    cout << p.get() << endl;
    const size_t n = 100000;
    mutex mtx;
    thread t1(SharePtrFunc, std::ref(p), n, std::ref(mtx));
    thread t2(SharePtrFunc, std::ref(p), n, std::ref(mtx));
    t1.join();
    t2.join();
    cout << p->_year << endl;
    cout << p->_month << endl;
    cout << p->_day << endl;
    cout << p.use_count() << endl;
    return 0;
}
~~~

###### std::shared_ptr的循环引用

~~~C++
struct ListNode
{
    int _data;
    my_shared_ptr<ListNode> _prev;
    my_shared_ptr<ListNode> _next;
    ~ListNode() { cout << "~ListNode()" << endl; }
};
int main()
{
    my_shared_ptr<ListNode> node1(new ListNode);
    my_shared_ptr<ListNode> node2(new ListNode);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    node1->_next = node2;
    node2->_prev = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
~~~

循环引用分析： 

1. node1和node2两个智能指针对象指向两个节点，引用计数变成1，我们不需要手动 delete。
2.  node1的_next指向node2，node2的_prev指向node1，引用计数变成2。 
3.  node1和node2析构，引用计数减到1，但是_next还指向下一个节点。但是_prev还指向上 一个节点。 
4. 也就是说_next析构了，node2就释放了。 
5. _也就是说_prev析构了，node1就释放了。 
6. 但是_next属于node的成员，node1释放了，_next才会析构，而node1由_prev管理，_prev 属于node2成员，所以这就叫循环引用，谁也不会释放。

![image-20221206215000656](%E5%9B%BE%E7%89%87/README/image-20221206215000656.png)

![image-20221203212218744](%E5%9B%BE%E7%89%87/README/image-20221203212218744.png)

~~~C++
// 解决方案：在引用计数的场景下，把节点中的_prev和_next改成weak_ptr就可以了
// 原理就是，node1->_next = node2;和node2->_prev = node1;时weak_ptr的_next和_prev不会增加node1和node2的引用计数。

struct ListNode
{
    int _data;
    my_weak_ptr<ListNode> _prev;
    my_weak_ptr<ListNode> _next;
    ~ListNode() { cout << "~ListNode()" << endl; }
};
int main()
{
    my_shared_ptr<ListNode> node1(new ListNode);
    my_shared_ptr<ListNode> node2(new ListNode);
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    node1->_next = node2;
    node2->_prev = node1;
    cout << node1.use_count() << endl;
    cout << node2.use_count() << endl;
    return 0;
}
~~~

###### 定制删除器

**如果不是new出来的对象如何通过智能指针管理呢？其实shared_ptr设计了一个删除器来解决这 个问题（ps：删除器这个问题我们了解一下**）

new出来的可以通过析构函数操作，malloc需要自己调用free

~~~C++
// 仿函数的删除器
template<class T>
struct FreeFunc {
    void operator()(T* ptr)
    {
        cout << "free:" << ptr << endl;
        free(ptr);
    }
};
template<class T>
struct DeleteArrayFunc {
    void operator()(T* ptr)
    {
        cout << "delete[]" << ptr << endl;
        delete[] ptr;
    }
};
int main()
{
    FreeFunc<int> freeFunc;
    std::shared_ptr<int> sp1((int*)malloc(4), freeFunc);
    DeleteArrayFunc<int> deleteArrayFunc;
    std::shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);


    std::shared_ptr<A> sp4(new A[10], [](A* p) {delete[] p; });
    std::shared_ptr<FILE> sp5(fopen("test.txt", "w"), [](FILE* p)
        {fclose(p); });

    return 0;
}
~~~

> **定制删除器即构造智能指针对象时，指定析构资源的方式**

###### 再谈new与delete

![image-20221203223921978](%E5%9B%BE%E7%89%87/README/image-20221203223921978.png)

- delete和delete[] 底层都是调用 op delete(), 而op delete()是调用析构函数 + free， 若不存在析构函数，delete 和 delete[] 都只是调用 free， 所以对于内置类型， vs平台(以下都是vs平台)new和delete不匹配不会报错 。
- 但对于自定义类型，是需要析构函数的，对于new[]，调用op new时， **op new知道[]中的参数**，因此调用参数次的构造函数，但对于析构函数，delete[]中并不存在参数，不知道调用几次析构函数。所以，new[]在申请空间时，会在实际空间的头部**额外申请四个字节空间用来保存变量个数**，
- new[]返回的是实际需要的空间的地址+ 4，delete[]时，会找到存放个数的空间，读取内容后正确调用够析构函数。
- 也就是说，**new申请的是实际大小的空间，返回实际需要空间的地址，一次析构函数**
- new[]申请的是实际大小 + 4的空间，返回的也是实际需要空间的地址，n次析构函数
- delete会**直接调用一次析构函数**，释放ptr的空间
- 而delete[]会**先去头部读取个数**，再调用实际次数的析构函数，再释放实际大小+4的空间



#### C++11和boost中智能指针的关系

> 1. C++ 98 中产生了第一个智能指针auto_ptr. 
> 2. C++ boost给出了更实用的scoped_ptr和shared_ptr和weak_ptr. 
> 3. C++ TR1，引入了shared_ptr等。不过注意的是TR1并不是标准版。 
> 4. C++ 11，引入了unique_ptr和shared_ptr和weak_ptr。需要注意的是unique_ptr对应boost 的scoped_ptr。并且这些智能指针的实现原理是参考boost中的实现的。

#### 智能指针面试问题

![image-20221204095024459](%E5%9B%BE%E7%89%87/README/image-20221204095024459.png)

### 内存泄漏

####  什么是内存泄漏，内存泄漏的危害

> 什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内 存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对 该段内存的控制，因而造成了内存的浪费。 
>
> 内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现 内存泄漏会导致响应越来越慢，最终卡死。
>

~~~C++
void MemoryLeaks()
{
// 1.内存申请了忘记释放
int* p1 = (int*)malloc(sizeof(int));
int* p2 = new int;

// 2.异常安全问题
int* p3 = new int[10];

Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.

delete[] p3;
}
~~~



#### 内存泄漏分类（了解）

C/C++程序中一般我们关心两种方面的内存泄漏：

- **堆内存泄漏(Heap leak)** 

~~~c++
堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一 块内存，用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分 内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak。
~~~

- **系统资源泄漏** 

~~~C++
指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放 掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定。
~~~

#### 如何检测内存泄漏（了解）

- 在linux下内存泄漏检测：[(15条消息) Linux下几款C++程序中的内存泄露检查工具_CHENG Jian的博客-CSDN博客](https://blog.csdn.net/gatieme/article/details/51959654)
- 在windows下使用第三方工具：[(15条消息) VS编程内存泄漏：VLD(Visual LeakDetector)内存泄露库_波波在学习的博客-CSDN博客](https://blog.csdn.net/GZrhaunt/article/details/56839765)
- 其他工具：[内存泄露检测工具比较 - 默默淡然 - 博客园 (cnblogs.com)](https://www.cnblogs.com/liangxiaofeng/p/4318499.html)

#### 如何避免内存泄漏

- 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps： 这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题。需要下一条智 能指针来管理才有保证。
-  采用RAII思想或者智能指针来管理资源。
- 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项。 
- 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵。
- 总结一下: 内存泄漏非常常见，解决方案分为两种：1、事前预防型。如智能指针等。2、事后查错型。如泄 漏检测工具。

### 特殊类设计

#### 不能被拷贝的类

> 这里的拷贝是广义上的拷贝，是不能把整个对象的内容拷贝给另一个对象，则拷贝只会发生在拷贝构造和赋值中
>
> 因此，想要让一个类禁止拷贝，**只需要让该类的拷贝构造函数和赋值运算符重载不能被调用**即可

**C++98**

> 将拷贝构造函数与赋值运算符重载只声明不定义，并且将其访问权限设置为私有。
>
> 则外界无法调用私有成员函数，但类内仍允许，因为函数没有实体，会报错。

~~~C++
class CopyBan
{
    // ...
    
private:
    CopyBan(const CopyBan&);
    CopyBan& operator=(const CopyBan&);
    //...
};
~~~

**C++11**

> C++11扩展delete的用法，delete除了释放new申请的资源外，如果在默认成员函数后跟上=delete，表示禁止编译器生成该默认成员函数。则类内不存在拷贝构造函数和赋值运算符重载。

~~~c++
class CopyBan
{
    // ...
    CopyBan(const CopyBan&)=delete;
    CopyBan& operator=(const CopyBan&)=delete;
    //...
};
~~~



#### 只能在堆上创建对象

1. 将析构函数私有化

    > 栈上创建对象时，构造函数和析构函数都是由系统调用的，若私有化析构函数，则无法去调用析构函数，无法释放栈空间，就无法在栈上创建对象。这个方法禁止了栈上和静态区调用对象，但在堆上创建对象时，需要提供一个额外的公有函数‘手动’释放资源，如公有调用析构，公有直接释放。

    ~~~C++
    class HeapOnly
    {
    public:
        void DeleteHeap()//1
        {
            delete this;//类内可调用析构
        }
    
        static void s_DeleteHeap(HeapOnly* p)//2
        {
            delete p;//类内可调用析构
        }
        
    private:
        ~HeapOnly()
        {
            cout << "~HeapOnly" << endl;
        }
    };
    
    int main()
    {
        //HeapOnly ho;
    
        HeapOnly* ho1 = new HeapOnly();
        ho1->DeleteHeap();
    
        HeapOnly* ho2 = new HeapOnly();
        ho2->s_DeleteHeap(ho2);
    
        return 0;
    }
    ~~~

    

2. 将构造函数私有化

    > 则创建栈上对象和new创建堆上对象都无法创建，因为他们都需要调用构造函数。则需要创建一个静态的公有的Create函数，Create函数里去new对象，此时这个new可以调用构造函数，返回这个对象的指针。

    ~~~C++
    class HeapOnly
    {
    public:
        static HeapOnly* CreateObject()
        {
            return new HeapOnly;
        }
    
        HeapOnly(const HeapOnly&)
        {
            cout << "CopyHeapOnly()" << endl;
        }
        /*HeapOnly& operator=(const HeapOnly& ho)
        {
            cout << "operator=HeapOnly()" << endl;
    
            return *this;
        }*/
    private:
        HeapOnly() 
        {
            cout << "HeapOnly()" << endl;
        }
    
        void operator=(const HeapOnly& ho);
        //HeapOnly(const HeapOnly& ho) = delete;
    
    };
    
    int main()
    {
        //HeapOnly ho;
    
        HeapOnly* ho1 = HeapOnly::CreateObject();
    
        HeapOnly ho2(*ho1);
        ho2 = *ho1;
    
    
        return 0;
    }
    ~~~

    > 将构造函数私有化并不能完全禁止在栈上创建对象，还**需要私有化拷贝构造函数和赋值运算符重载**
    >
    > ps：初始化赋值会优化为拷贝构造

#### 只能在栈上创建对象

1. 将构造函数私有化，

    > 则函数里创建栈上对象和new创建堆上对象都无法创建，因为他们都需要调用构造函数。 创建一个静态的公有的Create函数，Create函数里去创建对象，此时这个静态函数可以调用构造函数，传值返回。用这个静态类成员函数去创建栈上对象，需要把禁止op new 和 op delete，即把它俩私有化，是new和delete调不到底层的op。

    ~~~C++
    class StackOnly
    {
    public:
        static StackOnly CreateObj()
        {
            return StackOnly();
        }
    
        // 禁掉operator new可以把下面用new 调用拷贝构造申请对象给禁掉
        // StackOnly obj = StackOnly::CreateObj();
        // StackOnly* ptr3 = new StackOnly(obj);//拷贝构造
        //为什么不禁止拷贝构造？
        //静态函数返回的是值返回，会调用拷贝函数，会失败，只能禁止底层的new/delete
        void* operator new(size_t size) = delete;
        void operator delete(void* p) = delete;
    private:
        StackOnly()
            :_a(0)
        {}
    private:
        int _a;
    };
    ~~~

    

#### 不能被继承

> 1. c++98， 将构造函数私有化，因为子类在构造时需要调用父类的构造函数，无法调用，就会语法错误
> 2. c++11， final关键字

#### 单例模式：设计一个类，只能创建一个对象

> **设计模式：** 设计模式（Design Pattern）是一套被反复使用、多数人知晓的、经过分类的、代码设计经验的总结。为什么会产生设计模式这样的东西呢？就像人类历史发展会产生兵法。最开始部落之间打仗时都是人拼人的对砍。后来春秋战国时期，七国之间经常打仗，就发现打仗也是有套路的，后来孙子就总结出了《孙子兵法》。孙子兵法也是类似。 
>
> 使用设计模式的目的：为了代码可重用性、让代码更容易被他人理解、保证代码可靠性。 设计模式使代码编写真正工程化；设计模式是软件工程的基石脉络，如同大厦的结构一样。 
>

**单例模式：** 

> 一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个 访问它的全局访问点，该实例被所有程序模块共享。比如在某个服务器程序中，该服务器的配置 信息存放在一个文件中，这些配置数据由一个单例对象统一读取，然后服务进程中的其他对象再 通过这个单例对象获取这些配置信息，这种方式简化了在复杂环境下的配置管理。 

单例模式有两种实现模式：

##### 饿汉模式

> 就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象。
>

~~~C++
// 饿汉模式
// 优点：简单，没有线程安全
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        return &m_instance;
    }

private:
    // 构造函数私有
    Singleton() {};

    // C++98 防拷贝
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
    // or
    // C++11
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;

    static Singleton m_instance;
};

Singleton Singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化
//静态成员变量对象m_instance属于类，所以系统对它初始化时，调用私有的构造函数相当于调用成员函数调用私有函数
~~~

如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，那么显然使用饿汉模式来避 免资源竞争，提高响应速度更好。



##### 懒汉模式

如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等等，而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化， 就会导致程序启动时非常的缓慢。 所以这种情况使用懒汉模式（**延迟加载**）更好。

~~~C++
// 懒汉
// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
// 缺点：复杂
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Singleton
{
public:
	static Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类    
	// 后构造的先析构
	class CGarbo {
	public:
		~CGarbo() {
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton() {};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx;   //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;
int main()
{
	thread t1([] {cout << Singleton::GetInstance() << endl; });
	thread t2([] {cout << Singleton::GetInstance() << endl; });
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}

~~~



### C++类型转换

#### C语言

- 隐式类型转换

    编译器在编译阶段自动进行，能转就转，不能转就编译失败。

- 显式强制类型转换

    意义不相近，需要用户自己处理，有的类似隐式类型转换，有的属于截断内存

~~~C
void Test ()
{
     int i = 1;
     // 隐式类型转换
     double d = i;
     printf("%d, %.2f\n" , i, d);
     int* p = &i;
     // 显示的强制类型转换
     int address = (int) p;
     printf("%x, %d\n" , p, address);
}
~~~

> 转换的可视性比较差，所有的转换形式都是以一种相同形式书写，难以跟踪错误的转换。
>
> 有些转换是隐式呢，需要注意。

#### C++的类型转换

> 标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符： 
>
> static_cast、reinterpret_cast、const_cast、dynamic_cast

##### 1. static_cast\<type> (value)

> static_cast用于非多态类型的转换（静态转换），编译器隐式执行的任何类型转换都可用 static_cast，但它不能用于两个不相关的类型进行转换
>
> 替代隐式类型转换，可转换意义相近的类型

~~~C++
int main()
{
  double d = 12.34;
  int a = static_cast<int>(d);
  cout<<a<<endl;
  return 0;
}

~~~

##### 2. reinterpret_cast\<type>(value)

> reinterpret_cast操作符通常为操作数的位模式提供较低层次的重新解释，用于将一种类型转换 为另一种不同的类型，需要两者内存‘匹配’
>
> 替代显式强制类型转换，适用于意义不相干的类型转换，但转换后仍有一定意义

~~~C++
int main()
{
 double d = 12.34;
 int a = static_cast<int>(d);
 cout << a << endl;
 // 这里使用static_cast会报错，应该使用reinterpret_cast
 //int *p = static_cast<int*>(a);
 int *p = reinterpret_cast<int*>(a);
 return 0;
}

~~~

##### 3. const_cast\<type>(value)

> const_cast最常用的用途就是删除变量的const属性，方便赋值

~~~C++
void Test ()
{
  const int a = 2;
  int* p = const_cast< int*>(&a );
  *p = 3;
  cout<<a <<endl;
}

~~~

##### 拾遗

![image-20221204175423406](%E5%9B%BE%E7%89%87/README/image-20221204175423406.png)

~~~
c++中， const int a 属于常变量， 不存放在常量区，而是在栈上，因为按语法来说，a不能再改变， 所以编译器虽然会使程序中存在a的代码，但不去调用a，而是以宏的方式替代，或保存在寄存器中。所以*p的内容是真的a的地址的内容，a是之前的内容
使用volatile 修饰a， 可以禁止编译器优化， 两个都是3
~~~

##### 4. dynamic_cast\<type>(value)

> dynamic_cast用于**将一个父类对象的指针/引用转换为子类对象的指针或引用**(动态转换) 
>
> 向上转型：子类对象指针/引用->父类指针/引用(不需要转换，赋值兼容规则) 
>
> 向下转型：父类对象指针/引用->子类指针/引用(用dynamic_cast转型是安全的)
> 注意：
>
> 1. dynamic_cast只能用于父类含有虚函数的类
> 2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0

~~~C++
class A
{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a); // 地址， nullptr
	fun(&b); // 地址， 地址
	return 0;
}
~~~

**多继承**

> ptr转为父类指针时，偏移到了正确位置。
>

![image-20221204222335917](%E5%9B%BE%E7%89%87/README/image-20221204222335917.png)



##### RTTI

> RTTI：Run-time Type identification的简称，即：运行时类型识别。 
>
> C++通过以下方式来支持RTTI： 
>
> 1. typeid运算符 
> 2. dynamic_cast运算符 
> 3. decltype

### IO流

