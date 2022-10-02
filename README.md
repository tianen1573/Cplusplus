### 基础语法

##### 命名空间

- 在C/C++中，变量、函数和类都是大量存在的, 这些变量、函数和类的名称若都存在于全局/局部作用域中, 可能会导致很多冲突. 使用命名空间的目的是对标识符的名称进行本地, 存放在各个不同的域中, 以避免命名冲突或名字污染, **namespace**关键字的出现就是针对这种问题的。


- 定义命名空间，需要使用到**namespace**关键字，后面跟命名空间的名字，然后接一对{}即可，{}中即为命名空间的成员。

规则

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

**注意：一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中**

###### 命名空间使用

- ```
    加命名空间名称及作用域限定符 N::a//每次使用都要限定, 推荐
    ```

- ```
    使用using将命名空间中成员引入 using N::a//只取出a, 推荐
    ```

- ```
    使用using namespace 命名空间名称引入 using namespace N//全部取出, OJ时推荐
    ```

------



##### 缺省参数

**缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实参则采用该 形参的缺省值，否则使用指定的实参。**

```C++
void fun(int a = 10)
{
    cout << a * a << endl;
}

int main()
{
    fun();//不传参, 此时形参a默认为10
    fun(1);//传参, 指定实参
    
    return 0;
}
```

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
    
    //在传参时,从左至右一次给形参赋值
    ```

2. 缺省参数不能在函数声明和定义中同时出现

    ```C++
    //原因
    
    // a.h
    void fun(int a = 10);
    // a.cpp
    void fun(int a = 20)
    {}
    // 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省值。
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

函数重载：是函数的一种特殊情况，C++允许在**同一作用域中**声明几个功能类似的**同名函数**，这些 同名函数 的**形参列表(参数个数 或 类型 或 类型顺序)不同**，常用来处理实现功能类似数据类型不同的问题。

###### 实现形式

**同一作用域, 函数名相同, 形参列表不同, 和返回类型无关**

```C++
//参数类型不同，参数顺序不同，参数个数不同
int add(int a, int b);
double add(double a, double b);//a-类型不同
int add(int a, int b, int c);//a-个数不同
void add(int a, char b);
void add(char b, int a);//c-顺序不同
```

###### 为什么C++支持函数重载, 而C不

**C++在编译阶段会对函数进行名字修饰, 通常以某种规则对函数 + 形参类型 进行转换作为函数的新名字**

- 首先, 明确C++源码到程序的四个阶段: 预处理, 编译, 汇编, 链接
- 在**编译阶段**, C++编译器会对函数进行**名字修饰**, 以某种方式将函数名转化为符合语法的**新名字**, 如以 函数名+形参类型 进行转化, 则 `fun(int, int)` 和`fun(int, double)` 转化后 为 `fii`和`fid`, 两个函数的名字就有了区分, 函数名和地址会一起存放在符号表中.
-  在**链接阶段**, 若是同文件的函数调用, 在编译阶段就会CALL, 而不同文件的函数调用, 需要用**函数名**去文件的**符号表查函数对应的地址**. C++的函数经过转换, 同名函数可以区分. 而C就无法进行区分, 报错

###### extern "C"

- 有时候在C++工程中可能需要将某些函数按照C的风格来编译，在函数前加extern "C"，意思是告诉编译器，将该函数按照C语言规则来编译。
- C++调用C库，需要引用头文件时extern "C",告诉编译器,以c语言的方式在该头文件寻找函数/变量
- C调用C++库，需要 条件编译 + extern "C" h文件
    - 条件编译: 编译时,文件 按 C语言规则编译制表
    - extern "C": 按照C语言标准查找函数

###### Other

```
C++中 前置重载为正常重载, 后置重载需要在形参里增加一个int做标识
前置 Ref& operator++()
后置 Ref operator++(int)
```

两篇博客:
https://www.cnblogs.com/skynet/archive/2010/09/05/1818636.html
https://blog.csdn.net/lioncolumn/article/details/10376891

------



#####    引用

引用不是新定义一个变量，而是给已存在变量取了一个**别名**，编译器不会为引用变量开辟内存空间，它和 **它引用的变量共用同一块内存空间**。

###### 使用

1. 

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

**引用的底层实现是用指针实现的**

------



##### 内联函数--建议性关键字

**以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数调用建立栈帧 的开销，内联函数提升程序运行的效率。**

###### 简单了解

![image-20221002203826494](%E5%9B%BE%E7%89%87/README/image-20221002203826494.png)

![image-20221002204552313](%E5%9B%BE%E7%89%87/README/image-20221002204552313.png)

如果在上述函数前增加inline关键字将其改成内联函数，在编译期间编译器会用函数体替换函数的调用。 

查看方式：

1. 在release模式下，查看编译器生成的汇编代码中是否存在call Add 

2. 在debug模式下，需要对编译器进行设置，否则不会展开(因为debug模式下，编译器默认不会对代码进 行优化，以下给出vs2013的设置方式)

    ![image-20221002204514881](%E5%9B%BE%E7%89%87/README/image-20221002204514881.png)

###### 特性

- inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环/递归的函数不适宜使用作为内联函数。
- inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
- inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。(.cpp文件调用函数->通过.h文件的函数声明找出地址->call地址, 但inline展开后, 不会进符号表, 即没有这个函数了, call不到)

------



##### 面试问题

**宏的优缺点？** 

优点： 

1. 增强代码的复用性
2. 提高性能。

缺点： 

1. 不方便调试宏。（因为预编译阶段进行了替换） 
2. 导致代码可读性差，可维护性差，容易误用。
3. 没有类型安全的检查 。

**C++有哪些技术替代宏？**

1. 常量定义 换用const enum
2. 短小函数定义 换用内联函数

-----



##### extern & static

```
extern 声明的全局变量， 写入符号表， 整个项目就一个
static 修饰的变量，不写入符号表，仅当前文件
```

------



##### auto--自动推导变量类型

auto不再是一个存储类型指示符，而是作为一个新的类型指示符来指示编译器，**auto声明的变量必须由编译器在编译时期推导而得。**

使用auto定义变量时必须对其**进行初始化**，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。因此auto**并非是一种“类型”的声明**，而是一个类型**声明时的“占位符”**，编译器在编译期会将auto**替换为变量实际的类型**。

###### 使用细则

1. auto与指针和引用结合起来使用, 用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&

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

2. 在同一行定义多个变量, 当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，因为编译器实际只对第一个类型进行推导，然后用推导出来的类型定义其他变量.

    ```c++
    void TestAuto()
    {
        auto a = 1, b = 2; 
        auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
    }
    ```

###### auto不能推导的场景

-  auto不能作为函数的参数

    ```c++
    // 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
    void TestAuto(auto a)
    {}
    ```

- auto不能直接用来声明数组

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

对于一个**有范围的集合**而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。因此C++11中 引入了基于范围的for循环。for循环后的括号由冒号“ ：”分为两部分：第一部分是范围内用于迭代的变量， 第二部分则表示被迭代的范围。

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

### 类和对象

C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题。

C++是基于面向对象的，关注的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成。

##### C++中struct和class的区别是什么？

C++需要兼容C语言，所以C++中struct可以当成结构体去使用。

另外C++中struct还可以用来定义类。 和class定义类是一样的，区别是struct的成员默认访问方式是public，struct的成员默认访问方式是private。

######  类的访问限定符及封装 

```
C++实现封装的方式：用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限选择性的将其 接口提供给外部的用户使用。 
【访问限定符说明】 
1. public修饰的成员在类外可以直接被访问 
2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的) 3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止 
4. class的默认访问权限为private，struct为public(因为struct要兼容C)  
注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的区别
```

######  类的实例化

```
用类类型创建对象的过程，称为类的实例化 
1. 类只是一个模型一样的东西，限定了类有哪些成员，定义出一个类并没有分配实际的内存空间来存储它 2. 一个类可以实例化出多个对象，实例化出的对象 占用实际的物理空间，存储类成员变量 
3. 做个比方。类实例化出对象就像现实中使用建筑设计图建造出房子，类就像是设计图，只设计出需要什 么东西，但是并没有实体的建筑存在，同样类也只是一个设计，实例化出的对象才能实际存储数据，占用物理空间  
```

######  类的作用域

```
类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员，需要使用 :: 作用域解析符 指明成员属于哪个类域
```

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

###### 类对象内存大小

```
类成员函数存放在公共代码区，不与成员变量存在同一区域，不算大小
调用类成员函数代码，会在类作用域找函数，在编译时转换成call
无成员函数的类，内存默认为1
结论：一个类的大小，实际就是该类中”成员变量”之和，当然也要进行内存对齐，注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类。
```

###### this指针

```
C++编译器给每个“非静态的成员函数“增加了一个隐藏的指针参数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有成员变量的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编译器自动完成。
-----this指针的特性
1. this指针的类型：类类型* const
2. 只能在“成员函数”的内部使用
3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this形参。所以对象中不存储this指针。
4. this指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户传递
5. this指针存在函数形参列表里, 可以通过强转变成空指针
```

###### 六大默认成员函数

**构造函数：**

```
构造函数是一个特殊的成员函数，名字与类名相同,创建类类型对象时由编译器自动调用，保证每个数据成员都有一个合适的初始值，并且在对象的生命周期内只调用一次。需要注意的是，构造函数的虽然名称叫构造，但是构造函数的主要任务并不是开空间创建对象，而是初始化对象。
其特征如下：
1. 函数名与类名相同。
2. 无返回值。
3. 对象实例化时编译器自动调用对应的构造函数。
4. 构造函数可以重载。
5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦用户显式定
义编译器将不再生成。
-----------------------------
默认构造函数：a, 对内置类型不进行处理。b，对自定义类型，调用自定义类型的默认构造参数
----------------------
无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。注意：无参
构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认成员函数。他们不能同时存在.

```

**析构函数:**

```
与构造函数功能相反，析构函数不是完成对象的销毁，局部对象销毁工作是由编译器完成的。而对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。
其特征如下：
1. 析构函数名是在类名前加上字符 ~。
2. 无参数无返回值。
3. 一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
4. 对象生命周期结束时，C++编译系统系统自动调用析构函数。
--------------
关于编译器自动生成的析构函数，是否会完成一些事情呢？下面的程序我们会看到，编译器生成的默认
析构函数，对会自定类型成员调用它的析构函数。
```

**拷贝构造函数:**

```
构造函数：只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)，在用已存在的类类型对象创建新对象时由编译器自动调用。
其特征如下：
1. 拷贝构造函数是构造函数的一个重载形式。
2. 拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用。//重点
3. 若未显示定义，系统生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷
贝，这种拷贝我们叫做浅拷贝，或者值拷贝。//如果申请了堆空间,则对应的指针会指向同一块空间
4. 初始化赋值即int a = b; 会调用拷贝构造, 而不是赋值--编译器优化
```

**赋值运算符重载:**

  ***运算符重载 :***

```
C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其返回值类
型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
函数名字为：关键字operator后面接需要重载的运算符符号。
函数原型：返回值类型 operator操作符(参数列表)
--------注意：
1. 不能通过连接其他符号来创建新的操作符：比如operator@ 
2. 重载操作符必须有一个类类型或者枚举类型的操作数
3. 用于内置类型的操作符，其含义不能改变，例如：内置的整型+，不 能改变其含义
4. 作为类成员的重载函数时，其形参看起来比操作数数目少1, 因为成员函数的操作符有一个默认的形参this，限定为第一个形参
5. .* 、:: 、sizeof 、?: 、. 注意以上5个运算符不能重载。这个经常在笔试选择题中出现。
--------赋值运算符主要有四点：
1. 参数类型
2. 返回值
3. 检测是否自己给自己赋值
4. 返回*this
5. 一个类如果没有显式定义赋值运算符重载，编译器也会生成一个，完成对象按字节序的值拷贝。
6. 赋值运算符在类中不显式实现时，编译器会生成一份默认的，此时用户在类外再将赋值运算符重载为全局的，就和编译器生成的默认赋值运算符冲突了，故赋值运算符只能重载成成员函数
```

 **取地址及const取地址操作符重载** 

```
这两个默认成员函数一般不用重新定义 ，编译器默认会生成。
这两个运算符一般不需要重载，使用编译器生成的默认取地址的重载即可，只有特殊情况，才需要重载，比
如想让别人获取到指定的内容！
```

###### const成员
 **const修饰类的成员函数**

```
将const修饰的类成员函数称之为const成员函数，const修饰类成员函数，实际修饰该成员函数隐含的this 指针，表明在该成员函数中不能对类的任何成员进行修改。
形式: typeReturn name(typeElem ) const
```
**详解C++_const_**

```

```

###### 匿名对象
```
匿名对象生命周期只有一行, 若被const引用, 则其声明周期会延长
```

######   初始化列表

```
定义:
可以认为是类成员变量定义的地方, 一般在构造函数间
格式:
ClassName (int a, int b, int c, ClassName1 cn1)
	: _a(a)
	, _b(b)
	, _c(c)
	, _cn1(cn1)
	{
	///	
	}
知识点:
1. 初始化列表初始化顺序, 与成员变量声明顺序有关, 和初始化列表中出现的顺序无关	
2. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
总结:
引用类型, const修饰成员, 无默认构造函数自置类型必须初始化列表
内置类型也建议初始化列表初始化

```

######  explicit:

```
用explicit修饰构造函数，将会禁止构造函数的隐式转换。 
```

###### 静态类成员:

**静态变量: 只在定义文件显示, 文件外不可见**

```
1. 静态成员为所有类对象所共享，不属于某个具体的对象，存放在静态区
2. 静态成员变量必须在类外定义，定义时不添加static关键字，类中只是声明
3. 类静态成员即可用 类名::静态成员 或者 对象.静态成员 来访问
4. 静态成员函数没有隐藏的this指针，不能访问任何非静态成员, 只能访问静态成员变量
5. 静态成员也是类的成员，受public、protected、private 访问限定符的限制
```

###### 友元:

 友元提供了一种突破封装的方式，有时提供了便利。但是友元会增加耦合度，破坏了封装，所以友元不宜多 用。 

友元分为：友元函数和友元类 

```
友元函数:
友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加friend关键字。
1. 友元函数可访问类的私有和保护成员，但不是类的成员函数
2. 友元函数不能用const修饰
3. 友元函数可以在类定义的任何地方声明，不受类访问限定符限制
4. 一个函数可以是多个类的友元函数
5. 友元函数的调用与普通函数的调用原理相同
```

```
友元类:
友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员。
1. 友元关系是单向的，不具有交换性。
比如上述Time类和Date类，在Time类中声明Date类为其友元类，那么可以在Date类中直接访问Time类的私有成员变量，但想在Time类中访问Date类中私有的成员变量则不行。
2. 友元关系不能传递
如果B是A的友元，C是B的友元，则不能说明C时A的友元。
3. 友元关系不能继承，在继承位置再给大家详细介绍。
```

###### 内部类:

```
 概念：如果一个类定义在另一个类的内部，这个内部类就叫做内部类。内部类是一个独立的类，它不属于外 部类，更不能通过外部类的对象去访问内部类的成员。外部类对内部类没有任何优越的访问权限。

 注意：内部类就是外部类的友元类，参见友元类的定义，内部类可以通过外部类的对象参数来访问外部类中 的所有成员。但是外部类不是内部类的友元。  

 特性： 
 1. 内部类可以定义在外部类的public、protected、private都是可以的, 受访问限制符和外部类类域。 
 2. 注意内部类可以直接访问外部类中的static成员，不需要外部类的对象/类名。 
 3. sizeof(外部类)=外部类，和内部类没有任何关系。 
```

小知识

```
Class w{...};
匿名类:
w(val); //生命周期为一行
编译器优化:
构造 + 拷贝构造 ----> 编译器优化 ----> 合二为一
eg: w w2(w()); //直接构造w2
结论: 
一连串语句, 可能会发生编译器优化.
```

###### C++内存分配:

![Pasted image 20220920210403](cplusplus/%E5%9B%BE%E7%89%87/Pasted%20image%2020220920210403.png)

https://www.bilibili.com/video/BV117411w7o2/?spm_id_from=333.788.videocard.0

###### new/delete:

new可以申请到堆空间

```
--------内置类型:
和C语言没本质区别, 只是简化了语句
申请new:
int *p1 = new int;//申请大小为int的空间
int *p2 = new int[5];//申请大小为 int * 5 的空间
int *p3 = new int(5);//初始化
int *p4 = new int[5]{1, 2, 3};//c++11支持, 98不支持
释放delete:
delete p1;//
delete[] p2;//释放连续空间, 需要对应
delete p3;
delete[] p4;
--------内置类型
如果申请的是内置类型的空间，new和malloc，delete和free基本类似，不同的地方是： new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，而且new在申 请空间失败时会抛异常，malloc会返回NULL。
--------自置类型
申请new:
new不仅会申请堆空间, 还会进行初始化(调用构造函数)
释放delete:
delete释放空间, 并且会调用析构函数
--------失败处理
malloc失败会返回(int)0
new失败会抛出异常错误
--------原理
new的原理
1. 调用operator new函数申请空间
2. 在申请的空间上执行构造函数，完成对象的构造
delete的原理
1. 在空间上执行析构函数，完成对象中资源的清理工作
2. 调用operator delete函数释放对象的空间
new T[N]的原理//////注意
1. 调用operator new[]函数，在operator new[]中实际调用operator new函数完成N个对象空间的申请
2. 在申请的空间上执行N次构造函数
delete[]的原理
1. 在释放的对象空间上执行N次析构函数，完成N个对象中资源的清理
2. 调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间
```
- 对于内置类型, new[]申请的空间, 可以用delete释放, 不会报错, 但不建议这样做
- 对于自置类型, new[]申请的空间, 必须用delete[]释放, 否则会运行失败

######  operator new与operator delete函数:

```
1. new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是系统提供的全局函数，new在底层调用operator new全局函数来申请空间，delete在底层通过operator delete全局函数来释放空间。
2. new 和 delete 本质上调用了一个全局函数 operator new()/operator delete(), 这两个函数的功能, 本质上是用C语言内存函数实现的.
3. operator new 实际也是通过malloc来申请空间，如果malloc申请空间成功就直接返回，否则执行用户提供的空间不足应对措施，如果用户提供该措施就继续申请，否则就抛异常。operator delete 最终是通过free来释放空间的。
```

 **重载operator new与operator delete:**

```
 一般情况下不需要对 operator new 和 operator delete进行重载，除非在申请和释放空间 时候有某些特殊的需求。比如：在使用new和delete申请和释放空间时，打印一些日志信息，可 以简单帮助用户来检测是否存在内存泄漏。 
```

###### 常见内存管理面试题:

```
1. malloc/free和new/delete的区别
malloc/free和new/delete的共同点是：都是从堆上申请空间，并且需要用户手动释放。不同的地方是：
1. malloc和free是函数，new和delete是操作符
2. malloc申请的空间不会初始化，new可以初始化
3. malloc申请空间时，需要手动计算空间大小并传递，new只需在其后跟上空间的类型即可，如果是多个对象，[]中指定对象个数即可
4. malloc的返回值为void*, 在使用时必须强转，new不需要，因为new后跟的是空间的类型
5. malloc申请空间失败时，返回的是NULL，因此使用时必须判空，new不需要，但是new需要捕获异常
6. 申请自定义类型对象时，malloc/free只会开辟空间，不会调用构造函数与析构函数，而new在申请空间后会调用构造函数完成对象的初始化，delete在释放空间前会调用析构函数完成空间中资源的清理
2. 内存泄漏
2.1 什么是内存泄漏，内存泄漏的危害
什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。
内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死。
2.2 内存泄漏分类（了解）
C/C++程序中一般我们关心两种方面的内存泄漏：
堆内存泄漏(Heap leak):
堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak。
系统资源泄漏:
指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定。
2.3 如何检测内存泄漏（了解）
在vs下，可以使用windows操作系统提供的_CrtDumpMemoryLeaks() 函数进行简单检测，该函数只报出了大概泄漏了多少个字节，没有其他更准确的位置信息。
因此写代码时一定要小心，尤其是动态内存操作时，一定要记着释放。但有些情况下总是防不胜防，简单的可以采用上述方式快速定位下。如果工程比较大，内存泄漏位置比较多，不太好查时一般都是借助第三方内存泄漏检测工具处理的。
在linux下内存泄漏检测：linux下几款内存泄漏检测工具
在windows下使用第三方工具：VLD工具说明
其他工具：内存泄漏工具比较
2.4如何避免内存泄漏
1. 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps：
这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题。需要下一条智能指针来管理才有保证。
2. 采用RAII思想或者智能指针来管理资源。
3. 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项。
4. 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵。
总结一下:
内存泄漏非常常见，解决方案分为两种：1、事前预防型。如智能指针等。2、事后查错型。如泄漏检测工具
```

### STL

书籍推荐: <<STL源码剖析>> 侯捷

##### 泛型编程--模板:

 编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础。  可以缺省, 缺省类型, **模板的推导发生在编译阶段**

**函数模板:**
```
函数模板代表了一个函数家族，该函数模板与类型无关，在使用时被参数化，根据实参类型产生函数的特定类型版本->实例化出对应函数。
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
原理:
函数模板是一个蓝图，它本身并不是函数，是编译器用使用方式产生特定具体类型函数的模具。所以其实模
板就是将本来应该我们做的重复的事情交给了编译器
在编译器编译阶段，对于模板函数的使用，编译器需要根据传入的实参类型来推演生成对应类型的函数以供
调用。比如：当用double类型使用函数模板时，编译器通过对实参类型的推演，将T确定为double类型，然后产生一份专门处理double类型的代码，对于字符类型也是如此--推断在传参前。
```

**函数模板的实例化:**
```
用不同类型的参数使用函数模板时，称为函数模板的实例化。模板参数实例化分为：隐式实例化和显式实例
化。
隐式实例化:
通过编译器自动推导, 隐式实例化模板函数
显示实例化:
在调用函数时, 指定模板参数类型, 不需要编译器推移
eg: Swap<int>(a1, a2);//有几种模板类型, 指定几个
如果类型不匹配，编译器会尝试进行隐式类型转换，如果无法转换成功编译器将会报错。
匹配原则:
1. 一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函
数
eg : Add(1, 2) , Add<int>(1, 2)
2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模
板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
3. 模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
```

**类模板:**
```
格式:
template<class T1, class T2, ..., class Tn>
class 类模板名
{
 // 类内成员定义--存在模板类型成员
}; 
1. 在类中使用模板类型, 就是类模板
2. 类模板都是显示实例化
3. 模板类不支持分离编译, 即声明和定义必须在同一个文件
```

**实例化**
```
1. 类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后跟<>，然后将实例化的类型放在<>中即可，类模板名字不是真正的类，而实例化的结果才是真正的类。
eg: // Vector类名，Vector<int>才是真正的类
```


**注意注意注意注意注意注意注意注意注意注意注意注意注意注意注意注意注意注意**
```
1. 模板参数列表, 和其函数模板, 类模板是一一对应的

2. 类模板/函数模板 只是一种声明, 并不是定义, 由编译器在编译阶段推导出来的模板函数/模板类才是定义
```

##### string类:

**新思想**
```
深拷贝原理
深现代写法原理
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

###### 全代码

[String模拟实现参考](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/string%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/String.h)

```c++
#pragma once

#include<iostream>
#include<assert.h>
#include<string>
#include<algorithm>
using namespace std;

namespace Bit
{

	/*using std::cout;
	using std::cin;
	using std::endl;*/

	class string
	{

		typedef char* iterator;
		typedef const char* const_iterator;
	public:

#pragma region 其他
		//swap
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}

		//c指针
		const char* c_str() const
		{
			return _str;
		}	 
#pragma endregion

#pragma region 构造函数
		//无参
		// _str(nullptr) 错误: 转换成c指针 用cout输出的结束条件为 *p = '\0', 解引用了空指针
		// _str("\0") 错误: 常量字符串默认存在'\0'
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
			size_t len = strlen(str);
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
		//	strcpy(_str, str);
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

		//n个字符 ch
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
		//	memcpy(_str, str._str, _capacity + 1);
		//}
		//
		//现代写法
		string(const string& str)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(str._str);
			swap(tmp);
		}

		//sting对象 第 pos位置的 后n个字符
		string(const string& str, size_t pos, size_t n = npos)
			
		{
			assert(pos < str._size);//合法下标
			*this = str.substr(pos, n);

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
#pragma endregion

#pragma region 空间操作
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
#pragma endregion

#pragma region 增删改查
		
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
#pragma endregion

#pragma region 操作符重载
		
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
#pragma endregion
	
#pragma region 迭代器
		
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
#pragma endregion

#pragma region 成员变量
	private:
		size_t _capacity;//最大有效存储长度
		size_t _size;//实际长度
		char* _str;//字符串地址
	public:

		//静态成员变量 : 声明定义分离
		static size_t npos;
		//C++11特性 : 加上const可直接在类内定义静态变量
		//const static size_t npos = -1;  
#pragma endregion

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
		cout << s1 + " Bit" << endl;
		cout << s1 + s2 << endl;


		cout << (s1 += '!') << endl;
		cout << (s1 += " Bit") << endl;
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

###### 构造函数
```c++
//无参
	//---------注意
	// _str(nullptr) 错误: 转换成c指针 用cout输出的结束条件为 *p = '\0', 解引用了空指针
	// _str("\0") 错误: 常量字符串默认存在'\0'
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
		size_t len = strlen(str);
		_size = len;
		_capacity = len;
		_str = new char[len + 1];
		//使用strcpy拷贝, 符合常量字符串以'\0'结尾的规范
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
	//	strcpy(_str, str);
	//}

//常量字符串前n个字符
	string(const char* str, size_t n)
	{
		//确定实际长度
		size_t len = strlen(str);
		len = len > n ? n : len;

		_size = _capacity = len;
		_str = new char[_capacity + 1];

		//strcpy 遇到\0结束, 不支持提前结束
		for (size_t i = 0; i < _size; i++)
		{
			_str[i] = str[i];
		}
		_str[_size] = '\0';

	}

//n个字符 ch
	string(size_t n, char ch)
		:_str(new char[n + 1])//初始化列表初始化
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
	//	memcpy(_str, str._str, _capacity + 1);
	//}
	//
	
	//现代写法
	string(const string& str)
		: _str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		string tmp(str._str);//调用常量字符串构造, 复用代码
		swap(tmp);//交换
	}

//sting对象 第 pos位置的 后n个字符
	string(const string& str, size_t pos, size_t n = npos)
		
	{
		assert(pos < str._size);//合法下标
		
		*this = str.substr(pos, n);//调用substr, 此处偷懒

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
```

###### 空间操作
```c++
//reserve
	//仅扩充空间大小
	void reserve(size_t n)
	{
		//仅扩充, 不缩小
		if (n <= _size) return;

		char* tmp = new char[n + 1];
		
		//string中可包含'\0', strcpy遇到'\0', 可能发生截断,应该按字节拷贝
		memcpy(tmp, _str, _capacity + 1);

		delete[] _str;
		_str = tmp;
		tmp = nullptr;
		_capacity = n;
	}
//resize
	//扩充/缩减长度 ---> 扩充空间
	void resize(size_t n, char ch = '\0')
	{
		if (n > _size)
		{
			//判断扩容
			reserve(n);
			//填充字符
			for (_size; _size < n; _size++)
			{
				_str[_size] = ch;
			}
			_str[_size] = '\0';
		}
		else//缩减长度
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
	//仅改变字符串长度
	void clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
```

###### 增删改查
```c++	
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
		
		//是否扩容
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

		//判断是否超出string长度
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

		return tmp;//返回的临时对象为const属性
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
```

###### 操作符重载
```c++	
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
```

###### 迭代器/其他
```c++
//迭代器	
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
//其他
	//swap
	void swap(string& str)
	{
		std::swap(_str, str._str);
		std::swap(_size, str._size);
		std::swap(_capacity, str._capacity);
	}

	//c指针
	const char* c_str() const
	{
		return _str;
	}	 
```

###### 输入输出
```c++
//<<
	ostream& operator<<(std::ostream& out, const string& str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			out << str[i];
		}
		return out;
	}

//>> 
	//基础版本
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
	
	//升级版--减少前期扩容操作
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
```

###### 阅读推荐
<a href = "https://coolshell.cn/articles/10478.html">酷壳-陈浩-C++面试中string类的一种正确写法</a>
<a href = "https://blog.csdn.net/haoel/article/details/1491219?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166368282316782414956992%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166368282316782414956992&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-1491219-null-null.nonecase&utm_term=string%E7%B1%BB%E5%88%B0%E5%BA%95%E6%80%8E%E4%B9%88%E5%95%A6&spm=1018.2226.3001.4450">strig类到底怎么啦</a>
[C++ STL string的Copy-On-Write技术](https://coolshell.cn/articles/12199.html) 
[C++的std::string的“读时也拷贝”技术](https://coolshell.cn/articles/1443.html)

##### vector类

**新思想**
```
泛型编程--模板成员变量
迭代器失效问题
深拷贝嵌套问题
```

**自写模板--迭代器失效**
```
迭代器失效问题: insert(), erase()
insert: 发生扩容 使pos指向的空间非法, 野指针; 插入后, pos不再指向原来的 [逻辑位置], 运行结果不符合逻辑, std::insert()返回插入的元素的迭代器
erase: 发生缩容, 使pos指向的空间非法, 野指针; 逻辑问题. erase()根据编译器规则不同, 会有不同的结果. 不建议erase后立即访问, std::erase()返回删除元素的后一个元素的迭代器
```

**其他**
```
capacity的代码在vs和g++下分别运行会发现，vs下capacity是按1.5倍增长的，g++是按2倍增长的。 这个问题经常会考察，不要固化的认为，vector增容都是2倍，具体增长多少是根据具体的需求定义 的。vs是PJ版本STL，g++是SGI版本STL。 reserve只负责开辟空间，如果确定知道需要用多少空间，reserve可以缓解vector增容的代价缺陷问 题。 resize在开空间的同时还会进行初始化，影响size。
```

###### 全代码

[Vector模拟实现](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/vector%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/Vector.h)

```c++
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
#pragma region TypedefAndIterator
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

#pragma endregion

#pragma region 构造函数

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
		* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
		* 就不会走vector(size_t n, const T& value = T())这个构造方法，
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


#pragma endregion

#pragma region 空间

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

#pragma endregion

#pragma region Other

		//接受形参的引用, 将形参替换为空对象
		void swap(vector<T>& vec)
		{
			::swap(_start, vec._start);
			::swap(_finish, vec._finish);
			::swap(_endOfStorage, vec._endOfStorage);
		}

#pragma endregion

#pragma region 增删改查

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

#pragma endregion


#pragma region 操作符AND访问

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

#pragma endregion


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
```

###### 构造函数
```c++
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
	* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
	* 就不会走vector(size_t n, const T& value = T())这个构造方法，
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
//析构
	~vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}
```

###### 空间操作
```c++
private:
	bool Full()//私有化
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
```

###### 增删改查
```c++
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
```

###### 操作符重载
```c++
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
```

###### 迭代器/其他
```c++
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

//接受形参的引用, 将形参替换为空对象
	void swap(vector<T>& vec)
	{
		::swap(_start, vec._start);
		::swap(_finish, vec._finish);
		::swap(_endOfStorage, vec._endOfStorage);
	}
```

##### list类

**新思想**
```
泛型编程

泛型编程---通过模板类型列表的不同,形参实例化不同, 最终实现泛型编程
复用思想---适配器
非原生指针迭代器--封装原生指针, 形成迭代器类, 并重载运算符, 向原生指针靠拢

重点迭代器

```

###### 全代码

[List的模拟实现](https://gitee.com/ailiangshilove/cpp-class/blob/master/%E8%AF%BE%E4%BB%B6%E4%BB%A3%E7%A0%81/C++%E8%AF%BE%E4%BB%B6V6/List%E7%9A%84%E6%A8%A1%E6%8B%9F%E5%AE%9E%E7%8E%B0/List.h)

```
#pragma once

#include<assert.h>
#include<iostream>
#include<list>

using namespace std;


namespace qlz
{
	
	template<typename T>//数据类型
	//节点结构
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
	* 		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前             移动，所以需要重载，如果是forward_list就不需要重载--
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

		//////////////////////////////////////////////
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
		
	

#pragma region 构造函数
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

#pragma endregion

#pragma region 空间

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

#pragma endregion

#pragma region 迭代器
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
#pragma endregion

#pragma region 增删
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
#pragma endregion

#pragma region 访问
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
#pragma endregion


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

	void test1()
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
	void test2()
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
	void Func(const list<int>& l)
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
	void test3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		Func(lt);
	}
	void test4()
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
	void test5()
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

```

###### 构造函数
```C++
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
```

###### 空间操作
```c++
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
```

###### 增删
```c++
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
```

###### 迭代器
**模板类声明**
```c++
//迭代器模板类声明
typedef list_node<T> Node;
//通过实例化的区别, 生成const迭代器, 和非const迭代器
typedef _list_iterator<T, T&, T*> iterator;
typedef _list_iterator<T, const T&, const T*> const_iterator;		
//仍然可以 以 函数重载的方式, 实现返回 成员变量的const引用 和 非const引用

/*反向迭代器(不复用)*/
/*typedef _reverse_list_iterator<T, T&, T*> reverse_iterator;
typedef _reverse_list_iterator<T, const T&, const T*> const_reverse_iterator;*/
/*反向迭代器(复用)*/
typedef _reverse_list_iterator<iterator> reverse_iterator;
typedef _reverse_list_iterator<const_iterator> const_reverse_iterator;

//----------------------------------------------------------------------------
```
**模板类**
```c++
//迭代器模板类
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
* 		至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前             移动，所以需要重载，如果是forward_list就不需要重载--
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

	//////////////////////////////////////////////
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

//---------------------------------------------------------------------------------
```
**函数**
```
//迭代器函数
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

```

