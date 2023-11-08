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

template <typename T>
bool less(T a, T b)
{
    return a < b;
}

template <typename T>
struct Greater
{
    bool operator()(T a, T b) const
    {
        return b < a;
    }
};

template <typename T, typename Comp>
T minimum(const Array<T>& arr, Comp comp)
{
    T min = arr[0];
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (comp(arr[i], min))
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{

    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less<int>); // в min должно попасть число 2
    std::cout << min << std::endl;
    int max = minimum(ints, Greater<int>()); // в max должно попасть число 15
    std::cout << max << std::endl;

    return 0;
}