#include "calculator.h"
#include <qstack.h>
#include <iostream>
#include <QDebug>
#include <QMessageBox>


calculator::calculator(QString &expression)
{
   setExpression(expression);
}

QString calculator::calculate()
{
    QStack<QString> op;//存放操作符
    QStack<float> data;//存放数据
    float index = 0;//游标
    QString count = "";//记录完整数据
    QString left = "";//标志左括号(匹配括号)
//    try{
        while ( expression.at(index) != '$') {
                QString now = expression.at(index);//取出一个字符
                if (now >="0"&&now<="9"||now == "."){
                    count += now;//连接成完整数据
                }else{
                    if(count!=""){
                        float e = count.toFloat();//将数据转化为float
                        data.push(e);//入栈
                        count = "";//清空数据
                    }
                    if (op.isEmpty() || now == "("||priorty(now) > priorty(op.top())) {
                        op.push(now);
                        if(now == "("){
                            left = "(";
                        }
                    }
                    else {
                        if (now == ')') {
                            if(left=="("){
                                left = "";
                            QString a = op.top();
                            op.pop();
                            if(data.isEmpty()){
                                throw "括号前格式错误";
                            }
                            float x = data.top();
                            data.pop();
                            if(data.isEmpty()){
//                                throw "缺少数字";
                                data.push(x);
                                continue;
                            }
                            float y = data.top();
                            data.pop();
                            float z =  calulate2(x,y,a);;
                            data.push(z);
                            op.pop();//将"("出栈
                            }else{
                                throw "缺少左括号";
                            }
                        }else {
                            while (op.size() != 0 && priorty(now) <= priorty(op.top())) {
                                QString a = op.top();
                                op.pop();
                                if(data.isEmpty()){
                                    throw "括号后格式错误";
                                }
                                float x = data.top();
                                data.pop();
                                if(data.isEmpty()){
                                    if(left ==  "("){
                                        data.push(x);
                                        continue;
                                    }else{
                                         throw "缺少因子";
                                    }

                                }
                                float y = data.top();
                                data.pop();
                                float z = calulate2(x,y,a);
                                data.push(z);
                            }
                            op.push(now);
                        }
                    }
                }
                index++;
            }
        if(data.size()>1){
            throw "格式错误(乘号不能省略)";
        }
        result = QString("%1").arg(data.top());
//    }catch(const char *str){
//       return "erron";
//    }
    return result;
}

int calculator::priorty(QString c)
{
    if (c == '+' || c == '-') {
            return 0;
        }
        else if (c == '*' || c == '/'||c == '%') {
            return 1;
        }
        else if (c == '(' || c == ')') {
            return -1;
        }
        else if (c == '#'||c == '='||c == '/') {//运算结尾符
            return -2;
    }
}

void calculator::setExpression(QString &expression)
{
    expression.remove(QRegExp("\\s"));//去除空格
    this->expression = expression+"#$";//设置运算结尾符
}

float calculator::calulate2(float x, float y, QString a)
{
    float z;
    if(a == '+'){
        z = y + x;
    }else if(a == '-'){
          z = y - x;
    }else if(a == '*'){
        z = y * x;
    }else if(a == '/'){
        if(x == 0){
            throw "error";
        }
        z = y / x;
    }else if(a == '%'){
        z = (int)y % (int)x;
    }else {
       throw "符号不合法";
    }
    return z;
}
