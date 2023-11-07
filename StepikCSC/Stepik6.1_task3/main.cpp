#include <cstddef>
#include <iostream>

struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable()
    {
    }
};

// Шаблон ValueHolder с типовым параметром T,
// должен содержать одно открытое поле data_
// типа T.
//
// В шаблоне ValueHolder должен быть определен
// конструктор от одного параметра типа T,
// который инициализирует поле data_.
//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T>
struct ValueHolder : ICloneable
{
    ValueHolder(const T& obj)
        : data_(obj)
    {
    }

    virtual ValueHolder<T>* clone() const
    {
        return new ValueHolder<T>(*this);
    }

    // virtual ~ValueHolder()
    // {
    //     delete data_;
    // }

    T data_;
};

// struct Trace
// {

//     double a;
// };

int main()
{
    ValueHolder<int> vh(int(5));
    std::cout << vh.data_ << std::endl;
    return 0;
}