#include <iostream>
#include <fstream>
#include <cstring>
#include "library_system.h"
#include "book.h"
#include "user_admini.h"
#include "user_student.h"
#include "library_system_user.h"
#include <windows.h>
#include <cstdlib>

using namespace std;

int main(){
    int ttt;
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

    system("cls");
	
	while(true){
		cout << "欢迎来到H大学图书馆，请先登录;" << endl;
    	cout << "以管理员登录请输入1，以学校用户登录请输入2，退出请输入0" << endl;
    	cout << "请输入：";
    	int choose_status;
		cin >> choose_status;
		cout << "请稍候" << endl;
		Sleep(1000);
		system("cls");
		if(choose_status==0){
			break;
		}
		if(choose_status==1){
			cout << "您已选择管理员模式" << endl;
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
                    cout<<"--7--修改指定用户的借阅情况-----"<<endl;
                    cout<<"--8--增加图书-------------------"<<endl;
                    cout<<"--9--删除图书-------------------"<<endl;
                    cout<<"--10-搜索图书-------------------"<<endl;
                    cout<<"--11-退出登录-------------------"<<endl;
                    cout<<"--12-查看图书馆藏书-------------" << endl;
                    cout << "--13-查看管理员名单-----------" << endl;
                    cout << "--14-查看用户名单-------------"<< endl;
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
                    if(a==7){ cout<<"若需使用姓名查找用户输入1，若需使用账户名查找用户输入2"<<endl;int c;cin>>c;string aa;
                              if(c==1){cout<<"请输入用户名"<<endl;
                                       while(true){
                                       cin>>aa;
                                       if(lsu.findStudent_Name(aa)==-1){cout<<"不存在该用户请重新输入"<<endl;}
                                       else{
                                            user_student st1=lsu.getUserStatus(lsu.findStudent_Name(aa));
                                            cout<<"请输入指定用户修改后的借阅情况（1为已经借阅，其余数字为未借阅）"<<endl;
                                            int ii;cin>>ii;st1.setBorrow(ii);cout<<"修改借阅情况成功"<<endl;break;
                                       }    }
                              }
                              if(c==2){cout<<"请输入账户名"<<endl;
                                       while(true){
                                       cin>>aa;
                                       if(lsu.findStudent_Account(aa)==-1){cout<<"不存在该用户请重新输入"<<endl;}
                                       else{
                                            user_student st1=lsu.getUserStatus(lsu.findStudent_Account(aa));
                                            cout<<"请输入指定用户修改后的借阅情况（1为已经借阅，其余数字为未借阅）"<<endl;
                                            int ii;cin>>ii;st1.setBorrow(ii);cout<<"修改借阅情况成功"<<endl;break;
                                       }    }
                               }
                    }
                    if(a==8){ cout<<"已进入增加图书界面"<<endl;string bkn;string Isb;string anm;char cla1;string cla2;char cla3;
                              cout<<"请输入增加图书的名称"<<endl;cin>>bkn;cout<<"请输入对应ISBN编号"<<endl;cin>>Isb;
                              cout<<"请输入图书作者的姓名"<<endl;cin>>anm;cout<<"请输入图书分类第一类"<<endl;cin>>cla1;
                              cout<<"请输入图书分类第二类"<<endl;cin>>cla2;cout<<"请输入图书分类第三类"<<endl;cin>>cla3;
                              book bk1(bkn, Isb, anm, cla1, cla2, cla3);cout<<"增加图书成功"<<endl;ls1.addBook(bk1);
                    }
                    if(a==9){ cout<<"已进入删除图书界面，请输入要删除图书的相关信息"<<endl;
                              cout<<"输入1按照书名查找，输入2按照ISBN进行查找"<<endl;
                              int uu;cin>>uu;
                              if(uu==1){ cout<<"请输入书名:";string nnmm;cin>>nnmm;
                                         while(true){
                              if(ls1.findBook_name(nnmm)==-1){cout<<"所查找的书籍不存在，请重新输入"<<endl;}
                              else{cout<<"已查找到了对应书籍，确定删除请输入1，其余输入则退出"<<endl;int nntt;cin>>nntt;if(nntt==1){ls1.deleteBook(ls1.showBook(ls1.findBook_name(nnmm)));cout<<"删除成功"<<endl;break;}else{cout<<"已退出"<<endl;break;}}
                              }
                              }
                              if(uu==2){cout<<"请输入ISBN:";string iiss;cin>>iiss;
                                        while(true){
                              if(ls1.findBook_ISBN(iiss)==-1){cout<<"所查找的书籍不存在，请重新输入"<<endl;}
                              else{cout<<"已查找到了对应书籍，确定删除请输入1，其余输入则退出"<<endl;int nntt;cin>>nntt;if(nntt==1){ls1.deleteBook(ls1.showBook(ls1.findBook_ISBN(iiss)));cout<<"删除成功"<<endl;break;}else{cout<<"已退出"<<endl;break;}}
                              }
                              }
                            }
                    if(a==10){ cout<<"书名精确查找请输入1，ISBN码精确查找请输入2"<<endl;
                               cout<<"类型模糊查找请输入3,作者名模糊查找请输入4"<<endl;
                               cout<<"退出请输入5"<<endl;int yyy;cin>>yyy;string srr;
                                  while(true){
                                        if(yyy==1){cout<<"请输入需要查找的书名"<<endl;cin>>srr;
                                             if(ls1.findBook_name(srr)==-1){cout<<"所查找的书籍不存在，请重新输入"<<endl;break;}
                                             else{cout<<"查找书籍成功！请选择所需功能"<<endl;book bkk=ls1.showBook(ls1.findBook_name(srr));
                                                  cout<<"--1--获取书籍的相关信息-----"<<endl;
                                                  cout<<"--2--查询本书的借阅情况-----"<<endl;
                                                  cout<<"--3--退出-------------------"<<endl;int ttt;
                                                  cin>>ttt;if(ttt==3){break;}
                                                  while(true){
                                                    if(ttt==1){cout<<bkk<<endl;break;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"（0为未被借走，1为已被借走）"<<endl;break;}
                                                    if(ttt==3){break;}
                                                  }
                                             }}
                                        if(yyy==2){cout<<"请输入需要查找书籍的ISBN码"<<endl;cin>>srr;
                                             if(ls1.findBook_ISBN(srr)==-1){cout<<"所查找的书籍不存在，请重新输入"<<endl;}
                                             else{cout<<"查找书籍成功！请选择所需功能"<<endl;book bkk=ls1.showBook(ls1.findBook_ISBN(srr));
                                                  cout<<"--1--获取书籍的相关信息-----"<<endl;
                                                  cout<<"--2--查询本书的借阅情况-----"<<endl;
                                                  cout<<"--3--退出-------------------"<<endl;int ttt;
                                                  cin>>ttt;if(ttt==3){break;}
                                                  while(true){
                                                    if(ttt==1){cout<<bkk<<endl;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"（0为未被借走，1为已被借走）"<<endl;}
                                                    if(ttt==3){break;}
                                                  }
                                             }}
                                        if(yyy==3){cout<<"请输入所需要查找的书籍类别"<<endl;cin>>srr;ls1.findBook_classF(srr);break;}
                                        if(yyy==4){cout<<"请输入所需要查找的作者"<<endl;cin>>srr;ls1.findBook_authorName(srr);break;}
                                        if(yyy==5){break;}
                                  }
                             }
                    if(a==11){ cout<<"已退出登录"<<endl; cout << "感谢您的使用" << endl; break;}
                    if(a==12){
                        ls1.showAllBook();
                    }
                    if(a==13){
                        lsu.showAdminis();
                    }
                    if(a==14){
                        lsu.showUsers();
                    }
                    /**//**/ 
                    }
				}
			}
		}
		if(choose_status==2){
			cout << "您已选择学校用户模式" << endl;
            cout << "若需返回请输入back，若需退出请输入logout，若忘记密码请输入forget,若需登录请直接输入账号和密码" << endl;
            cout << "请输入:";
			Sleep(1000);
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
                    cout<<"登录成功！即将进入学生用户界面"<<endl;
                    user_student st=lsu.getUserStatus(lsu.isLogin_user(str1,str2));
                    cout<<"请选择你要实现的功能"<<endl;
                    cout<<"--1--修改密码-------------------"<<endl;
                    cout<<"--2--查看当前的借阅记录---------"<<endl;
                    cout<<"--3--采用检索功能查找图书-------"<<endl;

                    while(true){
                        int a;cin>>a;
                        if(a==1){ cout<<"请输入修改后的密码"<<endl;string b;cin>>b;st.setPassword(b);cout<<"修改密码成功"<<endl;}
                        if(a==2){ cout<<"当前账户的个人借阅情况为(0为未借书1为已借书）："<<st.getIsBorrow()<<endl;}
                        if(a==3){ cout<<"书名精确查找请输入1，ISBN码精确查找请输入2"<<endl;
                                  cout<<"类型模糊查找请输入3，作者名模糊查找请输入4"<<endl;
                                  cout<<"退出请输入5"<<endl;
                                  int tt;cin>>tt;string stt;
                                  while(true){if(tt==1){
                                            if(ttt==5){cout<<"已退出"<<endl;break;}
                                             cout<<"请输入需要查找的书名"<<endl;cin>>stt;
                                             if(ls1.findBook_name(stt)==-1){cout<<"所查找的书籍不存在，请重新输入"<<endl;}
                                             else{cout<<"查找书籍成功！请选择所需功能"<<endl;book bkk=ls1.showBook(ls1.findBook_name(stt));
                                                  cout<<"--1--获取书籍的相关信息-----"<<endl;
                                                  cout<<"--2--查询本书的借阅情况-----"<<endl;
                                                  cout<<"--3--借阅本书---------------"<<endl;
                                                  cout<<"--4--归还本书---------------"<<endl;
                                                  cout<<"--5--退出-------------------"<<endl;
                                                  while(true){
                                                    cin>>ttt;
                                                    if(ttt==1){cout<<bkk<<endl;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"（0为未被借走，1为已被借走）"<<endl;}
                                                    if(ttt==3){bkk.setBorrow(1);cout<<"书籍借阅成功"<<endl;}
                                                    if(ttt==4){bkk.setBorrow(0);cout<<"书籍归还成功"<<endl;}
                                                    if(ttt==5){break;}
                                                  }
                                             }
                                             }
                                  if(tt==2){ if(ttt==5){cout<<"已退出"<<endl;break;}
                                             cout<<"请输入需要查找书籍的ISBN码"<<endl;cin>>stt;
                                             if(ls1.findBook_ISBN(stt)==-1){cout<<"所查找的书籍不存在，请重新输入"<<endl;}
                                             else{cout<<"查找书籍成功！请选择所需功能"<<endl;book bkk=ls1.showBook(ls1.findBook_ISBN(stt));
                                                  cout<<"--1--获取书籍的相关信息-----"<<endl;
                                                  cout<<"--2--查询本书的借阅情况-----"<<endl;
                                                  cout<<"--3--借阅本书---------------"<<endl;
                                                  cout<<"--4--归还本书---------------"<<endl;
                                                  cout<<"--5--退出-------------------"<<endl;
                                                  while(true){
                                                    cin>>ttt;
                                                    if(ttt==1){cout<<bkk<<endl;}
                                                    if(ttt==2){cout<<bkk.getisBorrow()<<"（0为未被借走，1为已被借走）"<<endl;}
                                                    if(ttt==3){bkk.setBorrow(1);cout<<"书籍借阅成功"<<endl;}
                                                    if(ttt==4){bkk.setBorrow(0);cout<<"书籍归还成功"<<endl;}
                                                    if(ttt==5){break;}
                                                  }
                                             }
                                          }
                                  if(tt==3){cout<<"请输入所需要查找的书籍类别"<<endl;cin>>stt;ls1.findBook_classF(stt);break;}
                                  if(tt==4){cout<<"请输入所需要查找的作者"<<endl;cin>>stt;ls1.findBook_authorName(stt);break;}
                                  if(tt==5){break;}
                            }
                        }
                        /***//***/ 
                    }
                }
            }
		}
	}
	cout << "感谢您的使用!!" << endl;
    return 0;
}
