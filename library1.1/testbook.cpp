#include <iostream>
#include <fstream>
#include <cstring>
#include "library_system.h"
#include "book.h"
#include "user_admini.h"
#include "user_student.h"
#include "library_system_user.h"
#include <windows.h>

using namespace std;

int main(){
	cout << "加载中，请稍后…………"  << endl;
    ifstream infile_book("books.txt", ios::in);
    library_system ls1;
    ls1.setBook(infile_book);
	// ls1.showAllBook();
    infile_book.close();

    ifstream infile_users("user.txt", ios::in);
    library_system_user lsu;
    lsu.setVecUS(infile_users);
    // lsu.showUsers();
    infile_users.close();

    ifstream infile_admini("admini.txt", ios::in);
   	lsu.setVecAdmini(infile_admini);
    // lsu.showAdminis();
    infile_admini.close();

	cout << "加载完成" << endl;
	
	Sleep(1000);//让程序停留一段时间，Sleep(注意S大写)可以用在清除缓冲区之前，先让他看到提示信息再清除
	 
	while(true){
		cout << "欢迎来到H大学图书馆，请先登录;" << endl;
    	cout << "以管理员登录请输入1，以学校用户登录请输入2，退出请输入0" << endl;
    	cout << "请输入：";
    	int choose_status;
		cin >> choose_status;
		if(choose_status==0){
			break;
		}
		if(choose_status==1){
			cout << "若需返回请输入back，若需退出请输入logout，若忘记密码请输入forget,若需登录请直接输入账号和密码" << endl;
			cout << "请输入:";
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
					cout << "已进入找回密码界面，请输入您对应的账号和姓名" << endl;
					cin >> str1 >> str2;
					lsu.forgetPassword(str1,str2,1);//引用该函数来达到匹配信息修改管理员用户密码的操作
				}
				cin >> str2;
				if(lsu.isLogin_admini(str1, str2)==-1){
					cout << "账号或密码错误，请您重新登录" << endl;
				}
				else{
                    user_admini am=lsu.getAdnimiStatus(lsu.isLogin_admini(str1, str2));

				}
			}
		}
		if(choose_status==2){
            cout << "若需返回请输入back，若需退出请输入logout，若忘记密码请输入forget,若需登录请直接输入账号和密码" << endl;
            cout << "请输入:";
            while(true){
                string str1,str2;
                cin>>str1;
                if(str1=="back"){
                    break;
                }
                if(str1=="logout"){
                    break;
                }
                if(str1=="forget"){
                    cout << "已进入找回密码界面，请输入您对应的账号和姓名" << endl;
                    cin>>str1>>str2;
                    lsu.forgetPassword(str1,str2,2);//引用该函数来达到匹配信息修改学生用户密码的操作
                }
                cin>>str2;
                if(lsu.isLogin_user(str1,str2)==-1){
                    cout << "账号或密码错误，请您重新登录" << endl;
                }
                else{
                    user_student st=lsu.getUserStatus(lsu.isLogin_user(str1,str2));
                }
            }
		}
	}
	cout << "感谢您的使用!!" << endl;
	//这是我举的一个例子，就按照这个接着写就行，忘记密码那个我library_system_user类里面有库函数直接用就行，这个活简单但是太多了，辛苦了!!!!有什么疑问一定过来问我!!!
    return 0;
}
