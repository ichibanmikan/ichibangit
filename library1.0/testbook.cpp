#include <iostream>
#include <fstream>
#include <cstring>
#include "library_system.h"
#include "book.h"
#include "user_admini.h"
#include "user_student.h"
#include "library_system_user.h"

using namespace std;

int main(){
    ifstream infile_book("books.txt", ios::in);
    library_system ls1;
    ls1.setBook(infile_book);
    ls1.showAllBook();
    infile_book.close();
	
    ifstream infile_users("user.txt", ios::in);
    library_system_user lsu;
    lsu.setVecUS(infile_users);
    lsu.showUsers();
    infile_users.close();
	
    ifstream infile_admini("admini.txt", ios::in);
   	lsu.setVecAdmini(infile_admini);
    lsu.showAdminis();
    infile_admini.close();
    
	while(true){
		cout << "��ӭ����H��ѧͼ��ݣ����ȵ�¼;" << endl;
    	cout << "�����Ҫ��¼��������ǹ���Ա������1���������ѧУ�û�������2�������Ҫ�˳�������0:" << endl;
		int choose_status; 
		cin >> choose_status;
		if(choose_status==0){
			break;
		}
		if(choose_status==1){
			cout << "�����Ҫ����������back�������Ҫ�˳�������logout�������������������forget,�����Ҫ��¼��ֱ�������˺ź�����:" << endl;
			while(true){
				string str1, str2;
				cin >> str1;
				if(str1=="back"){
					break;
				}
				if(str1=="logout"){
					break;
				}
				if(str1=="forget"){
					cout << "�����������˺ź�����" << endl;
					cin >> str1 >> str2;
					lsu.forgetPassword(str1, str2, 1); //forgetgetPassWord���ж��ܷ�ƥ���
				}//ûд����
				cin >> str2;
				if(lsu.isLogin_admini(str1, str2)==-1){
					cout << "�˺Ż���������������µ�¼" << endl; 
				}
			}
		}
	} 
	cout << "��л����ʹ��!!" << endl;
	//�����Ҿٵ�һ�����ӣ��Ͱ����������д���У����������Ǹ���library_system_user�������п⺯��ֱ���þ��У������򵥵���̫���ˣ�������!!!!��ʲô����һ����������!!! 
    return 0;
}
