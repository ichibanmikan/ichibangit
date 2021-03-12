#ifndef USER_ADMINI_H
#define USER_ADMINI_H

#include <iostream>
#include <cstring>
#include "book.h"
#include "library_system.h"
#include "user_student.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

class user_admini : public user_student{
    private:
        string account;
        string password;
        string name;
    public:
        user_admini(){
            account="000000";
            password="000000";
            name="000000";
        }
        user_admini(string s1, string s2){
            name=s1;
            account=s2;
            password="123456";
        }
        void setAdmi_passWord(string s){
            password=s;
        }//修改管理员自己的密码
        void changeBookName(book b1, string sn){
            b1.setBookName(sn);
        }//修改书籍信息
        void changeBookISBN(book b1, string si){
            b1.setISBN(si);
        }//修改图书的ISBN
        void changeBookAuthorName(book b1, string sa){
            b1.setAuthorName(sa);
        }//修改图书的作者姓名
        void changeBookIsBorrow(book b1, int i){
            b1.setBorrow(i);
        }//修改是否被借走
        string getName(){
            return name;
        } //返回名字
        string getAccount(){
            return account;
        } //返回名字
};//管理员

#endif