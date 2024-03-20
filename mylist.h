#ifndef _MY_LIST_H_
#define _MY_LIST_H_

#include <cstddef> // size_t
#include <iostream> // cout
#include <limits> // numeric_limits

template<class T>
class MyList {

private:
    typedef std::size_t Length;

    struct Node {
        T &m_data;
        Node *m_next;
        Node *m_prev;

        Node(T &data, Node *next, Node *prev) : m_data(data),
                                                m_next(next),
                                                m_prev(prev)
        {}

        T &get()
        {
            return m_data;
        }

    }; /* Node */

    Node *m_head;
    Length m_len;

    MyList(const MyList &list) = delete;
    MyList(MyList &&list) = delete;
    MyList &operator=(const MyList &list) = delete;
    MyList &operator=(MyList &&list) = delete;

public:
    MyList() noexcept : m_head(nullptr), m_len(0)
    {}

    ~MyList()
    {
        while (m_head != nullptr) {
            Node *tmp = m_head->m_next;
            delete m_head;
            m_head = tmp;
        }
    }

    Node *insert(const size_t index, T &data)
    {
        if (index < 0) {
            return nullptr;
        } else if (index > std::numeric_limits<Length>::max()) {
            return nullptr;
        } else if (index > m_len) {
            return nullptr;
        } else if (index == 0) {
            Node *insertNode = new Node(data, m_head, nullptr);
            if (m_head != nullptr) {
                m_head->m_prev = insertNode;
            }

            m_head = insertNode;
            ++m_len;
            return m_head;
        } else {
            std::size_t i = 0;
            Node *prev = m_head;
            while ((prev != nullptr) && (i < index - 1)) {
                prev = prev->m_next;
                ++i;
            }

            Node *insertNode = new Node(data, prev->m_next, prev);
            Node *next = prev->m_next;
            if (next != nullptr) {
                next->m_prev = insertNode;
            }

            prev->m_next = insertNode;
            ++m_len;
            return insertNode;
        }
    }

    bool remove(const size_t index)
    {
        if (index < 0) {
            return false;
        } else if (index > std::numeric_limits<Length>::max()) {
            return false;
        } else if (m_head == nullptr) {
            return false;
        } else if (index > m_len - 1) {
            return false;
        } else if (index == 0) {
            Node *tmp = m_head->m_next;
            if (tmp != nullptr) {
                tmp->m_prev = nullptr;
            }

            delete m_head;
            m_head = tmp;
            return true;
        } else {
            std::size_t i = 0;
            Node *tmp = m_head;
            while (i < index) {
                tmp = tmp->m_next;
                ++i;
            }

            Node *prev = tmp->m_prev;
            prev->m_next = tmp->m_next;

            Node *next = tmp->m_next;
            if (next != nullptr) {
                next->m_prev = prev;
            }

            delete tmp;
            --m_len;
            return true;
        }
    }

    void print()
    {
        Node *tmp = m_head;
        Node *last;
        while (tmp != nullptr) {
            std::cout << tmp->m_data << " ";
            last = tmp;
            tmp = tmp->m_next;
        }

        std::cout << std::endl;

        while (last != nullptr) {
            std::cout << last->m_data << " ";
            last = last->m_prev;
        }

        std::cout << std::endl;
    }

    T *get(const std::size_t index)
    {
        if (index < 0) {
            return nullptr;
        } else if (index > std::numeric_limits<Length>::max()) {
            return nullptr;
        }

        std::size_t i = 0;
        Node *tmp = m_head;
        while ((tmp != nullptr) && (i < index)) {
            tmp = tmp->m_next;
            ++i;
        }

        if (tmp) {
            return &(tmp->get());
        } else {
            return nullptr;
        }
    }

}; /* MyList */

#endif /* _MY_LIST_H_ */