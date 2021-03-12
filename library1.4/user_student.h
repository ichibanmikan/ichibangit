#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include "book.h"
#include "library_system.h"
#include <fstream>
#include <sstream>

using namespace std;

class user_student : public library_system {
    private:
        string name;
        string password; //密码
        bool isBorrow;//是否借了书
    public:
        string account;//学生账号
        user_student(){
            password="123456";
            account="000000";
            name="aaaaaa";
        }
        user_student(string s1, string s2){
            name=s1;
            account=s2;
            password="123456";
        }
        string getPassword(){
            return password;
        } //密码接口
        void setPassword(string str){
            password=str;
        } //修改密码
        int getIsBorrow(){
            if(isBorrow){
                return 1;
            }
            return 0;
        } //查看借阅记录
        string getName(){
            return name;
        } //返回名字
        void setBorrow(int i){
            if(i=1){
                isBorrow=true;
                return ;
            }
            isBorrow=false;
        } //借、还图书
}; //学校用户

#endif
