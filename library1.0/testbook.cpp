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
		cout << "欢迎来到H大学图书馆，请先登录;" << endl;
    	cout << "如果您要登录，如果您是管理员请输入1，如果您是学校用户请输入2，如果您要退出请输入0:" << endl;
		int choose_status; 
		cin >> choose_status;
		if(choose_status==0){
			break;
		}
		if(choose_status==1){
			cout << "如果您要返回请输入back，如果您要退出请输入logout如果您忘记密码请输入forget,如果您要登录请直接输入账号和密码:" << endl;
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
					cout << "请输入您的账号和姓名" << endl;
					cin >> str1 >> str2;
					lsu.forgetPassword(str1, str2, 1); //forgetgetPassWord是判断能否匹配的
				}//没写完呢
				cin >> str2;
				if(lsu.isLogin_admini(str1, str2)==-1){
					cout << "账号或密码错误，请您重新登录" << endl; 
				}
			}
		}
	} 
	cout << "感谢您的使用!!" << endl;
	//这是我举的一个例子，就按照这个接着写就行，忘记密码那个我library_system_user类里面有库函数直接用就行，这个活简单但是太多了，辛苦了!!!!有什么疑问一定过来问我!!! 
    return 0;
}
