// // #include "vector.hpp"
//
// namespace pic {
//     template<class T>
//     vector<T>::vector(): m_size(0), m_capacity(0), m_data(nullptr) {}
//
//     template<typename T>
//     vector<T>::vector(size_type size): m_size(size), m_capacity(size), m_data(new T[size]) {
//         for(size_type i = 0; i < size; i++) {
//             m_data[i] = value_type();
//         }
//     }
//
//     template<typename T>
//     vector<T>::vector(size_type size, const_reference val): m_size(size), m_capacity(size), m_data(new T[size]) {
//         for(size_t i = 0; i < size; i++) {
//             m_data[i] = val;
//         }
//     }
//
//     template<typename T>
//     vector<T>::vector(std::initializer_list<T> list) : m_size(list.size()), m_capacity(list.size()), m_data(new T[list.size()]) {
//         size_type i = 0;
//         for (const T& val : list) {
//             m_data[i++] = val;
//         }
//     }
//
//     template<typename T>
//     vector<T>::vector(const vector<T>& other): m_size(other.size()), m_capacity(other.size()), m_data(new T[other.size()]) {
//         for(std::size_t i = 0; i < other.size(); i++) {
//             m_data[i] = other.m_data[i];
//         }
//     }
//
//     template<typename T>
//     vector<T>::vector(vector<T>&& other) noexcept: m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data) {
//         other.m_size = 0;
//         other.m_capacity = 0;
//         other.m_data = nullptr;
//     }
//
//     template<typename T>
//     vector<T> &vector<T>::operator=(const vector<T> &other) {
//         if(this != &other) {
//             delete[] m_data;
//             m_size = other.m_size;
//             m_capacity = other.m_capacity;
//             m_data = new value_type[m_size];
//             for(std::size_t i = 0; i < m_size; i++) {
//                 m_data[i] = other.m_data[i];
//             }
//         }
//         return *this;
//     }
//
//     template<typename T>
//     vector<T> &vector<T>::operator=(vector<T> &&other) noexcept {
//         if(this != &other) {
//             delete[] m_data;
//             m_size = other.m_size;
//             m_capacity = other.m_capacity;
//             m_data = other.m_data;
//
//             other.m_size = 0;
//             other.m_capacity = 0;
//             other.m_data = nullptr;
//         }
//         return *this;
//     }
//
//     template<typename T>
//     vector<T>::~vector() {
//         delete[] m_data;
//     }
//
//     template<typename T>
//     void vector<T>::assign(size_type size, const_reference val) {
//         if(size == 0) {
//             delete[] m_data;
//             m_size = 0;
//             m_capacity = 0;
//             m_data = nullptr;
//             return;
//         }
//         delete[] m_data;
//         m_size = size;
//         m_capacity = size;
//         m_data = new T[size];
//         for(std::size_t i = 0; i < size; i++) {
//             m_data[i] = val;
//         }
//     }
//
//     template<typename T>
//     bool vector<T>::empty() const {
//         return m_size == 0;
//     }
//
//     template<typename T>
//     typename vector<T>::size_type vector<T>::size() const {
//         return m_size;
//     }
//
//     template<typename T>
//     void vector<T>::reserve(size_type new_capacity) {
//         if(new_capacity > m_capacity && m_capacity > 0) {
//             T* new_data = new T[new_capacity];
//             for(std::size_t i = 0; i < m_size; i++) {
//                 new_data[i] = m_data[i];
//             }
//             delete[] m_data;
//             m_data = new_data;
//             m_capacity = new_capacity;
//         }
//     }
//
//     template<typename T>
//     void vector<T>::shrink_to_fit() {
//         if(m_size < m_capacity) {
//             T* new_data = new T[m_size];
//             for(std::size_t i = 0; i < m_size; i++) {
//                 new_data[i] = m_data[i];
//             }
//             delete[] m_data;
//             m_data = new_data;
//             m_capacity = m_size;
//         }
//     }
//
//     template<typename T>
//     typename vector<T>::reference vector<T>::at(size_type index) {
//         if(index < m_size) {
//             return m_data[index];
//         }
//         throw std::out_of_range("index out of range");
//     }
//
//     template<typename T>
//     typename vector<T>::const_reference vector<T>::at(size_type index) const {
//         if(index < m_size) {
//             return m_data[index];
//         }
//         throw std::out_of_range("index out of range");
//     }
//
//     template<typename T>
//     typename vector<T>::reference vector<T>::front() {
//         return m_data[0];
//     }
//
//     template<typename T>
//     typename vector<T>::const_reference vector<T>::front() const {
//         return m_data[0];
//     }
//
//     template<typename T>
//     typename vector<T>::reference vector<T>::back() {
//         return m_data[m_size - 1];
//     }
//
//     template<typename T>
//     typename vector<T>::const_reference vector<T>::back() const {
//         return m_data[m_size - 1];
//     }
//
//     template<typename T>
//     typename vector<T>::reference vector<T>::operator[](size_type index) {
//         return m_data[index];
//     }
//
//     template<typename T>
//     typename vector<T>::const_reference vector<T>::operator[](size_type index) const {
//         return m_data[index];
//     }
//
//     template<typename T>
//     void vector<T>::clear() {
//         delete[] m_data;
//         m_size = 0;
//         m_capacity = 0;
//         m_data = nullptr;
//     }
//
//     template<typename T>
//     void vector<T>::push_back(const_reference val) {
//         if(m_size == m_capacity) {
//             reserve(m_capacity ? m_capacity * 2 : 1);
//         }
//         m_data[m_size++] = val;
//     }
//
//     template<typename T>
//     void vector<T>::pop_back() {
//         if(m_size) {
//             m_size--;
//         }
//     }
//
//     template<typename T>
//     typename vector<T>::size_type vector<T>::capacity() const {
//         return m_capacity;
//     }
//
//     template<typename T>
//     typename vector<T>::size_type vector<T>::insert(Iterator pos, const_reference val) {
//         // after iterator impl (spasenq hla eli)
//     }
//
//     template<typename T>
//     typename vector<T>::size_type vector<T>::insert(Iterator pos, std::initializer_list<T> list) {
//         // spasenq
//     }
//
//     template<typename T>
//     typename vector<T>::size_type vector<T>::erase(Iterator pos) {
//         // stex el
//     }
//
//     template<typename T>
//     typename vector<T>::size_type vector<T>::erase(Iterator first, Iterator last) {
//         // es el
//     }
//
//     template<typename T>
//     void vector<T>::resize(size_type new_size) {
//         if(new_size > m_size) {
//             T* new_data = new T[new_size];
//             for(std::size_t i = 0; i < m_size; i++) {
//                 new_data[i] = m_data[i];
//             }
//             for(std::size_t i = m_size; i < new_size; i++) {
//                 new_data[i] = T();
//             }
//             delete[] m_data;
//             m_data = new_data;
//             m_capacity = new_size;
//         } else if (new_size < m_size) {
//             m_size = new_size;
//         }
//     }
//
//     template<typename T>
//     void vector<T>::resize(size_type new_size, const_reference val) {
//         if(new_size > m_size) {
//             T* new_data = new T[new_size];
//             for(std::size_t i = 0; i < m_size; i++) {
//                 new_data[i] = m_data[i];
//             }
//             for(std::size_t i = m_size; i < new_size; i++) {
//                 new_data[i] = val;
//             }
//             delete[] m_data;
//             m_data = new_data;
//             m_capacity = new_size;
//
//         } else if (new_size < m_size) {
//             m_size = new_size;
//         }
//     }
//
//     template<typename T>
//     void vector<T>::swap(vector &other) {
//         std::swap(m_size, other.m_size);
//         std::swap(m_capacity, other.m_capacity);
//         std::swap(m_data, other.m_data);
//     }
//
//     template<typename T>
//     vector<T>::Iterator::Iterator(pointer data): m_data(data) {}
//
//     template<typename T>
//     vector<T>::Iterator vector<T>::Iterator::operator+(typename pic::vector<T>::Iterator::difference_type n) const {
//         return Iterator(m_data + n);
//     }
//
//     template<typename T>
//     vector<T>::Iterator vector<T>::Iterator::operator-(typename pic::vector<T>::Iterator::difference_type n) const {
//         return Iterator(m_data - n);
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator::difference_type vector<T>::Iterator::operator-(const Iterator &rhs) const {
//         return m_data - rhs.m_data;
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator &vector<T>::Iterator::operator++() {
//         ++m_data;
//         return *this;
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator &vector<T>::Iterator::operator--() {
//         --m_data;
//         return *this;
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator &vector<T>::Iterator::operator++(int) {
//         return m_data++;
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator &vector<T>::Iterator::operator--(int) {
//         return m_data--;
//     }
//
//     template<typename T>
//     typename vector<T>::reference vector<T>::Iterator::operator*() const {
//         return *m_data;
//     }
//
//     template<typename T>
//     typename vector<T>::pointer vector<T>::Iterator::operator->() const {
//         return m_data;
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator vector<T>::begin() const {
//         return Iterator(m_data);
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator vector<T>::end() const {
//         return Iterator(m_data + m_size);
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator vector<T>::rbegin() const {
//         return Iterator(m_data + m_size - 1);
//     }
//
//     template<typename T>
//     typename vector<T>::Iterator vector<T>::rend() const {
//         return Iterator(m_data - 1);
//     }
//
//     template<typename T>
//     bool operator==(const typename vector<T>::Iterator& lhs, const typename vector<T>::Iterator& rhs) {
//         return lhs.m_data == rhs.m_data;
//     }
//
//     template<typename T>
//     bool operator!=(const typename vector<T>::Iterator& lhs, const typename vector<T>::Iterator& rhs) {
//         return lhs.m_data != rhs.m_data;
//     }
//
//     template<typename T>
//     bool operator<(const typename vector<T>::Iterator& lhs, const typename vector<T>::Iterator& rhs) {
//         return lhs.m_data < rhs.m_data;
//     }
//
//     template<typename T>
//     bool operator>(const typename vector<T>::Iterator& lhs, const typename vector<T>::Iterator& rhs) {
//         return lhs.m_data > rhs.m_data;
//     }
//
//     template<typename T>
//     bool operator<=(const typename vector<T>::Iterator& lhs, const typename vector<T>::Iterator& rhs) {
//         return lhs.m_data <= rhs.m_data;
//     }
//
//     template<typename T>
//     bool operator>=(const typename vector<T>::Iterator& lhs, const typename vector<T>::Iterator& rhs) {
//         return lhs.m_data >= rhs.m_data;
//     }
//
//     template<typename T>
//     bool operator==(const typename vector<T>::Iterator& lhs, const T& rhs) {
//         return lhs.m_data == rhs;
//     }
//
//     template<typename T>
//     bool operator!=(const typename vector<T>::Iterator& lhs, const T& rhs) {
//         return lhs.m_data != rhs;
//     }
// }