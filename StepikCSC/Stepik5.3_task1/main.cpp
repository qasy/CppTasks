#include <iostream>
struct Expression;
struct BinaryOperation;

struct Expression
{
    Expression()
    {
        std::cout << "in Expression()" << std::endl;
        std::cout << "ptr = " << this << std::endl;
        size = 10;
        data = new double[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = i;
        }
        std::cout << "out Expression()" << std::endl;
    };
    size_t size;
    double* data;
    ~Expression()
    {
        std::cout << "in ~Expression()" << std::endl;
        std::cout << "ptr = " << this << std::endl;
        delete[] data;
        data = nullptr;
        std::cout << "out ~Expression()" << std::endl;
    }
};

struct ScopedPtr
{
    explicit ScopedPtr(Expression* ptr = nullptr)
    {
        ptr_ = ptr;
    }
    ~ScopedPtr()
    {
        delete ptr_;
        ptr_ = nullptr;
    }
    Expression* get() const
    {
        return ptr_;
    }
    Expression* release()
    {
        Expression* tmp = ptr_;
        ptr_            = nullptr;
        return tmp;
    }
    void reset(Expression* ptr = nullptr)
    {
        delete ptr_;
        ptr_ = nullptr;
        ptr_ = ptr;
    }
    Expression& operator*() const
    {
        return *ptr_;
    }
    Expression* operator->() const
    {
        return ptr_;
    }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);

    ScopedPtr& operator=(const ScopedPtr&);

    Expression* ptr_;
};

int main()
{

    Expression* p1 = new Expression();
    Expression* p2 = new Expression();

    ScopedPtr sp(p1);
    std::cout << sp->data[2] << std::endl;

    return 0;
}