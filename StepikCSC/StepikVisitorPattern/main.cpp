#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor
{
    virtual void visitNumber(Number const* number)                      = 0;
    virtual void visitBinaryOperation(BinaryOperation const* operation) = 0;
    virtual ~Visitor()
    {
    }
};

struct Expression
{
    virtual double evaluate() const             = 0;
    virtual void visit(Visitor* vistitor) const = 0;
    virtual ~Expression()
    {
    }
};

bool isNumber(Expression const* exp);
bool isBinaryOperation(Expression const* exp);

struct Number : Expression
{
    Number(double value)
        : value(value)
    {
    }
    virtual double evaluate() const override
    {
        return value;
    }

    double get_value() const
    {
        return value;
    }

    void visit(Visitor* visitor) const
    {
        visitor->visitNumber(this);
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left)
        , op(op)
        , right(right)
    {
    }
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }
    virtual double evaluate() const override
    {
        double res;
        switch (op)
        {
            case ('+'):
                res = left->evaluate() + right->evaluate();
                break;
            case ('-'):
                res = left->evaluate() - right->evaluate();
                break;
            case ('*'):
                res = left->evaluate() * right->evaluate();
                break;
            case ('/'):
                res = left->evaluate() / right->evaluate();
                break;
        }
        return res;
    }

    Expression const* get_left() const
    {
        return left;
    }
    Expression const* get_right() const
    {
        return right;
    }
    char get_op() const
    {
        return op;
    }

    void visit(Visitor* visitor) const
    {
        visitor->visitBinaryOperation(this);
    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};

#include <iostream>

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor
{
    void visitNumber(Number const* number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const* bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << bop->get_op();
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};

int main()
{

    BinaryOperation* expr2 = new BinaryOperation(new BinaryOperation(new Number(2), '*', new Number(3)),
                                                 '+',
                                                 new BinaryOperation(new Number(2), '*', new Number(3)));

    PrintVisitor* pv = new PrintVisitor();
    expr2->visit(pv);

    std::cout << std::endl;

    return 0;
}