#ifndef BUFFER_H
#define BUFFER_H

#include <array>
#include <iostream>
#include "alarm_list.h"
using namespace std;


template <typename T, std::size_t sz>
class Buffer {
public:
    Buffer() = default;
    void add(const T& input_elem);
    void add(T&& input_elem);
    T get();
    bool is_empty() const;
    std::size_t crt_elem() const;
    std::size_t size() const; //max capacity
private:
//    std::size_t buffer_size {};
    using Container = std::array<T, sz>;
    using Iterator  = typename Container::iterator;
    Container buffer   { };
    Iterator read_head      { std::begin(buffer) };
    Iterator write_head     { std::begin(buffer) };
    unsigned counter_elements { 0 };

};

template <typename T, std::size_t sz>
void Buffer<T, sz>::add(const T& input_elem)
{
    if (counter_elements != sz) {
        *write_head = input_elem;
        ++counter_elements;
        ++write_head;
        if (write_head == std::end(buffer)){
            write_head = std::begin(buffer);
        }
    } else {
        cout << "Buffer is full!" << endl;
    }
}

template <typename T, std::size_t sz>
void Buffer<T, sz>::add(T&& input_elem)
{
    if (counter_elements != sz) {
        *write_head = std::move(input_elem);
        ++counter_elements;
        ++write_head;
        if (write_head == std::end(buffer)){
            write_head = std::begin(buffer);
        }
    } else {
        cout << "Buffer is full!" << endl;
    }
}

template <typename T, std::size_t sz>
T Buffer<T, sz>::get()
{
    if (counter_elements != 0) {
        auto ret_val_iter { read_head };
        --counter_elements;
        ++read_head;
        if (read_head == std::end(buffer)){
            read_head = std::begin(buffer);
        }
    return std::move(*ret_val_iter); }
    else {
        throw std::invalid_argument( "Buffer is empty!" );
    }
}

template <typename T, std::size_t sz>
std::size_t Buffer<T, sz>::crt_elem() const
{
    return counter_elements;
}

template <typename T, std::size_t sz>
std::size_t Buffer<T, sz>::size() const
{
    return sz;
}


template <typename T, std::size_t sz>
bool Buffer<T, sz>::is_empty() const
{
    if (counter_elements==0) {
        return true;
    }
    else {
        return false;
    }
}


#endif // BUFFER_H
