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
                    Sleep(1000);
                    cout<<"登陆成功！即将进入管理员用户界面"<<endl;
                    user_admini am=lsu.getAdnimiStatus(lsu.isLogin_admini(str1, str2));
                    cout<<"请选择你要实现的功能"<<endl;
                    cout<<"--1--修改密码-------------------"<<endl;
                    cout<<"--2--修改指定书籍名称-----------"<<endl;
                    cout<<"--3--修改指定书籍ISBN-----------"<<endl;
                    cout<<"--4--修改指定书籍作者姓名-------"<<endl;
                    cout<<"--5--修改指定书籍借用情况-------"<<endl;
                    cout<<"--6--获取当前用户名及用户人名---"<<endl;
                    cout<<"--7--退出登录-------------------"<<endl;
                    while(true){
                    int a;cin>>a;
                    if(a==1){ cout<<"请输入修改后的密码"<<endl;string mima;cin>>mima;am.setPassword(mima);cout<<"修改密码成功"<<endl;}
                    if(a==2){ cout<<"请输入要修改书籍名称"<<endl;string nm;cin>>nm;ls1.findBook_name(nm);
                              if(ls1.findBook_name(nm)==-1){cout<<"不存在该书"<<endl;}
                              else{cout<<"请输入修改后名称"<<endl;string a1;cin>>a1;am.changeBookName(ls1.showBook(ls1.findBook_name(nm)),a1);
                                   cout<<"书籍名称修改成功"<<endl;
                              }
                    }
                    if(a==3){ cout<<"请输入要修改书籍名称"<<endl;string nm1;cin>>nm1;ls1.findBook_name(nm1);
                              if(ls1.findBook_name(nm1)==-1){cout<<"不存在该书"<<endl;}
                              else{cout<<"请输入修改后ISBN"<<endl;string a2;cin>>a2;am.changeBookISBN(ls1.showBook(ls1.findBook_name(nm1)),a2);
                                   cout<<"书籍ISBN修改成功"<<endl;
                              }
                    }
                    string nm4;//这里我1月6日下午4.30修改过了，后面if(a==5)的时候有个nm2,我不知道跟这里的nm2一不一样，如果一样，这个nm2的作用域是在a=4的大括号里的，这个elseif运行完了就不继续运行了，nm2就被删掉了，下面a==5显示的nm2会报错未定义，我在这里加了一个
                    if(a==4){ cout<<"请输入要修改书籍名称"<<endl;string nm2;cin>>nm2;ls1.findBook_name(nm2);
                              nm4=nm2;
                              if(ls1.findBook_name(nm2)==-1){cout<<"不存在该书"<<endl;}
                              else{cout<<"请输入修改后作者姓名"<<endl;string a3;cin>>a3;am.changeBookAuthorName(ls1.showBook(ls1.findBook_name(nm2)),a3);
                                   cout<<"书籍作者名称修改成功"<<endl;
                              }
                    }
                    if(a==5){ cout<<"请输入要修改书籍名称"<<endl;string nm3;cin>>nm3;ls1.findBook_name(nm3);
                              if(ls1.findBook_name(nm3)==-1){cout<<"不存在该书"<<endl;}
                              else{cout<<"请输入修改后的借用情（0表示书未借出，1表示已借出）"<<endl;int it;cin>>it;
                                   am.changeBookIsBorrow(ls1.showBook(ls1.findBook_name(nm4)),it);cout<<"书籍借用情况已成功修改"<<endl;
                              }
                    }
                    if(a==6){ cout<<"当前的用户名为："<<am.getAccount()<<" 当前用户名本人为:"<<am.getName()<<endl;} //1.6.16:34;这里俩函数没加括号我也帮着加上了！！
                    if(a==7){ cout<<"正在退出登录"<<endl;break;}
                    }
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
                    Sleep(1000);
                    cout<<"登陆成功！即将进入学生用户界面"<<endl;
                    user_student st=lsu.getUserStatus(lsu.isLogin_user(str1,str2));
                    cout<<"请选择你要实现的功能"<<endl;
                    cout<<"--1--修改密码-------------------"<<endl;
                    cout<<"--2--查看当前的借阅记录---------"<<endl;
                    cout<<"--3-----------"<<endl;

                    while(true){
                        int a;cin>>a;
                        if(a==1){ cout<<"请输入修改后的密码"<<endl;string b;cin>>b;st.setPassword(b);cout<<"修改密码成功"<<endl;}
                        if(a==2){ }
                    }
                }
            }
		}
	}
	cout << "感谢您的使用!!" << endl;
	//这是我举的一个例子，就按照这个接着写就行，忘记密码那个我library_system_user类里面有库函数直接用就行，这个活简单但是太多了，辛苦了!!!!有什么疑问一定过来问我!!!
    return 0;
}
