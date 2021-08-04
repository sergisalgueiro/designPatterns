#include <string>
#include <sstream>
using namespace std;

struct MultiplicationExpression;
struct Value;
struct AdditionExpression;

struct ExpressionVisitor
{
  virtual void accept(Value& v) = 0;
  virtual void accept(AdditionExpression& ae) = 0;
  virtual void accept(MultiplicationExpression& me) = 0;
};

struct Expression
{
  virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
  int value;

  Value(int value) : value(value) {}

  void visit(ExpressionVisitor& ev) override
  {
      ev.accept(*this);
  }
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor& ev) override
  {
      ev.accept(*this);
  }
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
    : lhs(lhs), rhs(rhs) {}

void visit(ExpressionVisitor& ev) override
  {
      ev.accept(*this);
  }
};

struct ExpressionPrinter : ExpressionVisitor
{
    ostringstream oss;
    virtual void accept(Value& v)
    {
        oss << v.value;
    }

  virtual void accept(AdditionExpression& ae)
  {
      oss << "(";
      ae.lhs.visit(*this);
      oss << "+";
      ae.rhs.visit(*this);
      oss << ")";
  }
  virtual void accept(MultiplicationExpression& me)
  {
      me.lhs.visit(*this);
      oss << "*";
      me.rhs.visit(*this);
  }

  string str() const { return oss.str(); }
};
