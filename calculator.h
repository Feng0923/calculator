#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <qstring.h>
class calculator
{
public:
    calculator(QString &expression);
    QString calculate();
   int priorty(QString c);
   void setExpression(QString &expression);
   float calulate2(float x,float y,QString a);
private:
    QString expression;
    QString result;

};


#endif // CALCULATOR_H
