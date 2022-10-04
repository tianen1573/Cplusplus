#pragma once

#include<iostream>
#include<vector>
#include<deque>
#include<list>

using namespace std;

namespace qlz
{
	template <class T, class Container = vector<T>, class Compare = less<T> >
    //����ע���߼����������
	class priority_queue
	{
    public:

        //����������
        void adjust_down(size_t parent)
        {
            size_t child = parent * 2 + 1;
            while (child < _con.size())
            {
                // ѡ�����Һ����д����һ��, ���������ȥ�滻Ϊ���ڵ�
                if (child + 1 < _con.size() && _cmp(_con[child], _con[child + 1]))
                {
                    ++child;
                }

                //�ж��Ƿ�ȸ��ڵ��
                if (_cmp(_con[parent], _con[child]))
                {
                    std::swap(_con[child], _con[parent]);

                    //ԭ�ڵ��³�, �����ж��Ƿ���Ҫ�³�
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        //����������: һֱ������, �ҵ������Լ���λ��
        void adjust_up(size_t child)
        {
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                //if (_con[child] > _con[parent])
                //����ȸ��ڵ��, ����
                if (_cmp(_con[parent], _con[child]))
                {
                    std::swap(_con[child], _con[parent]);
                    //������, �жϽ������Ƿ���µĸ��ڵ��
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
            //��һ�εõ���ʵ�±�, �ټ�һ�γ���2, Ϊ�õ����ڵ�.
            //�Ƚ�С�Ķ�, �ٸ��ݵõ��Ķѽ���Ķ�
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

            adjust_up(_con.size() - 1);//������, ��λ��
        }

        void pop()
        {
            std::swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();

            adjust_down(0);//������ȥ��ΪСԪ��, ��ͷ��һ�ζ�
        }

    private:

        Container _con;

        Compare _cmp;
	};
}
