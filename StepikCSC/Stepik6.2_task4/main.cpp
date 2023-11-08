#include <iostream>
// Эти классы реализовывать заново не нужно
struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable()
    {
    }
};

// Поле data_ типа T в классе ValueHolder
// открыто, к нему можно обращаться
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

// Это класс, который вам нужно реализовать
class Any
{
public:
    Any()
    {
        data_ = nullptr;
    }

    // В классе Any должен быть шаблонный
    // конструктор от одного параметра, чтобы
    // можно было создавать объекты типа Any,
    // например, следующим образом:
    //    Any i(10); // i хранит значение 10
    template <typename T>
    Any(T t)
    {
        data_ = dynamic_cast<ICloneable*>(new ValueHolder<T>(t));
    }

    // Не забудьте про деструктор. Все выделенные
    // ресурсы нужно освободить.
    ~Any()
    {
        delete data_;
        data_ = nullptr;
    }

    // В классе Any также должен быть конструктор
    // копирования (вам поможет метод clone
    // интерфейса ICloneable)
    Any(const Any& copy)
    {
        data_ = dynamic_cast<ICloneable*>(copy.data_->clone());
    }

    // В классе должен быть оператор присваивания и/или
    // шаблонный оператор присваивания, чтобы работал
    // следующий код:
    //    Any copy(i); // copy хранит 10, как и i
    //    empty = copy; // empty хранит 10, как и copy
    //    empty = 0; // а теперь empty хранит 0

    template <typename T>
    Any& operator=(const T& a)
    {
        // if (this == &a)
        // {
        //     return *this;
        // }

        // if (dynamic_cast<Any>(a))
        // {
        //     data_ = a.data_;
        //     // dynamic_cast<ValueHolder<int>*>(b))->data_
        // }

        // if (dynamic_cast<ValueHolder<T>>)
        // {
        //     data_ = a
        // }

        // if (dynamic_cast<Any>)
        //     data_ = copy.data_;
        return *this;
    }

    // Ну и наконец, мы хотим уметь получать хранимое
    // значение, для этого определите в классе Any
    // шаблонный метод cast, который возвращает
    // указатель на хранимое значение, или нулевой
    // указатель в случае несоответствия типов или
    // если объект Any ничего не хранит:
    //    int *iptr = i.cast<int>(); // *iptr == 10
    //    char *cptr = i.cast<char>(); // cptr == 0,
    //        // потому что i хранит int, а не char
    //    Any empty2;
    //    int *p = empty2.cast<int>(); // p == 0
    // При реализации используйте оператор dynamic_cast.

    template <typename T>
    T* cast()
    {

        if (dynamic_cast<T>(((ValueHolder<T>*)this->data_)->data_))
        {
            return &(((ValueHolder<T>*)this->data_)->data_);
        }
    }

    ICloneable* data_;
};

int main()
{
    Any i(10);
    Any id(i);
    Any ic('5');
    Any ic2(ic);

    ValueHolder<int> a = 5;
    ICloneable* b      = a.clone();
    if (dynamic_cast<ValueHolder<int>*>(b))
    {
        std::cout << (dynamic_cast<ValueHolder<int>*>(b))->data_ << std::endl;
    }

    Any copy(i);      // copy хранит 10, как и i
    Any empty = copy; // empty хранит 10, как и copy

    empty = 0; // а теперь empty хранит 0
               // std::cout << *((ValueHolder<int>*)i.data_) << std::endl;
    // std::cout << *((ValueHolder<int>*)copy.data_) << std::endl;
    return 0;
}