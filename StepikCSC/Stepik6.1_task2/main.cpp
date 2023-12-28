#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    explicit Array(size_t size, const T& value = T())
    {
        std::cout << "Array(size_t size, const T& value = T())" << std::endl;

        size_ = size;
        data_ = nullptr;
        if (size_ != 0)
        {
            data_ = (T*)(new char[size_ * sizeof(T)]);
            for (size_t i = 0; i < size_; ++i)
            {
                new (&data_[i]) T(value);
            }
        }
    }

    Array()
    {
        std::cout << "Array()" << std::endl;
        size_ = 0;
        data_ = nullptr;
    }

    Array(const Array<T>& arr)
    {
        std::cout << "Array(const Array<T>& arr)" << std::endl;
        size_ = arr.size_;
        data_ = nullptr;
        if (size_ != 0)
        {
            data_ = (T*)(new char[size_ * sizeof(T)]);
            for (size_t i = 0; i < size_; ++i)
            {
                new (&data_[i]) T(arr.data_[i]);
            }
        }
    }

    ~Array()
    {
        std::cout << "~Array()" << std::endl;

        for (size_t i = 0; i < size_; ++i)
        {
            data_[i].~T();
        }
        delete[](char*) data_;
        data_ = nullptr;
    }

    Array& operator=(const Array<T>& arr)
    {
        std::cout << "Array& operator=(const Array<T>& arr)" << std::endl;
        if (this == &arr)
        {
            return *this;
        }

        for (size_t i = 0; i < size_; ++i)
        {
            data_[i].~T();
        }
        delete[](char*) data_;
        data_ = nullptr;

        size_ = arr.size_;

        if (size_ != 0)
        {
            data_ = (T*)(new char[size_ * sizeof(T)]);
            for (size_t i = 0; i < size_; ++i)
            {
                new (&data_[i]) T(arr.data_[i]);
            }
        }
        return *this;
    }

    size_t size() const
    {
        return size_;
    }

    T& operator[](size_t i)
    {
        return data_[i];
    }

    const T& operator[](size_t i) const
    {
        return data_[i];
    }

private:
    size_t size_;
    T* data_;
};

// std::ostream& operator<<(std::ostream& os, const Array<int>& data)
// {
//     os << "data: ";
//     for (size_t i = 0; i < data.size_; ++i)
//     {
//         os << data.data_[i] << " ";
//     }
//     return os;
// }

struct Int1
{
    Int1()        = delete;
    Int1& operator=(const Int1& b) = delete;

    Int1(int a)
    {
        std::cout << "Int1(int)" << std::endl;
        data_ = a;
    }

    Int1(const Int1& b)
    {
        std::cout << "Int1(const Int1&)" << std::endl;
        data_ = b.data_;
    }

    ~Int1()
    {
        std::cout << "~Int1()" << std::endl;
    }

    int data_;
};

struct Int2
{
    Int2()
    {
        std::cout << "Int2()" << std::endl;
        data_ = 0;
    }
    Int2(int a)
    {
        std::cout << "Int2(int)" << std::endl;
        data_ = a;
    }

    Int2(const Int2& b)
    {
        std::cout << "Int2(const Int2&)" << std::endl;
        data_ = b.data_;
    }

    ~Int2()
    {
        std::cout << "~Int2()" << std::endl;
    }

    Int2& operator=(const Int2& b)
    {
        std::cout << "Int2& operator=(const Int2&)" << std::endl;
        if (this != &b)
        {
            data_ = b.data_;
        }

        return *this;
    }

    int data_;
};

int main()
{
    Array<Int1> ai0;
    Array<Int1> ai1(2, Int1(0));
    Array<Int1> ai2(ai1);
    ai0 = ai1;
    // ai1 = ai1;
    ai2 = ai1;
    ai2 = ai0;

    // Array<Int2> ai3;
    // Array<Int2> ai4(3, Int2(1));
    // Array<Int2> ai5(ai4);
    // ai3 = ai3;
    // ai4 = ai3;
    // ai5 = ai3;

    // Array<int> ai2(ai);
    // ai = ai2;

    return 0;
}