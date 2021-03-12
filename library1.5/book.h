#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class book{
    private:
        string bookName; //����
        string ISBN; //ISBN���
        string authorName; //������
        char classF1; //��������ĵ�һ��
        string classF2; //��������ĵڶ���
        char classF3; //��������ĵ�����
        bool isBorrow; //�Ƿ񱻽���
    public:
        book(){isBorrow=0;}
        book(string s1, string s2, string s3, char ch1, string ch2, char ch3){
            bookName=s1;
            ISBN=s2;
            authorName=s3;
            classF1=ch1;
            classF2=ch2;
            classF3=ch3;
        }  //����
        ~book(){}  //����
        string getBookName(){
            return bookName;
        }//�������
        void setBookName(string s1){
            bookName=s1;
        }//��������
        string getISBN(){
            return ISBN;
        }//���ISBN
        void setISBN(string s2){
            ISBN=s2;
        }//����ISBN
        string getAuthorName(){
            return authorName;
        }//������������
        void setAuthorName(string s3){
            authorName=s3;
        }//������������
        string getClassF(){
            string s;
            s+=classF1;
            s+=classF2;
            s+=' ';
            s+=classF3;
            return s;
        }//���ͼ��ݵķ���
        void setClassF(char ch, string s0, char s1){
            classF1=ch;
            classF2=s0;
            classF3=s1;
        } //�����ǽӿڣ������޸ĺͻ�������Ϣ
        void setBorrow(int b1){
            if(b1==0){
                isBorrow=false;
                return ;
            }
            isBorrow=true;
        }//�����Ƿ񱻽���
        bool getisBorrow(){
            return isBorrow;
        }//�ӿ����Է����Ƿ񱻽���
        bool operator==(book b0){
            return (bookName==b0.getBookName()&&ISBN==b0.getISBN()&&authorName==b0.getAuthorName()&&b0.getisBorrow()==isBorrow&&this->getClassF()==b0.getClassF());
        }//���أ�����ȷ�����������
        friend ostream& operator<<(ostream &os, book &b1){
            os << b1.getBookName() << ' ' << b1.getISBN() << ' ' << b1.getAuthorName() << ' ' << b1.getClassF() << endl;
            return os;
        }
};

#endif
