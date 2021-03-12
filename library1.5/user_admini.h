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
        }//�޸Ĺ���Ա�Լ�������
        void changeBookName(book b1, string sn){
            b1.setBookName(sn);
        }//�޸��鼮��Ϣ
        void changeBookISBN(book b1, string si){
            b1.setISBN(si);
        }//�޸�ͼ���ISBN
        void changeBookAuthorName(book b1, string sa){
            b1.setAuthorName(sa);
        }//�޸�ͼ�����������
        void changeBookIsBorrow(book b1, int i){
            b1.setBorrow(i);
        }//�޸��Ƿ񱻽���
        string getName(){
            return name;
        } //��������
        string getAccount(){
            return account;
        } //��������
};//����Ա

#endif