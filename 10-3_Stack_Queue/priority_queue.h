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

        //建堆往下走
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
