#pragma once

#include <iostream>

namespace MySTL
{
    template <class T>
    class vector
    {
    private:
        T* _data;
        size_t _capacity; // 数组容量
        size_t _size;     // 元素个数

    public:
        vector() : _data(nullptr), _capacity(0), _size(0)
        {
        }

        ~vector()
        {
            delete[] _data;
        }

        // initializer list constructor
        vector(std::initializer_list<T> init_list) : _data(nullptr), _size(0), _capacity(init_list.size())
        {
            _data = new T[_capacity]; // 分配内存
            for (const auto& elem : init_list)
            {
                _data[_size++] = elem; // 复制元素
            }
        }

        // 拷贝构造函数
        vector(const vector& other) : _capacity(other._capacity), _size(other._size)
        {
            _data = new T[_capacity];
            std::copy(other._data, other._data + other._size, _data);
        }

        // 拷贝赋值操作符
        vector& operator=(const vector& other)
        {
            if (this != &other)
            {
                delete[] _data;
                _capacity = other._capacity;
                _size = other._size;
                _data = new T[_capacity];
                std::copy(other._data, other._data + other._size, _data);
            }
            return *this;
        }

        void push_back(const T& value)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 1 : 2 * _capacity);
            }
            _data[_size] = value;
            _size++;
        }

        size_t size() const
        {
            return _size;
        }

        T& operator[](size_t index)
        {
            // 检查索引是否越界
            if (index >= _size)
            {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }

        // const版本的访问数组中的元素
        const T& operator[](size_t index) const
        {
            // 检查索引是否越界
            if (index >= _size)
            {
                throw std::out_of_range("Index out of range");
            }
            return _data[index];
        }

        // 在指定位置插入元素
        void insert(size_t index, const T& value)
        {
            if (index > size)
            {
                throw std::out_of_range("Index out of range");
            }
            if (_size == _capacity)
            {
                reserve(capacity == 0 ? 1 : capacity * 2);
            }
            for (size_t i = size; i > index; --i)
            {
                _data[i] = _data[i - 1];
            }
            _data[index] = value;
            ++size;
        }

        // 删除数组末尾的元素
        void pop_back()
        {
            if (_size > 0)
            {
                --_size;
            }
        }

        // 清空数组
        void clear()
        {
            _size = 0;
        }

        bool empty()
        {
            return _size == 0;
        }

        // 使用迭代器遍历数组的开始位置
        T* begin()
        {
            return _data;
        }

        // 使用迭代器遍历数组的结束位置
        T* end()
        {
            return _data + _size;
        }

        // 使用迭代器遍历数组的开始位置（const版本）
        const T* begin() const
        {
            return _data;
        }

        // 使用迭代器遍历数组的结束位置（const版本）
        const T* end() const
        {
            return _data + _size;
        }

    private:
        // 扩容
        void reserve(size_t newCapacity)
        {
            if (newCapacity > _capacity)
            {
                T* newData = new T[newCapacity];
                std::copy(_data, _data + _size, newData);
                delete[] _data;
                _data = newData;
                _capacity = newCapacity;
            }
        }
    };
}