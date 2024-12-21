#pragma once

#include <iostream>

namespace MySTL {
template <class T>
class list {
public:
    template <typename L>
    friend std::ostream& operator<<(std::ostream& os, const list<L>& pt);

private:
    struct Node {
        T _data;
        Node* _next;
        Node* _prev;

        Node(const T& data, Node* next = nullptr, Node* prev = nullptr) : _data(data), _next(next), _prev(prev) {}
    };

    Node* _head;
    Node* _tail;
    size_t _size; // 链表中节点数量

public:
    list() : _head(nullptr), _tail(nullptr), _size(0) {}

    //  初始化列表构造
    list(std::initializer_list<T> init_list) : _head(nullptr), _tail(nullptr), _size(0) {
        for (const auto& elem : init_list) {
            push_back(elem);
        }
    }

    // 拷贝构造函数
    list(const list& other) : _head(nullptr), _tail(nullptr), _size(0) {
        Node* ptr = other._head;
        while (ptr) {
            push_back(ptr->_data);
            ptr = ptr->_next;
        }
    }

    // 拷贝赋值操作符
    list& operator=(const list& other) {
        if (this != &other) {
            clear();
            Node* ptr = other._head;
            while (ptr) {
                push_back(ptr->_data);
                ptr = ptr->_next;
            }
        }
        return *this;
    }

    ~list() {
        clear();
    }

    // 在链表末尾添加元素
    void push_back(const T& value) {
        // 创建新的节点
        Node* newNode = new Node(value, nullptr, _tail);

        if (_tail) {
            // 如果链表非空，将尾节点的 next 指针指向新节点
            _tail->_next = newNode;
        } else {
            // 如果链表为空，新节点同时也是头节点
            _head = newNode;
        }

        // 更新尾节点指针和链表大小
        _tail = newNode;
        _size++;
    }

    // 在链表开头添加元素
    void push_front(const T& value) {
        // 创建新的节点
        Node* newNode = new Node(value, _head, nullptr);

        if (_head) {
            // 如果链表非空，将头节点的 prev 指针指向新节点
            _head->_prev = newNode;
        } else {
            // 如果链表为空，新节点同时也是尾节点
            _tail = newNode;
        }

        // 更新头节点指针和链表大小
        _head = newNode;
        _size++;
    }

    // 获取链表中节点的数量
    size_t size() const {
        return _size;
    }

    // 访问链表中的元素
    T& operator[](size_t index) {
        // 从头节点开始遍历链表，找到第 index 个节点
        Node* current = _head;
        for (size_t i = 0; i < index; ++i) {
            if (!current) {
                // 如果 index 超出链表长度，则抛出异常
                throw std::out_of_range("Index out of range");
            }
            current = current->_next;
        }

        // 返回节点中的数据
        return current->_data;
    }

    // const版本的访问链表中的元素
    const T& operator[](size_t index) const {
        // 从头节点开始遍历链表，找到第 index 个节点
        Node* current = _head;
        for (size_t i = 0; i < index; ++i) {
            if (!current) {
                // 如果 index 超出链表长度，则抛出异常
                throw std::out_of_range("Index out of range");
            }
            current = current->_next;
        }

        // 返回节点中的数据
        return current->data;
    }

    // 删除链表末尾的元素
    void pop_back() {
        if (_size > 0) {
            // 获取尾节点的前一个节点
            Node* newTail = _tail->_prev;

            // 删除尾节点
            delete _tail;

            // 更新尾节点指针和链表大小
            _tail = newTail;
            if (_tail) {
                _tail->_next = nullptr;
            } else {
                _head = nullptr; // 如果链表为空，头节点也置为空
            }

            _size--;
        }
    }

    // 删除链表开头的元素
    void pop_front() {
        if (_size > 0) {
            // 获取头节点的下一个节点
            Node* newHead = _head->_next;

            // 删除头节点
            delete _head;

            // 更新头节点指针和链表大小
            _head = newHead;
            if (_head) {
                _head->_prev = nullptr;
            } else {
                _tail = nullptr; // 如果链表为空，尾节点也置为空
            }

            _size--;
        }
    }

    // 获取指定值的节点
    Node* getNode(const T& val) {
        Node* node = _head;
        while (node != nullptr && node->_data != val) {
            node = node->_next;
        }

        return node;
    }

    T* find(const T& val) {
        Node* node = getNode(val);
        if (node == nullptr) {
            return nullptr;
        }
        return &node->_data;
    }

    // 删除指定值的节点
    void remove(const T& val) {
        Node* node = _head;
        while (node != nullptr && node->_data != val) {
            node = node->_next;
        }

        if (node == nullptr) {
            // 没有找到
            return;
        }
        if (node != _head && node != _tail) {
            // 既不是头结点也不是尾结点
            node->_prev->_next = node->_next;
            node->_next->_prev = node->_prev;
        } else if (node == _head && node == _tail) {
            // 既是头结点也是尾结点
            _head = nullptr;
            node = nullptr;
        } else if (node == _head) {
            // 是头结点
            _head = node->_next;
            _head->_prev = nullptr;
        } else {
            // 是尾结点
            _tail = node->_prev;
            _tail->_next = nullptr;
        }

        _size--;

        delete node;
        node = nullptr;
    }

    bool empty() {
        return _size == 0;
    }

    // 清空链表
    void clear() {
        while (_head) {
            // 从头节点开始，依次删除节点
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
        }

        // 更新尾节点指针和链表大小
        _tail = nullptr;
        _size = 0;
    }

    // 使用迭代器遍历链表的开始位置
    Node* begin() {
        return _head;
    }

    // 使用迭代器遍历链表的结束位置
    Node* end() {
        return nullptr;
    }

    // 使用迭代器遍历链表的开始位置（const版本）
    const Node* begin() const {
        return _head;
    }

    // 使用迭代器遍历链表的结束位置（const版本）
    const Node* end() const {
        return nullptr;
    }
};

// 重载 << 运算符
template <typename T>
std::ostream& operator<<(std::ostream& os, const list<T>& pt) {
    for (typename List<T>::Node* current = pt._head; current; current = current->_next) {
        os << " " << current->_data;
    }
    os << std::endl;
    return os;
}

} // namespace MySTL