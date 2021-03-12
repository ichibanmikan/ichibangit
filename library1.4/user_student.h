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
        string password; //����
        bool isBorrow;//�Ƿ������
    public:
        string account;//ѧ���˺�
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
        } //����ӿ�
        void setPassword(string str){
            password=str;
        } //�޸�����
        int getIsBorrow(){
            if(isBorrow){
                return 1;
            }
            return 0;
        } //�鿴���ļ�¼
        string getName(){
            return name;
        } //��������
        void setBorrow(int i){
            if(i=1){
                isBorrow=true;
                return ;
            }
            isBorrow=false;
        } //�衢��ͼ��
}; //ѧУ�û�

#endif
