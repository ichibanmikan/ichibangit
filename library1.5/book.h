#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class book{
    private:
        string bookName; //书名
        string ISBN; //ISBN编号
        string authorName; //作者名
        char classF1; //三级分类的第一类
        string classF2; //三级分类的第二类
        char classF3; //三级分类的第三类
        bool isBorrow; //是否被借走
    public:
        book(){isBorrow=0;}
        book(string s1, string s2, string s3, char ch1, string ch2, char ch3){
            bookName=s1;
            ISBN=s2;
            authorName=s3;
            classF1=ch1;
            classF2=ch2;
            classF3=ch3;
        }  //构造
        ~book(){}  //析构
        string getBookName(){
            return bookName;
        }//获得书名
        void setBookName(string s1){
            bookName=s1;
        }//设置书名
        string getISBN(){
            return ISBN;
        }//获得ISBN
        void setISBN(string s2){
            ISBN=s2;
        }//设置ISBN
        string getAuthorName(){
            return authorName;
        }//设置作者名字
        void setAuthorName(string s3){
            authorName=s3;
        }//设置作者名字
        string getClassF(){
            string s;
            s+=classF1;
            s+=classF2;
            s+=' ';
            s+=classF3;
            return s;
        }//获得图书馆的分类
        void setClassF(char ch, string s0, char s1){
            classF1=ch;
            classF2=s0;
            classF3=s1;
        } //上面是接口，方便修改和获得相关信息
        void setBorrow(int b1){
            if(b1==0){
                isBorrow=false;
                return ;
            }
            isBorrow=true;
        }//设置是否被借走
        bool getisBorrow(){
            return isBorrow;
        }//接口用以返回是否被借走
        bool operator==(book b0){
            return (bookName==b0.getBookName()&&ISBN==b0.getISBN()&&authorName==b0.getAuthorName()&&b0.getisBorrow()==isBorrow&&this->getClassF()==b0.getClassF());
        }//重载，便于确定两个类相等
        friend ostream& operator<<(ostream &os, book &b1){
            os << b1.getBookName() << ' ' << b1.getISBN() << ' ' << b1.getAuthorName() << ' ' << b1.getClassF() << endl;
            return os;
        }
};

#endif
