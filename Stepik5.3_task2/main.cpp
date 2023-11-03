#include <iostream>
struct Expression;
struct BinaryOperation;

struct Expression
{
    Expression()
    {
        std::cout << "Expression()" << std::endl;
        size = 10;
        data = new double[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = i;
        }
    };
    size_t size;
    double* data;
    ~Expression()
    {
        std::cout << "~Expression()" << std::endl;
        delete[] data;
        data = nullptr;
    }
};

struct RefCounter
{
    RefCounter()
    {
        // std::cout << "RefCounter()" << std::endl;
        counter = 0;
    }
    size_t counter;
};

struct SharedPtr
{
    explicit SharedPtr(Expression* ptr = nullptr)
        : ptr_(nullptr)
        , cnt_(nullptr)
    {
        // std::cout << "SharedPtr() in" << std::endl;
        if (ptr)
        {
            ptr_ = ptr;
            cnt_ = new RefCounter();
            cnt_->counter += 1;
        }

        // std::cout << "  ptr_: " << ptr_ << std::endl;
        // std::cout << "  cnt_: " << cnt_ << " value: " << (cnt_ ? cnt_->counter : NULL) << std::endl;
        // std::cout << "SharedPtr() out" << std::endl;
    }

    SharedPtr(const SharedPtr& sp)
    {
        // std::cout << "SharedPtr(copy constructor) in" << std::endl;
        ptr_ = sp.ptr_;
        cnt_ = sp.cnt_;
        if (sp.cnt_)
        {
            cnt_->counter += 1;
        }

        // std::cout << "  ptr_: " << ptr_ << std::endl;
        // std::cout << "  cnt_: " << cnt_ << " value: " << (cnt_ ? cnt_->counter : NULL) << std::endl;
        // std::cout << "SharedPtr(copy constructor) out" << std::endl;
    }

    SharedPtr& operator=(const SharedPtr& sp)
    {
        // std::cout << "operator= in" << std::endl;
        if (&sp == this)
        {
            return *this;
        }

        if (ptr_ && cnt_)
        {
            cnt_->counter -= 1;
            if (cnt_->counter == 0)
            {
                delete ptr_;
                ptr_ = nullptr;

                delete cnt_;
                cnt_ = nullptr;
            }
        }

        ptr_ = sp.ptr_;
        cnt_ = sp.cnt_;
        if (sp.cnt_)
        {
            cnt_->counter += 1;
        }

        // std::cout << "operator= out" << std::endl;
        return *this;
    }

    ~SharedPtr()
    {
        // std::cout << "~SharedPtr() in" << std::endl;
        if (ptr_ && cnt_)
        {
            cnt_->counter -= 1;
            if (cnt_->counter == 0)
            {
                delete ptr_;
                ptr_ = nullptr;

                delete cnt_;
                cnt_ = nullptr;
            }
        }
        // std::cout << "  ptr_: " << ptr_ << std::endl;
        // std::cout << "  cnt_: " << cnt_ << " value: " << (cnt_ ? cnt_->counter : NULL) << std::endl;
        // std::cout << "~SharedPtr() out" << std::endl;
    }

    Expression* get() const
    {
        return ptr_;
    }

    void reset(Expression* ptr = nullptr)
    {
        if (ptr)
        {
            if (ptr_ && cnt_)
            {
                cnt_->counter -= 1;
                if (cnt_->counter == 0)
                {
                    delete ptr_;
                    ptr_ = nullptr;

                    delete cnt_;
                    cnt_ = nullptr;
                }
            }
            ptr_ = ptr;
            cnt_ = new RefCounter();
            cnt_->counter += 1;
        }
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
    Expression* ptr_;
    RefCounter* cnt_;
};

int main()
{

    // Expression* p1 = new Expression();

    // SharedPtr sp1(p1);

    // SharedPtr sp2(sp1);
    // sp1 = sp2;

    SharedPtr p1;
    {
        SharedPtr p2(new Expression());
        // SharedPtr p3(new Expression());
        SharedPtr p4(p2);
        p4 = p4;
        // SharedPtr p5;
        // p5 = p2;
        // p5 = p4;
        // p1 = p5;
        // p3.reset(NULL);
        // p3 = p5;
        // p5.reset(NULL);
        // SharedPtr p6;
        // SharedPtr p7;
        // p7 = p7;
        // p7.reset(NULL);
        // p7.reset(new Expression());
        // SharedPtr p8(new Expression());
        // p8.reset(NULL);
    }
    // p1 = p1;
    // std::cout << sp << std::endl;

    return 0;
}