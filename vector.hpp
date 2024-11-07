#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <iostream>

namespace pic {
    template <typename T>
    class vector {
    private:
        size_t m_size;
        size_t m_capacity;
        T *m_data;
    public:
        using value_type = T;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;

        class Iterator {
        private:
            pointer m_data;
        public:
            using iterator_category = std::random_access_iterator_tag;
            using difference_type = std::ptrdiff_t;

            explicit Iterator(pointer data = nullptr);

            Iterator operator+(difference_type n) const;
            Iterator operator-(difference_type n) const;
            difference_type operator-(const Iterator& rhs) const;
            Iterator& operator++();
            Iterator& operator--();
            Iterator operator++(int);
            Iterator operator--(int);

            friend bool operator<(const Iterator& lhs, const Iterator& rhs) {
                return lhs.m_data < rhs.m_data;
            }
            friend bool operator>(const Iterator& lhs, const Iterator& rhs) {
                return lhs.m_data > rhs.m_data;
            }
            friend bool operator<=(const Iterator& lhs, const Iterator& rhs) {
                return lhs.m_data <= rhs.m_data;
            }
            friend bool operator>=(const Iterator& lhs, const Iterator& rhs) {
                return lhs.m_data >= rhs.m_data;
            }

            bool operator==(const Iterator& it) const {
                return m_data == it.m_data;
            }

            bool operator!=(const Iterator& it) const {
                return m_data != it.m_data;
            }

            // friend bool operator==(const typename vector<T>::Iterator& lhs, const T& rhs);
            //
            // friend bool operator!=(const typename vector<T>::Iterator& lhs, const T& rhs);

            reference operator*() const;
            pointer operator->() const;
        };
        //Iterators
        Iterator begin() const;
        Iterator end() const;

        // Iterator cbegin() const;
        // Iterator cend() const;

        // Iterator rbegin() const;
        // Iterator rend() const;

        // Iterator crbegin() const;
        // Iterator crend() const;

        //Ctors & Member functions
        vector();
        explicit vector(size_type size);
        explicit vector(size_type size, const_reference val);
        vector(std::initializer_list<T> list);

        vector(const vector& other);
        vector(vector&& other) noexcept;

        vector& operator=(const vector& other);
        vector& operator=(vector&& other) noexcept;

        ~vector();

        void assign(size_type size, const_reference val);


        //Capacity
        bool empty() const;
        size_type size() const;
        void reserve(size_type new_capacity);
        void shrink_to_fit();

        //Element access
        reference at(size_type index);
        const_reference at(size_type index) const;

        reference front();
        const_reference front() const;

        reference back();
        const_reference back() const;

        reference operator[](size_type index);
        const_reference operator[](size_type index) const;

        //Modifiers
        void clear();

        void push_back(const_reference val);

        void pop_back();

        size_type capacity() const;

        Iterator insert(Iterator pos, const_reference val);
        Iterator insert(Iterator pos, std::initializer_list<T> list);

        Iterator erase(Iterator pos);
        Iterator erase(Iterator first, Iterator last);

        void resize(size_type new_size);
        void resize(size_type new_size, const_reference val);

        void swap(vector& other);

    };
}

#include "vector.cpp"

#endif //VECTOR_H
