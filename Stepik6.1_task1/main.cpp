#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T())
    {
        size_ = size;
        data_ = nullptr;
        if (size_ != 0)
        {
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = value;
            }
        }
    }

    Array(const Array<T>& arr)
    {
        size_ = arr.size_;
        data_ = nullptr;
        if (size_ != 0)
        {
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = arr.data_[i];
            }
        }
    }

    ~Array()
    {
        delete[] data_;
        data_ = nullptr;
    }

    Array& operator=(const Array<T>& arr)
    {
        if (this == &arr)
        {
            return *this;
        }

        delete[] data_;
        data_ = nullptr;

        size_ = arr.size_;

        if (size_ != 0)
        {
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = arr.data_[i];
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

int main()
{
    Array<int> ai(10, 5);
    Array<int> ai2(ai);
    ai = ai2;

    return 0;
}