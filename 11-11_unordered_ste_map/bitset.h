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
